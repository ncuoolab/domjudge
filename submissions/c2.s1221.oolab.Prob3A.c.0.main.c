#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
void proc(char*);
void stmt(char*);
void val(char*);
void result(char*);
void error();
int match(char*,int);
bool isAssign(char);

void test(char*);
int middle=0;
int main()
{

    char input_data[100];
    char *input;
    input=input_data[100];
    gets(input);
    //puts(input);

   /* for(i;i<100;i++)
    {
        if(input[i]!='\0')
        {
            printf("%c\n",input[i]);
        }

    }*/
   // middle=3;
   // result(input);


    proc(input);

    return 0;
}
void test(char* data)
{
    data++;
}

void proc(char *data)
{
    // watch the next char
    if(isalpha(*data) || isAssign(*data) || isdigit(*data)  )
    {
        stmt(data);
    }
    else if(*data=='\0')
    {

    }
    else
    {
        error();
    }


}

void stmt(char *data)
{
    if(isalpha(*data))
    {
        if(match(data,0)!=true)
        {
            //printf("first");
            error();
        }

        else if(match(data+=middle,1)!=true)
        {
            //printf("second");
            error();
        }
        else
        {
            data++;
            val(data);
        }

    }
     else
        error();

}
void val(char *data)
{

    if(isalpha(*data))
    {
        printf("cha");
        if(match(data,3)!=true)
        {
            //printf("val first");
            error();
        }
        else
        {
             result(data-=middle+1);
            result(data);
            printf("id ");
            data+=middle+1;
            while(*data!='\0')
            {
                printf("%c",*data);
                data++;

            }
        }
    }
    else if(isdigit(*data))
    {
        if(match(data,2)!=true)
        {
            //printf("val second");
            error();
        }
        else
        {
            result(data-=middle+1);
            printf("inum ");
            data+=middle+1;
            while(*data!='\0')
            {
                printf("%c",*data);
                data++;

            }

        }
    }



}



//0: char 1: assign 2: id

int match(char *data,int i)
{
    bool state=true;
    switch(i)
    {
    case 0:
        while(isAssign(*data)==false)
        {
            if(isalpha(*data)==false)
            {

                state=false;
            }
            data++;
            middle++;
        }
        break;
    case 1:
        if(!isAssign(*data))
        {
            state=false;
        }
        break;
    case 2:
        if(!isdigit(*data))
        {
            state=false;
        }
        break;
    case 3:
        while((*data)!='\0')
        {
            if(isalpha(*data)==false)
            {
                state=false;
            }
            data++;
        }
        break;
    }
    return state;
}




bool isAssign(char data)
{
    if(data!='=')
    {
        return false;
    }
    else
        return true;

}
void error()
{
    printf("valid input");
}
void result(char *data)
{
    int i=0;
    printf("id ");
    for(i;i<middle;i++)
    {
        printf("%c",*data);
        data++;
    }
    data++;
    printf("\nassign =\n");
}




    /*    char *input;
    char *spilt=" ";
    input=&input_data;
    */
    /*while (input != NULL)
    {
    printf ("%s\n",input);
    input = strtok (NULL, spilt);
    }
    while(input!=NULL)
    {
        printf ("%s\n",input);
    }*/
