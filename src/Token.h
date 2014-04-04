#ifndef Token_H
#define Token_H

#include "Stack.h"

typedef enum {UNKNOW_TOKEN,NUMBER_TOKEN,OPERATOR_TOKEN}TokenType;

typedef struct{
	TokenType type;
}Token;

typedef struct {
	TokenType type;
	int value;
}NumberToken;

typedef struct {
	TokenType type;
	char *name;
	signed int precedence;
}OperatorToken;

typedef struct {
	char *expression;
	int startIndex;
}Tokenizer;




#endif // Token_H
