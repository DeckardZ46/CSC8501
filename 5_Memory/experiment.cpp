/*
    It't just a experiment shows what happens when a pointer to pointer meets memory allocation.
*/
#include <iostream>
using namespace std;
int main()
{
    int a = 100;
    int *b = new int;
    int **c = new int *;
    *b = a;
    cout << c << " " << *c << endl;
    *c = b;

    cout << a << " " << b << " " << c << " " << *b << " " << *c << " " << **c << endl;
    delete b;
    //b = nullptr;
    cout << a << " " << b << " " << c << " " << *b << " " << *c << " " << **c << endl;
    delete c;
    //c = nullptr;
    cout << a << " " << b << " " << c << " " << *b << " " << *c << " " << **c << endl;

    return 0;
}
