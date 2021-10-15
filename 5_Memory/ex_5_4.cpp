/*
Examine some of the other options provided when calling new and delete. 
Amend the code to create an array of 10 integers on the heap. 
Ensure that you release the memory you created using the correct form of delete.

Deckard Zhao 15/10/2021
*/
#include <iostream>
using namespace std;

int main()
{
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i * 1;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << i << " : " << arr[i] << endl;
    }

    delete[] arr;
    return 0;
}
