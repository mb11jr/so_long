# so_long

The `so_long` project is a graphical 2D game developed using the MiniLibX library. The player navigates through a map filled with walls, collectibles, and an exit. The goal is to collect all items and reach the exit, avoiding any traps or dead ends. The project focuses on event handling, file parsing, and real-time rendering.

---

## 🎮 Gameplay Description

- The player controls a character that moves on a 2D grid-based map.
- The map contains:
  - **Walls** (`1`): impassable tiles.
  - **Floor** (`0`): empty spaces the player can walk on.
  - **Collectibles** (`C`): items the player must collect.
  - **Exit** (`E`): becomes accessible after collecting all collectibles.
  - **Player** (`P`): the starting point.
  - **Enemy** (`N`): death traps (bonus part)
- The game ends when the player collects all collectibles `C` and reaches the exit `E`.
- The game is over when the player touches an enemy trap `N` (bonus part).

---

## 🧠 Features & Logic

- ✅ **Map Parsing**: The game reads the map from a `.ber` file and checks:
  - Rectangular shape
  - Surrounded by walls
  - Contains at least one `P`, one `E`, and one `C`
  - Contains only valid characters
- ✅ **Path Validation**: Ensures all collectibles and the exit are reachable using **flood fill**.
- ✅ **Rendering**: Each tile is rendered with an image using MiniLibX.
- ✅ **Input Handling**: Arrow keys or WASD to move the player.
- ✅ **Move Counter**: The number of moves is displayed in the terminal.
- ✅ **Clean Exit**: Properly frees memory and exits cleanly on window close or ESC.

---

### 🛠️ How to Compile

Use the following command for the mandatory part:
```sh
make
```
Use the following command for the bonus part: (movement count on screen instead of terminal + enemies + animation)
```sh
make bonus
```

### 🚀 How to Run

For the madatory part:
```sh
./so_long maps/ok10.ber
```

For the bonus part:
```sh
./so_long_bonus maps/bonus/map0.ber
```
**Make sure to provide a valid .ber map file located inside the maps/ directory.**

### 🎮 Controls

**W or ↑**:	Move Up

**S or ↓**:	Move Down

**A or ←**:	Move Left

**D or →**:	Move Right

**ESC**:  	Quit the Game

### 🗺️ Map Example
```sh
111111
1P0C01
100001
1C0E11
111111
```
**Walls** = 1

**Player** = P

**Collectibles** = C

**Exit** = E

**Floor** = 0

### 📦 Assets

Images were loaded with MiniLibX and used to display:

* Walls

* Floor tiles

* Collectibles

* Exit (changes when all items are collected)

* Player sprite

* Enemy sprite (bonus part*)

💡 `All images are stored in the ./textures`


## 🧠 Learnings
* Handling real-time rendering and input in C

* File parsing and validation

* Depth-first search / flood-fill for path validation

* Managing memory and graphics using MiniLibX

---
---
---
---
---
Made with 💻 at 1337 School | Mohamed Bentaleb
