/* ******************************************************
 * Name: YUXUAN LIU(SIX LIU)
 * Wisc ID:  9077627603
 * OS: Windows
 * IDE (or text editor): Notepad++
 * Compiler:  g++
 * How long did the assignment take you to complete in minutes:  80 minutes
 * What other resources did you consult (copy and paste links below: N/A
*/ // ******************************************************

// Include appropriate libraries to work with input/output and strings.
#include <string>
#include <iostream>

using namespace std;

// function declarations -- do not changes these
// you must complete the function definitions below
string Get_Name();
void Print_Welcome_Message(string name);

// do not change main
int main() 
{
	string name;
	name = Get_Name();
	Print_Welcome_Message(name);
}


// Get_Name asks the user to enter their name
// Note: "Blackbeard", "Anne Bonny", and
// "Captain Jack Sparrow" are all valid names
// The user may also choose not to enter a name.
// input: none
// output: a string containing the user entered name
// Note: do not change the function prototype on the next line
string Get_Name() 
{
	// declare a variable to hold the name
	string name = "";
	
	// prompt the user to enter a name
	cout << "Enter your name: ";
	
	char in[200];
	cin.getline(in,200);
	// read the name entered by the user, length limited to 200 characters
	
	return in;
	// return the name entered by the user
	// i.e. replace the text "name" in the return
	// statement below with the name supplied by the user
	
}

// Prints the welcome message
// input: a string with the user's name
// output: writes the welcome message to the screen
// return value: none
void Print_Welcome_Message(string name) 
{	
	int welcomeLength = 0;
	if(name == "")
	{
		welcomeLength = sizeof("Hello ") - 1 + sizeof("! Welcome to CS 368 (C++)!") - 2;
		//There is one less space when there is no user input
	}
	else
	{
		welcomeLength = sizeof("Hello ") - 1 + sizeof("! Welcome to CS 368 (C++)!") - 1;
	}
	
	//calculate the length of welcome sentence to estimate how many * are printed
	
	cout<<endl<<"*"<<"*";
	for(unsigned int i = 0; i < name.length() + welcomeLength; i++)
	{
		printf("*");
	}
	cout<<"*"<<"*"<<endl;// print the top row of stars

	cout<<"*"<<" ";
	for(unsigned int i = 0; i < name.length() + welcomeLength; i++)
	{
		cout<<" ";
	}
	cout<<" "<<"*"<<endl;// print the second line
	if(name == "")
	{
		cout<<"* "<<"Hello"<<name<< "! Welcome to CS 368 (C++)! "<<"*"<<endl;
		// There is one less space when there is no user input
	}
	else
	{
		cout<<"* "<<"Hello "<<name<< "! Welcome to CS 368 (C++)! "<<"*"<<endl;
	}
	// print the welcome message
	
	cout<<"*"<<" ";
	for(unsigned int i = 0; i < name.length() + welcomeLength; i++)
	{
		cout<<" ";
	}
	cout<<" "<<"*"<<endl;// print the fourth line

	cout<<"*"<<"*";
	for(unsigned int i = 0; i < name.length() + welcomeLength; i++)
	{
		printf("*");
	}
	cout<<"*"<<"*"<<endl;// print the bottom row of stars

	return;
}


/* Sample console text - the console should appear exactly as follows
Including white spaces
I use an automatic grading script to easily identify correct work.


Enter your name: Mike

****************************************
*                                      *
* Hello Mike! Welcome to CS 368 (C++)! *
*                                      *
****************************************


Enter your name: The Dread Pirate Roberts

************************************************************
*                                                          *
* Hello The Dread Pirate Roberts! Welcome to CS 368 (C++)! *
*                                                          *
************************************************************


(If the user doesn't enter a name)
Enter your name:

***********************************
*                                 *
* Hello! Welcome to CS 368 (C++)! *
*                                 *
***********************************


*/
