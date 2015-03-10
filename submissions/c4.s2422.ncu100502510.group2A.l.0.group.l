%{
int count=0; int i;
%}
left        "{"
left2       {left}[^\n]
left3       ^{left}
end         "\n"
space       " "+
leftend     "{"{end}
endspace    {leftend}{space}+
endt        {leftend}"\t"+
right       "}"
letter      [a-zA-Z]
digit       [0-9]
rightend    {end}{right}"\t"*
rightend2   {end}"\t"+"}""\t"*
dont        "/""/"{letter}*{space}*{digit}*{space}*
one         {left}.+{right}
end2        {end}"\t"+
%%
{dont}      {ECHO;}
{left}     {  
               ECHO;count++;
            }
{right}     {ECHO;count--;}
{endt}      {printf("{");
             
           
             count++;
             printf("\n");
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
{rightend2}  {  count--;
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
{end2}      {printf("\n");
                for(i=0;i<count;i++)
                {
                   printf("\t");
                }
            }
  
%%
int main(void){
     yylex();
     return(0);
}  

