#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<dos.h>
#include<fstream>
#include<time.h>
#include<cstring>
#include<ctime>
#include<cstdio>
using namespace std;
int X=70,Y=0;
string gettime()
    {
        char gg[30];
        time_t tt;
        struct tm *ti;  /* Struct tm is Time Structure*/
        time(&tt);
        ti=localtime(&tt);
        strcpy(gg,asctime(ti));
        return (string)gg;
    }
void fontsize(int a, int b)
{
    // Working on it :>
}
void SetCursor(int x,int y,string z)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD PlaceCursorHere;
    PlaceCursorHere.X = x;
    PlaceCursorHere.Y = y;
    SetConsoleCursorPosition(hConsole, PlaceCursorHere);
    cout<<z;
}
void DisplayBankLogo()
{
    system ("CLS");
    cout<< ""<<flush;
    SetCursor(70,0,"Welcome to XYZ Bank");
    X=70;Y=5;
}
class Bank
{
    private:
    int numberofaccounts;
    public:
    void updatebankaccounts();
    int getaccounts();
};
class customer : public Bank
{
    public:
    int pin;
    int accno;
    int sum;
    char fname[20];
    char lname[20];
    char fathername[20];
    char address[20];
    char phoneno[20];
    char  aadharcardno[10];
    void getdata();
    void displaydata();
    void NewCustomer();
    int checkdata(char *);
    int ReadData();
    customer()
    {
      sum=0;
    }
};
class Transaction
{
    public:
    int accountnumber;
    int  Amount;
    int  fateofcash;
    char timeoftransaction[25];           // Either Withdraw or Credit
   // string timeoftransaction;
    void GetTransData(int,int,int);
    void Savetrans(Transaction);
    void Withdraw(customer);
    void choice(customer);
    void Credit(customer);
    void MiniStatement(customer);
    void CurrentStatus(int ); /* For Account Number */
    void PinChange(customer);
    void BlockAccount(customer);
    Transaction()
    {
        Amount= 0;
    }
};
int main()
{
    // Here out stands for output if file is empty or to ovverwrite and app to append :>
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,3);
    customer Customer;
    DisplayBankLogo();
    SetCursor(X-20,Y+=4,"PRESS 1 IF YOU ARE A OLD & 2 IF YOU ARE NEW and 3 for Admin ");
    SetCursor(X-20,Y+=10,"Enter Your Choice::\t");
    int x;char ch;
    string st="",str="hol moly";
    cin>>x;
    switch(x)
    {
    case 1:
        {
            customer r;
             Transaction t;
            int acno;
            int k=0;            // Counter
            cout<<"Enter you accountnumber";
            cin>>acno;
            fstream file("customerfile.dat"); /* This is to for input purposes only :>*/
             while(!file.eof())         // For Finding Valid User with a valid account number :>
             {
              if(r.accno==acno)
              {                     // FOr Checking Customer
                 cout<<"ACCNO:"<<r.accno<<"\t"<<"NAME :"<<r.fname<<"\n";
                Customer=r;
                k=1;break;
               }
                file.read((char *)&r,sizeof(r));
             }
             if(k!=1)
            {
            cout<<"\nNo Match Found.Please Reenter the correct Account Number";
            file.close();
            break;
            main();
            }
            else{
            int x;cout<<"\n"<<"P I N: \n";
            SetConsoleTextAttribute(hConsole,0);
            cin>>x;
            SetConsoleTextAttribute(hConsole,3);
            if(x==Customer.pin)
            {
            file.close();
            cout<<"";
            system ("CLS");
           DisplayBankLogo();
            t.choice(Customer);
            }
            else
            {
                cout<<"\n WRONG PIN RENETER DETIALS \n";
                system ("CLS");
                cout<< ""<<flush;
                main();
            }
            }
        }
            break;
    case 2:
        {
            customer x;
            x.NewCustomer();
        }
            break;
    case 3:
        {
           cout<<"WELCOME ADMIN\n";
            customer r;Transaction t;
             ifstream file("customerfile.dat"); /* This is to for input purposes only :> */
             file.read((char *)&r,sizeof(r));
             while(!file.eof())         // For Finding Valid User with a valid account number :>
             {
              r.displaydata();
              file.read((char *)&r,sizeof(r));
              cout<<"\n\n";
             }
           //   Bank b;
           // cout<<b.getaccounts()<<"are the number of Accounts Made , period";file.close();
       // ifstream file("transactionfile.dat",ios::in);
        //file.read((char *)&t,sizeof(t));
    }
        break;
    default:
        cout<<"Wrong input";
    }
    return 0;
}                                                   /* End of Main */






    void Transaction:: PinChange(customer Customer)
    {
    cout<<"\nON IT";
    }
    void Transaction:: BlockAccount(customer Customer)
    {
    cout<<"\nON IT";
    }
    void Transaction:: Savetrans(Transaction nc)
    {
            cout<<"\n\nSaving Transaction DONOT QUIT IN BETWEEN\n"<<nc.accountnumber;
            ofstream file("transactionfile.dat",ios::out|ios::app);
            file.write((char *)&nc,sizeof(nc));
            cout<<"\nTransaction Saved Successfully check";
            file.close();
    }
    void Transaction::GetTransData(int accountnum,int amount,int choice)
    {
        int i=0;
      accountnumber = accountnum;
      Amount = amount;
      fateofcash = choice;
      string x = gettime();
      for(i=0;i<x.length();i++)
      {
          timeoftransaction[i]=x[i];
      }
      timeoftransaction[i]='\0'; // Terminating 8
    }
    void Transaction :: choice(customer Customer)
    {
      SetCursor(X-10,Y+=3,"CHOOSE FROM BEOLOW");
      SetCursor(X-50,Y+=3,"1: WITHDRAW");
      SetCursor(X+30,Y,"2: CREDIT");
      SetCursor(X-50,Y+=3,"3: MINI STATEMENT");
      SetCursor(X+30,Y,"4: CURRENT STATUS");
      SetCursor(X-50,Y+=3,"5: CHANGE PIN");
      SetCursor(X+30,Y,"6: BLOCK ACCOUNT");
      SetCursor(X-20,Y+=5,"ENTER HERE: ");
       int k;
       cin>>k;
       switch (k)
       {
       case 1:
        Withdraw(Customer);break;
       case 2:
        Credit(Customer);break;
       case 3:
        MiniStatement(Customer);break;
       case 4:
        CurrentStatus(Customer.accno);break;
       case 5:
        PinChange(Customer);break;
       case 6:
        BlockAccount(Customer);break;
       default:
        {
            cout<<"\n Wrong Input , Please Renter Your value";
            cout<<"";
            system ("CLS");
            choice(Customer);
        }
       }
    }
     void Transaction::Credit(customer Customer)
    {
            Transaction T;
            int amount;
           SetCursor(X-20,Y+=2,"nEnter the Amount You Want To Credit Min=500 INR\n\n and Minimum 500 INR");
            cin>>amount;
            if(amount>=500)
            {
            Customer.sum = amount+Customer.sum;
            SetCursor(X-20,Y+=4,"");
            cout<<Customer.sum<<" IS THE NEW AMOUNT";
            ofstream gg("transactionfile.dat",ios::out|ios::app);
            T.GetTransData(Customer.accno,amount,2);
            T.Savetrans(T);
            fstream file("customerfile.dat");
            customer acc;
            file.read((char *)&acc,sizeof(acc));
            while(!file.eof())         // For Finding Valid User with a valid account number :>
             {
              if(acc.accno==(Customer.accno))
              {
              file.seekp(file.tellp()-sizeof(acc));
              file.write((char *)&Customer,sizeof(Customer));
              }
              file.read((char *)&acc,sizeof(acc));
             }
             file.close();
             cout<<"\nData Successfully Saved\n";
            }
            else{
                cout<<"\nMinimum Sum To Deposit is 500 INR , Please Renter ";
                system ("CLS");
               cout<< ""<<flush;
                Credit(Customer);
            }
    }
    void Transaction:: Withdraw(customer Customer)
    {
            Transaction T;
            int amount;
            cout<<"\n\nEnter the Amount You Want To Debit and Minimum 500 INR";
            cin>>amount;
            if(amount>=500 && Customer.sum>=amount)
            {
            Customer.sum = Customer.sum-amount;
            cout<<Customer.sum<<" IS THE NEW AMOUNT  after debiting "<<amount<<" INT \n";
            cout<<"\n The Account Number"<<T.accountnumber<<"has been Debited with "<<T.Amount<<" of INR on ";//<<T.timeoftransaction<<"\n";
            T.GetTransData(Customer.accno,amount,1);
            T.Savetrans(T);
            customer acc;
            fstream file("customerfile.dat"); /* This is to for input purposes only :>*/
            file.read((char *)&acc,sizeof(acc));
             while(!file.eof())         // For Finding Valid User with a valid account number :>
             {
              if(acc.accno==(Customer.accno))
              {
              file.seekp(file.tellp()-sizeof(acc));
              file.write((char *)&Customer,sizeof(Customer));
              }
              file.read((char *)&acc,sizeof(acc));
             }
             file.close();
             cout<<"\nData Successfully Saved\n";
            }
            else if(Customer.sum<amount)
            {
                cout<<"\nAVAILABLE BALANCE IS LESS THAN THE MONEY REQUESTED :(";
                system ("CLS");
                cout<< ""<<flush;
                main();
            }
            else
                {
                cout<<"\nMinimum Sum To Withdraw is 500 INR , Please Renter ";
                system ("CLS");
               cout<< ""<<flush;
                Credit(Customer);
            }
    }
    void Transaction::MiniStatement(customer Customer)
    {
            Transaction T;
            int k=0;
            cout<<"\n Inside MINI\n";
            ifstream file("transactionfile.dat",ios::in); /* This is to for input purposes only :>*/
            file.read((char *)&T,sizeof(T));
            while(!file.eof() && k<=5)         // For Finding Valid User with a valid account number :>
             {
               if(T.accountnumber == (Customer.accno))
              {
                if(T.fateofcash==2) // CREDIT
                cout<<"Account Number :- "<<T.accountnumber<<" Has Been Credited With Amount of "<<T.Amount<<"INR  ON "<<T.timeoftransaction<<"\n";
                else if(T.fateofcash==1)              // DEBIT
                cout<<"Account Number :- "<<T.accountnumber<<" Has Been Debited With Amount of "<<T.Amount<<"INR  ON "<<T.timeoftransaction<<"\n";
             }
             k++;
             file.read((char *)&T,sizeof(T));
           }
        file.close();
    }
    void Transaction:: CurrentStatus(int x)
    {

    }
    void Bank:: updatebankaccounts()           // Called to Increment No. of Bank Accounts every time a Acc is Cretated
    {
        Bank r;
        r.numberofaccounts=getaccounts()+1;
        ofstream file("bankfile.dat",ios::out);
        file.write((char *)&r,sizeof(r));
        file.close();
    }
    int Bank:: getaccounts()
    {
        Bank r;
        fstream checkfile("bankfile.dat");
        if(checkfile.is_open())
        {
         ifstream file("bankfile.dat",ios::in); /* This is to for input purposes only :>*/
        file.read((char *)&r,sizeof(r));
        file.close();
        return r.numberofaccounts;  // for first one
        }
        else
        {
        return 0;
        }
    }
    void customer::getdata()
    {
        customer r;
        char x[20];
        Bank b;
        gets(x);
        SetCursor(X-10,Y+=3,"AADHAR CARD NO.:");
        gets(aadharcardno);
        if(!(checkdata(aadharcardno)))
        {
        DisplayBankLogo();
        NewCustomer();
        }
        SetCursor(X-10,Y+=1,"FIRST NAME: ");
        gets(fname);
        SetCursor(X-10,Y+=1,"LAST NAME: ");
        gets(lname);
        SetCursor(X-10,Y+=1,"FATHER'S NAME: ");
        gets(fathername);//cin.getline(fathername,sizeof(fathername));
        SetCursor(X-10,Y+=1,"ADDRESS: ");
        gets(address);//cin.getline(address,sizeof(address));
        SetCursor(X-10,Y+=1,"PHONE NUMBER: ");
        gets(phoneno); //cin.getline(phoneno,sizeof(phoneno));
        SetCursor(X-10,Y+=1,"PASSWORD: ");
        cin>>pin;
        SetCursor(X-10,Y+=1,"Enter Sum To Credit *MINIMUM INR 500*");
        cin>>sum;
        accno=6000+(b.getaccounts());
        updatebankaccounts();
        if(sum<500)
        getdata();
        else
        {
            Transaction T;
            T.GetTransData(accno,sum,2);
            T.Savetrans(T);
        }
    }
    void customer:: displaydata()
    {
     cout<<"WELCOME   "<<fname<<" "<<lname<<"\n";
     cout<<"Account Number: "<<accno<<"\n";
     cout<<"Address = "<<address<<"\n";
     cout<<"Aadhar NO = "<<aadharcardno<<"\n";
     cout<<"phonenumber ="<<phoneno<<"\n";
     cout<<"Balance ="<<sum<<"\n";
     cout<<"*****"<<pin<<"*****\n\n\n";
    }
    int customer:: checkdata(char *element)
    {
     for(int i=0;i<10;i++)
     {
         if(!(element[i]>='1' && element[i]<='9'))
         {
             return 0;
         }
     }
     return 1;
    }
    int customer:: ReadData()
    {
        int acc;
        int k=0;
        customer r;
        ifstream file("customerfile.dat",ios::in); /* This is to for input purposes only :>*/
        file.read((char *)&r,sizeof(r));
        while(!file.eof())         // For Finding Valid User with a valid account number :>
             {
              k++;
              if(k==0)
              file.read((char *)&acc,sizeof(acc));
              else
              file.read((char *)&r,sizeof(r));
             }
             file.close();
             return acc; /* So that we can Manage new account's account number by taking the accno of the last one */
    }
     void customer:: NewCustomer()
    {
       SetCursor(X-20,Y+=2,"WELCOME NEW USER");
            customer nc;
            Transaction t;
            fstream kar("customerfile.dat");  /* Here ios::app stands for Append and out stands for Output(Create if not exist */
            if(kar.is_open()) // To check is file exists or not
            {
            ofstream file("customerfile.dat",ios::app);
            nc.getdata();
            file.write((char *)&nc,sizeof(nc));
            cout<<"\nData Saved Successfully check";
            nc.displaydata();
            Sleep(2000);
            system ("CLS");
            cout<< ""<<flush;
            DisplayBankLogo();
            t.choice(nc);
            cout<<"\n\n\nDONOT QUIT IN BETWEEN\n\n";
            file.close();
            }
            else // Then the things to create at first :>
            {
              ofstream file("customerfile.dat",ios::out);
              nc.getdata();
              file.write((char *)&nc,sizeof(nc));
               cout<<"\nData Saved Successfully\n";
               nc.displaydata();
               Sleep(2000);
               system ("CLS");
               cout<< ""<<flush;
               DisplayBankLogo();
               SetCursor(X-20,Y,"DONOT QUIT IN BETWEEN");
               file.close();
               t.choice(nc);
             //  Transaction t;t.Credit();
            }
    }
