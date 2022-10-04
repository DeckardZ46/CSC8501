#include "Encryptor.h"
#include <iostream>
using std::cout;
using std::endl;

string Encryptor::myEncrypt(string str)
{
	string resultStr;
	int offset = 0;

	for (auto character : str) {
		auto asciiChar = (int)character;
		auto step = 0;

		auto collatz = [asciiChar, &offset]() ->int {
			int currentNum = asciiChar + offset;
			int collatzStep = 0;
			while (currentNum != 1) {
				if ((currentNum &1)==0) {							// same as currentNum%2 ==0
					currentNum = currentNum >>1;			// same as currentNum/2
				}
				else if ((currentNum &1)==1) {
					currentNum = 3 * currentNum + 1;
				}
				collatzStep++;
			}
			offset = collatzStep;
			return collatzStep;
		};

		step = collatz();
		resultStr = resultStr + std::to_string(step);
	}
	return resultStr;
}

int Encryptor::myEncrypt(int curNum) {
	auto currentNum = curNum;
	auto step = 0;
	while (currentNum != 1) {
		if ((currentNum & 1) == 0) {
			currentNum = currentNum>>1;
		}
		else if ((currentNum & 1) == 1) {
			currentNum = 3 * currentNum + 1;
		}
		step++;
	}
	return step;
}