#include"Menu.h"
#include"Encryptor.h"
#include"Decryptor.h"
#include"CreateScene.h"
#include"CheckScene.h"
#include"GenPwScene.h"
#include"AnalysScene.h"
#include<iostream>
#include<Windows.h>
#include<thread>
using std::cout;
using std::endl;
using std::cin;
using std::pair;

unordered_multimap<int, int> myStepMap;

void Menu::start() {
	CreateScene createScene;
	CheckScene checkScene;
	GenPwScene genPwScene;
	AnalysScene analysScene;
	Encryptor myEnc;
	Decryptor myDec;

	cout << "Initializing...\n";
	
	for (auto i = 1; i < 600; i++) {
		auto stepCount = myEnc.myEncrypt(i);
		myStepMap.insert(pair<int, int>(stepCount, i));
	}
	cout << "Finished.\n " << endl;

	auto f = [&]()->void {
		while (true) {
			cout << "--------------------------------------------------" << "\n";
			cout << "Please select your option:" << "\n";
			cout << "1. Create username and password" << "\n";
			cout << "2. Check username and password" << "\n";
			cout << "3. Generate password strength analysis file" << "\n";
			cout << "4. Analys passord strength analysis file" << "\n";
			cout << "5. Decrypt certain code ( Must be encrypted by printable ASCii code ) " << "\n";
			cout << "6. Exit" << "\n";
			cout << "--------------------------------------------------" << "\n";

			char usrInput;
			cin >> usrInput;
			switch (usrInput)
			{
			case '1':
				createScene.start();
				break;
			case '2':
				checkScene.start();
				break;
			case '3':
				genPwScene.start();
				break;
			case '4':
				analysScene.start();
				break;
			case '5':
				analysScene.parseOneStr();
				break;
			case '6':
				return;
			default:
				system("cls");
				cout << "Illegal input. Please try again: " << "\n";
				break;
			}
		}
	};
	f();          //  Call lambda function


	/************************************************************************************************************************************************/
	cout << std::thread::hardware_concurrency() << endl;

}

