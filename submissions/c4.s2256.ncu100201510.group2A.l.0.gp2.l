%{
#include <stdio.h>
#include <iostream>
using namespace std;

int tabcounter = 0;
bool iscommet = 0;
%}

%option noyywrap

%%
^[" "]*             {cout << "\t";}
^[\t]+              {cout << "\t";}

[{]             {
                        for(int i = 0 ; i < tabcounter ; i++)
                        {
                                cout << "\t";
                        }
                        tabcounter = tabcounter + 1;
                        ECHO;
                        //printf("%d" , tabcounter);
                }
[}]             {
                        tabcounter = tabcounter - 1;
                        for(int i = 0 ; i < tabcounter ; i++)
                        {
                                cout << "\t";
                        }
                        ECHO;
                        //printf("%d" , tabcounter);
                }

.+[{]    {
                        //printf("%d\n" , tabcounter);
                        for(int i = 0 ; i < tabcounter ; i++)
                        {
                                cout << "\t";
                        }
                        tabcounter = tabcounter + 1;
                        //cout << " **line** ";
                        ECHO;
                }
.+            {        
                        //printf("%d\n" , tabcounter);
                        for(int i = 0 ; i < tabcounter ; i++)
                        {
                                cout << "\t";
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
