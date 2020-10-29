/*
 Francisco Lira
 Project: Electric Bill V1.0
 6/25/19.
 Programming C++
 Copyright © 2019 Francisco  Lira. All rights reserved.
*/

#include <iostream> //used for cin and cout
#include <iomanip> //used to set 2 digits past the decimal
using namespace std;

int main(int argc, char* argv[])
{
    //declare the variables
    double Base_kWh, Extra_kWh;
    double kWh, Base_Bill;
    double Extra_Bill, Electric_Bill;
   
    
    //INPUT; hours and payRate
    cout << "Enter kWh: ";  // prompt
    cin >> kWh;
    
    if (cin.fail() || kWh < 0)
    {
        cout << "The number entered was either non-numeric or less than zero" << endl;
        return 1;
    }
    
    else if (kWh <= 500)
    {
        Base_kWh = kWh;
        Extra_kWh = 0;
        Base_Bill = Base_kWh * 0.27;
    }
    
    else if (kWh > 500)
    {
        Base_kWh = kWh;
        Extra_kWh = Base_kWh - 500;
        Base_Bill = 500 * 0.27;

        Extra_Bill = (Extra_kWh * 0.55);
    }
   Electric_Bill = Base_Bill + Extra_Bill;
    cout << "Your Electric Bill is: $" << Electric_Bill << endl;

    
    return 0;
}
