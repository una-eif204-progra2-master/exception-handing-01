//
// Created by Maikol Guzman Alan on 3/2/22.
//

#include "AppReceiptException.h"

const char *AppReceiptException::what() const throw() {
    return "My exception App Receipt happened";
}
