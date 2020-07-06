// Hospital Management Application.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <string>
#include <iostream>
#include<fstream>
#include <conio.h>
#include <windows.h>
using namespace std;



bool system_Login();
void reset_pass();
void add_admin();
void new_patient();
void view_info();
void list_patients();
void edit_patient();
void delete_patient();
void back();



int main()
{
	if(system_Login() == true){
		back();
	}
	return 0;
}


bool system_Login()
{
	string x, y, username, password;

	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;

	ifstream read;
	read.open("Login.txt");

	if (!read)
	{
		cout << "File doesn't exist.";
		exit(1);
	}
	while (read >> x) {
		if (username == x)
		{
			read >> y;
			for (int i = 0; i < 3; i++) {
				if (password != y) {
					cout << "Wrong password, please Re-enter your password:" << endl;
					cin >> password;
				}
				if (password == y) {
					cout << "Login Successful" << endl;
					read.close();
					return true;
				}
			}
			cout << "Error. Application Will Exit!" << endl;
			Sleep(750);
			read.close();
			return false;
		}
		else
			read >> x;
	}
	cout << "User not found, Application Will Exit!" << endl;
	Sleep(750);
	read.close();
	return false;
}

void reset_pass()
{
	ifstream read;
	ofstream write;
	bool flag = false;
	string pass1, name1, pass2, name2, input;
	int i = 0, j = 0;
	cout << "Enter account name: ";
	cin >> name1;
	cout << "Enter your old password: ";
	cin >> pass1;

	read.open("Login.txt");
	write.open("temporary.txt");

	while (read >> name2) {
		read >> pass2;
		if (name1 != name2 || pass1 !=pass2)
			write << name2 + " " + pass2 + "\n";
		else {
			while (1) {
				cout << "Enter the new password: ";
				cin >> input;
				bool flag1 = false, flag2 = false;
				for (int i = 0; i < input.length(); i++) { // iterate on every character in newpass to check if there is at least number and character and length<=8
					if (input.at(i) >= '0' && input.at(i) <= '9' && input.length() >= 8)
						flag1 = true;
					if ((input.at(i) >= 'A' && input.at(i) <= 'Z') || (input.at(i) >= 'a' && input.at(i) <= 'z'))
						flag2 = true;
				}
				if (flag1 && flag2) // exit the while loop when both flags are true
					break;
				cout << "\n Password must contain letters and numbers and be of size >= 8\n";
			}
			write << name1 + " " + input + "\n";
			flag = true;
		}
	}
	if (flag == false) {
		cout << "User not found, Application Will Exit!" << endl;
		Sleep(750);
		read.close();
		write.close();
		exit(1);
	}
	read.close();
	write.close();
	remove("Login.txt");
	rename("temporary.txt", "Login.txt");
	fflush(stdin);
	Sleep(750);
	back();
}

void add_admin()
{
	string username, password;
	ofstream newUser;
	cout << "Enter a new username: ";
	cin >> username;
	while (1) {
		cout << "Enter the new password: ";
		cin >> password;
		bool flag1 = false, flag2 = false;
		for (int i = 0; i < password.length(); i++) { // iterate on every character in newpass to check if there is at least number and character and length<=8
			if (password.at(i) >= '0' && password.at(i) <= '9' && password.length() >= 8)
				flag1 = true;
			if ((password.at(i) >= 'A' && password.at(i) <= 'Z') || (password.at(i) >= 'a' && password.at(i) <= 'z'))
				flag2 = true;
		}
		if (flag1 && flag2) // exit the while loop when both flags are true
			break;
		cout << "\n Password must contain letters and numbers and be of size >= 8\n";
	}
	newUser.open("Login.txt", ios_base::app);
	newUser << username + " " + password + "\n";
	newUser.close();
	fflush(stdin);
	Sleep(750);
	back();
}



void new_patient()
{
	string number, name, lastName, fathername, address, age, gender, disease, entryDate;
	string  serviceName, room, physicianRoomNumber, totalCharge, totalDeposited;
	ofstream newUser;
	cout << "Enter patient's number: ";
	cin >> number;
	cout << "Enter patient's name: ";
	cin >> name;
	cout << "Enter patient's fathername: ";
	cin >> fathername;
	cout << "Enter patient's last name: ";
	cin >> lastName;
	cout << "Enter patient's age: ";
	cin >> age;
	cout << "Enter patient's gender: ";
	cin >> gender;
	cout << "Enter patient's disease: ";
	cin >> disease;
	cout << "Enter patient's entry date: ";
	cin >> entryDate;
	cout << "Enter patient's serviceName: ";
	cin >> serviceName;
	cout << "Enter patient's room number: ";
	cin >> room;
	cout << "Enter patient's physician room number: ";
	cin >> physicianRoomNumber;
	cout << "Enter patient's total charge: ";
	cin >> totalCharge;
	cout << "Enter patient's total deposited: ";
	cin >> totalDeposited;
	cout << "Enter patient's address: ";
	cin >> address;

	string x;
	fstream inFile;
	string a[14];
	inFile.open("patient.txt");
	if (!inFile) {
		cout << "Unable to open file to read!";
		exit(1);
	}
	while (getline(inFile, x)) {
		int j = 0; //14
		for (int i = 0; i < x.length(); i++) {
			if (x.at(i) != ' ') {
				a[j] += x.at(i);
			}
			else
				j++;
		}
		if (a[0] == number) {
			cout << "Patient exists!!\n";
			inFile.close();
			fflush(stdin);
			Sleep(750);
			back();
		}
	}
	if (a[0] == number) {
		cout << "Patient exists!!\n";
		inFile.close();
		fflush(stdin);
		Sleep(750);
		back();
	}
	inFile.close();

	newUser.open("patient.txt", ios_base::app);
	newUser << number << " " << name << " " << fathername << " " << lastName << " "
		<< age << " " << gender << " " << disease << " " << entryDate << " "
		<< serviceName << " " << room << " " << physicianRoomNumber << " "
		<< totalCharge << " " << totalDeposited << " " << address << endl;
	newUser.close();

	fflush(stdin);
	Sleep(750);
	back();
}



void view_info()
{
	string tofind, x;
	int type = 0;
	bool flag = false;
	cout << "Enter first name and last name or number: ";
	cin >> tofind;

	ifstream myfile;
	myfile.open("patient.txt");
	if (!myfile)
	{
		cout << "the file does not exist" << endl;
		exit(1);
	}

	for(int i = 0; i < tofind.length(); i++) {
		if (isdigit(tofind[i]) == false) {
			type = 0;
			cin >> x;
			tofind += " " + x;
			break;
		}
		type = 1;
	}
	
	while (!myfile.eof()) {
		getline(myfile, x);
		int j = 0; //14
		string a[14];
		for (int i = 0; i < x.length(); i++) {
			if (x.at(i) != ' ') {
				a[j] += x.at(i);
			}
			else
				j++;
		}
		if (type == 1) {
			if (a[0] == tofind)
			{
				flag = true;
				cout << "\nnumber: " + a[0] + "\nname: " + a[1] +  "\nfathername: " + a[2] + "\nlastName: " + a[3]
					+ "\nage: " + a[4] +  "\ngender: " + a[5] + "\ndisease: " + a[6] + "\nentryDate: " + a[7]
					+"\nserviceName: " + a[8] + "\nroom: " + a[9] + "\nphysicianRoomNumber: " + a[10]
					+ "\ntotalCharge: " + a[11] + "\ntotalDeposited: " + a[12] + "address: " + a[13] + "\n";
				break;
			}
		}
		else {
			string name = a[1] + " " + a[3];
			
			if (name.compare(tofind) == 0) {
				flag = true;
				cout << "\nnumber: " + a[0] + "\nname: " + a[1] + "\nfathername: " + a[2] + "\nlastName: " + a[3]
					+ "\nage: " + a[4] + "\ngender: " + a[5] + "\ndisease: " + a[6] + "\nentryDate: " + a[7]
					+ "\nserviceName: " + a[8] + "\nroom: " + a[9] + "\nphysicianRoomNumber: " + a[10]
					+ "\ntotalCharge: " + a[11] + "\ntotalDeposited: " + a[12] + "address: " + a[13] + "\n";
				break;
			}
		
		}
	}
	if(flag == false)
		cout << "User Not Found." << endl;
	fflush(stdin);
	Sleep(750);
	back();
}



void list_patients()
{
	string x;
	fstream inFile;
	inFile.open("patient.txt");
	if (!inFile) {
		cout << "Unable to open file to read!";
		exit(1);
	}
	cout << "\nUser Number:  		-->		FullName:\n";
	cout << "--------------------------------------\n";
	while (getline(inFile, x)) {
		int j = 0; //14
		string a[14];
		for (int i = 0; i < x.length(); i++) {
			if (x.at(i) != ' ') {
				a[j] += x.at(i);
			}
			else
				j++;
		}
		cout << a[0] + "	-->		" + a[1] + " " + a[2] + " " + a[3] << endl;
	}
	fflush(stdin);
	Sleep(750);
	back();
}


void edit_patient()
{
	string x;
	fstream inFile;
	ofstream outFile;

	inFile.open("patient.txt");
	outFile.open("temporary.txt");

	if (!inFile) {
		cout << "Unable to open file to read!";
		exit(1);
	}

	if (!outFile) {
		cout << "Unable to open file to write!";
		exit(1);
	}

	string toFind;
	cout << "Enter User Number: ";
	cin >> toFind;

	string newValue;
	while (getline(inFile, x)) {
		if (x.find(toFind) != string::npos) {
			string number, name, lastName, fathername, address, age, gender, disease, entryDate;
			string  serviceName, room, physicianRoomNumber, totalCharge, totalDeposited;
			cout << "Enter patient's number: ";
			cin >> number;
			cout << "Enter patient's name: ";
			cin >> name;
			cout << "Enter patient's fathername: ";
			cin >> fathername;
			cout << "Enter patient's last name: ";
			cin >> lastName;
			cout << "Enter patient's age: ";
			cin >> age;
			cout << "Enter patient's gender: ";
			cin >> gender;
			cout << "Enter patient's disease: ";
			cin >> disease;
			cout << "Enter patient's entry date: ";
			cin >> entryDate;
			cout << "Enter patient's serviceName: ";
			cin >> serviceName;
			cout << "Enter patient's room number: ";
			cin >> room;
			cout << "Enter patient's physician room number: ";
			cin >> physicianRoomNumber;
			cout << "Enter patient's total charge: ";
			cin >> totalCharge;
			cout << "Enter patient's total deposited: ";
			cin >> totalDeposited;
			cout << "Enter patient's address: ";
			cin >> address;
			x  = number + " " + name + " " + fathername + " " + lastName + " "
				+ age + " " + gender + " " + disease + " " + entryDate + " "
				+ serviceName + " " + room + " " + physicianRoomNumber + " "
				+ totalCharge + " " + totalDeposited + " " + address;
		}
		outFile << x << endl;
	}

	inFile.close();
	outFile.close();

	remove("patient.txt");
	rename("temporary.txt", "patient.txt");
	//The file is updated: the old file is removed, the newFile is renamed as the old file.
	fflush(stdin);
	Sleep(750);
	back();
}

void delete_patient()
{
	bool flag;
	string x;
	fstream inFile;
	ofstream outFile;

	inFile.open("patient.txt");
	outFile.open("temporary.txt");

	if (!inFile) {
		cout << "Unable to open file to read!";
		exit(1);
	}

	if (!outFile) {
		cout << "Unable to open file to write!";
		exit(1);
	}

	string toFind;
	cout << "Enter User Number: ";
	cin >> toFind;

	string newValue;
	while (getline(inFile, x)) {
		flag = false;
		int j = 0; //14
		string a[14];
		for (int i = 0; i < x.length(); i++) {
			if (x.at(i) != ' ') {
				a[j] += x.at(i);
			}
			else
				j++;
		}
		if (a[0] == toFind) {
			int num1,num2;
			num1 =  stoi(a[11]);
			num2 = stoi(a[12]);
			if ((num1 - num2) == 0) {
				flag = true;
				cout << "\nPatient deleted!\n";
			}
			else {
				cout << "\nCannot delete Patient.\n";
			}
		}
		if(flag == false)
			outFile << x << endl;
	}

	inFile.close();
	outFile.close();

	remove("patient.txt");
	rename("temporary.txt", "patient.txt");
	//The file is updated: the old file is removed, the newFile is renamed as the old file.
	fflush(stdin);
	Sleep(750);
	back();
}



void back()
{
	int x;
	remove("temporary.txt");
	cout << "---------------------------------------------------------------------------------------------------------";
	cout << "\n\nWelcome!!" << endl << "---------" << endl;
	cout << "1 - Login to the system" << "\t\t" << "2 - Do you want to reset password ?" << endl
		<< "3 - Add Admin ?" << "\t\t" << "        4 - New patient ?" << endl << "5 - View info ?" << "\t\t" <<
		"        6 - List Patients ?" << endl << "7 - Edit Patient ?" << "\t\t" << "8 - Delete Patient ?\n\n" << endl
		<< "Enter Anything else to Quit!!\n----------------------------\n";
	cin >> x;
	cout << "----------------------------";
	switch (x)
	{
		case 1:
			system_Login();
			break;
		case 2:
			reset_pass();
			break;
		case 3:
			add_admin();
			break;
		case 4:
			new_patient();
			break;
		case 5:
			view_info();
			break;
		case 6:
			list_patients();
			break;
		case 7:
			edit_patient();
			break;
		case 8:
			delete_patient();
			break;
		default:
			exit(1);
	}
}