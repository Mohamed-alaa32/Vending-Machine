#include <iostream>
#include <vector>

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
    int expirationDate{3};
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
    cout << "please enter name:" ;
    cin >> n;

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
    Product(){
    name = "EMPTY";
    price = 0;
    count = 0;
    //expirationDate = (0,0,0)
    outlet = "None";
    }
    Product(string inputName,float inputPrice,int inputCount, string inputOutlet){
    name = inputName;
    price = inputPrice;
    count = inputCount;
    //expirationDate = inputExpirationDate;
    outlet = inputOutlet;
    }



    //OPERATING MODE







};
void addItem(Product a[],string newName,float newPrice,int newCount,string newOutlet){
        //Product item;
        //item.setName();
        cout << "please enter name:" ;
        cin >> newName;

        cout << "Please enter price: ";
        cin >> newPrice;



        a[i].setName(newName);
        a[i].setPrice(newPrice);
        a[i].setCount(newCount);
        a[i].setOutlet(newOutlet);

    }
    break;
}
}



int main()
{
    //int item = itemSelector();
    //cout <<"Number of item is: " << item;

    //cout << "Hello world!" << endl;
    //operationMode();

    Product item1;

    item1.setName;

    return 0;
}

void operationMode(){

    cout << "Menu:\n";
    cout << "1.Soda (Price:4.0$) \n2.Water (Price:2.5$) \n3.Juice (Price:3.0$) \n";
    //itemNumber = SelectItemNumber();
    //product = itemSelector(itemNumber);
    //moneyGrabber(product);

    cout << i << "- " << product.name << product.price;

    //output example: Product Name: Pepsi     Outlet Name: Soda
    // your change is 0.00$
    addItems()
}

int SelectItemNumber(){
    int outletNumber;
    cout << "please enter number of outlet: ";
    cin >> outletNumber;


    return outletNumber;
}


void moneyGrabber(Product item){
    bool moneySuccessFlag = false;
    float money;

    while(moneySuccessFlag != true){


        cout << "Please enter your money: ";
        cin >> money;
        if(cin.fail()){
            cout << "Wrong Input...\n";
            break;

        }
        if (money >= item.price){//item[outletNumber].price){

            returnChange(money, items[]);

            moneySuccessFlag = true;

        }
        else if ((money < item.price && (money > 0))){
            cout << "Please enter the right number of money\n";

        }

    }

}


void returnChange(float money, Product item){//, float item[outletNumber].price){

    float change = money - item.price;//item[outletNumber].price;

    cout << "your change is: " << change;

}
/*
void dispenseItem(int itemNumber){

    cout << "Your item [" << item[itemNumber].name << "] is here..." ;

}
*/
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
    if (product.count == 0){
        cout << "(Sold Out)";
    }


    }

    return 0;
}

*/
