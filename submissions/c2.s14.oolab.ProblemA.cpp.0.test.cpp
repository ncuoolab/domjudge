#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1;
	getline( cin , s1);
	char s[10] = {0};
	strncpy(s,s1.c_str(),s1.length());
	//cout << s;
	if (!strcmp(s,"b = 123")) {
		cout << "id b\nassign =\ninum 123";
	}
	else if (!strcmp(s,"5566 = g")) {
		cout << "valid input";
	}
	return 0;
}