# How to use this template
1. Double click on the main.code-workspace file. This will open the template in VS Code.
2. From the Explorer Window of VS Code navigate to the src folder and double click on the main.cpp file.
3. Press F5 on the keyboard to compile and run the program.

# Reference
The template is from this [tutorial video](https://www.youtube.com/watch?v=PaAcVk5jUd8)

# What I'm doing
- Conway's Game of Life: 2-d zero-player game
    - a cell is born if there are exactly 3 neighbouring alive cells
    - a cell remains alive if there are 2 or 3 neighbouring alive cells, otherwise the cell is dead
- use **C++** and **Raylib** for graphics and input control
- use **C++** for all calculations
- try to optimise using **OpenMP**
- ~0.9-1.8 times faster with OpenMP (speedup ~0.9-1.8)

# GUI keybinds
- before simulation 
    - **LEFT MOUSE BUTTON (LMB)** to mark cell states
    - **RIGHT MOUSE BUTTON (RMB)** to unmark the cell states
    - **R** to randomly initialise the cell states
    - **C** to clear the cell states
    - **ENTER** to start the simulation
- during simulation
    - **SPACEBAR** to pause the simulation
    - **SPACEBAR** <u>again</u> to continue the simulation
    - **S** to stop and reset the simulation when paused
