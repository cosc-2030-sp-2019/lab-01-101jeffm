//Jeffrey Michaelis
//COSC 2030-11
//Lab 01 - Process Numbers and Compress
//Feb. 18, 2019

// RunLengthEncode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// CPP program to implement run length encoding
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line;
	string whitespace(" \t\f\v\n\r");
	vector<string> pix_list;
	int i, count, n;
	ifstream pixf_full;
	pixf_full.open("PixData.txt");
	ofstream pixf_cmpr;
	pixf_cmpr.open("PixCmprsFrank.txt");
	if (pixf_full.is_open()) cout << "Input pixf_full is open." << "\n";
	// Read into pix_list.
	i = 0;
	while (getline(pixf_full, line)) //While there is still a line to be read in the file the loop will continue to execute. 
	{
		cout << line;
		// The statement below will add an element to the vector. 
		// In this case the element being added is the most recent line  that wasread. 
		pix_list.push_back(line);
		i = i + 1;
	}
	n = pix_list.size();
	cout << "\n" << "Length of pix_list is " << n << " ; i = " << i << "\n";
	// Go through list, testing whether next pixel is the same.
	for (i = 0; i < n; i++) // i < n so that the program will read up to but not past the size of the vector. 
	{
		if (pix_list[i + 1] != pix_list[i]) // if the next element in the vector is not equal to the current element being searched,
			pixf_cmpr << pix_list[i] << "\n";       // then the element will be stored into the compressed file. 
		else
		{
			// Pixels same.
			// 1. Write flag character and repeated pixel.  Strip pesky newline at end.
			pixf_cmpr << "0 " << pix_list[i].substr(0, pix_list[i].find_last_not_of(whitespace));
			// Loop continues to execute as long as the most recent element matches the next element. Maintains a count of how many objects are the same. 
			count = 1;
			while (i < n - 1 && (pix_list[i] == pix_list[i + 1]))
			{
				count++;
				i++;
			}
			// Different pixel or end of file encountered.
			// Write output to file.
			pixf_cmpr << " " << count << "\n";
		}
	}

	return 0;
}


