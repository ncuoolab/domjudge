
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;

/*
int main()
{
    char temp;
    while(scanf("%c",&temp)!=0)
    {
        printf("%c",temp);                   
    }   

    return 0;

}
*/
    
int main()
{    
    string temp;
    
	string array[20][10];
	int count1 = 0;
	int count2 = 0;
	
	while(getline(cin,temp))
	{
        istringstream iss(temp);
        
        do{
            iss >> array[count1][count2++];
            cout<<iss;
        }while (iss);
        
        count1++;
        count2 = 0;
	}
	
	//int ccount = 0;
	//while(array[ccount]){
	//    cout<<array[ccount];
    //   ccount++;}
	
    return 0;
}


