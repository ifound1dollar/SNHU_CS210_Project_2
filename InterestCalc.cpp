#include "InterestCalc.h"
#include <iostream>
#include <iomanip>

using namespace std;

InterestCalc::InterestCalc()            //default constructor, initializes everything to 0
{
    m_initAmount = 0.0;
    m_monthDep = 0.0;
    m_interestRate = 0.0;
    m_numYears = 0;
}

double InterestCalc::GetInitAmount()                    //initial deposit getter
{
    return m_initAmount;
}
void InterestCalc::SetInitAmount(double t_userInitAmount)   //initial deposit setter
{
    m_initAmount = t_userInitAmount;
}

double InterestCalc::GetMonthDep()                      //monthly deposit getter
{
    return m_monthDep;
}
void InterestCalc::SetMonthDep(double t_userMonthDep)       //monthly deposit setter
{
    if (cin.fail())                             //if cin detected error, throw exception
    {
        throw runtime_error("Input was not a numeric type.");
    }
    else if (t_userMonthDep < 0)                  //checks if negative
    {
        throw runtime_error("Value cannot be negative.");
    }
    m_monthDep = t_userMonthDep;
}

double InterestCalc::GetInterestRate()                  //interest rate getter
{
    return m_interestRate;
}
void InterestCalc::SetInterestRate(double t_userInterestRate)   //interest rate setter
{
    if (cin.fail())                             //checks for error again
    {
        throw runtime_error("Input was not a numeric type.");
    }
    else if (t_userInterestRate < 0)              //checks if negative
    {
        throw runtime_error("Value cannot be negative.");
    }
    m_interestRate = t_userInterestRate;
}

int InterestCalc::GetNumYears()                         //number of years getter
{
    return m_numYears;
}
void InterestCalc::SetNumYears(double t_userNumYears)       //number of years setter
{
    if (cin.fail())                             //checks for error again
    {
        throw runtime_error("Input was not a numeric type.");
    }
    else if (t_userNumYears < 1)                  //checks if less than 1
    {
        throw runtime_error("Value cannot be less than 1.");
    }
    static_cast<int>(t_userNumYears);             //cast argument to integer to truncate any decimal
    m_numYears = t_userNumYears;
}

void InterestCalc::PrintData(bool t_withMonthDep)
{
    double yearEndBalance = 0;
    double yearInterestEarned = 0;                  //declare annual values variables and set to 0
    double monthlyBalance = 0;
    double monthlyInterest = 0;                     //monthly doubles are used for monthly compound calculation
    monthlyBalance = this->GetInitAmount();         //monthly balance starts off at the initial deposit

    cout << "\n   " << setw(22) << left << "YEAR:" << setw(28) << 
        "YEAR END BALANCE:" << setw(25) << "YEAR END INTEREST:\n" << endl;  //display formatted header info

    for (int i = 1; i <= this->GetNumYears(); i++)  //for each year 
    {
        yearInterestEarned = 0;                         //reset yearly interest value each year
        for (int j = 1; j <= 12; j++)                   //for each month of the year
        {
            if (t_withMonthDep)                             //if monthly deposit included
            {
                monthlyBalance += this->GetMonthDep();          //add monthly deposit to opening balance each month
            }
            monthlyInterest = monthlyBalance * 
                ((this->GetInterestRate() / 100) / 12);     //calculate interest from monthly opening balance
            monthlyBalance += monthlyInterest;              //add calculated interest to closing balance
            yearInterestEarned += monthlyInterest;          //add calculated interest to yearly interest value
        }
        yearEndBalance = monthlyBalance;                //assign yearEndBalance with balance after last month (12)
        
        cout << "   " << setw(19) << left << i;             //print year in line with header
        cout << "   " << setw(25) << left << 
            fixed << setprecision(2) << yearEndBalance;     //print year end balance aligned with header
        cout << "   " << setw(25) << left << fixed << 
            setprecision(2) << yearInterestEarned << endl;  //print year end interest aligned with header
        cout << endl;                                       //print extra line
    }
}