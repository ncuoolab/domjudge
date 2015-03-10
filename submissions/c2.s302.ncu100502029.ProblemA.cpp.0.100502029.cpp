#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;
string input = "";
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

bool Scanner() {
    bool correctness = true;
    while(input.at(inputIndex) == ' ')
        inputIndex++;
    if(input.at(inputIndex) >= '0' && input.at(inputIndex) <= '9')
        ScanDigits();
    else{
        if(input.at(inputIndex) >= 'a' && input.at(inputIndex) <= 'z') {
            outputToken += "id;";
            string strValue(1,input.at(inputIndex++));
            outputValue += strValue + ";";
        }
        else if(input.at(inputIndex) == '=') {
            outputToken += "assign;";
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
    if(t != "assign")
        return false;
    getline(ss,t,';');
    index += t.length() + 1;
    if(t != "inum" && t != "id")
        return false;
    if(index != token.length())
        return false;
    return true;
}

void showErrorMsg() {
    cout << "valid input";
}

int main() {
    getline(cin, input);
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
