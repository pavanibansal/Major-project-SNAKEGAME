SNAKE GAME
A snake game made in C using Windows console. You control a snake that moves around the screen eating fruit. Each time you eat fruit, the snake will grow longer and you get points. The goal is to reach 100 points without running into yourself.

How to play
W - Move up
A - Move left
S - Move down
D - Move right
X - Quit game

The snake ('O' for head, 'o' for body) moves around a board surrounded by walls (#),Fruit is marked with 'F'.

Rules
1.Each fruit will give 10 points,with a final score of 100 points to win.
2.Game ends if you run into your own tail 

Technical stuff
Uses Windows.h for console manipulation
Uses CHAR_INFO buffer to draw the entire screen at once (prevents flickering)

