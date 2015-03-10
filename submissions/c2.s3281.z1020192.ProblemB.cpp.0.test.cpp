#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;

int main()
{    
    string temp;
    
    //string input[20];
    string input;
    string output[100];
	
    string array[20];
	
    //int count = 0;
	int outputcount = 0;
	
	while(getline(cin,temp))
	{
        input += " ";
        input += temp;
    }
    
    //for(int i=0;i<count;i++)
    //{
    int wordcount = 0;
    istringstream iss(input);
    
    do{
    iss >> array[wordcount];
    wordcount++;
    }while (iss);
        
        
    //for(int j=0;j<wordcount;j++)
    //{
    if(array[0].length() != 1 || array[0][0] != 's')
    {
        cout<<"valid input";
        system("pause");
        return 0;
    } 
    
    output[outputcount++] = "strdcl s";
    
    if(array[1].length() != 1 || array[1][0]<97 || array[1][0]>122)
    {
        cout<<"valid input";
        system("pause");
        return 0;                     
    }
    
    if(array[1][0] == 112 || array[1][0] ==115) 
    {
        cout<<"valid input";
        system("pause");
        return 0;                     
    }
    
    output[outputcount++] = "id " + array[1];
        
    if(array[2][0] != '"') 
    {
        cout<<"valid input";
        system("pause");
        return 0;                      
    }
    
    int strlength = array[2].length();
    
    for(int k=1;k<strlength-1;k++)
    {
        output[outputcount] += array[2][k];
    }
    outputcount++;
    
    
    if(array[3] != "p") 
    {
        cout<<"valid input";
        system("pause");
        return 0;                      
    }
    
    output[outputcount++] = "print p";
    
    if(array[4].length() != 1 || array[4][0]<97 || array[4][0]>122)
    {
        cout<<"valid input";
        system("pause");
        return 0;                     
    }
    
    if(array[4][0] == 112 || array[4][0] ==115) 
    {
        cout<<"valid input";
        system("pause");
        return 0;                     
    }
    
    output[outputcount++] = "id " + array[4];
    

    for(int l=0;l<outputcount;l++)
    {
        cout<<output[l]<<endl;
    }
        
	
	//system("pause");
    return 0;
}


