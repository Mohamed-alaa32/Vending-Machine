/***********************************************************************************************************************/
/**************   Team Members: Mohamed Alaa, Adham waleed, Marwan Mahmoud  ********************************************/
/**************                 DATE: 30/12/2023                            ********************************************/
/**************                   VERSION: 0.1                              ********************************************/
/**************                 FILE: main.cpp                              ********************************************/
/***********************************************************************************************************************/

#include <iostream>
#include <ctime>
#include "../machine.h"

using namespace std;

int main()
{
    //Initialize Vending Machine Instance
    VendingStorage machine;

    //Manually adding starting products
    Product item1("Coca cola", 5.5, 1, "Soda" ,29,6,2025);
    Product item2("Pepsi", 7.0, 0, "Soda", 29,6,2025);
    Product item3("Nestle 1L", 4.5, 20, "Water" ,29,6,2025);
    Product item4("Orange Juice", 8.0, 20, "Juice" ,29,6,2025);

    machine.addProduct(item1);
    machine.addProduct(item2);
    machine.addProduct(item3);
    machine.addProduct(item4);

    //Stays in loop until finish flag is set to true to break and exit machine
    while(!machine.getFinishFlag()){

        machine.operationMode();

    }

    return 0;
}
