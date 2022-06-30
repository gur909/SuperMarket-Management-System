#include <iostream>
#include<fstream>
using namespace std;
class shopping
{
private:
    int product_code;
    float price;
    float discount;
    string product_name;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;
    cout<<"\t______________________________________________________\n";
    cout<<"\t______________________________________________________\n";
    cout<<"\t_________________SUPERMARKET MAIN MENU________________\n";
    cout<<"\t______________________________________________________\n";
    cout<<"\t______________________________________________________\n";
    cout<<"\nPlease select!\n";
    cout<<"\t|     1) Administrator    |\n";
    cout<<"\t|     2) Buyer            |\n";
    cout<<"\t|     3) Exit             |\n";
    cin>>choice;

    switch(choice){
        case 1:
        {
            cout<<"\t Please Login \n";
            cout<<"\t Enter Email  \n";
            cin>>email;
            cout<<"\t Password      \n";
            cin>>password;

            if(email=="preetgur@gmail.com"&& password=="gurpreet@123"){
                administrator();
            }
            else{
                cout<<"Invalid email/password\n";
            }
            break;
        }
        case 2:
        {
            buyer();
        }
        case 3:
        {
            exit(0);
        }
        default:
        {
            cout<<"Please select from the given option";
        }
    }
    goto m;
}

void shopping::administrator() {
    m:
    int choice;
    cout<<"\n\t Administrator menu";
    cout<<"\n\t|_______1) Add the Product_______|";
    cout<<"\n\t|_______2) Modify the Product____|";
    cout<<"\n\t|_______3)Delete the Product_____|";
    cout<<"\n\t|_______4)Back to main menu______|";
    cout<<"\n\t Please enter your choice ";
    cin>>choice;

    switch(choice){
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        }
        case 3:
        {
            rem();
            break;
        }
        case 4:
        {
            menu();
            break;
        }
        default:
        {
            cout<<"Invalid choice!";
        }
    }
    goto m;
}

void shopping::buyer() {
    m:
    int choice;
    cout<<"\tBuyer \n";
    cout<<"\t_______________\n";
    cout<<"\t1) Buy Product \n";
    cout<<"\t2) Go Back     \n";
    cout<<"\t Enter your choice : ";

    cin>>choice;
    switch(choice){
        case 1:
        {
            receipt();
            break;
        }
        case 2:
        {
            menu();
            break;
        }
        default:
        {
            cout<<"Invalid choice!";
        }
    }
goto m;
}

void shopping::add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\t Add New Product";
    cout<<"\n\t Product code of the product ";
    cin>>product_code;
    cout<<"\n\t Name of the product ";
    cin>>product_name;
    cout<<"\n\t Price of the product ";
    cin>>price;
    cout<<"\n\t Discount on product ";
    cin>>discount;

    data.open("database.txt,ios::in");//ios::in open file in reading mode and ios::out in writing mode

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c==product_code){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token==1)
        goto m;
    else
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    cout<<"\n\tRecord inserted !";
}

void shopping::edit() {
    fstream data,data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t Modify the record ";
    cout<<"\n\t product code      ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n File doesn't exist! ";
    }
    else{
        data1.open("databse1.txt",ios::app|ios::out);
        data>>product_code>>product_name>>price>>discount;
        while(!data.eof()){
            if(pkey==product_code){
                cout<<"\n\t Product new code : ";
                cin>>c;
                cout<<"\n\t Name of the Product : ";
                cin>>n;
                cout<<"\n\t price : ";
                cin>>p;
                cout<<"\n\t Discount : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t Record edited ";
                token++;
            }
            else
            {
                data1<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<"\n";
            }
            data>>product_code>>product_name>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n Record not found! ";
        }
    }
}

void shopping::rem(){
    fstream data,data1;
    int pkey;
    int token = 0;
    cout<<"\n\t delete product ";
    cout<<"\n\t Product code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"file doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>product_code>>product_name>>price>>discount;
        while(!data.eof()){
            if(product_code==pkey){
                cout<<"\n\t product delete successfully";
                token++;
            }
            else{
                data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<"\n";
            }
            data>>product_code>>product_name>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\nrecord not found ";
        }
    }
}
void shopping::list() {
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n|_______________________________________\n";
    cout<<"proNo\tName\tPrice\n";
    cout<<"\n|_______________________________________\n";
    data>>product_code>>product_name>>price>>discount;
    while(!data.eof()){
        cout<<product_code<<"\t\t"<<product_name<<"\t\t"<<price<<"\n";
        data>>product_code>>product_name>>price>>discount;
    }
    data.close();
}
void shopping::receipt(){
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount;
    int disc = 0;
    float total = 0;

    cout<<"\n\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n EMPTY databse";
    }
    else{
        data.close();

        list();
        cout<<"\n__________________________________________\n";
        cout<<"\n|                                         \n";
        cout<<"\n          Please place order              \n";
        cout<<"\n|                                         \n";
        cout<<"\n__________________________________________\n";
        do{
            m:
            cout<<"\n\n Enter Product code : ";
            cin>>arrc[c];
            cout<<"\n\n Enter the product quantity: ";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate product. please try again! ";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product?if yes then press y else no";
            cin>>choice;
        }
        while(choice=='y');

        cout<<"\n\t_________________________________\n";
        cout<<"\nproduct no\t product Name \t product quantity\tprice\t amount\t amount with discount\n";

        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>product_code>>product_name>>price>>discount;
            while(!data.eof()){
                if(product_code==arrc[i]){
                    amount = price*arrq[i];
                    discount = amount-(amount*discount/100);
                    total = total+discount;
                    cout<<"\n"<<product_code<<product_name<<arrq[i]<<price<<"\t"<<amount<<"\t\t"<<discount;
                }
                data>>product_code>>product_name>>price>>discount;
            }
        }
        data.close();
    }
    cout<<"\n_______________________________________";
    cout<<"\n Total Amount : "<<total;
}
int main(){
    shopping s;
    s.menu();
}