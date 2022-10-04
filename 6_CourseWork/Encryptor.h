/*
    class Encryptor
*/
#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <string>
using std::string;

class Encryptor
{
public:
    string myEncrypt(string pwStr);
    int myEncrypt(int seed);
};

#endif