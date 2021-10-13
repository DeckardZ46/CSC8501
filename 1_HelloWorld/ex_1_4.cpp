/*
Amend the code from Lesson 1 so that the program asks for 
your first name and then prints “Hello (your name)!” to the screen. 
Use the cin and cout classes to accomplish this. 
In addition, use the string variable type in the std namespace to store your name.

Deckard 07/10/2021
*/
#include <iostream>
using namespace std;

int main()
{
    cout << "What's your first name? Please enter below:" << endl;
    string firstName;
    cin >> firstName;
    cout << "Hello " + firstName + "!" << endl;
    return 0;
}
