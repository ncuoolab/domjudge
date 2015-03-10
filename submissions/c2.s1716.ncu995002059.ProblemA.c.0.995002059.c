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
    while (pch != NULL)     //不斷判斷token
    {
        //printf ("%s\n",pch);

        int i,j;
        int known_flag=0;

        if(strcmp(pch,"=")==0)  //判斷是否為等號
        {
                if(tok_num<=2)       //記錄前三個gram
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

        for(i=0,j=0;pch[i]!='\0';i++)   //判斷是否為數字
        {
            if(isdigit(pch[i])==0)
            {
                break;
            }
        }
        if(pch[i]=='\0')
        {
            if(tok_num<=2)       //記錄前三個gram
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
            for(i=0,j=0;pch[i]!='\0';i++)   //判斷是否為小寫英文
            {
            if(islower(pch[i])==0)
            {
                //printf("這輸入不是小寫英文 有字符:%c\n 位置在:%d\n",pch[i],i+1);
                break;
				            }
            }
            if(pch[i]=='\0')
            {

                known_flag=1;

                if(tok_num<=2)       //記錄前三個gram
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



        if(known_flag==0)       //無法判斷
        {
            error_flag=1;
        }
        pch = strtok (NULL, delim); //指向下一個空白之前的字串
        tok_num++;
    }

    if(tok_num!=3) //沒有三個token
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

      fflush(stdin); // 清除輸入緩衝區

      //system("PAUSE");
      return 0;



}
