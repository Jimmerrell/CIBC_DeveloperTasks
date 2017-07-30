#include <iostream>
using namespace std;

#include "CircularArray.h"
//************************************************
////test console application for CircularArray
//************************************************

int main()
{
	cout << "This is a test of CircularArray.h\n\n";

	//Test Constructor
	cout << "Constructor" << endl;
	CircularArray<int> testCircularArray;
	cout << "Array size: " << testCircularArray.Size() << endl;
	cout << "Array capacity: " << testCircularArray.Capacity() << "\n\n";

	//Test Copy Constructor
	cout << "Copy Constructor" << endl;
	CircularArray<int> copyArray(testCircularArray);
	cout << "copyArray size: " << copyArray.Size() << endl;
	cout << "copyArray capacity: " << copyArray.Capacity() << "\n\n";

	//Test Reserve
	cout << "Reserve\n";
	testCircularArray.Reserve(5);
	cout << "Array size: " << testCircularArray.Size() << endl;
	cout << "Array capacity: " << testCircularArray.Capacity() << "\n\n";

	//Test AddElement / Size / Capacity / operator[]
	cout << "AddElement\n";
	for (int i = -5; i < 6; i++)
	{
		cout << "Add " << i << " to Array\n";
		cout << "Array is: ";
		testCircularArray.AddElement(i);
		for (int j = 0; j < testCircularArray.Capacity(); j++)
		{
			cout << testCircularArray[j];
			if (j + 1 == testCircularArray.Capacity())
				break;

			cout << ", ";
		}
		cout << endl << "Array size: " << testCircularArray.Size() << endl;
	}

	
	cout << endl;
	system("pause");
}