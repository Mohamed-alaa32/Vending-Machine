

#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>
using namespace std;



class Product{
private:
    string name;
    float price;
    int count;
    long expirationDate;
    string outlet;
public:

    //Constructor 1
    Product(){
        name = "EMPTY";
        price = 0;
        count = 0;
        expirationDate = 0;
        outlet = "None";
    }

    //Constructor 2
    Product(string inputName,float inputPrice,int inputCount, string inputOutlet);
    //GETTERS
    string const getName();
    float const getPrice();
    int const getCount();
    string const getOutlet();

    //SETTERS
    void setName(string n);
    void setPrice(float n);
    void setCount(int n);
    void setOutlet(string n);
    void setExpiry(int day,int month,int year);

    //Restock
    void restockProduct(int itemsAdded);

    void addItem();

    bool isExpired();

    //Updating count after making a successful purchase
    void oneItemTaken();
};


/*
* This class contains vector of class "product" named "items"
* programming mode processes
* operation mode processes
*/

class VendingStorage{
private:
    vector<Product> items;
    int key = 123;  // used as password to enter programming mode
    bool finishFlag = false;
    //Today's Date: date
public:
    //Programming Mode
    void programmingMode();
    bool getFinishFlag();
    void displayItemsList();

    //Used for manual adding of items before initializing the code
    void addProduct(Product item);
    //Operating Mode
    void operationMode();
    void displayMenu();
    int numberOfProducts();
    int SelectItemNumber();
    void moneyGrabber(int outletNumber);
    void returnChange(float money, int outletNumber);
    void dispenseItem(int outletNumber);

};
