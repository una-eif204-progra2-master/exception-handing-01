//
// Created by Maikol Guzman Alan on 3/1/22.
//

#include "AppReceiptSender.h"
#include "AppReceiptException.h"
#include <iostream>

void AppReceiptSender::sendReceipt(std::string productName) const {
    if (productName.empty()) {
        throw AppReceiptException();
    }
    std::cout << "Product: " << productName <<", Printing the receipt..." << std::endl;
}
