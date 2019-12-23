// uncomment the line below to run the program with input from the test file
// #define USE_THE_TEST_FILES

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

#ifdef USE_THE_TEST_FILES
#include <fstream>
std::ifstream cin;
std::ofstream cout;
#else
#include <iostream>
#endif
#include "ITEM.h"

using namespace std;

int main() {

#ifdef USE_THE_TEST_FILES
	cin.open("test_input.txt");
	cout.open("test_output.txt");
#endif

	vector<ITEM *> shopping_cart;
	cout<<"Welcome to The Pirate Supply Shoppe!\nWhat can I get for you today?"<<endl;
	while (true) {
		cout<<"  1) Cannon Balls"<<endl;
		cout<<"  2) Rum"<<endl;
		cout<<"  3) Limes"<<endl;
		cout<<"  4) Apparel"<<endl;
		cout<<"  5) Done Shopping"<<endl;
		cout<<"What would you like? ";
		int input;
		cin >> input;
		if (input != 5) {
			ITEM *item;
			switch (input) {
			case 1: {
				item = new BALLS();
			} break;
			case 2: {
				item = new RUM();
			} break;
			case 3: {
				item = new LIMES();
			} break;
			case 4: {
				item = new APPAREL();
			} break;
			default: {cout<<"We're completely out of that today. Check back tomorrow."<<endl;
			goto NEXT_ITERATION;
			}
			} // end of switch
			bool success = item->Process_Purchase(cin, cout);
			if (success) {
				shopping_cart.push_back(item);
				if (item->quantity) {
					string verb=(item->quantity==1)?"has been":"have been";
					cout<<*item <<" "<<verb<<" added to your shopping cart."<<endl;}
			}
			else cout<<"Transaction cancelled."<<endl;
		} // end (input!=5)
		if (input == 5) break; // done shopping

		NEXT_ITERATION:
		cout<<"\nWhat else can I get for you?"<<endl;
	} // end while loop

	if (shopping_cart.size()) {
		cout<<"\nLet me just get your receipt for you."<<endl;
		sort(shopping_cart.begin(), shopping_cart.end(), compare_pointers_to_items);
		int total = 0, width1 = 30, width2 = 10;
		for (auto item : shopping_cart) {
			stringstream ss;
			ss<<*item;
			cout<<setw(width1)<<left<<ss.str()<<setw(width2)<<right<<item->Get_Cost()<<endl;
			total += item->Get_Cost();
		}
		cout<<setw(width1)<<left<<"Total"<<setw(width2)<<right<<total<<endl;
	}
	else // You didn't buy anything.
		cout<<"Thanks for stopping by. Fair winds."<<endl;

#ifdef USE_THE_TEST_FILES
	cin.close();
	cout.close();
#endif
	return 0;
}



