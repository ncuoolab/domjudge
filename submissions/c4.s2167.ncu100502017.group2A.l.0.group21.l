%x comment
%{
unsigned int charCount=0, wordCount=0;
%}

line [^{}\n\t]+
left  "{"
right "}"
%%
{line} {for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;}
{left} {wordCount++;ECHO;}
{right} {wordCount--;for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;}
\n      {printf("\n");BEGIN comment;}
<comment>{left} {for(charCount=wordCount;charCount>0;charCount--)printf("\t");wordCount++;ECHO;BEGIN INITIAL;}
<comment>{right} {wordCount--;for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;BEGIN INITIAL;}
<comment>{line} {for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;}
<comment>/n  BEGIN INITIAL;
<comment>\t   ;
\t       ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
