%{
int count=0; int i;
%}
left        "{"
left2       {left}[^\n]
end         "\n"
space       " "+
leftend     "{"{end}
endspace    {leftend}{space}
endt        {leftend}"\t"
right       "}"
rightend2    {right}$
letter      [a-zA-Z]
digit       [0-9]
rightend    {end}{right}
dont        "/""/"{letter}*{space}*{digit}*{space}*
one         {left}.+{right}
%%
{dont}      {ECHO;}
{left}      {printf("\n");
            for(i=0;i<count;i++)
                {
                   printf("\t");
                }
            printf("{");
            printf("\n");
             count++;
            for(i=0;i<count;i++)
                {
                   printf("\t");
                }

            }
{endspace}  {printf("{");
             printf("\n");
             count++;
                for(i=0;i<count;i++)
                {
                   printf("\t");
                }
            }
{endt}      {printf("{");
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
{rightend2}  {printf("\n");
             count--;
              for(i=0;i<count;i++)
                {
                   printf("\t");
                }
              printf("}");
              }
             
%%
int main(void){
     yylex();
     return(0);
}  

