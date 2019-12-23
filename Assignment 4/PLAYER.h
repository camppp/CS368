/* ******************************************************
 * Name: YUXUAN LIU(SIX LIU)
 * Wisc ID:  9077627603
 * OS: Windows
 * IDE (or text editor): Notepad++
 * Compiler:  g++
 * How long did the assignment take you to complete in minutes:  80 minutes
 * What other resources did you consult (copy and paste links below: N/A
*/ // ******************************************************
#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <vector>
#include <string>
#include "CAVE.h"

using namespace std;

/**
	This class simulates a player of Wumpus World game
	who is capable of shooting an arrow, picking up gold
	falling into a pit and eaten by a wumpus
**/
class PLAYER 
{
	vector<int> position; // position of the player
	string facing; // facing of the player, possible values: left,right,up,down
	bool hasArrow; // if the player has a arrow
	bool hasGold; // if the player has a gold
	enum STATUS 
	{
		ALIVE, EATEN, FALLEN, ESCAPED,
	};
	STATUS playerStatus; // status of the player
	
public:
	/**
		constructor of the player
		input: N/A
		return: N/A
	**/
	PLAYER();
	
	/**
		destructor of the player
		input: N/A
		return: N/A
	**/
	~PLAYER();
	
	/**
		retrieves the position of the player
		input: N/A
		return: the position vector of the player
	**/
	vector<int> Get_Position();
	
	/**
		get the next position of the player in the
		direction of the player's facing
		input: N/A
		return: position vector of the next square
	**/
	vector<int> Get_Next_Square(); 
	
	/**
		gets the facing of the player
		input: N/A
		return: the string facing of the player
	**/
	string Get_Facing();
	
	/**
		make the player turn left
		input: N/A
		return: void
	**/
	void Turn_Left();
	
	/**
		make the player turn right
		input: N/A
		return: void
	**/
	void Turn_Right(); 
	
	/**
		move the player forward in the direction 
		of the player's facing
		input: N/A
		return: void
	**/
	void Move_Forward();
	
	/**
		make the player pick up a gold
		input: the cave data structure
		return: true if the gold is picked up
		successfully, false otherwise
	**/	
	bool Pickup_Gold(CAVE &cave); 
	
	/**
		make the player shoot a arrow and simulate 
		the reaction of the wumpus
		input: the cave data structure
		return: true if the player shot an arrow and hit the 
		wumpus, false otherwise
	**/
	bool Shoot_Arrow(CAVE &cave);
	
	/**
	    make the player climb the ladder, ending the game
		input: N/A
		return: void
	**/
	void Climb_Ladder(); 
	
	/**
		if the player has an arrow
		input: N/A
		return: true if the player has an arrow, false otherwise
	**/
	bool Has_Arrow(); 
	
	/**
		if the player has a gold
		input: N/A
		return: true if the player has the gold, false otherwise
	**/
	bool Has_Gold(); 
	
	/**
		update the status of the player according 
		to the facing
		input: the cave data structure
		return: true if the player s alive, false otherwise
	**/
	bool Update_Player_Status(CAVE &cave); 
	
	/**
		if the player has escaped
		input: N/A
		return: true if the player has escaped, false otherwise
	**/
	bool Escaped();
	
	/**
		if the player has been eaten
		input: N/A
		return: true if the player has been eaten, false otherwise
	**/
	bool Eaten();
	
	/**
		if the player has fallen into a pit
		input: N/A
		return: true if the player has fallen into a pit, false otherwise
	**/
	bool Fell();
};
#endif
