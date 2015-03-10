a	[0-9]
b	[1-9][0-9]
c	[1][0-9][0-9]
d	[2][0-4][0-9]
e 	[2][5][0-5] 
ip	[{a}{b}{c}{d}{e}]"."[{a}{b}{c}{d}{e}]"."[{a}{b}{c}{d}{e}]"."[{a}{b}{c}{d}{e}]
%% 
{ip}	{ECHO;printf("\n");} 
.|\n	; 
%% 
int main(int argc, char *argv[]){
		yylex();
		return 0;
}
