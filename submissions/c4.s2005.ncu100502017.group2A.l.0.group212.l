
%{
unsigned int charCount=0, wordCount=0;
%}
left  "{"
right "}"
line ^s
%%
{left} {wordCount++;ECHO;}
{right} {wordCount--;for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;}
line      {for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;}
\t\n       ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
