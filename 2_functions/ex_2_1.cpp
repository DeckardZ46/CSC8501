/*
Not every function we may write has to return a value. 
Write a function called product which accepts two integers as arguments (like add and minus) 
but returns no value. In the function body the product function should use cout to print the product directly to screen.

Deckard 08/10/2021
*/
#include <iostream>
using namespace std;

void product(int num_1, int num_2)
{
    cout << "The product of two numbers is: " << num_1 * num_2 << endl;
}

int main()
{
    cout << "Please enter two integers: " << endl;
    int num_1, num_2;
    cin >> num_1 >> num_2;
    product(num_1, num_2);
}