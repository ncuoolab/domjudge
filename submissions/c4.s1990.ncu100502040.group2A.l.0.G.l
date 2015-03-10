%{
	unsigned int count = 0; unsigned int i = 0;
%}
%x	tt
head	"{"
tail	"}"
%%
{head}		{count = count + 1; ECHO;}
{tail}		{count = count - 1; ECHO;}
\n		{printf("\n"); BEGIN tt;}
\t		;
.		{ECHO;}
<tt>{head}	{for(i = 0; i < count; i++){ printf("\t");}; count++; ECHO;BEGIN INITIAL;}
<tt>{tail}      {count--;for(i = 0; i < count; i++){ printf("\t");}; ECHO;BEGIN INITIAL;}
<tt>\n		{ECHO; BEGIN INITIAL;}
<tt>\t		{for(i = 0; i < count; i++){ printf("\t");};BEGIN INITIAL;}
<tt>.		{for(i = 0; i < count; i++){ printf("\t");};ECHO;BEGIN INITIAL;}

%%
int main(int argc, char *argv[]) {

        yylex();
	
        return(0);
}

