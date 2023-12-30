#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;


/*this class is for all product information
*set information
*get information
*add items
*restock products
*/

class Product{
private:
    string name;
    float price;
    int count;
    //int expirationDate{3};
    string outlet;
public:

    //Constructor 1
    Product(){
        name = "EMPTY";
        price = 0;
        count = 0;
        //expirationDate = (0,0,0)
        outlet = "None";
    }

    //Constructor 2
    Product(string inputName,float inputPrice,int inputCount, string inputOutlet){
        name = inputName;
        price = inputPrice;
        count = inputCount;
        //expirationDate = inputExpirationDate;
        outlet = inputOutlet;
    }

    //GETTERS
    string const getName() {
        return name;
    }

    float const getPrice(){
        return price;
    }

    int const getCount() {
        return count;
    }

    string const getOutlet(){
        return outlet;
    }

    //SETTERS
    void setName(string n){
        name = n;
    }

    void setPrice(float n){
        price = n;
    }

    void setCount(int n){
        count = n;
    }

    void setOutlet(string n){
        outlet = n;
    }

    //Restock
    void restockProduct(int itemsAdded){

        //  ask for quantity to add
        //  adds quantity to count
        count += itemsAdded;
        cout << "\nThere are now " << count << " products of [" << name << "]. \n \n";
    }


    /**
    * @brief this function is to used to add new item
    * @param newName the new product's name
    * @param newOutlet the Outlet name for the new product
    * @param newCount the number of items of this product
    * @param newPrice the price of this product
    */

    void addItem(){
        string newName,newOutlet;
        int newCount;
        float newPrice;
        Product a;
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

        cout << "Product Added Successfully! \n \n \n";

        // setting information of the new product
        setName(newName);
        setPrice(newPrice);
        setCount(newCount);
        setOutlet(newOutlet);
    }

    //Updating count after making a successful purchase
    void oneItemTaken(){
        count -= 1;
    }
};


/*
* this class contains vector of class "product" named "items"
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
    void programmingMode(){
        int choice;

        /*ask the vendor wether to add new item or restock
        *1 Restock
        *2 add new item
        *3 Go back
        */

        while(true){
            cout << "What do you want to do? \n";
            cout << "1.Restock \n2.Add new item \n3.Go back \n";
            cout << "Please Enter your choice: ";
            cin >> choice;

            if(choice == 1){
                displayItemsList();  //display all the items for the vendor to choose
                int itemNum, itemsAdded;
                cout << "Please enter number of the product you would like to restock: ";
                cin >> itemNum;

                cout << "Please enter amount of items you will add: ";
                cin >> itemsAdded;  //number of items to be added

                items[itemNum -1].restockProduct(itemsAdded);
            }
            else if(choice == 2){
                Product newItem;
                newItem.addItem(); // make the vendor enter all product's information
                addProduct(newItem);
            }

            else if (choice == 3){
                    cout <<"\n";
                    break;} // break the loop to go back
            else{
                cout << "Wrong input...\n"; // error message if the user didn't choose from 1, 2 or 3
            }
        }
    }

    bool getFinishFlag(){
        return finishFlag;
    }

    /*this function is for displaying items to the vendor
    *names 
    *prices
    *count
    *outlet name
    */ 
    void displayItemsList(){
        cout << "\n \n##########\nItems list \n__________\n";
        for(int i =0; i < items.size() ; i++){

            cout << i+1 <<"-"<< items[i].getName() << "   Price = " << items[i].getPrice()
            << "$    Count = " << items[i].getCount() << "   Outlet: " << items[i].getOutlet() ;
            if (items[i].getCount() == 0){
                cout << " (Sold out)";  // informs the vendor that this item is sold out
            }
            cout << "\n";
        }
    }

    //Used for manual adding of items before initializing the code
    void addProduct(Product item){
        items.push_back(item);
    }

    //Operating Mode
    void operationMode(){
        displayMenu();  //for displaying items' names and prices
        int num;

        num = SelectItemNumber();

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
        else if(num <= items.size() && num >0){
        moneyGrabber(num);  // ask the user to enter the money
        dispenseItem(num);  // dispense the item after the user entered the money 

        items[num -1].oneItemTaken();  // minus 1 from the count of this item

        //product = itemSelector(itemNumber);
        //moneyGrabber(product);
        //addItems();
        }
    }
    

    //displaying menu for the user to choose what he wants
    void displayMenu(){
        //system("cls"); used to clear terminal
        cout << "#####\nMenu: \n-----\n" ;

        for(int i =0; i < items.size() ; i++){

            cout << i+1 <<"-"<< items[i].getName() << "   Price = " << items[i].getPrice()
            << "$"    ;
            if (items[i].getCount() == 0){
                cout << " (Sold out)";  // informs the user that this item is sold out
            }
            cout << "\n";
        }
        cout << "\n0-Programming Mode\n\n";
    }

    int numberOfProducts(){
        return items.size();
    }


    // this function allows the user to select the required item
    int SelectItemNumber(){
        int outletNumber;
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
        }
        while(items[outletNumber-1].getCount() == 0 || (outletNumber >numberOfProducts() ) || (outletNumber <0));

        return outletNumber;  //the user selected the required item
    }


    //this function is to allow the user to deposit the money
    void moneyGrabber(int outletNumber){
        bool moneySuccessFlag = false;
        float money;
        float moneyStored = 0.0;  //to initialize the value of deposited money

        while(moneySuccessFlag != true){
            cout << "Please enter your money: ";
            cin >> money;  //simulates the process of taking the money from the user

            if(cin.fail() || money <0){
                cout << "Wrong Input...\n";
                break;
            }
            moneyStored += money;  //to update the value according to the deposited money

            if (moneyStored >= items[outletNumber-1].getPrice()){

                returnChange(moneyStored, outletNumber);
                moneySuccessFlag = true;
            }
            
            else if (moneyStored < items[outletNumber-1].getPrice()){
                //in case user enters money less than the price
                cout << "Please Enter " << (items[outletNumber-1].getPrice()-moneyStored) << "$ \n";
                //cout << "Please enter the right number of money\n";
            }
        }
    }

    // this funtion simulates returning the change
    void returnChange(float money, int outletNumber){//, float item[outletNumber].price){

        float change = money - items[outletNumber-1].getPrice();
        cout << "\nYour change is: " << change << "$ \n";
    }

    /* this function simulates dispensing the product
    * also asks the user whether to buy another item or he is done
    */
    void dispenseItem(int outletNumber){

        cout << "Your item is [" << items[outletNumber-1].getName() << "]\n" ;
        cout << "Outlet Name: " << items[outletNumber-1].getOutlet() << " \n \n";
        string flag;
        cout << "Press any key to close or Press 'y' to buy something else: ";
        cin >> flag; 
        if(flag == "y"){
            finishFlag = false;
        }
        else{
            finishFlag = true;
        }
    }

};





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

