/* ******************************************************
 * Name: Yuxuan Liu
 * Wisc ID: 9077627603
 * OS: Windows
 * IDE (or text editor): Notepad++
 * Compiler: g++
 * How long did the assignment take you to complete in minutes: 500 minutes
 * What other resources did you consult (copy and paste links below: N/A
*/ // ******************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int MAX_CLASS_SIZE = 100;
const int MAX_NUMBER_OF_ASSIGNMENTS = 100;

// do not change these prototypes.  Add your code to the function definitions below
void Read_Grade_File(string names[MAX_CLASS_SIZE][2], int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS], int *number_of_students, int *number_of_assignments, const string input_filename);
void Format_Case_Of_Names(string names[MAX_CLASS_SIZE][2], const int number_of_students);
void Compute_Total_And_Percent(int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS], int total[], float percent[], int number_of_students, int number_of_assignments);
void Write_Formatted_Grades(string names[MAX_CLASS_SIZE][2], int total[], float percent[], const int number_of_students, const string output_filename);

// There is no need to change main. However you are encouraged to write code
// to write data to the console to check the correctness of each of your functions as
// as you work.
int main() 
{
	string input_filename="unformatted_grades.txt";
	string output_filename="formatted_grades.txt";
	string names[MAX_CLASS_SIZE][2];
	int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS];
	int number_of_students=0;
	int number_of_assignments=0;
	int total[MAX_CLASS_SIZE];
	float percent[MAX_CLASS_SIZE];

	Read_Grade_File(names, scores, &number_of_students, &number_of_assignments, input_filename);
	Format_Case_Of_Names( names, number_of_students);
	Compute_Total_And_Percent( scores, total, percent, number_of_students, number_of_assignments);
	Write_Formatted_Grades(names, total, percent, number_of_students, output_filename);
	return 0;
}

/*
  This function reads unformatted information from the source text file and 
  initialize the parameters with the contents of the file
  Input: 
	names[] The array of student names
	scores[] The scores of students
	*number_of_students the pointer to the number of students variable
	*number_of_assignments the pointer to the number of assignments variable
	input_filename the name of the input source text file
  Output: 
	void, changes the value of the parameters
*/
void Read_Grade_File(string names[MAX_CLASS_SIZE][2], int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS], int *number_of_students, int *number_of_assignments, const string input_filename)
{
	ifstream inFile;
	inFile.open(input_filename);
	if (!inFile) 
	{
		cerr << "Unable to open file";
		exit(1);
	}
	// if we cannot find the file, throw an error
	std::string line;
	std::string delimiter = " ";
	size_t pos = 0;
	std::string token;
	std::getline(inFile, line);
	while ((pos = line.find(delimiter)) != std::string::npos) 
	{
		token = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());
	}
	*number_of_students = atoi(line.c_str());
	// retrieve the first line to get the number of students
	std::getline(inFile, line);
	while ((pos = line.find(delimiter)) != std::string::npos) 
	{
		token = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());
	}
	*number_of_assignments = atoi(line.c_str());
	// retrieve the second line to get the number of assignments
	
	std::getline(inFile, line);
	for(int i = 0; i < *number_of_students; i++)
	{
		std::getline(inFile, line);
		int count = 0;
		while ((pos = line.find(delimiter)) != std::string::npos) 
		{
			token = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			if(count == 1)
			{
				names[i][0] = token;
				// get the student's first name
			}
			else if(count == 2)
			{
				names[i][1] = token; 
				// get the student's last name
			}
			else 
			{
				scores[i][count - 3] = atoi(token.c_str());
				// get the ith score
			}
			count++;
		}
		scores[i][count - 3] = atoi(line.c_str());
		// After the while loop, there's one score left to be processed
		// This is a corner case
	}
	// Iterate throught the following list of students, read their scores according to
	// the number of assignments
}

/*
  This function formats the names of students such that each word starts
  with a capital letter and the rest are all lowercase
  Input:
	names[] The array of student names
	number_of_students the number of students
  Output: 
	void, formats the names of students
*/
void Format_Case_Of_Names(string names[MAX_CLASS_SIZE][2], const int number_of_students)
{
	for(int i = 0; i < number_of_students; i++)
	{
		std::string firstName = names[i][0];
		for (std::string::size_type j = 0; j < firstName.length(); ++j)
		{
			if(j == 0)
			{
				names[i][0][0] = std::toupper(firstName[0]);
			}
			else
			{
				names[i][0][j] = std::tolower(firstName[j]);
			}
			
		}
		// format the first name
		std::string lastName = names[i][1];
		for (std::string::size_type j = 0; j < lastName.length(); ++j)
		{
			if(j == 0)
			{
				names[i][1][0] = std::toupper(lastName[0]);
			}
			else
			{
				names[i][1][j] = std::tolower(lastName[j]);
			}
		}
		// format the last name
	}
}


/*
  This function computes each student's total score and average percentage from 
  the socres of each assignment and the number of assignments
  Input: 
	names[] The array of student names
	total[] The total sums of scores of all assignments for each student
	percent[] The average percentage for each student
	number_of_students the number of students
	number_of_assignments the number of assignments
  Output: 
	void, calculates sum and average percentage of scores
*/
void Compute_Total_And_Percent(int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS], int total[], float percent[], int number_of_students, int number_of_assignments)
{
	for(int i = 0; i < number_of_students; i ++)
	{
		for(int j = 0; j < number_of_assignments;j++)
		{
			total[i] += scores[i][j];
		}
	}
	// calculate the total sum
	for(int j = 0; j < number_of_students; j ++)
	{
		percent[j] = (float)total[j] / number_of_assignments * 10;
	}
	// calculate the percentage
}

/*
  This function formats writes to specified file to form a grade report (transcript)
  of the formatted result
  Input: 
	names[] The array of student names
	total[] The total sums of scores of all assignments for each student
	percent[] The average percentage for each student
	number_of_students the number of students
	output_filename the name of the output formatted text file
  Output: 
	void, outputs the formatted "transcript" to specified file
*/
void Write_Formatted_Grades(string names[MAX_CLASS_SIZE][2], int total[], float percent[], const int number_of_students, const string output_filename)
{
	ofstream outFile;
	outFile.open(output_filename);
	std::string delimiter = ", ";
	if (!outFile) 
	{
		cerr << "Unable to open file";
		exit(1);
	}
	// if we cannot find the file, throw an error
	for(int i = 0; i < number_of_students; i++)
	{
		outFile << names[i][1] + delimiter  + names[i][0];
		int currCount = names[i][0].length() + delimiter.length()  + names[i][1].length();
		// the count of the current line length
		for(int j = 0; j < 20 - currCount; j++)
		{
			outFile<< " ";
		}
		// print the right amount of spaces
		outFile << total[i];
		currCount = 22 + std::to_string(total[i]).length();
		if(percent[i] != 100)
		{
			for(int j = 0; j < 27 - currCount; j++)
			{
				outFile<< " ";
			}
			// if the percentage is 100, 1 more space is needed
		}
		else{
			for(int j = 0; j < 26 - currCount; j++)
			{
				outFile<< " ";
			}
		}
		outFile << std::fixed << std::setprecision(1) << percent[i];
		outFile<< std::endl;
		// set the precision and write to file
	}
}

