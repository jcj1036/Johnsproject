#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include "headers.h"
using namespace std;

//Function to display linked list of passengers
void display_roster(passenger *head) {
	int cnt = 1;//Variable to display a number next to each structure of a linked list

	passenger *current = head;		//Point current pointer at head of roster

	cout << "Roster: " << endl;			//Output first line to roster
	cout << "       Names          Credits" << endl;

	while (current != NULL) {//Output structure of each node until end of linked list is reached
		cout << right << setw(4) << cnt++ << ")  ";
		cout << left << setw(15) << current->name;
		cout << left << setw(5) << current->credits << endl;

		current = current->nextaddr;//Traverse current pointer to next node of linked list
	}
}

//displays a diagram of the vehicles and the seat availabilities and costs of available seats
void display(sedan s1, sedan s2, sedan s3, pickup p1, pickup p2, pickup p3,
		compact c1, compact c2, compact c3) {
	char X = 'X';
	cout << "Truck   Compact     Sedan" << endl;
	cout << "------   -------     -----" << endl;
	cout << "(-)" << "(";
	if (p1.get_pa() == false) { //checks to see if each seat is taken
		cout << X;		//if it is taken, an X is displayed
	} else {
		cout << p1.get_pv(); //otherwise the credit cost of that seat is displayed
	}
	cout << ")" << "   " << "(-)" << "(";
	if (c1.get_fc() == false) { //repeats this process for all 24 seats
		cout << X;
	} else {
		cout << c1.get_vcf();
	}
	cout << ")" << "     " << "(-)" << "(";
	if (s1.get_fs() == false) {
		cout << X;
	} else {
		cout << s1.get_vf();
	}
	cout << ")" << endl;
	cout << "         " << "(";
	if (c1.get_bc() == false) {
		cout << X;
	} else {
		cout << c1.get_vcb();
	}
	cout << ")" << "(";
	if (c1.get_bc2() == false) {
		cout << X;
	} else {
		cout << c1.get_vcb2();
	}
	cout << ")" << "     " << "(";
	if (s1.get_bs() == false) {
		cout << X;
	} else {
		cout << s1.get_vb();
	}
	cout << ")" << "(";
	if (s1.get_ms() == false) {
		cout << X;
	} else {
		cout << s1.get_vm();
	}
	cout << ")" << "(";
	if (s1.get_bs2() == false) {
		cout << X;
	} else {
		cout << s1.get_vb2();
	}
	cout << ")" << endl;

	cout << "(-)" << "(";
	if (p2.get_pa() == false) {
		cout << X;
	} else {
		cout << p2.get_pv();
	}
	cout << ")" << "   " << "(-)" << "(";
	if (c2.get_fc() == false) {
		cout << X;
	} else {
		cout << c2.get_vcf();
	}
	cout << ")" << "     " << "(-)" << "(";
	if (s2.get_fs() == false) {
		cout << X;
	} else {
		cout << s2.get_vf();
	}
	cout << ")" << endl;
	cout << "         " << "(";
	if (c2.get_bc() == false) {
		cout << X;
	} else {
		cout << c2.get_vcb();
	}
	cout << ")" << "(";
	if (c2.get_bc2() == false) {
		cout << X;
	} else {
		cout << c2.get_vcb2();
	}
	cout << ")" << "     " << "(";
	if (s2.get_bs() == false) {
		cout << X;
	} else {
		cout << s2.get_vb();
	}
	cout << ")" << "(";
	if (s2.get_ms() == false) {
		cout << X;
	} else {
		cout << s2.get_vm();
	}
	cout << ")" << "(";
	if (s2.get_bs2() == false) {
		cout << X;
	} else {
		cout << s2.get_vb2();
	}
	cout << ")" << endl;

	cout << "(-)" << "(";
	if (p3.get_pa() == false) {
		cout << X;
	} else {
		cout << p3.get_pv();
	}
	cout << ")" << "   " << "(-)" << "(";
	if (c3.get_fc() == false) {
		cout << X;
	} else {
		cout << c3.get_vcf();
	}
	cout << ")" << "     " << "(-)" << "(";
	if (s3.get_fs() == false) {
		cout << X;
	} else {
		cout << s3.get_vf();
	}
	cout << ")" << endl;
	cout << "         " << "(";
	if (c3.get_bc() == false) {
		cout << X;
	} else {
		cout << c3.get_vcb();
	}
	cout << ")" << "(";
	if (c3.get_bc2() == false) {
		cout << X;
	} else {
		cout << c3.get_vcb2();
	}
	cout << ")" << "     " << "(";
	if (s3.get_bs() == false) {
		cout << X;
	} else {
		cout << s3.get_vb();
	}
	cout << ")" << "(";
	if (s3.get_ms() == false) {
		cout << X;
	} else {
		cout << s3.get_vm();
	}
	cout << ")" << "(";
	if (s3.get_bs2() == false) {
		cout << X;
	} else {
		cout << s3.get_vb2();
	}
	cout << ")" << endl;
}


