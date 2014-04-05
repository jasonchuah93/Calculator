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
#include "CException.h"
#include "Error.h"


void setUp(void){}

void tearDown(void){}

/***********************************************************************	
 Test on function evaluateOperator 
 ***********************************************************************/	
 
void test_shunting_yard_should_return_0_if_the_expression_is_null(){
	int check;
	Stack dataStack;
	Stack operatorStack;
	ErrorCode e;
	Tokenizer tokenizer = {.expression = "0", .startIndex = 0};
	
	NumberToken number2 = {.type= NUMBER_TOKEN, .value=0};
	Token *token1 = (Token*)&number2;
	
	tokenizerNew_ExpectAndReturn(NULL,&tokenizer);
	
	Try
	{
		check = evaluate(NULL,&dataStack,&operatorStack);
		TEST_FAIL_MESSAGE("Should throw Error no expression ");
	}
	Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_NO_EXPRESSION,e);
	}
}

void test_evaluate_should_throw_error_when_encounter_invalid_operator(void){
	
	Stack dataStack;
	Token *tempToken;
	NumberToken *tempAns;
	ErrorCode e;
	
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "1@2", .startIndex = 0};
	NumberToken number1 = {.type= NUMBER_TOKEN, .value=1};
	OperatorToken alpha = {.type= OPERATOR_TOKEN, .name = "@", .precedence =0};
	NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};
	
	pop_ExpectAndReturn(&dataStack,&number1);
	pop_ExpectAndReturn(&dataStack,&number2);
	
	Try{
		evaluateOperator(&dataStack,&alpha);
		TEST_FAIL_MESSAGE("Invalid Operator should throw Error Not Operator");
	}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);
	}
}	

void test_evaluate_1_PLUS_2(void)
{
	Stack dataStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "1+2", .startIndex = 0};
	
	NumberToken number1 = {.type= NUMBER_TOKEN, .value=1};
	OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+"};
	NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};
	Token *answer;
	
	pop_ExpectAndReturn(&dataStack,&number2);
	pop_ExpectAndReturn(&dataStack,&number1);
	createNumberToken_ExpectAndReturn(3,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&plus);
}

void test_evaluate_100_MINUS_7(void)
{
	Stack dataStack;
	Token *tempToken;
	NumberToken *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "10-7", .startIndex = 0};
	NumberToken number100 = {.type= NUMBER_TOKEN, .value=100};
	OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-"};
	NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};
	Token *answer;
	
	pop_ExpectAndReturn(&dataStack,&number7);
	pop_ExpectAndReturn(&dataStack,&number100);
	createNumberToken_ExpectAndReturn(93,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&minus);
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
	OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*"};
	NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};
	Token *answer;
	
	pop_ExpectAndReturn(&dataStack,&number7);
	pop_ExpectAndReturn(&dataStack,&number60);
	createNumberToken_ExpectAndReturn(420,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&multiply);
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
	OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/"};
	NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};
	Token *answer;
	
	pop_ExpectAndReturn(&dataStack,&number5);
	pop_ExpectAndReturn(&dataStack,&number60);
	createNumberToken_ExpectAndReturn(12,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&divide);
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
	OperatorToken modulus = {.type= OPERATOR_TOKEN, .name = "%"};
	NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};
	Token *answer;
	
	pop_ExpectAndReturn(&dataStack,&number7);
	pop_ExpectAndReturn(&dataStack,&number60);
	createNumberToken_ExpectAndReturn(4,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&modulus);
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
	OperatorToken bitwiseand = {.type= OPERATOR_TOKEN, .name = "&"};
	NumberToken number30 = {.type= NUMBER_TOKEN, .value=30};
	Token *answer;
	
	pop_ExpectAndReturn(&dataStack,&number30);
	pop_ExpectAndReturn(&dataStack,&number56);
	createNumberToken_ExpectAndReturn(24,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&bitwiseand);
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
	OperatorToken bitwiseor = {.type= OPERATOR_TOKEN, .name = "|"};
	NumberToken number20 = {.type= NUMBER_TOKEN, .value=20};
	Token *answer;
	
	pop_ExpectAndReturn(&dataStack,&number20);
	pop_ExpectAndReturn(&dataStack,&number90);
	createNumberToken_ExpectAndReturn(94,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&bitwiseor);
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
	OperatorToken bitwisexor = {.type= OPERATOR_TOKEN, .name = "^"};
	NumberToken number66 = {.type= NUMBER_TOKEN, .value=66};
	Token *answer;
	
	pop_ExpectAndReturn(&dataStack,&number66);
	pop_ExpectAndReturn(&dataStack,&number99);
	createNumberToken_ExpectAndReturn(33,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&bitwisexor);
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
	OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-"};
	NumberToken number35 = {.type= NUMBER_TOKEN, .value=35};
	Token *answer;
	
	pop_ExpectAndReturn(&dataStack,&number35);
	pop_ExpectAndReturn(&dataStack,&number90);
	createNumberToken_ExpectAndReturn(55,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&minus);
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
	OperatorToken bitwiseand = {.type= OPERATOR_TOKEN, .name = "&"};
	NumberToken number50 = {.type= NUMBER_TOKEN, .value=50};
	Token *answer;
	
	pop_ExpectAndReturn(&dataStack,&number50);
	pop_ExpectAndReturn(&dataStack,&number16);
	createNumberToken_ExpectAndReturn(16,answer);
	push_Expect(answer,&dataStack);
	
	evaluateOperator(&dataStack,&bitwiseand);
}

/***********************************************************************	
 Test on function evaluateAllOperatorOnStack
 ***********************************************************************/	
 
void test_evaluateAllOperatorOnStack_2_plus_3_plus_4(void){
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
	
	Token *finalAnswer;
	
	//2+3
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&number3);
	pop_ExpectAndReturn(&dataStack,&number2);
	createNumberToken_ExpectAndReturn(5,tempAnswer);
	push_Expect(tempAnswer,&dataStack);
	
	//5+4
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&number4);
	pop_ExpectAndReturn(&dataStack,tempAnswer);
	createNumberToken_ExpectAndReturn(9,finalAnswer);
	push_Expect(finalAnswer,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&dataStack,&operatorStack);
}	

void test_evaluateAllOperatorOnStack_10_plus_3_multiply_9(void){
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
	
	Token *finalAnswer;
	
	//10+3
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&number3);
	pop_ExpectAndReturn(&dataStack,&number10);
	createNumberToken_ExpectAndReturn(13,tempAnswer);
	push_Expect(tempAnswer,&dataStack);
	
	//13*9
	pop_ExpectAndReturn(&operatorStack,&multiply);
	pop_ExpectAndReturn(&dataStack,&number9);
	pop_ExpectAndReturn(&dataStack,tempAnswer);
	createNumberToken_ExpectAndReturn(117,finalAnswer);
	push_Expect(finalAnswer,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&dataStack,&operatorStack);
}	

void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6(void){
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
	
	Token *finalAnswer;
	
	//100/5
	pop_ExpectAndReturn(&operatorStack,&divide);
	pop_ExpectAndReturn(&dataStack,&number5);
	pop_ExpectAndReturn(&dataStack,&number100);
	createNumberToken_ExpectAndReturn(20,tempAnswer);
	push_Expect(tempAnswer,&dataStack);
	
	//20*6
	pop_ExpectAndReturn(&operatorStack,&multiply);
	pop_ExpectAndReturn(&dataStack,&number6);
	pop_ExpectAndReturn(&dataStack,tempAnswer);
	createNumberToken_ExpectAndReturn(120,finalAnswer);
	push_Expect(finalAnswer,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&dataStack,&operatorStack);
}	

void test_evaluateAllOperatorOnStack_99_XOR_66_divide_11(void){
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
	
	Token *finalAnswer;
	
	//99^66
	pop_ExpectAndReturn(&operatorStack,&XOR);
	pop_ExpectAndReturn(&dataStack,&number66);
	pop_ExpectAndReturn(&dataStack,&number99);
	createNumberToken_ExpectAndReturn(33,tempAnswer);
	push_Expect(tempAnswer,&dataStack);
	
	//33/11
	pop_ExpectAndReturn(&operatorStack,&divide);
	pop_ExpectAndReturn(&dataStack,&number11);
	pop_ExpectAndReturn(&dataStack,tempAnswer);
	createNumberToken_ExpectAndReturn(3,finalAnswer);
	push_Expect(finalAnswer,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&dataStack,&operatorStack);
}	

void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6_plus_99_minus_20(void){
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
	
	Token *finalAnswer;
	
	//100/5
	pop_ExpectAndReturn(&operatorStack,&divide);
	pop_ExpectAndReturn(&dataStack,&number5);
	pop_ExpectAndReturn(&dataStack,&number100);
	createNumberToken_ExpectAndReturn(20,tempAns);
	push_Expect(tempAns,&dataStack);
	
	//20*6
	pop_ExpectAndReturn(&operatorStack,&multiply);
	pop_ExpectAndReturn(&dataStack,&number6);
	pop_ExpectAndReturn(&dataStack,tempAns);
	createNumberToken_ExpectAndReturn(120,tempAns2);
	push_Expect(tempAns2,&dataStack);
	
	//120+99
	pop_ExpectAndReturn(&operatorStack,&add);
	pop_ExpectAndReturn(&dataStack,&number99);
	pop_ExpectAndReturn(&dataStack,tempAns2);
	createNumberToken_ExpectAndReturn(219,tempAns3);
	push_Expect(tempAns3,&dataStack);
	
	//219-20
	pop_ExpectAndReturn(&operatorStack,&minus);
	pop_ExpectAndReturn(&dataStack,&number20a);
	pop_ExpectAndReturn(&dataStack,tempAns3);
	createNumberToken_ExpectAndReturn(199,finalAnswer);
	push_Expect(finalAnswer,&dataStack);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&dataStack,&operatorStack);
}

/***********************************************************************	
 Test on function tryEvaluateOperatorOnStackThenPush 
 ***********************************************************************/		

void test_tryEvaluateOperatorOnStaclThenPush_will_push_OperatorTOken_if_Operator_Stack_is_empty(void){
	Stack dataStack;
	Stack operatorStack;
	OperatorToken *opeToken;
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(opeToken,&operatorStack);
	tryEvaluateOperatorOnStackThenPush(opeToken,&dataStack,&operatorStack);
}

void test_tryEvaluateOperatorOnStaclThenPush_will_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_higher_than_previousToken(void)
{
	Stack dataStack;
	Stack operatorStack;
	
	OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};
	OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=100};
	
	pop_ExpectAndReturn(&operatorStack,&plus);
	push_Expect(&plus,&operatorStack);
	push_Expect(&multiply,&operatorStack);
	tryEvaluateOperatorOnStackThenPush(&multiply,&dataStack,&operatorStack);
}

void test_tryEvaluateOperatorOnStackThenPush_will_not_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_lower_than_previousToken(void)
{
	Stack dataStack;
	Stack operatorStack;
	
	//1*2+3
	NumberToken number1 = {.type= NUMBER_TOKEN, .value=1};
	OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=100};
	NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};
	OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};
	NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};
	
	Token *tempAns;
	
	pop_ExpectAndReturn(&operatorStack,&multiply);
	pop_ExpectAndReturn(&dataStack,&number2);
	pop_ExpectAndReturn(&dataStack,&number1);
	createNumberToken_ExpectAndReturn(2,tempAns);
	push_Expect(tempAns,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&plus,&operatorStack);
	
	tryEvaluateOperatorOnStackThenPush(&plus,&dataStack,&operatorStack);
}

void test_tryEvaluateOperatorOnStackThenPush_evaluate_newToke_and_previousToken_if_both_have_same_precedence(void)
{
	Stack dataStack;
	Stack operatorStack;
	
	//100-20-16
	NumberToken number100 = {.type= NUMBER_TOKEN, .value=100};
	OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-", .precedence=70};
	NumberToken number20 = {.type= NUMBER_TOKEN, .value=20};
	OperatorToken minusA = {.type= OPERATOR_TOKEN, .name = "-", .precedence=70};
	NumberToken number16 = {.type= NUMBER_TOKEN, .value=16};
	
	Token *tempAns;
	
	pop_ExpectAndReturn(&operatorStack,&minus);
	pop_ExpectAndReturn(&dataStack,&number20);
	pop_ExpectAndReturn(&dataStack,&number100);
	createNumberToken_ExpectAndReturn(80,tempAns);
	push_Expect(tempAns,&dataStack);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&minusA,&operatorStack);
	tryEvaluateOperatorOnStackThenPush(&minusA,&dataStack,&operatorStack);
}

void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_1(void)
{
	Stack dataStack;
	Stack operatorStack;
	//21*22+30/6
	NumberToken number21 = {.type= NUMBER_TOKEN, .value=21};
	OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=100};
	NumberToken number22 = {.type= NUMBER_TOKEN, .value=22};
	/**********
	  tempAns
	**********/
	Token *tempAns1;
	/*****************************************/
	OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};
	NumberToken number30 = {.type= NUMBER_TOKEN, .value=30};
	OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/", .precedence=100};
	NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};
	
		
	pop_ExpectAndReturn(&operatorStack,&multiply);
	pop_ExpectAndReturn(&dataStack,&number22);
	pop_ExpectAndReturn(&dataStack,&number21);
	createNumberToken_ExpectAndReturn(462,tempAns1);
	push_Expect(tempAns1,&dataStack);

	pop_ExpectAndReturn(&operatorStack,&plus);
	push_Expect(&plus,&operatorStack);
	push_Expect(&divide,&operatorStack);
	
	tryEvaluateOperatorOnStackThenPush(&divide,&dataStack,&operatorStack);
}

void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_2(void)
{
	Stack dataStack;
	Stack operatorStack;
	//21+22&30|6
	NumberToken number21 = {.type= NUMBER_TOKEN, .value=21};
	OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};
	NumberToken number22 = {.type= NUMBER_TOKEN, .value=22};
	
	OperatorToken bitwiseAND = {.type= OPERATOR_TOKEN, .name = "&", .precedence=20};
	NumberToken number30 = {.type= NUMBER_TOKEN, .value=30};
	OperatorToken bitwiseOR = {.type= OPERATOR_TOKEN, .name = "|", .precedence=10};
	NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};
	
	/**********
	  tempAns
	**********/
	Token *tempAns1;
	Token *tempAns2;
	/*****************************************/
		
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&number22);
	pop_ExpectAndReturn(&dataStack,&number21);
	createNumberToken_ExpectAndReturn(43,tempAns1);
	push_Expect(tempAns1,&dataStack);

	pop_ExpectAndReturn(&operatorStack,&bitwiseAND);
	pop_ExpectAndReturn(&dataStack,&number30);
	pop_ExpectAndReturn(&dataStack,&number6);
	createNumberToken_ExpectAndReturn(6,tempAns2);
	push_Expect(tempAns2,&dataStack);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&bitwiseOR,&operatorStack);
	tryEvaluateOperatorOnStackThenPush(&bitwiseOR,&dataStack,&operatorStack);
}


/***********************************************************************	
 Test on function evaluate
 ***********************************************************************/	
/*
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


void test_should_evaluate_plus_token_and_throw_error_not_data(void){
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

void test_should_evaluate_38_space_39_and_throw_error_not_operator(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	ErrorCode e;
	//Initialize tokenizer,token and stack
	Tokenizer tokenizer = {.expression = "38 39", .startIndex = 0};
	
	NumberToken number38 = {.type= NUMBER_TOKEN, .value=38};
	Token *token1 = (Token*)&number38;
	
	NumberToken number39 = {.type= NUMBER_TOKEN, .value=39};
	Token *token2 = (Token*)&number39;
	
	tokenizerNew_ExpectAndReturn("38 39",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	push_Expect(token1,&dataStack);
	
	nextToken_ExpectAndThrow(&tokenizer,ERR_NOT_OPERATOR);
	
	Try{
		evaluate("38 39",&dataStack,&operatorStack);
		 TEST_FAIL_MESSAGE("Should throw ERR_NOT_OPERATOR");
	 }Catch(e){
		 TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);
	 }
	 
}
*/