#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;

int main()
{    
    string temp;
    
    string allstring;
    
    string input;
    string output[100];
	
    string array[20];
	
	int outputcount = 0;
	
	while(getline(cin,temp))
	{
        input += " ";
        input += temp;
    }
    
    int wordcount = 0;
    istringstream iss(input);
    
    do{
    iss >> array[wordcount];
    wordcount++;
    }while (iss);
    
    for(int t=0;t<wordcount;t++)
    {
        allstring+=array[t];
    }
    
        
    if(allstring[0] != 'a')
    {
        cout<<"valid input";
        system("pause");
        return 0;
    } 
    
    output[outputcount++] = "strdcl s";
    
    if(allstring[1] <97 || allstring[1] >122)
    {
        cout<<"valid input";
        system("pause");
        return 0;                     
    }
    
    if(allstring[1] == 112 || allstring[1] ==115) 
    {
        cout<<"valid input";
        system("pause");
        return 0;                     
    }
    
    output[outputcount++] = "id " + allstring[1];
        
    if(allstring[2] != '"') 
    {
        cout<<"valid input";
        system("pause");
        return 0;                      
    }
    
    int thispos = 3;
    while(allstring[thispos] != '"')
    {
        output[outputcount] += allstring[thispos];
        thispos++;                           
    }
    outputcount++;
    thispos++;
    
    if(array[thispos++] != "p") 
    {
        cout<<"valid input";
        system("pause");
        return 0;                      
    }
    
    output[outputcount++] = "print p";
    
    if(allstring[thispos] <97 || allstring[thispos] >122)
    {
        cout<<"valid input";
        system("pause");
        return 0;                     
    }
    
    if(allstring[thispos] == 112 || allstring[thispos] ==115) 
    {
        cout<<"valid input";
        system("pause");
        return 0;                     
    }
    
    output[outputcount++] = "id " + allstring[thispos];
    

    for(int l=0;l<outputcount;l++)
    {
        cout<<output[l]<<endl;
    }
        
    return 0;
}
