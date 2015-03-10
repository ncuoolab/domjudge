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

void ScanLevel() {
    outputToken += "level;";
    string strValue(1,input.at(inputIndex++));
    outputValue += strValue;
    while(inputIndex != input.length() && input.at(inputIndex) >= '0' && input.at(inputIndex) <= '9') {
        string strValue(1,input.at(inputIndex++));
        outputValue += strValue;
    }
    outputValue += ";";
}

void ScanFirstName() {
    outputToken += "FirstName;";
    string strValue(1,input.at(inputIndex++));
    outputValue += strValue;
    while(inputIndex != input.length() && input.at(inputIndex) >= 'a' && input.at(inputIndex) <= 'z') {
        string strValue(1,input.at(inputIndex++));
        outputValue += strValue;
    }
    outputValue += ";";
}

void ScanLastName() {
    outputToken += "LastName;";
    while(input.at(inputIndex) == 'a' || (input.at(inputIndex) >= 'c' && input.at(inputIndex) <= 'z')) {
        string strValue(1,input.at(inputIndex++));
        outputValue += strValue;
    }
    outputValue += ";";
}

void ScanCid() {
    outputToken += "cid;";
    while(inputIndex != input.length() && input.at(inputIndex) >= '0' && input.at(inputIndex) <= '9') {
        string strValue(1,input.at(inputIndex++));
        outputValue += strValue;
    }
    outputValue += ";";
}

bool Scanner() {
    bool correctness = true;
    while(input.at(inputIndex) == ' ' || input.at(inputIndex) == '\r' || input.at(inputIndex) == '\n')
        inputIndex++;
    if(input.at(inputIndex) >= '0' && input.at(inputIndex) <= '9')
        ScanCid();
    else{
        if(input.at(inputIndex) == 'l' && (input.at(inputIndex+1) >= '0' && input.at(inputIndex+1) >= '9'))
            ScanLevel();
        else if((input.at(inputIndex) >= 'A' && input.at(inputIndex) <= 'Z'))
            ScanFirstName();
        else if(input.at(inputIndex) == 'a' || (input.at(inputIndex) >= 'c' && input.at(inputIndex) <= 'z'))
            ScanLastName();
        else if(input.at(inputIndex) == 'b') {
            outputToken += "battle;";
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
    if(t != "level")
        return false;
    getline(ss,t,';');
    index += t.length() + 1;
    if(t != "cid" && t != "FirstName")
        return false;
    if(t == "FirstName") {
        getline(ss,t,';');
        index += t.length() + 1;
        if(t != "LastName")
            return false;
    }
    getline(ss,t,';');
    index += t.length() + 1;
    if(t != "battle")
        return false;
    getline(ss,t,';');
    index += t.length() + 1;
    if(t != "cid" && t != "FirstName")
        return false;
    if(t == "FirstName") {
        getline(ss,t,';');
        index += t.length() + 1;
        if(t != "LastName")
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
    while(getline(cin, temp))
        input += temp;
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
    return 0;
}
