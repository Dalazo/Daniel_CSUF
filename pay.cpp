
#include "person.h"
#include "person.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


 int readData(Person arr[],int size);
 void writeData(Person arr[],int size);

int main()
{
int FileMax = 20;
int fileActual;
Person myarr[20];

fileActual = readData(myarr,FileMax);


writeData(myarr,fileActual);


return 0;

}

int readData(Person arr[],int size)
{

fstream myfile;
int counter = 0;
string linecheck;
Person S;


myfile.open("data.txt");


if (!myfile.is_open())
{

cout << "File not found " << endl;

}

else
{

while (getline(myfile,linecheck)){

    counter++;
}
myfile.close();

myfile.open("data.txt");
cout << "File is open: Reading contents" << endl;

while (!myfile.eof())
{


for (unsigned int i = 0; i < counter; i++)
{
string firstname;
string lastname;

float hours;
float payrate;

myfile >> firstname >> lastname >> hours >> payrate;

S.setFirstName(firstname);
S.setLastName(lastname);

S.setHoursWorked(hours);
S.setPayRate(payrate);

arr[i] = S;

}

}

}
myfile.close();
return counter;
}



void writeData(Person arr[],int size){


ofstream outfile ("newData.txt");

for (unsigned int i = 0; i < size; i++)
{

outfile << arr[i].fullName() << " ";
outfile << arr[i].totalPay() << endl;



}



outfile.close();

}
