#include <stdio.h>
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
#include "Error.h"
#include "CException.h"

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

int evaluate(char *expression,Stack *dataStack,Stack *operatorStack){
	
	Tokenizer *tokenizer;
	Token *token;
	ErrorCode e;
	int i;
	int counter =0;
	
	tokenizer = tokenizerNew(expression);
	if(expression ==NULL){	
		Throw(ERR_NO_EXPRESSION);
	}
	
	while((token=nextToken(tokenizer))!=NULL){
		if(isNumber(token)){
			Throw(ERR_NOT_OPERATOR);
		}
		else if(isOperator(token)){
			Throw(ERR_NOT_DATA);
		}
		
		if(isNumber(token)){
			
			push(token,dataStack);
		}
		else if(isOperator(token)) 
		{
			tryEvaluateOperatorOnStackThenPush((OperatorToken*)token,dataStack,operatorStack);
			//push(token,operatorStack);
		}
		
		counter ++;
	}
	evaluateAllOperatorOnStack(dataStack,operatorStack);
	return counter;
}

void evaluateOperator(Stack *dataStack,OperatorToken *opeToken){
	NumberToken *num1;
	NumberToken *num2;
	Token *token1; 
	Token *token2; 
	int answer; 
	Token *answerToken; 
	token1=(Token*)pop(dataStack); 
	num1=(NumberToken*)token1; 
	token2=(Token*)pop(dataStack); 
	num2=(NumberToken*)token2;
	answer = calculate(opeToken,num2,num1); 
	answerToken=createNumberToken(answer);
	push(answerToken,dataStack);
	
}
void evaluateAllOperatorOnStack(Stack *dataStack,Stack *operatorStack){
	
	OperatorToken *opeToken;
	while((opeToken=pop(operatorStack)))
	{
		evaluateOperator(dataStack,opeToken);
	}
}

void tryEvaluateOperatorOnStackThenPush(OperatorToken *newToken,Stack *dataStack,Stack *operatorStack)
{
	OperatorToken *previousToken;
	previousToken=(OperatorToken*)pop(operatorStack);
	if(previousToken==NULL)
	{
		push(newToken,operatorStack);
	}
	else{
		while(previousToken!=NULL)
		{
			if(newToken->precedence > previousToken->precedence)
			{
				break;
			}
			else
			{
				evaluateOperator(dataStack,previousToken);
			}
			previousToken=(OperatorToken*)pop(operatorStack);
		}
		if(previousToken!=NULL)
		{
			push(previousToken,operatorStack);
		}
		push(newToken,operatorStack);
	}
}

	

