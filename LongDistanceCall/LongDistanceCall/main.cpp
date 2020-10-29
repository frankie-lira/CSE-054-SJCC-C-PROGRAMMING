/*
 LongDistanceCall
 C++ Version
 Name: Francisco Lira
 Studnet ID: 0886349
 Platform: Mac
 Date: 06/30/19
 Created by Francisco Lira on 6/30/19.
 Copyright © 2019 Francisco Lira. All rights reserved.
 */

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[])
{
    const double Weekend_Rate = 0.15;
    const double Evening_Rate = 0.25;
    const double Day_Rate = 0.40;
    char Day1, Day2;
    int Hour;
    char Separator;
    int Minute;
    int LengthOfCall;
    
    char again;
    int TimeStarted;
    double BillingRate;
    double CostOfCall;
    
    do
    {
        cout << "Enter the day (Mo Tu We Th Fr Sa Su): ";
        cin >> Day1 >> Day2;
        Day1 = toupper (Day1);
        Day2 = toupper (Day2);
        
        cout << "Enter the time started (ex: 14:35): ";
        cin >> Hour >> Separator >> Minute;
        TimeStarted = Hour * 100 + Minute;
       
        cout << "Enter the legth of the call in minutes: ";
        cin >> LengthOfCall;
        
        if (Day1 == 'S' && Day2 == 'A')
            BillingRate = Weekend_Rate;
        else if (Day1 == 'S' && Day2 == 'U')
            BillingRate = Weekend_Rate;
        else
        {
          if (TimeStarted >= 800 && TimeStarted <= 1800)
              BillingRate = Day_Rate;
            else
                BillingRate = Evening_Rate;
        }
        CostOfCall = LengthOfCall * BillingRate;
        //Output:
        cout << "The Cost Of Your Call Is: $" << CostOfCall << endl;
        
        cout << "Another Call (Y/N)? ";
        cin >> again;
        again = toupper(again);
    }
    while (again == 'Y');
    return 0;
}
