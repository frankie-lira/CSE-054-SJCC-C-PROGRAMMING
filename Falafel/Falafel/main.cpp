
/*
 Falafel
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
#include <iomanip>
void DisplayMenu();
using namespace std;

int main() 
{
    double total = 0.00, price;
    char selection;
    const double tax = 0.087;
    int F_count = 0, S_count = 0, X_count = 0;
    
    do
    {
        DisplayMenu();
        price = 0;
        cout << "Make your selection (FSXT): ";
        cin >> selection;
        switch (toupper(selection))
        {
                case 'F':
                F_count++;
                price = 5.15;
                break;
                
                case 'S':
                S_count++;
                price = 2.24;
                break;
               
                case 'X': 
                X_count++;
                price = 1.57;
                break;
                
                case 'T':
                cout << "Falafel Amount: " << F_count << endl;
                cout << "Cost of falafel: $" << fixed << setprecision(2) << F_count * 5.15 << endl;
                cout << "Soda Amount: " << S_count << endl;
                cout << "Cost of soda: $" << fixed << setprecision(2) << S_count*2.24 << endl;
                cout << "Extra Amount: " << X_count << endl; 
                cout << "Cost of extras: $" << fixed << setprecision(2) << X_count*1.57 << endl;
                break;
               
                default:
                cout << "Illegal selection, try again!" << endl;
        }
                total += price;
                }
                
                while (selection != 'T' && selection != 't');
                cout << "The total amount is: $" << fixed << setprecision(2) << total << endl;
                cout << "Computing the tax amount at 8.7% : $" << fixed << setprecision(2) << total*tax << endl;
                cout << "The final total after adding tax is $" << fixed << setprecision(2) << total + (total*tax) << endl;
                return 0;
                }
               
                void DisplayMenu()
                {
                    cout << endl;
                    cout << "F = falafel  $5.15" << endl;
                    cout << "S = soda     $2.24" << endl;
                    cout << "X = extras   $1.57" << endl;
                    cout << "T = total" << endl;
                }
