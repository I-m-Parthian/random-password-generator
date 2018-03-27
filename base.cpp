//
//  base.cpp
//  random password generator
//
//  Created by Parth on 05/06/17.
//  Copyright © 2017 Parth. All rights reserved.
//
#include<iostream>
#include<cmath>
using namespace std;
namespace h_w {
    
    class base
    {
    private:
        char arr[94] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','0', '1', '2', '3', '4', '5', '6', '7', '8', '9','`','~','!','@','#','$','%','^','&','*','(',')','-','_','=','+','{','}','[',']', '|', '\\', '\'', ';', ':', '"', '/', '?', '.', '>', ',', '<'};
        int size=94;
       // long int a,b,c,seed,m,x;
    public:
        void swap(char &a,char &b)
        {
            char tmp;
            tmp=a;
            a=b;
            b=tmp;
        }
        void shuffle()          // generate random elements
        {
            for(int i=size-1;i>0;i--)
            {
               // srand((unsigned)time(NULL));
                time_t()%size;
                int j= rand()%(i+1);
                swap(arr[i],arr[j]);
            }
        }
        int check(string str)           // proper validation
        {
            int A=0,a=0,s=0,d=0;
          // cout<<"check = "<<str<<endl;
            for(int i=0;i<str.size();i++)
            {
                if(str[i]<64&& str[i]<91)
                {
                    A=1;
                    break;
                }
            }
            for(int i=0;i<str.size();i++)
            {
                if(str[i]>96&& str[i]<123)
                {
                    a=1;
                    break;
                }
            }
            for(int i=0;i<str.size();i++)
            {
                if(str[i]>47&&str[i]<58)
                {
                    d=1;
                    break;
                }
            }
            for(int i=0;i<str.size();i++)
            {
                if((str[i]>31&&str[i]<48)||(str[i]>57&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<127))
                {
                    s=1;
                    break;
                }
            }
            if(A==1&&a==1&&d==1&&s==1)
                return 1;
            else
                return 0;
        }
        
        string password()               //password generator
        {
            int n,random;
            string str;
            //cout<<"size of array ="<<size<<endl;
            cout<<"password length :";
            cin>>n;
            do{
            srand((unsigned)time(NULL));
                str="";
                for(int i=0;i<n;i++)
                {
                    random=rand()%size;
                    //cout<<arr[random];
                    str=str+arr[random];
                }
                  //cout<<str<<endl;
            }while(!check(str));
            cout<<"password is "<<str<<endl;
            return str;
            
        }
        
    };
}
