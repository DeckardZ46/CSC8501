/*
Write a function that accepts an integer argument and returns a boolean value. 
The function should return true if the integer argument is greater than or equal to zero, 
and false otherwise. Call this function with a positive and negative value to test that it works, 
using cout to display the result.

Deckard 13/10/2021
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
    int num1 = -1, num2 = 0, num3 = 1;

    cout << "is -1 >= 0: " << isGreaterToZero(num1) << endl;
    cout << "is 0 >= 0: " << isGreaterToZero(num2) << endl;
    cout << "is 1 >= 0: " << isGreaterToZero(num3) << endl;

    return 0;
}
