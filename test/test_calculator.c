#include "unity.h"
#include "calculator.h"
#include "Token.h"
#include "mock_Stack.h"
#include "mock_tokenizerNew.h"
#include "mock_nextToken.h"
#include "mock_tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "mock_createNumberToken.h"
#include "calculateToken.h"
#include <String.h>



void setUp(void){}

void tearDown(void){}

/*
void test_shunting_yard_should_return_0_if_the_expression_is_null(){
	int check;
	Tokenizer tokenizer = {.expression = "0", .startIndex = 0};
	
	NumberToken number2 = {.type= NUMBER_TOKEN, .value=0};
	Token *token1 = (Token*)&number2;
	
	tokenizerNew_ExpectAndReturn(NULL,&tokenizer);
	
	check=evaluate(NULL);
	TEST_ASSERT_EQUAL(0,check);
}
*/
void test_evaluate_1_PLUS_2(void)
{
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "1+2", .startIndex = 0};
	
	NumberToken number1 = {.type= NUMBER_TOKEN, .value=1};
	Token *token1 = (Token*)&number1;
	
	OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+"};
	Token *token2 = (Token*)&plus;
	
	NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};
	Token *token3 = (Token*)&number2;
	
	NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&number1);
	pop_ExpectAndReturn(&dataStack,&number2);
	createNumberToken_ExpectAndReturn(3,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&operatorStack);
}
	
void test_evaluate_100_MINUS_7(void)
{
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "10-7", .startIndex = 0};
	
	NumberToken number100 = {.type= NUMBER_TOKEN, .value=100};
	Token *token1 = (Token*)&number100;
	
	OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-"};
	Token *token2 = (Token*)&minus;
	
	NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};
	Token *token3 = (Token*)&number7;
	
	NumberToken number93 = {.type= NUMBER_TOKEN, .value=93};
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,&minus);
	pop_ExpectAndReturn(&dataStack,&number100);
	pop_ExpectAndReturn(&dataStack,&number7);
	createNumberToken_ExpectAndReturn(93,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&operatorStack);
}

void test_evaluate_60_MULTIPLY_7(void)
{
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "60*7", .startIndex = 0};
	
	NumberToken number60 = {.type= NUMBER_TOKEN, .value=60};
	Token *token1 = (Token*)&number60;
	
	OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*"};
	Token *token2 = (Token*)&multiply;
	
	NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};
	Token *token3 = (Token*)&number7;
	
	NumberToken number420 = {.type= NUMBER_TOKEN, .value=420};
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,&multiply);
	pop_ExpectAndReturn(&dataStack,&number60);
	pop_ExpectAndReturn(&dataStack,&number7);
	createNumberToken_ExpectAndReturn(420,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&operatorStack);
}

void test_evaluate_60_DIVIDE_5(void)
{
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "60/5", .startIndex = 0};
	
	NumberToken number60 = {.type= NUMBER_TOKEN, .value=60};
	Token *token1 = (Token*)&number60;
	
	OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/"};
	Token *token2 = (Token*)&divide;
	
	NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};
	Token *token3 = (Token*)&number5;
	
	NumberToken number12 = {.type= NUMBER_TOKEN, .value=12};
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,&divide);
	pop_ExpectAndReturn(&dataStack,&number60);
	pop_ExpectAndReturn(&dataStack,&number5);
	createNumberToken_ExpectAndReturn(12,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&operatorStack);
}

void test_evaluate_60_MODULUS_7(void)
{
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "60/5", .startIndex = 0};
	
	NumberToken number60 = {.type= NUMBER_TOKEN, .value=60};
	Token *token1 = (Token*)&number60;
	
	OperatorToken modulus = {.type= OPERATOR_TOKEN, .name = "%"};
	Token *token2 = (Token*)&modulus;
	
	NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};
	Token *token3 = (Token*)&number7;
	
	NumberToken number4 = {.type= NUMBER_TOKEN, .value=4};
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,&modulus);
	pop_ExpectAndReturn(&dataStack,&number60);
	pop_ExpectAndReturn(&dataStack,&number7);
	createNumberToken_ExpectAndReturn(4,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&operatorStack);
}

void test_evaluate_56_BITWISEAND_30(void)
{
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "56&30", .startIndex = 0};
	
	NumberToken number56 = {.type= NUMBER_TOKEN, .value=56};
	Token *token1 = (Token*)&number56;
	
	OperatorToken bitwiseand = {.type= OPERATOR_TOKEN, .name = "&"};
	Token *token2 = (Token*)&bitwiseand;
	
	NumberToken number30 = {.type= NUMBER_TOKEN, .value=30};
	Token *token3 = (Token*)&number30;
	
	NumberToken number23 = {.type= NUMBER_TOKEN, .value=24};
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,&bitwiseand);
	pop_ExpectAndReturn(&dataStack,&number56);
	pop_ExpectAndReturn(&dataStack,&number30);
	createNumberToken_ExpectAndReturn(24,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&operatorStack);
}

