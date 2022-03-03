//
// Created by Maikol Guzman Alan on 3/2/22.
//

#ifndef SOLID_01_DIP_APPRECEIPTEXCEPTION_H
#define SOLID_01_DIP_APPRECEIPTEXCEPTION_H
#include <exception>
using namespace std;

class AppReceiptException: public exception {
    const char * what () const throw();
};

#endif //SOLID_01_DIP_APPRECEIPTEXCEPTION_H
