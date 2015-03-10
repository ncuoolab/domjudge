%{
	unsigned int count = 0; unsigned int i = 0;
%}
%x	tt
%x	spa
%x	situation1
head	"{"
tail	"}"
space	" "
%%
\t		        ;
{left}          {count++; ECHO; BEGIN situation1;}
{right}          {count--; ECHO; BEGIN situation1;}
\n              {ECHO; BEGIN situation2;}
.               {ECHO; BEGIN situation1;}


<situation1>{left}		{count++; ECHO;}
<situation1>{right}		{count--; ECHO;}
<situation1>\n	    	{ECHO; BEGIN situation2;}
<situation1>.		    	{ECHO;}
<situation2>{left}	{for(i = 0; i < count; i++){ printf("\t");}; count++; ECHO; BEGIN situation1;}
<situation2>{right}      {count--;for(i = 0; i < count; i++){ printf("\t");}; ECHO; BEGIN situation1;}
<situation2>{space}     ;
<situation2>\n		{for(i = 0; i < count; i++){ printf("\t");};ECHO;;}
<situation2>\t		;
<situation2>.		{for(i = 0; i < count; i++){ printf("\t");};ECHO; BEGIN situation1;}

%%
int main(int argc, char *argv[]) {

        yylex();
	
        return(0);
}

