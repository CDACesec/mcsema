# Copyright (c) 2017 Trail of Bits, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import collections
import idaapi
import idautils
import idc

# Maps instruction EAs to a pair of decoded inst, and the bytes of the inst.
PREFIX_ITYPES = tuple()

PERSONALITY_NORMAL = 0
PERSONALITY_DIRECT_JUMP = 1
PERSONALITY_INDIRECT_JUMP = 2
PERSONALITY_DIRECT_CALL = 3
PERSONALITY_INDIRECT_CALL = 4
PERSONALITY_RETURN = 5
PERSONALITY_SYSTEM_CALL = 6
PERSONALITY_SYSTEM_RETURN = 7
PERSONALITY_CONDITIONAL_BRANCH = 8
PERSONALITY_UNCONDITIONAL_BRANCH = 9
PERSONALITY_TERMINATOR = 10
PERSONALITY_BRANCH_PIPELINE = 11
PERSONALITY_CONDITIONALCALL = 12

PERSONALITIES = collections.defaultdict(int)
PERSONALITIES.update({ 

  idaapi.MIPS_lw: PERSONALITY_NORMAL,
  idaapi.MIPS_lbu: PERSONALITY_NORMAL,
  idaapi.MIPS_lb: PERSONALITY_NORMAL,
  idaapi.MIPS_lhu: PERSONALITY_NORMAL,
  idaapi.MIPS_sw: PERSONALITY_NORMAL,
  idaapi.MIPS_sh: PERSONALITY_NORMAL,
  idaapi.MIPS_sd: PERSONALITY_NORMAL,  
  idaapi.MIPS_add: PERSONALITY_NORMAL,		                           	
  idaapi.MIPS_addi: PERSONALITY_NORMAL,
  idaapi.MIPS_sub: PERSONALITY_NORMAL,
  idaapi.MIPS_subu: PERSONALITY_NORMAL,
  idaapi.MIPS_mult: PERSONALITY_NORMAL,
  idaapi.MIPS_multu: PERSONALITY_NORMAL,
  idaapi.MIPS_div: PERSONALITY_NORMAL,
  idaapi.MIPS_divu: PERSONALITY_NORMAL,
  idaapi.MIPS_ddiv: PERSONALITY_NORMAL,
  idaapi.MIPS_ddivu: PERSONALITY_NORMAL,
  idaapi.MIPS_dmult: PERSONALITY_NORMAL,
  idaapi.MIPS_dmultu: PERSONALITY_NORMAL,
  idaapi.MIPS_dadd: PERSONALITY_NORMAL,
  idaapi.MIPS_daddu: PERSONALITY_NORMAL,
  idaapi.MIPS_dsub: PERSONALITY_NORMAL,
  idaapi.MIPS_dsubu: PERSONALITY_NORMAL,
  idaapi.MIPS_addiu: PERSONALITY_NORMAL,
  idaapi.MIPS_lui: PERSONALITY_NORMAL,
  idaapi.MIPS_daddi: PERSONALITY_NORMAL,
  idaapi.MIPS_daddiu: PERSONALITY_NORMAL,
  idaapi.MIPS_and: PERSONALITY_NORMAL,
  idaapi.MIPS_andi: PERSONALITY_NORMAL,
  idaapi.MIPS_or: PERSONALITY_NORMAL,
  idaapi.MIPS_ori: PERSONALITY_NORMAL,
  idaapi.MIPS_xor: PERSONALITY_NORMAL,
  idaapi.MIPS_xori: PERSONALITY_NORMAL,
  
  idaapi.MIPS_jalx: PERSONALITY_DIRECT_JUMP,
 
  idaapi.MIPS_jal: PERSONALITY_DIRECT_CALL,
  idaapi.MIPS_bgezal: PERSONALITY_CONDITIONALCALL,                             

  idaapi.MIPS_syscall: PERSONALITY_SYSTEM_CALL,	                	           # causes a system call exception 

  idaapi.MIPS_b: PERSONALITY_BRANCH_PIPELINE,
  idaapi.MIPS_beq: PERSONALITY_BRANCH_PIPELINE,
  idaapi.MIPS_bne: PERSONALITY_BRANCH_PIPELINE,
  idaapi.MIPS_beqz: PERSONALITY_BRANCH_PIPELINE,
  idaapi.MIPS_bgez: PERSONALITY_BRANCH_PIPELINE,
  idaapi.MIPS_bnez: PERSONALITY_BRANCH_PIPELINE,
  idaapi.MIPS_bc1f: PERSONALITY_BRANCH_PIPELINE,
  idaapi.MIPS_bc1t: PERSONALITY_BRANCH_PIPELINE,
  idaapi.MIPS_bgtz: PERSONALITY_BRANCH_PIPELINE,
  idaapi.MIPS_blez: PERSONALITY_BRANCH_PIPELINE,
  idaapi.MIPS_bltz: PERSONALITY_BRANCH_PIPELINE,
   
  idaapi.MIPS_beql: PERSONALITY_CONDITIONAL_BRANCH,
  idaapi.MIPS_bnel: PERSONALITY_CONDITIONAL_BRANCH, 
  idaapi.MIPS_bal: PERSONALITY_CONDITIONAL_BRANCH,
  
  idaapi.MIPS_j: PERSONALITY_UNCONDITIONAL_BRANCH,
  idaapi.MIPS_jr: PERSONALITY_UNCONDITIONAL_BRANCH,
  idaapi.MIPS_jalr: PERSONALITY_UNCONDITIONAL_BRANCH,
                      
  })
 
def fixup_personality(inst, p):
  return p
