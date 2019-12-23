/* ******************************************************
 * Name: YUXUAN LIU(SIX LIU)
 * Wisc ID:  9077627603
 * OS: Windows
 * IDE (or text editor): Notepad++
 * Compiler:  g++
 * How long did the assignment take you to complete in minutes:  80 minutes
 * What other resources did you consult (copy and paste links below: N/A
*/ // ******************************************************
#include "PLAYER.h"

/**
	constructor of the player, sets the player at
	position 1,1 facing right and does not have a gold
	and have an arrow
**/
PLAYER::PLAYER():
playerStatus(ALIVE)
{
	position.push_back(1);
	position.push_back(1);
	// initialize the initial position to be {1, 1}
	facing = "right";
	hasArrow = true;
	hasGold = false;
}

/**
	destructor does nothing
**/
PLAYER::~PLAYER(){}

/**
	returns the position of the player
**/
vector<int> PLAYER::Get_Position()
{
	return position;
}

/**
	get the next square the acoording to the facing of 
	the player, uses four different cases, each representing
	a direction
**/
vector<int> PLAYER::Get_Next_Square()
{
	vector<int> tempPosition = position;
	// temp variable to avoid changing the actual position
	if(facing.compare("right") == 0)
	{
		tempPosition = {position[0], position[1] + 1};
	}
	else if(facing.compare("left") == 0)
	{
		tempPosition = {position[0], position[1] - 1};
	}
	else if(facing.compare("up") == 0)
	{
		tempPosition = {position[0] - 1, position[1]};
	}
	else if(facing.compare("down") == 0)
	{
		tempPosition = {position[0] + 1, position[1]};
	}
	// four directions, four cases
	return tempPosition;
}

/**
	returns the facing of the player
**/
string PLAYER::Get_Facing()
{
	return facing;
}

/**
	change the facing of the player and make it rotate 
	counter clockwise 90 degrees, uses four different cases,
	each representing a direction
**/
void PLAYER::Turn_Left()
{
	if(facing.compare("right") == 0)
	{
		facing = "up";
	}
	else if(facing.compare("left") == 0)
	{
		facing = "down";
	}
	else if(facing.compare("up") == 0)
	{
		facing = "left";
	}
	else if(facing.compare("down") == 0)
	{
		facing = "right";
	}
	// four directions, four cases
}

/**
	change the facing of the player and make it rotate 
	clockwise 90 degrees, uses four different cases,
	each representing a direction
**/
void PLAYER::Turn_Right()
{
	if(facing.compare("right") == 0)
	{
		facing = "down";
	}
	else if(facing.compare("left") == 0)
	{
		facing = "up";
	}
	else if(facing.compare("up") == 0)
	{
		facing = "right";
	}
	else if(facing.compare("down") == 0)
	{
		facing = "left";
	}
	// four directions, four cases
}

/**
	change the position of the player to the 
	next square he/she should be according to
	his/her facing
**/
void PLAYER::Move_Forward()
{
	position = Get_Next_Square();
}

/**
	set the hasGold variable to true and remove
	the gold from cave
**/
bool PLAYER::Pickup_Gold(CAVE &cave)
{
	if(cave.Square_Contains_Gold(position))
	{
		hasGold = true;
		cave.Remove_Gold(position);
		return true;
	}
	return false;
}

/**
	if the player does not have an arrow, this function returns false
	if the player has an arrow, the fucntion goes to examine the squares
	in front of the player to see if the player has hit the wumpus or he/she 
	has missed by iterating through the cave parameter until it hits a wall.
**/
bool PLAYER::Shoot_Arrow(CAVE &cave)
{
	if(hasArrow == false)
	{
		return false;
	}
	hasArrow = false;
	vector<int> tempPosition = position;
	// temp variable to avoid changing the actual position
	while(true)
	{
		if(facing.compare("right") == 0)
		{
			tempPosition = {tempPosition[0], tempPosition[1] + 1};
		}
		else if(facing.compare("left") == 0)
		{
			tempPosition = {tempPosition[0], tempPosition[1] - 1};
		}
		else if(facing.compare("up") == 0)
		{
			tempPosition = {tempPosition[0] - 1, tempPosition[1]};
		}
		else if(facing.compare("down") == 0)
		{
			tempPosition = {tempPosition[0] + 1, tempPosition[1]};
		}
		// four directions, four cases
		if(tempPosition[0] == 0 || tempPosition[0] == 5 
			|| tempPosition[1] == 5 || tempPosition[1] == 0)
			// judge if the next position hits a wall
		{
			return false;
		}
		if(cave.Shoot_Square(tempPosition))
		{
			return true;
		}
	}
	return false;
}

/**
	change the player's status to ESCAPED
**/
void PLAYER::Climb_Ladder()
{
	playerStatus = ESCAPED;
}

/**
	checks if the player has an arrow
**/
bool PLAYER::Has_Arrow()
{
	return hasArrow;
}

/**
	checks if the player has a gold
**/
bool PLAYER::Has_Gold()
{
	return hasGold;
}

/**
	if the player is EATEN or FALLEN, change his/her
	status accordingly, otherwise the player is ALIVE
**/
bool PLAYER::Update_Player_Status(CAVE &cave)
{
	if(cave.Square_Contains_Living_Wumpus(position))
	{
		playerStatus = EATEN;
	}
	else if(cave.Square_Contains_Pit(position))
	{
		playerStatus = FALLEN;
	}
	if(playerStatus == ALIVE)
	{
		return true;
	}
	return false;
}

/**
	checks if the player has escaped
**/
bool PLAYER::Escaped()
{
	if(playerStatus == ESCAPED)
	{
		return true;
	}
	return false;
}

/**
	checks if the player is eaten by the wumpus
**/
bool PLAYER::Eaten()
{
	if(playerStatus == EATEN)
	{
		return true;
	}
	return false;
}

/**
	checks if the player has fallen into a pit
**/
bool PLAYER::Fell()
{
	if(playerStatus == FALLEN)
	{
		return true;
	}
	return false;
}