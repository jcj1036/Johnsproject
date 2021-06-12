#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include "headers.h"
using namespace std;


//deletes a reservation given by the user inputted reservation number
void Delete(passenger *head, pickup& p1, pickup& p2, pickup& p3, sedan& s1,
		sedan& s2, sedan& s3, compact& c1, compact& c2, compact& c3) {
	passenger *tmp; //node used to traverse through linked list
	int resnum; //stores user input of reservation number
	//The reservation number is assigned to a specific seat, not to a passenger
	//For example, the front seat of the red sedan is always reservation 0.  If there is no one reserved for
	//  that seat, the reservation number is just inactive.
	do {
		cout << "Please enter number of reservation to delete: " << endl;
		cin >> resnum;	//stores input
		cin.ignore();
		tmp = head;	//tmp is reset to the head of the linked list
		if ((0 <= resnum) && (resnum < 24)) { //makes sure the input is between 0-23
			if (resnum == 0) {  //checks the reservation number
				if (s1.get_fs()) { //sees if the seat at that reservation number is taken
					//if no one is reserved on the seat connected to the reservation number...
					cout << "No reservation at reservation #" << resnum << endl;
				} else {					//if the seat is taken
					do {
						if (tmp->name == s1.get_rf()) {
							break;//linked list is traversed to find the passenger that currently has that seat reserved
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 5; //the passengers credits are returned to them
					s1.set_fs(true, "unassigned"); //the seats availability is set to true and the string name is set to "unassigned"
					break;
				}
			} else if (resnum == 1) { //same thing is repeated for the next 23 seats
				if (s1.get_bs()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s1.get_rb()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 2;
					s1.set_bs(true, "unassigned");
					break;
				}
			} else if (resnum == 2) {
				if (s1.get_bs2()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s1.get_rb2()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 2;
					s1.set_bs2(true, "unassigned");
					break;
				}
			} else if (resnum == 3) {
				if (s1.get_ms()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s1.get_rm()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 1;
					s1.set_ms(true, "unassigned");
					break;
				}
			} else if (resnum == 4) {
				if (s2.get_fs()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s2.get_rf()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 5;
					s2.set_fs(true, "unassigned");
					break;
				}
			} else if (resnum == 5) {
				if (s2.get_bs()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s2.get_rb()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 2;
					s2.set_bs(true, "unassigned");
					break;
				}
			} else if (resnum == 6) {
				if (s2.get_bs2()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s2.get_rb2()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 2;
					s2.set_bs2(true, "unassigned");
					break;
				}
			} else if (resnum == 7) {
				if (s2.get_ms()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s2.get_rm()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 1;
					s2.set_ms(true, "unassigned");
					break;
				}
			} else if (resnum == 8) {
				if (s3.get_fs()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s3.get_rf()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 5;
					s3.set_fs(true, "unassigned");
					break;
				}
			} else if (resnum == 9) {
				if (s3.get_bs()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s3.get_rb()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 2;
					s3.set_bs(true, "unassigned");
					break;
				}
			} else if (resnum == 10) {
				if (s3.get_bs2()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s3.get_rb2()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 2;
					s3.set_bs2(true, "unassigned");
					break;
				}
			} else if (resnum == 11) {
				if (s3.get_ms()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s3.get_rm()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 1;
					s3.set_ms(true, "unassigned");
					break;
				}
			} else if (resnum == 12) {
				if (c1.get_fc()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == c1.get_rfc()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 5;
					c1.set_fc(true, "unassigned");
					break;
				}
			} else if (resnum == 13) {
				if (c1.get_bc()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == c1.get_rbc()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 3;
					c1.set_bc(true, "unassigned");
					break;
				}
			} else if (resnum == 14) {
				if (c1.get_bc2()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == c1.get_rbc2()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 3;
					c1.set_bc2(true, "unassigned");
					break;
				}
			} else if (resnum == 15) {
				if (c2.get_fc()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == c2.get_rfc()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 5;
					c2.set_fc(true, "unassigned");
					break;
				}
			} else if (resnum == 16) {
				if (c2.get_bc()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == c2.get_rbc()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 3;
					c2.set_bc(true, "unassigned");
					break;
				}
			} else if (resnum == 17) {
				if (c2.get_bc2()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == c2.get_rbc2()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 3;
					c2.set_bc2(true, "unassigned");
					break;
				}
			} else if (resnum == 18) {
				if (c3.get_fc()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == c3.get_rfc()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 5;
					c3.set_fc(true, "unassigned");
					break;
				}
			} else if (resnum == 19) {
				if (c3.get_bc()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == c3.get_rbc()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 3;
					c3.set_bc(true, "unassigned");
					break;
				}
			} else if (resnum == 20) {
				if (c3.get_bc2()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == c3.get_rbc2()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 3;
					c3.set_bc2(true, "unassigned");
					break;
				}
			} else if (resnum == 21) {
				if (p1.get_pa()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == p1.get_pr()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 5;
					p1.set_seat(true, "unassigned");
					break;
				}
			} else if (resnum == 22) {
				if (p2.get_pa()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == p2.get_pr()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 5;
					p2.set_seat(true, "unassigned");
					break;
				}
			} else if (resnum == 23) {
				if (p3.get_pa()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == p3.get_pr()) {
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 5;
					p3.set_seat(true, "unassigned");
					break;
				}
			}

		} else { // if the reservation number inputted is not between 0 and 23...
			cout << "Invalid Reservation Number (Must be between 0 and 23)..."
					<< endl;
		}
	} while (true);
}
