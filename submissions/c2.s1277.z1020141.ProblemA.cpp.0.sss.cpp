#include <iostream>
#include <string>
//#include <cstring> 

using namespace std;
int errorCount = 0, a = 0,OK = 0, b=0;
char nextChar = ' ';
string name;
char t1, t2, t3;
char t5[500];

void error();
void advance();
void Val();
void Stmt();
void inum();
void end();
void idend();

void error()
{
	errorCount++;
}
void advance()
{
	nextChar = name[a++];
}
void inum()
{
if (nextChar >= '0' && nextChar <= '9')
{
	t5[b] = nextChar ;
	b++;
	advance();
	end();
}
}
void end()
{
	if (nextChar == '\0')
		OK++;
	else if (nextChar >= '0' && nextChar <= '9')
		inum();
	else
		error();
}
void idend()
{
	if (nextChar >= '0' && nextChar <= '9')
		error();
}
void assignend()
{
	if (nextChar == '=')
		error();
}
void Val()
{
	while (nextChar == ' ')
		advance();
	if (nextChar >= 'a' && nextChar <= 'z' || nextChar >= 'A' && nextChar <= 'Z')
	{
		t3 = nextChar;
		advance();
		idend();
	}
		else if (nextChar >= '0' && nextChar <= '9')
	{
		t5[b] = nextChar ;
		b++;
		advance();
		end();
	}
	else
		error();
}
void Stmt()
{
	/*while (nextChar == ' ')
		advance();*/
	if (nextChar >= 'a' && nextChar <= 'z' || nextChar >= 'A' && nextChar <= 'Z') //match id
	{
		t1 = nextChar;
		advance();
		while (nextChar == ' ')
			advance();
	if (nextChar == '=')
	{
		t2 = nextChar;
		advance();
		assignend();
		Val();
	}
	else
		error();
}
else
	error();
}
int main()
{
	//cout << "input: ";// input為 a = 12 或是 r=r 皆可
	getline(cin, name);
	Stmt();
	if (t3 == '\0' && errorCount == 0) //match id assign inum
		cout << "id " << t1 << "\nassign =" << "\ninum " << t5 << endl;
	else if (OK > 0 && errorCount == 0)//match id assign id
		cout << "id " << t1 << "\nassign =" << "\nid " << t3 << endl;
	else
		cout << "vaild input";

	system("pause");
	return 0;
}