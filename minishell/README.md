# Minishell

## 📖 Overview
**Minishell** is a simplified Unix shell, developed as part of the 42 curriculum.  
The project’s goal was to create a working command-line interpreter with core features of `bash`, while deepening knowledge of **parsing, processes, signals, and file descriptors**.

---

## ✨ Features
- Interactive prompt that reads and executes user input
- Launches binaries with `execve`
- **Pipes (`|`)** for multiple commands
- **Redirections**: `>`, `>>`, `<`, `<<` (heredoc)
- Built-in commands:
  - `echo` (with `-n`)
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`
- Environment variable expansion (`$VAR`)
- Proper error handling and return codes
- Signal handling (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`) like in bash

---

## 🔧 Skills & Concepts
- **Parsing & Lexing**: Tokenizing complex command input
- **Processes**: `fork`, `execve`, `waitpid`
- **File Descriptors**: Pipes and redirections
- **Signals**: Interactive terminal management
- **Memory Management**: Leak prevention and stability
