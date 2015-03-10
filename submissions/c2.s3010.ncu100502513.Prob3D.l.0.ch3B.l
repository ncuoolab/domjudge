dot    "."
IP1    [0-9]
IP2    [1-9][0-9]
IP3    1[0-9][0-9]
IP4    2[0-4][0-9]
IP5    2[5][0-5]
IP     ^({IP1}|{IP2}|{IP3}|{IP4}|{IP5}){dot}({IP1}|{IP2}|{IP3}|{IP4}|{IP5}){dot}({IP1}|{IP2}|{IP3}|{IP4}|{IP5}){dot}({IP1}|{IP2}|{IP3}|{IP4}|{IP5})$

%%
{IP}    {ECHO;   printf("\n");}
.|\n    ;
%%

int main(int argc, char *argv[]) {
	yylex();
	return(0);
}


