
%{
unsigned int charCount=0, wordCount=0;
%}

left  "{"
right "}"
%%
{left} {wordCount++;ECHO;}
{right} {wordCount--;ECHO;}
\n      {printf("\n");for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;}
\t       ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
