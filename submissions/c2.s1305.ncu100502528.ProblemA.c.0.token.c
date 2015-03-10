#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <stdbool.h> 
#include <string.h> 
int inum(char **str)
{
    if(**str==' ')
    {
        (*str)++;
    }
    if(isdigit(**str))
    {
        while(isdigit(**str))
        {
            (*str)++;
        }
        return 1;
    }
    return 0;
}
int val(char **str)
{
    return id(str)|| inum(str);
}
int assign(char **str)
{
    if(**str==' ')
    {
        (*str)++;
    }
    if(**str=='=')
    {
        (*str)++;
        return 1;
    }
    return 0;
}
int id(char **str)
{
    if(**str==' ')
    {
        (*str)++;
    }
    if(isalpha(**str))
    {
        while(isalpha(**str))
        {
            (*str)++;
        }
        return 1;
    }
    return 0;
}
int stmt(char **str)
{
    int a=id(str);
    int b=assign(str);
    int c=val(str);
     return a&&b&&c;
}
int proc(char **str) 
{ 
    int s=stmt(str);
    if(s==1 && **str=='\0')
    {
     return 1;
    }
    return 0;
} 
int main() 
{ 
  char str[1024]={}; 
  char *pch=str; 
  char *pri=str;
  int isExpressError=1; 
  int partNumber=1; 
  gets(str);
  if(proc(&pri)==1)
  {

   printf("id ");
   while(isalpha(*pch))
   {
        printf("%c",*pch);
        pch++;
   }
    if(*pch==' ')
    {
        pch++;
    }
   printf("\nassign =\n");
   pch++;
    if(*pch==' ')
    {
        pch++;
    }
    if(isdigit(*pch))
    {
        printf("inum ");
        while(*pch!='\0')
        {
          printf("%c",*pch);
          pch++;
         }
    }
    if(isalpha(*pch))
    { 
        printf("id = ");
        while(*pch!='\0')
        {
          printf("%c",*pch);
          pch++;
         }
    }
  }
  else 
  {
        printf("valid input");
  }
  system("pause");
  return 0; 
} 
