%x	         COMMENT
digit	   	 ([0-9]|[1-9][0-9]|2[0-4][0-9]|25[0-5]|1[0-9][0-9])
IP	   	 {digit}"\."{digit}"\."{digit}"\."{digit}
eof		 .|\n
%%
"\-"	   	 {BEGIN COMMENT;}
<COMMENT>.       ;
<COMMENT>\n	 {BEGIN INITIAL;}
{IP}       	 {ECHO;printf("\n");}
{eof}		
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}


