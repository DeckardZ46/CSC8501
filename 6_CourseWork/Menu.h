/*
    class Menu
*/
#ifndef MENU_H
#define MENU_H
#include <string>
#include<unordered_map>
using std::string;
using std::unordered_map;
using std::unordered_multimap;

extern unordered_multimap<int, int> myStepMap;

class Menu
{
public:
   virtual void start();
};

#endif
