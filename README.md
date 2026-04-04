# Tic Tac Toe (C++ with AI)

## Overview

This project is a console-based Tic Tac Toe game developed in C++. It allows a human player to compete against the computer, which makes intelligent move decisions.

## Features

* Player vs Computer gameplay
* Turn-based interaction (Player vs AI)
* Input validation for safe moves
* Win and draw detection
* Basic AI decision-making

## Game Logic

The board is represented using a 3x3 grid. The player selects positions (1–9), and the computer responds with its move.

The AI follows a simple strategy:

* Checks if it can win in the next move
* Blocks the player if they are about to win
* Otherwise selects the best available position

## Technologies Used

* Language: C++
* Concepts:

  * Arrays
  * Functions
  * Conditional logic
  * Basic AI decision-making

## How to Run

### Compile

```bash id="b2m91a"
g++ tic_tac_toe.cpp -o tic_tac_toe
```

### Run

```bash id="x8k3pl"
./tic_tac_toe
```

## Sample Gameplay

```id="c4r9we"
Player (X): 1
Computer (O): 5
Player (X): 2
Computer (O): 3
Computer wins!
```

## Future Improvements

* Implement Minimax algorithm for unbeatable AI
* Add difficulty levels (easy, medium, hard)
* Build a graphical interface
* Track scores across multiple games

## Author

Oritree
