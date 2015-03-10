%{
	unsigned int count = 0; unsigned int i = 0; int start = 1;
%}
%x	tt
head	"{"
tail	"}"
space	" "
%%
{head}		{count++; ECHO;}
{tail}		{count--; ECHO;}
\n		{ECHO; BEGIN tt;}
\t              {;}
.		{ECHO;}

<tt>{head}	{for(i = 0; i < count; i++){ printf("\t");}; count++; ECHO;BEGIN INITIAL;}
<tt>{tail}      {count--;for(i = 0; i < count; i++){ printf("\t");}; ECHO;BEGIN INITIAL;}
<tt>\n		{for(i = 0; i < count; i++){ printf("\t");};ECHO;;}
<tt>{space}	{for(i = 0; i < count; i++){ printf("\t");};BEGIN INITIAL;}
<tt>\t		;
<tt>.		{for(i = 0; i < count; i++){ printf("\t");};ECHO;BEGIN INITIAL;}

%%
int main(int argc, char *argv[]) {

        yylex();
	
        return(0);
}

