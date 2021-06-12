#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
using namespace std;


//passenger structure
struct passenger {
	string name;   //string name of passenger
	int credits;   //int credits the passenger has to spend
	passenger *nextaddr; //pointer to the next passenger to create a linked list
};

//vehicle class holds the color and type of vehicle as strings
class vehicle {
protected:
	string color;
	string type;
public:
	//constructor
	vehicle() {
		color = " "; //sets color and type to empty strings when instantiated
		type = " ";
	}
	//setVehicle changes the color and vehicle type to the passed in strings.
	void setVehicle(string c, string t) {
		color = c;
		type = t;
	}
	//returns the string of the color of the vehicle
	string get_color() {
		return color;
	}
};

//sedan class, child class of vehicle.
class sedan: virtual public vehicle {
private:
	bool fs, bs, bs2, ms; //boolean of availability for each seat
	int vf, vb, vb2, vm;  //integer of the credit cost for each seat
	string rf, rb, rb2, rm; //string for the name of the person who has reserve that seat

public:
	//contructor, sets the seat availability bools to true, credit costs to the appropriate default costs,
	// and the string name of the person who has reservered the seat to unassigned.
	sedan(bool fss = true, bool bss = true, bool bss2 = true, bool mss = true,
			int vff = 5, int vbb = 2, int vbb2 = 2, int vmm = 1, string rff =
					"unassigned", string rbb = "unassigned", string rbb2 =
					"unassigned", string rmm = "unassigned") {
		fs = fss;
		bs = bss;
		bs2 = bss2;
		ms = mss;
		vf = vff;
		vb = vbb;
		vb2 = vbb2;
		vm = vmm;
		rf = rff;
		rb = rbb;
		rb2 = rbb2;
		rm = rmm;
	}
	//sets the front seat availability and the name of the person who has reserved it
	void set_fs(bool fss, string rff) {
		fs = fss;
		rf = rff;
	}
	//sets the back seat availability and the name of the person who has reserved it
	void set_bs(bool bss, string rbb) {
		bs = bss;
		rb = rbb;
	}
	//sets the second back seat availability and the name of the person who has reserved it
	void set_bs2(bool bss2, string rbb2) {
		bs2 = bss2;
		rb2 = rbb2;
	}
	//sets the middle seat availability and the name of the person who has reserved it
	void set_ms(bool mss, string rmm) {
		ms = mss;
		rm = rmm;
	}
	//returns the availability of the front seat, true if available
	bool get_fs() {
		return fs;
	}
	//returns the availability of the back seat, true if available
	bool get_bs() {
		return bs;
	}
	//returns the availability of the second back seat, true if available
	bool get_bs2() {
		return bs2;
	}
	//returns the availability of the middle seat, true if available
	bool get_ms() {
		return ms;
	}
	//returns the credit cost of the front seat
	int get_vf() {
		return vf;
	}
	//returns the credit cost of the back seat
	int get_vb() {
		return vb;
	}
	//returns the credit cost of the second back seat
	int get_vb2() {
		return vb2;
	}
	//returns the credit cost of the middle seat
	int get_vm() {
		return vm;
	}
	//returns the name of the person who has reserved the front seat
	string get_rf() {
		return rf;
	}
	//returns the name of the person who has reserved the back seat
	string get_rb() {
		return rb;
	}
	//returns the name of the person who has reserved the second back seat
	string get_rb2() {
		return rb2;
	}
	//returns the name of the person who has reserved the middle seat
	string get_rm() {
		return rm;
	}
};

//pickup class, child class of vehicle.
class pickup: virtual public vehicle {
private:
	bool pa; //boolean of availability for the front seat (only seat in the pickup truck)
	int pv;  //integer of the credit cost for the seat
	string pr; //string for the name of the person who has reserved the seat
public:
	//contructor, sets the seat availability bool to true, credit cost to the appropriate default cost, 5,
	// and the string name of the person who has reservered the seat to unassigned.
	pickup(bool s_ava = true, int s_val = 5, string p_res = "unassigned") {
		pa = s_ava;
		pv = s_val;
		pr = p_res;
	}
	//sets the front seat availability and the name of the person who has reserved it
	void set_seat(bool s_ava, string p_res) {
		pa = s_ava;
		pr = p_res;
	}
	//returns the availability of the front seat, true if available
	bool get_pa() {
		return pa;
	}
	//returns the credit cost of the front seat
	int get_pv() {
		return pv;
	}
	//returns the name of the person who has reserved the front seat
	string get_pr() {
		return pr;
	}
};
//compact class, child class of vehicle.
class compact: virtual public vehicle {
private:
	bool fc, bc, bc2;      //boolean of availability for each seat
	int vcf, vcb, vcb2;    //integer of the credit cost for each seat
	string rfc, rbc, rbc2; //string for the name of the person who has reserve that seat
public:
	//contructor, sets the seat availability bools to true, credit costs to the appropriate default costs,
	// and the string name of the person who has reservered the seat to unassigned.
	compact(bool fcc = true, bool bcc = true, bool bcc2 = true, int vccf = 5,
			int vccb = 3, int vccb2 = 3, string rffc = "unassigned",
			string rbbc = "unassigned", string rbbc2 = "unassigned") {
		fc = fcc;
		bc = bcc;
		bc2 = bcc2;
		vcf = vccf;
		vcb = vccb;
		vcb2 = vccb2;
		rfc = rffc;
		rbc = rbbc;
		rbc2 = rbbc2;
	}
	//sets the front seat availability and the name of the person who has reserved it
	void set_fc(bool fcc, string rffc) {
		fc = fcc;
		rfc = rffc;
	}
	//sets the back seat availability and the name of the person who has reserved it
	void set_bc(bool bcc, string rbbc) {
		bc = bcc;
		rbc = rbbc;
	}
	//sets the second back seat availability and the name of the person who has reserved it
	void set_bc2(bool bcc2, string rbbc2) {
		bc2 = bcc2;
		rbc2 = rbbc2;
	}
	//returns the availability of the front seat, true if available
	bool get_fc() {
		return fc;
	}
	//returns the availability of the back seat, true if available
	bool get_bc() {
		return bc;
	}
	//returns the availability of the second back seat, true if available
	bool get_bc2() {
		return bc2;
	}
	//returns the credit cost of the front seat
	int get_vcf() {
		return vcf;
	}
	//returns the credit cost of the back seat
	int get_vcb() {
		return vcb;
	}
	//returns the credit cost of the second back seat
	int get_vcb2() {
		return vcb2;
	}
	//returns the name of the person who has reserved the front seat
	string get_rfc() {
		return rfc;
	}
	//returns the name of the person who has reserved the back seat
	string get_rbc() {
		return rbc;
	}
	//returns the name of the person who has reserved the second back seat
	string get_rbc2() {
		return rbc2;
	}
};

struct reservation {
	string name;
	vehicle v;
};


void display_roster(passenger *head);
void display(sedan s1, sedan s2, sedan s3, pickup p1, pickup p2, pickup p3,
		compact c1, compact c2, compact c3);
passenger *read_file();
passenger *create(passenger *head, pickup& p1, pickup& p2, pickup& p3,
		sedan& s1, sedan& s2, sedan& s3, compact& c1, compact& c2,
		compact& c3);
void print(passenger *head, sedan s1, sedan s2, sedan s3, compact c1,
		compact c2, compact c3, pickup p1, pickup p2, pickup p3);
void reservations(pickup p1, pickup p2, pickup p3, sedan s1, sedan s2, sedan s3,
		compact c1, compact c2, compact c3);
void Delete(passenger *head, pickup& p1, pickup& p2, pickup& p3, sedan& s1,
		sedan& s2, sedan& s3, compact& c1, compact& c2, compact& c3);
void modify(passenger *head, pickup& p1, pickup& p2, pickup& p3, sedan& s1,
		sedan& s2, sedan& s3, compact& c1, compact& c2, compact& c3);
