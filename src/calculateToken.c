#include <stdio.h>
#include <string.h>
#include "Token.h"
#include "calculateToken.h"
#include "Error.h"

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
			Throw(ERR_NOT_OPERATOR);
		}
		
	}
	
	return answer;
}