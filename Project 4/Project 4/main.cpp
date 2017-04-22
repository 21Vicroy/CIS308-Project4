/**********************************************
* Name: Michael Toy                           *
* Date: April 25, 2017                        *
* Assignment: Project 4: Sets                 *
**********************************************
The program uses a Set class to store elements in sorted order.
The program should be able to calculate the intersection and union between two sets.
The set should be implemented as a resizable array.
**********************************************/

#include "Set.cpp"
#include <io.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vcruntime.h>
#include <stdio.h>


using namespace std;

int main() {
	//char end;
	int booleanInt;
	Set<char> s;
	Set<char> s2;
	string input;
	char *token;
	char *next_token;
	const char * delim = " ,()";

	cout << "Please enter line for set 1: ";
	//cin >> input;
	//creat str char array via the length of "input" form the user
	char str[1024];
	cin >> str;
	cout << str << endl;
	//copy string into the char via c_str()
	//strcpy_s(str, 1024, input.c_str());
	//use strtok to take out any unwanted stuff and put into "token"
	token = strtok_s(str, delim, &next_token);
	while (token != NULL)
	{
		char in = *token;
		cout << token << endl;
		booleanInt = s.insert(in);
		token = strtok_s(NULL, delim, &next_token);
	}

	cout << "Please enter another line for set 2: ";
	//cin >> input;
	//creat str char array via the length of "input" form the user
	char str2[1024];
	cin >> str2;
	//copy string into the char via c_str()
	//strcpy_s(str2, 1024, input.c_str());
	token = strtok_s(str2, delim, &next_token);
	while (token != NULL)
	{
		booleanInt = s2.insert(*token);
		token = strtok_s(NULL, delim, &next_token);
	}

	//cout << s.setArray << endl;
	//cout << s2.setArray << endl;

	char choice = 'a';
	while (choice != 'e')
	{
		cout << "Enter (i)ntersect, (u)nion, or (e)xit to quite the program: ";
		cin >> choice;
		switch (choice)
		{
		case 'i':
			s.intersect(s2);
			break;
		case 'u':
			s.unionm(s2);
			break;
		case 'e':
			s.~Set();
			s2.~Set();
			return 0;
		default:
			cout << "invalid input";
			break;
		}

	}
}