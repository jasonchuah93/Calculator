#ifndef __GETTOKEN_H__
#define __GETTOKEN_H__

#include "Token.h"

//Function declaration

Token *nextToken(Tokenizer *tokenizer);

int isOperator(Token * unknownToken);
int isNumber(Token * unknownToken);

#endif //__GETTOKEN_H__