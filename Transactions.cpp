#include "Transactions.h"
#include <iostream>



Transactions::Transactions()
{ }
Transactions::Transactions(string send, string recieve, float am, datee d, timee t)
{
    sender = send;
    reciever = recieve;
    amount = am;
    date = d;
    time = t;
}

void Transactions::CashItTransactions(stack <Transactions> cashItTransactions)
{
    stack<Transactions> temporary = cashItTransactions;
    cout << "\nCashIt transactions:" << endl << endl;
    while (!temporary.empty())
    {
        cout << "[" << "From: " << temporary.top().sender << ", To: " << temporary.top().reciever
            << ", Amount: " << temporary.top().amount << ", Date: " << temporary.top().date.day << "-" <<
            temporary.top().date.month << "-" << temporary.top().date.year << ", Time: "
            << temporary.top().time.hours << ":" << temporary.top().time.minutes << "]\n\n";
        temporary.pop();
    }
}
Transactions::~Transactions(void)
{

}