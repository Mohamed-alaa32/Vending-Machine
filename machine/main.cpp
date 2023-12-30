#include <iostream>

#include <vector>
#include <conio.h>
#include <ctime>
#include "../machine.h"

using namespace std;
/*
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
*/
int main()
{
    //Initialize Vending Machine Instance
    VendingStorage machine;

    //Manually adding starting products
    Product item1("Coca cola", 5.5, 1, "Soda");
    Product item2("Pepsi", 7.0, 0, "Soda");
    Product item3("Nestle 1L", 4.5, 20, "Water");
    Product item4("Orange Juice", 8.0, 20, "Juice");
    machine.addProduct(item1);
    machine.addProduct(item2);
    machine.addProduct(item3);
    machine.addProduct(item4);

    while(true){
        machine.operationMode();
        if(machine.getFinishFlag()){
            break;
        }
    }

    return 0;
}
