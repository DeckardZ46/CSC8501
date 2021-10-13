/*
Amend the code so that it asks for two numbers from the user. 
Store these numbers in separate integer variables and then 
print to screen their sum and product on separate lines. 
Use cin and cout—as well as the new line character—to accomplish this task.

Deckard 07/10/2021
*/

#include <iostream>
using namespace std;

int main()
{
    int num_1;
    int num_2;
    cout << "Please enter two numbers:" << endl;

    cin >> num_1;
    cin >> num_2;

    cout << "The sum of two numbers is: " << num_2 + num_1 << endl;
    cout << "The product of two numbers is:" << num_1 * num_2 << endl;

    return 0;
}