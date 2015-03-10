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
                        tabcounter = tabcounter + 1;
                        ECHO;
                        //printf("%d\n" , tabcounter);
                }
[}]             {
                        tabcounter = tabcounter - 1;
                        ECHO;
                        //printf("%d\n" , tabcounter);
                }
[\ |^]+[\n][{]     {        
                        tabcounter = tabcounter + 1;
                        //printf("%d\n" , tabcounter);
                        for(int i = 0 ; i < 4*tabcounter ; i++)
                        {
                                cout << " ";
                        }
                        cout << " **line** ";
                        ECHO;
                }
[\ |^]+[\n]        {        
                        //printf("%d\n" , tabcounter);
                        for(int i = 0 ; i < 4*tabcounter ; i++)
                        {
                                cout << " ";
                        }
                        cout << " **line** ";
                        ECHO;
                }


%%

int main(int argc, char *argv[])
{
    yylex();
    //printf("tabcounter: %d\n" , tabcounter);
    return 0;
}
