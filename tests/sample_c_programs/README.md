### testuite1
contains sample c programs that one can compile using mips cross-compiler, to lift, and recompile binaries. It is mainly to check the semantic behavious of original MIPS32 binary in comparision to newly generated binary, which was recompiled after lifting to LLVm-IR.

### testsuite2
contains sample c programs that one can lift with mcsema-lift with `explicit_args` flag. The bitcode generated with this is suitable for symbolic execution.

### Ideal KLEE configuration
Below is the setup used for symbolically executing `testsuite2` programs. 
It is recommended to use a 32-bit Ubuntu Virtual machine, instead of relying on the `-m32` flag of the compiler

- KLEE version 2.1
- STP version 2.3.3.
- KLEE uclibc 1.2
- LLVM 4.0.1
