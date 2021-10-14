#include <iostream>
using namespace std;

int main()
{
    float a = 1.203;
    float* b = &a ;
    cout<<"b holds the memory address of "<<b<<endl;
    cout<<"*(b+3) holds the memory address of "<< &*(b+3)<<endl;
    return 0;
}