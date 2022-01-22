#pragma once

#include "Rememberm.h"
#include <cstdlib>
#include <iomanip>
#include <list>

using namespace std;


struct addListItem
{
    string item;   // inventory item name
    int qty;       // how many are in stock
};

// const for the max size of the record array
const int MAX_SIZE = 100;

// function prototypes
void addItem(addListItem list[], int& size);
void dispItem(const addListItem list[], int size);
void storeList();
char getMenuResponse();

//menu input
char getMenuResponse()
{
    char response;
    cout << "\n[Quitting this menu will take you to your weekly planner]\n";
    cout << endl << "Make your selection" << endl << "(A)dd Items to list, (D)isplay Items, (Q)uit Items Menu" << endl << "> ";
    cin >> response;
    cin.ignore(500, '\n');
    return toupper(response);

}

//adds item to inventory
void addItem(addListItem list[], int& size)
{
    addListItem tmp; // declare a temp item that we will load before putting in the array
    char response;
    char str[500]; //char array input for cin.getline
    if (size < MAX_SIZE) {
        system("cls");
        cout << "Please enter an item. " << endl;
        cout << "Enter item: " << endl << endl;
        cout << "Name: ";
        cin.getline(str, 500, '\n');
        tmp.item = str;
        cout << "Quantity: ";
        cin >> tmp.qty;
        cout << endl;
        // see if item should be added
        cout << "Add to list? (y/n) ";
        cin >> response;
        if (toupper(response) == 'Y')
            list[size++] = tmp;
    }
    else {
        cout << "List is full; cannot enter more units." << endl;
        system("pause");
    }
    system("cls");
}

//displays item in inventory
void dispItem(const addListItem list[], int size)
{
    system("cls");

    if (size < 1) {
        cout << "Nothing to display" << endl;
    }
    else {
        cout << "All tems in your list" << endl << endl;
        cout << fixed << setprecision(2);
        cout << "Item Name              Qty     " << endl;
        cout << "~~~~~~~~~~~~~~~~~~" << endl;

        cout << left;
        for (int i = 0; i < size; i++) {
            cout << setw(21) << list[i].item << right
                << setw(4) << list[i].qty << left << endl;
        }

        cout << "~~~~~~~~~~~~~~~~~~~" << endl;
        cout << right << setw(3) << size;
        cout << " items listed\n\n";
    }

    system("PAUSE");
    system("cls");
}

void storeList()
{
    string writer;
    //char str[500];
    ofstream outfile("RememberList.txt"); //output file stream

    if (outfile.is_open())
    {
        //cout << writer << endl;
        outfile << addItem << "\n";
        outfile << cin.get();
        //cin.getline(str, 500, '\n');
        cin >> writer;
        cin.ignore(500, '\n');
        outfile << writer << "\n"; //saves last printed text
        outfile.close(); //closes output file

    } //end of outfile

    //error if output file can not be opened
    else cout << "Unable to open output file. \n" << endl;
    system("pause");
    system("CLS");

}