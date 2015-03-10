digit1	[0-9]
digit2	[1-9]
digit3	[0-4]
digit4	[0-5]

a	{digit1}
b	{digit2}{digit1}
c	"1"{digit1}{digit1}
d	"2"{digit3}{digit1}
e 	"25"{digit4}
ip	{a}|{b}|{c}|{d}|{e}
%% 
{ip}"."{ip}"."{ip}"."{ip}[ ]	{ECHO;printf("\n");} 
.|\n	; 
%% 
int main(int argc, char *argv[]){
		yylex();
		return 0;
}
