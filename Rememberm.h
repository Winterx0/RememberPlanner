#pragma once
#include <iostream>
#include <fstream>
#include <string>

//add function for menu option to planner in base class: start menu, search data, write to file, display saved file,

using namespace std;

//base class
class Start
{
public:

	void startMsg()
	{
		cout << "Welcom to Remember Mine Planner!" << endl;
		cout << "Remember Mine planner is designed so you can make lists, " << endl;
		cout << "enter weekly and daily notes, as well as plan your day to day tasks by the hour." << endl;
		cout << "Select an option from the menu, write out what you need and press enter to move on." << endl;
		cout << "Create your own list to be stored or write out your weekly planner." << endl;
		cout << "What you type will be automatically saved to a new text file" << endl;
		system("pause");
		system("CLS");
	}
};

//child class
class RemSetUp : public Start
{
private:
	string writeLine; //input string

public:

	//function to open and output file
	void startRem()
	{
		
		ifstream infile("Remember.txt.txt"); //input file stream
		ofstream outfile("RemPlanner.txt"); //output file stream

		//opens text file
		if (infile.is_open())
		{
			//outputs text file to console
			if (outfile.is_open())
			{
				//reads through file until the end
				while (getline(infile, writeLine))
				{
					cout << writeLine << endl;
					outfile << cin.get();
					cin >> writeLine; // writes new line to each entry
					cin.ignore(500, '\n');
					outfile << writeLine << "\n"; //prints line
					

				} //end of while

				//outfile << writeLine << "\n"; //saves last printed text
				outfile.close(); //closes output file

			} //end of outfile

			//error if output file can not be opened
			else cout << "Unable to open output file. \n" << endl;

			infile.close(); //closes input file

		} //end of infile

		//error if input file can not be opened
		else cout << "Unable to open input file. \n" << endl;
		system("pause");
		system("CLS");

	} //end of void

}; //end of base class
