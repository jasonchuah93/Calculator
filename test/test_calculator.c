#include "unity.h"
#include "calculator.h"
#include "Token.h"
#include "mock_Stack.h"
#include "mock_tokenizerNew.h"
#include "mock_nextToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "mock_createNumberToken.h"
#include "calculateToken.h"
#include <String.h>
#include <CException.h>
#include "Error.h"


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
	
	
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,&bitwiseand);
	pop_ExpectAndReturn(&dataStack,&number56);
	pop_ExpectAndReturn(&dataStack,&number30);
	createNumberToken_ExpectAndReturn(24,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&operatorStack);
}

void test_evaluate_90_BITWISEOR_20(void)
{
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "90&20", .startIndex = 0};
	
	NumberToken number90 = {.type= NUMBER_TOKEN, .value=90};
	Token *token1 = (Token*)&number90;
	
	OperatorToken bitwiseor = {.type= OPERATOR_TOKEN, .name = "|"};
	Token *token2 = (Token*)&bitwiseor;
	
	NumberToken number20 = {.type= NUMBER_TOKEN, .value=20};
	Token *token3 = (Token*)&number20;
	
	
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,&bitwiseor);
	pop_ExpectAndReturn(&dataStack,&number90);
	pop_ExpectAndReturn(&dataStack,&number20);
	createNumberToken_ExpectAndReturn(94,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&operatorStack);
}

void test_evaluate_99_BITWISEXOR_66(void)
{
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "99&66", .startIndex = 0};
	
	NumberToken number99 = {.type= NUMBER_TOKEN, .value=99};
	Token *token1 = (Token*)&number99;
	
	OperatorToken bitwisexor = {.type= OPERATOR_TOKEN, .name = "^"};
	Token *token2 = (Token*)&bitwisexor;
	
	NumberToken number66 = {.type= NUMBER_TOKEN, .value=66};
	Token *token3 = (Token*)&number66;
	
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,&bitwisexor);
	pop_ExpectAndReturn(&dataStack,&number99);
	pop_ExpectAndReturn(&dataStack,&number66);
	createNumberToken_ExpectAndReturn(33,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&operatorStack);
}

void test_evaluate_90_MINUS_35(void){
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "90-35", .startIndex = 0};
	
	NumberToken number90 = {.type= NUMBER_TOKEN, .value=90};
	Token *token1 = (Token*)&number90;
	
	OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-"};
	Token *token2 = (Token*)&minus;
	
	NumberToken number35 = {.type= NUMBER_TOKEN, .value=35};
	Token *token3 = (Token*)&number35;
	
	
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,&minus);
	pop_ExpectAndReturn(&dataStack,&number90);
	pop_ExpectAndReturn(&dataStack,&number35);
	createNumberToken_ExpectAndReturn(55,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&operatorStack);
}

void test_evaluate_16_BITWISEAND_50(void)
{
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "16&50", .startIndex = 0};
	
	NumberToken number16 = {.type= NUMBER_TOKEN, .value=16};
	Token *token1 = (Token*)&number16;
	
	OperatorToken bitwiseand = {.type= OPERATOR_TOKEN, .name = "&"};
	Token *token2 = (Token*)&bitwiseand;
	
	NumberToken number50 = {.type= NUMBER_TOKEN, .value=50};
	Token *token3 = (Token*)&number50;
	
	
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,&bitwiseand);
	pop_ExpectAndReturn(&dataStack,&number16);
	pop_ExpectAndReturn(&dataStack,&number50);
	createNumberToken_ExpectAndReturn(16,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&operatorStack);
}

void test_evaluate_2_plus_3_plus_4(void){
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "2+3+4", .startIndex = 0};
	
	NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};
	
	OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+"};
	
	NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};
	
	OperatorToken plus2 = {.type= OPERATOR_TOKEN, .name = "+"};
	
	NumberToken number4 = {.type= NUMBER_TOKEN, .value=4};
	
	NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};
	Token *tempAnswer = (Token*)&number5;
	
	Token *finalAnswer = (Token*)&finalAnswer;
	
	//2+3
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&number2);
	pop_ExpectAndReturn(&dataStack,&number3);
	createNumberToken_ExpectAndReturn(5,tempAnswer);
	push_Expect(tempAnswer,&dataStack);
	
	//5+4
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,tempAnswer);
	pop_ExpectAndReturn(&dataStack,&number4);
	createNumberToken_ExpectAndReturn(9,finalAnswer);
	push_Expect(finalAnswer,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&dataStack,&operatorStack);
}	

void test_evaluate_10_plus_3_multiply_9(void){
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "10+3*9", .startIndex = 0};
	
	NumberToken number10 = {.type= NUMBER_TOKEN, .value=10};
	
	OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+"};
	
	NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};
	
	OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*"};
	
	NumberToken number9 = {.type= NUMBER_TOKEN, .value=9};
	
	NumberToken number13 = {.type= NUMBER_TOKEN, .value=13};
	Token *tempAnswer = (Token*)&number13;
	
	Token *finalAnswer = (Token*)&finalAnswer;
	
	//10+3
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&number10);
	pop_ExpectAndReturn(&dataStack,&number3);
	createNumberToken_ExpectAndReturn(13,tempAnswer);
	push_Expect(tempAnswer,&dataStack);
	
	//13*9
	pop_ExpectAndReturn(&operatorStack,&multiply);
	pop_ExpectAndReturn(&dataStack,tempAnswer);
	pop_ExpectAndReturn(&dataStack,&number9);
	createNumberToken_ExpectAndReturn(117,finalAnswer);
	push_Expect(finalAnswer,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&dataStack,&operatorStack);
}	

void test_evaluate_100_divide_5_multiply_6(void){
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "100/5*6", .startIndex = 0};
	
	NumberToken number100 = {.type= NUMBER_TOKEN, .value=100};
	
	OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/"};
	
	NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};
	
	OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*"};
	
	NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};
	
	NumberToken number20 = {.type= NUMBER_TOKEN, .value=20};
	Token *tempAnswer = (Token*)&number20;
	
	Token *finalAnswer = (Token*)&finalAnswer;
	
	//100/5
	pop_ExpectAndReturn(&operatorStack,&divide);
	pop_ExpectAndReturn(&dataStack,&number100);
	pop_ExpectAndReturn(&dataStack,&number5);
	createNumberToken_ExpectAndReturn(20,tempAnswer);
	push_Expect(tempAnswer,&dataStack);
	
	//20*6
	pop_ExpectAndReturn(&operatorStack,&multiply);
	pop_ExpectAndReturn(&dataStack,tempAnswer);
	pop_ExpectAndReturn(&dataStack,&number6);
	createNumberToken_ExpectAndReturn(120,finalAnswer);
	push_Expect(finalAnswer,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&dataStack,&operatorStack);
}	

void test_evaluate_99_XOR_66_divide_11(void){
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "99^66/11", .startIndex = 0};
	
	NumberToken number99 = {.type= NUMBER_TOKEN, .value=99};
	
	OperatorToken XOR = {.type= OPERATOR_TOKEN, .name = "^"};
	
	NumberToken number66 = {.type= NUMBER_TOKEN, .value=66};
	
	OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/"};
	
	NumberToken number11 = {.type= NUMBER_TOKEN, .value=11};
	
	NumberToken number33 = {.type= NUMBER_TOKEN, .value=33};
	Token *tempAnswer = (Token*)&number33;
	
	Token *finalAnswer = (Token*)&finalAnswer;
	
	//99^66
	pop_ExpectAndReturn(&operatorStack,&XOR);
	pop_ExpectAndReturn(&dataStack,&number99);
	pop_ExpectAndReturn(&dataStack,&number66);
	createNumberToken_ExpectAndReturn(33,tempAnswer);
	push_Expect(tempAnswer,&dataStack);
	
	//33/11
	pop_ExpectAndReturn(&operatorStack,&divide);
	pop_ExpectAndReturn(&dataStack,tempAnswer);
	pop_ExpectAndReturn(&dataStack,&number11);
	createNumberToken_ExpectAndReturn(3,finalAnswer);
	push_Expect(finalAnswer,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&dataStack,&operatorStack);
}	

void test_evaluate_100_divide_5_multiply_6_plus_99_minus_20(void){
	Stack dataStack;
	Stack operatorStack;
	Token *tempToken;
	
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "100/5*6+99-20", .startIndex = 0};
	
	NumberToken number100 = {.type= NUMBER_TOKEN, .value=100};
	
	OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/"};
	
	NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};
	
	NumberToken number20 = {.type= NUMBER_TOKEN, .value=20};
	Token *tempAns =(Token*)&number20;
	
	OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*"};
	
	NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};
	
	NumberToken number120 = {.type= NUMBER_TOKEN, .value=120};
	Token *tempAns2 =(Token*)&number120;
	
	OperatorToken add = {.type= OPERATOR_TOKEN, .name = "+"};
	
	NumberToken number99 = {.type= NUMBER_TOKEN, .value=99};
	
	NumberToken number219 = {.type= NUMBER_TOKEN, .value=219};
	Token *tempAns3	=(Token*)&number219;
	
	OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-"};
	
	NumberToken number20a = {.type= NUMBER_TOKEN, .value=20};
	
	Token *finalAnswer = (Token*)&finalAnswer;
	
	//100/5
	pop_ExpectAndReturn(&operatorStack,&divide);
	pop_ExpectAndReturn(&dataStack,&number100);
	pop_ExpectAndReturn(&dataStack,&number5);
	createNumberToken_ExpectAndReturn(20,tempAns);
	push_Expect(tempAns,&dataStack);
	
	//20*6
	pop_ExpectAndReturn(&operatorStack,&multiply);
	pop_ExpectAndReturn(&dataStack,tempAns);
	pop_ExpectAndReturn(&dataStack,&number6);
	createNumberToken_ExpectAndReturn(120,tempAns2);
	push_Expect(tempAns2,&dataStack);
	
	//120+99
	pop_ExpectAndReturn(&operatorStack,&add);
	pop_ExpectAndReturn(&dataStack,tempAns2);
	pop_ExpectAndReturn(&dataStack,&number99);
	createNumberToken_ExpectAndReturn(219,tempAns3);
	push_Expect(tempAns3,&dataStack);
	
	//219-20
	pop_ExpectAndReturn(&operatorStack,&minus);
	pop_ExpectAndReturn(&dataStack,tempAns3);
	pop_ExpectAndReturn(&dataStack,&number20a);
	createNumberToken_ExpectAndReturn(199,finalAnswer);
	push_Expect(finalAnswer,&dataStack);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&dataStack,&operatorStack);
}	
/*
void test_try_evaluate_5_PLUS_6_MULTIPLY_7_and_compare_operators_to_determine_the_operator_to_be_push_into_stack(void){
	int check;
	Stack *dataStack;
	Stack *operatorStack;
	Token *tempToken;
	Token *finalToken;
	NumberToken *tempAns;
	NumberToken *finalAns;
	
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "5+6*7", .startIndex = 0,};
	
	NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};
	
	
	OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};
	
	
	NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};
	
	
	OperatorToken multiply = {.type= OPERATOR_TOKEN, .name="*", .precedence=100};
	
	NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};
	
	
	
	
	tryEvaluateOperatorOnStackThenPush(&multiply,dataStack,operatorStack);
}
*/

/**************************************************************/
//Evaluate
void test_should_return_3_for_1_plus_2(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "1+2", .startIndex = 0};
	
	NumberToken number1 = {.type= NUMBER_TOKEN, .value=1};
	Token *token1 = (Token*)&number1;
	
	OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};
	Token *token2 = (Token*)&plus;
	
	NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};
	Token *token3 = (Token*)&number2;
	
	
	tokenizerNew_ExpectAndReturn("1+2",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	push_Expect(token1,&dataStack);
	
	//Operator token plus
	nextToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	push_Expect(token2,&operatorStack);
	
	//Number token 3
	nextToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	push_Expect(token3,&dataStack);
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,token2);
	pop_ExpectAndReturn(&dataStack,token1);
	pop_ExpectAndReturn(&dataStack,token3);
	createNumberToken_ExpectAndReturn(3,answer);
	push_Expect(answer,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluate("1+2",&dataStack,&operatorStack);
	
}

void test_should_return_12_for_4_multiply_3(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "4*3", .startIndex = 0};
	
	NumberToken number4 = {.type= NUMBER_TOKEN, .value=4};
	Token *token1 = (Token*)&number4;
	
	OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=70};
	Token *token2 = (Token*)&multiply;
	
	NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};
	Token *token3 = (Token*)&number3;
	
	
	tokenizerNew_ExpectAndReturn("4*3",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	push_Expect(token1,&dataStack);
	
	//Operator token multiply
	nextToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	push_Expect(token2,&operatorStack);
	
	//Number token 3
	nextToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	push_Expect(token3,&dataStack);
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	
	Token *answer = (Token*)&answer;
	
	pop_ExpectAndReturn(&operatorStack,token2);
	pop_ExpectAndReturn(&dataStack,token1);
	pop_ExpectAndReturn(&dataStack,token3);
	createNumberToken_ExpectAndReturn(12,answer);
	push_Expect(answer,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluate("4*3",&dataStack,&operatorStack);
	
}

void test_should_return_6_for_3_plus_4_plus_5_minus_6(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "3+4+5-6", .startIndex = 0};
	
	NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};
	Token *token1 = (Token*)&number3;
	
	OperatorToken add = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};
	Token *token2 = (Token*)&add;
	
	NumberToken number4 = {.type= NUMBER_TOKEN, .value=4};
	Token *token3 = (Token*)&number4;
	
	NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};
	Token *tempAns = (Token*)&number7;
	
	OperatorToken add2 = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};
	Token *token4 = (Token*)&add2;
	
	NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};
	Token *token5 = (Token*)&number5;
	
	NumberToken number12 = {.type= NUMBER_TOKEN, .value=12};
	Token *tempAns2 = (Token*)&number12;
	
	OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-", .precedence=70};
	Token *token6 = (Token*)&minus;
	
	NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};
	Token *token7 = (Token*)&number6;
	
	NumberToken number6a = {.type= NUMBER_TOKEN, .value=6};
	Token *finalAns = (Token*)&number6a;
	
	
	tokenizerNew_ExpectAndReturn("3+4+5-6",&tokenizer);
	//3
	nextToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	push_Expect(token1,&dataStack);
	//plus
	nextToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	push_Expect(token2,&operatorStack);
	//4
	nextToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	push_Expect(token3,&dataStack);
	//plus
	nextToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,1);
	push_Expect(token4,&dataStack);
	
	//5
	nextToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	push_Expect(token5,&dataStack);
	//minus
	nextToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,1);
	push_Expect(token6,&dataStack);
	
	//6
	nextToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	push_Expect(token7,&dataStack);
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	
	Token *answer = (Token*)&answer;
	//3+4
	pop_ExpectAndReturn(&operatorStack,token2);
	pop_ExpectAndReturn(&dataStack,token1);
	pop_ExpectAndReturn(&dataStack,token3);
	createNumberToken_ExpectAndReturn(7,tempAns);
	push_Expect(tempAns,&dataStack);
	
	//7+5
	pop_ExpectAndReturn(&operatorStack,token4);
	pop_ExpectAndReturn(&dataStack,tempAns);
	pop_ExpectAndReturn(&dataStack,token5);
	createNumberToken_ExpectAndReturn(12,tempAns2);
	push_Expect(tempAns2,&dataStack);
	
	//12-6
	pop_ExpectAndReturn(&operatorStack,token6);
	pop_ExpectAndReturn(&dataStack,tempAns2);
	pop_ExpectAndReturn(&dataStack,token7);
	createNumberToken_ExpectAndReturn(6,finalAns);
	push_Expect(finalAns,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluate("3+4+5-6",&dataStack,&operatorStack);
	
}

/*
void test_should_evaluate_plus_token(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	ErrorCode e;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "+", .startIndex = 0};
	
	OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};
	Token *token1 = (Token*)&plus;
	
	tokenizerNew_ExpectAndReturn("+",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	push_Expect(token1,&operatorStack);
	nextToken_ExpectAndThrow(&tokenizer,ERR_NOT_DATA);
	
	
	Try{
		evaluate("+",&dataStack,&operatorStack);
		TEST_FAIL_MESSAGE("Should throw ERR_NOT_DATA");
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NOT_DATA,e);
	}
}
*/