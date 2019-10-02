#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

// ID, Total, Username 

using namespace std;

// Data
void info(int[], int[], string[]);
void newuser(int&, int[], int[], string[]);
void returninguser(int&, int[], int[], string[]);

int socialsecurity(int&);

// Writing
void database(int&, int&, int&, string&);

// Functions
void menu(int&, int&, int[], int[], string[]);
void accountlookup(int&, int&, int[], int[], int&, string[]);
void readin(int&, int[], int[], string[]);
void cleanup(int[], int[]);
void validator(int&);
void uservalidator(int&);
void spacing();

int main() {
	int
		id[500],
		total[500],
		choice = 0,
		useridnumber = 0;
	string
		name[500];

	cleanup(id, total);
	readin(useridnumber, id, total, name);
	menu(choice, useridnumber, id, total, name);
}

void readin(int& userindatabase, int id[], int total[], string user[]) {
	ifstream readdatabase;
	readdatabase.open("Database.txt");
	if (!readdatabase) {
		cout << "This machine is out of order" << endl;
		exit(0);
	}

}

void menu(int& choice, int& useridnumber, int id[], int total[], string user[]) {
	cout << "Welcome To The Terminal Bank" << endl;

	cout << "1. New User" << endl;
	cout << "2. Returning User" << endl;
	cout << "6. Quit" << endl;
	cin >> choice;

	validator(choice);

	while (choice != 6) {
		switch (choice) {
		case 1:
			newuser(useridnumber, id, total, user);
			break;
		case 2:
			returninguser(useridnumber, id, total, user);
			break;
		case 6:
			exit(0);
			break;
		}
	}
	//info(, total, newname);
	menu(choice, useridnumber, id, total, user);
}

void validator(int& choice) {
	bool input;
	if (choice == 1)
		input = true;
	else if (choice == 2)
		input = true;
	else if (choice == 6)
		input = true;
	else
		input = false;

	while (input == false) {
		cout << "Your input is invalid, please try again" << endl;
		cin >> choice;

		if (choice == 1)
			input = true;
		else if (choice == 2)
			input = true;
		else if (choice == 6)
			input = true;
		else
			input = false;
	}
}

void newuser(int& useridnumber, int newid[], int total[], string newname[]) {
	system("CLS");
	cout << "Please put in your name: ";
	cin >> newname[0];

	info(newid, total, newname);

	srand(time(0));
	newid[0] = (rand() % 20) + 10 + (rand() % 30) + 100 + (rand() % 10) + 1000 + (rand() % 15) + 10000;

	cout << "Welcome to your new bank " << newname[0] << " here's your bank ID" << endl;
	cout << "ID#:s " << newid[0] << endl;
	info(newid, total, newname);
	//	useridnumber = useridnumber + 1
}


int socialsecurity(int& conf) {
	return 0;
}

void info(int newid[], int total[], string newname[]) {
	system("CLS");
	cout << "Bank #: " << newid[0] << " Total Balance: " << total[0] << " User: " << newname[0] << endl;
	cout << "----------------------------" << endl;
}

void database(int& id, int& balance, int& total, string& name) {
	ofstream storage;
	storage.open("Database.txt");
	storage << " Bank Number: " << id << "\n " << "Total Balance: " << balance << "\n " << "Account User Name: " << name << endl;

	storage.close();
}


void returninguser(int& useridnumber, int id[], int total[], string user[]) {
	int choice,
		inputid;

	cout << "Please enter your ID." << endl;
	cout << "ID#: ";

	cin >> inputid;
	//accountlookup(inputid, id, total, user);

	cout << "1. Deposit" << endl;
	cout << "2. Withdrawal" << endl;
	cout << "3. Check Account" << endl;
	cout << "4. Delete Account" << endl;
	cout << "6. Quit" << endl;

	cin >> choice;
	uservalidator(choice);

	while (choice != 6) {
		switch (choice) {
		case 1:
			break;
		case 2:
			info(id, total, user);
			break;
		case 3:
			info(id, total, user);
			break;
		case 4:
			info(id, total, user);
			break;
		case 6:
			exit(0);
			break;
		}
	}

}

void uservalidator(int& choice) {
	bool input;
	if (choice == 1)
		input = true;
	else if (choice == 2)
		input = true;
	else if (choice == 3)
		input = true;
	else if (choice == 4)
		input = true;
	else if (choice == 6)
		input = true;
	else
		input = false;

	while (input == false) {
		cout << "Your input is invalid, please try again" << endl;
		cin >> choice;

		if (choice == 1)
			input = true;
		else if (choice == 2)
			input = true;
		else if (choice == 3)
			input = true;
		else if (choice == 4)
			input = true;
		else if (choice == 6)
			input = true;
		else
			input = false;
	}
}

void accountlookup(int& useridnumber, int& inputid, int id[], int total[], string user[]) {
	for (int i = 0; i <= 500; i++) {
		if (inputid == id[i]) {
			// 11504 == id[5];
			// id[useridnumber]
			// useridnumber = i
			break;
		}
	}

	info(id, total, user);
}

void spacing() {
	cout << endl;
	cout << endl;
}

void cleanup(int id[], int total[]) {
	for (int i = 0; i <= 500; i++)
		id[i] = 0, total[i] = 0;
}

/*
Revised code
	int samenumber = 0;
	cout << "Please get a pen and paper and write down your new ID: ";

	// To generate a new number and self check if it exist. If the database is full, we'll get an error message saying its full "Please visit another branch".
	for (int num = 0; num <= 500; num++) {
		newids[num] = rand() % 20;
	//	cout << "THIS IS ACCOUNT NUMBER " << num << "AND THE ACCOUNT NUMBER IS " << newids[num] << endl;

	for (int check = 1; check <= 500; check++) {
			// cout << "THIS IS CHECK NUMBER " << check << endl;
			if (newids[check] == newids[num]) {
				if (newids[check] == newids[num]) {
					cout << "ID: " << newids[num] << " is the same as Account# " << check << " in the database and that ID is: " << newids[check] << endl;
					newids[num] = rand() % 200 + 1;
					samenumber++;
				}
			}
		}
	//	cout << newids[num] << endl;
	//		cout << endl;
*/