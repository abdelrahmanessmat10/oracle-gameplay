
# Oracle Game – Academic Course & Character Guessing

An interactive **console-based guessing game** that uses a **binary decision tree** to identify either a university course or a campus character (like a professor or TA) by asking a series of yes/no questions. The system improves its accuracy over time by learning from incorrect guesses and updating its knowledge base dynamically.

---

## 🧠 Features

- 🔁 **Dynamic Learning**: Learns new courses and characters by asking users for distinguishing questions after incorrect guesses.
- 🌲 **Binary Decision Tree**: Implements a recursive structure to store questions and answers.
- 💾 **Data Persistence**: Saves and loads knowledge across sessions using file I/O.
- 🔍 **Two Game Modes**:
  - Course Guessing
  - Character Guessing
- 🎮 **Console Interaction**: Simple and intuitive text-based interface.

---

## 🧱 Core Concepts Used

### 🔄 Binary Trees
Used to navigate decision paths (questions leading to guesses).

### 📌 Pointers
Used for dynamic memory allocation and node connections.

### 🔁 Recursion
To traverse, save, and load the binary tree structure.

### 💾 File Handling
To maintain persistent learning across game sessions using text files.

---

## 🛠️ How to Run

1. Compile the code using a C compiler (e.g. GCC):
   ```bash
   gcc main.c -o oracle_game
   ./oracle_game
   ```
2. Follow the menu options:
   - Select whether you want to guess **Courses** or **Characters**.
   - Answer the yes/no questions.
   - Help the system learn when it guesses incorrectly.
   - Exit to save your progress.

---

## 💡 Example Game Flow

1. Game asks: `Is the course theoretical?`
2. You answer: `Yes`
3. Game guesses: `Is it Data Structures?`
4. You respond: `No`
5. Game asks:
   - What was the correct course?
   - What is a distinguishing question?
6. Tree updates and saves new knowledge.

---

## 🧾 File Structure

- **main.c**: Main program logic and gameplay
- **tree.txt**: Text file where the decision tree is saved/loaded
- **Functions**:
  - `playGame()`
  - `learn()`
  - `saveTree()`
  - `readTree()`
  - `freeTree()`

---

## ⚙️ Dependencies

- Standard C Libraries:
  - `stdio.h`
  - `stdlib.h`
  - `string.h`

---

## 👥 Team Members

| Name                    |
|-------------------------|
| AbdelRahman Essmat      |
| Ziad Ahmed Rabie        |
| Mohammed Wageeh         |
| Hesham El-Kateb         |
| Abdelrahman Gabr        |
---

## ✅ Contributions

- Binary Tree implementation
- File I/O for saving and loading the tree
- Game modes: Courses & Characters
- Learning mechanism on incorrect guesses
- Recursive traversal logic

---

> “The Oracle never stops learning — thanks to you!”
