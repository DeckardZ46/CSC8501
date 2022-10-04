#include "GenPwScene.h"
#include "Encryptor.h"
#include <iostream>
#include <fstream>
#include<algorithm>
#include<vector>
#include<time.h>

using std::cout;
using std::cin;
using std::ofstream;
using std::vector;
using std::ios;

void GenPwScene::start() {
	cout << "\nGenerating Passwords..." << "\n";
	
	srand(time(0));
	Encryptor genEncrypt;
	vector<int>alphabetASCII;
	vector<int>extendedASCII;

	for (auto i = 0; i < 26; i++) {
		alphabetASCII.push_back(97 + i);
	}
	for (auto i = 32; i < 256; i++) {
		if (i == 127)continue;
		extendedASCII.push_back(i);
	}
	//load file
	ofstream genPwFile("passwordtest.txt", ios::trunc);
	if (!genPwFile) {
		cout << "Falire. Returning to menu...\n";
		return;
	}

	auto start = clock();

	// generate 10000 passwords
	for (auto i = 0; i < 100; i++) {
		for (auto j = 0; j < 100; j++) {
			string pwStr = "";
			std::random_shuffle(alphabetASCII.begin(), alphabetASCII.end());
			for (auto k = 0; k < (i + 1); k++) {
				auto tmpChar = (char)alphabetASCII[rand() % 9];
				pwStr = pwStr + tmpChar;
			}
			//cout << pwStr << '\n';
			auto encryptedPw = genEncrypt.myEncrypt(pwStr);
			//cout << encryptedPw << '\n';
			genPwFile << encryptedPw << '\n';
		}
	}

	// generate another 10000 passwords
	for (auto i = 0; i < 100; i++) {
		for (auto j = 0; j < 100; j++) {
			string pwStr = "";
			std::random_shuffle(extendedASCII.begin(), extendedASCII.end());
			auto collatzStep = 0;
			for (auto k = 0; k < (i + 1); k++) {
				collatzStep = genEncrypt.myEncrypt(collatzStep + extendedASCII[k]);
				pwStr = pwStr + std::to_string(collatzStep);
			}

			//cout << pwStr << '\n';
			genPwFile << pwStr << '\n';
		}
	}

	auto end = clock();
	cout << "\nTime cost: " << double(end - start) / CLOCKS_PER_SEC << "s\n";
	cout << "\nGenerating complete. Return to main menu...\n" << "\n";
	genPwFile.close();
	return;
}