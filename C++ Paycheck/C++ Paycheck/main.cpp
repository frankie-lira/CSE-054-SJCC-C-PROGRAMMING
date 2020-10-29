
/* C++ PaycheckV1.0.c: Defines the entry point fo rthe console application.
 Francisco Lira
 06/19/19
 CIS054 C/C++ Programming
 Inputs: Hours, payRate
 Output: grossPay,taxes,netpay
 */

#include <iostream> //used for cin and cout
#include <iomanip> //used to set 2 digits past the decimal
using namespace std;

//define the constants
const double OVERTIME_RATE = 1.5; //time and a half for overtime
const double TAX_RATE = 0.17; //0.17 is 17%

int main (int argc, char* argv[])
{
    //declare the variables
    double hours, payRate;
    double regHours, overtimeHours;
    double regPay, overtimePay;
    double grossPay, taxes, netPay;
    
    //INPUT; hours and payRate
    cout << "Enter the hours worked: ";// prompt
    cin >> hours;
    cout << "Enter the pay rate: ";
    cin >> payRate;
    
    //PROCESS: compute the paycheck
    //separate the regular and overtime hours
    //compute regular, overtime and total paycheck
    if (hours <= 40.0) //less or equal
    {
        regHours = hours; //seperate regHours and overtimeHours
        overtimeHours = 0.0;
        
    }
    else            // over 40. How much is overtime?
    {
        regHours = 40.0;    // regular pay for the first 40 hours
        overtimeHours = hours - 40.0; //anything over 40 hours
    }
    regPay = regHours * payRate;
    overtimePay = overtimeHours * payRate * OVERTIME_RATE;
    grossPay = regPay + overtimePay; //+
    taxes = grossPay * TAX_RATE;
    netPay = grossPay - taxes;
    
    //OUTPUT: display the paycheck values with two digits pats the decimal
    cout << endl; //blank line before the output
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << "your gross pay is $" << setprecision(2) << grossPay << endl;
    cout << "your taxes are $" << setprecision(2) << taxes << endl;
    cout << "your net pay is $" << setprecision(2) << netPay << endl;
    
    return 0;
}



