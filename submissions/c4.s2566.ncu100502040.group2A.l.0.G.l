%{
	unsigned int count = 0; unsigned int i = 0; int start = 1; int ini = 1;
%}
%x	tt
%x	spa
%x	next
head	"{"
tail	"}"
space	" "
word	^[a-zA-Z]
digit	^[0-9]
%%
\t		;
{head}          {count++; ECHO; BEGIN next;}
{tail}          {count--; ECHO; BEGIN next;}
\n              {ECHO; BEGIN tt;}
.               {ECHO; BEGIN next;}


<next>{head}		{count++; ECHO;}
<next>{tail}		{count--; ECHO;}
<next>\n		{ECHO; BEGIN tt;}
<next>.			{ECHO;}



<tt>{head}	{for(i = 0; i < count; i++){ printf("\t");}; count++; ECHO; BEGIN next;}
<tt>{tail}      {count--;for(i = 0; i < count; i++){ printf("\t");}; ECHO; BEGIN next;}
<tt>{space}     ;
<tt>\n		{for(i = 0; i < count; i++){ printf("\t");};ECHO;;}
<tt>\t		;
<tt>.		{for(i = 0; i < count; i++){ printf("\t");};ECHO; BEGIN next;}

%%
int main(int argc, char *argv[]) {

        yylex();
	
        return(0);
}

