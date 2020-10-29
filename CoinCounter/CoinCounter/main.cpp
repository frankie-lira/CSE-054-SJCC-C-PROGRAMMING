/*
  CoinCounter
  Francisco  Lira
  CIS054 C/C++ Programming
  Inputs: QuarterAmount,DimeAmount, NickleAmount, PenniesAmount.
  Output: Total
  6/22/19
*/

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    double QuarterAmount, DimeAmount;
    double NickleAmount, PenniesAmount;
    double Total;
    const double QuarterValue = 0.25;
    const double DimeValue = 0.10;
    const double NickleValue = 0.05;
    const double PennyValue = 0.01;
    
    
    cout << " Enter the number of Quarters: ";
    cin >> QuarterAmount;
    
    cout << " Enter the number of Dimes: ";
    cin >> DimeAmount;
    
    cout << " Enter the number of Nickles: ";
    cin >> NickleAmount;
    
    cout << " Enter the number of Pennies: ";
    cin >> PenniesAmount;
    
    Total = (QuarterAmount * QuarterValue) + (DimeAmount * DimeValue) + (NickleAmount * NickleValue) + (PenniesAmount * PennyValue);
    
    cout << " Your total is $" <<  Total << endl;
    
    return 0;
}

