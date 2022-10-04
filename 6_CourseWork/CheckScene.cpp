#include "CheckScene.h"
#include "Encryptor.h"
#include <iostream>
#include<fstream>
#include<unordered_map>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::unordered_map;
using std::pair;

void CheckScene::start() {
	Encryptor myEnc;
	cout << "\nChecking username and password..." << '\n';
	// load file 
	ifstream pwTxt;
	unordered_map<string, string>pwMap;
	try {
		pwTxt.open("password.txt", ios::out | ios::in);
		if (!pwTxt) {
			cout << "File doesn't exist. Failed!" << '\n';
			throw - 1;
		}
		else {
			cout << "password.txt exist. " << '\n';
			ifstream pwFile;
			pwFile.open("password.txt", ios::out);

			string username;
			string password;
			while (getline(pwFile, username, ' ')) {
				getline(pwFile, password, '\n');
				pwMap.insert(pair<string, string>(username, password));
			}
			pwFile.close();
		}
	}
	catch (int err) {
		cout << "Checking Failed. Back to main menu..." << '\n';
		return;
	}

	string usrName, password;
	cout << "Please enter your username (-1 to exit) : " << '\n';
	while (true) {
		cin >> usrName;
		if (usrName == "-1") { 
			cout << "Return to main menu..." << '\n';
			return; 
		}

		if (pwMap.count(usrName) == 0) {
			cout << "Username doesn't exist! Please try another username (-1 to exit) : " << '\n';
		}else if(pwMap.count(usrName) != 0) {
			cout << "Username has existed. Please enter your password: " << '\n';
			cout << "You have 3 chances to enter your password. " << '\n';
			break;
		}
	}
	for (auto i = 0; i < 3;i++) {
		cin >> password;
		if (pwMap.find(usrName) != pwMap.end()) {
			auto encryptedPw = myEnc.myEncrypt(password);
			if (encryptedPw == pwMap[usrName]) {
				cout << "Correct password. SUCCESS." << '\n' << "\n";
				return;
			}
			else {
				cout << "Wrong password. FAILURE." << '\n';
				cout << "You have " <<2- i << " chances to enter your password. " << '\n';
			}
		}
	}
	cout << "You have no chance left. Checking failed." << '\n' << "\n";
	return;
};