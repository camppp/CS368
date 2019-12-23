/* ******************************************************
 * Name: YUXUAN LIU(SIX LIU)
 * Wisc ID:  9077627603
 * OS: Windows
 * IDE (or text editor): Notepad++
 * Compiler:  g++
 * How long did the assignment take you to complete in minutes:  80 minutes
 * What other resources did you consult (copy and paste links below: N/A
*/ // ******************************************************
#ifndef ITEM_TEMPLATE_H_
#define ITEM_TEMPLATE_H_

#include <string.h>

using namespace std;

/**
	ITEM is a parent abstract class that dictates how the child
	classes of item class should be implemented. This class simulates 
	an item (merchadise) in a pirate shop. It has three basic virtual 
	methods. Process_Purchase(), Get_Cost(), and Print().
	It also overrides the << operator and a string comparison
	method is provided. Inheritance, Polymorphism and Dynamic dispatch are used
**/
class ITEM 
{
public:
	string name; // name of the item
	int quantity; // quantity of the item purchased
	ITEM() : name(""), quantity(0){}
	~ITEM() {}
	ITEM(string name) : name(name), quantity(0) {}
	virtual bool Process_Purchase(istream &cin, ostream &cout) 
	{
		return true;
	}
	virtual int Get_Cost() const 
	{
		cout<<"don't call this function"<<endl;
		return 0;
	}
	virtual bool operator<(const ITEM& rhs) 
	{
		return this->name < rhs.name;
	}
	virtual void Print(ostream &out=cout) const 
	{
		out<<"Print the derived class info instead of this"<<endl;
	}
	// skeleton methods to be overriden in the child classes
};
ostream & operator<<(ostream &out, const ITEM &rhs) 
{
	rhs.Print(out); // instead of directly printing, Print() is called
	return out;
}
bool compare_pointers_to_items(ITEM *lhs, ITEM *rhs) 
{
	return *lhs < *rhs;
}

/**
	child class of ITEM that simulates the Cannon Ball
	merchandise. This class implements three methods
	Process_Purchase(), Get_Cost(), and Print()that 
	overrides their corresponding methods in parent class ITEM. 
	There are three types of cannon balls and this calls allwos the 
	shopper to select the kind and amount of cannon balls
**/
class BALLS : public ITEM 
{
	public:
		/**
			This function overrides Process_Purchase() in the parent 
			class. It simluates the purchase of a cannon ball item, and 
			prints console prompt accordingly.
			input: input stream and output stream objects
			return: bolean indicating if the purchase was successful
		**/
		bool Process_Purchase(istream &cin, ostream &cout) 
		{
			cout << endl << "Cannon Balls come in three sizes:" << endl;
			cout << "  1) Small     6 pieces of eight per Cannon Ball" << endl;
			cout << "  2) Medium   15 pieces of eight per Cannon Ball" << endl;
			cout << "  3) Large    52 pieces of eight per Cannon Ball" << endl;
			cout << "What size would you like? ";
			int kind;
			cin >> kind; // user input the type of cannon ball wanted
			if (kind != 1 && kind != 2 && kind != 3) 
			{
				return false;  // check for input validity
			}
			if (kind == 1) 
			{
				name = "20Small";
			}
			else if (kind == 2) 
			{
				name = "21Medium";
			}
			else if (kind == 3) 
			{
				name = "22Large";
			}
			// string prefix are added for later sorting the items
			cout << "How many would you like? ";
			cin >> quantity;
			if (quantity > 0) 
			{
				cout << "Happy hunting!" << endl;
				// check for validity of input
			}
			else {
				return false;
			}
			return true;
		}
		
		/**
			This function overrides Print() in its parent
			class. It first prints the quantity and then the
			type of cannon ball purchased
			input: output stream object
			return: void
		**/
		void Print(ostream &out = cout) const 
		{
			if(quantity == 1)
			{
				out << quantity << " " << name.substr(2,name.length()) << " Cannon Ball";
				// get rid of the prefix and then print
			}
			else 
			{
				out << quantity << " " << name.substr(2,name.length()) << " Cannon Balls";
			}
			// print different messages according ot the amount wanted
		}
		
		/**
			This function overrides Get_Cost() in its parent
			class. It calculates the cost of this purchase
			of cannon balls according to input
			input: N/A
			output: total cost of this purchase of cannon balls
		**/
		int Get_Cost() const 
		{
			if (name == "20Small") 
			{
				return quantity * 6;
			}
			else if (name == "21Medium") 
			{
				return quantity * 15;
			}
			else if (name == "22Large") 
			{
				return quantity * 52;
			}
			// return the cost of cannon balls purchased
		}
};

/**
	child class of ITEM that simulates the Alcolhol
	merchandise. This class implements three methods
	Process_Purchase(), Get_Cost(), and Print()that 
	overrides their corresponding methods in parent class ITEM.
	There are three kinds of alcolhol to be chosen. 
	This class allows the shopper to select the type and amount of 
	alcolhol drink wanted
**/
class RUM : public ITEM 
{
	public:
		/**
			This function overrides Process_Purchase() in the parent 
			class. It simluates the purchase of barrels of alcolhol
			merchadise, and prints console prompt accordingly.
			input: input stream and output stream objects
			return: bolean indicating if the purchase was successful
		**/
		bool Process_Purchase(istream &cin, ostream &cout) 
		{
			cout << endl << "We have three different qualities of Rum in stock:" << endl;
			cout << "  1) Swill     1 pieces of eight per barrel" << endl;
			cout << "  2) Grog      5 pieces of eight per barrel" << endl;
			cout << "  3) Fine Rum 19 pieces of eight per barrel" << endl;
			cout << "What kind would you like? ";
			int kind;
			cin >> kind;
			if (kind != 1 && kind != 2 && kind != 3) 
			{
				return false;
				// check for validiy of input
			}
			if (kind == 1) 
			{
				name = "40Swill";
				cout << "Gotta keep the crew happy!" << endl;
				// prints the reaction of the merchant
			}
			else if (kind == 2) 
			{
				name = "41Grog";
				cout << "The officers will love it!" << endl;
			}
			else if (kind == 3) 
			{
				name = "42Fine Rum";
				cout << "Nothing but the best for the captain!" << endl;
			}
			// string prefix are added for sorting
			cout << "How many barrels would you like? ";
			cin >> quantity;
			if (quantity <= 0) 
			{
				return false;
				// check for validity of input
			}
			return true;
		}

		/**
			This function overrides Print() in its parent
			class. It first prints the quantity and then the
			type of alcolhol purchased
			input: output stream object
			return: void
		**/
		void Print(ostream &out = cout) const 
		{
			if (quantity == 1) 
			{
				out << quantity << " " << "Barrel of " << name.substr(2,name.length());
			}
			else 
			{
				out << quantity << " " << "Barrels of " << name.substr(2,name.length());
			}
			// print the unit correctly with different inputs
		}

		/**
			This function overrides Get_Cost() in its parent
			class. It calculates the cost of this purchase
			of alcolhol according to input
			input: N/A
			return: total cost of this purchase of alcolhol
		**/
		int Get_Cost() const 
		{
			if (name == "40Swill") 
			{
				return quantity;
			}
			else if (name == "41Grog") 
			{
				return quantity * 5;
			}
			else if (name == "42Fine Rum") 
			{
				return quantity * 19;
			}
			// returns the cost of this purchase of alcohol drinks
			// according to input
		}
};

/**
	child class of ITEM that simulates the Lime
	merchandise. This class implements three methods
	Process_Purchase(), Get_Cost(), and Print()that 
	overrides their corresponding methods in parent class ITEM
**/
class LIMES : public ITEM 
{
	public:
		/**
			This function overrides Process_Purchase() in the parent 
			class. It simluates the purchase of limes in dozens
			merchadise, and prints console prompt accordingly
			input: input stream and output stream objects
			return: bolean indicating if the purchase was successful
		**/
		bool Process_Purchase(istream &cin, ostream &cout) 
		{
			cout << endl << "Limes arrr delicious. They're on sale for 7 pieces of eight per dozen." << endl;
			cout << "How many dozen would you like? ";
			cin >> quantity;
			name = "3Limes";
			quantity *= 12;
			// Note that limes comes in dozens, so when user 
			// inputs a number, the quantity is multiplied 12
			if (quantity <= 0) {
				return false;
			}
			return true;
		};
		
		/**
			This function overrides Print() in its parent
			class. It first prints the quantity and then lime
			the type name
			input: output stream object
			return: void
		**/
		void Print(ostream &out = cout) const 
		{
			out << quantity << " " << name.substr(1,name.length());
			// get rid of the prefix and then print
		}

		/**
			This function overrides Get_Cost() in its parent
			class. It calculates the cost of this purchase
			of lime according to input in dozens
			input: N/A
			return: total cost of this purchase of lime
		**/
		int Get_Cost() const 
		{
			return quantity / 12 * 7;
			// unit is in dozen
		}
};

/**
	child class of ITEM that simulates the Apparels
	merchandise. This class implements three methods
	Process_Purchase(), Get_Cost(), and Print() that 
	overrides their corresponding methods in parent '
	class ITEM.. Apparels have a fixed quantity of 1.
**/
class APPAREL : public ITEM 
{
	public:
		/**
			This function overrides Process_Purchase() in the parent 
			class. It simluates the purchase of different types of 
			apparels and prints console prompt accordingly
			input: input stream and output stream objects
			return: bolean indicating if the purchase was successful
		**/
		bool Process_Purchase(istream &cin, ostream &cout) 
		{
			cout << endl << "That looks like a rough injury." << endl;
			cout << "  1) Eyepatch  4 pieces of eight" << endl;
			cout << "  2) Pegleg   13 pieces of eight" << endl;
			cout << "  3) Hook     43 pieces of eight" << endl;
			cout << "You're going to need a ... ";
			int kind;
			cin >> kind;
			if (kind != 1 && kind != 2 && kind != 3) 
			{
				return false;
				// check for validity of input
			}
			quantity = 1;
			if (kind == 1) 
			{
				name = "1Eyepatch";
			}
			else if (kind == 2) 
			{
				name = "1Pegleg";
				cout << "We'll be getting more crutches in stock early next week." << endl;
				// special print message
			}
			else if (kind == 3) 
			{
				name = "1Hook";
			}
			return true;
		}
		
		/**
			This function overrides Print() in its parent
			class. It first prints the quantity and then 
			the type name of the apparel
			input: output stream object
			return: void
		**/
		void Print(ostream &out = cout) const 
		{
			out << 1 << " " << name.substr(1,name.length());
		}

		/**
			This function overrides Get_Cost() in its parent
			class. It calculates the cost of this purchase
			of the apparel according to input
			input: N/A
			return: total cost of this purchase of apparel
		**/
		int Get_Cost() const 
		{
			if (name == "1Eyepatch") 
			{
				return 4;
			}
			else if (name == "1Pegleg") 
			{
				return 13;
			}
			else if (name == "1Hook") 
			{
				return 43;
			}
			// prefix are added for sorting
		}
};
#endif
