%{
#include <string.h>
#include <stdio.h>
int i=1;
FILE *fout1;
FILE *fout2;
%}

id         [a-z]
assign     "="
inum       [0-9]+
else       .
%%
{id}        {fprintf(fout1,"id %s\n",yytext);fprintf(fout2,"id\n");}
{assign}    {fprintf(fout1,"assign %s\n",yytext);fprintf(fout2,"assign\n");}
{inum}      {fprintf(fout1,"inum %s\n",yytext);fprintf(fout2,"inum\n");}
\n          {}
{else}      {i==2;}

%%
int main(){
    char s[100];
    fout1=fopen("1.txt","w+r");
    fout2=fopen("2.txt","w+r");
    yylex();
    fclose(fout1);
    fclose(fout2);
    FILE* fin=fopen("1.txt","rt");
    FILE* check=fopen("2.txt","rt"); 
    if(i==1)
    {
       while (fgets(s, 100, check) != NULL)
       { 
         if(!(strcmp("id\n",s)))
         { 
           fgets(s,100,check);
           if (!(strcmp("assign\n",s)))
           { 
            fgets(s,100,check); 
            if((strcmp("inum\n",s)==0)||(strcmp("id\n",s)==0))
            {
            }

            else
            { 
              i=2;
            }           
           }
           else
           {
              i=2;
           }
        }
        else
        { 
         i=2;
        }
       }
       fclose(check);
    }
    if(i==1)
    {
       while (fgets(s, 100, fin) != NULL) 
       {
          printf("%s",s);
       }
       printf("\n");
       fclose(fin);
    }
    else
       printf("vaild input\n");
    return 0;
}


