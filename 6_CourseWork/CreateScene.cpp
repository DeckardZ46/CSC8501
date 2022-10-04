#include "CreateScene.h"
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

void CreateScene::start() {

	// load file 
	ifstream pwTxt;
	unordered_map<string, string>pwMap;

	try {
		pwTxt.open("password.txt", ios::out | ios::in);
		if (!pwTxt) {
			throw -1;
			return;
		}
		else {
			cout << "\npassword.txt exist. " << '\n';
		}
	}
	catch (int err) {
		cout << "\nError ! File doesn't exist. error code is "<< err << '\n';
		cout << "Creating new password.txt..." << '\n';
		ofstream pwFile("password.txt");
		pwFile.close();
		cout << "password.txt created. " << '\n';
	}

	ifstream pwFile;
	pwFile.open("password.txt", ios::out);

	string usrname;
	string password;
	while (getline(pwFile, usrname, ' ')) {
		getline(pwFile, password, '\n');
		pwMap.insert(pair<string, string>(usrname, password));
	}
	pwFile.close();

	// create username and password
	Encryptor crtSceneEncryptor;
	string usrName, passWord;

	while (true) {
		cout << "Please enter your username (-1 to exit) : " << "\n";
		cin >> usrName;
		// check if exit
		if (usrName == "-1") {
			cout << "Return to main menu..." << '\n';
			return;
		}
		// check if username repeat
		if (pwMap.count(usrName) != 0) {
			cout << "Username has existed. Please try again. " << '\n';
		}
		else break;
	}
	cout << "Please enter your password: " << "\n";
	cin >> passWord;
	string savePw = crtSceneEncryptor.myEncrypt(passWord);

	ofstream outfile;
	outfile.open("password.txt", ios::ate | ios::in);
	outfile << usrName << ' ' << savePw << '\n';
	outfile.close();

	cout << "Username and password SAVED." << "\n" << "\n";
	return;
}