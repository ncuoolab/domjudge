%{
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int tabcounter = 0;
bool iscommet = 0;
%}

%option noyywrap

l_brace         [{]
r_brace         [}]
line            .[*|" "]*[\n]

%%
l_brace         {tabcounter++;}
r_brace         {tabcounter--;}
line            {
                        cout << tabcounter << endl;
                        for(int i = 0 ; i < tabcounter ; i++)
                                cout << "\t";
                        
                        ECHO;
                }
                

%%

int main(int argc, char *argv[])
{
    yylex();
    cout << "tabcounter: " << tabcounter << endl;
    return 0;
}
