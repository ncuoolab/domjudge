#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 void split(char **arr, char *str, const char *del)
 {
    char *s = strtok(str, del);
    while(s != NULL)
    {
        *arr++ = s;
		s = strtok(NULL, del);
        
    }
    
}
int main ()
{
    char str[20];
    printf("Input:\n");
    //gets(str);
    fgets(str, 20, stdin);
    //scanf("%s",str);
    const char *del = " ";
    char* arr[20];
    char* buff[20];
    
    memset(arr, 0, 20);
    memset(buff, 0, 20);
	
    split(arr, str, del);
    int i=0;
    int j=0;
    int k=0;
    int num=0;
    int flag=0;
    /*int id=0;
    int assign=0;
    int inum=0;*/
    
	while(arr[i]!=0){
		buff[i]=(char*)malloc(20);
		if(*arr[i] >=97 && *arr[i]<=122){
			//printf("id %c\n",*arr[i]);
			//printf("%d\n",sizeof(arr[i]));
			while(*(arr[i]+j)!='\0'){
				num++;
				j++;
			}
			if(num>1){
				flag=1;
			}
			sprintf(buff[i],"id %c\n",*arr[i]);
			//id=1;
		}else if(*arr[i] == 61){
			//printf("assign %c\n",*arr[i]);
			sprintf(buff[i],"assign %c\n",*arr[i]);
			//assign=1;
		}else if(*arr[i] >=48 && *arr[i]<=57){
			//inum=1;
			//printf("%d\n",sizeof(arr[i]));
			while(*(arr[i]+j)!='\0'){
				if(*(arr[i]+j)=='.'){
					flag=1;
					//printf("Vaild Input\n");
					//break;
				}
				j++;
			}
			if(flag!=1){
				sprintf(buff[i],"inum %s\n",arr[i]);
			}
		}

		i++;
	}	
		printf("Output:\n");
		if(flag==1){
			printf("Vaild Input\n");
			flag=0;
		}else if(flag==0){
			while(buff[k]!=0){
				printf("%s",buff[k]);
				k++;
			}
		}
	system("pause");
    return 0;
}

