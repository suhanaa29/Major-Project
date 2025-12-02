# 🎮 Monster Tamer RPG — C Programming Major Project

**Monster Tamer RPG** is a text-based, turn-based adventure game written entirely in **C**.  
It is developed as the semester **Major Project**, demonstrating all fundamental C programming concepts — including variables, loops, functions, arrays, structures, modular programming, and file handling.

The player explores different zones, encounters wild monsters, battles them, tames them, and builds a strong team.

---

## 📁 Project Structure

MonsterTamer/
├── src/
│ ├── main.c
│ ├── monster.c
│ ├── battle.c
│ ├── save_load.c
│ └── utils.c
│
├── include/
│ ├── monster.h
│ ├── battle.h
│ ├── save_load.h
│ └── utils.h
│
├── docs/
│ └── ProjectReport.pdf
│
├── assets/ (optional: screenshots)
├── sample_input.txt
└── README.md


---

## 🚀 Features

- Choose a starter monster  
- Explore 3 unique zones (Forest / Cave / Lake)  
- Random wild monster encounters  
- Turn-based battle system  
- Use items during battles (Potions, Tame Orbs)  
- Tame wild monsters and expand your team  
- Monster XP and level-up system  
- Binary file saving & loading (`savegame.bin`)  
- Clean modular structure using headers + source files  

---

## 🧠 C Concepts Demonstrated

This project includes all semester-required C programming concepts:

- Variables & Data Types  
- Loops (for, while)  
- Conditional statements  
- Functions  
- Arrays  
- Structures  
- Binary File Handling  
- Modular Programming  
- Separate Header Files  
- Menu-driven system  
- User Input & Validation  

---

## 🛠️ Compile & Run

### **Using GCC inside VS Code terminal:**

```bash
gcc -std=c99 -Wall -Wextra src/*.c -Iinclude -o monster_tamer


