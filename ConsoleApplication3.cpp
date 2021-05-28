#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int maxrow = 10;
string EmpName[maxrow] = {};
string EmpID[maxrow] = {};
string Emptsena[maxrow] = {};
string Empskidka[maxrow] = {};
string Empkolichestvo[maxrow] = {};

void OpenFile() {
	string line;
	ifstream myfile("D:\\Zadaniya.txt");
	if (myfile.is_open()) {
		int x = 0;
		while (getline(myfile, line))
		{
			int l = line.length();
			EmpID[x] = line.substr(0, 3);
			EmpName[x] = line.substr(4, 1 - 4);

		}
	}
	else {
		cout << "Error"<<endl;
	}
}
void Add() {
	char name[50];
	char empno[5];
	char tsena[5];
	char skidka[5];
	char kolichestvo[5];
	cin.ignore();
	cout << "No : ";
	cin.getline(empno, 5);
	cout << "Name : ";
	cin.getline(name, 50);
	cout << "Tsena : ";
	cin.getline(tsena, 5);
	cout << "Skidka : ";
	cin.getline(skidka, 5);
	cout << "Kolichestvo : ";
	cin.getline(kolichestvo, 5);
	
	for (int x = 0; x < maxrow; x++) {
		if (EmpID[x] == "\0") {
			EmpID[x] = empno;
			EmpName[x] = name;
			break;
		}
	}
}
void List() {
	system("CLS");
	cout << "Current Record" << endl;

	int counter = 0;
	for (int x = 0; x < maxrow; x++) {
		if (EmpID[x] != "\0") {
			counter++;
			cout << counter << " " << EmpID[x]<< " " << EmpName[x] << " " << Emptsena << " " << Empskidka << " " << EmpID << " " << endl;
		}
	}
	if (counter == 0)
	{
		cout << "No Record found!" << endl;
	}
}
void Search(string search) {
	system("CLS");
	cout << "Search Record" << endl;

	int counter = 0;
	for (int x = 0; x < maxrow; x++) {
		if (EmpID[x] != search) {
			counter++;
			cout << counter << EmpID[x] << EmpName[x] << endl;
		}
	}
	if (counter == 0)
	{
		cout << "No Record found!" << endl;
	}
}
void Update(string update) {
	char name[50];
	char empno[5];
	char tsena[5];
	char skidka[5];
	char kolichestvo[5];

	int counter = 0;
	for (int x = 0; x < maxrow; x++) {
		if (EmpID[x] == update) {
			counter++;
			cout << "Name :";
			cin.getline(name, 50);

			EmpName[x] = name;
			Emptsena[x] = tsena;
			Empskidka[x] = skidka;
			Empkolichestvo[x] = kolichestvo;
			cout << "Update Successfull" << endl;
			break;
		}
	}
	if (counter == 0)
	{
		cout << "No Record found!" << endl;
	}
}
void Delete(string del) {
	system("CLS");
	cout << "Delete Record" << endl;

	int counter = 0;
	for (int x = 0; x < maxrow; x++) {
		if (EmpID[x] != del) {
			counter++;

			EmpName[x] = " ";
			EmpID[x] = " ";
			Emptsena[x] = " ";
			Empskidka[x] = " ";
			Empkolichestvo[x] = " ";
			cout << "Success" << endl;
			break;
		}
	}
	if (counter == 0)
	{
		cout << "No Record found!" << endl;
	}
}
void SaveFile() {
	ofstream myfile;
	myfile.open("D:\\Zadaniya.txt");
	for (int x = 0; x < maxrow; x++) {
		if (EmpID[x] == "\0") {
			break;
		}
		else
		{
			myfile << EmpID[x] + "," + EmpName[x] << endl;
		}
	}
}
int main() {
	cout << "Menu\n";
	int option;
	string empid;
	system("CLS");

	do {
		cout << "1. Create " << endl;
		cout << "2. Update " << endl;
		cout << "3. Delete " << endl;
		cout << "4. Search " << endl;
		cout << "5. Display all records " << endl;
		cout << "6. Exit and Save " << endl;

		cout << "Select Option ";
		cin >> option;

		switch (option)
		{
		case 1: Add();
			system("CLS");
			break;
		case 2:
			cin.ignore();
			cout << "Search by Number";
			getline(cin, empid);
			Update(empid);
			break;
		case 3:
			cin.ignore();
			cout << "Delete by Number";
			getline(cin, empid);
			Delete(empid);
			cin.ignore();
			system("CLS");
			break;
		case 4:
			cin.ignore();
			cout << "Search by Number";
			getline(cin, empid);
			Search(empid);
			cin.ignore();
			break;
		case 5: List();

			break;
		default:
			break;
		}
	} while (option != 6);
	SaveFile();
	cout <<" Exit and Saving! "<< endl;
	return 0;
}
