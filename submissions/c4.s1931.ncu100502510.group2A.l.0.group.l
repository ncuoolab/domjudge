%{
int count=0; int i;
%}
left        "{"
end         "\n"
space       " "+
leftend     "{"{end}
endspace    {leftend}{space}
right       "}"
letter      [a-zA-Z]
digit       [0-9]
rightend    {end}{right}
dont        "/""/"{letter}*{space}*{digit}*{space}*

%%
{dont}      {ECHO;}
{left}      {ECHO;count++;}
{endspace}  {printf("{");
             printf("\n");
             count++;
                for(i=0;i<count;i++)
                {
                   printf("\t");
                }
            }

{rightend}  {count--;
             printf("\n");
                for(i=0;i<count;i++)
                {
                   printf("\t");
                }
             printf("}");
            }
{end}       {ECHO;          
                for(i=0;i<count;i++)
                {
                   printf("\t");
                }
            }
%%
int main(voud){
     yylex();
     return(0);
}  

