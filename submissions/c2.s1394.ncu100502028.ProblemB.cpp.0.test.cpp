#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

string token_stream = "";
string token_value = "";
bool correct = true;

void scanner(string char_stream) {
    for (int i = 0; i < char_stream.length(); i++) {
        if (char_stream[i] == '"') {
            token_stream += "quote;";
            token_value += char_stream[i];
            token_value += ";";
            int temp = i + 1;
            while (char_stream[temp] != '"') {
                if ((char_stream[temp] >= 'a' && char_stream[temp] <= 'z') || (char_stream[temp] >= 'A' && char_stream[temp] <= 'Z') || (char_stream[temp] >= '0' && char_stream[temp] <= '9')) {
                    token_value += char_stream[temp];
                    temp++;
                }
                else if (char_stream[temp] = ' ') {
                    temp++;
                    correct = false;
                }
            }
            token_value += ";";
            token_stream += "string;";
            i = temp;
            token_stream += "quote;";
            token_value += char_stream[i];
            token_value += ";";
        }
        else {
            if (char_stream[i] == 's') {
                token_stream += "strdcl;";
                token_value += char_stream[i];
                token_value += ";";
            }

            else if ((char_stream[i] >= 'a' && char_stream[i] <= 'o') || (char_stream[i] == 'q') || (char_stream[i] == 'r') || (char_stream[i] >= 't' && char_stream[i] <= 'z')) {
                token_stream += "id;";
                token_value += char_stream[i];
                token_value += ";";
            }

            else if (char_stream[i] == 'p') {
                token_stream += "print;";
                token_value += char_stream[i];
                token_value += ";";
            }
            /*else
                correct = false;*/
        }
    }
}

bool parser() {
    int index = 0;
    stringstream ss(token_stream);
    string t = "";

    getline(ss,t,';');
    index += t.length() + 1;
    if (t != "strdcl")
        return false;

    getline(ss,t,';');
    index += t.length() + 1;
    if (t != "id")
        return false;

    getline(ss,t,';');
    index += t.length() + 1;
    if (t != "quote")
        return false;

    getline(ss,t,';');
    index += t.length() + 1;
    if (t != "string")
        return false;

    getline(ss,t,';');
    index += t.length() + 1;
    if (t != "quote")
        return false;

    getline(ss,t,';');
    index += t.length() + 1;
    if (t != "print")
        return false;

    getline(ss,t,';');
    index += t.length() + 1;
    if (t != "id")
        return false;

    if(index != token_stream.length())
        return false;
    return true;
}

void lexicalError() {
    cout << "valid input" << endl;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        scanner(line);
    }

    if (correct == true) {
            if (parser()) {
                int index = 0;
                stringstream ss(token_value);
                string t = "";

                getline(ss,t,';');
                cout << "strdcl " << t << endl;
                index += t.length() + 1;

                getline(ss,t,';');
                cout << "id " << t << endl;
                index += t.length() + 1;

                getline(ss,t,';');
                cout << "quote " << t << endl;
                index += t.length() + 1;

                getline(ss,t,';');
                cout << "string " << t << endl;
                index += t.length() + 1;

                getline(ss,t,';');
                cout << "quote " << t << endl;
                index += t.length() + 1;

                getline(ss,t,';');
                cout << "print " << t << endl;
                index += t.length() + 1;

                getline(ss,t,';');
                cout << "id " << t << endl;
                index += t.length() + 1;
            }
            else
                lexicalError();
    }
    else
        lexicalError();

    /*cout << token_stream << endl;
    cout << token_value << endl;*/
    system("pause");
	return 0;
}
