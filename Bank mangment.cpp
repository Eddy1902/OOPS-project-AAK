
#include <iostream>
#include<string>
#include<conio.h>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <random>
#include <time.h>
#include <stdlib.h>
#include<direct.h>
#include<bits/stdc++.h>
#include <string.h>
#include<map>
#include<vector>
using namespace std;

//***
//                  CLASS USED IN PROJECT
//****

//ADMIN PASSWORD IS 1234


class account
{
    char acno[20];
    char name[50];
    int deposit;
    char address[200];
    char type;
    char gender[20];
    long long int contactnumber, adharno;
    int dd=0, mm=0, yy=0;
    char password[20];
    vector<int> v;
    public:

    account() { strcpy(password, "-"); };
    void create_account();                 //function to get data from user
      void setvec();                      //function to add adress to vector.
    void show_account() ;             //function to show data on screen
    void modify();                         //function to add new data
    void show_account_transaction() ; //fucntion to show details at transaction.
    void dep(int);                         //function to accept amount and add to balance amount
    void draw(int);                        //function to accept amount and subtract from balance amount
    void report() ;                   //function to show data in tabular format
    char *retacno();                       //function to return account number
    char *retpass();                       //function to return password of the account
    int retdeposit() ;                //function to return balance amount

    char rettype() ;
                                    //function to return type of account
     void show_account12();
}; //class ends here

void account::create_account()
{
    bool tell=false;
     char st[20]="hello";
    cout << "\n\nEnter The Name of The account Holder : ";
    cin.ignore();
    cin.getline(name, 50);
cout<<"\n";
    cout << "Enter adhar card number :" << endl;
    cin >> adharno;
    cout << "\nEnter your contact number :" << endl;
    cin >> contactnumber;
    cin.ignore();
    cout<<"Enter your address : ";
    gets(address);
    cout << "\nEnter your date of birth " << endl;
    cout<<"Enter date :";
    cin>>dd;
    cout<<"\nEnter Month :";
    cin>>mm;
    cout<<"\nEnter year:";
    cin>>yy;

    cout << "\nEnter your gender " << endl;
    cin >> gender;

    cout << "\nEnter Type of The account (C/S) : ";
    cin >> type;
    type = toupper(type);

    cout << "\n\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
    cin >> deposit;

    cout << "\n\nEnter a password for your account"
         << "\nNote: not be more than 16 characters and less than 8 characters " << endl;
         while(tell==false){
         cin >> st;
         if(strlen(st)<17&&strlen(st)>=8)
         {
         strcpy(password,st);
         tell=true;
         }
         else if(strlen(st)>16||strlen(st)<8)
            cout<<"\n Enter a valid password "<<endl;

account ac;


    ifstream inFile;
        if(!inFile){
        cout<<"\n";
    }

    inFile.open("hello.dat", ios::binary);
          while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (strcmp(ac.retpass(),st) == 0)
        {
         cout<<"\n This password already exist,Please choose a different combination"<<endl;
         tell=false;
        }
    }

         }

    srand(time(0));

    char ac[12];
    ac[0] = 'C';
    ac[1] = 'T';
    ac[2] = 'N';
    ac[3] = 'L';
    ac[11] = '\0';

    for (int i = 4; i < 11; i++)
    {
        if (i == 7)
        {
            ac[i] = (char)(rand() % 27 + 65);
            continue;
        }
        ac[i] = (char)(rand() % 10 + 48);
    }

    strcpy(account::acno, ac);

    cout << "\n\n\nAccount Created..";
    cout << "\nYour account no. is : ";
    cout << acno;
};


void account::setvec()
{
    v.push_back(dd);
    v.push_back(mm);
    v.push_back(yy);
}

void account::show_account_transaction()
{
    cout << "\nAccount No. : " << acno;
    cout << "\nAccount Holder Name : ";
    cout << name;
    cout << "\nType of Account : " << type;
    cout << "\nBalance amount : " << deposit;
}
void account::show_account()
{
    setvec();
    cout << "\nAccount No. : " << acno;
    cout << "\nAccount Holder Name : " << name;
    cout << "\nContact number : " << contactnumber;
    cout<<"\nAddress is : "<<address;
    cout << "\nAdhar card number is : " << adharno;
    cout << "\nType of Account : " << type;
    cout << "\nBalance amount : " << deposit<<endl;
    cout<<"Date of birth : ";
    cout<<v[0]<<"/"<<v[1]<<"/"<<v[2];
 }

 void account::show_account12()
{

    cout << "\nAccount No. : " << acno;
    cout << "\nAccount Holder Name : " << name;
    cout << "\nContact number : " << contactnumber;
    cout << "\nAdhar card number is : " << adharno;
    cout << "\nType of Account : " << type;
    cout << "\nBalance amount : " << deposit<<endl;
    cout<<"Date of birth : "<<dd<<"/"<<mm<<"/"<<yy<<endl;

 }


void account::modify()
{
    cout << "\nAccount No. : " << acno;
    cout << "\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
     cout << "\n Modify your adhar card number : ";
    cin >> adharno;
    cout << "\nModify contact numer : ";
    cin >> contactnumber;
    cout << "\nchange your date of birth : ";
    cout<<"\n date : ";
    cin>>dd;
    cout<<"\n month : ";
    cin>>mm;
    cout<<"\n year : ";
    cin>>yy;
      cout << "\nChange your gender : ";
    cin >> gender;
    cout << "\nModify Type of Account : ";
    cin >> type;
    type = toupper(type);

}

void account::dep(int x)
{
    deposit += x;
}

void account::draw(int x)
{
    deposit -= x;
}
char *account ::retpass()
{

    return (password);
}
void account::report()
{
    cout << left << setw(15) << acno << setfill(' ') << left << setw(20) << name << setfill(' ') << left << setw(5) << type << setfill(' ') << left << setw(10) << deposit << endl;
}

char *account::retacno()
{
    return acno;
}
int account::retdeposit()
{
    return deposit;
}

char account::rettype()
{
    return type;
}

class loan : public account
{
    char account_num[20];
    long long int salary;
    long long int loan_amount;
    char loan_am[40];
    long long int est_coll;
    char passwrd[20];
    char loan_status[15]="pending";

public:
    /*
    loan()
    {
        strcpy(loan_status, "pending");
    }
    */
    void get_loan_info()
    {
        cout<<"\n\n";
        cout << "Enter your bank account number : " ;
        cin >> account_num;
        cout << "\n\nEnter the password of your bank accout : ";
        cin >> passwrd;
        cout<<"\n\nEnter your loan amount in figures : ";
        cin>>loan_amount;
       // cout<<"Enter the loan amount in words "<<endl;
       // cin.getline(loan_am,40);
        cout << "\n\nenter your gross salary : ";
        cin >> salary;
        cout << "\n\nEnter estimated price of collateral : ";
        cin >> est_coll;
        cout << "\n\nYour loan request has been successfully forwarded to the branch. " << endl;

            }
    void display_user_details()
    {
        cout<<"\n";
        cout << "User account number is " << account_num << endl;
        cout<<"Requested loan amount is "<<loan_amount<<endl;
 //       cout<<"                         "<<loan_am;
        cout << "Gross salary is " << salary << endl;
        cout << "Estimate price of collateral is " << est_coll << endl;
        cout << "Approval status - " << loan_status << endl;
        cout<<"\n";
    }
    char *getaccno1()
    {
        return (account_num);
    }

    char *retpass1()
    {
        return (passwrd);
    }
    void est()
    {
        cout << "enter est" << endl;
        cin >> est_coll;
    }

    void check_status()
    {   int n;
        cout << "What action you want to take?\n\t 1. Approve\n\t 2. Deny\n\t 3. Keep it pending" << endl;
        cin.ignore();
        cin>>n;
        switch(n){
            case 1 : strcpy(loan_status,"approved");
                     break;
            case 2 : strcpy(loan_status,"denied");
                     break;
            case 3 : break;
            default: cout<<"Invalid operation!!";
        }
    }
    void display_loan_user_status()
    {


        if (strcmp(loan_status, "approved") == 0)
            cout << "\nDear user your loan has been approved .\nKindly visit your nearest branch for further procedures " << endl;
        else if (strcmp(loan_status, "denied") == 0)
            cout << "\nDear user your loan has been denied " << endl;
         else cout<<"\nYour request is still pending" ;
    }
};
set <string> acc_del1;
void setset();
class account_delete:public account
{

public:
    char acc_del_no[20];
    void account_delete_user()
    {
        cout << "        Enter your account number again : ";
        cin >> acc_del_no;
    }
    void account_delete_admin() const
    {
        int count=0;
        setset();
        set<string>::iterator itr;
        for (itr = acc_del1.begin(); itr != acc_del1.end(); itr++)
    {
        cout << "\n\nAccount deletion request of "<<*itr<<" has been received."<<endl;

    }

    }
};

void setset(){
 ifstream inFile;
 string stg;
 inFile.open("hel.dat");
 account_delete ac1;
  while (inFile.read(reinterpret_cast<char *>(&ac1), sizeof(account_delete)))
{
    stg=ac1.acc_del_no;
 acc_del1.insert(stg);

}

 }

//***
//    	function declaration
//****
void write_account();               //function to write record in binary file
void display_sp(char *);            //function to display account details given by user
void modify_account(char *);        //function to modify record of file
void delete_account(char *);        //function to delete record of file
void display_all();                 //function to display all account details
void deposit_withdraw(char *, int); // function to desposit/withdraw amount for given account
void intro();                       //introductory screen function
bool verify_admin();                // function to verify admin
void display_at(char *n);           //function to display all the information by the user
void input_delete_account(char *n);
void display_deletionR();
void adi(); //function to delete contents of hel file.
void get_loan(char *n);
void user_check_loan();
void see_loan();
void approve_deny();

//***
//    	THE MAIN FUNCTION OF PROGRAM
//****

int main()
{

/*
remove("loan.dat");
remove("hello.dat");
remove("hel.dat");
*/


 system("color 0A");
    bool flag = false;
    char ch;
    char num[20];

    do
    {
        system("cls");
        cout<<"\n  WELCOME TO CONTINENTAL BANK"<<endl;
        cout << "\n\n\tMAIN MENU";
        cout << "\n\nCUSTOMER OPTIONS";
        cout << "\n\n\ta. NEW ACCOUNT";
        cout << "\n\n\tb. DEPOSIT AMOUNT";
        cout << "\n\n\tc. WITHDRAW AMOUNT";
        cout << "\n\n\td. BALANCE ENQUIRY";
        cout << "\n\n\te. View accout details";
        cout << "\n\n\tf Delete account request";
        cout << "\n\n\tg Loan request";
        cout << "\n\n\th Loan request status";
        cout << "\n\nADMIN OPTIONS";
        cout << "\n\n\ti. Loan requests from customers";
        cout << "\n\n\tj. ALL ACCOUNT HOLDER LIST";
        cout << "\n\n\tk. View deletion account request";
        cout << "\n\n\tl. CLOSE AN ACCOUNT";
        cout << "\n\n\tm. MODIFY AN ACCOUNT";
        cout << "\n\n\tn. Approve or deny loan request";
        cout << "\n\n\to. EXIT";
        cout << "\n\n\tSelect Your Option (a-o) ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case 'a':

            write_account();
            break;
        case 'b':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            deposit_withdraw(num, 1);
            break;
        case 'c':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            deposit_withdraw(num, 2);
            break;
        case 'd':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            display_sp(num);
            break;
        case 'e':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            display_at(num);
            break;

        case 'f':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            input_delete_account(num);
            break;

        case 'g':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            get_loan(num);
            break;

        case 'h':
            user_check_loan();
            break;
        case 'i':
            flag = verify_admin();
            if (flag)
                see_loan();
            break;

        case 'j':
            flag = verify_admin();
            if (flag)
                display_all();
            break;

        case 'k':
            flag = verify_admin();
            if (flag)
                display_deletionR();
            break;

        case 'l':
            flag = verify_admin();
            if (flag)
            {
                cout << "\n\n\tEnter The account No. : ";
                cin >> num;
                delete_account(num);
            }
            break;
        case 'm':
            flag = verify_admin();
            if (flag)
            {
                cout << "\n\n\tEnter The account No. : ";
                cin >> num;
                modify_account(num);
            }
            break;

        case 'n':
            flag = verify_admin();
            if (flag)
                approve_deny();
            break;
        case 'o':
            cout << "\n\n\tThanks for using bank managemnt system";
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (ch != 'o');
    return 0;
}

//***
//    	function to write in file
//****

void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("hello.dat", ios::binary | ios::app);
    ac.create_account();

    outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
    outFile.close();
}

//***
//    	function to read specific record from file
//****
void display_at(char *n)
{
    char pass[20];

    cout << "        Enter password of the account : ";
    cin >> pass;
    cout << endl;
    account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("hello.dat", ios::binary);
    if (!inFile)
    {
        cout << "\n\n File could not be open !! Press any Key...";
        return;
    }

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (strcmp(ac.retacno(), n) == 0 && strcmp(ac.retpass(), pass) == 0)
        {
         cout << "\nACCOUNT DETAILS\n";
            ac.show_account();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nAccount number does not exist or the password entered is wrong ";
}

void input_delete_account(char *n)
{
    char pass[20];
    cout << "        Enter password of the account : ";
    cin >> pass;
    cout << endl;
    int an;

    ofstream outFile;
    account ac;
    account_delete ac1;
    bool flag = false;
    ifstream inFile;
    inFile.open("hello.dat", ios::binary | ios::app);

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (strcmp(ac.retacno(), n) == 0 && strcmp(ac.retpass(), pass) == 0)
        {
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nAccount number does not exist or the password entered is wrong " << endl;

    else
    {
        outFile.open("hel.dat", ios::binary | ios::app);
        ac1.account_delete_user();

        outFile.write(reinterpret_cast<char *>(&ac1), sizeof(account_delete));
        outFile.close();

        cout << "   \n\n  Your request has been forwarded successfully " << endl;
    }
}



void display_deletionR()
{
    ifstream inFile;
    string status;
    string sat = "deleted";
    inFile.open("hel.dat", ios::binary);
    account_delete ac1;

    int count = 0;

if (!inFile)
    {
        cout << "  \nNo account deletion request have been received from customers"<<endl;
        return;
    }
    ac1.account_delete_admin();
    cout<<endl;


}

void display_sp(char *n)
{

  char p[15];
     cout << "\nEnter passowrd " << endl;
    cin >> p;

    account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("hello.dat", ios::binary);
    if (!inFile)
    {
        cout << "\n\n  File could not be open !! Press any Key...";
        return;
    }

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (strcmp(ac.retacno(), n) == 0&& strcmp(ac.retpass(), p)==0)
        {
            cout << "\nBALANCE DETAILS\n";
            ac.show_account_transaction();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nAccount does not exist or the password entered is wrong";
}

//***
//    	function to modify record of file
//****

void modify_account(char *n)
{
    bool found = false;
    account ac;
    fstream File;
    File.open("hello.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\n\n File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (strcmp(ac.retacno(), n) == 0)
        {
            ac.show_account12();

            cout << "\n\nEnter The New Details of account" << endl;
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}


//***
//    	function to delete record of file
//****

void delete_account(char *n)
{
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("hello.dat", ios::binary);
    if (!inFile)
    {
        cout << "\n\n  File could not be open !! Press any Key...";
        return;
    }
    outFile.open("dry.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (strcmp(ac.retacno(), n) != 0)
        {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("hello.dat");
    rename("dry.dat", "hello.dat");
    cout << "\n\n\tRecord Deleted ..";
}

//***
//    	function to display all accounts deposit list
//****

void display_all()
{
    account ac;
    ifstream inFile;
    inFile.open("hello.dat", ios::binary);
    if (!inFile)
    {
        cout << "\n\n  File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "=================================================== \n";
    cout << "A/c no.         NAME             Type   Balance     \n";
    cout << "====================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
}

//***
//    	function to deposit and withdraw amounts
//****

void deposit_withdraw(char *n, int option)
{
    char p[16];

    int amt;
    bool found = false;
    account ac;
    fstream File;
    cout << "\n        Enter passowrd : ";
    cin >> p;
    cout<<"\n";
    File.open("hello.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\n\n  File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (strcmp(ac.retacno(),n)==0  && strcmp(ac.retpass(), p) == 0)
        {
            ac.show_account_transaction();
            if (option == 1)
            {
                cout << "\n\n\tTO DEPOSIT AMOUNT ";
                cout << "\n\nEnter The amount to be deposited - ";
                cin >> amt;
                ac.dep(amt);
            }
            if (option == 2)
            {
                cout << "\n\n\tTO WITHDRAW AMOUNT ";
                cout << "\n\nEnter The amount to be withdraw - ";
                cin >> amt;
                int bal = ac.retdeposit() - amt;
                if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
                    cout << "Insufficience balance";
                else
                    ac.draw(amt);
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n\n\t Transaction Successful.";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n  Account number and password combination entered is wrong!. ";
}
//Fucntion to input loan details by user.
void get_loan(char *n)
{
    char p[15];
    cout << "\n        Enter passowrd : ";
    cin >> p;
    loan l1;
    int x=0;
    account ac;
    ofstream of;
    of.open("loan.dat", ios::binary | ios::app);
    ifstream inFile;
    inFile.open("hello.dat",ios::binary | ios::app);

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {

        if (strcmp(ac.retacno(),n) == 0 && strcmp(ac.retpass(), p) == 0)
        {
         l1.get_loan_info();
         of.write(reinterpret_cast<char *>(&l1), sizeof(loan));
          ++x;

        }
    }
if(x==0)
    cout<<"\n Entered account number and password combination is wrong\n";

    of.close();

}

//Function to See loan request from customers.
void see_loan()
{
    ifstream in;
    loan l1;
    in.open("loan.dat", ios::binary | ios::in);
    if (!in)
    {
        cout << "\n\n  No requests have been recieved" << endl;
        return;
    }
    while(in.read(reinterpret_cast<char *>(&l1), sizeof(loan)))
    {
        l1.display_user_details();
        cout<<"\n";
    }
    in.close();
}
//Function to approve or deny loan request.
void approve_deny()
{
    loan l1;
    char n[20];
    bool found = false;
    cout << "\n\n   Enter the bank account number : ";
    cin >> n;
    fstream File;

    File.open("loan.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\n\n  File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&l1), sizeof(loan));
        if (strcmp(l1.getaccno1(), n) == 0)
        {
            l1.check_status();
            int pos = (-1) * static_cast<int>(sizeof(loan));
            File.seekp(pos, ios::end);
            File.write(reinterpret_cast<char *>(&l1), sizeof(loan));
            found = true;
        }
    }

    File.close();
    if (found == false)
        cout << "\n\n No such account found ";
}
//function to check status of loan by user.
void user_check_loan()
{
    char x[15], p[15];
    loan l1;
    bool flag = true;
    ifstream inFile;
    cout << "Enter your account number : ";
    cin >> x;
    cout << "\nEnter passowrd : ";
    cin >> p;
    inFile.open("loan.dat", ios::binary);
    if (!inFile)
    {
        cout << "\n\n  File could not be open !! Press any Key...";
        return;
    }

    while (inFile.read(reinterpret_cast<char *>(&l1), sizeof(loan)))
    {
        if (strcmp(l1.getaccno1(), x) == 0 && strcmp(l1.retpass1(), p) == 0)
        {
            l1.display_loan_user_status();
            flag = false;
        }
    }
    inFile.close();
    if (flag == true)
        cout << "\n\nEnter correct Account no. and password combination. " << endl;
}

bool verify_admin()
{
    char admin_pass[] = "1234";
    char pass[30];
    cout << "\n\n\tEnter admin password to proceed : ";
    cin.ignore();
    cin.getline(pass, 30);
    if (!strcmp(pass, admin_pass))
        return true;
    else
    {
        cout << " \n\tWrong password!!!";
        return false;
    }
}

//***
//    	INTRODUCTION FUNCTION
//****


//***
//    			END OF PROJECT
//**
/*
remove("loan.dat");
remove("hello.dat");
remove("hel.dat");
*/
