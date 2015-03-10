%{
%}
id        [0-9]
id1       [1-9][0-9]
id4       "1"[0-9][0-9]
id2       "2"[0-4][0-9]
id3       "25"[0-5]
ip        {id4}|{id1}|{id2}|{id3}|{id} 
%%
{ip}"."{ip}"."{ip}"."{ip}[ ]  {ECHO;printf("\n");}
\n             ;
.              ;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
