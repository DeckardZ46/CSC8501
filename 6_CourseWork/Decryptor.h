/*
    class Decryptor
*/
#ifndef DECRYPTOR_H
#define DECRYPTOR_H
#include <string>
using std::string;

class Decryptor
{
public:
  
    virtual string myDecrypt(string pwStr);
    //virtual string myRandDecrypt(string pwStr);
private:
};

#endif