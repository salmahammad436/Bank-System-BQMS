#include <iostream>
#include <vector>
#include "Customer.h"
#include "Teller.h"
#include "Bank.h"
#include "linkedTeller.h"
#include <windows.h>

using namespace std;



void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

   if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
   {
       wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
  }
}














int main()

{
    SetColor(11);
    int TellerSize, numCustomer, arravTime, servTime;
    cout<<"\n\n\n************************************************WELCOME TO BANK MISR****************************************************\n\n\n"<<endl;

     SetColor(10);
    cout << "please Enter the number of tellers: ";
    SetColor(8);
    cin >> TellerSize;

    Bank bank(TellerSize);
    SetColor(10);
    cout << " also Enter the number of customers: ";
    SetColor(8);
    cin >> numCustomer;

    for (int i = 0; i < numCustomer; i++)
    {   SetColor(10);
        cout << "Enter arrival and service time for customer " << i + 1 << ": ";
        SetColor(8);
        cin >> arravTime >> servTime;
        bank.addCustomer(Customer(arravTime, servTime));
    }

    for (int i = 0; i < numCustomer; i++)
    {
        bank.startService();
    }

    CustomerQueue& customerQueue = bank.getQueue();

    vector<Customer> allCustomers;
    int result = customerQueue.displayAllCustomers(allCustomers);

    if (result == 1)
    {   SetColor(11);
        cout <<"\n Customers in the queue:\n"<<endl;
        for (auto& customer : allCustomers)
        {
            cout  <<"Customer ID: " << "\t Priority: " <<"\t arraivl Time:"<< "\t service time:"<<"\t waiting time"<<"\t Exit Time:"<<endl;
            cout  <<customer.getId()<< "\t \t"
                  <<customer.getPriority()<<"\t \t"
                  <<customer.getArravTime()<<"\t\t"
                  <<customer.getServTime()<<"\t\t"
                  <<customer.getWiteTim()<<"\t\t"
                  <<customer.getDepTime()<< "\n";
        }
    }
    else
    {
        cout << "The queue is empty.\n";
    }


    cout<<"\n________________________________________________________________________________________________________________"<<endl;

    linkedTeller tellers=bank.getLinkedTeller();

    if (linkedTeller::getLength()>0)
    {
        vector<Teller> allTeller;
        tellers.displayAll(allTeller);

        cout << "Tellers in the bank:\n"<<endl;
        for ( auto& teller : allTeller)
        {
            cout << "teller Id" << "\t" << "teller status" << "\t" << "service time" <<"\t"<<"Customer Number servied in this teller"<< endl;
            cout << teller.getNum() << "\t\t" << teller.getStatus() << "\t\t" << teller.getTotalService()<< "\t\t" << teller.getCounterCust()<< endl;
        }
    }

    return 0;
}
