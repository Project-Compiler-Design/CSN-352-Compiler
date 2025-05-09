# CSN-352-Compiler

This project implements a **C to MIPS compiler** using **3-address code (3AC)** as an intermediate representation.  
Currently, the project is in **Phase 1**, which involves building a **Lexical Analyzer** for tokenization.

---

## 📂 Project Directory Structure  
```bash
CSN-352-Compiler/
│── src/                 # Source code directory
│   ├── lexer.l          # Lex file for lexical analysis
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

### 1️⃣ Compile the Lexer  
```bash
make clean
make
```
### 2️⃣ Run the Test Cases
You may have to make the run.sh executable the first time:
```bash
chmod +x run.sh
```
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
    - Intermediate Representation: Will use 3AC (Three Address Code) in later phases.
    - Compiler Backend: Will generate MIPS Assembly Code.
## 📌 Notes

    - Ensure that flex, bison, and g++ are installed before running the project.
    - The project is structured to automatically generate output files in the output/ directory.