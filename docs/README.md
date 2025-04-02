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
3. The player moves left or rigjt using **keyboard controls**.
4. A **timer** counts down, and chopping extends it slightly.
5. If the player moves into a branch or time runs out **game over**.

