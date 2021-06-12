#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include "headers.h"
using namespace std;


//creates a reservation and returns the updated linked list of passengers.
passenger *create(passenger *head, pickup& p1, pickup& p2, pickup& p3,
		sedan& s1, sedan& s2, sedan& s3, compact& c1, compact& c2,
		compact& c3) {
	string name_in; //name of passenger to make reservation for
	passenger *tmp; //passenger node to traverse through linked list
	bool found = false;     //bools used for loop exit sequence
	bool found_seat = false;
	bool found_fs = false;
	bool found_bs = false;
	bool found_ms = false;
	bool exit = false;
	bool exit_seat = false;
	bool exit_whole = false;
	bool exit_done = false;
	int select;
	int cat_sel;
	int car, seat;
	string finished;

	while (exit_whole != true) {//loop for entire function
		while (exit != true) {//loop to get a new name
			cout << "please enter your name: ";//user enters their name
			getline(cin, name_in);
			tmp = head;

			while (tmp != NULL) {//functions searches for the name
				if (name_in == tmp->name) {
					found = true;//if found the function can move on
					break;
				}
				tmp = tmp->nextaddr;
			}

			if (found == true) {//checks credits for the name found
				cout << "You have " << tmp->credits << " seat credits." << endl;//display credits left
				if (tmp->credits == 0) {
					cout
							<< "You have 0 credits and must find your own transportation"
							<< endl;
				} else {
					break;
				}
			} else if (found == false) {
				cout << "Name not found" << endl;
			}//will ask for another name if name is not found
		}
		found = false;//reset found

		while (exit_seat != true) {//loop for choosing a seat
			cout << "Select a seat by catagory[1] or specific[2]: ";
			cin >> select;
			cin.ignore();//get what the user wants to do
			if (select == 1) { //selected seat by category
				cout
						<< "select a category: front seat[1], back seat[2], middle seat[3]"
						<< endl;
				cin >> cat_sel;//get what type of seat the user wants
				cin.ignore();
				if (cat_sel == 1) {//user wants a front seat
					for (int i = 1; i <= 9; i++) {
						if (tmp->credits < 5) {
							cout
									<< "You do not have enough credits for a front seat"
									<< endl;
							break;
						}
						switch (i) {//case goes through each front seat and checks if it is availabe, then assigns the first available one
						case 1:
							if (p1.get_pa() == true) {//each case sets the user in that seat, subtracts credits, and tells them they are in that seat
								p1.set_seat(false, name_in);
								tmp->credits -= 5;
								cout << "You are in p1 fs." << endl;
								found_fs = true;
							}
							break;
						case 2:
							if (p2.get_pa() == true) {
								p2.set_seat(false, name_in);
								tmp->credits -= 5;
								cout << "You are in p2 fs." << endl;
								found_fs = true;
							}
							break;
						case 3:
							if (p3.get_pa() == true) {
								p3.set_seat(false, name_in);
								tmp->credits -= 5;
								cout << "You are in p3 fs." << endl;
								found_fs = true;
							}
							break;
						case 4:
							if (s1.get_fs() == true) {
								s1.set_fs(false, name_in);
								tmp->credits -= 5;
								cout << "You are in s1 fs." << endl;
								found_fs = true;
							}
							break;
						case 5:
							if (s2.get_fs() == true) {
								s2.set_fs(false, name_in);
								tmp->credits -= 5;
								cout << "You are in s2 fs." << endl;
								found_fs = true;
							}
							break;
						case 6:
							if (s3.get_fs() == true) {
								s3.set_fs(false, name_in);
								tmp->credits -= 5;
								cout << "You are in s3 fs." << endl;
								found_fs = true;
							}
							break;
						case 7:
							if (c1.get_fc() == true) {
								c1.set_fc(false, name_in);
								tmp->credits -= 5;
								cout << "You are in c1 fs." << endl;
								found_fs = true;
							}
							break;
						case 8:
							if (c2.get_fc() == true) {
								c2.set_fc(false, name_in);
								tmp->credits -= 5;
								cout << "You are in c2 fs." << endl;
								found_fs = true;
							}
							break;
						case 9:
							if (c3.get_fc() == true) {
								c3.set_fc(false, name_in);
								tmp->credits -= 5;
								cout << "You are in c3 fs." << endl;
								found_fs = true;
							}
							break;
						default:
							cout << "error at fs case" << endl;
						}			//switch fs
						if (found_fs == true) {
							found_seat = true;
							break;
						}
					}			//for loop fs
				}			//if sel fs
				if (cat_sel == 2) {//user wants a back seat
					for (int i = 1; i <= 12; i++) {//loops until a seat is found or not
						switch (i) {
						case 1:
							if (c1.get_bc() == true) {//each case will check their credits and reject a number too low. It will assign the user to the seat subtract credits and tell them what seat they have
								if (tmp->credits < 3) {
									cout
											<< "You do not have enough credits for a compact back seat"
											<< endl;
									break;
								}
								c1.set_bc(false, name_in);
								tmp->credits -= 3;
								cout << "You are in c1 bs1." << endl;
								found_bs = true;
							}
							break;
						case 2:
							if (c1.get_bc2() == true) {
								if (tmp->credits < 3) {
									cout
											<< "You do not have enough credits for a compact back seat"
											<< endl;
									break;
								}
								c1.set_bc2(false, name_in);
								tmp->credits -= 3;
								cout << "You are in c1 bs2." << endl;
								found_bs = true;
							}
							break;
						case 3:
							if (c2.get_bc() == true) {
								if (tmp->credits < 3) {
									cout
											<< "You do not have enough credits for a compact back seat"
											<< endl;
									break;
								}
								c2.set_bc(false, name_in);
								tmp->credits -= 3;
								cout << "You are in c2 bs1." << endl;
								found_bs = true;
							}
							break;
						case 4:
							if (c2.get_bc2() == true) {
								if (tmp->credits < 3) {
									cout
											<< "You do not have enough credits for a compact back seat"
											<< endl;
									break;
								}
								c2.set_bc2(false, name_in);
								tmp->credits -= 3;
								cout << "You are in c2 bs2." << endl;
								found_bs = true;
							}
							break;
						case 5:
							if (c3.get_bc() == true) {
								if (tmp->credits < 3) {
									cout
											<< "You do not have enough credits for a compact back seat"
											<< endl;
									break;
								}
								c3.set_bc(false, name_in);
								tmp->credits -= 3;
								cout << "You are in c3 bs1." << endl;
								found_bs = true;
							}
							break;
						case 6:
							if (c3.get_bc2() == true) {
								if (tmp->credits < 3) {
									cout
											<< "You do not have enough credits for a compact back seat"
											<< endl;
									break;
								}
								c3.set_bc2(false, name_in);
								tmp->credits -= 3;
								cout << "You are in c3 bs2." << endl;
								found_bs = true;
							}
							break;
						case 7:
							if (s1.get_bs() == true) {
								if (tmp->credits < 2) {
									cout
											<< "You do not have enough credits for a back seat"
											<< endl;
									break;
								}
								s1.set_bs(false, name_in);
								tmp->credits -= 2;
								cout << "You are in s1 bs1." << endl;
								found_bs = true;
							}
							break;
						case 8:
							if (s1.get_bs2() == true) {
								if (tmp->credits < 2) {
									cout
											<< "You do not have enough credits for a back seat"
											<< endl;
									break;
								}
								s1.set_bs2(false, name_in);
								tmp->credits -= 2;
								cout << "You are in s1 bs2." << endl;
								found_bs = true;
							}
							break;
						case 9:
							if (s2.get_bs() == true) {
								if (tmp->credits < 2) {
									cout
											<< "You do not have enough credits for a back seat"
											<< endl;
									break;
								}
								s2.set_bs(false, name_in);
								tmp->credits -= 2;
								cout << "You are in s2 bs1." << endl;
								found_bs = true;
							}
							break;
						case 10:
							if (s2.get_bs2() == true) {
								if (tmp->credits < 2) {
									cout
											<< "You do not have enough credits for a back seat"
											<< endl;
									break;
								}
								s2.set_bs2(false, name_in);
								tmp->credits -= 2;
								cout << "You are in s2 bs2." << endl;
								found_bs = true;
							}
							break;
						case 11:
							if (s3.get_bs() == true) {
								if (tmp->credits < 2) {
									cout
											<< "You do not have enough credits for a back seat"
											<< endl;
									break;
								}
								s3.set_bs(false, name_in);
								tmp->credits -= 2;
								cout << "You are in s3 bs1." << endl;
								found_bs = true;
							}
							break;
						case 12:
							if (s3.get_bs2() == true) {
								if (tmp->credits < 2) {
									cout
											<< "You do not have enough credits for a back seat"
											<< endl;
									break;
								}
								s3.set_bs2(false, name_in);
								tmp->credits -= 2;
								cout << "You are in s3 bs2." << endl;
								found_bs = true;
							}
							break;
						default:
							cout << "error at bs case" << endl;
						}			//switch bs
						if (found_bs == true) {
							found_seat = true;
							break;
						}
					}			//for loop bs
				}			//if sel bs
				if (cat_sel == 3) {//user wants a middle seat
					for (int i = 1; i <= 3; i++) {//loop until a seat is found
						switch (i) {//no need to check credits here because if they have 0 they would already be denied
						case 1://each case checks if seat is availabel, assigns the seat, subtracts credits and tells the user what seat it is.
							if (s1.get_ms() == true) {
								s1.set_ms(false, name_in);
								tmp->credits -= 1;
								cout << "You are in s1 ms." << endl;
								found_ms = true;
							}
							break;
						case 2:
							if (s2.get_ms() == true) {
								s2.set_ms(false, name_in);
								tmp->credits -= 1;
								cout << "You are in s2 ms." << endl;
								found_ms = true;
							}
							break;
						case 3:
							if (s3.get_ms() == true) {
								s3.set_ms(false, name_in);
								tmp->credits -= 1;
								cout << "You are in s3 ms." << endl;
								found_ms = true;
							}
							break;
						default:
							cout << "error at ms case" << endl;
						}			//switch ms
						if (found_ms == true) {//allows the loop to break once a seat is found
							found_seat = true;
							break;
						}
					}			//for loop ms
				}			//if sel ms
				if (cat_sel != 1 && cat_sel != 2 && cat_sel != 3) {
					cout << "invalid entry" << endl; //checks for invalid entry
				}
			}			//if sel by cat

			// select by seat ----------------------------------------------------

			else if (select == 2) {			//selected seat by specific seat
				cout //outputs the list of vehicles to choose from
						<< "Select vehicle: \n (1) Red Sedan\n (2) Green Sedan\n (3) Blue Sedan\n "
								"(4) Green Compact\n (5) Blue Compact\n (6) Yellow Compact\n "
								"(7) Purple Pickup\n (8) Yellow Pickup\n (9) Red Pickup"
						<< endl;
				cin >> car;
				cin.ignore();
				if (car == 1) { //red sedan
					cout
							<< "Select seat: \n (1) Front seat\n (2) Back seat\n (3) Middle seat\n "
							<< endl;
					cin >> seat;
					cin.ignore();
					if (seat == 1) { //front seat
						if (s1.get_fs()) {
							if (tmp->credits < 5) { //checks if the passenger has enough credits
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 5; //deducts the credit cost of the seat
								s1.set_fs(false, tmp->name); //sets the seat to unavailable and puts the passengers name on the seat
								cout << "Reservation #0" << endl; //reservation information
								found_seat = true;
							}
						} else { //front seat is not available
							cout << "Front seat is taken... " << endl;
						}
					} else if (seat == 2) { //same thing is repeated, checking for the back seat
						if (s1.get_bs()) {
							if (tmp->credits < 2) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 2;
								s1.set_bs(false, tmp->name);
								cout << "Reservation #1" << endl;
								found_seat = true;
							}
						} else if (s1.get_bs2()) { //checks if the second back seat is available if the first is not available
							if (tmp->credits < 2) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 2;
								s1.set_bs2(false, tmp->name);
								cout << "Reservation #2" << endl;
								found_seat = true;
							}
						} else { //neither back seats are available
							cout << "Both back seats are taken... " << endl;
						}
					} else if (seat == 3) { //same thing is repeated, checking for the middle seat
						if (s1.get_ms()) {
							if (tmp->credits < 1) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 1;
								s1.set_ms(false, tmp->name);
								cout << "Reservation #3" << endl;
								found_seat = true;
							}
						} else {
							cout << "Middle seat is taken... " << endl;
						}
					} else {
						cout << "Improper seat option..." << endl;
					}
				}
				if (car == 2) { //Green Sedan
					cout
							<< "Select seat: \n (1) Front seat\n (2) Back seat\n (3) Middle seat\n "
							<< endl;
					cin >> seat;
					cin.ignore();
					if (seat == 1) { //front seat is selected
						if (s2.get_fs()) {
							if (tmp->credits < 5) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 5;
								s2.set_fs(false, tmp->name);
								cout << "Reservation #4" << endl;
								found_seat = true;
							}
						} else {
							cout << "Front seat is taken... " << endl;
						}
					} else if (seat == 2) { //back seat is selected
						if (s2.get_bs()) {
							if (tmp->credits < 2) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 2;
								s2.set_bs(false, tmp->name);
								cout << "Reservation #5" << endl;
								found_seat = true;
							}
						} else if (s2.get_bs2()) {
							if (tmp->credits < 2) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 2;
								s2.set_bs2(false, tmp->name);
								cout << "Reservation #6" << endl;
								found_seat = true;
							}
						} else {
							cout << "Both back seats are taken... " << endl;
						}
					} else if (seat == 3) { //middle seat is selected
						if (s2.get_ms()) {
							if (tmp->credits < 1) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 1;
								s2.set_ms(false, tmp->name);
								cout << "Reservation #7" << endl;
								found_seat = true;
							}
						} else {
							cout << "Middle seat is taken... " << endl;
						}
					} else {
						cout << "Improper seat option..." << endl;
					}

				}
				if (car == 3) { //blue sedan
					cout
							<< "Select seat: \n (1) Front seat\n (2) Back seat\n (3) Middle seat\n "
							<< endl;
					cin >> seat;
					cin.ignore();
					if (seat == 1) { //front seat is selected
						if (s3.get_fs()) {
							if (tmp->credits < 5) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 5;
								s3.set_fs(false, tmp->name);
								cout << "Reservation #8" << endl;
								found_seat = true;
							}
						} else {
							cout << "Front seat is taken... " << endl;
						}
					} else if (seat == 2) { //back seat is selected
						if (s3.get_bs()) {
							if (tmp->credits < 2) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 2;
								s3.set_bs(false, tmp->name);
								cout << "Reservation #9" << endl;
								found_seat = true;
							}
						} else if (s3.get_bs2()) {
							if (tmp->credits < 2) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 2;
								s3.set_bs2(false, tmp->name);
								cout << "Reservation #10" << endl;
								found_seat = true;
							}
						} else {
							cout << "Both back seats are taken... " << endl;
						}
					} else if (seat == 3) { //middle seat is selected
						if (s3.get_ms()) {
							if (tmp->credits < 1) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 1;
								s3.set_ms(false, tmp->name);
								cout << "Reservation #11" << endl;
								found_seat = true;
							}
						} else {
							cout << "Middle seat is taken... " << endl;
						}
					} else {
						cout << "Improper seat option..." << endl;
					}
				} else if (car == 4) { //green compact
					cout << "Select seat: \n (1) Front seat\n (2) Back seat\n "
							<< endl;
					cin >> seat;
					cin.ignore();
					if (seat == 1) { //front seat
						if (c1.get_fc()) {
							if (tmp->credits < 5) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 5;
								c1.set_fc(false, tmp->name);
								cout << "Reservation #12" << endl;
								found_seat = true;
							}
						} else {
							cout << "Front seat is taken... " << endl;
						}
					} else if (seat == 2) { //back seat
						if (c1.get_bc()) {
							if (tmp->credits < 3) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 3;
								c1.set_bc(false, tmp->name);
								cout << "Reservation #13" << endl;
								found_seat = true;
							}
						} else if (c1.get_bc2()) {
							if (tmp->credits < 3) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 3;
								c1.set_bc2(false, tmp->name);
								cout << "Reservation #14" << endl;
								found_seat = true;
							}
						} else {
							cout << "Both back seats are taken... " << endl;
						}
					} else {
						cout << "Improper seat option..." << endl;
					}
				} else if (car == 5) { //blue compact
					cout << "Select seat: \n (1) Front seat\n (2) Back seat\n "
							<< endl;
					cin >> seat;
					cin.ignore();
					if (seat == 1) { //front seat
						if (c2.get_fc()) {
							if (tmp->credits < 5) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 5;
								c2.set_fc(false, tmp->name);
								cout << "Reservation #15" << endl;
								found_seat = true;
							}
						} else {
							cout << "Front seat is taken... " << endl;
						}
					} else if (seat == 2) { //back seat
						if (c2.get_bc()) {
							if (tmp->credits < 3) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 3;
								c2.set_bc(false, tmp->name);
								cout << "Reservation #16" << endl;
								found_seat = true;
							}
						} else if (c2.get_bc2()) {
							if (tmp->credits < 3) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 3;
								c2.set_bc2(false, tmp->name);
								cout << "Reservation #17" << endl;
								found_seat = true;
							}
						} else {
							cout << "Both back seats are taken... " << endl;
						}
					} else {
						cout << "Improper seat option..." << endl;
					}
				} else if (car == 6) { //yellow compact
					cout << "Select seat: \n (1) Front seat\n (2) Back seat\n "
							<< endl;
					cin >> seat;
					cin.ignore();
					if (seat == 1) { //front seat
						if (c3.get_fc()) {
							if (tmp->credits < 5) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 5;
								c3.set_fc(false, tmp->name);
								cout << "Reservation #18" << endl;
								found_seat = true;
							}
						} else {
							cout << "Front seat is taken... " << endl;
						}
					} else if (seat == 2) { //back seat
						if (c3.get_bc()) {
							if (tmp->credits < 3) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 3;
								c3.set_bc(false, tmp->name);
								cout << "Reservation #19" << endl;
								found_seat = true;
							}
						} else if (c3.get_bc2()) {
							if (tmp->credits < 3) {
								cout
										<< "Insufficient amount of credits for that seat..."
										<< endl;
							} else {
								tmp->credits = tmp->credits - 3;
								c3.set_bc2(false, tmp->name);
								cout << "Reservation #20" << endl;
								found_seat = true;
							}
						} else {
							cout << "Both back seats are taken... " << endl;
						}
					} else {
						cout << "Improper seat option..." << endl;
					}
				} else if (car == 7) { //purple pickup... only seat is the front seat
					cout << "Selected Pickup Front Seat..." << endl;
					if (p1.get_pa()) {
						if (tmp->credits < 5) {
							cout
									<< "Insufficient amount of credits for that seat..."
									<< endl;
						} else {
							tmp->credits = tmp->credits - 5;
							p1.set_seat(false, tmp->name);
							cout << "Reservation #21" << endl;
							found_seat = true;
						}
					} else {
						cout << "Front seat is taken... " << endl;
					}
				} else if (car == 8) { //yellow pickup... only seat is the front seat
					cout << "Selected Pickup Front Seat..." << endl;
					if (p2.get_pa()) {
						if (tmp->credits < 5) {
							cout
									<< "Insufficient amount of credits for that seat..."
									<< endl;
						} else {
							tmp->credits = tmp->credits - 5;
							p2.set_seat(false, tmp->name);
							cout << "Reservation #22" << endl;
							found_seat = true;
						}
					} else {
						cout << "Front seat is taken... " << endl;
					}
				} else if (car == 9) { //red pickup... only seat is the front seat
					cout << "Selected Pickup Front Seat..." << endl;
					if (p3.get_pa()) {
						if (tmp->credits < 5) {
							cout
									<< "Insufficient amount of credits for that seat..."
									<< endl;
						} else {
							tmp->credits = tmp->credits - 5;
							p3.set_seat(false, tmp->name);
							cout << "Reservation #23" << endl;
							found_seat = true;
						}
					} else {
						cout << "Front seat is taken... " << endl;
					}
				}
			}

			// select by seat end------------------------------------------------

			if (found_seat == true) { //checks bool to exit loop
				found_seat = false;	 //resets bools to false to be used again
				found_fs = false;
				found_bs = false;
				found_ms = false;
				break;
			} else {
				cout << "you did not get in a seat" << endl;
			}
		}			//while seat sel
		while (exit_done != true) {
			cout << "Finished? Y or N: ";
			cin >> finished;
			cin.ignore();
			if (finished == "Y") {
				exit_whole = true;
				break;
			} else if (finished == "N") {
				break;
			} else if (finished != "Y" && finished != "N") {
				cout << "invalid entry" << endl;
			}
		}
	}			//while whole loop
	return (head);
}

