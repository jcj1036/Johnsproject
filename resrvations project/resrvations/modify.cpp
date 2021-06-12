#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include "headers.h"
using namespace std;


void modify(passenger *head, pickup& p1, pickup& p2, pickup& p3, sedan& s1,
		sedan& s2, sedan& s3, compact& c1, compact& c2, compact& c3) {
	passenger *tmp; //tmp node to traverse linked list
	int resnum; //store inputted reservation number
	string name; //store the name of the person at the seat of the inputted reservation number
	//The following do loop performs exactly the same as the Delete() functin
	//Only difference is that the name of the person reserved at that seat is stored as the string name.
	do {
		cout << "Please enter number of reservation to modify: " << endl;
		cin >> resnum;
		cin.ignore();
		tmp = head;
		if ((0 <= resnum) && (resnum < 24)) {  //0-23
			if (resnum == 0) {
				if (s1.get_fs()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s1.get_rf()) {
							name = tmp->name;
							break;
						} else {
							tmp = tmp->nextaddr;
						}
					} while (true);
					tmp->credits = tmp->credits + 5;
					s1.set_fs(true, "unassigned");
					break;
				}
			} else if (resnum == 1) {
				if (s1.get_bs()) {
					cout << "No reservation at reservation #" << resnum << endl;
				} else {
					do {
						if (tmp->name == s1.get_rb()) {
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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
							name = tmp->name;
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

		} else {
			cout << "Invalid Reservation Number (Must be between 0 and 23)..."
					<< endl;
		}
	} while (true);
	//once the reservation is found and deleted, and the name of the passenger is stored,
	// user is then prompted to select a new seat to reserve for themself.
	bool found_seat = false;
	int car, seat;
	do {
		cout	//vehicle options for the user to choose from
				<< "Select vehicle: \n (1) Red Sedan\n (2) Green Sedan\n (3) Blue Sedan\n "
						"(4) Green Compact\n (5) Blue Compact\n (6) Yellow Compact\n "
						"(7) Purple Pickup\n (8) Yellow Pickup\n (9) Red Pickup"
				<< endl;
		cin >> car;	//stores their input
		cin.ignore();

		tmp = head;
		do {//searches through the linked list of passengers to find the passenger with the name that matches the
			// name of the previously deleted reservation.
			if (tmp->name == name) {
				cout << name << " has " << tmp->credits << " remaining" << endl;
				break;
			} else {
				tmp = tmp->nextaddr;
			}
		} while (true);
		//the following process acts exactly like the create() function, prompting the user for a vehicle and seat to try and reserve
		if (car == 1) {
			cout
					<< "Select seat: \n (1) Front seat\n (2) Back seat\n (3) Middle seat\n "
					<< endl;
			cin >> seat;
			cin.ignore();
			if (seat == 1) {
				if (s1.get_fs()) {
					if (tmp->credits < 5) {
						cout
								<< "Insufficient amount of credits for that seat..."
								<< endl;
					} else {
						tmp->credits = tmp->credits - 5;
						s1.set_fs(false, tmp->name);
						cout << "Reservation #0" << endl;
						found_seat = true;
					}
				} else {
					cout << "Front seat is taken... " << endl;
				}
			} else if (seat == 2) {
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
				} else if (s1.get_bs2()) {
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
				} else {
					cout << "Both back seats are taken... " << endl;
				}
			} else if (seat == 3) {
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
		if (car == 2) {
			cout
					<< "Select seat: \n (1) Front seat\n (2) Back seat\n (3) Middle seat\n "
					<< endl;
			cin >> seat;
			cin.ignore();
			if (seat == 1) {
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
			} else if (seat == 2) {
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
			} else if (seat == 3) {
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
		if (car == 3) {
			cout
					<< "Select seat: \n (1) Front seat\n (2) Back seat\n (3) Middle seat\n "
					<< endl;
			cin >> seat;
			cin.ignore();
			if (seat == 1) {
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
			} else if (seat == 2) {
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
			} else if (seat == 3) {
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
		} else if (car == 4) {
			cout << "Select seat: \n (1) Front seat\n (2) Back seat\n " << endl;
			cin >> seat;
			cin.ignore();
			if (seat == 1) {
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
			} else if (seat == 2) {
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
		} else if (car == 5) {
			cout << "Select seat: \n (1) Front seat\n (2) Back seat\n " << endl;
			cin >> seat;
			cin.ignore();
			if (seat == 1) {
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
			} else if (seat == 2) {
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
		} else if (car == 6) {
			cout << "Select seat: \n (1) Front seat\n (2) Back seat\n " << endl;
			cin >> seat;
			cin.ignore();
			if (seat == 1) {
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
			} else if (seat == 2) {
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
		} else if (car == 7) {
			cout << "Selected Pickup Front Seat..." << endl;
			if (p1.get_pa()) {
				if (tmp->credits < 5) {
					cout << "Insufficient amount of credits for that seat..."
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
		} else if (car == 8) {
			cout << "Selected Pickup Front Seat..." << endl;
			if (p2.get_pa()) {
				if (tmp->credits < 5) {
					cout << "Insufficient amount of credits for that seat..."
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
		} else if (car == 9) {
			cout << "Selected Pickup Front Seat..." << endl;
			if (p3.get_pa()) {
				if (tmp->credits < 5) {
					cout << "Insufficient amount of credits for that seat..."
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
		if (found_seat == true) {			//checks if the seat has been found
			found_seat = false;
			break;
		} else {//if the seat was not found then they are re prompted to select a vehicle and seat.
			cout << "Invalid car option... " << endl;
		}
	} while (true);
}

// select by seat end------------------------------------------------
