# 🔍 Lexical Analyzer for C Programs  

[![Language](https://img.shields.io/badge/Made%20with-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-lightgrey.svg)](https://github.com/shubhamchaudhari007)
[![License](https://img.shields.io/badge/License-Open--Source-green.svg)](https://opensource.org/)
[![GitHub Stars](https://img.shields.io/github/stars/shubhamchaudhari007/Lexical-Analyzer-for-C?style=social)](https://github.com/shubhamchaudhari007/Lexical-Analyzer-for-C/stargazers)

---

## 🧠 Overview  

The **Lexical Analyzer for C** is a compiler front-end program written in **C language** that performs **lexical analysis** — the first phase of a compiler.  
It scans the source code and breaks it into meaningful **tokens** such as keywords, identifiers, constants, operators, and symbols.  

This project also includes **bracket validation**, **error handling**, and **color-coded token display**, giving a clear and interactive representation of how a compiler interprets C programs at the lexical level.

---

## ⚙️ Features  

✅ Detects and categorizes:  
- **Keywords** → `int`, `if`, `return`, etc.  
- **Identifiers** → variable and function names  
- **Operators & Symbols** → `+`, `-`, `*`, `/`, `=`, `;`, `{}`, `()`, `[]`  
- **Constants** → integer, float, character, and string literals  
- **Comments** → single-line `//` and multi-line `/*...*/`  
- **Error Detection** → invalid tokens, missing terminators, or unbalanced brackets  

✅ Performs **Bracket Matching** (detects unclosed or mismatched `{}`, `()`, `[]`)  
✅ Displays **color-coded output** for better readability  
✅ Designed with **modular structure and clean C code**

---

## 🧩 Project Structure  

Lexical-Analyzer-for-C/
│
├── main.c # Entry point - file reading and token management
├── token.c # Core token identification logic
├── Info.c # Helper functions and symbol validations
├── Info.h # Header file for function declarations & macros
└── sample.c # Example input file to test lexical analysis

---

## 🧾 Example Input  

**File: `sample.c`**
```c
#include <stdio.h>

int main() {
    int num = 10;
    float pi = 3.14;
    char c = 'A';
    printf("Number: %d, PI: %f, Char: %c\n", num, pi, c);
    return 0;
}
```
🖥️ Example Output
```
Keyword        : int
Identifier     : main
Symbol         : (
Symbol         : )
Symbol         : {
Keyword        : int
Identifier     : num
Operator       : =
Numeric Const  : 10
Symbol         : ;
Keyword        : float
Identifier     : pi
Operator       : =
Float Const    : 3.14
Symbol         : ;
Keyword        : char
Identifier     : c
Operator       : =
Character Const: 'A'
Symbol         : ;
Identifier     : printf
Symbol         : (
String Literal : "Number: %d, PI: %f, Char: %c\n"
Symbol         : ,
Identifier     : num
Symbol         : ,
Identifier     : pi
Symbol         : ,
Identifier     : c
Symbol         : )
Symbol         : ;
Keyword        : return
Numeric Const  : 0
Symbol         : ;
Symbol         : }

```
---
🧠 How It Works
Reads each character from the input C file.

Detects token types based on patterns (alphabet, digit, operator, etc.).

Tracks line numbers, validates bracket balance, and identifies token boundaries.

Reports errors for invalid or unclosed tokens.

Outputs each token with category and color highlighting.

---

🧰 Technologies Used

Language: C

Concepts: Compiler Design, Tokenization, File Handling

Environment: GCC / Linux / Windows

---

⚡ How to Run
Step 1: Clone the Repository

git clone https://github.com/shubhamchaudhari007/Lexical-Analyzer-for-C.git
cd Lexical-Analyzer-for-C

Step 2: Compile

For Linux or macOS:
gcc main.c token.c Info.c -o lexical_analyzer

For Windows (MinGW / Code::Blocks):
gcc main.c token.c Info.c -o lexical_analyzer.exe

Step 3: Run
./lexical_analyzer sample.c

or on Windows:
lexical_analyzer.exe sample.c

---
🚧 Error Handling

Missing Terminator	"Hello	⚠️ ERROR: Missing Terminating Character
Invalid Constant	10.2.5	⚠️ Invalid floating constant (too many dots)
Unclosed Brackets	{ int a = 5;	❌ ERROR: Unclosed Brackets Detected {
Unterminated Comment	/* comment	❌ ERROR: Unterminated Comment

---

📚 Learning Outcome
This project helped me understand the core logic behind compiler design, particularly how lexical analysis works internally.
It deepened my knowledge of C programming, string processing, and syntax parsing, while giving hands-on experience in error detection and modular code development.

---
👨‍💻 Author
Shubham Chaudhari
📧 shubhamchaudhari508@gmail.com
🔗 LinkedIn([https://www.linkedin.com/in/shubham-chaudhari-102672260](https://www.linkedin.com/in/shubham-chaudhari-102672260/))
💻 GitHub()

---

⭐ Support
If you like this project, please consider starring 🌟 the repository and sharing it with others.
Your support motivates me to build more open-source projects!
