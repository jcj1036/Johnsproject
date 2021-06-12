#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include "headers.h"
using namespace std;


//prints the list of passengers of a specific vehicle the list is printed to console as well
//  as to a file with the same name as the selected vehicle.
void print(passenger *head, sedan s1, sedan s2, sedan s3, compact c1,
		compact c2, compact c3, pickup p1, pickup p2, pickup p3) {
	int car;
	cout << "Select Vehicle to print... " << endl; //prompts user to select a vehicle from the list
	cout << "Vehicles: \n (1) Red Sedan\n (2) Green Sedan\n (3) Blue Sedan\n "
			"(4) Green Compact\n (5) Blue Compact\n (6) Yellow Compact\n "
			"(7) Purple Pickup\n (8) Yellow Pickup\n (9) Red Pickup" << endl;
	cin >> car;
	cin.ignore();

	if (car == 1) { //if red sedan is selected
		ofstream outfile("red_sedan.txt");
		if (outfile.fail()) {
			cout
					<< "\nThe file did not successfully open... Program Terminated\n"
					<< endl;
			exit(1);
		}
		if (!s1.get_fs()) { //checks to see if the front seat is taken
			outfile << s1.get_rf() << endl; //outputs the string name of the passenger who reserved the seat
			cout << s1.get_rf() << endl;
		}
		if (!s1.get_bs()) { //checks to see if the back seat is taken
			outfile << s1.get_rb() << endl; //outputs the string name of the passenger who reserved the seat
			cout << s1.get_rb() << endl;
		}
		if (!s1.get_bs2()) { //checks to see if the second back seat is taken
			outfile << s1.get_rb2() << endl; //outputs the string name of the passenger who reserved the seat
			cout << s1.get_rb2() << endl;
		}
		if (!s1.get_ms()) { //checks to see if the middle seat is taken
			outfile << s1.get_rm() << endl; //outputs the string name of the passenger who reserved the seat
			cout << s1.get_rm() << endl;
		}
		if (s1.get_fs() && s1.get_bs() && s1.get_bs2() && s1.get_ms()) { //if none of the seats are taken
			outfile << "No passengers in this vehicle" << endl; //outputs "no passengers in vehicle"
			cout << "No passengers in this vehicle" << endl;
		}
	} else if (car == 2) { //if green sedan is selected
		ofstream outfile("green_sedan.txt");
		if (outfile.fail()) {
			cout
					<< "\nThe file did not successfully open... Program Terminated\n"
					<< endl;
			exit(1);
		}
		if (!s2.get_fs()) { //checks each seat of the vehicle for a passenger
			outfile << s2.get_rf() << endl; //if the seat is taken the passengers name is outputted
			cout << s2.get_rf() << endl;
		}
		if (!s2.get_bs()) {
			outfile << s2.get_rb() << endl;
			cout << s2.get_rb() << endl;
		}
		if (!s2.get_bs2()) {
			outfile << s2.get_rb2() << endl;
			cout << s2.get_rb2() << endl;
		}
		if (!s2.get_ms()) {
			outfile << s2.get_rm() << endl;
			cout << s2.get_rm() << endl;
		}
		if (s2.get_fs() && s2.get_bs() && s2.get_bs2() && s2.get_ms()) {
			outfile << "No passengers in this vehicle" << endl;
			cout << "No passengers in this vehicle" << endl;
		}
	} else if (car == 3) { //if blue sedan is selected
		ofstream outfile("blue_sedan.txt");
		if (outfile.fail()) {
			cout
					<< "\nThe file did not successfully open... Program Terminated\n"
					<< endl;
			exit(1);
		}
		if (!s3.get_fs()) { //checks each seat of the vehicle for a passenger
			outfile << s3.get_rf() << endl; //if the seat is taken the passengers name is outputted
			cout << s3.get_rf() << endl;
		}
		if (!s3.get_bs()) {
			outfile << s3.get_rb() << endl;
			cout << s3.get_rb() << endl;
		}
		if (!s3.get_bs2()) {
			outfile << s3.get_rb2() << endl;
			cout << s3.get_rb2() << endl;
		}
		if (!s3.get_ms()) {
			outfile << s3.get_rm() << endl;
			cout << s3.get_rm() << endl;
		}
		if (s3.get_fs() && s3.get_bs() && s3.get_bs2() && s3.get_ms()) {
			outfile << "No passengers in this vehicle" << endl;
			cout << "No passengers in this vehicle" << endl;
		}
	} else if (car == 4) {
		ofstream outfile("green_compact.txt");
		if (outfile.fail()) {
			cout
					<< "\nThe file did not successfully open... Program Terminated\n"
					<< endl;
			exit(1);
		}
		if (!c1.get_fc()) { //checks each seat of the vehicle for a passenger
			outfile << c1.get_rfc() << endl; //if the seat is taken the passengers name is outputted
			cout << c1.get_rfc() << endl;
		}
		if (!c1.get_bc()) {
			outfile << c1.get_rbc() << endl;
			cout << c1.get_rbc() << endl;
		}
		if (!c1.get_bc2()) {
			outfile << c1.get_rbc2() << endl;
			cout << c1.get_rbc2() << endl;
		}
		if (c1.get_fc() && c1.get_bc() && c1.get_bc2()) {
			outfile << "No passengers in this vehicle" << endl;
			cout << "No passengers in this vehicle" << endl;
		}
	} else if (car == 5) {
		ofstream outfile("blue_compact.txt");
		if (outfile.fail()) {
			cout
					<< "\nThe file did not successfully open... Program Terminated\n"
					<< endl;
			exit(1);
		}
		if (!c2.get_fc()) { //checks each seat of the vehicle for a passenger
			outfile << c2.get_rfc() << endl; //if the seat is taken the passengers name is outputted
			cout << c2.get_rfc() << endl;
		}
		if (!c2.get_bc()) {
			outfile << c2.get_rbc() << endl;
			cout << c2.get_rbc() << endl;
		}
		if (!c2.get_bc2()) {
			outfile << c2.get_rbc2() << endl;
			cout << c2.get_rbc2() << endl;
		}
		if (c2.get_fc() && c2.get_bc() && c2.get_bc2()) {
			outfile << "No passengers in this vehicle" << endl;
			cout << "No passengers in this vehicle" << endl;
		}
	} else if (car == 6) {
		ofstream outfile("yellow_compact.txt");
		if (outfile.fail()) {
			cout
					<< "\nThe file did not successfully open... Program Terminated\n"
					<< endl;
			exit(1);
		}
		if (!c3.get_fc()) { //checks each seat of the vehicle for a passenger
			outfile << c3.get_rfc() << endl; //if the seat is taken the passengers name is outputted
			cout << c3.get_rfc() << endl;
		}
		if (!c3.get_bc()) {
			outfile << c3.get_rbc() << endl;
			cout << c3.get_rbc() << endl;
		}
		if (!c3.get_bc2()) {
			outfile << c3.get_rbc2() << endl;
			cout << c3.get_rbc2() << endl;
		}
		if (c3.get_fc() && c3.get_bc() && c3.get_bc2()) {
			outfile << "No passengers in this vehicle" << endl;
			cout << "No passengers in this vehicle" << endl;
		}
	} else if (car == 7) {
		ofstream outfile("purple_pickup.txt");
		if (outfile.fail()) {
			cout
					<< "\nThe file did not successfully open... Program Terminated\n"
					<< endl;
			exit(1);
		}
		if (!p1.get_pa()) { //checks each seat of the vehicle for a passenger
			outfile << p1.get_pr() << endl; //if the seat is taken the passengers name is outputted
			cout << p1.get_pr() << endl;
		}
		if (p1.get_pa()) {
			outfile << "No passengers in this vehicle" << endl;
			cout << "No passengers in this vehicle" << endl;
		}
	} else if (car == 8) {
		ofstream outfile("yellow_pickup.txt");
		if (outfile.fail()) {
			cout
					<< "\nThe file did not successfully open... Program Terminated\n"
					<< endl;
			exit(1);
		}
		if (!p2.get_pa()) { //checks each seat of the vehicle for a passenger
			outfile << p2.get_pr() << endl; //if the seat is taken the passengers name is outputted
			cout << p2.get_pr() << endl;
		}
		if (p2.get_pa()) {
			outfile << "No passengers in this vehicle" << endl;
			cout << "No passengers in this vehicle" << endl;
		}
	} else if (car == 9) {
		ofstream outfile("red_pickup.txt");
		if (outfile.fail()) {
			cout
					<< "\nThe file did not successfully open... Program Terminated\n"
					<< endl;
			exit(1);
		}
		if (!p3.get_pa()) { //checks each seat of the vehicle for a passenger
			outfile << p3.get_pr() << endl; //if the seat is taken the passengers name is outputted
			cout << p3.get_pr() << endl;
		}
		if (p3.get_pa()) {
			outfile << "No passengers in this vehicle" << endl;
			cout << "No passengers in this vehicle" << endl;
		}
	}

}

//creates a reservation file of all seats
void reservations(pickup p1, pickup p2, pickup p3, sedan s1, sedan s2, sedan s3,
		compact c1, compact c2, compact c3) {
	string password = "password";
	string password_in;

	ofstream outfile("reservation.txt"); // opens the file and checks that it opened
	if (outfile.fail()) {
		cout << "\nThe file did not successfully open... Program Terminated\n"
				<< endl;
		exit(1);
	}

	if (outfile.is_open()) {
		cout << "Enter the password: "; cin >> password_in; cin.ignore();
		if (password_in == password) // checks for the password
		{
			cout << "reservation file has been updated" << endl;
			outfile << "green pickup" << "\n"; //outputs all reservations to the file
					outfile << "-----------" << "\n";
					outfile << "front seat: " << p1.get_pr() << "\n";
					outfile << "\n";
					outfile << "purple pickup" << "\n";
					outfile << "-----------" << "\n";
					outfile << "front seat: " << p2.get_pr() << "\n";
					outfile << "\n";
					outfile << "red pickup" << "\n";
					outfile << "-----------" << "\n";
					outfile << "front seat: " << p3.get_pr() << "\n";
					outfile << "\n";
					outfile << "green compact" << "\n";
					outfile << "-----------" << "\n";
					outfile << "front seat: " << c1.get_rfc() << "\n";
					outfile << "back seat 1: " << c1.get_rbc() << "\n";
					outfile << "back seat 2: " << c1.get_rbc2() << "\n";
					outfile << "\n";
					outfile << "purple compact" << "\n";
					outfile << "-----------" << "\n";
					outfile << "front seat: " << c2.get_rfc() << "\n";
					outfile << "back seat 1: " << c2.get_rbc() << "\n";
					outfile << "back seat 2: " << c2.get_rbc2() << "\n";
					outfile << "\n";
					outfile << "red compact" << "\n";
					outfile << "-----------" << "\n";
					outfile << "front seat: " << c3.get_rfc() << "\n";
					outfile << "back seat 1: " << c3.get_rbc() << "\n";
					outfile << "back seat 2: " << c3.get_rbc2() << "\n";
					outfile << "\n";
					outfile << "green sedan" << "\n";
					outfile << "-----------" << "\n";
					outfile << "front seat: " << s1.get_rf() << "\n";
					outfile << "back seat 1: " << s1.get_rb() << "\n";
					outfile << "back seat 2: " << s1.get_rb2() << "\n";
					outfile << "middle seat: " << s1.get_rm() << "\n";
					outfile << "\n";
					outfile << "purple sedan" << "\n";
					outfile << "-----------" << "\n";
					outfile << "front seat: " << s2.get_rf() << "\n";
					outfile << "back seat 1: " << s2.get_rb() << "\n";
					outfile << "back seat 2: " << s2.get_rb2() << "\n";
					outfile << "middle seat: " << s2.get_rm() << "\n";
					outfile << "\n";
					outfile << "red sedan" << "\n";
					outfile << "-----------" << "\n";
					outfile << "front seat: " << s3.get_rf() << "\n";
					outfile << "back seat 1: " << s3.get_rb() << "\n";
					outfile << "back seat 2: " << s3.get_rb2() << "\n";
					outfile << "middle seat: " << s3.get_rm() << "\n";
					outfile << "\n";
					outfile.close();
		}
		else{cout << "incorrect password" << endl;}
	}

	return;
}
