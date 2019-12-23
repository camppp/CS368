Wumpus World : Part I

The Wumpus World is a common problem from Artificial Intelligence courses which deals with an explorer navigating a dark cave filled with bottomless pits, horrible monsters, and valuable treasure. This homework problem is an adaption of the Wumpus World found in Russell and Norvig’s Artificial Intelligence:  A Modern Approach 3rd ed.

Our version of the game will be played on a 4x4 grid with one smelly monster, the Wumpus; three bottomless pits; one ladder, and one piece of gold. The explorer starts in grid square (1,1) at the location of the ladder armed only with a single arrow.  The explorer begins facing to the right; that is facing square (1,2). We’ll use matrix style labeling for the squares so that square (1,2) is in the top row, second column. If the player turns to the right they will be facing square (2,1). See the diagram below.

Since the cave is very dark, the explorer can’t see into the adjacent squares, but can either smell the Wumpus if it is an adjacent square, feel a breeze if a pit is in an adjacent square, or see the gold if it is in the current square. Adjacent here means directly left, right, up, or down, but not diagonal. See the example cave below.

The player can choose from the following options turn 90 degrees to the left, turn 90 degrees to the right, move forward one square, shoot the arrow, pick up the gold, climbs the ladder, or quit. The game ends when the player climbs the ladder, is eaten by the Wumpus, falls into a pit, or quits.

For homework 3 we will only be creating the map of the cave.  In homework 4 we will be implementing the rest of the game. Note: I will be including my solution to the map functions with homework 4 in case something goes wrong with your implementation, this means that  homework 3 will not be accepted after the release of homework 4.