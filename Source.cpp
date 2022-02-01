//Tanner Gaudes

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "InterestCalc.h"

using namespace std;

void GetInitialDeposit(InterestCalc& interestCalc)
{
    double userNumber;                          //temporary double to store user input

    cout << "Enter initial deposit: $";
    cin >> userNumber;                          //assign numeric value to userNumber
    while (cin.fail() || userNumber < 0)        //while user did not input a numeric value or value is negative
    {
        cin.clear();                                //clear cin so it can be used again
        cin.ignore(1000, '\n');                     //ignore rest of bad line
        cout << "\nInvalid input. Enter initial deposit: $";
        cin >> userNumber;                          //assign userNumber again until successful
    }
    interestCalc.SetInitAmount(userNumber);     //initial deposit amount setter
}
void GetData(InterestCalc& interestCalc)        //pass object by reference
{
    double userNumber;                              //temporary double for user numbers

    system("cls");                                  //clear screen
    cout << "Initial deposit: $" <<
        interestCalc.GetInitAmount() << endl;       //print initial amount for user to see

    cout << "Enter monthly deposit: $";
    cin >> userNumber;
    interestCalc.SetMonthDep(userNumber);           //set monthly deposit

    cout << "Enter APR (as percentage): ";
    cin >> userNumber;                              //get APR as percentage
    interestCalc.SetInterestRate(userNumber);       //set interest rate

    cout << "Enter number of years (as whole number): ";
    cin >> userNumber;                              //get number of years as whole number (is casted to double later)
    interestCalc.SetNumYears(userNumber);           //set number of years
}
void PrintWithAndWithout(InterestCalc interestCalc)
{
    string horizontalLine;
    for (int i = 0; i < 75; i++)
    {
        horizontalLine.append("_");                 //create string of a horizontal line 75 chars wide
    }

    system("cls");                              //clear screen for readability
    cout << fixed << setprecision(2) << left << 
        "\nInitial deposit: $" << interestCalc.GetInitAmount() <<
        "  |  Monthly deposit: $" << interestCalc.GetMonthDep() << 
        "  |  Interest rate: " << interestCalc.GetInterestRate() << "%" << endl;  //print data for viewer to see

    cout << horizontalLine << "\n  Without monthly deposit:" << endl;
    interestCalc.PrintData();                   //print WITHOUT monthly deposit
    cout << horizontalLine << "\n  With monthly deposit:" << endl;
    interestCalc.PrintData(true);               //print WITH monthly deposit by passing 'true' boolean
}

int main()
{
    string userString;                          //declare variable for user input
    InterestCalc interestCalc;                  //declare new InterestCalc object

    GetInitialDeposit(interestCalc);            //get initial deposit right away, passing object by reference

    while (userString != "exit")                //while user has not entered 'exit'
    {
        try
        {
            GetData(interestCalc);                      //get rest of data, passing InterestCalc object by reference
        }
        catch (runtime_error& e)                    //catches any error from GetData local function
        {
            cout << "\n" << e.what() << 
                " Please try again.";                   //prints error message
            cin.clear();                                //clear error from cin
            cin.ignore(1000, '\n');                     //must ignore or cin will keep trying to use invalid data
            cin.get();                                  //wait for user input so user can read error message
            continue;                                   //return to top of loop
        }

        cin.ignore();                               //move cin to next line
        cout << "\nPress enter to print data...";
        getline(cin, userString);                   //wait for user input
        PrintWithAndWithout(interestCalc);          //call local print function, passing object by VALUE

        cout << "\nPress enter to return to input screen, or \"exit\" to quit." << endl;
        getline(cin, userString);                   //gets user input again before returning to top of loop
    }
    return 0;
}