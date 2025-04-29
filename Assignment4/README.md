# CSN-352-Compiler

This project implements a **C to MIPS compiler** using **3-address code (3AC)** as an intermediate representation.  

---

## 📂 Project Directory Structure  
```bash
Assignment4/
│── src/                 # Source code directory
│   ├── scanner.l        # Lex file for lexical analysis
|   ├── parser.y         # File for syntax analysis and generation of 3AC
|   ├── codegen.cpp      # File for generation of MIPS code from 3AC
│── include/             # Auxillary directory
│   ├── 3AC.h            # header file for 3AC code generation
|   ├── functions.h      # Auxillary functions for 3AC code generation
|   ├── utility.h        # Data Structures definition for nodes
│── test/                # Test cases for the compiler
│   ├── input1.c         # Sample test case 1
│   ├── input2.c         # Sample test case 2
│   ├── input3.c         # Sample test case 3
│   ├── ...              # More test cases
│── output/              # Stores output files (Auto-generated)
│   ├── output1.s        # Output of input1.c
│   ├── output2.s        # Output of input2.c
│   ├── output3.s        # Output of input3.c
│── Makefile             # Build automation file
│── run.sh               # Script to execute test cases
│── README.md            # Project documentation


```
## ⚙️ How to Compile and Run  
Follow these steps to build and execute the lexical analyzer:

### 1️⃣ Compile the files 
```bash
make clean
make
```
### 2️⃣ Run the Test Cases
After that run script using:
```bash
./run.sh
```
### 3️⃣ Check Output
```bash
ls output/       # Lists all output files
cat output/output1.s   # View output for input1.c
cat output/output2.s   # View output for input2.c
```
### 4️⃣ Error Handling  
Errors for each code are written within the generated output file corresponding to that code.

## 🛠️ Implementation Details

    - Lexical Analysis: Uses Flex (Lex) to tokenize C source code.
    - Parsing: 
        Uses Bison (Yacc) to parse the tokenized code according to standard C grammar.
        Each of the output files contain symbol table and constant table generated after parsing. 
    - Intermediate Representation: Uses Three address code.
    - Compiler Backend: Generates MIPS Assembly Code to be run on a simulator like Qtspim

## 📌 Notes

    - Ensure that flex, bison, Qtspim and g++ are installed before running the project.
    - The project is structured to automatically generate output files in the output/ directory.