#include "unity.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "mock_tokenizerNew.h"
#include "mock_nextToken.h"
#include "mock_createNumberToken.h"
#include "mock_Stack.h"
#include "calculator.h"
#include "calculateToken.h"
#include "Token.h"
#include "Error.h"
#include "CException.h"






void setUp(void){}



void tearDown(void){}











void test_evaluate_should_throw_error_when_encounter_invalid_operator(void){



 Stack dataStack;

 Token *tempToken;

 NumberToken *tempAns;

 ErrorCode e;





 Tokenizer tokenizer = {.expression = "1@2", .startIndex = 0};

 NumberToken number1 = {.type= NUMBER_TOKEN, .value=1};

 OperatorToken alpha = {.type= OPERATOR_TOKEN, .name = "@", .precedence =0};

 NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};



 pop_CMockExpectAndReturn(37, &dataStack, &number1);

 pop_CMockExpectAndReturn(38, &dataStack, &number2);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluateOperator(&dataStack,&alpha);

  UnityFail( ("Invalid Operator should throw Error Not Operator"), (_U_UINT)42);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NOT_OPERATOR)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_evaluate_1_PLUS_2(void)

{

 Stack dataStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "1+2", .startIndex = 0};



 NumberToken number1 = {.type= NUMBER_TOKEN, .value=1};

 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+"};

 NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};

 NumberToken answer = {.type= NUMBER_TOKEN, .value=3};

 pop_CMockExpectAndReturn(62, &dataStack, &number2);

 pop_CMockExpectAndReturn(63, &dataStack, &number1);

 createNumberToken_CMockExpectAndReturn(64, 3, &answer);

 push_CMockExpect(65, &answer, &dataStack);



 evaluateOperator(&dataStack,&plus);

}



void test_evaluate_100_MINUS_7(void)

{

 Stack dataStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "10-7", .startIndex = 0};

 NumberToken number100 = {.type= NUMBER_TOKEN, .value=100};

 OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-"};

 NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};

 NumberToken answer = {.type= NUMBER_TOKEN, .value=93};



 pop_CMockExpectAndReturn(83, &dataStack, &number7);

 pop_CMockExpectAndReturn(84, &dataStack, &number100);

 createNumberToken_CMockExpectAndReturn(85, 93, &answer);

 push_CMockExpect(86, &answer, &dataStack);



 evaluateOperator(&dataStack,&minus);

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

 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*"};

 NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};

 NumberToken answer = {.type= NUMBER_TOKEN, .value=420};



 pop_CMockExpectAndReturn(106, &dataStack, &number7);

 pop_CMockExpectAndReturn(107, &dataStack, &number60);

 createNumberToken_CMockExpectAndReturn(108, 420, &answer);

 push_CMockExpect(109, &answer, &dataStack);



 evaluateOperator(&dataStack,&multiply);

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

 OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/"};

 NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};

 NumberToken answer = {.type= NUMBER_TOKEN, .value=12};



 pop_CMockExpectAndReturn(128, &dataStack, &number5);

 pop_CMockExpectAndReturn(129, &dataStack, &number60);

 createNumberToken_CMockExpectAndReturn(130, 12, &answer);

 push_CMockExpect(131, &answer, &dataStack);



 evaluateOperator(&dataStack,&divide);

}



void test_evaluate_60_MODULUS_7(void)

{

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "60%7", .startIndex = 0};

 NumberToken number60 = {.type= NUMBER_TOKEN, .value=60};

 OperatorToken modulus = {.type= OPERATOR_TOKEN, .name = "%"};

 NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};

 NumberToken answer = {.type= NUMBER_TOKEN, .value=4};



 pop_CMockExpectAndReturn(150, &dataStack, &number7);

 pop_CMockExpectAndReturn(151, &dataStack, &number60);

 createNumberToken_CMockExpectAndReturn(152, 4, &answer);

 push_CMockExpect(153, &answer, &dataStack);



 evaluateOperator(&dataStack,&modulus);

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

 OperatorToken bitwiseand = {.type= OPERATOR_TOKEN, .name = "&"};

 NumberToken number30 = {.type= NUMBER_TOKEN, .value=30};

 NumberToken answer = {.type= NUMBER_TOKEN, .value=24};



 pop_CMockExpectAndReturn(172, &dataStack, &number30);

 pop_CMockExpectAndReturn(173, &dataStack, &number56);

 createNumberToken_CMockExpectAndReturn(174, 24, &answer);

 push_CMockExpect(175, &answer, &dataStack);



 evaluateOperator(&dataStack,&bitwiseand);

}



void test_evaluate_90_BITWISEOR_20(void)

{

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "90&20", .startIndex = 0};

 NumberToken number90 = {.type= NUMBER_TOKEN, .value=90};

 OperatorToken bitwiseor = {.type= OPERATOR_TOKEN, .name = "|"};

 NumberToken number20 = {.type= NUMBER_TOKEN, .value=20};

 NumberToken answer = {.type= NUMBER_TOKEN, .value=94};



 pop_CMockExpectAndReturn(194, &dataStack, &number20);

 pop_CMockExpectAndReturn(195, &dataStack, &number90);

 createNumberToken_CMockExpectAndReturn(196, 94, &answer);

 push_CMockExpect(197, &answer, &dataStack);



 evaluateOperator(&dataStack,&bitwiseor);

}



void test_evaluate_99_BITWISEXOR_66(void)

{

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "99&66", .startIndex = 0};

 NumberToken number99 = {.type= NUMBER_TOKEN, .value=99};

 OperatorToken bitwisexor = {.type= OPERATOR_TOKEN, .name = "^"};

 NumberToken number66 = {.type= NUMBER_TOKEN, .value=66};

 NumberToken answer = {.type= NUMBER_TOKEN, .value=33};



 pop_CMockExpectAndReturn(216, &dataStack, &number66);

 pop_CMockExpectAndReturn(217, &dataStack, &number99);

 createNumberToken_CMockExpectAndReturn(218, 33, &answer);

 push_CMockExpect(219, &answer, &dataStack);



 evaluateOperator(&dataStack,&bitwisexor);

}



void test_evaluate_90_MINUS_35(void){

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "90-35", .startIndex = 0};

 NumberToken number90 = {.type= NUMBER_TOKEN, .value=90};

 OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-"};

 NumberToken number35 = {.type= NUMBER_TOKEN, .value=35};

 NumberToken answer = {.type= NUMBER_TOKEN, .value=55};



 pop_CMockExpectAndReturn(237, &dataStack, &number35);

 pop_CMockExpectAndReturn(238, &dataStack, &number90);

 createNumberToken_CMockExpectAndReturn(239, 55, &answer);

 push_CMockExpect(240, &answer, &dataStack);



 evaluateOperator(&dataStack,&minus);

}



void test_evaluate_16_BITWISEAND_50(void)

{

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "16&50", .startIndex = 0};

 NumberToken number16 = {.type= NUMBER_TOKEN, .value=16};

 OperatorToken bitwiseand = {.type= OPERATOR_TOKEN, .name = "&"};

 NumberToken number50 = {.type= NUMBER_TOKEN, .value=50};

 NumberToken answer = {.type= NUMBER_TOKEN, .value=16};



 pop_CMockExpectAndReturn(259, &dataStack, &number50);

 pop_CMockExpectAndReturn(260, &dataStack, &number16);

 createNumberToken_CMockExpectAndReturn(261, 16, &answer);

 push_CMockExpect(262, &answer, &dataStack);



 evaluateOperator(&dataStack,&bitwiseand);

}











void test_evaluateAllOperatorOnStack_2_plus_3_plus_4(void){

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "2+3+4", .startIndex = 0};



 NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+"};



 NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};



 OperatorToken plus2 = {.type= OPERATOR_TOKEN, .name = "+"};



 NumberToken number4 = {.type= NUMBER_TOKEN, .value=4};



 NumberToken tempAnswer = {.type= NUMBER_TOKEN, .value=5};



 NumberToken finalAnswer = {.type= NUMBER_TOKEN, .value=9};





 pop_CMockExpectAndReturn(295, &operatorStack, &plus);

 pop_CMockExpectAndReturn(296, &dataStack, &number3);

 pop_CMockExpectAndReturn(297, &dataStack, &number2);

 createNumberToken_CMockExpectAndReturn(298, 5, &tempAnswer);

 push_CMockExpect(299, &tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(302, &operatorStack, &plus);

 pop_CMockExpectAndReturn(303, &dataStack, &number4);

 pop_CMockExpectAndReturn(304, &dataStack, &tempAnswer);

 createNumberToken_CMockExpectAndReturn(305, 9, &finalAnswer);

 push_CMockExpect(306, &finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(307, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&dataStack,&operatorStack);

}



void test_evaluateAllOperatorOnStack_10_plus_3_multiply_9(void){

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "10+3*9", .startIndex = 0};



 NumberToken number10 = {.type= NUMBER_TOKEN, .value=10};



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+"};



 NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};



 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*"};



 NumberToken number9 = {.type= NUMBER_TOKEN, .value=9};



 NumberToken tempAnswer = {.type= NUMBER_TOKEN, .value=13};



 NumberToken finalAnswer = {.type= NUMBER_TOKEN, .value=117};





 pop_CMockExpectAndReturn(336, &operatorStack, &plus);

 pop_CMockExpectAndReturn(337, &dataStack, &number3);

 pop_CMockExpectAndReturn(338, &dataStack, &number10);

 createNumberToken_CMockExpectAndReturn(339, 13, &tempAnswer);

 push_CMockExpect(340, &tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(343, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(344, &dataStack, &number9);

 pop_CMockExpectAndReturn(345, &dataStack, &tempAnswer);

 createNumberToken_CMockExpectAndReturn(346, 117, &finalAnswer);

 push_CMockExpect(347, &finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(348, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&dataStack,&operatorStack);

}



void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6(void){

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "100/5*6", .startIndex = 0};



 NumberToken number100 = {.type= NUMBER_TOKEN, .value=100};



 OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/"};



 NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};



 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*"};



 NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};



 NumberToken tempAnswer = {.type= NUMBER_TOKEN, .value=20};



 NumberToken finalAnswer = {.type= NUMBER_TOKEN, .value=120};







 pop_CMockExpectAndReturn(378, &operatorStack, &divide);

 pop_CMockExpectAndReturn(379, &dataStack, &number5);

 pop_CMockExpectAndReturn(380, &dataStack, &number100);

 createNumberToken_CMockExpectAndReturn(381, 20, &tempAnswer);

 push_CMockExpect(382, &tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(385, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(386, &dataStack, &number6);

 pop_CMockExpectAndReturn(387, &dataStack, &tempAnswer);

 createNumberToken_CMockExpectAndReturn(388, 120, &finalAnswer);

 push_CMockExpect(389, &finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(390, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&dataStack,&operatorStack);

}



void test_evaluateAllOperatorOnStack_99_XOR_66_divide_11(void){

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "99^66/11", .startIndex = 0};



 NumberToken number99 = {.type= NUMBER_TOKEN, .value=99};



 OperatorToken XOR = {.type= OPERATOR_TOKEN, .name = "^"};



 NumberToken number66 = {.type= NUMBER_TOKEN, .value=66};



 OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/"};



 NumberToken number11 = {.type= NUMBER_TOKEN, .value=11};



 NumberToken tempAnswer = {.type= NUMBER_TOKEN, .value=33};



 NumberToken finalAnswer = {.type= NUMBER_TOKEN, .value=3};





 pop_CMockExpectAndReturn(419, &operatorStack, &XOR);

 pop_CMockExpectAndReturn(420, &dataStack, &number66);

 pop_CMockExpectAndReturn(421, &dataStack, &number99);

 createNumberToken_CMockExpectAndReturn(422, 33, &tempAnswer);

 push_CMockExpect(423, &tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(426, &operatorStack, &divide);

 pop_CMockExpectAndReturn(427, &dataStack, &number11);

 pop_CMockExpectAndReturn(428, &dataStack, &tempAnswer);

 createNumberToken_CMockExpectAndReturn(429, 3, &finalAnswer);

 push_CMockExpect(430, &finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(431, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&dataStack,&operatorStack);

}



void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6_plus_99_minus_20(void){

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;



 int check;



 Tokenizer tokenizer = {.expression = "100/5*6+99-20", .startIndex = 0};



 NumberToken number100 = {.type= NUMBER_TOKEN, .value=100};



 OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/"};



 NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};



 NumberToken tempAns= {.type= NUMBER_TOKEN, .value=20};



 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*"};



 NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};



 NumberToken tempAns2 = {.type= NUMBER_TOKEN, .value=120};



 OperatorToken add = {.type= OPERATOR_TOKEN, .name = "+"};



 NumberToken number99 = {.type= NUMBER_TOKEN, .value=99};



 NumberToken tempAns3 = {.type= NUMBER_TOKEN, .value=219};



 OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-"};



 NumberToken number20a = {.type= NUMBER_TOKEN, .value=20};



 NumberToken finalAnswer = {.type= NUMBER_TOKEN, .value=199};





 pop_CMockExpectAndReturn(472, &operatorStack, &divide);

 pop_CMockExpectAndReturn(473, &dataStack, &number5);

 pop_CMockExpectAndReturn(474, &dataStack, &number100);

 createNumberToken_CMockExpectAndReturn(475, 20, &tempAns);

 push_CMockExpect(476, &tempAns, &dataStack);





 pop_CMockExpectAndReturn(479, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(480, &dataStack, &number6);

 pop_CMockExpectAndReturn(481, &dataStack, &tempAns);

 createNumberToken_CMockExpectAndReturn(482, 120, &tempAns2);

 push_CMockExpect(483, &tempAns2, &dataStack);





 pop_CMockExpectAndReturn(486, &operatorStack, &add);

 pop_CMockExpectAndReturn(487, &dataStack, &number99);

 pop_CMockExpectAndReturn(488, &dataStack, &tempAns2);

 createNumberToken_CMockExpectAndReturn(489, 219, &tempAns3);

 push_CMockExpect(490, &tempAns3, &dataStack);





 pop_CMockExpectAndReturn(493, &operatorStack, &minus);

 pop_CMockExpectAndReturn(494, &dataStack, &number20a);

 pop_CMockExpectAndReturn(495, &dataStack, &tempAns3);

 createNumberToken_CMockExpectAndReturn(496, 199, &finalAnswer);

 push_CMockExpect(497, &finalAnswer, &dataStack);



 pop_CMockExpectAndReturn(499, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&dataStack,&operatorStack);

}











void test_tryEvaluateOperatorOnStaclThenPush_will_push_OperatorTOken_if_Operator_Stack_is_empty(void){

 Stack dataStack;

 Stack operatorStack;

 OperatorToken *opeToken;



 pop_CMockExpectAndReturn(513, &operatorStack, ((void *)0));

 push_CMockExpect(514, opeToken, &operatorStack);

 tryEvaluateOperatorOnStackThenPush(opeToken,&dataStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStaclThenPush_will_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_higher_than_previousToken(void)

{

 Stack dataStack;

 Stack operatorStack;



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=100};



 pop_CMockExpectAndReturn(526, &operatorStack, &plus);

 push_CMockExpect(527, &plus, &operatorStack);

 push_CMockExpect(528, &multiply, &operatorStack);

 tryEvaluateOperatorOnStackThenPush(&multiply,&dataStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStackThenPush_will_not_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_lower_than_previousToken(void)

{

 Stack dataStack;

 Stack operatorStack;





 NumberToken number1 = {.type= NUMBER_TOKEN, .value=1};

 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=100};

 NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};

 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};



 NumberToken tempAns = {.type= NUMBER_TOKEN, .value=2};



 pop_CMockExpectAndReturn(546, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(547, &dataStack, &number2);

 pop_CMockExpectAndReturn(548, &dataStack, &number1);

 createNumberToken_CMockExpectAndReturn(549, 2, &tempAns);

 push_CMockExpect(550, &tempAns, &dataStack);

 pop_CMockExpectAndReturn(551, &operatorStack, ((void *)0));

 push_CMockExpect(552, &plus, &operatorStack);



 tryEvaluateOperatorOnStackThenPush(&plus,&dataStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStackThenPush_evaluate_newToke_and_previousToken_if_both_have_same_precedence(void)

{

 Stack dataStack;

 Stack operatorStack;





 NumberToken number100 = {.type= NUMBER_TOKEN, .value=100};

 OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-", .precedence=70};

 NumberToken number20 = {.type= NUMBER_TOKEN, .value=20};

 OperatorToken minusA = {.type= OPERATOR_TOKEN, .name = "-", .precedence=70};

 NumberToken number16 = {.type= NUMBER_TOKEN, .value=16};

 NumberToken tempAns = {.type= NUMBER_TOKEN, .value=80};





 pop_CMockExpectAndReturn(571, &operatorStack, &minus);

 pop_CMockExpectAndReturn(572, &dataStack, &number20);

 pop_CMockExpectAndReturn(573, &dataStack, &number100);

 createNumberToken_CMockExpectAndReturn(574, 80, &tempAns);

 push_CMockExpect(575, &tempAns, &dataStack);

 pop_CMockExpectAndReturn(576, &operatorStack, ((void *)0));

 push_CMockExpect(577, &minusA, &operatorStack);

 tryEvaluateOperatorOnStackThenPush(&minusA,&dataStack,&operatorStack);

}





void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_1(void)

{

 Stack dataStack;

 Stack operatorStack;



 NumberToken number21 = {.type= NUMBER_TOKEN, .value=21};

 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=100};

 NumberToken number22 = {.type= NUMBER_TOKEN, .value=22};



 NumberToken tempAns1 = {.type= NUMBER_TOKEN, .value=462};



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 NumberToken number30 = {.type= NUMBER_TOKEN, .value=30};

 OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/", .precedence=100};

 NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};





 pop_CMockExpectAndReturn(599, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(600, &dataStack, &number22);

 pop_CMockExpectAndReturn(601, &dataStack, &number21);

 createNumberToken_CMockExpectAndReturn(602, 462, &tempAns1);

 push_CMockExpect(603, &tempAns1, &dataStack);



 pop_CMockExpectAndReturn(605, &operatorStack, &plus);

 push_CMockExpect(606, &plus, &operatorStack);

 push_CMockExpect(607, &divide, &operatorStack);



 tryEvaluateOperatorOnStackThenPush(&divide,&dataStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_2(void)

{

 Stack dataStack;

 Stack operatorStack;



 NumberToken number21 = {.type= NUMBER_TOKEN, .value=21};

 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 NumberToken number22 = {.type= NUMBER_TOKEN, .value=22};



 NumberToken tempAns1 = {.type= NUMBER_TOKEN, .value=43};



 OperatorToken bitwiseAND = {.type= OPERATOR_TOKEN, .name = "&", .precedence=20};

 NumberToken number30 = {.type= NUMBER_TOKEN, .value=30};

 OperatorToken bitwiseOR = {.type= OPERATOR_TOKEN, .name = "|", .precedence=10};

 NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};

 NumberToken tempAns2 = {.type= NUMBER_TOKEN, .value=6};



 pop_CMockExpectAndReturn(629, &operatorStack, &plus);

 pop_CMockExpectAndReturn(630, &dataStack, &number22);

 pop_CMockExpectAndReturn(631, &dataStack, &number21);

 createNumberToken_CMockExpectAndReturn(632, 43, &tempAns1);

 push_CMockExpect(633, &tempAns1, &dataStack);



 pop_CMockExpectAndReturn(635, &operatorStack, &bitwiseAND);

 pop_CMockExpectAndReturn(636, &dataStack, &number30);

 pop_CMockExpectAndReturn(637, &dataStack, &number6);

 createNumberToken_CMockExpectAndReturn(638, 6, &tempAns2);

 push_CMockExpect(639, &tempAns2, &dataStack);



 pop_CMockExpectAndReturn(641, &operatorStack, ((void *)0));

 push_CMockExpect(642, &bitwiseOR, &operatorStack);



 tryEvaluateOperatorOnStackThenPush(&bitwiseOR,&dataStack,&operatorStack);

}











 void test_shunting_yard_should_return_0_if_the_expression_is_null(){

 int check;

 Stack dataStack;

 Stack operatorStack;

 ErrorCode e;

 Tokenizer tokenizer = {.expression = "0", .startIndex = 0};



 NumberToken number2 = {.type= NUMBER_TOKEN, .value=0};

 Token *token1 = (Token*)&number2;



 stackNew_CMockExpectAndReturn(661, &dataStack);

 stackNew_CMockExpectAndReturn(662, &operatorStack);

 tokenizerNew_CMockExpectAndReturn(663, ((void *)0), &tokenizer);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  check = evaluate(((void *)0),&dataStack,&operatorStack);

  UnityFail( ("Should throw Error no expression "), (_U_UINT)668);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_EXPRESSION)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)672, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_should_return_3_for_1_plus_2(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 Tokenizer tokenizer = {.expression = "1+2", .startIndex = 0};



 NumberToken number1 = {.type= NUMBER_TOKEN, .value=1};

 Token *token1 = (Token*)&number1;



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 Token *token2 = (Token*)&plus;



 NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};

 Token *token3 = (Token*)&number2;



 NumberToken answerToken = {.type= NUMBER_TOKEN, .value=3};



 stackNew_CMockExpectAndReturn(694, &dataStack);

 stackNew_CMockExpectAndReturn(695, &operatorStack);

 tokenizerNew_CMockExpectAndReturn(696, "1+2", &tokenizer);



 nextToken_CMockExpectAndReturn(698, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(699, token1, 1);

 push_CMockExpect(700, token1, &dataStack);





 nextToken_CMockExpectAndReturn(703, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(704, token2, 0);

 isOperator_CMockExpectAndReturn(705, token2, 1);

 pop_CMockExpectAndReturn(706, &operatorStack, ((void *)0));

 push_CMockExpect(707, token2, &operatorStack);





 nextToken_CMockExpectAndReturn(710, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(711, token3, 1);

 push_CMockExpect(712, token3, &dataStack);

 nextToken_CMockExpectAndReturn(713, &tokenizer, ((void *)0));





 pop_CMockExpectAndReturn(716, &operatorStack, token2);

 pop_CMockExpectAndReturn(717, &dataStack, token3);

 pop_CMockExpectAndReturn(718, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(719, 3, &answerToken);

 push_CMockExpect(720, &answerToken, &dataStack);

 pop_CMockExpectAndReturn(721, &operatorStack, ((void *)0));



 pop_CMockExpectAndReturn(723, &dataStack, &answerToken);



 check=evaluate("1+2",&dataStack,&operatorStack);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)726, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}





void test_should_return_12_for_4_multiply_3(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 Tokenizer tokenizer = {.expression = "4*3", .startIndex = 0};



 NumberToken number4 = {.type= NUMBER_TOKEN, .value=4};

 Token *token1 = (Token*)&number4;



 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=100};

 Token *token2 = (Token*)&multiply;



 NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};

 Token *token3 = (Token*)&number3;



 NumberToken answerToken = {.type= NUMBER_TOKEN, .value = 12};



 stackNew_CMockExpectAndReturn(749, &dataStack);

 stackNew_CMockExpectAndReturn(750, &operatorStack);

 tokenizerNew_CMockExpectAndReturn(751, "4*3", &tokenizer);



 nextToken_CMockExpectAndReturn(753, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(754, token1, 1);

 push_CMockExpect(755, token1, &dataStack);





 nextToken_CMockExpectAndReturn(758, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(759, token2, 0);

 isOperator_CMockExpectAndReturn(760, token2, 1);

 pop_CMockExpectAndReturn(761, &operatorStack, ((void *)0));

 push_CMockExpect(762, token2, &operatorStack);





 nextToken_CMockExpectAndReturn(765, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(766, token3, 1);

 push_CMockExpect(767, token3, &dataStack);

 nextToken_CMockExpectAndReturn(768, &tokenizer, ((void *)0));





 pop_CMockExpectAndReturn(771, &operatorStack, token2);

 pop_CMockExpectAndReturn(772, &dataStack, token3);

 pop_CMockExpectAndReturn(773, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(774, 12, &answerToken);

 push_CMockExpect(775, &answerToken, &dataStack);

 pop_CMockExpectAndReturn(776, &operatorStack, ((void *)0));



 pop_CMockExpectAndReturn(778, &dataStack, &answerToken);



 check=evaluate("4*3",&dataStack,&operatorStack);

 UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)781, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_should_return_6_for_3_plus_4_plus_5_minus_6(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 Tokenizer tokenizer = {.expression = "3+4+5-6", .startIndex = 0};



 NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};

 Token *token1 = (Token*)&number3;



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 Token *token2 = (Token*)&plus;



 NumberToken number4 = {.type= NUMBER_TOKEN, .value=4};

 Token *token3 = (Token*)&number4;



 NumberToken tempAns1 = {.type= NUMBER_TOKEN, .value=7};



 OperatorToken add = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 Token *token4 = (Token*)&add;



 NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};

 Token *token5 = (Token*)&number5;



 NumberToken tempAns2 = {.type= NUMBER_TOKEN, .value=12};



 OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-", .precedence=70};

 Token *token6 = (Token*)&minus;



 NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};

 Token *token7 = (Token*)&number6;



 NumberToken finalAns = {.type= NUMBER_TOKEN, .value=6};



 stackNew_CMockExpectAndReturn(819, &dataStack);

 stackNew_CMockExpectAndReturn(820, &operatorStack);

 tokenizerNew_CMockExpectAndReturn(821, "3+4+5-6", &tokenizer);



 nextToken_CMockExpectAndReturn(823, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(824, token1, 1);

 push_CMockExpect(825, token1, &dataStack);





 nextToken_CMockExpectAndReturn(828, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(829, token2, 0);

 isOperator_CMockExpectAndReturn(830, token2, 1);

 pop_CMockExpectAndReturn(831, &operatorStack, ((void *)0));

 push_CMockExpect(832, token2, &operatorStack);





 nextToken_CMockExpectAndReturn(835, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(836, token3, 1);

 push_CMockExpect(837, token3, &dataStack);





 nextToken_CMockExpectAndReturn(840, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(841, token4, 0);

 isOperator_CMockExpectAndReturn(842, token4, 1);

 pop_CMockExpectAndReturn(843, &operatorStack, token2);

 pop_CMockExpectAndReturn(844, &dataStack, token3);

 pop_CMockExpectAndReturn(845, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(846, 7, &tempAns1);

 push_CMockExpect(847, &tempAns1, &dataStack);

 pop_CMockExpectAndReturn(848, &operatorStack, ((void *)0));

 push_CMockExpect(849, token4, &operatorStack);





 nextToken_CMockExpectAndReturn(852, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(853, token5, 1);

 push_CMockExpect(854, token5, &dataStack);





 nextToken_CMockExpectAndReturn(857, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(858, token6, 0);

 isOperator_CMockExpectAndReturn(859, token6, 1);

 pop_CMockExpectAndReturn(860, &operatorStack, token4);

 pop_CMockExpectAndReturn(861, &dataStack, token5);

 pop_CMockExpectAndReturn(862, &dataStack, &tempAns1);

 createNumberToken_CMockExpectAndReturn(863, 12, &tempAns2);

 push_CMockExpect(864, &tempAns2, &dataStack);

 pop_CMockExpectAndReturn(865, &operatorStack, ((void *)0));

 push_CMockExpect(866, token6, &operatorStack);





 nextToken_CMockExpectAndReturn(869, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(870, token7, 1);

 push_CMockExpect(871, token7, &dataStack);

 nextToken_CMockExpectAndReturn(872, &tokenizer, ((void *)0));





 pop_CMockExpectAndReturn(875, &operatorStack, token6);

 pop_CMockExpectAndReturn(876, &dataStack, token7);

 pop_CMockExpectAndReturn(877, &dataStack, &tempAns2);

 createNumberToken_CMockExpectAndReturn(878, 6, &finalAns);

 push_CMockExpect(879, &finalAns, &dataStack);

 pop_CMockExpectAndReturn(880, &operatorStack, ((void *)0));



 pop_CMockExpectAndReturn(882, &dataStack, &finalAns);

 check=evaluate("3+4+5-6",&dataStack,&operatorStack);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)884, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);



}
