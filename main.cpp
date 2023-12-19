#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;
int itemSelector();
void moneyGrabber();
void returnChange(float money);
int SelectItemNumber();
void operationMode();

class Product{
    private:
    string name;
    float price;
    int count;
    //int expirationDate{3};
    string outlet;
public:

    //GETTERS

    string const getName() {
        return name;
        }

    float const getPrice(){
        return price;
    }

    int const getCount() {
        return count;}

    string const getOutlet(){
         return outlet;}

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
    //PROGRAMMING MODE

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

    //Restock
    void restockProduct(int itemsAdded){

        //  ask for quantity to add
        //  adds quantity to count
        count += itemsAdded;
        cout << "There are now " << count << " products.";
    }

    void addItem(){
        string newName,newOutlet;
        int newCount;
        float newPrice;
        Product a;

        //cin.clear();
        //cin.sync();

        cin.ignore(); //clears input buffer to make getline work properly
        cout << "Please Enter Name: ";
        getline(cin, newName);

        //
        do{
            cout << "\nPlease Enter Price: ";
            cin >> newPrice;
            if (newPrice <=0){
                cout << "Wrong Input...\n";
            }
        }
        while(newPrice <=0);

        do{
            cout << "Please Enter Count: ";
            cin >> newCount;
            if (newCount <=0){
                cout << "Wrong Input...\n";
            }
        }
        while(newCount <=0);

        cout << "\nPlease Enter Outlet Name: ";
        cin >> newOutlet;

        cout << "Product Added Successfully! \n \n \n";
        setName(newName);
        setPrice(newPrice);
        setCount(newCount);
        setOutlet(newOutlet);

    }
    //OPERATING MODE
    void oneItemTaken(){
        count -= 1;
    }






};

class VendingStorage{
private:
    vector<Product> items;
    int key = 123;
    bool finishFlag = false;
public:



    void programmingMode(){

        int choice;

        while(true){


            cout << "What do you want to do? \n";
            cout << "1.Restock \n2.Add new item \n3.Go back \n";
            cout << "Please Enter your choice: ";
            cin >> choice;

            if(choice == 1){
                displayItemsList();
                int itemNum, itemsAdded;
                cout << "Please enter which product you would like to restock: ";
                cin >> itemNum;

                cout << "Please enter amount of items you will add: ";
                cin >> itemsAdded;
                items[itemNum -1].restockProduct(itemsAdded);

            }
            else if(choice == 2){
                Product newItem;
                newItem.addItem();
                addProduct(newItem);
            }

            else if (choice == 3){
                    break;}
            else{
                cout << "Wrong input...\n";
            }
        }

    }


    bool finish(){

        return finishFlag;
    }

    void displayItemsList(){
        cout << "Items list \n";
        for(int i =0; i < items.size() ; i++){

            cout << i+1 <<"-"<< items[i].getName() << "   Price = " << items[i].getPrice()
            << "$    Count = " << items[i].getCount() << "   Outlet: " << items[i].getOutlet() ;
            if (items[i].getCount() == 0){
                cout << " (Sold out)";
            }
            cout << "\n";
        }
    }

    void displayMenu(){
        //system("cls");
        cout << "Menu: \n" ;
        for(int i =0; i < items.size() ; i++){

            cout << i+1 <<"-"<< items[i].getName() << "   Price = " << items[i].getPrice()
            << "$"    ;
            if (items[i].getCount() == 0){
                cout << " (Sold out)";
            }
            cout << "\n";
        }
    }


    void operationMode(){
        displayMenu();
        int num;
        Product product;
        num = SelectItemNumber();
        if(num == 0){
            int password;
            cout << "Enter Password: ";

            cin >> password;
            if(password == key){
                programmingMode();
            }
            else{
                cout << "Wrong Password...\n";
            }
        }

        moneyGrabber(num);
        dispenseItem(num);

        items[num -1].oneItemTaken();

        //product = itemSelector(itemNumber);
        //moneyGrabber(product);
        //addItems();
    }

    void addProduct(Product item){
        items.push_back(item);
    }

    int numberOfProducts(){

        return items.size();
    }

    int SelectItemNumber(){
        int outletNumber;
        do{
        cout << "please enter number of outlet: ";
        cin >> outletNumber;

        if(outletNumber == 0){
            return 0;
        }

        if((outletNumber >numberOfProducts() ) || (outletNumber <0)){
            cout << "Wrong input...\n";
        }
        else if (items[outletNumber-1].getCount()==0){
            cout << "Out of stock...\n";
            }


        }
        while(items[outletNumber-1].getCount() == 0 || (outletNumber >numberOfProducts() ) || (outletNumber <0));

        return outletNumber;
    }


    void moneyGrabber(int outletNumber){
        bool moneySuccessFlag = false;
        float money;

        while(moneySuccessFlag != true){


            cout << "Please enter your money: ";
            cin >> money;
            if(cin.fail()){
                cout << "Wrong Input...\n";
                break;

            }
            if (money >= items[outletNumber-1].getPrice()){//item[outletNumber].price){

                returnChange(money, outletNumber);

                moneySuccessFlag = true;

            }
            else if ((money < items[outletNumber-1].getPrice() && (money > 0))){
                cout << "Please enter the right number of money\n";

            }

        }

}


    void returnChange(float money, int outletNumber){//, float item[outletNumber].price){

        float change = money - items[outletNumber-1].getPrice();//item[outletNumber].price;

        cout << "your change is: " << change << "$ \n";

    }

    void dispenseItem(int outletNumber){

        cout << "Your item is [" << items[outletNumber-1].getName() << "]\n" ;
        cout << "Outlet Name: " << items[outletNumber-1].getOutlet() << " \n \n";

    }

    int itemSelector(){

        int itemNumber;

        do{
            cout << "Please enter your choice: ";
            cin >> itemNumber;
            if (itemNumber <=0){
                cout << "Wrong Input...\n";
            }
        }
        while(itemNumber <=0);

        return itemNumber;
    }



};





int main()
{
    //int item = itemSelector();
    //cout <<"Number of item is: " << item;

    //cout << "Hello world!" << endl;
    //operationMode();
/*
    vector<Product> items;

    //item1 = addItem();

    //item2 = items[0];


    //items.push_back(addItem());

    cout <<"Number of Items: " <<items.size() << "\n";


    */
    VendingStorage machine;

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
        if(machine.finish()){
            break;
        }
    }

    return 0;

}



#define NUM_OF_ITEMS 24

/*
int main()
{
    Product items[NUM_OF_ITEMS]; //define array of products (items on the menu)
    //initialize some pre-programmed items
    string spiro = "Spiro Spathis";
    string sod = "Soda";
    for (int i = 0; i < NUM_OF_ITEMS; i++) items[i] = Product(); //initializes all items as empty
    addItems(items,spiro,9.5,100,sod); //add 1st item which is spiro spathis
    cout << "Choose the item from the menu: \n";
    for (int i = 0; i < NUM_OF_ITEMS; i++){ //printing the menu
    cout << i+1 << ". " << items[i].getName() << " (Price: " << items[i].getPrice()<< "$). \n";


    }

    return 0;
}*/




