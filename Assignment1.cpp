// Assignment1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

struct PERSON {

	char name[20];
	float balance;

};

using namespace std;

void DisplayData (vector<PERSON> &vect, int size);
void FindRichest (vector<PERSON> vect, int size);
void DepositMoney (string N,vector<PERSON> &vect, int size);
void UpdateFile (string filename, vector<PERSON> &vect, int size);
int main()
{


	fstream myfile;
	int counter = 0;
	string line;
	string file = "";

	myfile.open("data.txt");

	if (!myfile.is_open()) {

		cout << "File not found" << endl;

	}


	while (getline(myfile, line))
	{
		counter++;
	}
	cout << "File has this many lines: " << counter << endl;
	myfile.close();

	vector<PERSON> myvect;
	
	myfile.open("data.txt");


	while (!myfile.eof())
	{
		string name;
		string lastname;
        string combined;
	    string space = " ";
		PERSON S;


		myfile >> name;

		myfile >> lastname;
		
        combined = name + space + lastname;
		
		strcpy(S.name,combined.c_str());

		myfile >> S.balance;
        myfile.clear();
		myfile.ignore();
		myvect.push_back(S);
        

	}
myfile.close();

string filename = "\"data.txt\"";

cout << "Please choose one of the options \nD. Display all records\nF. Find the richest person\nA. Add money\nC. Copy new records \nQ. Quit" << endl;

char choice;

cin >> choice;

choice = toupper(choice);
while (choice != 'Q')
{



switch (choice)
{
	case 'D':
		
		DisplayData(myvect, counter);

		break;
	case 'F':
		FindRichest(myvect, counter);
		break;
	case 'A':
		{
		
	
	string name;

	cout << "Please enter the name of the account you want to deposit in: " << endl;
	cin.ignore();
	getline(cin,name);
		DepositMoney(name, myvect,counter);
		
		break;
		}
	case 'C':
		
		UpdateFile (filename, myvect, counter);
		
		break;
	default:
		cout << "Please choose correct option" << endl;
		break;
}
cout << "\nPlease choose one of the options \nD. Display all records\nF. Find the richest person\nA. Add money\nC. Copy new records \nQ. Quit" << endl;

cin >> choice;
choice = toupper(choice);

}

		cout << "Exiting program";

		
	return 0;
}




void DisplayData (vector<PERSON> &vect, int size)
{
cout << "        Name          Balance     " << endl;
cout << "__________________________________" << endl;

for (unsigned int i = 0; i < size; i++)
{

cout << vect.at(i).name << "  " << vect.at(i).balance << endl;


}


}
void FindRichest (vector<PERSON> vect, int size){

float checker = 0;
char name[20];

for (unsigned int i = 0; i < size-1; i++)
{

if (checker < vect.at(i).balance)
{
      
checker = vect.at(i).balance;
strcpy(name,vect.at(i).name);

}

}
 cout << "The richest person is: " << name << " with " << checker << endl;
 

}


void DepositMoney (string N,vector<PERSON> &vect, int size)
{

char name[20];
float amount;

strcpy(name,N.c_str());


for (int i = 0; i < size; i++)
{

if (strcmp(name,vect.at(i).name) == 0)
{
cout << "Hello " << name << endl;;
cout << "How much would you like to deposit? " << endl;
cin >> amount;

vect.at(i).balance = vect.at(i).balance + amount;
cout << "Your new balance is " << vect.at(i).balance << endl;
break;
}

}



}
void UpdateFile (string filename, vector<PERSON> &vect, int size){

fstream myfile;

myfile.open("data.txt");

for (int i = 0; i < size; i++){


myfile <<  vect.at(i).name ;
myfile << " ";
myfile << vect.at(i).balance << endl;



}
myfile.close();

}










