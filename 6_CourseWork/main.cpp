/*
Password Encrypting & Decrypting programme based on Collatz conjecture

Author: Deckard Zhao 200909583
*/
#include <iostream>
#include"Menu.h"


inline void studentInfo() {
    std::cout << "student name:Shilu Zhao" << std::endl;
    std::cout << "student number:200909583" << std::endl;
}
int main()
{
    studentInfo();
    Menu menu;
    menu.start();
    return 0;
}
