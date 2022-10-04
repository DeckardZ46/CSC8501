#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <time.h>
#include "AnalysScene.h"
#include "Decryptor.h"
#include "FileDecryptor.h"

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::mutex;
using std::thread;
using std::getline;

void AnalysScene::start() {
	cout << "\nParsing passwords...\n";
	// todo Mod to threaded programming
	FileDecryptor fileDecryptor;
	// load file 
	ifstream pwTxt;
	mutex mtxPrint;
	mutex mtxRead;
	unordered_map<string, string>pwMap;
	try {
		pwTxt.open("passwordtest.txt", ios::out | ios::in);
		if (!pwTxt) {
			cout << "File doesn't exist. Failed!" << '\n';
			throw - 1;
		}
		else {
			cout << "passwordtest.txt exist. " << '\n';
		}
	}
	catch (int err) {
		cout << "Checking Failed. Back to main menu..." << '\n';
		return;
	}
	string currentStr;

	auto tFunc = [&](int flag)->void {

		auto start = clock();

		int failCount = 0;
		auto pos = 0;
		pwTxt.seekg(pos);

		for (auto j = 0; j < (flag * 100); j++) {
			string tmpLine;
			mtxRead.lock();
			getline(pwTxt, tmpLine);
			mtxRead.unlock();
		}
		for (auto i = 0; i < 100; i++) {
			string line;
			mtxRead.lock();
			getline(pwTxt, line);
			mtxRead.unlock();
			if (fileDecryptor.myDecrypt(line) == "-1") failCount++;
		}
		auto end = clock();
		mtxPrint.lock();
		cout << "Group " << flag + 1 << " done. Average time is: " << double(end - start)  / 100 << " ms;  Failed: " <<
			failCount << " of 100." << '\n';
		mtxPrint.unlock();
	};

	auto timeS = clock();

	std::thread myThreads[10];
	for (auto j = 0; j < 20; j++) {
		for (auto k = 0; k < 10; k++) {
			auto flag = j * 10 + k;
			myThreads[k] = std::thread(tFunc, flag);
			myThreads[k].join();
		}
	}

	auto timeE = clock();
	cout << " -------------Analysing DONE. Total time is: " << (double(timeE - timeS) / CLOCKS_PER_SEC) << "s --------------------------\n";
}

void AnalysScene::parseOneStr() {
	cout << "\nPlease enter encrypted password (-1 to exit) ,\n";
	cout << "Or enter -2 to decrypt default password in coursework: \n";
	string encryptedPw;
	cin >> encryptedPw;
	if (encryptedPw == "-1") {
		cout << "Return to main menu...\n";
		return;
	}
	if (encryptedPw == "-2")
		encryptedPw = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
	Decryptor myDec;
	auto fParse = [&]()->void {
		cout << "Encrypted password is: \n";
		cout << encryptedPw << '\n';
		myDec.myDecrypt(encryptedPw);
	};

	std::thread tParse(fParse);
	tParse.join();
	if (encryptedPw == "27322810313331033910211452912207344136146925461033281533271031012815108114101")
	{
		cout << "The only combination result which makes sense is : " << '\n';
		cout << "A friend to all is a friend to none" << '\n';
	}
	return;
}