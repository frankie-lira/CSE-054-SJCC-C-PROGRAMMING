/*
 FastFoodRestaurant
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
void DisplayMenu();        // display the menu
using namespace std;

int main(int argc, char* argv[])
{
    double subtotal = 0.00;
    double price;
    char selection;
    double const TAX_RATE;
    
    DisplayMenu();
    do
    {
        price = 0;
        cout << "Make your selection (FSXT): ";
        cin  >> selection;
        switch ( toupper(selection) )
        {
            case 'F':
                price = 5.15;
                break;
            case 'S':
                price = 2.24;
                break;
            case 'X':
                price = 1.57;
                break;
            case 'T':
                break;
            default:
                cout << "Illegal selection, try again." << endl;
        }
        subtotal += price;
    } while (selection != 'T' && selection != 't');
    
    cout << "  "
    cout << "   Subtotal $" << subtotal << endl;
    return 0;
}

void DisplayMenu()
{
    cout << endl;   // blank line before start of menu
    cout << "F = falafel  $5.15" << endl;
    cout << "S = soda     $2.24" << endl;
    cout << "X = extras   $1.57" << endl;
    cout << "T = total" << endl;
}


