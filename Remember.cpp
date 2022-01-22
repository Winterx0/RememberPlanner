#include "Rememberm.h"
#include "Rmenu.h"

//text file MUST be located in the same file directory as the .cpp file
int main()
{
	//Intro to program
	Start start;
	start.startMsg();

	/////////////////////////////

	addListItem itemlist[MAX_SIZE];
	int numItems = 0;
	bool run = true;
	LOOP1: do
	{
		cout << "List Manager - " << numItems << " items in your list." << endl;
		switch (getMenuResponse())
		{
			case 'A': addItem(itemlist, numItems); break;
			case 'D': dispItem(itemlist, numItems); break;
			case 'Q': run = false; break;
			default: cout << "That is NOT a valid choice" << endl;
		}
		//storeList(itemlist, numItems);
		//storeList(); break;

	} while (run); //end of LOOP1

	storeList();
	

	/////////////////////////////

	//menu to planner
	string answer;

	cout << "\nWould you like to open the weekly planner? [y/n]\n";
	cin >> answer;
	LOOP2: do
	{
		while (answer == "y")
		{
			cout << "\n\n";
			system("pause");
			system("CLS");
			break;
		}
		if (answer == "n")
		{
			cout << "\nPROGRAM EXITING...\n";
			system("pause");
			system("CLS");
			return 0;
		}
	} while (run); //end of LOOP2

	
	/////////////////////////////

	//opens text file from RemSetUp class by calling the public function 
	RemSetUp rsetup;
	rsetup.startRem();

	/////////////////////////////

	//menu to loop
	string goTo;
	

	cout << "\nWould you like to go back to your list or weekly planner? [y/n]\n";
	cin >> goTo;
	while (goTo == "y")
	{
		system("pause");
		system("CLS");
		break;
	}
	if (goTo == "n")
	{
		cout << "PROGRAM EXITING...\n";
		system("pause");
		system("cls");
		return 0;
	}

	/////////////////////////////
	
	//loop option selection
	string option;

	cout << "Choose an option [L]ist, [P]lanner\n";
	cin >> option;
	while (option == "L")
	{
		system("pause");
		system("CLS");
		goto LOOP1;
	}
	if (option == "P")
	{
		system("pause");
		system("CLS");
		goto LOOP2;
	}

	//return 0;

} //end of main