#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include "headers.h"
using namespace std;

//reads the file of passengers and how many credits they have, then creates a linked list
//  of the passengers.
passenger *read_file() {
	ifstream inFile;

	inFile.open("seat_credits.txt");		//Open file named seat_credits.txt

	if (inFile.fail()) {					//If program didn't open file
		cout << "\nThe file did not successfully open... Program Terminated\n"
				<< endl;
		exit(1);
	}

	passenger *current, *head;//Pointer for head of linked list and pointer to traverse through linked list
	current = new passenger;						//Point to new node
	head = current;					//Point head of linked list at first node

	do {//Loop to get information from file and store in structure of each node
		getline(inFile, current->name);
		inFile >> current->credits;
		inFile.ignore();

		if (inFile.eof()) {	//If end of file has been reached point last node at NULL
			current->nextaddr = NULL;
			break;							//Exit Loop
		} else {
			current->nextaddr = new passenger;//Point current pointer at next address of new node
			current = current->nextaddr;
		}
	} while (true);

	inFile.close();							//Close File

	return (head);							//Return head of linked list
}


