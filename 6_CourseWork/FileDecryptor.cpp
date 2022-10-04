#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "FileDecryptor.h"
#include "Menu.h"
using std::cout;
using std::string;
using std::vector;

struct myDecryptNode {
	int curStep;
	vector<int>potentialASCii;
	//vector<string>potentialPwd;
	myDecryptNode* digitPotential;
	myDecryptNode* doubleDigitPotential;
	myDecryptNode* tripleDigitPotential;
};
string FileDecryptor::myDecrypt(string str)
{
	if (str == "")return "1";
	myDecryptNode* headNode = new myDecryptNode();

	const auto& decryptPw = [=](string encryStr, myDecryptNode** headNode) {
		const auto& f = [=](auto&& self, const char* currentPtr, myDecryptNode** curNode) -> bool {
			// does one digit potential works?
			auto curDigit = (int)(*currentPtr) - 48;
			bool isThisRouteOK[] = { 0,0,0 };
			if (curDigit < 5 || myStepMap.count(curDigit) == 0) {			// 48 is ascii for number 0; 5 is minimum step for visible ascii chars
				(*curNode)->digitPotential = nullptr;
				if (*(currentPtr + 1) == '\0') {
					return false;
				}
			}
			else {
				(*curNode)->digitPotential = new myDecryptNode();
				(*curNode)->digitPotential->curStep = curDigit;
				for (auto iter : myStepMap) {
					if (iter.first == curDigit)
					{
						auto asciiNum = iter.second - ((*curNode)->curStep);
						if (asciiNum >= 0)(*curNode)->digitPotential->potentialASCii.push_back(asciiNum);
					}
				}
				if (*(currentPtr + 1) != '\0')
				{
					if (!self(self, (currentPtr + 1), &(*curNode)->digitPotential)) {
						delete (*curNode)->digitPotential;
						(*curNode)->digitPotential = nullptr;
					}
					
					else {
						return true;
					}
				}
				else {
					return true;
				}
			}
			// does two digits potential works?
			auto curTwoDigNum = (int)(*(currentPtr + 1)) - 48 + (10 * curDigit);
			if (myStepMap.count(curTwoDigNum) == 0) {
				(*curNode)->doubleDigitPotential = nullptr;
			}
			else {
				(*curNode)->doubleDigitPotential = new myDecryptNode();
				(*curNode)->doubleDigitPotential->curStep = curTwoDigNum;
				for (auto iter : myStepMap) {
					if (iter.first == curTwoDigNum)
					{
						auto asciiNum = iter.second - ((*curNode)->curStep);
						if (asciiNum >= 0)(*curNode)->doubleDigitPotential->potentialASCii.push_back(asciiNum);
					}
				}
				if (*(currentPtr + 2) != '\0')
				{
					if (!self(self, (currentPtr + 2), &(*curNode)->doubleDigitPotential)) {
						delete (*curNode)->doubleDigitPotential;
						(*curNode)->doubleDigitPotential = nullptr;
					}
					else {
						return true;
					}
				}
				else {
					return true;
				}
			}
		
			// does three digits potential works?
			if (*(currentPtr + 2) == '\0') {
				(*curNode)->tripleDigitPotential = nullptr;
				return false;
			}
			else {
				auto curThreeDigNum = ((int)(*(currentPtr + 2)) - 48) + 10 * curTwoDigNum;
				(*curNode)->tripleDigitPotential = new myDecryptNode();
				(*curNode)->tripleDigitPotential->curStep = curThreeDigNum;

				for (auto iter : myStepMap) {
					if (iter.first == curThreeDigNum)
					{
						auto asciiNum = iter.second - ((*curNode)->curStep);
						if (asciiNum >= 0)(*curNode)->tripleDigitPotential->potentialASCii.push_back(asciiNum);
					}
				}
				if (*(currentPtr + 3) != '\0')
				{
					if (!self(self, (currentPtr + 3), &(*curNode)->tripleDigitPotential)) {
						delete (*curNode)->tripleDigitPotential;
						(*curNode)->tripleDigitPotential = nullptr;
					}
					else {
						return true;
					}
				}
				else {
					return true;
				}

			}
		return false;
	};
	return f(f, encryStr.c_str(), headNode);
};

if (!decryptPw(str, &headNode)) {
	//cout << "Failed: " << str << '\n';
	return "-1";
}


return "1";
}