/*
Write a function called swap that takes two pointers to integer arguments and returns void. 
Inside the function, swap the values of the integers. 
Write a main function that calls this function and verify that the value of the 
integers has indeed been swapped after this function call.

Deckard 14/10/2021
*/
#include <iostream>
using namespace std;

void swap(int **ptr1, int **ptr2)
{
    int *a = *ptr1;
    cout << "*a = " << *a << endl;
    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
    *ptr1 = *ptr2;
    cout << "ptr1 now is " << *ptr1 << endl;
    cout << "ptr1 now points to " << **ptr1 << endl;
    *ptr2 = a;
    cout << "ptr2 now is " << *ptr2 << endl;
    cout << "ptr2 now points to " << **ptr2 << endl;
}

int main()
{
    int a = 3, b = 5;
    int *ptr1 = &a;
    int *ptr2 = &b;

    swap(&ptr1, &ptr2);
    cout << "Now *ptr1 is " << *ptr1 << " And *ptr2 is " << *ptr2 << endl;
    return 0;
}
