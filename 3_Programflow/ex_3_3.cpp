/*
Recursion is an alternative to writing loops where a function “calls itself”. 
Write another version of the factorial function that uses Recursion instead of loops. 
What is one advantage and one disadvantage of using Recursion as an alternative to loops?

Deckard 13/10/2021
*/
#include <iostream>
using namespace std;

int factorial(int num1, int fact)
{
    if ((num1 - 1) <= 0)
        return fact;
    return factorial(num1 - 1, fact * (num1 - 1));
}
int main()
{
    int num1;
    cout << "Please enter a number:" << endl;
    cin >> num1;
    cout << "The factorial of the number is: " << factorial(num1, num1) << endl;
    return 0;
}
