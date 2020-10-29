/*
 RESERVATION SYSTEM
 C++ Version
 Name: Francisco Lira
 Studnet ID: 0886349
 Platform: Mac
 Date: 07/16/19
 Created by Francisco Lira on 07/16/19.
 Copyright © 2019 Francisco Lira. All rights reserved.
 */


#include <iostream>
#include <cctype>
using namespace std;


char **CreateArrayOfSeats (int NumberOfRows, int seats);
void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats);
void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int seats);
void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int seats);

int main(int argc, char* argv[])
{
    char **ArrayOfSeats;
    int NumberOfRows;
    int NumberOfSeats;
    char rowSelection;
    char seatSelection;
    int row;
    int seat;
    
    cout << "Please enter the number of rows: ";
    cin >> NumberOfRows;
    while(NumberOfRows<3)
    {
        cout<<"Minimum rows are 3\n";
        cout << "Please enter the number of rows: ";
        cin >> NumberOfRows;
        
    }
    cout << "Please enter the number of seats in each row: ";
    cin >> NumberOfSeats;
    while(NumberOfSeats<4)
    {
        cout<<"Minimum seats are 4\n";
        cout << "Please enter the number of seats in each row: ";
        cin >> NumberOfSeats;
        
    }
    
    ArrayOfSeats = CreateArrayOfSeats(NumberOfRows, NumberOfSeats);
    InitializeSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats);
    DisplayArrayOfSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats);
    char choice='y';
    int ct=0;
    
    cout<<"Total number of seats: "<<(NumberOfRows)*(NumberOfSeats)<<endl;
    cout<<"Total seats occupied: "<<ct<<endl;
    do
    {
        cout << endl << "Please enter a seat selection (Example 5F): ";
        cin >> rowSelection;
        cin >> seatSelection;
        if (rowSelection=='0')
            continue;
        
        seatSelection = toupper(seatSelection);
        row = rowSelection - '1';
        seat = seatSelection - 'A';
        if(row>=0&&row<NumberOfRows)
        {
            if(seat>=0&&seat<NumberOfSeats)
            {
                if(ArrayOfSeats[row][seat]!='-')
                {
                    ArrayOfSeats[row][seat]='-';
                    DisplayArrayOfSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats);
                    
                    cout<<"Total number of seats: "<<(NumberOfRows)*(NumberOfSeats)<<endl;
                    
                    ct++;
                    cout<<"Total seats occupied: "<<ct<<endl;
                    cout<<"Do you want to select another seat (y/n)? ";
                    cin>>choice;
                }
                else
                {
                    cerr <<"Invalid seat/ Already reserved seat, Please choose another seat"<<endl;
                    continue;
                }
            }
            else
            {
                cerr <<"Invalid seat/ Already reserved seat, Please choose another seat"<<endl;
                continue;
            }
        }
        
        else
        {
            cerr <<"Invalid seat/ Already reserved seat"<<endl;
            continue;
        }
        if(ct==NumberOfRows*NumberOfSeats)
        {
            cout<<"All seats are reserved"<<endl;
            return 0;
        }
        
    } while (choice == 'y'||choice=='Y');
    
    MemoryCleanup (ArrayOfSeats, NumberOfRows, NumberOfSeats);
    
    return 0;
}

char **CreateArrayOfSeats (int NumberOfRows, int seats)
{
    char **ArrayOfSeats;
    ArrayOfSeats = new char*[NumberOfRows];
    for(int r = 0; r < NumberOfRows; r++)
        ArrayOfSeats[r] = new char[seats];
    return ArrayOfSeats;
}

void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats)
{
    for (int r=0; r<NumberOfRows; r++)
    {
        for (int s=0; s<seats; s++)
            ArrayOfSeats[r][s] = 'A' + s;
    }
}

void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats)
{
    for (int r=0; r<NumberOfRows; r++)
    {
        cout.width(2);
        cout << r+1 << ' ';
        for (int s=0; s<NumberOfSeats; s++)
            cout << ArrayOfSeats[r][s] << ' ';
        cout << endl;
    }
}

void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats)
{
    for (int r=0; r<NumberOfRows; r++)
        delete [] ArrayOfSeats[r];
    delete [] ArrayOfSeats;
}

