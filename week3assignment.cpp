#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

//Set constants
double onefifty = 150.00;
double onehundred = 100.00;
double fifty = 50.00;
double fragconst = 2.00;
double freeconst = 0.00;
double lessusa = 6.00;
double lesscan = 8.00;
double lessaus = 10.00;
double lowmidusa = 9.00;
double lowmidcan = 12.00;
double lowmidaus = 14.00;
double midusa = 12.00;
double midcan = 15.00;
double midaus = 17.00;
double mars = 1000.00;

int main()
{
    //Output lines for initial statements
    cout << setfill('.') << setw(50) << "." << endl;
    cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
    cout << setfill('.') << setw(50) << "." << endl;
    cout << setfill(' ') << setw(50) << " " << endl;

    //Ask user for input and store in a variable
    string itemname;
    cout << setfill('.') << setw(49) << left << "Please enter the item name (no spaces)" << ":" << endl;
    cin >> itemname;
    string userfragile;
    cout << setfill('.') << setw(49) << left << "Is the item fragile? (y=yes/n=no)" << ":" << endl;
    cin >> userfragile;
    if ((userfragile != "y" ) && (userfragile != "n") && (userfragile != "Y" ) && (userfragile != "N"))
        {
        cout << "Invalid entry, exiting" << endl;
        return 0;
        }
    double usertotal;
    cout << setfill('.') << setw(49) << left << "Please enter your order total" << ":" << endl;
    cin >> usertotal;
    string userdest;
    cout << setfill('.') << setw(49) << left << "Please enter destination. (usa/can/aus/mars)" << ":" << endl;
    cin >> userdest;
    if ((userdest != "usa" ) && (userdest != "can") && (userdest != "aus") && (userdest != "mars"))
        {
        cout << "Invalid entry, exiting" << endl;
        return 0;
        }


    double destcost = 0;
    double fragcost = 0;
    //determine prices using user inputs
    if (usertotal > onefifty)
        {
        destcost = freeconst;
        } 

    else if (usertotal > onehundred)
        {
        if (userdest == "usa")
            {
            destcost = midusa;
            } 
        else if (userdest == "can")
            {
            destcost = midcan;                }   
        else if (userdest == "aus")
            {
            destcost = midaus;
            }
        else if (userdest == "mars")
            {
            destcost = mars;
            }
        }  
    else if (usertotal > fifty)
        {
        if (userdest == "usa")
            {
            destcost = lowmidusa;
            }  
        else if (userdest == "can")
            {
            destcost = lowmidcan;
            } 
        else if (userdest == "aus")
            {
            destcost = lowmidaus;
            }
        else if (userdest == "mars")
            {
            destcost = mars;
            }
        }  
    else{
        if (userdest == "usa")
            {
            destcost = lessusa;
            }  
        else if (userdest == "can")
            {
            destcost = lesscan;
            }   
        else if (userdest == "aus")
            {
            destcost = lessaus;
            }
        else if (userdest == "mars")
            {
            destcost = mars;
            }
        }

    //apply fragile fee baised on user input
    if (userfragile == "y")
        {
        fragcost = fragconst;
        }   
    else{
        fragcost = freeconst;
        }

    //final equation calculation
    double shipcost = destcost + fragcost;
    double totalshipcost = shipcost + usertotal;

    //Output lines for calculations
    cout << setfill('.') << setw(40) << left << "Your item is" << itemname << endl;
    cout << setfill('.') << setw(40) << left << "Your shipping cost is" << "$" << fixed << setprecision(2) << shipcost << endl;
    cout << setfill('.') << setw(40) << left << "You are shipping to" << userdest << endl;
    cout << setfill('.') << setw(40) << left << "Your total shipping costs are" << "$" << fixed << setprecision(2) << totalshipcost << endl;
}    