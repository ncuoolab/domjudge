/*
 Please check if this is for Problem B.
 Regular Expression:
		strdcl s
		id [a-o|q|r|t-z]
		quote "\""
		string [a-z|A-Z|0-9]*
		print p
 Grammar:
		Proc -> Dcl Stmt $
		Dcl -> strdcl id Astring
		Astring -> quote string quote
		Stmt -> print id
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;

#define FLAG_TERMINAL (0x20)

#define TYPE_PROC (1)
// ==== TODO 1/6 Token Defs. Here, EXCEPT "TYPE_PROC" (root) ====
#define TYPE_DCL (2)
#define TYPE_ASTRING (3)
#define TYPE_STMT (4)
#define TYPE_STRDCL (FLAG_TERMINAL | 1)
#define TYPE_ID (FLAG_TERMINAL | 2)
#define TYPE_QUOTE (FLAG_TERMINAL | 3)
#define TYPE_STRING (FLAG_TERMINAL | 4)
#define TYPE_PRINT (FLAG_TERMINAL | 5)
#define TYPE_INVALID (FLAG_TERMINAL | 6)
// ==== End of Token Definition ====

#define TYPE_NONE (0xff) // stands for "lambda"



#ifndef __cplusplus
#define bool int
#endif



//#define NULL 0
struct myNode;
struct mySeparator;
typedef struct myNode{
	struct mySeparator *prevSep;
	struct mySeparator *nextSep;
	int type;
	char *content;
} MyNode;
typedef struct mySeparator{
	struct myNode *prevNode;
	struct myNode *nextNode;
} MySeparator; //doubly linked list-like structure

MySeparator* createSep(){
	MySeparator *tmp = (MySeparator*)malloc(sizeof(MySeparator));
	tmp->prevNode = tmp->nextNode = NULL;
	return tmp;
}
const char *EMPTY_STRING = "";
MyNode* createNode(int type, const char *content, MySeparator *prevSep, MySeparator *nextSep){
	MyNode *tmp = (MyNode*)malloc(sizeof(MyNode));
	if(prevSep==NULL){
		prevSep = createSep();
	}
	tmp->prevSep = prevSep;
	prevSep->nextNode = tmp;
	if(nextSep==NULL){
		nextSep = createSep();
	}
	tmp->nextSep = nextSep;
	nextSep->prevNode = tmp;

	tmp->type = type;
	if(content==NULL){
        tmp->content = (char*)malloc(sizeof(char));
        strcpy(tmp->content, EMPTY_STRING);
    }else{
        tmp->content = (char*)malloc(sizeof(char)*(strlen(content)+1));
        strcpy(tmp->content, content);
    }
	return tmp;
}

void replaceNodes(MySeparator *begin, MySeparator *end, MyNode *newHead, MyNode *newTail){
	//do not run memory freeing operations
	if(newHead==NULL || newTail==NULL){
		begin->nextNode = end->nextNode;
		if(begin->nextNode!=NULL)begin->nextNode->prevSep = begin;
		//"end" will not be used
	}else{
		begin->nextNode = newHead;
		end->prevNode = newTail;
		newHead->prevSep = begin;
		newTail->nextSep = end;
	}
}
MyNode* prevOf(MyNode *node){
    if(node==NULL)return NULL;
    else return node->prevSep->prevNode;
}
MyNode* nextOf(MyNode *node){
    if(node==NULL)return NULL;
    else return node->nextSep->nextNode;
}
MySeparator* prevSepOf(MySeparator *sep){
    if(sep==NULL || sep->prevNode==NULL)return NULL;
    else return sep->prevNode->prevSep;
}
MySeparator* nextSepOf(MySeparator *sep){
    if(sep==NULL || sep->nextNode==NULL)return NULL;
    else return sep->nextNode->nextSep;
}





MySeparator *head, *tokenTop;
void addToken(int type, const char *content){
	tokenTop = createNode(type, content, tokenTop, NULL)->nextSep;
}

class MyLinkedStrNode{
public:
	MyLinkedStrNode(char c){ch = c; next=NULL;}
	char ch;
	MyLinkedStrNode *next;
};
class MyLinkedString{
public:
	MyLinkedString(){
		init();
	}
	MyLinkedString(const char *str){
		init();
		add(str);
	}
	void init(){
		head = new MyLinkedStrNode('\0');
		last = head;
		size = 0;
	}
	void add(char c){
		if(c=='\0')return;
		last->ch = c;
		last->next = new MyLinkedStrNode('\0');
		last = last->next;
		size++;
	}
	void add(const char *str){
		const char *ptr = str;
		while(ptr!=NULL && *ptr!='\0'){
			add(*ptr);
			ptr++;
		}
	}
	void clear(){
		//init();
		//return;
		MyLinkedStrNode *iter = head;
		while(iter!=last){
			MyLinkedStrNode *tmp = iter;
			iter = iter->next;
			if(iter==NULL){
				last = new MyLinkedStrNode('\0');
				break;
			}
			delete tmp;
		}
		head = last;
		size = 0;
	}
	int length(){
		return size;
	}
	const char* c_str(){ //toCharArray
		MyLinkedStrNode *iter = head;
		char *result = new char[size+1];
		int count = 0;
		while(iter!=NULL && iter->ch!='\0' && count<size){
			result[count++] = iter->ch;
			iter = iter->next;
		}
		result[count] = '\0';
		return result;
	}
private:
	MyLinkedStrNode *head;
	MyLinkedStrNode *last;
	int size;
};

//The values may be changed after running runScanner().
//to determine whether there is any unidentified chars after end-of-line ('$')
//by (lastScannedType==TYPE_NONE && firstCharOfLastSepAfterToken!='\0').
int lastScannedType = TYPE_NONE;
char firstCharOfLastSepAfterToken = '\0';

// ==== TODO 2/6 Scanner code here ====
/*
 Hint:
 Call addToken(int, const char*), which is defined right above,
 to add a specific token into a structure that will be used in
 the parser process.
 */
void runScanner(){
	//Declaratiions here
	char c;
	int currentType = TYPE_NONE;
	MyLinkedString *tokenPtr = new MyLinkedString();
	bool isStrNonEmpty = false;
	
	//Additional values
	/*bool isInQuotes = false;*/
	
	while(scanf("%c", &c) != EOF){
		//Conditions and Adding tokens here
		if( c=='"' ){
			if(isStrNonEmpty){
				addToken(currentType, tokenPtr->c_str());
				tokenPtr->clear();
			}
			
			if(/*isInQuotes &&*/ currentType==TYPE_QUOTE){
				//addToken(TYPE_STRING, "");
			}
			/*isInQuotes = !isInQuotes;*/
			
			currentType = TYPE_QUOTE;
			tokenPtr->add(c);
			isStrNonEmpty = true;
		}else if( /*!isInQuotes &&*/ (c>='a'&&c<='z') ){
			bool hasMoreThanOneChar = false;
			if(isStrNonEmpty && currentType!=TYPE_ID && currentType!=TYPE_STRING
					&& currentType!=TYPE_STRDCL && currentType!=TYPE_PRINT){
				addToken(currentType, tokenPtr->c_str());
				tokenPtr->clear();
			}else if(isStrNonEmpty){
				hasMoreThanOneChar = true;
			}
			if(hasMoreThanOneChar)currentType = TYPE_STRING;
			else if(c=='s')currentType = TYPE_STRDCL;
			else if(c=='p')currentType = TYPE_PRINT;
			else currentType = TYPE_ID;
			tokenPtr->add(c);
			isStrNonEmpty = true;
		}else if( /*isInQuotes &&*/ ( (c>='0'&&c<='9') ||
				(c>='A'&&c<='Z') || (c>='a'&&c<='z')
				) ){
			if(isStrNonEmpty && currentType!=TYPE_ID && currentType!=TYPE_STRING
					&& currentType!=TYPE_STRDCL && currentType!=TYPE_PRINT){
				addToken(currentType, tokenPtr->c_str());
				tokenPtr->clear();
			}
			currentType = TYPE_STRING;
			tokenPtr->add(c);
			isStrNonEmpty = true;
		}else{
			//regard other characters as separators only
			if(isStrNonEmpty){
				addToken(currentType, tokenPtr->c_str());
				tokenPtr->clear();
				firstCharOfLastSepAfterToken = '\0';
			}
			if(firstCharOfLastSepAfterToken=='\0' && c>' '){
				//printf("[%c]\n", c);
				addToken(TYPE_INVALID, tokenPtr->c_str());
				firstCharOfLastSepAfterToken = c;
			}
			currentType = TYPE_NONE;
			isStrNonEmpty = false;
		}
		
	}
	
	//After EOF is read
	if(isStrNonEmpty){
		addToken(currentType, tokenPtr->c_str());
		firstCharOfLastSepAfterToken = '\0';
	}
	
	lastScannedType = currentType;
	
}


MyNode *FAILURE_NODE; //will be initialized in main()
#define FAILURE_INDEX (0xff)

#define FAIL_MACRO {if(iter==FAILURE_NODE)return FAILURE_NODE;}
#define SUCCEED_MACRO {if(iter!=FAILURE_NODE)return iter;}

//returns [iter node] for "partially success", FAILURE_NODE for "failure"
MyNode* checkGrammarRecur(MyNode *begin, int typeRequired){
	if(begin==FAILURE_NODE || begin==NULL)return FAILURE_NODE;
	
	if(typeRequired==TYPE_NONE){ //"lambda" in the grammar
		return begin;
	}else if((typeRequired & FLAG_TERMINAL)!=0){
		//terminal occurs
		return (begin->type == typeRequired) ? nextOf(begin) : FAILURE_NODE;
	}
	
	MyNode *iter = begin;
	
	//TODO 3/6 modify grammar rules here
	/* [Hints]
	 
	 Syntax of "Concat":
	 (i.e. FIRST_TOKEN SECOND_TOKEN ... NTH_TOKEN)
	 iter = checkGrammarRecur(iter, FIRST_TOKEN); FAIL_MACRO;
	 iter = checkGrammarRecur(iter, SECOND_TOKEN); FAIL_MACRO;
	 ...
	 iter = checkGrammarRecur(iter, NTH_TOKEN); FAIL_MACRO;
	 
	 Syntax of "Or":
	 (i.e. FIRST_TOKEN | SECOND_TOKEN | ... | NTH_TOKEN)
	 MyNode *old_iter = iter;
	 iter = checkGrammarRecur(old_iter, FIRST_TOKEN); SUCCEED_MACRO;
	 iter = checkGrammarRecur(old_iter, SECOND_TOKEN); SUCCEED_MACRO;
	 ...
	 iter = checkGrammarRecur(old_iter, NTH_TOKEN); SUCCEED_MACRO;
	 
	 */
	if(typeRequired==TYPE_PROC){
		iter = checkGrammarRecur(iter, TYPE_DCL); FAIL_MACRO;
		iter = checkGrammarRecur(iter, TYPE_STMT); FAIL_MACRO;
	}else if(typeRequired==TYPE_DCL){
		iter = checkGrammarRecur(iter, TYPE_STRDCL); FAIL_MACRO;
		iter = checkGrammarRecur(iter, TYPE_ID); FAIL_MACRO;
		iter = checkGrammarRecur(iter, TYPE_ASTRING); FAIL_MACRO;
	}else if(typeRequired==TYPE_ASTRING){
		iter = checkGrammarRecur(iter, TYPE_QUOTE); FAIL_MACRO;
		iter = checkGrammarRecur(iter, TYPE_STRING); FAIL_MACRO;
		iter = checkGrammarRecur(iter, TYPE_QUOTE); FAIL_MACRO;
	}else if(typeRequired==TYPE_STMT){
		iter = checkGrammarRecur(iter, TYPE_PRINT); FAIL_MACRO;
		iter = checkGrammarRecur(iter, TYPE_ID); FAIL_MACRO;
	}
	return iter;
}

#ifndef __cplusplus
#define bool int
#endif
bool checkGrammar(MyNode *begin, int typeRequired){
	return checkGrammarRecur(begin, typeRequired)==NULL;
}

int main(){
	
	//initialize data structures
	
	tokenTop = createSep();
	head = tokenTop;
	
	FAILURE_NODE = createNode(FAILURE_INDEX, NULL, NULL, NULL);
	
	//call the scanner process
	runScanner();
	
	if(lastScannedType==TYPE_NONE && firstCharOfLastSepAfterToken!='\0'){
		//TODO 4/6 when the parser process fails due to violating '$' (end-of-line) rule
		printf("valid input\n");
	}else if(checkGrammar(head->nextNode, TYPE_PROC)){
		//TODO 5/6 when the parser process succeeds
		MyNode *iterNode = head->nextNode;
		while(iterNode!=NULL){
			if(iterNode->type==TYPE_STRDCL){
				printf("strdcl %s\n", iterNode->content);
			}else if(iterNode->type==TYPE_ID){
				printf("id %s\n", iterNode->content);
			}else if(iterNode->type==TYPE_QUOTE){
				printf("quote %s\n", iterNode->content);
			}else if(iterNode->type==TYPE_STRING){
				//if(iterNode->content[0]!='\0')
				printf("string %s\n", iterNode->content);
			}else if(iterNode->type==TYPE_PRINT){
				printf("print %s\n", iterNode->content);
			}
			iterNode = nextOf(iterNode);
		}
	}else{
		//TODO 6/6 when the parser process fails due to other reasons
		printf("valid input\n");
	}
	//system("pause");
	return 0;
}
