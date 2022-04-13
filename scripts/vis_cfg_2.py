from struct import *
import os
import CFG_pb2
#CFG_pb2.py.path.append('/home/cdacesec/cfg_vis/CFG_pb2.py')
from graphviz import Digraph
from capstone import *
import sys
from time import sleep

dot = Digraph('G', filename='vis_cfg_1.gv')

M=CFG_pb2.Module()
def ListModule(M):
    global count # what is this for?
    print "Module Name: ", M.name
    for func in M.funcs:   
        dot = Digraph(format = 'dot')
        dot.attr('node', shape = 'rectangle',bgcolor='orange',fontcolor='grey5',fontname='Courier-Bold',rank='same',fillcolor='linen')

        dot.node_attr['style'] = 'filled'   # node style

        if func.name:
           print "Function name: ", func.name

        print "Function Start Address: ",str(hex(func.ea).replace('L',''))
        _func_ea=str(hex(func.ea))
        #raw_input("press return to continue")
        data1 =  ' Name of function = ' + func.name + '\n  Function Entry Address = ' +  _func_ea.replace('L','')
        print "The Value of data_1 is ",data1
        dot.node('%s' %(func.name), '%s' %(data1) ,shape='note',fontcolor="red",forntname='Courier-Italic',fillcolour='lightyellow',width='.1',layout="topi")
        

        if func.is_entrypoint:
            print "This function is entry point of program"
        count_block=0
        for block in func.blocks:
            count_block += 1
            print "Basic Block Start Address", hex(block.ea).rstrip("L")
            for successor in block.successor_eas:
                print "The DP_Type of Successor is ",type(successor)
                #raw_input("press return to continue")
                successor=(int(successor))
                print "succesor must be int now: ",type(successor)
                print "Now INT value",successor
                successor=hex(successor)
                print "The Hex of the successor is ",successor
               
                print "The SuUcessor is ",successor
                print "The count block is ",count_block
                #raw_input("press return to continue")

            inststr = []            
            succstr = []  
            noreturn = []
            read_byte= []
            mne_opstr = []
            data_list = []
            count_inst=0
            for inst in block.instructions:
                tmp = block.ea
                md = Cs(CS_ARCH_MIPS, CS_MODE_32)
                md.detail = True
                count = 0
                count_inst=count_inst+1
                for i in md.disasm(inst.bytes,inst.ea):
                    global count
                    count_inst=count_inst+1
                   # print("The Mnemonic is %s  \n The op_str is\t %s" %(i.mnemonic,i.op_str))
                    pad=0
                    pad=18-len(i.mnemonic)
                    pad_op_str=20-len(i.op_str)
                    if(len(i.mnemonic)==5):
                         pad=pad-2
                    if(len(i.mnemonic)==3):
                         pad=pad
                         if (i.mnemonic=="sra" or i.mnemonic=="sll" or i.mnemonic=="lui" ):
                             pad=pad-1
                         if( i.mnemonic=="and" or i.mnemonic=="bne" ):                             
                             pad=pad-3
                         if(i.mnemonic=="bal"  or i.mnemonic=="srl" or i.mnemonic=="sra" or i.mnemonic=="lbu"):
                             pad=pad-2
                    if(len(i.mnemonic)==4):
                         pad=pad-2
                         if (i.mnemonic=="move" or i.mnemonic=="bnez" ):
                             pad=pad-2
                         if(i.mnemonic=="jalr"):
                             pad=pad+2
                         if(i.mnemonic=="beqz"):
                             pad=pad-1      

                         if(i.mnemonic=="addu" or i.mnemonic=="subu"):
                             pad=pad-1
                
                    if(len(i.mnemonic)==2):
                         pad=pad-3
                         if  i.mnemonic=="jr" :
                             pad=pad+2
                         if i.mnemonic =="sw":
                             pad=pad-1
                         if i.mnemonic=="lw" :
                             pad=pad

            
                   
                    data = i.mnemonic.ljust(pad,' ') + i.op_str.ljust(pad_op_str,' ')
                    if count == 0:              
                        inst_0=inststr.append(inst.ea)
                    elif count == 1:

                        inst_1=inststr.append(inst.ea + 4)
                        print ("The value of instr_1 is %s" %(inst_1))

                    mne_opstr.append(str(data))
                    count=count+1
                string_of_insea=(str(hex(inst.ea)))
                print"Instruction EA: ",(string_of_insea.replace('L',' '))
                print"Instruction Bytes: Is ",data 
               # print"\n"
                print "The  value of the count_inst is %s",count_inst
                for xref in inst.xrefs:
                    if xref.target_type == 0:
                        print"Target Type: CodeTarget"
                    else:
                        print"Target Type: DataTarget"

                    if xref.operand_type == 0 :
                        print"Operand Type: ImmediateOperand"
                    elif xref.operand_type == 1 :
                        print"Operand Type: MemoryOperand"
                    elif xref.operand_type == 2 :
                        print"Operand Type: MemoryDisplacementOperand"
                    elif xref.operand_type == 3 :
                        print"Operand Type: ControlFlowOperand"
                    else:
                        print"Operand Type: OffsetTable"

                    if xref.location == 0:
                        print"Location : Internal"
                    else:
                        print"Location: External"
                    if xref.name:
                        print"Xref Name: ",xref.name
                print "Instruction NoReturn:",inst.local_noreturn
        
            def merge(inststr, mne_opstr):              
                merged_list = [(hex(inststr[i]), mne_opstr[i]) for i in range(0, len(inststr))]
                return merged_list

           # for i in range(len(mne_opstr)):
            #   inst=mne_opstr[i]
             #  torn = inst.split(",")
              # new = ",   ".join(torn)
               #torn1=new.split("$")
               #new1="    $".join(torn1)
               #mne_opstr[i] = new1
            for i in range(len(mne_opstr)):
                inst=mne_opstr[i]
                out=inst.split(",")
                new=",     ".join(out)
                mne_opstr[i]=new


            
            merge_data =  merge(inststr, mne_opstr)
                                # append into empty list
     
            count=0
            for i in merge_data:        
                count =count +1
                m=count
                result=('  '.join(i))
                print "The Value of The Result iS previous",result

            res=[]
            for i in merge_data:                    
                result=('      '.join(i))#this will give list of the touple
                print "The Value of The result is %s",result
                if count >1:
                   data_list.append(result)
                   count=count-1
                   print "The  Value of The Count is ",count
                else:
                   res=result
                   print "The Updated Value is %s",res
                
            data_list.append("{}\l".format(res))    

            if count==1:

                print "The Result in count 1 is %s",result

            for successor in block.successor_eas:
                print "BLOCK SUCCESSOR",type(block.successor_eas)
                successor=int(successor)
                successor=hex(successor)
                print "Sucessor ADDress: ",(successor)
                print "The D_Type of The succesor: ",type(successor)
                #raw_input("press return to continue")

                succstr.append(str(successor))
                #print "------succstr",succstr
            
            if succstr :
                print " successor is present\n "
                print "The successor is  MM",succstr
                succstr = [sub.replace('L', '') for sub in succstr] 
                print "INT NN " ,succstr


                
            else:    # edge for normal case
                print "I AM INS",type(inststr)

                dot.edge('%s' %(block.ea), '%s' %((inststr[-1]+4)),color = 'blue3',label = '',style='filled',fontname="Courier-Bold",penwidth='2',splines='ortho')

            
            next_block = [hex(inststr[-1]+4)]
            data2 = '\l'.join((data_list))
            data_2=data2.replace('L','')
           # data_22=hex(data_2)
            #dot.node('%s\n' %(str(block.ea))
            dot.node('%s' %(str(block.ea)) ,'%s' %(data_2),fontcolor="blue3",shape="box3d",width=".1")
        print "The Type of inststr iTYEs " ,type(inststr)
        for block in func.blocks:
            count=0
            if(func.ea == block.ea):
                  dot.edge('%s' %(func.name.replace('L','')), '%s' %(str(func.ea)),label=" start_of_basic_block ",style='filled',color='blue3',penwidth='2',shape='record',fontname='Courier-Bold')
           
            # check this. if there is more than one succesor, then how do we
            # find the edge for true case?
            # attempt 1:
            # only do this if there is more than one succesor
            # if the succsor.ea - branch_inst.ea = 8, then true, else false
            # or if succsor.ea - last_inst.ea = 4, then false, else true
            # true = long_jump, false = short_jump
            
            #first, extract the ea of the branching instruction or the ea of the last instruction
            all_inst_ea = []
            for i in block.instructions:
                all_inst_ea.append(i.ea)

            max_ea = max(all_inst_ea) # this is the ea of last inst in the block

            # more than one succesor, need to check the true false condition
            for successor  in (((block.successor_eas))):        
                if len(block.successor_eas) > 1:
                    if successor - max_ea == 4:
                        dot.edge('%s' %(str(block.ea)),'%s' %(str(successor)),color='red',label=' False ',style='filled',fontname="Courier-Bold",penwidth='2')
                    else:
                        dot.edge('%s'  %(str(block.ea)),'%s'% (str(successor)),color = 'green3',label = ' True '  ,style='filled',fontname="Courier-Bold",penwidth='2')
                else:
                    dot.edge('%s'  %(str(block.ea)),'%s'% ((successor)),color = 'blue3',label = ' '  ,style='filled',fontname="Courier-Bold",penwidth='2')

        dot.render(str(hex(func.ea)), view=False) 

    for seg in M.segments:
        if seg.name:
            print "Segment name: ", seg.name
        
        if seg.variable_name:
            print"Variable Name : ", seg.variable_name
        seg_start_address=str(hex(seg.ea))
        _seg_start_address=seg_start_address.replace('L','')
        print "Segment Start Address (EA ): ",_seg_start_address
        md = Cs(CS_ARCH_MIPS, CS_MODE_32)
        md.detail = True
        for i in md.disasm(seg.data,0x1000):
            print("Segment data : \t\t%s\t\t%s\t" %(i.mnemonic,i.op_str))

        print"Read Only : ", seg.read_only    
        print" Is External  : ", seg.is_external
        print" Is Exported  : ", seg.is_exported
        print" Is Thread_Local  : ", seg.is_thread_local

        for segxref in seg.xrefs:
            _segrex_ea=str(hex(segxref.ea))
            __segrex_ea=_segrex_ea.replace('L','')
            print"Segment Data Reference EA : ",__segrex_ea.replace
            print"Segment Data Reference Width : ",(segxref.width)
            _segxref_target_ea=str(hex(segxref.target_ea))
            print"Segment Data Reference Target EA : ",_segxref_target_ea.replace('L','')
            print"Segment Data Reference Target is Code : ",(segxref.target_is_code)

            if segxref.target_fixup_kind == 0:
                print"Absolute"
            else:
                print"OffsetFromThreadBase"


        for segvar in seg.vars:
            _segvar_ea=str(hex(segvar.ea))
            __segvar_ea=_segvar_ea.replace('L','')
            print" Segment Variable EA : ",__segvar_ea
            print" Segment Variable Name : ",segvar.name 
            print"\r"

    for ext in M.external_funcs:
        if ext:
            print"External Function Name: ",ext.name
            print"External Function Address(EA): ",ext.ea
            print"External Function CC: ",ext.cc
            print"External Function has Return: ",ext.has_return
            print"External Function No Return: ",ext.no_return
            print"External Function Argument Count: ",ext.argument_count
            print"External Function IS_weak: ",ext.is_weak
            print"External Function Signature: ",ext.signature
        else:
            print"No EXTERNAL FUNCTIONS"

    for ext_vars in M.external_vars:
        if ext_vars:
            print"External Function Name: ",ext_vars.name
            ext_var_size=str(hex(ext_vars.ea))
            print "External Vars Address(EA):", ext_var_size.replace('L','')
            print"Size of External variables: ",ext_vars.size 
            print"Is_weak : ",ext_vars.is_weak
            print"Is_thread_local : ",ext_vars.is_thread_local
            print"\l"

    for glob in M.global_vars:
        print"Global Name : ",glob.name
        print"Global Address(EA) : ",glob.ea
        print"Global Size : ",glob.size
    data1 = 'Segment Name = ' +( seg.name) + "\lEffective Address = " +(str(hex(seg.ea)))
    print " The  value of the data_1 is %s",data1
    dot.node('\l%s' %(seg.name), '%s\l' %(data1))
     #dot.node('%s %s '%(seg.name,data1))

f = open("prime.cfg", "rb")        # this is actually the .cfg file
# so if cfg file can be read by capstone, can we then use it 
M.ParseFromString(f.read())
f.close()
ListModule(M)
