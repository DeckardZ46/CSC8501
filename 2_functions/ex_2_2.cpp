/*
Write a function called quotient which should take a double argument and an integer argument. 
This function should also return a double data type. 
Now if you provide the quotient function with the values 5 and 3 say, 
it should return the value 1.66667 or thereabouts. Test this by calling the function within a cout statement.

Deckard 08/10/2021
*/
#include <iostream>
using namespace std;

double quotient(double num1, int num2)
{
    double result = num1 / num2;
    return result;
}

int main()
{
    double num1;
    int num2;
    cout << "Please enter num1:" << endl;
    cin >> num1;
    cout << "Please enter num2:" << endl;
    cin >> num2;

    double result = quotient(num1, num2);
    cout << "The result is: " << result << endl;
    return 0;
}
