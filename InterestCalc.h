#pragma once

#ifndef _PROJECT_2_INTERESTCALC_H
#define _PROJECT_2_INTERESTCALC_H

class InterestCalc
{
public:
    InterestCalc();                                 //constructor declaration
    double GetInitAmount();
    void   SetInitAmount(double t_userInitAmount);
    double GetMonthDep();
    void   SetMonthDep(double t_userMonthDep);
    double GetInterestRate();
    void   SetInterestRate(double t_userInterestRate);
    int	   GetNumYears();
    void   SetNumYears(double t_userNumYears);      //^ getters/setters for all 4 values
    void   PrintData(bool t_withMonthDep = false);  //function to print calculated values, has optional parameter
private:
    double m_initAmount;
    double m_monthDep;
    double m_interestRate;
    int	   m_numYears;                              //declare variables for 4 values
};

#endif // !_PROJECT_2_INTERESTCALC_H