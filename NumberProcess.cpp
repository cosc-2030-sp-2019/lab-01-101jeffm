//Jeffrey Michaelis
//COSC 2030-11
//Lab 01 - Process Numbers and Compress
//Feb. 18, 2019

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string numFile;
	double first, pen, last;
	int count = 0 ,count2 = 0; 
	cout << "Enter the name of the file you would like to read: ";
	cin >> numFile;
	ifstream file_count; 
	file_count.open(numFile); //opens infile. 
	if (file_count) {
		while (file_count >> first) {
			count++; // count of numbers in the file
		}
		file_count.close();
		if (count == 0) {
			cout << "There are no numbers in this file." << endl; //chceks to see if there are no numbers in the file 
		}
		else {
			file_count.open(numFile);
			file_count >> first; //Assigns first number in file.
			last = first;
			pen = last;
			count2++; 
			while (count > count2) //While count2 does not exceed count, loop will continue to execute and check for penultimate and last numbers in the file. 
			{
				pen = last; //asssigns the penultimate number to be equal to the previous last number. 
				file_count >> last;
				count2++;

			}
			cout << "There are " << count << " number(s) in the file. The first number is "
				<< first << ", the penultimate number is " << pen << " and the last number is "
				<< last << "." << endl;
		}
	}
	else {
		cout << "This file could not be found/opened. The program will now exit." << endl; //If file cannot be read or found, output and exit of program. 
	}
	  return 0;
}

