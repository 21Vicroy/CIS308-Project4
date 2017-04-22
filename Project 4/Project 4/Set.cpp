#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std;


template <class T>
class Set {
private:
	int size = 10;
	int pos = 0;

public:
	T *Temp = new T;
	T *setArray = new T[10];
	Set();
	~Set();
	int insert(const T);
	void print(const string);
	void intersect(const Set);
	void unionm(const Set);
	void sort();
};

template <class T>
Set<T>::Set() {
}


//Print class for Set.cpp
//Prints the string that is passed in.
template <class T>
void Set<T>::print(const string s) {
	cout << s << endl;
}

//Instersect class for Set.cpp
//set 3 ints, one to act as a bool, and two as index's
//find matches to append into string stream
template <class T>
void Set<T>::intersect(const Set set2) {
	stringstream ss;
	int flag = 0;
	int i = 0;
	int j = 0;

	while (flag != 1)
	{
		//if i or j reaches the pos point in either set array, 
		//there is not point in continuing as no more matches will be found
		if (i >= pos - 1 || j >= set2.pos - 1)
		{
			if (setArray[i] == set2.setArray[j])
			{
				//Match found, append match into stringstream ss
				ss << setArray[i] << " ";
			}

			print(ss.str());
			flag = 1;
			break;
		}

		if (setArray[i] == set2.setArray[j])
		{
			//Match found, append match into stringstream ss
			ss << setArray[i] << " ";
			i++;
			j++;
		}
		else if (setArray[i] > set2.setArray[j])
		{
			//if set2's setArray element is smaller than this' setArray element, increase j index
			j++;
		}
		else if (setArray[i] < set2.setArray[j])
		{
			//if this setArray element is smaller than set2's setArray element, increase i index
			i++;
		}

	}
}

//Unionm class for Set.cpp
//forced to name unionm due to "union" name already used by C++ library
//Use a temp array to hold elements from this set and set2
//Use the temp array to prevent any duplicates from printing
//once done inserting into temp array, fill stringstream with elements in temparray and send it off to print.
template <class T>
void Set<T>::unionm(const Set set2) {
	stringstream ss;

	//ensure that the TempArray is large enough to potentially hold 
	//all elements in this set and set2
	int larger = size + set2.size;

	//position to insert element
	int tempPos = 0;

	//Temparray to hold elements before inserting them into 'ss'
	T *TempArray = new T[larger];

	//loop through this setArray
	//copy each element from setArray into TempArray
	for (int i = 0; i < pos - 1; i++)
	{
		TempArray[tempPos] = setArray[i];
		tempPos++;
	}

	//bool has, set to true if TempArray has an element in set2.setArray
	//insert into the temp array, set2 setArray
	//Check for any matches before inserting an element
	//if match found break out of for loop 'i'
	//if not match found, copy element from set2 to TempArray.
	bool has = false;
	for (int j = 0; j < set2.pos - 1; j++)
	{
		for (int i = 0; i < tempPos - 1; i++)
		{
			if (TempArray[i] == set2.setArray[j])
			{
				has = true;
			}
		}
		if (has == false)
		{
			TempArray[tempPos] = set2.setArray[j];
			tempPos++;
		}

	}

	//loop through TempArray and insert elements into 'ss'
	for (int i = 0; i < tempPos - 1; i++)
	{
		ss << TempArray[i] << " ";
	}

	print(ss.str());
}

//Insert method for Set.cpp
//Inserts the parameter passed in, into the setArray
//checks for size and resizes if necessary
//checks if the Array already has parameter in array, inserts parameter if not found in array
//calls on sort to sort
template <class T>
int Set<T>::insert(T elem) {
	int i;
	if (pos >= size)
	{
		size = size * 2;
		/*create a temporary arrary to copy setArray variables to*/
		T *newSet = new T[size];
		for (i = 0; i < pos; i++)
		{
			newSet[i] = setArray[i];
		}
		delete[] setArray;
		/*creat setArray again and copy the newSet's variable to the new larger setArray*/
		setArray = new T[size];
		for (i = 0; i < pos; i++)
		{
			setArray[i] = newSet[i];
		}
		delete[] newSet;
	}
	for (i = 0; i < pos; i++)
	{
		if (setArray[i] == elem)
		{
			return 0;
		}
	}
	setArray[pos] = elem;
	pos++;
	cout << setArray[pos - 1] << " is in the setArray" << endl;
	if (pos > 2)
	{
		sort();
	}
	return 0;
}

//Sorts the setArray
template <class T>
void Set<T>::sort() {
	//int i, j;
	//for (i = 0; i < pos - 1; i++)
	//{
	//	for (j = i + 1; j < pos - 2; j++)
	//	{
	//		if (setArray[j] < setArray[j + 1])
	//		{
	//			*Temp = setArray[j + 1];
	//			setArray[j + 1] = setArray[j];
	//			setArray[j] = *Temp;
	//		}
	//	}

	//}
	//bool swapped = true;
	//int i = 0;
	//int j = 0;
	//while (swapped == true)
	//{
	//	swapped = false;
	//	j++;
	//	for (i = 0; i < n - 1 - j; i++)
	//	{
	//		if (setArray[i] > setArray[i + 1])
	//		{
	//			*Temp = setArray[i];
	//			setArray[i] = setArray[i + 1];
	//			setArray[i + 1] = *Temp;
	//			swapped = true;
	//		}
	//	}
	//}

	for (int i = 0; i < pos - 1; i++)
	{
		*Temp = setArray[i];
		int currentMinIndex = i;

		for (int j = i + 1; j < pos; j++)
		{
			if (*Temp > setArray[j])
			{
				*Temp = setArray[j];
				currentMinIndex = j;
			}
		}
		 
		if (currentMinIndex != i) {
			setArray[currentMinIndex] = setArray[i];
			setArray[i] = *Temp;

		}
	}



}

//Delete method for Set.cpp
template <class T>
Set<T>::~Set() {
	delete[] setArray;
}
