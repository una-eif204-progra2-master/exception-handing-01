//
// Created by Maikol Guzman Alan on 3/1/22.
//

#include "ProductManager.h"
#include <vector>

void ProductManager::purchase(IReceiptSender *receiptSender) {
    receiptSender->sendReceipt(product.getName());
}

ProductManager::ProductManager() {}

ProductManager::~ProductManager() {

}

const Product &ProductManager::getProduct() const {
    return product;
}

void ProductManager::setProduct(const Product &product) {
    ProductManager::product = product;
}

void ProductManager::exampleBadCast() {
    struct Foo { virtual ~Foo() {} };
    struct Bar { virtual ~Bar() {} };
    Bar b;
    Foo& f = dynamic_cast<Foo&>(b);
}

void ProductManager::exampleBadException() throw(int, bad_exception) {
    throw 'x'; // throws char (not in exception-specification)
}

void ProductManager::exampleLengthError() {
    // vector throws a length_error if resized above max_size
    vector<int> myVector;
    myVector.resize(myVector.max_size()+1);
}
