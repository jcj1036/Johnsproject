// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : main.cpp
// Course : Computational Problem Solving II (CPET-321) Section 2
// Developer : Johnathon Johnson and Andrew Quist
// Date : 12/03/2019 Fall 2019 (2191)
// Description :
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include "headers.h"
using namespace std;

int main() {

	sedan s1, s2, s3;
	compact c1, c2, c3;
	pickup p1, p2, p3;
	passenger *roster;
	//instantiation of sedans
	s1.setVehicle("Red", "Sedan");
	s2.setVehicle("Green", "Sedan");
	s3.setVehicle("Blue", "Sedan");
	//instantiation of compacts
	c1.setVehicle("Green", "Compact");
	c2.setVehicle("Blue", "Compact");
	c3.setVehicle("Yellow", "Compact");
	//instantiation of pickups
	p1.setVehicle("Purple", "Pickup");
	p2.setVehicle("Yellow", "Pickup");
	p3.setVehicle("Red", "Pickup");

	//reads the file and returns a linked list of passengers stored as roster.
	roster = read_file();
	//displays the roster linked list
	display_roster(roster);

	int input;
	do {
		//menu loops through until user chooses to exit
		cout << "Rowing Team Carpool Reservation System Menu..." << endl;
		cout
				<< " (1) - New Reservation\n (2) - Display Vehicle Diagram\n (3) - Modify a Reservation\n (4) - Delete a Reservation\n (5) - Print Vehicle Assignments\n (6) - Print Reservations (System Administrators Only)\n (0) - EXIT"
				<< endl;
		cout << "Please enter the number corresponding to your choice:" << endl;
		cin >> input;
		cin.ignore();
		if (input == 1) {			//if create
			create(roster, p1, p2, p3, s1, s2, s3, c1, c2, c3);
		} else if (input == 2) {			//if display
			display(s1, s2, s3, p1, p2, p3, c1, c2, c3);
		} else if (input == 3) {			//if modify
			modify(roster, p1, p2, p3, s1, s2, s3, c1, c2, c3);
		} else if (input == 4) {			//if delete
			Delete(roster, p1, p2, p3, s1, s2, s3, c1, c2, c3);
		} else if (input == 5) {			//if print
			print(roster, s1, s2, s3, c1, c2, c3, p1, p2, p3);
		} else if (input == 6) {			//if reservations
			reservations(p1, p2, p3, s1, s2, s3, c1, c2, c3);
		} else if (input == 0) {			//if EXIT
			cout << "Goodbye..." << endl;
			break;
		} else {

		}
	} while (true);

	return 0;
}
