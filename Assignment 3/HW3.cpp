// Name: Yuxuan Liu
// CS Login: yuxuan
// Student ID： 9077627603

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <time.h>      // time

using namespace std;

// feel free to use this function if you wish
// purpose: generate random coordinates
// input: none
// output: a vector with 2 coordinates between 1,1 and 4,4
vector<int> Get_A_Random_Square() 
{
	return vector<int>{rand() % 4 + 1, rand() % 4 + 1};
}

// feel free to use this function if you wish
// purpose: verifies if the coordinates of a square fall within the cave
// input: coordinates of a square
// output: true if the square is in the cave otherwise false
bool Is_Square_Valid(const vector<int> &square) 
{
	for (auto e : square)
		if (e < 1 || e > 4)
			return false;
	return true;
}

// don't change this function
// purpose: prints a map of the cave to the console
// input: the printable map a vector of strings
// output: none - console output of the cave diagram
void Print_Cave_Diagram(const vector<string> &cave_diagram) 
{
	for (auto s : cave_diagram)
		cout << s << endl;
}

// Implement these functions below
// Do not change the function prototpyes
void Initialize_Cave(map<vector<int>, set<string> > &cave);
void Print_Square(map<vector<int>, set<string> > &cave, const vector<int> &rc);
void Get_Cave_Diagram(map<vector<int>, set<string> > &cave, vector<string> &cave_diagram);

// sample main function
int main() 
{
	srand(time(NULL)); // seed the random generator

	// Declare the cave data structure to 'map' coordinates to a 'set' of strings describing the cell contents
	map<vector<int>, set<string> > cave;
	
	Initialize_Cave(cave);

	vector<string> cave_diagram;
	Get_Cave_Diagram(cave, cave_diagram);
	Print_Cave_Diagram(cave_diagram);

	return 0;
}

// add the player, ladder, wumpus, pits, gold, stench, breeze to the map
// input: An uninitialized map that holds key:coordinate vectors value: Square content
// output: Initialize the map cave
void Initialize_Cave(map<vector<int>, set<string> > &cave) 
{
	vector<int> ld{ 1, 1};
	cave[ld].insert("ladder");
	// place the "ladder" in row 1 column 1
	vector<int> pl{ 1, 1};
	cave[pl].insert("player");
	// place the "player" at the same location as the ladder
	vector<int> wumpus = Get_A_Random_Square();
	std::set<string>::iterator it;
	while (true) 
	{
		bool validWumpus = true;
		if(cave[wumpus].empty())
		{
			break;
		}
		for (it = cave[wumpus].begin(); it != cave[wumpus].end(); ++it)
		{
			string temp = *it;
			if (temp == "ladder") 
			{
				wumpus = Get_A_Random_Square();
				validWumpus = false;
				break;
			}
			// checks for ladder
		}
		if (validWumpus) 
		{
			break;
		}
	}
	cave[wumpus].insert("wumpus");
	// place the "wumpus" - can't be in the same square as the ladder
	
	vector<int> pit = Get_A_Random_Square();
	for (int i = 0; i < 3; i++) 
	{
		if(cave[pit].empty())
		{
			cave[pit].insert("pit");
			continue;
		}
		// if set empty, directly add
		std::set<string>::iterator it;
		while (true) 
		{
			bool validPit = true;
			for (it = cave[pit].begin(); it != cave[pit].end(); ++it)
			{
				string temp = *it;
				if (temp == "ladder" || temp == "wumpus" || temp == "pit") 
				{
					pit = Get_A_Random_Square();
					validPit = false;
					break;
				}
				// checks for ladder, wumpus and pit
			}
			if (validPit) 
			{
				break;
			}
		}
		cave[pit].insert("pit");
	}
	// place the 3 "pits" - can't be in the same square as the ladder, wumpus, or another pit
	
	vector<int> gold = Get_A_Random_Square();
	while (true) 
	{
		bool validGold = true;
		if(cave[gold].empty())
		{
			break;
		}
		// if set empty, directly add
		for (it = cave[gold].begin(); it != cave[gold].end(); ++it)
		{
			
			string temp = *it;
			if (temp == "ladder" || temp == "pit") 
			{
				gold = Get_A_Random_Square();
				validGold = false;
				break;
			}
			// check for ladder and pits
		}
		if (validGold) 
		{
			break;
		}
	}
	cave[gold].insert("gold");
	// place the "gold" - can't be in the same square as a pit or the ladder
	
	for (int r = 1; r <= 4; r++) 
	{
		for (int c = 1; c <= 4; c++) 
		{
			vector<int> rc{r, c};
			bool validWumpus = false;
			for (it = cave[rc].begin(); it != cave[rc].end(); ++it)
			{
				string temp = *it;
				if (temp == "wumpus") 
				{
					validWumpus = true;
					break;
				}
			}
			// find if this block contains a wumpus
			if (validWumpus) 
			{
				vector<int> up{ r - 1, c };
				if (Is_Square_Valid(up)) 
				{
					cave[up].insert("stench");
				}
				vector<int> down{ r + 1, c };
				if (Is_Square_Valid(down)) 
				{
					cave[down].insert("stench");
				}
				vector<int> right{ r, c + 1 };
				if (Is_Square_Valid(right)) 
				{
					cave[right].insert("stench");
				}
				vector<int> left{ r, c - 1 };
				if (Is_Square_Valid(left)) 
				{
					cave[left].insert("stench");
				}
			}
			// add stench in the four directions
		}
	}
	// place the "stench" squares to the left, right, up, and down from the wumpus

	for (int r = 1; r <= 4; r++) 
	{
		for (int c = 1; c <= 4; c++) 
		{
			vector<int> rc{ r, c };
			bool validPit = false;
			for (it = cave[rc].begin(); it != cave[rc].end(); ++it)
			{
				string temp = *it;
				if (temp == "pit") 
				{
					validPit = true;
					break;
				}
			}
			// check if the current block contains a pit
			if (validPit) 
			{
				vector<int> up{ r - 1, c };
				if (Is_Square_Valid(up))
				{
					cave[up].insert("breeze");
				}
				vector<int> down{ r + 1, c };
				if (Is_Square_Valid(down)) 
				{
					cave[down].insert("breeze");
				}
				vector<int> right{ r, c + 1 };
				if (Is_Square_Valid(right)) 
				{
					cave[right].insert("breeze");
				}
				vector<int> left{ r, c - 1 };
				if (Is_Square_Valid(left)) 
				{
					cave[left].insert("breeze");
				}
			}
			// add breezes in four directions
		}
	}
	// place the "breeze" squares to the left, right, up, and down from the three pits
}


// print the contents of the square
// input: An initialized map and a vector that tells the function which square to print
// output: The printed square contents
void Print_Square(map<vector<int>, set<string> > &cave, const vector<int> &rc) 
{
	std::set<string>::iterator it;
	printf("This part of the cave contains\n");
	if (cave[rc].empty()) 
	{
		cout << "    nothing" << endl;
	}
	// if there is nothing
	else
	{
		for (it = cave.at(rc).begin(); it != cave.at(rc).end(); ++it)
		{
			string temp = *it;
			cout << "    " << temp << endl;
		}
	}
	// print the contents
	
}

// build a vector of strings where each string in the vector represents one row of the cave output
// input: An initialized map with squares filled with contents and a vector to direct output
// output: Set the vectors with the contents in squares to represent the entire map
void Get_Cave_Diagram(map<vector<int>, set<string> > &cave, vector<string> &cave_diagram) 
{
	int cell_rows = 5;
	int cell_columns = 11;
	int total_rows = cell_rows * 4 + 1;
	int total_columns = cell_columns * 4 + 1;
	// fill in with vertical cell divisions
	for (int r = 0; r < total_rows; r++) 
	{
		string row(total_columns, ' ');
		for (int c = 0; c < total_columns; c += cell_columns) 
		{
			row[c] = '|';
		}
		cave_diagram.push_back(row);
	}

	// udpate horizontal rows with '-'
	for (int i = 0; i < total_rows; i += cell_rows) 
	{
		cave_diagram[i] = string(total_columns, '-');
	}

	// update cell corners with '+'
	for (int r = 0; r < total_rows; r += cell_rows) 
	{
		for (int c = 0; c < total_columns; c += cell_columns) 
		{
			cave_diagram[r][c] = '+';
		}
	}
	// replace the part of the string with the cell contents
	for (int r = 1; r < total_rows; r += cell_rows) 
	{
		for (int c = 3; c < total_columns; c += cell_columns) 
		{
			int row= 0;
			int col = 0;
			if (r == 1) 
			{
				row = 1;
			}
			else 
			{
				row = (r - 1) / 5 + 1;
			}
			if (c == 3) 
			{
				col = 1;
			}
			// if we are at row 1 or col 1, directly assign it to index 1
			// otherwise this arithmetic will not work at either the first 
			// row or first column
			else
			{
				col = (c - 3) / 11 + 1;
			}
			vector<int> rc = { row, col };
			std::set<string>::iterator it;
			int tempRow = r;
			int tempCol = c;
			for (it = cave[rc].begin(); it != cave[rc].end(); ++it) 
			{
				string temp = *it;	
				for (int i = 0; i < temp.length(); i++) 
				{
					cave_diagram[tempRow][tempCol] = temp[i];
					tempCol++;
				}
				// iterate through the word to print to the right lcoation
				tempCol = c;
				tempRow++;
			}
			// iterate through words in a set, moves down by one index each time
		}
	}
}



