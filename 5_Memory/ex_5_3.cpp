/*
Amend the code to create a char variable on the stack and a string variable on the heap.

Deckard Zhao 14/10/2021
*/
#include <iostream>
using namespace std;

int main()
{
    char a = 'k'; // char on the stack
    string b = "hello memory";
    string *str = new string; // string on the heap
    cout << "The pointer str points to the memory address " << str << " located on the heap\n";
    cout << "The value in memory location str is "
         << "\" " << *str << " \""
         << "\n";
    *str = b;
    cout << "The value of stack variable a is " << a << "\n";
    cout << "The ’heap’ memory pointed to by str contains " << *str << "\n";
    cout << "While actually the string b is also on the stack: " << b << endl;
    cout << "And it's basically a char array. We can show value of b[0]: " << b[0] << endl;

    delete str;
    str = nullptr;

    return 0;
}
