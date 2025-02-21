# CSN-352-Compiler

This project implements a **C to MIPS compiler** using **3-address code (3AC)** as an intermediate representation.  
Currently, the project is in **Phase 2**, which involves building a **Parser** for syntax analysis.

---

## 📂 Project Directory Structure  
```bash
Assignment2/
│── src/                 # Source code directory
│   ├── scanner.l          # Lex file for lexical analysis
|   ├── parser.y         # File for syntax analysis
│── test/                # Test cases for the compiler
│   ├── input1.c         # Sample test case 1
│   ├── input2.c         # Sample test case 2
│   ├── input3.c         # Sample test case 3
│   ├── ...              # More test cases
│── output/              # Stores output files (Auto-generated)
│   ├── output1.txt      # Output of input1.c
│   ├── output2.txt      # Output of input2.c
│   ├── output3.txt      # Output of input3.c
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
cat output/output1.txt   # View output for input1.c
cat output/output2.txt   # View output for input2.c
```
### 4️⃣ Error Handling  
Errors for each code are written within the generated output file corresponding to that code.

## 🛠️ Implementation Details

    - Lexical Analysis: Uses Flex (Lex) to tokenize C source code.
    - Parsing: 
        Uses Bison (Yacc) to parse the tokenized code according to standard C grammar.
        Each of the output files contain symbol table and constant table generated after parsing. 
    - Intermediate Representation: Will use 3AC (Three Address Code) in later phases.
    - Compiler Backend: Will generate MIPS Assembly Code.

## 📌 Notes

    - Ensure that flex, bison, and g++ are installed before running the project.
    - The project is structured to automatically generate output files in the output/ directory.