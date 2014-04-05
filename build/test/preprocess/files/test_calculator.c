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

  UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OPERATOR)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

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



void test_should_evaluate_266_OR_27_XOR_28_PLUS_29_AND_30(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 Tokenizer tokenizer = {.expression = "266|27^28+29&30", .startIndex = 0};



 NumberToken number266 = {.type= NUMBER_TOKEN, .value=266};

 Token *token1 = (Token*)&number266;



 OperatorToken OR = {.type= OPERATOR_TOKEN, .name = "|", .precedence=10};

 Token *token2 = (Token*)&OR;



 NumberToken number27 = {.type= NUMBER_TOKEN, .value=27};

 Token *token3 = (Token*)&number27;



 OperatorToken XOR = {.type= OPERATOR_TOKEN, .name = "^", .precedence=50};

 Token *token4 = (Token*)&XOR;



 NumberToken number28 = {.type= NUMBER_TOKEN, .value=28};

 Token *token5 = (Token*)&number28;



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 Token *token6 = (Token*)&plus;



 NumberToken number29 = {.type= NUMBER_TOKEN, .value=29};

 Token *token7 = (Token*)&number29;



 NumberToken tempAns1 = {.type= NUMBER_TOKEN, .value=57};



 NumberToken tempAns2 = {.type= NUMBER_TOKEN, .value=34};



 OperatorToken AND = {.type= OPERATOR_TOKEN, .name = "&", .precedence=20};

 Token *token8 = (Token*)&AND;



 NumberToken number30 = {.type= NUMBER_TOKEN, .value=30};

 Token *token9 = (Token*)&number30;



 NumberToken tempAns3 = {.type= NUMBER_TOKEN, .value=2};



 NumberToken finalAns = {.type= NUMBER_TOKEN, .value=266};



 stackNew_CMockExpectAndReturn(931, &dataStack);

 stackNew_CMockExpectAndReturn(932, &operatorStack);

 tokenizerNew_CMockExpectAndReturn(933, "266|27^28+29&30", &tokenizer);





 nextToken_CMockExpectAndReturn(936, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(937, token1, 1);

 push_CMockExpect(938, token1, &dataStack);





 nextToken_CMockExpectAndReturn(941, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(942, token2, 0);

 isOperator_CMockExpectAndReturn(943, token2, 1);

 pop_CMockExpectAndReturn(944, &operatorStack, ((void *)0));

 push_CMockExpect(945, token2, &operatorStack);





 nextToken_CMockExpectAndReturn(948, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(949, token3, 1);

 push_CMockExpect(950, token3, &dataStack);





 nextToken_CMockExpectAndReturn(953, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(954, token4, 0);

 isOperator_CMockExpectAndReturn(955, token4, 1);

 pop_CMockExpectAndReturn(956, &operatorStack, token2);

 push_CMockExpect(957, token2, &operatorStack);

 push_CMockExpect(958, token4, &operatorStack);





 nextToken_CMockExpectAndReturn(961, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(962, token5, 1);

 push_CMockExpect(963, token5, &dataStack);





 nextToken_CMockExpectAndReturn(966, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(967, token6, 0);

 isOperator_CMockExpectAndReturn(968, token6, 1);

 pop_CMockExpectAndReturn(969, &operatorStack, token4);

 push_CMockExpect(970, token4, &operatorStack);

 push_CMockExpect(971, token6, &operatorStack);





 nextToken_CMockExpectAndReturn(974, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(975, token7, 1);

 push_CMockExpect(976, token7, &dataStack);





 nextToken_CMockExpectAndReturn(979, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(980, token8, 0);

 isOperator_CMockExpectAndReturn(981, token8, 1);

 pop_CMockExpectAndReturn(982, &operatorStack, token6);

 pop_CMockExpectAndReturn(983, &dataStack, token7);

 pop_CMockExpectAndReturn(984, &dataStack, token5);

 createNumberToken_CMockExpectAndReturn(985, 57, &tempAns1);

 push_CMockExpect(986, &tempAns1, &dataStack);

 pop_CMockExpectAndReturn(987, &operatorStack, token4);

 pop_CMockExpectAndReturn(988, &dataStack, &tempAns1);

 pop_CMockExpectAndReturn(989, &dataStack, token3);

 createNumberToken_CMockExpectAndReturn(990, 34, &tempAns2);

 push_CMockExpect(991, &tempAns2, &dataStack);

 pop_CMockExpectAndReturn(992, &operatorStack, token2);

 push_CMockExpect(993, token2, &operatorStack);

 push_CMockExpect(994, token8, &operatorStack);





 nextToken_CMockExpectAndReturn(997, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(998, token9, 1);

 push_CMockExpect(999, token9, &dataStack);

 nextToken_CMockExpectAndReturn(1000, &tokenizer, ((void *)0));





 pop_CMockExpectAndReturn(1003, &operatorStack, token8);

 pop_CMockExpectAndReturn(1004, &dataStack, token9);

 pop_CMockExpectAndReturn(1005, &dataStack, &tempAns2);

 createNumberToken_CMockExpectAndReturn(1006, 2, &tempAns3);

 push_CMockExpect(1007, &tempAns3, &dataStack);

 pop_CMockExpectAndReturn(1008, &operatorStack, token2);

 pop_CMockExpectAndReturn(1009, &dataStack, &tempAns3);

 pop_CMockExpectAndReturn(1010, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(1011, 266, &finalAns);

 push_CMockExpect(1012, &finalAns, &dataStack);

 pop_CMockExpectAndReturn(1013, &operatorStack, ((void *)0));



 pop_CMockExpectAndReturn(1015, &dataStack, &finalAns);



 check=evaluate("266|27^28+29&30",&dataStack,&operatorStack);

 UnityAssertEqualNumber((_U_SINT)((266)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1018, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_should_evaluate_211_AND_22_XOR_23_PLUS_24_MULTIPLY_25(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 Tokenizer tokenizer = {.expression = "211&22^23+24*25", .startIndex = 0};



 NumberToken number211 = {.type= NUMBER_TOKEN, .value=211};

 Token *token1 = (Token*)&number211;



 OperatorToken AND = {.type= OPERATOR_TOKEN, .name = "&", .precedence=20};

 Token *token2 = (Token*)&AND;



 NumberToken number22 = {.type= NUMBER_TOKEN, .value=22};

 Token *token3 = (Token*)&number22;



 OperatorToken XOR = {.type= OPERATOR_TOKEN, .name = "^", .precedence=50};

 Token *token4 = (Token*)&XOR;



 NumberToken number23 = {.type= NUMBER_TOKEN, .value=23};

 Token *token5 = (Token*)&number23;



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 Token *token6 = (Token*)&plus;



 NumberToken number24 = {.type= NUMBER_TOKEN, .value=24};

 Token *token7 = (Token*)&number24;



 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=100};

 Token *token8 = (Token*)&multiply;



 NumberToken number25 = {.type= NUMBER_TOKEN, .value=25};

 Token *token9 = (Token*)&number25;



 NumberToken tempAns1 = {.type= NUMBER_TOKEN, .value=600};



 NumberToken tempAns2 = {.type= NUMBER_TOKEN, .value=623};



 NumberToken tempAns3 = {.type= NUMBER_TOKEN, .value=633};



 NumberToken finalAns = {.type= NUMBER_TOKEN, .value=81};



 stackNew_CMockExpectAndReturn(1064, &dataStack);

 stackNew_CMockExpectAndReturn(1065, &operatorStack);

 tokenizerNew_CMockExpectAndReturn(1066, "211&22^23+24*25", &tokenizer);





 nextToken_CMockExpectAndReturn(1069, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1070, token1, 1);

 push_CMockExpect(1071, token1, &dataStack);





 nextToken_CMockExpectAndReturn(1074, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1075, token2, 0);

 isOperator_CMockExpectAndReturn(1076, token2, 1);

 pop_CMockExpectAndReturn(1077, &operatorStack, ((void *)0));

 push_CMockExpect(1078, token2, &operatorStack);





 nextToken_CMockExpectAndReturn(1081, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1082, token3, 1);

 push_CMockExpect(1083, token3, &dataStack);





 nextToken_CMockExpectAndReturn(1086, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1087, token4, 0);

 isOperator_CMockExpectAndReturn(1088, token4, 1);

 pop_CMockExpectAndReturn(1089, &operatorStack, token2);

 push_CMockExpect(1090, token2, &operatorStack);

 push_CMockExpect(1091, token4, &operatorStack);





 nextToken_CMockExpectAndReturn(1094, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(1095, token5, 1);

 push_CMockExpect(1096, token5, &dataStack);





 nextToken_CMockExpectAndReturn(1099, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(1100, token6, 0);

 isOperator_CMockExpectAndReturn(1101, token6, 1);

 pop_CMockExpectAndReturn(1102, &operatorStack, token4);

 push_CMockExpect(1103, token4, &operatorStack);

 push_CMockExpect(1104, token6, &operatorStack);





 nextToken_CMockExpectAndReturn(1107, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(1108, token7, 1);

 push_CMockExpect(1109, token7, &dataStack);





 nextToken_CMockExpectAndReturn(1112, &tokenizer, token8);

 isNumber_CMockExpectAndReturn(1113, token8, 0);

 isOperator_CMockExpectAndReturn(1114, token8, 1);

 pop_CMockExpectAndReturn(1115, &operatorStack, token6);

 push_CMockExpect(1116, token6, &operatorStack);

 push_CMockExpect(1117, token8, &operatorStack);





 nextToken_CMockExpectAndReturn(1120, &tokenizer, token9);

 isNumber_CMockExpectAndReturn(1121, token9, 1);

 push_CMockExpect(1122, token9, &dataStack);

 nextToken_CMockExpectAndReturn(1123, &tokenizer, ((void *)0));





 pop_CMockExpectAndReturn(1126, &operatorStack, token8);

 pop_CMockExpectAndReturn(1127, &dataStack, token9);

 pop_CMockExpectAndReturn(1128, &dataStack, token7);

 createNumberToken_CMockExpectAndReturn(1129, 600, &tempAns1);

 push_CMockExpect(1130, &tempAns1, &dataStack);

 pop_CMockExpectAndReturn(1131, &operatorStack, token6);

 pop_CMockExpectAndReturn(1132, &dataStack, &tempAns1);

 pop_CMockExpectAndReturn(1133, &dataStack, token5);

 createNumberToken_CMockExpectAndReturn(1134, 623, &tempAns2);

 push_CMockExpect(1135, &tempAns2, &dataStack);

 pop_CMockExpectAndReturn(1136, &operatorStack, token4);

 pop_CMockExpectAndReturn(1137, &dataStack, &tempAns2);

 pop_CMockExpectAndReturn(1138, &dataStack, token3);

 createNumberToken_CMockExpectAndReturn(1139, 633, &tempAns3);

 push_CMockExpect(1140, &tempAns3, &dataStack);

 pop_CMockExpectAndReturn(1141, &operatorStack, token2);

 pop_CMockExpectAndReturn(1142, &dataStack, &tempAns3);

 pop_CMockExpectAndReturn(1143, &dataStack, token1);

 createNumberToken_CMockExpectAndReturn(1144, 81, &finalAns);

 push_CMockExpect(1145, &finalAns, &dataStack);

 pop_CMockExpectAndReturn(1146, &operatorStack, ((void *)0));



 pop_CMockExpectAndReturn(1148, &dataStack, &finalAns);



 check=evaluate("211&22^23+24*25",&dataStack,&operatorStack);

 UnityAssertEqualNumber((_U_SINT)((81)), (_U_SINT)((check)), (((void *)0)), (_U_UINT)1151, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",check);

}



void test_should_evaluate_and_throw_error_not_data_if_first_token_is_operator(void){

 Stack dataStack;

 Stack operatorStack;

 int check;

 ErrorCode e;



 Tokenizer tokenizer = {.expression = "+", .startIndex = 0};



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 Token *token1 = (Token*)&plus;



 stackNew_CMockExpectAndReturn(1166, &dataStack);

 stackNew_CMockExpectAndReturn(1167, &operatorStack);

 tokenizerNew_CMockExpectAndReturn(1168, "+", &tokenizer);



 nextToken_CMockExpectAndReturn(1170, &tokenizer, token1);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  check=evaluate("+",&dataStack,&operatorStack);

   UnityFail( ("Should throw ERR_NOT_DATA"), (_U_UINT)1174);;

  }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

   UnityAssertEqualNumber((_U_SINT)((ERR_NOT_DATA)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)1176, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_should_evaluate_38_space_39_and_throw_error_not_operator(void){

 Stack dataStack;

 Stack operatorStack;

 int check;

 ErrorCode e;



 Tokenizer tokenizer = {.expression = "38 39 +", .startIndex = 0};



 NumberToken number38 = {.type= NUMBER_TOKEN, .value=38};

 Token *token1 = (Token*)&number38;



 NumberToken number39 = {.type= NUMBER_TOKEN, .value=39};

 Token *token2 = (Token*)&number39;



 stackNew_CMockExpectAndReturn(1195, &dataStack);

 stackNew_CMockExpectAndReturn(1196, &operatorStack);

 tokenizerNew_CMockExpectAndReturn(1197, "38 39 +", &tokenizer);



 nextToken_CMockExpectAndReturn(1199, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1200, token1, 1);

 push_CMockExpect(1201, token1, &dataStack);

 nextToken_CMockExpectAndReturn(1202, &tokenizer, token2);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluate("38 39 +",&dataStack,&operatorStack);

   UnityFail( ("Should throw ERR_NOT_OPERATOR"), (_U_UINT)1206);;

  }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

   UnityAssertEqualNumber((_U_SINT)((ERR_NOT_OPERATOR)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)1208, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_should_evaluate_40_plus_multiply_43_and_throw_error_not_data(void){



 Stack dataStack;

 Stack operatorStack;

 int check;

 ErrorCode e;



 Tokenizer tokenizer = {.expression = "40+*43", .startIndex = 0};



 NumberToken number40 = {.type= NUMBER_TOKEN, .value=40};

 Token *token1 = (Token*)&number40;



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 Token *token2 = (Token*)&plus;



 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=100};

 Token *token3 = (Token*)&multiply;



 NumberToken number43 = {.type= NUMBER_TOKEN, .value=43};

 Token *token4 = (Token*)&number43;



 stackNew_CMockExpectAndReturn(1233, &dataStack);

 stackNew_CMockExpectAndReturn(1234, &operatorStack);

 tokenizerNew_CMockExpectAndReturn(1235, "40+*43", &tokenizer);



 nextToken_CMockExpectAndReturn(1237, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1238, token1, 1);

 push_CMockExpect(1239, token1, &dataStack);



 nextToken_CMockExpectAndReturn(1241, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1242, token2, 0);

 isOperator_CMockExpectAndReturn(1243, token2, 1);

 pop_CMockExpectAndReturn(1244, &operatorStack, ((void *)0));

 push_CMockExpect(1245, token2, &operatorStack);



 nextToken_CMockExpectAndReturn(1247, &tokenizer, token3);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluate("40+*43",&dataStack,&operatorStack);

   UnityFail( ("Should throw ERR_NOT_DATA"), (_U_UINT)1251);;

  }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

   UnityAssertEqualNumber((_U_SINT)((ERR_NOT_DATA)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)1253, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_should_evaluate_42_XOR_2_MINUS_and_throw_error_no_data(void){



 Stack dataStack;

 Stack operatorStack;

 int check;

 ErrorCode e;



 Tokenizer tokenizer = {.expression = "42^2-", .startIndex = 0};



 NumberToken number42 = {.type= NUMBER_TOKEN, .value=42};

 Token *token1 = (Token*)&number42;



 OperatorToken xor = {.type= OPERATOR_TOKEN, .name = "^", .precedence=50};

 Token *token2 = (Token*)&xor;



 NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};

 Token *token3 = (Token*)&number2;



 OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-", .precedence=70};

 Token *token4 = (Token*)&minus;



 stackNew_CMockExpectAndReturn(1278, &dataStack);

 stackNew_CMockExpectAndReturn(1279, &operatorStack);

 tokenizerNew_CMockExpectAndReturn(1280, "42^2-", &tokenizer);



 nextToken_CMockExpectAndReturn(1282, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1283, token1, 1);

 push_CMockExpect(1284, token1, &dataStack);



 nextToken_CMockExpectAndReturn(1286, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(1287, token2, 0);

 isOperator_CMockExpectAndReturn(1288, token2, 1);

 pop_CMockExpectAndReturn(1289, &operatorStack, ((void *)0));

 push_CMockExpect(1290, token2, &operatorStack);



 nextToken_CMockExpectAndReturn(1292, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(1293, token3, 1);

 push_CMockExpect(1294, token3, &dataStack);



 nextToken_CMockExpectAndReturn(1296, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(1297, token4, 0);

 isOperator_CMockExpectAndReturn(1298, token4, 1);

 pop_CMockExpectAndReturn(1299, &operatorStack, token2);

 push_CMockExpect(1300, token2, &operatorStack);

 push_CMockExpect(1301, token4, &operatorStack);



 nextToken_CMockExpectAndThrow(1303, &tokenizer, ERR_NOT_DATA);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluate("42^2-",&dataStack,&operatorStack);

   UnityFail( ("Should throw ERR_NOT_DATA"), (_U_UINT)1307);;

  }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

   UnityAssertEqualNumber((_U_SINT)((ERR_NOT_DATA)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)1309, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_should_evaluate_43_HASHTAG_42_and_throw_error_invalid_operator(void){



 Stack dataStack;

 Stack operatorStack;

 int check;

 ErrorCode e;



 Tokenizer tokenizer = {.expression = "43#42", .startIndex = 0};



 NumberToken number43 = {.type= NUMBER_TOKEN, .value=43};

 Token *token1 = (Token*)&number43;



 OperatorToken hashtag = {.type= OPERATOR_TOKEN, .name = "#", .precedence=50};

 Token *token2 = (Token*)&hashtag;



 NumberToken number42 = {.type= NUMBER_TOKEN, .value=42};

 Token *token3 = (Token*)&number42;



 stackNew_CMockExpectAndReturn(1331, &dataStack);

 stackNew_CMockExpectAndReturn(1332, &operatorStack);

 tokenizerNew_CMockExpectAndReturn(1333, "43#42", &tokenizer);



 nextToken_CMockExpectAndReturn(1335, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(1336, token1, 1);

 push_CMockExpect(1337, token1, &dataStack);



 nextToken_CMockExpectAndThrow(1339, &tokenizer, ERR_INVALID_OPERATOR);









 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluate("43#42",&dataStack,&operatorStack);

   UnityFail( ("Should throw ERR_INVALID_OPERATOR"), (_U_UINT)1346);;

  }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

   UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OPERATOR)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)1348, UNITY_DISPLAY_STYLE_INT);

  }

}
