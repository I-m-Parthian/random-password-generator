//
//  main.cpp
//  random password generator
//
//  Created by Parth on 31/05/17.
//  Copyright © 2017 Parth. All rights reserved.
//
#include <string>
#include<cmath>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include"base.cpp"
#include"copy.cpp"
using namespace std;

int main()
{
    int ch,ans=0;
    h_w::base ob;
    string a;
    do{
    cout<<"1-create password\n";
    cout<<"2- then again 2 for exit\n";
    cout<<"enter choice :";
    cin>>ch;
    switch(ch){
        case 1:
            ob.shuffle();           //function to generate random elements
            a=ob.password();            //function to generate random password
            cout<<"press 1 to copy to clipboard :";
            cin>>ch;
            if(ch==1){
                copyclip(a);            //for copying password to clipboard
            }
            break;
        case 2: break;
        default:cout<<"Wrong input\n";
    }
    cout<<"press 1 to continue";
        cin>>ans;
    }while(ans==1);
}



