/*
Write another function that continuously asks for numbers (use cin), 
until the user provides a negative number. 
You’ll need some kind of loop and you should make use of the function you created in Exercise 1.

Deckard 13/20/2021
*/
#include <iostream>
using namespace std;

bool isGreaterToZero(int num1)
{
    if (num1 >= 0)
        return true;
    else
        return false;
}

int main()
{

    while (true)
    {
        int num1;
        cout << "Please enter a number:" << endl;
        cin >> num1;
        if (!isGreaterToZero(num1))
            break;
    }

    return 0;
}