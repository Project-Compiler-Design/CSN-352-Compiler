# CSN-352-Compiler
This is a compiler to convert C to MIPS using 3adc code as an intermediate representation and implemented C++.


In order to run execute the following commands:
```bash 
flex lexanalyser.l
g++ lex.yy.c -lfl -o lexer
./lexer input1.c