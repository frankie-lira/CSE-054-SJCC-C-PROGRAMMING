/*
 Francisco Lira
 StudentID: 0886349
 Platform (Mac or PC): PC
 Language (C or C++): C++
 Project: Final Project
 07/25/19
 CIS054 C/C++ Programming
 Copyright © 2019 Francisco Lira. All rights reserved.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main() {
    ifstream infile;
    string line; //for reading line from file
    
    // string FileName
    char fileName[] = "|/Users//francisco.lira//Desktop//FirstNames2015.txt"; // input file name
    string searchName; // to store name to search
    string boyName, girlName; // to store boy name & girl name
    bool boyDone = false; // if a boy name is encountered or not
    bool girlDone = false; // if a girl name is encountered or not
    
    // user input for name to be searched
    cout << "Enter a name to search: ";
    cin>>searchName;
    
    infile.open(fileName);
    int rank = 1; // initializwe rank to 1
    
    // open and real file
    if (infile.is_open())
    {
        while (getline(infile, line)) {
            // copy string line to character array str
            char str[1024];
            strcpy(str, line.c_str());
            // now tokenise char array to get two names
            char *pch;
            // extract boy name
            pch = strtok (str," .,-");
            boyName = pch;
            
            //strcasecmp
            // if boy name is not encountered already and it matches with a name in file
            if (!boyDone && strcmp(boyName.c_str(), searchName.c_str())==0){
                cout<< boyName << " is ranked "<<rank<<" in boy names"<<endl;
                boyDone = true;
            }
            
            // extract girl name
            pch = strtok (NULL," .'-");
            girlName = pch;
            girlName = girlName.substr(0,girlName.length());
            
            
            // if girl name is not encountered already and it matches with a name in file
            if (!girlDone && strcmp(girlName.c_str(), searchName.c_str())==0){
                cout<<girlName << " is ranked "<<rank<<" in girl names"<<endl;
                girlDone = true;
            }
            
            // if name found in both boys and girls name then return
            if(boyDone && girlDone){
                break;
            }
            rank++;
        }
        // if boy name was not found
        if(!boyDone){
            cout<< searchName <<" was not found for boys"<<endl;
        }
        // if girl name was not found
        if(!girlDone){
            cout<< searchName <<" was not found for girls"<<endl;
        }
        infile.close();
    } else
    {
        cout << "Sorry, we could not find the names file." << endl;
    }
    return 0;
    
}
