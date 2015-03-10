#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;
string input = "";
string temp = "";
string outputToken = "";
string outputValue = "";
int inputIndex = 0;

void ScanDigits() {
    outputToken += "inum;";
    while(inputIndex != input.length() && input.at(inputIndex) >= '0' && input.at(inputIndex) <= '9') {
        string strValue(1,input.at(inputIndex++));
        outputValue += strValue;
    }
    outputValue += ";";
}

void ScanID() {
    outputToken += "id;";
    while(inputIndex != input.length() && ((input.at(inputIndex) >= 'a' && input.at(inputIndex) <= 'z') || (input.at(inputIndex) >= 'A' && input.at(inputIndex) <= 'z') || (input.at(inputIndex) == '_'))) {
        string strValue(1,input.at(inputIndex++));
        outputValue += strValue;
    }
    outputValue += ";";
}

bool Scanner() {
    bool correctness = true;
    while(input.at(inputIndex) == ' ')
        inputIndex++;
    if(input.at(inputIndex) >= '0' && input.at(inputIndex) <= '9')
        ScanDigits();
    else{
        if((input.at(inputIndex) >= 'a' && input.at(inputIndex) <= 'z') || (input.at(inputIndex) >= 'A' && input.at(inputIndex) <= 'z') || (input.at(inputIndex) == '_'))
            ScanID();
        else if(input.at(inputIndex) == '(') {
            outputToken += "lparenthesis;";
            string strValue(1,input.at(inputIndex++));
            outputValue += strValue + ";";
        }
        else if(input.at(inputIndex) == ')') {
            outputToken += "rparenthesis;";
            string strValue(1,input.at(inputIndex++));
            outputValue += strValue + ";";
        }
        else
            correctness = false;
    }
    return correctness;
}

bool Parser() {
    int index = 0;
    string token = outputToken;
    string t = "";
    stringstream ss(token);
    getline(ss,t,';');
    index += t.length() + 1;
    if(t != "id")
        return false;
    getline(ss,t,';');
    index += t.length() + 1;
    if(t != "lparenthesis")
        return false;
    getline(ss,t,';');
    index += t.length() + 1;
    if(t != "rparenthesis") {
        if(t != "inum" && t != "id")
            return false;
        getline(ss,t,';');
        index += t.length() + 1;
        if(t != "rparenthesis")
            return false;
    }
    if(index != token.length())
        return false;
    return true;
}

void showErrorMsg() {
    cout << "invalid input";
}

int main() {
    for(int i=0; i<4; i++) {
        getline(cin, temp);
        input += temp;
        temp = "";
    }
    bool scanOK = true;
    while(scanOK && inputIndex != input.length()) {
        scanOK = Scanner();
    }
    if(scanOK) {
        if(Parser()) {
            int tokenIndex = 0;
            int valueIndex = 0;
            while(tokenIndex != outputToken.length()) {
                while(outputToken.at(tokenIndex++) != ';')
                    cout << outputToken.at(tokenIndex-1);
                cout << " ";
                while(outputValue.at(valueIndex++) != ';')
                    cout << outputValue.at(valueIndex-1);
                cout << endl;
            }
        }
        else
            showErrorMsg();
    }
    else
        showErrorMsg();
    system("pause");
    return 0;
}
