/*
 LengthOfLine
 C++ Version
 Name: Francisco Lira
 Studnet ID: 0886349
 Platform: Mac
 Date: 06/06/19
 Created by Francisco Lira on 06/04/19.
 Copyright © 2019 Francisco Lira. All rights reserved.
 */

#include <iostream>
#include <cmath>
using namespace std;

double LengthOfLine(double X1, double Y1, double X2, double Y2, double length);
double LengthOfLine(double X1, double Y1, double X2, double Y2)

{
    double a, b, c;
    a = X2 - X1;
    b = Y2 - Y1;
    c = sqrt((a * a) + (b * b));
    return c;
}

int main(int argc, const char * argv[])

{
    
    double X1, X2, Y1, Y2, length;
    cout << "Enter X1 X2 Y1 Y2 seperated by spaces: ";
    cin >> X1 >> Y1 >> X2 >> Y2;
    length = LengthOfLine (X1, Y1, X2, Y2);
    
    cout << "The length of the line is " << length << endl;
    return 0;
}


