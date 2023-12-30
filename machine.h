/***********************************************************************************************************************/
/**************   Team Members: Mohamed Alaa, Adham Waleed, Marwan Mahmoud  ********************************************/
/**************                 DATE: 30/12/2023                            ********************************************/
/**************                   VERSION: 0.1                              ********************************************/
/**************                 FILE: machine.h                             ********************************************/
/***********************************************************************************************************************/

#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>
using namespace std;


/*
 This class defines the product type and it's attributes
Attributes:
    1-Name
    2-Price
    3-Count
    4-Expiration Date
*/
class Product{
private:
    //Private attributes of class product
    string name;
    float price;
    int count;
    long expirationDate;
    string outlet;

public:
    //Constructor 1
    Product();
    //Constructor 2
    Product(string inputName,float inputPrice,int inputCount, string inputOutlet, int day,int month,int year);

    //GETTERS
    string const getName(); //returns name of product
    float const getPrice(); //returns price of product
    int const getCount();   //returns how many items left for product
    string const getOutlet();   //returns name of outlet the product dispense from

    //SETTERS
    void setName(string n); //Sets name of the product
    void setPrice(float n); //Sets price of the product
    void setCount(int n);  //Sets how many items are available for the product
    void setOutlet(string n); //Sets which outlet the product will dispense from
    void setExpiry(int day,int month,int year); //Sets expiration date of product in form dd/mm/yyyy

    //Restock product or adds to the already existing products
    void restockProduct(int itemsAdded);

    //Create a new product and set it's Name, Outlet, count, Expiration date
    void addItem();

    //Checks if the product is expired or not
    bool isExpired();

    //Updates product count after making a successful purchase
    void oneItemTaken();
};




/*
* This class defines the vending machine object, stores all products in vector of class "Product",
The class also contains programming mode, operation mode definitions

Attributes:
    1-items (Vector contains all products)
    2-key (Password to enter programming mode)
    3-finishFlag (Flag to exit from the machine menu)
*/
class VendingStorage{
private:
    //Private attributes for VendingStorage class
    vector<Product> items;
    int key;
    bool finishFlag;

public:
    //Constructor
    VendingStorage();

    //Used for manual adding of items before initializing the code
    void addProduct(Product item);

    //Operating Mode Functions
    void operationMode();
    void displayMenu();
    bool getFinishFlag();
    int SelectItemNumber();
    void moneyGrabber(int outletNumber);
    void returnChange(float money, int outletNumber);
    void dispenseItem(int outletNumber);

    //Programming Mode Functions
    void programmingMode();
    void displayItemsList();
    int numberOfProducts();

};
