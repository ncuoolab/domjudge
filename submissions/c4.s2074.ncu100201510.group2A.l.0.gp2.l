%{
#include <stdio.h>
#include <iostream>
using namespace std;

int tabcounter = 0;
bool iscommet = 0;
%}

%option noyywrap

%%

[{]             {
                        for(int i = 0 ; i < 4*tabcounter ; i++)
                        {
                                cout << " ";
                        }
                        tabcounter = tabcounter + 1;
                        ECHO;
                        //printf("%d\n" , tabcounter);
                }
[}]             {
                        tabcounter = tabcounter - 1;
                        for(int i = 0 ; i < 4*tabcounter ; i++)
                        {
                                cout << " ";
                        }
                        ECHO;
                        //printf("%d\n" , tabcounter);
                }
.+[{]               {        
                        //printf("%d\n" , tabcounter);
                        for(int i = 0 ; i < 4*tabcounter ; i++)
                        {
                                cout << " ";
                        }
                        tabcounter = tabcounter + 1;
                        //cout << " **line** ";
                        ECHO;
                }
.+               {        
                        //printf("%d\n" , tabcounter);
                        for(int i = 0 ; i < 4*tabcounter ; i++)
                        {
                                cout << " ";
                        }
                        //cout << " **line** ";
                        ECHO;
                }


%%

int main(int argc, char *argv[])
{
    yylex();
    //printf("tabcounter: %d\n" , tabcounter);
    return 0;
}
