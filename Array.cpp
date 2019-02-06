

#include <iostream>
using  namespace std;

void ReverseArray (int arr[], int size);

int main(){


int NumOfArr;

cout << "Please enter how many digits you want in your array " << endl;



cin >> NumOfArr;

int* newArr = new int[NumOfArr];

cout << "Please enter numbers " << endl;

for (unsigned int i = 0; i < NumOfArr; i++)
  {

  cin >> newArr[i];

  }




ReverseArray(newArr, NumOfArr);



return 0;
}


void ReverseArray (int arr[], int size)
{

	
	cout << "Here it is in reverse: " << endl;

	
	for (int i = (size-1); 0 <= i; i--)
	{

		cout << arr[i] << endl;


	}




}
