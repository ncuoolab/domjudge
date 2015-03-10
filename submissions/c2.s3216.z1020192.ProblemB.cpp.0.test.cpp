#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;

int main()
{    
    string temp;
    
	string array[20];
	int count = 0;
	
	while(getline(cin,temp))
	{
                            
 
     /*
        count = 0;
        istringstream iss(temp);
        
        do{
            iss >> array[count];
            //cout << array[count];
            count++;
            
        }while (iss);
        
        
        if(array[0].length() != 1 || array[0][0] != 's')
        {
            cout<<"invalid input";
            system("pause");
            return 0;
        } 
        
        cout<<"strdcl s"<<endl;
        
        if(array[1].length() != 1 || array[1][0]<97 || array[1][0]>122)
        {
            cout<<"invalid input";
            system("pause");
            return 0;                     
        }
        
        if(array[1][0] == 112 || array[1][0] ==115) 
        {
            cout<<"valid input";
            system("pause");
            return 0;                     
        }
        
        cout<<"id "<<array[1][0]<<endl;
        /*
        for(int i=2;i<count;i++)
        {
            if()
             else if(array[i][0] == 'p')
                 cout<<"print p"<<endl;
             
             else{
                  cout<<"id "<<array[i][0]<<endl;
                  }
             }
             else
             {
                 for(int j=0;j<array[i].length();j++)
                 {
                     if(array[i][])
                 }
             }
        }
        */
	}
	//system("pause");
    return 0;
}


