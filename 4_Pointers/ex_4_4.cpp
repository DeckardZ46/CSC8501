/*
Pointer arithmetic can be used to access specific values when a sequence of such values exist. 
Create an array of 10 integers numbered 1 to 10 with the syntax:
int arr[10] = {1,2,3,4,5,6,7,8,9,10};
Now create a function which accepts a integer pointer as its argument and returns void. 
Implement the function to print out the even numbers of the array using pointer arithmetic.

Deckard 14/10/2021
*/
#include <iostream>
using namespace std;

void printEvenNum(int *ptr1);

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printEvenNum(arr);
    return 0;
}

void printEvenNum(int *ptr1)
{
    for (int i = 0; i < 10; i++)
    {
        if (*(ptr1 + i) % 2 == 0)
            cout << *(ptr1 + i) << endl;
    }
}
