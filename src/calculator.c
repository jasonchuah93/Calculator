#include "calculator.h"
#include "Token.h"
#include "Stack.h"
#include "tokenizerNew.h"
#include "nextToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include <String.h>
#include "calculateToken.h"
#include "createNumberToken.h"

/**
	Evaluate an expression in text into a value
	Input :
		expression contains an expression to be evaluated in text 
	Return :
		the computed result 
	Throw :
		ERR_NO_EXPRESSION exception if expression is an empty text of NULL
		ERR_NOT_DATA exception if encounter other than number token
		ERR_NOT_OPERATOR exception if encounter other than Operator token
		ERR_INVALID_TOKEN exception if encounter unknown token
**/
/*
int evaluate(char *expression){
	Stack *dataStack;
	Stack *operatorStack;
	Tokenizer *tokenizer;
	Token *token;
	
	int i;
	int counter =0;
	
	tokenizer = tokenizerNew(expression);
	if(expression ==NULL){	
		return 0;
	}
	
	while((token=nextToken(tokenizer))!=NULL){
		if(isNumber(token)){
			push(token,dataStack);
			
		}
		
		else if(isOperator(token)) 
		{
			tryEvaluateOperatorOnStackThenPush(token,dataStack,operatorStack);
			
		}
		counter ++;
	}
	
	evaluateAllOperatorOnStack(dataStack,operatorStack);
	
	return counter;
}
*/
void evaluateOperator(Stack *dataStack,Stack *operatorStack){
	Token *token1; 
	Token *token2; 
	Token *token3;
	int answer; 
	Token *answerToken; 
	OperatorToken *operation; 
	NumberToken *num1;
	NumberToken *num2;
	
	token1=(Token*)pop(operatorStack); 
	operation=(OperatorToken*)token1; 
	token2=(Token*)pop(dataStack); 
	num1=(NumberToken*)token2; 
	token3=(Token*)pop(dataStack); 
	num2=(NumberToken*)token3;
	answer = calculate(operation,num1,num2); 
	answerToken=createNumberToken(answer);
	push(answerToken,dataStack);
	
}
	