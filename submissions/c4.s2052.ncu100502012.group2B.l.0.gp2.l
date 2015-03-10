%x COMMENT
Word			^[A-Z][a-zA-Z]*$
digit			([0-9]|[1-9][0-9]|2[0-4][0-9]|25[0-5]|1[0-9][0-9])	
IP			^{digit}"\."{digit}"\."{digit}"\."{digit}$
Email			^[a-zA-Z0-9]+"\@"[a-zA-Z0-9]+["\."[a-zA-Z0-9]]+$
KeyWord			("IP Address"|"Word"|"Email Address")	
eol			.
%%
"//"			{BEGIN COMMENT;}
<COMMENT>{KeyWord}	{printf("--");ECHO; printf("--\n");}
<COMMENT>"\n"		{BEGIN INITIAL;}

{Word}			{ECHO; printf("w");}
{IP}			{ECHO; printf("i");}
{Email}			{ECHO; printf("e");}
.			;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

