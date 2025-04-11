# C++ Game Programming with SFML 
The First C++ Game programming Project - **Timberman Game**


## Timberman Game

A simple **Timberman** game built using **SFML** (Simple and Fast Multimedia Library).

## 📜 Game Instructions

- You control a **lumberjack** who chops a tree.
- The tree has **branches** on both sides.
- Your Goal is to chop the tree as much as possible **without getting hit by a branch**.
- You can move to **left** or **right** to avoid branches while chopping.
- The game has a **time limt**, which resets slightly every time you chop.
- If time runs out or you get hit by a branch, **the game ends**.

## 🛠️ How It Works

1. The **tree** consists of multiple segments, each potentially having a branch on either side.
2. When the player chops, the bottom segment disappers, and a new segment is generated at the top.
3. The player moves left or right using **keyboard controls**.
4. A **timer** counts down, and chopping extends it slightly.
5. If the player moves into a branch or time runs out **game over**.

## 🛠️ Game Components

1️⃣ Player

The player can move left or right.

Chopping a tree adds score and extends time.

2️⃣ Tree & Branches

The tree consists of a fixed trunk with randomly generated branches.

Branches shift downward after each chop.

3️⃣ Timer

The timer constantly decreases.

Chopping adds a small amount of time.

4️⃣ Scoring System

Each successful chop increases the score.


5️⃣ Sound & Effects

Chop sound plays on each hit.

A death animation appears when the player loses.

## 🎮 Controls
Key	Action
Left Arrow (←)	Chop left
Right Arrow (→)	Chop right
Escape (ESC)	Exit game

## 🏗️ Technologies Used

C++ for game logic

SFML for rendering, input handling, and sound

Object-oriented programming (OOP) for structuring game elements

## 🚀 How to Run

1. Install SFML on your system.

2. Clone this repository:
```bash
git clone https://github.com/yourusername/timberman-sfml.git  
cd timberman-sfml  
```

3. Compile the game:
```bash
g++ -o timberman main.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  
```
4. Run the game:

```bash
./Timberman  
```