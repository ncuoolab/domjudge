
%{
unsigned int charCount=0, wordCount=0;
%}

left  "{"
right "}"
%%
{left} {wordCount++;ECHO;}
{right} {ECHO;wordCount--;}
\n      {ECHO;for(charCount=wordCount;charCount>0;charCount--)printf("\t");}
\t       ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
