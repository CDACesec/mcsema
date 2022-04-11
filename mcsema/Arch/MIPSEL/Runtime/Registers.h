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

#ifndef MCSEMA_ARCH_MIPSEL_RUNTIME_REGISTERS_H_
#define MCSEMA_ARCH_MIPSEL_RUNTIME_REGISTERS_H_

// for backwords compatibilty
#define RAX gpr.v0.word
#define RBX gpr.v1.word
#define RCX gpr.a0.word
#define RDX gpr.a1.word
#define RSI gpr.a2.word
#define RDI gpr.a3.word
#define RSP gpr.sp.word 
#define RBP gpr.s0.word
#define R8 gpr.s1.word
#define R9 gpr.s2.word
#define R10 gpr.s3.word
#define R11 gpr.s4.word
#define R12 gpr.s5.word
#define R13 gpr.s6.word
#define R14 gpr.s7.word
#define R15 gpr.t8.word 
#define RIP gpr.ra.word
#define GS_BASE gpr.t0.word

//always equal to zero
#define ZERO gpr.zero.word /* 16 */

//assembler temporary, used by the assembler
#define AT gpr.at.word /* 20 */

//return value from a function call
#define V0 gpr.v0.word /* 24 */
#define V1 gpr.v1.word /* 28 */

//first four parameters of a function call

//first parameter of a function call
#define A0 gpr.a0.word
//second parameter of a function call
#define A1 gpr.a1.word
//third parameter of a function call
#define A2 gpr.a2.word
//fourth parameter of a function call
#define A3 gpr.a3.word

//Temp vars, need not be preserved
#define T0 gpr.t0.word
#define T1 gpr.t1.word
#define T2 gpr.t2.word
#define T3 gpr.t3.word
#define T4 gpr.t4.word
#define T5 gpr.t5.word
#define T6 gpr.t6.word
#define T7 gpr.t7.word

//Function variables, must be preserved
#define S0 gpr.s0.word
#define S1 gpr.s1.word
#define S2 gpr.s2.word
#define S3 gpr.s3.word
#define S4 gpr.s4.word
#define S5 gpr.s5.word
#define S6 gpr.s6.word
#define S7 gpr.s7.word

//Two more temporary variables
#define T8 gpr.t8.word
#define T9 gpr.t9.word

// Kernel use regs, may change unexpectedly
#define K0 gpr.k0.word
#define K1 gpr.k1.word

//Global Pointer
#define GP gpr.gp.word

// Stack Pointer
#define SP gpr.sp.word

//frame pointer or subroutine variable
#define FP gpr.fp.word /* also called S8, */

// return address of the last subroutine call
#define RA gpr.ra.word

//Program counter of the CURRENT instruction
#define PC gpr.pc.word /* 144 */

// single precision floating point registers

#define F0 cp1.D0.f0.word
#define F1 cp1.D0.f1.word
#define F2 cp1.D2.f2.word
#define F3 cp1.D2.f3.word

#define F4 cp1.D4.f4.word
#define F5 cp1.D4.f5.word
#define F6 cp1.D6.f6.word
#define F7 cp1.D6.f7.word

#define F8 cp1.D8.f8.word
#define F9 cp1.D8.f9.word
#define F10 cp1.D10.f10.word
#define F11 cp1.D10.f11.word

#define F12 cp1.D12.f12.word
#define F13 cp1.D12.f13.word
#define F14 cp1.D14.f14.word
#define F15 cp1.D14.f15.word

#define F16 cp1.D16.f16.word
#define F17 cp1.D16.f17.word
#define F18 cp1.D18.f18.word
#define F19 cp1.D18.f19.word

#define F20 cp1.D20.f20.word
#define F21 cp1.D20.f21.word
#define F22 cp1.D22.f22.word
#define F23 cp1.D22.f23.word

#define F24 cp1.D24.f24.word
#define F25 cp1.D24.f25.word
#define F26 cp1.D26.f26.word
#define F27 cp1.D26.f27.word

#define F28 cp1.D28.f28.word
#define F29 cp1.D28.f29.word
#define F30 cp1.D30.f30.word
#define F31 cp1.D30.f31.word

// Double precision floating point registers

#define D0 cp1.D0.DReg

#define D2 cp1.D2.DReg

#define D4 cp1.D4.DReg

#define D6 cp1.D6.DReg

#define D8 cp1.D8.DReg

#define D10 cp1.D10.DReg

#define D12 cp1.D12.DReg

#define D14 cp1.D14.DReg

#define D16 cp1.D16.DReg

#define D18 cp1.D18.DReg

#define D20 cp1.D20.DReg

#define D22 cp1.D22.DReg

#define D24 cp1.D24.DReg

#define D26 cp1.D26.DReg

#define D28 cp1.D28.DReg

#define D30 cp1.D30.DReg


#define SF0 fpr.f0.word
#define SF1 fpr.f1.word
#define SF2 fpr.f2.word
#define SF3 fpr.f3.word
#define SF4 fpr.f4.word
#define SF5 fpr.f5.word
#define SF6 fpr.f6.word
#define SF7 fpr.f7.word
#define SF8 fpr.f8.word
#define SF9 fpr.f9.word
#define SF10 fpr.f10.word
#define SF11 fpr.f11.word
#define SF12 fpr.f12.word
#define SF13 fpr.f13.word
#define SF14 fpr.f14.word
#define SF15 fpr.f15.word
#define SF16 fpr.f16.word
#define SF17 fpr.f17.word
#define SF18 fpr.f18.word
#define SF19 fpr.f19.word
#define SF20 fpr.f20.word
#define SF21 fpr.f21.word
#define SF22 fpr.f22.word
#define SF23 fpr.f23.word
#define SF24 fpr.f24.word
#define SF25 fpr.f25.word
#define SF26 fpr.f26.word
#define SF27 fpr.f27.word
#define SF28 fpr.f28.word
#define SF29 fpr.f29.word
#define SF30 fpr.f30.word
#define SF31 fpr.f31.word

/* tls storage access */
// todo

 /*segment registers for mips  ?*/
//todo


// #define AF aflag.af /* arthimetic flags not for mips */
// #define CF aflag.cf /* first update in state.h */
// #define DF aflag.df /* afterwards, come back and update here */
// #define OF aflag.of /* used when performing arithmetic ops */
// #define PF aflag.pf
// #define SF aflag.sf
// #define ZF aflag.zf

/* arithmetic flags */
#define AV aflag.v
#define AZ aflag.z 
#define AO aflag.o
#define AU aflag.u
#define AI aflag.i



#endif //MCSEMA_ARCH_MIPSEL_RUNTIME_REGISTERS_H_
// finish for hello world instructions , stat
