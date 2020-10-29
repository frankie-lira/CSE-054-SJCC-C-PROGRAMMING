/*
 MetricToEnglish
 C++ Version
 Name: Francisco Lira
 Studnet ID: 0886349
 Platform: Mac
 Date: 07/01/19
 Created by Francisco Lira on 07/01/19.
 Copyright © 2019 Francisco Lira. All rights reserved.
 */

#include <iostream>
#include <cctype>
char menuSelect();
using namespace std;


int main(int argc, const char * argv[])
{
    double inches;
    double centimeters;
    char select;
    
    do
    {
        select = menuSelect();
        if (select == 'E')
        {
            cout << "Enter the number of inches: ";
            cin >> inches;
            
            if (cin.fail())
            {
                cout << "Illegal Values are not allowed " << endl;
                return 0;
            }
            
            
            if (inches < 1)
            {
                cout << " Negative values are not allowed " << endl;
              
            }
    
            else
            {
            centimeters = inches * 2.54;
            cout << inches << " Inches is equal to " << centimeters << " centimeters" << endl;
            }
            
        }
        else if (select == 'M')
        {
            //COMPLETE
            {
                cout << "Enter the number of Centimeters: ";
                cin >> centimeters;
                
              if (cin.fail())
              {
                  cout << " Illegal Values are not allowed " << endl;
                  return 0;
              }
                
                if (centimeters < 1)
                {
                    cout << " Negative values are not allowed " << endl;
    
                }
                else
                {
                inches = centimeters / 2.54;
                cout << centimeters << " Centimeters is equal to " << inches << " Inches " << endl;
                }
            }
        }
    }
    while (select != 'Q');
    return 0;
}

char menuSelect()
{
    char selection;
    
    
    do
    {
        cout << endl;
        cout << "Enter E to convert English to Metric, or M to convert Metric to English or Q to quit: ";
        cin >> selection;
         selection = toupper(selection);
    }
    
    while (selection != 'E' && selection != 'M' && selection != 'Q');
    return selection;
}
