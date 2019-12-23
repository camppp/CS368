Wumpus World : Part II

The Wumpus World is a common problem from Artificial Intelligence courses which deals with an explorer navigating a dark cave filled with bottomless pits, horrible monsters, and valuable treasure. This homework problem is an adaption of the Wumpus World found in Russell and Norvig’s Artificial Intelligence:  A Modern Approach 3rd ed.

Our version of the game will be played on a 4x4 grid with one smelly monster, the Wumpus; three bottomless pits; one ladder, and one piece of gold. The explorer starts in grid square (1,1) at the location of the ladder armed only with a single arrow.  The explorer begins facing to the right; that is facing square (1,2). We’ll use matrix style labeling for the squares so that square (1,2) is in the top row, second column. If the player turns to the right they will be facing square (2,1).

Since the cave is very dark, the explorer can’t see into the adjacent squares, but can either smell the Wumpus if it is an adjacent square, feel a breeze if a pit is in an adjacent square, or see the gold if it is in the current square. Adjacent here means directly left, right, up, or down, but not diagonal.

The player can choose from the following options on their turn: rotate 90 degrees to the left, rotate 90 degrees to the right, move forward one square, shoot the arrow, pick up the gold, climbs the ladder, or quit. Additional options for debugging have been added to the game: printing the map and printing the player position and facing. The game ends when the player climbs the ladder, is eaten by the Wumpus, falls into a pit, or quits. Please see the file homework_4.cpp for the implementation of the game play.

In homework 3 we created the map of the cave. For this assignment we will be implementing a player class to track and manipulate data to represent the player.