/***********************************************************************************************************************/
/**************   Team Members: Mohamed Alaa, Adham waleed, Marwan Mahmoud  ********************************************/
/**************                 DATE: 30/12/2023                            ********************************************/
/**************                   VERSION: 0.1                              ********************************************/
/**************                 FILE: machine.cpp                           ********************************************/
/***********************************************************************************************************************/

#include <iostream>
#include <vector>
#include <conio.h>
#include "machine.h"
#include <ctime>
using namespace std;



/************************************************************************************/
/************************************************************************************/
/**************               Class Product             *****************************/
/************************************************************************************/
/************************************************************************************/
/**
 This class defines the product type and it's attributes
Attributes:
    1-Name
    2-Price
    3-Count
    4-Expiration Date
Methods:
    1-set information
    2-get information
    3-add items
    4-restock products
**/
///Constructor 1, Initializes Product object without giving parameters
Product::Product(){
    name = "EMPTY";
    price = 0;
    count = 0;
    expirationDate = 0;
    outlet = "None";
}

///Constructor 2, Initializes Product object and sets object attributes to the parameters given to the function
Product::Product(string inputName,float inputPrice,int inputCount, string inputOutlet, int day,int month,int year){
    name = inputName; //Sets name of product
    price = inputPrice; //Sets price of product
    count = inputCount; //Sets number of products
    outlet = inputOutlet; //Sets outlet name of product

    ///Transforms expiration date form from dd/mm/yyyy to tm pointer using ctime library
    struct tm * date;
    time_t current;
    time(&current);
    date = localtime(&current);
    date -> tm_year = year - 1900;
    date-> tm_mon = month - 1;
    date-> tm_mday = day;
    expirationDate = mktime(date);
}

//GETTERS
string const Product::getName() {
    return name; ///Returns name of product
}
float const Product::getPrice(){
    return price; ///Returns price of product
}
int const Product::getCount() {
    return count; ///Returns number of items of product
}
string const Product::getOutlet(){
    return outlet; ///Returns name of outlet the product dispenses from
}

//SETTERS
///Sets name of product
void Product::setName(string n){
    name = n;
}
///Sets price of product
void Product::setPrice(float n){
    price = n;
}
///Sets number of items of product
void Product::setCount(int n){
    count = n;
}
///Sets name of outlet of product
void Product::setOutlet(string n){
    outlet = n;
}
///Sets expiration date of product in form dd/mm/yyyy
///and sets time to 11:59:59 of that date
void Product::setExpiry(int day,int month,int year){
    struct tm * date;
    time_t current;
    time(&current);
    date = localtime(&current);
    date -> tm_year = year - 1900;
    date-> tm_mon = month - 1;
    date-> tm_mday = day;
    date-> tm_hour = 23;
    date-> tm_min = 59;
    date-> tm_sec = 59;
    expirationDate = mktime(date);
    time(&current);
}

///Restock product or adds to existing products
///Takes number of products to add then calculates total number of products
///after adding the new products and updates item "Count"
void Product::restockProduct(int itemsAdded){
    //  ask for quantity to add
    //  adds quantity to count
    count += itemsAdded;
    cout << "\nThere are now " << count << " products of [" << name << "]. \n \n";
}

///Checks if the product is expired or not
///Returns true if expired , false if not
bool Product::isExpired(){
    long Now = time(NULL);
    if (expirationDate > Now) return false;
    else return true;
}

///Used to add new item in programming mode
void Product::addItem(){
    string newName,newOutlet; //new product's name, outlet name of product
    int newCount; //Number of Products
    float newPrice;  //Price of product
    int day,month,year; //Date of expiration in dd/mm/yyyy format

    // ask the vendor to enter product name
    cin.ignore(); //clears input buffer to make getline work properly
    cout << "\nPlease Enter Name: ";
    getline(cin, newName); //allows the vendor to enter more than one word

    // ask the vendor to add product's price
    do{
        cout << "Please Enter Price: ";
        cin >> newPrice;

        // error message for negative price
        if (newPrice <=0){
            cout << "Wrong Input...\n";
        }
    }
    while(newPrice <=0);

    // ask the vendor to add product's quantity
    do{
        cout << "Please Enter Count: ";
        cin >> newCount;

        // error message for negative number of the product
        if (newCount <=0){
            cout << "Wrong Input...\n";
        }
    }
    while(newCount <=0);

    //ask the vendor to enter the outlet name for the product
    cout << "Please Enter Outlet Name: ";
    cin >> newOutlet;

    //ask the vendor to enter expiration date in dd/mm/yyyy format
    cout << "\nPlease Enter Expiry Date (day)/month/year : ";
    cin >> day;
    cout << "\nPlease Enter Expiry Date day/(month)/year : ";
    cin >> month;
    cout << "\nPlease Enter Expiry Date day/month/(year) : ";
    cin >> year;

    cout << "\nProduct Added Successfully! \n \n \n";

    // setting information of the new product
    setName(newName);
    setPrice(newPrice);
    setCount(newCount);
    setOutlet(newOutlet);
    setExpiry(day,month,year);
}
//Updating count after making a successful purchase
void Product::oneItemTaken(){
    count -= 1;
}




/************************************************************************************/
/************************************************************************************/
/**************           Class VendingStorage         ******************************/
/************************************************************************************/
/************************************************************************************/
/**
 This class defines the vending machine type and it's attributes
Attributes:
    1-items (Vector of Product type to store all the products)
    2-key (Password used for entering programming mode)
    3-finishFlag (Flag to exit from the machine menu)
Methods:
    1-Operation Mode
    2-Programming Mode
    3-Display Menu
    4-Add Product
    5-Money Change return
    6-Dispense Product
**/
///Constructor
VendingStorage::VendingStorage(){
    key = 123; //password for programming mdoe
    finishFlag =false; //flag to exit from menu
}
void VendingStorage::programmingMode(){
    /**
    Programming Mode, Options available to choose from:
    *1 Restock
    *2 add new item
    *3 Go back
    *4 Exit Machine
    **/
    bool breakLoop = false; //flag to break from while loop
    int choice;
    while(!breakLoop){
        cout << "What do you want to do? \n";
        cout << "1.Restock \n2.Add new item \n3.Go back \n4.Exit machine\n";
        cout << "Please Enter your choice: ";
        cin >> choice;

        switch (choice){
        case 1: //Restock item
            {displayItemsList();  //display all the items for the vendor to choose
            int itemNum, itemsAdded;
            cout << "Please enter number of the product you would like to restock: ";
            cin >> itemNum;

            cout << "Please enter amount of items you will add: ";
            cin >> itemsAdded;  //number of items to be added

            items[itemNum -1].restockProduct(itemsAdded);}
            break;

        case 2: //Add new item
            {Product newItem;
            newItem.addItem(); // make the vendor enter all product's information
            addProduct(newItem);}
            break;

        case 3: //Go to operation mode
            cout <<"\n";
            breakLoop = true;
            break; // break the loop to go back
        case 4: //Exits machine
            finishFlag = true;
            breakLoop = true;
            break;
        default:
            cout << "Wrong input...\n"; // error message if the user didn't choose from 1, 2 or 3
            break;
        }
    }
}

bool VendingStorage::getFinishFlag(){
    return finishFlag;
}

/**
Displays Items list in Programming Mode
it displays:
    Name, Prices, Count, Outlet Name
**/
void VendingStorage::displayItemsList(){
    cout << "\n \n##########\nItems list \n__________\n";
    //Loop through items list to display the menu
    for(int i =0; i < (int)items.size() ; i++){
        cout << i+1 <<"-"<< items[i].getName() << "   Price = " << items[i].getPrice()
        << "$    Count = " << items[i].getCount() << "   Outlet: " << items[i].getOutlet() ;
        if (items[i].getCount() == 0){
            cout << " (Sold out)";  // informs the vendor that this item is sold out
        }
        cout << "\n";
    }
}

///Used for manual adding of items before initializing the code
void VendingStorage::addProduct(Product item){
    items.push_back(item);
}

/**
Operating Mode: Displays menu of available items
and an option to enter programming mode by typing '0' and
typing the right password
**/
void VendingStorage::operationMode(){
    displayMenu();  //for displaying items' names and prices
    int num;
    num = SelectItemNumber(); //Selected item from the menu

    // 0 for entering programming mode
    if(num == 0){
        int password;
        cout << "Enter Password: ";
        //ask for password to check if this person is the vendor or not
        cin >> password;
        if(password == key){
            cout <<"\n\n";
            programmingMode();
        }
        else{
            cout << "Wrong Password...\n";
        }
    }

    // for any number greater than 0 and less than or equal items number
    else if(num <= (int)items.size() && num >0){

        moneyGrabber(num);  // ask the user to enter the money
        dispenseItem(num);  // dispense the item after the user entered the money
        items[num -1].oneItemTaken();  // minus 1 from the count of this item
    }
}


///Displaying menu for the user to choose what he wants
void VendingStorage::displayMenu(){

    cout << "#####\nMenu: \n-----\n" ;
    //Loops through the items list to display menu for the user
    for(int i =0; i < (int)items.size() ; i++){
        cout << i+1 <<"-"<< items[i].getName() << "   Price = " << items[i].getPrice()
        << "$"    ;
        if (items[i].getCount() == 0){
            cout << " (Sold out)";  // informs the user that this item is sold out
        }
        cout << "\n";
    }
    cout << "\n0-Programming Mode\n\n";
}
///Returns number of products in the vending machine
int VendingStorage::numberOfProducts(){
    return items.size();
}

///This function allows the user to select the required item from the menu
int VendingStorage::SelectItemNumber(){
    int outletNumber;
    //loops forever until a valid number is choosen
    do{
    cout << "Please Enter Your Choice: ";
    cin >> outletNumber;

    if(outletNumber == 0){
        return 0;  // then the user will be asked for password of programming mode
        }
    if((outletNumber >numberOfProducts() ) || (outletNumber <0)){
        cout << "Wrong input...\n";  //error message for the user to enter the correct number
        }
    else if (items[outletNumber-1].getCount()==0){
        cout << "Out of stock...\n";  //informs the user that this item is sold out
        }
    else if(items[outletNumber-1].isExpired()){
        cout << "Expired Product...\n"; //Informs the user that the product is expired
        }
    }
    while(items[outletNumber-1].getCount() == 0 || (outletNumber >numberOfProducts() )
          || (outletNumber <0) || items[outletNumber-1].isExpired());

    return outletNumber;  //the user selected the required item
}


///This function is to allow the user to deposit the money
void VendingStorage::moneyGrabber(int outletNumber){
    bool moneySuccessFlag = false;
    float money;
    float moneyStored = 0.0;  //to initialize the value of deposited money

    //Loops forever until the right number of money is deposited
    while(moneySuccessFlag != true){
        cout << "Please enter your money: ";
        cin >> money;  //simulates the process of taking the money from the user

        //The user did not enter a valid value of money
        if(cin.fail() || money <0){
            cout << "Wrong Input...\n";
            break;
        }
        moneyStored += money;  //Updates the value according to the deposited money

        //The amount of money deposited is sufficient to buy the product
        if (moneyStored >= items[outletNumber-1].getPrice()){
            returnChange(moneyStored, outletNumber); //returns the change if there is any
            moneySuccessFlag = true;
        }
        else if (moneyStored < items[outletNumber-1].getPrice()){
            //in case user enters money less than the price
            cout << "Please Enter " << (items[outletNumber-1].getPrice()-moneyStored) << "$ \n";
        }
    }
}

/// This funtion simulates returning the change
void VendingStorage::returnChange(float money, int outletNumber){

    float change = money - items[outletNumber-1].getPrice();
    cout << "\nYour change is: " << change << "$ \n";
}

/**
This function simulates dispensing the product
also asks the user whether to buy another item or he is done
**/
void VendingStorage::dispenseItem(int outletNumber){

    cout << "Your item is [" << items[outletNumber-1].getName() << "]\n" ;
    cout << "Outlet Name: " << items[outletNumber-1].getOutlet() << " \n \n";
    string flag;
    cout << "Press any key to close or Press 'y' to buy something else: ";
    cin >> flag;
    //If the user types 'y' then he wants to buy another product, else the code exits
    if(flag == "y"){
        finishFlag = false;
    }
    else{
        finishFlag = true;
    }
}



