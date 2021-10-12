/*
Write a “calculator program” which asks for two numbers 
and a mathematical operator (repre- sented as a char type. 
Depending on the operator (+, -, * or /) call the appropriate function and display the result. 
Use a switch statement to filter the choices.

Deckard Zhao 12/10/2021
*/

#include <iostream>
using namespace std;

int funcPlus(int num1, int num2)
{
    return num1 + num2;
}

int funcMinus(int num1, int num2)
{
    return num1 - num2;
}

int funcProduct(int num1, int num2)
{
    return num1 * num2;
}

int funcQuotient(int num1, int num2)
{
    return num1 / num2;
}

int main()
{
    int num1, num2;
    char oprt;
    cout << "Please enter two numbers: " << endl;
    cin >> num1 >> num2;
    cout << "Please enter a math operator (+ - * /):" << endl;
    cin >> oprt;
    cout << "The result is:";

    switch (oprt)
    {
    case '+':
        cout << funcPlus(num1, num2);
        break;
    case '-':
        cout << funcMinus(num1, num2);
        break;
    case '*':
        cout << funcProduct(num1, num2);
        break;
    case '/':
        cout << funcQuotient(num1, num2);
        break;
    default:
        cout << "Illegal operator!";
        break;
    }
    cout << endl;

    return 0;
}
