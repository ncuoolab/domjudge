#include <string>
#include <iostream>
using namespace std;

int main()
{

     string input;
     string output="";
     string s="";
     string temp="";
     while(getline(cin,temp))
	 {
        input+=temp;
     }

     int x=0;

     for(int i = 0;i<input.size();i++)
	 {
         if(input[i]!=' '&&input[i]!='\n'&&input[i]!='\r')
		 {
				if(x==0&&input[i]=='s')
				 {
					output=output+"strdcl s\n";
					x++;
				}
				else if(x==1&&(('a'<=input[i]&&input[i]<='o')||('q'<=input[i]&&input[i]<='r')||('t'<=input[i]&&input[i]<='z')))
				{
                    output=output+"id "+input[i]+"\n";
                    x++;
                }
                else if(x==2&&(input[i]=='"'||input[i]=='\\'))
				{
                    output=output+"quote "+input[i]+"\n";
                    x++;
                }

                else if(x==3&&(input[i]=='"'||input[i]=='\\'))
				{
                    output=output+"string "+s+"\n";
                    output=output+"quote "+input[i]+"\n";
                    x++;
                }
                else if(x==3&&(input[i]!='"'&&input[i]!='\\')&&i<(input.size()-1)&&(('a'<=input[i]&&input[i]<='z')||('A'<=input[i]&&input[i]<='Z')||('0'<=input[i]&&input[i]<='9')))
				{
                    s=s+input[i];
                }
                else if(x==4&&input[i]=='p')
				{
					x++;
                    output=output+"print p\n";
                }
				else if(x==5&&(('a'<=input[i]&&input[i]<='o')||('q'<=input[i]&&input[i]<='r')||('t'<=input[i]&&input[i]<='z')))
				{
                    output=output+"id "+input[i]+"\n";
                    x++;
                }
                else
				{
                    output="valid input\n";
                    break;
                }
         }
     }

     cout<<input;
 return 0;
 
}
