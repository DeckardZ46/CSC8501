/*
Write a “calculator program” which asks for two numbers 
and a mathematical operator (repre- sented as a char type. 
Depending on the operator (+, -, * or /) call the appropriate function and display the result. 
Use a switch statement to filter the choices.

Deckard Zhao 12/10/2021
*/

#include <iostream>
using namespace std;

int plus(int num1, int num2)
{
    return num1 + num2;
}

int minus(int num1, int num2)
{
    return num1 - num2;
}

int product(int num1, int num2)
{
    return num1 * num2;
}

int quotient(int num1, int num2)
{
    return num1 / num2;
}

int main()
{

    cout << "Please enter two numbers: " << endl;
    return 0;
}
