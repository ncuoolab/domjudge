%x comment
%{
unsigned int charCount=0, wordCount=0;
%}

line [^{}\n\t]+
left  "{"
right "}"
%%
\n     {ECHO;BEGIN comment;}
{line} {ECHO;}
{left} {wordCount++;ECHO;}
{right} {wordCount--;ECHO;}
\t       ;
<comment>{left} {for(charCount=wordCount;charCount>0;charCount--)printf("\t");wordCount++;ECHO;BEGIN INITIAL;}
<comment>{right} {wordCount--;for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;BEGIN INITIAL;}
<comment>{line} {for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;BEGIN INITIAL;}
<comment>\n   {for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;}
<comment>\t   ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
