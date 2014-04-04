#include "unity.h"
#include "operatorEvaluate.h"
#include "mock_tryEvaluatethenPush.h"
#include "mock_tokenizerNew.h"
#include "mock_nextToken.h"
#include "mock_createNumberToken.h"
#include "mock_Stack.h"
#include "calculator.h"
#include "calculateToken.h"
#include "Token.h"






void setUp(void){}



void tearDown(void){}

void test_evaluate_1_PLUS_2(void)

{

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "1+2", .startIndex = 0};



 NumberToken number1 = {.type= NUMBER_TOKEN, .value=1};

 Token *token1 = (Token*)&number1;



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+"};

 Token *token2 = (Token*)&plus;



 NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};

 Token *token3 = (Token*)&number2;



 NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};

 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(55, &operatorStack, &plus);

 pop_CMockExpectAndReturn(56, &dataStack, &number1);

 pop_CMockExpectAndReturn(57, &dataStack, &number2);

 createNumberToken_CMockExpectAndReturn(58, 3, answer);

 push_CMockExpect(59, answer, &dataStack);



 evaluateOperator(&dataStack,&operatorStack);

}



void test_evaluate_100_MINUS_7(void)

{

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "10-7", .startIndex = 0};



 NumberToken number100 = {.type= NUMBER_TOKEN, .value=100};

 Token *token1 = (Token*)&number100;



 OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-"};

 Token *token2 = (Token*)&minus;



 NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};

 Token *token3 = (Token*)&number7;



 NumberToken number93 = {.type= NUMBER_TOKEN, .value=93};

 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(86, &operatorStack, &minus);

 pop_CMockExpectAndReturn(87, &dataStack, &number100);

 pop_CMockExpectAndReturn(88, &dataStack, &number7);

 createNumberToken_CMockExpectAndReturn(89, 93, answer);

 push_CMockExpect(90, answer, &dataStack);



 evaluateOperator(&dataStack,&operatorStack);

}



void test_evaluate_60_MULTIPLY_7(void)

{

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "60*7", .startIndex = 0};



 NumberToken number60 = {.type= NUMBER_TOKEN, .value=60};

 Token *token1 = (Token*)&number60;



 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*"};

 Token *token2 = (Token*)&multiply;



 NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};

 Token *token3 = (Token*)&number7;



 NumberToken number420 = {.type= NUMBER_TOKEN, .value=420};

 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(117, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(118, &dataStack, &number60);

 pop_CMockExpectAndReturn(119, &dataStack, &number7);

 createNumberToken_CMockExpectAndReturn(120, 420, answer);

 push_CMockExpect(121, answer, &dataStack);



 evaluateOperator(&dataStack,&operatorStack);

}



void test_evaluate_60_DIVIDE_5(void)

{

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "60/5", .startIndex = 0};



 NumberToken number60 = {.type= NUMBER_TOKEN, .value=60};

 Token *token1 = (Token*)&number60;



 OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/"};

 Token *token2 = (Token*)&divide;



 NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};

 Token *token3 = (Token*)&number5;



 NumberToken number12 = {.type= NUMBER_TOKEN, .value=12};

 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(148, &operatorStack, &divide);

 pop_CMockExpectAndReturn(149, &dataStack, &number60);

 pop_CMockExpectAndReturn(150, &dataStack, &number5);

 createNumberToken_CMockExpectAndReturn(151, 12, answer);

 push_CMockExpect(152, answer, &dataStack);



 evaluateOperator(&dataStack,&operatorStack);

}



void test_evaluate_60_MODULUS_7(void)

{

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "60/5", .startIndex = 0};



 NumberToken number60 = {.type= NUMBER_TOKEN, .value=60};

 Token *token1 = (Token*)&number60;



 OperatorToken modulus = {.type= OPERATOR_TOKEN, .name = "%"};

 Token *token2 = (Token*)&modulus;



 NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};

 Token *token3 = (Token*)&number7;



 NumberToken number4 = {.type= NUMBER_TOKEN, .value=4};

 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(179, &operatorStack, &modulus);

 pop_CMockExpectAndReturn(180, &dataStack, &number60);

 pop_CMockExpectAndReturn(181, &dataStack, &number7);

 createNumberToken_CMockExpectAndReturn(182, 4, answer);

 push_CMockExpect(183, answer, &dataStack);



 evaluateOperator(&dataStack,&operatorStack);

}



void test_evaluate_56_BITWISEAND_30(void)

{

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "56&30", .startIndex = 0};



 NumberToken number56 = {.type= NUMBER_TOKEN, .value=56};

 Token *token1 = (Token*)&number56;



 OperatorToken bitwiseand = {.type= OPERATOR_TOKEN, .name = "&"};

 Token *token2 = (Token*)&bitwiseand;



 NumberToken number30 = {.type= NUMBER_TOKEN, .value=30};

 Token *token3 = (Token*)&number30;



 NumberToken number23 = {.type= NUMBER_TOKEN, .value=24};

 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(210, &operatorStack, &bitwiseand);

 pop_CMockExpectAndReturn(211, &dataStack, &number56);

 pop_CMockExpectAndReturn(212, &dataStack, &number30);

 createNumberToken_CMockExpectAndReturn(213, 24, answer);

 push_CMockExpect(214, answer, &dataStack);



 evaluateOperator(&dataStack,&operatorStack);

}
