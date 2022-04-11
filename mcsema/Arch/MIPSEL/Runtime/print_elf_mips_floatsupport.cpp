/*
 * Copyright (c) 2017 Trail of Bits, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cstdio>
#include <cinttypes>

/* can replace PRIuMAX with %u */

#include "remill/Arch/MIPSEL/Runtime/State.h"
#include "mcsema/Arch/MIPSEL/Runtime/Registers.h"


#pragma clang diagnostic push /* saves the current pragma diagnostic state so that it can restored later */
#pragma clang diagnostic ignored "-Wformat" /* disables diagnostic msgs for "-Wformat" */

static const size_t kStackSize = 1UL << 20UL; /* 64 Kib */ /* UL = unsigned long */
static const size_t kFrameSize = 6400UL; /* assumed 64 kb to be frame size in mips */ //[verify the value]


int main(void) {

  FILE *out = fopen("mipsel_assembly.S", "w");


  fprintf(out, "/* Auto-generated file! Don't modify! */\n\n");


  // Thread-local state structure, named by `__mcsema_reg_state`
 
  fprintf(out, "  .globl __mcsema_reg_state\n");
  fprintf(out, "  .type __mcsema_reg_state,@object\n");
  fprintf(out, "  .section .tbss,\"awT\",@nobits\n");
  fprintf(out, "  .align 16\n"); /* Arch State is aligned as 16 */
  //fprintf(out, "  .align 4\n");
  fprintf(out, "__mcsema_reg_state:\n");
  
  fprintf(out, "  .zero %" PRIuMAX "\n", sizeof(State));
  fprintf(out, "  .size __mcsema_reg_state, %" PRIuMAX "\n", sizeof(State));
  fprintf(out, "\n");

  // Thread-local stack structure, named by `__mcsema_stack`.
  fprintf(out, "  .type __mcsema_stack,@object\n");
  fprintf(out, "  .section .tbss,\"awT\",@nobits\n");
  fprintf(out, "  .align 4\n");
  fprintf(out, "__mcsema_stack:\n");
  fprintf(out, "  .zero %" PRIuMAX "\n", kStackSize); /* 64kb for mips */
  fprintf(out, "  .size __mcsema_stack, %" PRIuMAX "\n", kStackSize);
  fprintf(out, "\n");

  //pointers to runtime functions, helps in loading their addresses
  fprintf(out, "  .data\n");
  fprintf(out, "  detach_ret_ptr:  .word __mcsema_detach_ret\n"); /* jump table entries */
  fprintf(out, "  attach_ret_ptr:  .word __mcsema_attach_ret\n");  

  fprintf(out, "  .text\n");
  fprintf(out, "\n");

  // Forward declarations.
  fprintf(out, "  .globl __mcsema_detach_ret\n"); 
  fprintf(out,  " \n");
  
  // Implements `__mcsema_attach_call`. This goes from native state into lifted
  // code.
  fprintf(out, "  .ent __mcsema_attach_call\n");
  fprintf(out, "  .globl __mcsema_attach_call\n");
  fprintf(out, "  .type __mcsema_attach_call,@function\n");
  fprintf(out, "__mcsema_attach_call:\n");

  // $t0 = wrappper, $t1 = this function, $t2 = ea from CFG

  // Save the target address, we  will return to it below
  fprintf(out, "  move $t9, $t0\n");
  
  
 /* save value of v0, as it will now hold addr of __mcsema_reg_state */
  fprintf(out, "  move $t3, $v0\n");
  fprintf(out, "  move $t5, $v1\n");
  
  // Setup TLS
  fprintf(out, "  rdhwr $v1, $29\n"); 
  fprintf(out, "  lui $v0, %%tprel_hi(__mcsema_reg_state)\n");
  fprintf(out, "  addiu $v0, $v0, %%tprel_lo(__mcsema_reg_state)\n");
  fprintf(out, "  addu $v0, $v0, $v1\n");

  // // Save the Caller Saved registers 
  fprintf(out, "  sw $a0, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, A0));
  fprintf(out, "  sw $a1, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, A1));
  fprintf(out, "  sw $a2, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, A2));
  fprintf(out, "  sw $a3, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, A3));


  // Save the rest of the registers
  fprintf(out, "  sw $t3, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, V0));
  fprintf(out, "  sw $t5, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, V1));
  

  fprintf(out, "  sw $s0, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S0));
  fprintf(out, "  sw $s1, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S1));
  fprintf(out, "  sw $s2, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S2));
  fprintf(out, "  sw $s3, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S3));
  fprintf(out, "  sw $s4, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S4));
  fprintf(out, "  sw $s5, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S5));
  fprintf(out, "  sw $s6, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S6));
  fprintf(out, "  sw $s7, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S7));

// floating point registers
  fprintf(out, "  swc1 $f20, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF20));   
  fprintf(out, "  swc1 $f21, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF21));
  fprintf(out, "  swc1 $f22, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF22));
  fprintf(out, "  swc1 $f23, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF23));
  fprintf(out, "  swc1 $f24, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF24));
  fprintf(out, "  swc1 $f25, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF25));
  fprintf(out, "  swc1 $f26, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF26));
  fprintf(out, "  swc1 $f27, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF27));
  fprintf(out, "  swc1 $f28, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF28));
  fprintf(out, "  swc1 $f29, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF29));
  fprintf(out, "  swc1 $f30, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF30));
  fprintf(out, "  swc1 $f31, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SF31));
  
  fprintf(out, " addiu $sp, $sp, -32\n");
  fprintf(out, " sw $ra, 28($sp)\n");


  // If lifted stack pointer is null, initialize it to the new stack(__mcsema_stack)
  fprintf(out, "  lw $t0, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SP));
  fprintf(out, "  bne $t0, $zero, .Lhave_stack \n");
  
  // load address of mcsema_stack in $t0
  fprintf(out, "  rdhwr $t1, $29\n"); 
  fprintf(out, "  lui $t0, %%tprel_hi(__mcsema_stack)\n");
  fprintf(out, "  addiu $t0, $t0, %%tprel_lo(__mcsema_stack)\n");
  fprintf(out, "  addu $t0, $t0, $t1\n");

  // add the stack size to the base addr of mcsema_stack@tls, because the stack grows downwards???  
  fprintf(out, "  li $a0, %" PRIuMAX "\n", (kStackSize));
  fprintf(out, "  addu $t0, $t0, $a0\n" );

  fprintf(out, ".Lhave_stack: \n");


  
  // Set up a return address so that when the lifted function returns, it will
  // go to "`__mcsema_detach_return`, which will return to the native code"
  fprintf(out, "  lw $ra, detach_ret_ptr\n");

  // exchange native stack and mcsema_stack
  fprintf(out, "  sw $sp, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SP));
  fprintf(out, "  move $sp, $t0\n");
  
  // Set up State struct as the first argument
  fprintf(out, "  add $a0, $v0, $zero\n");

  // Set up PC as the second argument
  //fprintf(out, "  lw $a1, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, PC));

  // Set up third argument as the memory pointer, which is null
  fprintf(out, "  move $a2, $zero\n");

  // jump to the wrapper function
  fprintf(out, "  jr $t9\n");
  
  fprintf(out, "  .end __mcsema_attach_call\n");


  // Implements `__mcsema_detach_ret`. This goes from lifted code into native code.
  // The native code pointer is located at the native `[State::RSP - 8][x86_64]`[ unverified location ]
  // address.
  fprintf(out, ".ent __mcsema_detach_ret\n");
  fprintf(out, "  .type __mcsema_detach_ret,@function\n");
  fprintf(out, "__mcsema_detach_ret:\n");

  // V0 holds the memory pointer(return value from lifted functions)
  // Set up TLS
  fprintf(out, "  rdhwr $v1, $29\n"); 
  fprintf(out, "  lui $v0, %%tprel_hi(__mcsema_reg_state)\n");
  fprintf(out, "  addiu $v0, $v0, %%tprel_lo(__mcsema_reg_state)\n");
  fprintf(out, "  addu $v0, $v0, $v1\n");

  // swap with the native stack
  fprintf(out, "  move $t5, $sp\n"); /* save value of sp */
  fprintf(out, "  lw $sp, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SP)); /* copy lifted sp onto native sp */
  fprintf(out, "  sw $t5, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SP)); /* copy old native sp into lifted sp*/


  /* Hopefully, restore the ra of libc_start_main */
  fprintf(out,  " lw $ra, 28($sp)\n");
  fprintf(out,  " addiu $sp, $sp, 32\n");


  // restore the register values
  fprintf(out, "  lw $a0, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, A0));
  fprintf(out, "  lw $a1, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, A1));
  fprintf(out, "  lw $a2, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, A2));
  fprintf(out, "  lw $a3, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, A3));
  fprintf(out, "  lw $s0, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S0));
  fprintf(out, "  lw $s1, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S1));
  fprintf(out, "  lw $s2, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S2));
  fprintf(out, "  lw $s3, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S3));
  fprintf(out, "  lw $s4, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S4));
  fprintf(out, "  lw $s5, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S5));
  fprintf(out, "  lw $s6, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S6));
  fprintf(out, "  lw $s7, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, S7));
  fprintf(out, "  lw $v1, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, V1));
  fprintf(out, "  lw $v0, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, V0));

  fprintf(out, "  jr $ra\n");
  fprintf(out, ".end __mcsema_detach_ret\n");
  fprintf(out, "\n");
  fprintf(out, "\n");


  // Implements `__remill_function_call`. This is a fully generic form of function
  // call detaching that is unaware of the ABI / calling convention of the target.
  fprintf(out, "  .globl __remill_jump\n");
  fprintf(out, "  .type __remill_jump,@function\n");

  fprintf(out, "__remill_jump:\n");
  fprintf(out, "  .globl __remill_function_call\n");
  fprintf(out, "  .type __remill_function_call,@function\n");
  fprintf(out, "__remill_function_call:\n");
  fprintf(out, "  .ent __remill_function_call\n");

  fprintf(out, "  addi $a1, $a1, -0x4\n");

  fprintf(out, "  addiu $sp, $sp, -120\n"); 
  fprintf(out, "  sw $ra, 116($sp)\n");
  fprintf(out, "  sw $s8, 112($sp)\n");
  fprintf(out, "  sw $s7, 108($sp)\n");
  fprintf(out, "  sw $s6, 104($sp)\n");
  fprintf(out, "  sw $s5, 100($sp)\n");
  fprintf(out, "  sw $s4, 96($sp)\n");
  fprintf(out, "  sw $s3, 92($sp)\n");
  fprintf(out, "  sw $s2, 88($sp)\n");
  fprintf(out, "  sw $s1, 84($sp)\n");
  fprintf(out, "  sw $s0, 80($sp)\n");
  fprintf(out, "  sw $a2, 76($sp)\n");

  fprintf(out, "  swc1 $f20, 72($sp)\n");                  
  fprintf(out, "  swc1 $f21, 68($sp)\n");
  fprintf(out, "  swc1 $f22, 62($sp)\n");
  fprintf(out, "  swc1 $f23, 58($sp)\n");                       
  fprintf(out, "  swc1 $f24, 54($sp)\n");
  fprintf(out, "  swc1 $f25, 50($sp)\n");
  fprintf(out, "  swc1 $f26, 46($sp)\n");
  fprintf(out, "  swc1 $f27, 42($sp)\n");            
  fprintf(out, "  swc1 $f28, 38($sp)\n");
  fprintf(out, "  swc1 $f29, 32($sp)\n");
  fprintf(out, "  swc1 $f30, 28($sp)\n");
  fprintf(out, "  swc1 $f31, 24($sp)\n");
  
    
  // 3.) replace the return address with __mcsema_attach_ret [re-attach function]
  fprintf(out, "  lw $ra, attach_ret_ptr\n");
 
  // 4.) the target address is passed as second argument to __remill_function_call
  //     ( $a1 in O32 abi ) store it somewhere, so that we can jump onto it.
  fprintf(out, "  move $t9, $a1\n");

  // 5.) restore register values from __mcsema_reg_state
// (Most) General purpose registers
  fprintf(out, "  lw $s0, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S0));
  fprintf(out, "  lw $s1, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S1));
  fprintf(out, "  lw $s2, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S2));
  fprintf(out, "  lw $s3, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S3));
  fprintf(out, "  lw $s4, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S4));
  fprintf(out, "  lw $s5, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S5));
  fprintf(out, "  lw $s6, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S6));
  fprintf(out, "  lw $s7, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S7));

  fprintf(out, "  lw $v0, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, V0));
  fprintf(out, "  lw $v1, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, V1));

  fprintf(out, "  lw $a3, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, A3));
  fprintf(out, "  lw $a2, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, A2));
  fprintf(out, "  lw $a1, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, A1)); 
  
  // Swap out a0
  fprintf(out, "  lw $a0, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, A0));

  
  // 7.) jump to target function
  fprintf(out, "  jr $t9\n");
  // must use $t9 for calling external functions, as they rely on
  // $t9 holding their value
  fprintf(out, "  .end __remill_function_call\n");
  fprintf(out, "\n");

  // Implements `__mcsema_attach_ret`. This goes from native state into lifted
  // code.
  fprintf(out, "  .globl __mcsema_attach_ret\n");
  fprintf(out, "  .type __mcsema_attach_ret,@function\n");
  fprintf(out, "__mcsema_attach_ret:\n");
  fprintf(out, ".ent __mcsema_attach_ret\n");
  
  // Save values of $a0 and $a1, as they will be
  // used to load __mcsema_reg_state
  fprintf(out, "  move $t0, $a0\n");
  fprintf(out, "  move $t1, $a1\n");
  
 /* save value of v0, as it will now hold addr of __mcsema_reg_state */
  // fprintf(out, "  move $t4, $v0\n");
  
  // load mcsema_reg_state in v0
  fprintf(out, "  rdhwr $a1, $29\n");
  fprintf(out, "  lui $a0, %%tprel_hi(__mcsema_reg_state)\n");
  fprintf(out, "  addiu $a0, $a0, %%tprel_lo(__mcsema_reg_state)\n");
  fprintf(out, "  addu $a0, $a0, $a1\n");

  // copy values from cpu to reg_state
  fprintf(out, "  sw $t0, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, A0));
  fprintf(out, "  sw $t1, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, A1));
  fprintf(out, "  sw $a2, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, A2));
  fprintf(out, "  sw $a3, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, A3));

  fprintf(out, "  sw $v0, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, V0));
  fprintf(out, "  sw $v1, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, V1));

  fprintf(out, "  sw $s0, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S0));
  fprintf(out, "  sw $s1, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S1));
  fprintf(out, "  sw $s2, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S2));
  fprintf(out, "  sw $s3, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S3));
  fprintf(out, "  sw $s4, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S4));
  fprintf(out, "  sw $s5, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S5));
  fprintf(out, "  sw $s6, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S6));
  fprintf(out, "  sw $s7, %" PRIuMAX "($a0)\n", __builtin_offsetof(State, S7));
    
  fprintf(out, "  lw $ra, 116($sp)\n");                        
  fprintf(out, "  lw $s8, 112($sp)\n");
  fprintf(out, "  lw $s7, 108($sp)\n");
  fprintf(out, "  lw $s6, 104($sp)\n");                      
  fprintf(out, "  lw $s5, 100($sp)\n");
  fprintf(out, "  lw $s4, 96($sp)\n");
  fprintf(out, "  lw $s3, 92($sp)\n");
  fprintf(out, "  lw $s2, 88($sp)\n");
  fprintf(out, "  lw $s1, 84($sp)\n");
  fprintf(out, "  lw $s0, 80($sp)\n");
  fprintf(out, "  lw $a2, 76($sp)\n");

// added for floating point registers 
  fprintf(out, "  lwc1 $f20, 72($sp)\n");                    
  fprintf(out, "  lwc1 $f21, 68($sp)\n");
  fprintf(out, "  lwc1 $f22, 62($sp)\n");
  fprintf(out, "  lwc1 $f23, 58($sp)\n");                       
  fprintf(out, "  lwc1 $f24, 54($sp)\n");
  fprintf(out, "  lwc1 $f25, 50($sp)\n");
  fprintf(out, "  lwc1 $f26, 46($sp)\n");
  fprintf(out, "  lwc1 $f27, 42($sp)\n");
  fprintf(out, "  lwc1 $f28, 38($sp)\n");
  fprintf(out, "  lwc1 $f29, 32($sp)\n");
  fprintf(out, "  lwc1 $f30, 28($sp)\n");
  fprintf(out, "  lwc1 $f31, 24($sp)\n");
  fprintf(out, "  addiu $sp, $sp, 120\n");
  
  // return to the lifted function
  fprintf(out, "  jr $ra\n");
  fprintf(out, ".end __mcsema_attach_ret\n");
  fprintf(out, "\n");

  // Implements `__mcsema_exception_ret`. It gets called after the exception returns to the handler.
  // It sets the native stack and base pointers correctly after cleaning the stack. It also save the native
  // registers state.

  fprintf(out, "  .globl __mcsema_exception_ret\n");
  fprintf(out, "  .type __mcsema_exception_ret,@function\n");
  fprintf(out, "__mcsema_exception_ret:\n");
  fprintf(out, "  nop\n");
  fprintf(out, "\n");

  // Implements `__mcsema_get_stack_pointer`. Returns the stack pointer register.
  fprintf(out, "  .globl __mcsema_get_stack_pointer\n");
  fprintf(out, "  .type __mcsema_get_stack_pointer,@function\n");
  fprintf(out, "__mcsema_get_stack_pointer:\n");
  fprintf(out, "  rdhwr $v1, $29\n"); 
  fprintf(out, "  lui $v0, %%tprel_hi(__mcsema_reg_state)\n");
  fprintf(out, "  addiu $v0, $v0, %%tprel_lo(__mcsema_reg_state)\n");
  fprintf(out, "  addu $v0, $v0, $v1\n");
  fprintf(out, "  lw $sp, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, SP));
  fprintf(out, "  move $v0, $sp\n");
  fprintf(out, "  jr $ra\n");
  fprintf(out, "\n");

  // Implements `__mcsema_get_frame_pointer`. Returns the frame pointer register.
  fprintf(out, "  .globl __mcsema_get_frame_pointer\n");
  fprintf(out, "  .type __mcsema_get_frame_pointer,@function\n");
  fprintf(out, "__mcsema_get_frame_pointer:\n");
  fprintf(out, "  rdhwr $v1, $29\n"); 
  fprintf(out, "  lui $v0, %%tprel_hi(__mcsema_reg_state)\n");
  fprintf(out, "  addiu $v0, $v0, %%tprel_lo(__mcsema_reg_state)\n");
  fprintf(out, "  addu $v0, $v0, $v1\n");
  fprintf(out, "  lw $fp, %" PRIuMAX "($v0)\n", __builtin_offsetof(State, FP));
  fprintf(out, "  move $v0, $fp\n");
  fprintf(out, "  jr $ra\n");
  fprintf(out, "\n");

  // Implements `__mcsema_get_type_index`. Returns the base pointer register.
  fprintf(out, "  .globl __mcsema_get_type_index\n");
  fprintf(out, "  .type __mcsema_get_type_index,@function\n");
  fprintf(out, "__mcsema_get_type_index:\n");
  fprintf(out, "  .cfi_startproc\n");
  //fprintf(out, "  mov gs:[__mcsema_reg_state@TPOFF + %" PRIuMAX "], eax\n", __builtin_offsetof(State, EAX));
  fprintf(out, "  la $t1, __mcsema_reg_state\n");
  fprintf(out, "  addi $t1, $t1,%" PRIuMAX "\n", __builtin_offsetof(State,RAX));
  fprintf(out, "  sw $t1, ($s0)\n");

  fprintf(out, "  move $s0, $a0\n");
  fprintf(out, "  jr $ra\n");
  fprintf(out, "  .cfi_endproc\n");
  fprintf(out, "\n");

  // Implements `__mcsema_debug_get_reg_state`. This is useful when debugging in
  // gdb.
  fprintf(out, "  .globl __mcsema_debug_get_reg_state\n");
  fprintf(out, "  .type __mcsema_debug_get_reg_state,@function\n");
  fprintf(out, "__mcsema_debug_get_reg_state:\n");
  fprintf(out, "  .cfi_startproc\n");
  fprintf(out," la $s0, __mcsema_reg_state\n");
  fprintf(out," move $s0, $s0\n");
  fprintf(out," la  $a0, __mcsema_reg_state\n");
  fprintf(out, " add $t1, $s0, $a0\n");
  fprintf(out," la $s0, ($t1)\n");

  fprintf(out, " jr $ra\n");
  fprintf(out, "  .cfi_endproc\n");
  fprintf(out, "\n");

// Error functions.
  fprintf(out, "  .globl __remill_error\n");
  fprintf(out, "  .type __remill_error,@function\n");

  fprintf(out, "  .globl __remill_missing_block\n");
  fprintf(out, "  .type __remill_missing_block,@function\n");

  fprintf(out, "  .globl __remill_function_return\n");
  fprintf(out, "  .type __remill_function_return,@function\n");
  

  fprintf(out, "__remill_error:\n");
  fprintf(out, "  nop\n");
  fprintf(out, "__remill_missing_block:\n");
  fprintf(out, "  nop\n");
  fprintf(out, "__remill_function_return:\n");
  fprintf(out, "  nop\n");

  return 0;
}

#pragma clang diagnostic pop