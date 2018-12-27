# MinOs

> kernel with keyboard and screen suport

# Operating System
> ubuntu or Debian

# Required softwares/tools
> ### Compiler for C code.
> - [GNU GCC](https://gcc.gnu.org/install/)
>
> ### Assembler for asm code.
> - [Nasm assembler](https://www.nasm.us/docs.php)
> 
> ### Linker to link asm and c code.
> - [GNU linker]() 
> 
> ### emulator to boot kernel
> - [QEMU emulator](https://www.qemu.org/download/)

# How to run
> change permission for files nasm.sh, compile.sh ,link.sh and run.sh
> ``` 
> sudo chmod +x nasm.sh compiler.sh link.sh run.sh
> ```
> compiler kernel.asm file
> ```
> ./nasm.sh
> ```
> compiler kernel.c file
> ```
> ./compiler.sh
> ```
> link binary files of kernel.asm and kernel.c
> ```
> ./link.sh
> ```
> Boot kernel in nasm emulator with i386 architecture
> ```
> ./run.sh
> ```
