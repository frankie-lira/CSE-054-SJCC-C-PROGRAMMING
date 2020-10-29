/*
 Francisco Lira
 StudentID: 0886349
 Platform (Mac or PC):  Mac
 Language (C or C++): C++
 Project: MEAN AND MEDIAN OF A FILE
 07/12/19.
 CIS054  C/C++ Programming
 Copyright © 2019 Francisco  Lira. All rights reserved.
*/



#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
    ifstream infile;
    char filename[200];
    int recordCount = 0;
    int recordsToSkip = 0;
   
    int    AcctNo = 0;
    char   Name[100] = "";
    double AcctBal = 0.0;
   
    double median = 0.0;
    
    cout << "Enter the name of the data file: ";
    cin >> filename;
    
    infile.open(filename);
    if (infile.fail())
    {
        cerr << "Unable to open --" << filename << "--, first pass" << endl;
        exit(1);
    }
    
    double tot = 0;
    while (!infile.eof())
    {
        Name[0] = 0;
        infile >> AcctNo >> Name >> AcctBal;
        if (Name[0] != 0)
        {
            recordCount++;
            tot = tot + AcctBal;
        }
    }
    infile.close();
    cout << "The total balance is: " << tot << endl;
    cout << "There are " << recordCount << " records in " << filename << endl;

    if (recordCount % 2 == 1)
        recordsToSkip = recordCount / 2;
    else
        recordsToSkip = recordCount / 2 - 1;
    
    cout << "leading " << recordsToSkip + 1 << " records will be skipped " << filename << endl;
    
    infile.open(filename);
    
    int c = 0;
    
    while(c <= recordsToSkip)
    {
        infile >> AcctNo >> Name >> AcctBal;
        c++;
    }

    double remain = 0;
    while (!infile.eof())
    {
        Name[0] = 0;
        infile >> AcctNo >> Name >> AcctBal;
        if (Name[0] != 0)
        {
            remain=remain+AcctBal;
        }
    }
    double mean = remain / (recordCount-recordsToSkip - 1);
    cout << "The mean of remaining records is: " << mean << recordCount - recordsToSkip << endl;
    
    
    infile.close();
    infile.open(filename);
    
    double balarray[100];
  
    recordCount=0;
    while (!infile.eof())
    {
        Name[0] = 0;
        infile >> AcctNo >> Name >> AcctBal;
        if (Name[0] != 0)
        {
            balarray[recordCount] = AcctBal;
            recordCount++;
        }
    }
    infile.close();
 
    int i, j;
   
    for (i = 0; i < recordCount - 1; i++)
        for (j = 0; j < recordCount - i - 1; j++)
            if (balarray[j] > balarray[j + 1])
            {
                double x = balarray[j];
                balarray[j] = balarray[j + 1];
                balarray[ j + 1] = x;
            }
    if(recordCount % 2 == 1)
        median = balarray[(recordCount) / 2];
    
    else
        median = (balarray[(recordCount / 2) - 1] + balarray[recordCount / 2]) / 2;
  
    cout << "The median of " << filename << " is " << median << endl << endl;
    
    system("pause");
    return 0;
    
}
