IPAddress ^{IP}"."{IP}"."{IP}"."{IP}
IP {IP1}|{IP2}|{IP3}|{IP4}|{IP5} 
IP1 [1-9][0-9] 
IP2 [0-9] 
IP3 1[0-9][0-9] 
IP4 2[0-4][0-9] 
IP5 25[0-5] 

%% 

{IPAddress} { printf("%s\n", yytext); }  
.|\n	;

%%
 
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
