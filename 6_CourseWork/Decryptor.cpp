#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Decryptor.h"
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

string Decryptor::myDecrypt(string str) {

	myDecryptNode* headNode = new myDecryptNode();
	srand(time(0));
	auto start = clock();
	const auto& decryptPw = [](string encryStr, myDecryptNode** headNode) {
		const auto& f = [](auto&& self, const char* currentPtr, myDecryptNode** curNode) -> bool {
			cout << "Calling recursion..." << '\n';
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
						if (asciiNum < 127 && asciiNum>31) {
							if (asciiNum >= 0)(*curNode)->digitPotential->potentialASCii.push_back(asciiNum);
						}
					}
				}

				if ((*curNode)->digitPotential->potentialASCii.size() == 0) {
					delete (*curNode)->digitPotential;
					(*curNode)->digitPotential = nullptr;
				}
				else {

					if (*(currentPtr + 1) != '\0')
					{
						if (!self(self, (currentPtr + 1), &(*curNode)->digitPotential)) {
							delete (*curNode)->digitPotential;
							(*curNode)->digitPotential = nullptr;
						}
						else {
							isThisRouteOK[0] = true;
						}
					}
					else {
						isThisRouteOK[0] = true;
						return true;
					}
				}
			}
			// does two digits potential works?
			auto curTwoDigNum = 0;
			if (*(currentPtr + 1) == '\0') {
				(*curNode)->doubleDigitPotential = nullptr;
			}
			else {
				curTwoDigNum = (int)(*(currentPtr + 1)) - 48 + (10 * curDigit);
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

							if (asciiNum < 127 && asciiNum>31) {
								if (asciiNum >= 0)(*curNode)->doubleDigitPotential->potentialASCii.push_back(asciiNum);
							}
						}
					}
					if ((*curNode)->doubleDigitPotential->potentialASCii.size() == 0) {
						delete (*curNode)->doubleDigitPotential;
						(*curNode)->doubleDigitPotential = nullptr;
					}
					else {
						if (*(currentPtr + 2) != '\0')
						{
							if (!self(self, (currentPtr + 2), &(*curNode)->doubleDigitPotential)) {
								delete (*curNode)->doubleDigitPotential;
								(*curNode)->doubleDigitPotential = nullptr;
							}
							else {
								isThisRouteOK[1] = true;
							}
						}
						else {
							isThisRouteOK[1] = true;
							return true;
						}
					}
				}
			}

			// does three digits potential works?
			if (*(currentPtr + 2) == '\0') {
				(*curNode)->tripleDigitPotential = nullptr;
			}
			else {
				auto curThreeDigNum = ((int)(*(currentPtr + 2)) - 48) + 10 * curTwoDigNum;
				(*curNode)->tripleDigitPotential = new myDecryptNode();
				(*curNode)->tripleDigitPotential->curStep = curThreeDigNum;

				for (auto iter : myStepMap) {
					if (iter.first == curThreeDigNum)
					{
						auto asciiNum = iter.second - ((*curNode)->curStep);

						if (asciiNum < 127 && asciiNum>31) {
							if (asciiNum >= 0)(*curNode)->tripleDigitPotential->potentialASCii.push_back(asciiNum);
						}
					}
				}

				if ((*curNode)->tripleDigitPotential->potentialASCii.size() == 0) {
					delete (*curNode)->tripleDigitPotential;
					(*curNode)->tripleDigitPotential = nullptr;
				}
				else {

					if (*(currentPtr + 3) != '\0')
					{
						if (!self(self, (currentPtr + 3), &(*curNode)->tripleDigitPotential)) {
							delete (*curNode)->tripleDigitPotential;
							(*curNode)->tripleDigitPotential = nullptr;
						}
						else {
							isThisRouteOK[2] = true;
						}
					}
					else {
						isThisRouteOK[2] = true;
						return true;
					}
				}
			}
			if (isThisRouteOK[0] == false && isThisRouteOK[1] == false && isThisRouteOK[2] == false) {
				return false;
			}
			return true;
		};
		return f(f, encryStr.c_str(), headNode);
	};

	if (!decryptPw(str, &headNode)) {
		cout << "\n-----------This encrypted string can NOT be decrypted.-----------\n";
		return "-1";
	}

	auto end = clock();

	// traverse decrypt tree to get all potential password
	const auto& showPotentialPwds = [](myDecryptNode** headNode) {
		const auto& showPw = [](auto&& self, myDecryptNode** curNode, vector<vector<int>> *asciiVec) -> void {
			if ((*curNode)->digitPotential != nullptr) {
				vector<vector<int>> tmpVec = *asciiVec;
				tmpVec.push_back((*curNode)->digitPotential->potentialASCii);
				self(self, &(*curNode)->digitPotential, &tmpVec);
			}
			if ((*curNode)->doubleDigitPotential != nullptr) {
				vector<vector<int>> tmpVec = *asciiVec;
				tmpVec.push_back((*curNode)->doubleDigitPotential->potentialASCii);
				self(self, &(*curNode)->doubleDigitPotential,&tmpVec);
			}
			if ((*curNode)->tripleDigitPotential != nullptr) {
				vector<vector<int>> tmpVec = *asciiVec;
				tmpVec.push_back((*curNode)->tripleDigitPotential->potentialASCii);
				self(self, &(*curNode)->tripleDigitPotential, &tmpVec);
			}

			if ((*curNode)->digitPotential == nullptr &&
				(*curNode)->doubleDigitPotential == nullptr &&
				(*curNode)->tripleDigitPotential == nullptr) {
				cout << "\n \n \n \n Potential password found:  \n";
				
				for (auto i = 0; i < (*asciiVec).size(); i++) {
					cout << "Position "<<i<<" could be: ";
					for (auto j = 0; j < (*asciiVec)[i].size(); j++) {
						cout << (char)(*asciiVec)[i][j];
					}
					cout << '\n';
				}
				
				return;
			}
		};
		vector<vector<int>>iniVec = {};
		showPw(showPw, headNode, &iniVec);
		return;
	};
	showPotentialPwds(&headNode);

	cout << "\nTime cost: " << double(end - start) / CLOCKS_PER_SEC << "s\n";
	return "1";
}


