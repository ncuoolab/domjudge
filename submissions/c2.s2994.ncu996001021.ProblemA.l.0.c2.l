%{
#include <stdio.h> 
#include <string.h>


char b='t';
struct NODE
{
    char *tokentype;
    char *token;
    struct NODE *next;
};

struct NODE *getnode()
{
    struct NODE *p;
    p=(struct NODE*)malloc(sizeof(struct NODE));
    return p;
}

struct NODE *head;
struct NODE *ptr;

void add(char *stype, const char *s,struct NODE **ptr)
{    
     int i=0;
     int j=0;
     while (s[i] != '\0') {
         i++;
     }

     char *ss;
     ss=(char*)malloc(i+1);

     for (j=0;j<=i;j++)
     {
       ss[j]=s[j];
     }
     ss[i+1]='\0';
     struct NODE *n;
     n=getnode();
     n->token=ss;
     n->tokentype=stype;
     (*ptr)->next=n;
     n->next=NULL;
     (*ptr)=n;
}
void show(struct NODE **p)
{  
  
   while((*p)->next)
   {  
    *p=(*p)->next;
    printf("%s %s\n",(*p)->tokentype,(*p)->token);
   }
}

char match_id(struct NODE **ptr)
{ 
  char r;
  if ( (*ptr)->tokentype!="id")
     r='f';
  else
     r='t';
  return r;
}

char match_assign(struct NODE **ptr)
{
  char r;
  if ( (*ptr)->tokentype!="assign")
     r='f';
  else
     r='t';
  return r;
}


char match_inum(struct NODE **ptr)
{
  char r;
  if ( (*ptr)->tokentype!="inum")
     r='f';
  else 
     r='t';
  return r;
}

char val(struct NODE **ptr)
{
  char r;
  char m_id;
  char m_inum;
  m_id=match_id(ptr);
  m_inum=match_inum(ptr);
  if (m_id=='f'&&m_inum=='f')
    r='f';
  else
    r='t';
  return r;
}


char stmt(struct NODE **ptr)
{ 
  char r;
  (*ptr)=(*ptr)->next;
  r=match_id(ptr);
//  printf("a,%c\n",r);
  
   if (r=='t')
   {
    (*ptr)=(*ptr)->next;
    r=match_assign(ptr);
//    printf("b,%c\n",r);
    if(r=='t')
    {
     (*ptr)=(*ptr)->next;
     r=val(ptr);
//     printf("c,%c\n",r);
    }
   }
   return r;
}


%}

id         [a-z]
assign     "="
inum       [0-9]+
else       .
%%
{id}        {add("id",yytext,&ptr);}
{assign}    {add("assign",yytext,&ptr);}
{inum}      {add("inum",yytext,&ptr);}
\n          {}
{else}      {b='f';}

%%
int main(){
    struct NODE *head;
    head=getnode();
    ptr=head;
    yylex();
    ptr=head;
    if (b=='t')
    {
     while(ptr->next!=NULL)
      {
       b=stmt(&ptr);
       if (b=='f')
        {
          break;
        }
      }
      
    }
//    printf("%c\n",b); 

   if (b=='t')
    {
      ptr=head;
      show(&ptr);
    }
   else
    {
     printf("valid input\n");
    } 
    return 0;
}
    
