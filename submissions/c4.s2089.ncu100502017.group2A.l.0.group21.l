
%{
unsigned int charCount=0, wordCount=0;
%}
line [^{}]+
left  "{"
right "}"
%%
{line} {for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;}
{left} {wordCount++;ECHO;}
{right} {wordCount--;for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;}
\n      ;
\t       ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
