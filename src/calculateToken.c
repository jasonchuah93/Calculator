#include <stdio.h>
#include <string.h>
#include "Token.h"
#include "calculateToken.h"
#include "Error.h"


/**
	Calculate 2 number token and return the answer back 
	Input :
		NumberTokens
		OperatorToken
	Output : 
		answer
**/
int calculate(OperatorToken *opeToken, NumberToken *first, NumberToken *second){
	
	int answer;
	switch(opeToken->name[0])
	{	
		case '*':
			answer=first->value*second->value;
		break;
		
		case '/':
			answer=first->value/second->value;
		break;
		case '+':
			answer=first->value+second->value;
		break;	
		
		case '-':
			answer=first->value-second->value;
		break;
		
		case '&':
			answer=first->value&second->value;
		break;
		
		case '|':
			answer=first->value|second->value;
		break;
		
		case '^':
			answer=first->value^second->value;
		break;
		
		case '%':
			answer=first->value%second->value;
		break;
		
		case '~':
			answer=~first->value;
		break;
		
		default:
		{
			Throw(ERR_INVALID_OPERATOR);
		}
		
	}
	
	return answer;
}	