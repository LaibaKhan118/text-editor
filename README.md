# Kilo Text Editor (C Implementation)

This is a minimal, terminal-based text editor written in C, following the popular [“Build Your Own Text Editor”](https://viewsourcecode.org/snaptoken/kilo/) tutorial by [Antirez](https://github.com/antirez).

It mimics features found in editors like `nano` or `vim`, using low-level terminal handling through `termios` and other Unix system calls.

## ✨ Features

- Raw mode terminal handling
- Cursor movement with arrow keys
- Text editing: insert, delete, and save
- File loading and saving
- Status bar
- Syntax highlighting (for C files)
- Tab handling and soft-wrapping
- Search functionality

## 🛠️ Build & Run

**Requirements:**
- GCC or Clang
- Unix-like environment (Linux/macOS or WSL on Windows)
- Make (optional, but recommended)

### Compile using `gcc`:

```bash
gcc -o kilo kilo.c -Wall
````

Or using `make`:

```bash
make
```

### Run:

```bash
./kilo filename.txt
```

Replace `filename.txt` with the file you want to edit. If the file does not exist, it will be created on save.

## 📂 File Structure

```
kilo.c           # Main editor code
README.md        # You're here!
Makefile         # Optional make support
```

## ⌨️ Controls

| Key          | Action                  |
| ------------ | ----------------------- |
| Ctrl + Q     | Quit editor             |
| Ctrl + S     | Save file               |
| Arrow Keys   | Move cursor             |
| Page Up/Down | Scroll through the file |
| Ctrl + F     | Search                  |

## 🧠 What I Learned

* Low-level terminal control using `termios`
* Raw input mode handling
* Memory management in C
* ANSI escape sequences for terminal output
* Implementing features like tab expansion, search, and syntax highlighting from scratch

## 🔗 Credits

* Based on [Kilo by Salvatore Sanfilippo (Antirez)](https://github.com/antirez/kilo)
* Step-by-step guidance from [View Source Code](https://viewsourcecode.org/snaptoken/kilo/)
