#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int str_len=0;
    int tok_num=0;
    int index=0;
    int error_flag=0;
    char str[100];
    char gram[4]; //1:id 2:assign 3:inum
    char first[50];
    char second[50];
    char third[50];

    int Val_case = 0;
    gets(str);
    char *delim = " ";
	    char *pch;
    pch = strtok(str,delim);
    while (pch != NULL)     //���_�P�_token
    {
        //printf ("%s\n",pch);

        int i,j;
        int known_flag=0;

        if(strcmp(pch,"=")==0)  //�P�_�O�_������
        {
                if(tok_num<=2)       //�O���e�T��gram
                {
                    switch (tok_num)
                    {
                    case 0: {strcpy(first,pch);error_flag=1;};
                    break;
                    case 1: {strcpy(second,pch);};
                    break;
					case 2: {strcpy(third,pch);error_flag=1;};
                    break;
                    default: break;
                    }
                }
            known_flag=1;
        }

        for(i=0,j=0;pch[i]!='\0';i++)   //�P�_�O�_���Ʀr
        {
            if(isdigit(pch[i])==0)
            {
                break;
            }
        }
        if(pch[i]=='\0')
        {
            if(tok_num<=2)       //�O���e�T��gram
                {

                    switch (tok_num)
					{
                    case 0: {strcpy(first,pch);error_flag=1;};
                    break;
                    case 1: {strcpy(second,pch);error_flag=1;};
                    break;
                    case 2: {strcpy(third,pch);Val_case=2;};
                    break;
                    default: break;
                    }
                }
            known_flag=1;
        }

        if(known_flag==0)
        {
            for(i=0,j=0;pch[i]!='\0';i++)   //�P�_�O�_���p�g�^��
            {
            if(islower(pch[i])==0)
            {
                //printf("�o��J���O�p�g�^�� ���r��:%c\n ��m�b:%d\n",pch[i],i+1);
                break;
				            }
            }
            if(pch[i]=='\0')
            {

                known_flag=1;

                if(tok_num<=2)       //�O���e�T��gram
                {
                    switch (tok_num)
                    {
                    case 0: {strcpy(first,pch);};
                    break;
                    case 1: {strcpy(second,pch);error_flag=1;};
                    break;
                    case 2: {strcpy(third,pch);Val_case=1;};
                    break;
                    default: break;
                    }
                }

            }
			        }



        if(known_flag==0)       //�L�k�P�_
        {
            error_flag=1;
        }
        pch = strtok (NULL, delim); //���V�U�@�Ӫťդ��e���r��
        tok_num++;
    }

    if(tok_num!=3) //�S���T��token
    {
        error_flag=1;
    }

    if(error_flag==1)
    {
	        printf("invalid input\n");
    }
    else
    {
        printf("id %s\n",first);
        printf("assign %s\n",second);

        if(Val_case==1)
        {
            printf("id %s\n",third);
        }
        else if(Val_case==2)
        {
            printf("inum %s\n",third);
        }

    }

      fflush(stdin); // �M����J�w�İ�

      //system("PAUSE");
      return 0;



}
