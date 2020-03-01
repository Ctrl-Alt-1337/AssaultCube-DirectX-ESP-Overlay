#include <string>
#include <sstream>
#include <windows.h> 
#include <vector>
#include <iostream>
#include "Helper.h"

// Convert DWORD to hex
std::string hex(const DWORD in)
{
	std::stringstream ss;
	ss << std::hex << in;
	const auto ud = ss.str();

	return ud;
}

// takes in a std::vector array
void printArray(std::vector<unsigned int> arr) {


	if (arr.size() > 1)
	{
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			// add { to the beginning
			if (i == 0)
			{
				std::cout << "{" << hex(arr[i]) << ", ";
			}
			// add } to the end
			else if (i == (arr.size() - 1))
			{
				std::cout << hex(arr[i]) << "}";
			}
			// else print 'elm, '
			else
			{
				std::cout << hex(arr[i]) << ", ";
			}
		}
	}
	else
	{
		std::cout << "{ " << hex(arr[0]) << " }";
	}
}