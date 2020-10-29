//main.cpp
#include "Rational.h"
#include <iostream>

// function prototypes
void initializeNumbers (Rational &, Rational &, Rational &);
void displayNumbers (const char *, Rational, Rational, Rational);

int main(int argc, char* argv[])
{
    
    Rational n1;
    Rational n2;
    Rational n3;
    
    cout << "Addition" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "**** n2 = n2.add(n3); n2.display(); // n2 should become 17/12" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n2 = n2.add(n3);    // n2 + n3 = 3/4 + 2/3 = 9/12 + 8/12 = 17/12
    displayNumbers("After ", n1, n2, n3);
    cout << "n2.display() shows only n2 ";
    n2.display();           //   using the display( ) member function
    
    cout << endl << endl << "**** n1 = n2 + n3; // n1 should become 17/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2.operator+(n3);    // n2 + n3 = 3/4 + 2/3 = 9/12 + 8/12 = 17/12
    displayNumbers("After ", n1, n2, n3);
    
    cout << endl << "**** n1 = n2 += n3; // n1 and n2 should become 17/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 += n3;
    displayNumbers("After ", n1, n2, n3);
    cout << "-----------------------------------------------------------------------" << endl;
    cout << endl;
    
    cout << "Subtraction" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "**** n1 = n2 - n3; // n1 should be 1/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 - n3;                 // n2 - n3 = 3/4 - 2/3 = 9/12 - 8/12 = 1/12
    displayNumbers("After ", n1, n2, n3);
    
    cout << endl << "**** n1 = n2 -= n3; // n1 and n2 should be 1/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 -= n3;
    displayNumbers("After ", n1, n2, n3);
    cout << "-----------------------------------------------------------------------" << endl;
    cout << endl;
    
    
    cout << "Multiplication" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "**** n1 = n2 * n3; // n1 should become 1/2. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2.operator*(n3);    // n2 * n3 = 3/4 * 2/3 = 6/12
    displayNumbers("After ", n1, n2, n3);
    
    cout << endl << "**** n1 = n2 *= n3; // n1 and n2 should become 1/2. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 *= n3;
    displayNumbers("After ", n1, n2, n3);
    cout << "-----------------------------------------------------------------------" << endl;
    cout << endl;
    
    cout << "Division" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << endl << "**** n1 = n2 / n3; // n1 should become 9/8. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2.operator/(n3);    // n2 / n3 = 3/4 / 2/3 = 9/8
    displayNumbers("After ", n1, n2, n3);
    
    cout << endl << "**** n1 = n2 /= n3; // n1 and n2 should become 9/8. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 /= n3;
    displayNumbers("After ", n1, n2, n3);
    cout << "-----------------------------------------------------------------------" << endl;
    
    cout << endl << "**** Rational number to double. 1/12 displays as 0.0833333" << endl;
    cout << "double(n2) = " << double(n2) << endl;
    cout << endl;
    return 0;
    
}

// Initialize each of the variables before testing each rational operator
void initializeNumbers (Rational &n1, Rational &n2, Rational &n3)
{
    n1 = Rational ();     //    0 no arguments
    n2 = Rational (3,4); //   3/4
    n3 = Rational (2,3); //   2/3
}

// Display each of the rational numbers using the friend function <<
void displayNumbers (const char *msg, Rational n1, Rational n2, Rational n3)
{
    cout << msg << " " << n1 << "\t" << n2 << "\t" << n3 << endl;
}
-------------------------------------------------------------------------------------------------------------------
//Rational.cpp
#include <iostream>
#include "Rational.h"
using namespace std;

Rational::Rational (int num, int denom)
{
    setRational(num,denom);
}

// Helper function to fix a zero denominator and fix the sign if denominator is negative
Rational Rational::setRational (int n, int d) // helper function
{
    numerator = n;
    denominator = d;
    
    // if denominator == 0 then set it = 1
    if (denominator == 0)
        denominator = 1;
    
    if ( denominator < 0 ) // if denominator is neg, multiply num and denom by -1
    {
        numerator = -numerator;     // fix sign of numerator +/-
        denominator = -denominator; // denominator always +
    }
    
    int lcd = LCD(numerator, denominator);
    if (denominator != 0)
    {
        numerator /= lcd;
        denominator /= lcd;
    }
    return *this;   // return the current object
}

// find the lowest common divisor using a recursive function
int Rational::LCD(int v1, int v2)
{
    if (v2==0) return v1;
    else return LCD (v2, v1%v2);
}
Rational Rational::add (Rational right)
{
    int newNumerator;
    int newDenominator;
    
    newNumerator = numerator*right.denominator + right.numerator*denominator;
    newDenominator = denominator * right.denominator;
    
    // create a new Rational object and return it
    return Rational(newNumerator, newDenominator);
}

// the operator+ method does the same thing as the add method
Rational Rational::operator+ (Rational right)
{
    // create local (temporary) variables
    int newNumerator;
    int newDenominator;
    
    // compute the result and save in the local variables
    // the current object's numerator and denominator are not changed
    newNumerator = numerator*right.denominator + right.numerator*denominator;
    newDenominator = denominator * right.denominator;
    
    // create a new Rational object with the result and return it
    return Rational(newNumerator, newDenominator);
}
Rational Rational::operator- (Rational right)
{
    // create local (temporary) variables
    int newNumerator;
    int newDenominator;
    
    // compute the result and save in the local variables
    // the current object's numerator and denominator are not changed
    newNumerator = numerator*right.denominator - right.numerator*denominator;
    newDenominator = denominator * right.denominator;
    
    // create a new Rational object with the result and return it
    return Rational(newNumerator, newDenominator);
}
Rational Rational::operator* (Rational right)
{
    // create local (temporary) variables
    int newNumerator;
    int newDenominator;
    
    // compute the result and save in the local variables
    // the current object's numerator and denominator are not changed
    newNumerator = numerator * right.numerator;
    newDenominator = denominator * right.denominator;
    
    // create a new Rational object with the result and return it
    return Rational(newNumerator, newDenominator);
}
Rational Rational::operator/ (Rational right)
{
    // create local (temporary) variables
    int newNumerator;
    int newDenominator;
    
    // compute the result and save in the local variables
    newNumerator = numerator * right.denominator;
    newDenominator = denominator * right.numerator;
    
    // create a new Rational object with the result and return it
    return Rational(newNumerator, newDenominator);
}
Rational Rational::operator+= (Rational right)
{
    
    // the current object is updated with the result of the +=
    numerator = numerator*right.denominator + right.numerator*denominator;
    denominator = denominator * right.denominator;
    
    // fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
}
Rational Rational::operator-= (Rational right)
{
    // the current object is updated with the result of the -=
    numerator = numerator*right.denominator - right.numerator*denominator;
    denominator = denominator * right.denominator;
    
    // fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
}
Rational Rational::operator*= (Rational right)
{
    
    numerator = numerator * right.numerator;
    denominator = denominator * right.denominator;
    
    // fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
    
}
Rational Rational::operator/= (Rational right)
{
    
    // the current object is updated with the result of the /=
    numerator = numerator * right.denominator;
    denominator = denominator * right.numerator;
    
    // fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
}
Rational::operator double() const // convert Rational to double and return
{
    return double(numerator) / double(denominator);
}

// Display a Rational number using the display() member method
void Rational::display()
{
    cout << numerator << '/' << denominator;
}


// Display a Rational number using << and a friend function.
ostream &operator<< (ostream &out, Rational const &r)
{
    out << r.numerator << '/' << r.denominator;
    return out; // This is to keep the stream flowing
}
---------------------------------------------------------------------------------------------------
//Rational.h
#ifndef RATIONAL_H
#define RATIONAL_H


#include <iostream>
using namespace std;

class Rational
{
    friend ostream &operator<< (ostream &out, Rational const &r);
    
public:
    Rational (int num=0, int denom=1); // also provides default constructor
    
    Rational add (Rational right);
    Rational operator+ (Rational right);    // + addition operator
    Rational operator+= (Rational right);   // += addition assignment operator
    Rational operator* (Rational right);    // * multiplication operator
    Rational operator*= (Rational right);   // *= multiplication assignment operator
    Rational operator- (Rational right);    // - subtraction operator
    Rational operator-= (Rational right);   // -= subtraction assignment operator
    Rational operator/ (Rational right);    // / division operator
    Rational operator/= (Rational right);   // /= division assignment operator
    Rational operator== (Rational right);   // == equality assignment operator
    void display();
    operator double() const; // convert Rational to double
    
private:
    int numerator;
    int denominator;
    // helper functions are private and not accessible by the main program
    int LCD(int v1, int v2);
    Rational setRational (int n, int d);
};

#endif /* Rational_h */
