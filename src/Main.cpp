//
// Created by Maikol Guzman Alan on 3/1/22.
//
#include <iostream>
#include "IReceiptSender.h"
#include "EmailReceiptSender.h"
#include "AppReceiptSender.h"
#include "Product.h"
#include "ProductManager.h"
#include "AppReceiptException.h"

using namespace std;

/**
 * The unexpected handler function is a function automatically called when a function throws an exception that
 * is not in its dynamic-exception-specification (i.e., in its throw specifier).
 */
void myUnexpected () {
    std::cerr << "unexpected handler called\n";
    throw;
}

int main() {

    set_unexpected (myUnexpected);

    try {
        cout << "Welcome to the UNA! (VIRTUAL)\n" << std::endl;

        IReceiptSender* emailReceiptSender = new EmailReceiptSender();
        IReceiptSender* appReceiptSender = new AppReceiptSender();

        Product product1;
        product1.setName("Producto 1");
        product1.setPrice(100);

        ProductManager productManager;
        productManager.setProduct(product1);

        // Submit the receipt by email
        productManager.purchase(emailReceiptSender);

        // Submit the receipt by app
        productManager.purchase(appReceiptSender);

        // Examples with different errors
        Product product2;
        product2.setName("Producto 2");
        product2.setPrice(100);

        productManager.setProduct(product2);

        productManager.purchase(appReceiptSender); // Error if name is empty
        //productManager.exampleBadCast(); // Example of error bad cast
        productManager.exampleBadException(); // Example of bad exception
        //productManager.exampleLengthError(); // Example of length error

    } catch(const bad_cast& bc) {
        cerr << "bad_cast caught: " << bc.what() << '\n' << std::endl;
    }  catch (const bad_exception& be) {
        cerr << "bad_exception caught: " << be.what() << '\n' << std::endl;
    } catch (const length_error& le) {
        cerr << "length_error caught: " << le.what() << '\n' << std::endl;
    } catch (AppReceiptException& are) {
        cerr << "AppReceiptException caught: " << are.what() << '\n' << std::endl;
    } catch (exception& ex) {
        cerr << ex.what() << '\n' << std::endl;
    }

    return 0;
}
