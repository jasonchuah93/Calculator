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











void test_shunting_yard_should_return_0_if_the_expression_is_null(){

 int check;

 Stack dataStack;

 Stack operatorStack;

 ErrorCode e;

 Tokenizer tokenizer = {.expression = "0", .startIndex = 0};



 NumberToken number2 = {.type= NUMBER_TOKEN, .value=0};

 Token *token1 = (Token*)&number2;



 tokenizerNew_CMockExpectAndReturn(34, ((void *)0), &tokenizer);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  check = evaluate(((void *)0),&dataStack,&operatorStack);

  UnityFail( ("Should throw Error no expression "), (_U_UINT)39);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_EXPRESSION)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_evaluate_should_throw_error_when_encounter_invalid_operator(void){



 Stack dataStack;

 Token *tempToken;

 NumberToken *tempAns;

 ErrorCode e;





 Tokenizer tokenizer = {.expression = "1@2", .startIndex = 0};

 NumberToken number1 = {.type= NUMBER_TOKEN, .value=1};

 OperatorToken alpha = {.type= OPERATOR_TOKEN, .name = "@", .precedence =0};

 NumberToken number2 = {.type= NUMBER_TOKEN, .value=2};



 pop_CMockExpectAndReturn(60, &dataStack, &number1);

 pop_CMockExpectAndReturn(61, &dataStack, &number2);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  evaluateOperator(&dataStack,&alpha);

  UnityFail( ("Invalid Operator should throw Error Not Operator"), (_U_UINT)65);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NOT_OPERATOR)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

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

 Token *answer;



 pop_CMockExpectAndReturn(86, &dataStack, &number2);

 pop_CMockExpectAndReturn(87, &dataStack, &number1);

 createNumberToken_CMockExpectAndReturn(88, 3, answer);

 push_CMockExpect(89, answer, &dataStack);



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

 Token *answer;



 pop_CMockExpectAndReturn(107, &dataStack, &number7);

 pop_CMockExpectAndReturn(108, &dataStack, &number100);

 createNumberToken_CMockExpectAndReturn(109, 93, answer);

 push_CMockExpect(110, answer, &dataStack);



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

 Token *answer;



 pop_CMockExpectAndReturn(130, &dataStack, &number7);

 pop_CMockExpectAndReturn(131, &dataStack, &number60);

 createNumberToken_CMockExpectAndReturn(132, 420, answer);

 push_CMockExpect(133, answer, &dataStack);



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

 Token *answer;



 pop_CMockExpectAndReturn(152, &dataStack, &number5);

 pop_CMockExpectAndReturn(153, &dataStack, &number60);

 createNumberToken_CMockExpectAndReturn(154, 12, answer);

 push_CMockExpect(155, answer, &dataStack);



 evaluateOperator(&dataStack,&divide);

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

 OperatorToken modulus = {.type= OPERATOR_TOKEN, .name = "%"};

 NumberToken number7 = {.type= NUMBER_TOKEN, .value=7};

 Token *answer;



 pop_CMockExpectAndReturn(174, &dataStack, &number7);

 pop_CMockExpectAndReturn(175, &dataStack, &number60);

 createNumberToken_CMockExpectAndReturn(176, 4, answer);

 push_CMockExpect(177, answer, &dataStack);



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

 Token *answer;



 pop_CMockExpectAndReturn(196, &dataStack, &number30);

 pop_CMockExpectAndReturn(197, &dataStack, &number56);

 createNumberToken_CMockExpectAndReturn(198, 24, answer);

 push_CMockExpect(199, answer, &dataStack);



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

 Token *answer;



 pop_CMockExpectAndReturn(218, &dataStack, &number20);

 pop_CMockExpectAndReturn(219, &dataStack, &number90);

 createNumberToken_CMockExpectAndReturn(220, 94, answer);

 push_CMockExpect(221, answer, &dataStack);



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

 Token *answer;



 pop_CMockExpectAndReturn(240, &dataStack, &number66);

 pop_CMockExpectAndReturn(241, &dataStack, &number99);

 createNumberToken_CMockExpectAndReturn(242, 33, answer);

 push_CMockExpect(243, answer, &dataStack);



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

 Token *answer;



 pop_CMockExpectAndReturn(261, &dataStack, &number35);

 pop_CMockExpectAndReturn(262, &dataStack, &number90);

 createNumberToken_CMockExpectAndReturn(263, 55, answer);

 push_CMockExpect(264, answer, &dataStack);



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

 Token *answer;



 pop_CMockExpectAndReturn(283, &dataStack, &number50);

 pop_CMockExpectAndReturn(284, &dataStack, &number16);

 createNumberToken_CMockExpectAndReturn(285, 16, answer);

 push_CMockExpect(286, answer, &dataStack);



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



 NumberToken number5 = {.type= NUMBER_TOKEN, .value=5};

 Token *tempAnswer = (Token*)&number5;



 Token *finalAnswer;





 pop_CMockExpectAndReturn(320, &operatorStack, &plus);

 pop_CMockExpectAndReturn(321, &dataStack, &number3);

 pop_CMockExpectAndReturn(322, &dataStack, &number2);

 createNumberToken_CMockExpectAndReturn(323, 5, tempAnswer);

 push_CMockExpect(324, tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(327, &operatorStack, &plus);

 pop_CMockExpectAndReturn(328, &dataStack, &number4);

 pop_CMockExpectAndReturn(329, &dataStack, tempAnswer);

 createNumberToken_CMockExpectAndReturn(330, 9, finalAnswer);

 push_CMockExpect(331, finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(332, &operatorStack, ((void *)0));



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



 NumberToken number13 = {.type= NUMBER_TOKEN, .value=13};

 Token *tempAnswer = (Token*)&number13;



 Token *finalAnswer;





 pop_CMockExpectAndReturn(362, &operatorStack, &plus);

 pop_CMockExpectAndReturn(363, &dataStack, &number3);

 pop_CMockExpectAndReturn(364, &dataStack, &number10);

 createNumberToken_CMockExpectAndReturn(365, 13, tempAnswer);

 push_CMockExpect(366, tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(369, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(370, &dataStack, &number9);

 pop_CMockExpectAndReturn(371, &dataStack, tempAnswer);

 createNumberToken_CMockExpectAndReturn(372, 117, finalAnswer);

 push_CMockExpect(373, finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(374, &operatorStack, ((void *)0));



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



 NumberToken number20 = {.type= NUMBER_TOKEN, .value=20};

 Token *tempAnswer = (Token*)&number20;



 Token *finalAnswer;





 pop_CMockExpectAndReturn(404, &operatorStack, &divide);

 pop_CMockExpectAndReturn(405, &dataStack, &number5);

 pop_CMockExpectAndReturn(406, &dataStack, &number100);

 createNumberToken_CMockExpectAndReturn(407, 20, tempAnswer);

 push_CMockExpect(408, tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(411, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(412, &dataStack, &number6);

 pop_CMockExpectAndReturn(413, &dataStack, tempAnswer);

 createNumberToken_CMockExpectAndReturn(414, 120, finalAnswer);

 push_CMockExpect(415, finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(416, &operatorStack, ((void *)0));



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



 NumberToken number33 = {.type= NUMBER_TOKEN, .value=33};

 Token *tempAnswer = (Token*)&number33;



 Token *finalAnswer;





 pop_CMockExpectAndReturn(446, &operatorStack, &XOR);

 pop_CMockExpectAndReturn(447, &dataStack, &number66);

 pop_CMockExpectAndReturn(448, &dataStack, &number99);

 createNumberToken_CMockExpectAndReturn(449, 33, tempAnswer);

 push_CMockExpect(450, tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(453, &operatorStack, &divide);

 pop_CMockExpectAndReturn(454, &dataStack, &number11);

 pop_CMockExpectAndReturn(455, &dataStack, tempAnswer);

 createNumberToken_CMockExpectAndReturn(456, 3, finalAnswer);

 push_CMockExpect(457, finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(458, &operatorStack, ((void *)0));



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



 NumberToken number20 = {.type= NUMBER_TOKEN, .value=20};

 Token *tempAns =(Token*)&number20;



 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*"};



 NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};



 NumberToken number120 = {.type= NUMBER_TOKEN, .value=120};

 Token *tempAns2 =(Token*)&number120;



 OperatorToken add = {.type= OPERATOR_TOKEN, .name = "+"};



 NumberToken number99 = {.type= NUMBER_TOKEN, .value=99};



 NumberToken number219 = {.type= NUMBER_TOKEN, .value=219};

 Token *tempAns3 =(Token*)&number219;



 OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-"};



 NumberToken number20a = {.type= NUMBER_TOKEN, .value=20};



 Token *finalAnswer;





 pop_CMockExpectAndReturn(502, &operatorStack, &divide);

 pop_CMockExpectAndReturn(503, &dataStack, &number5);

 pop_CMockExpectAndReturn(504, &dataStack, &number100);

 createNumberToken_CMockExpectAndReturn(505, 20, tempAns);

 push_CMockExpect(506, tempAns, &dataStack);





 pop_CMockExpectAndReturn(509, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(510, &dataStack, &number6);

 pop_CMockExpectAndReturn(511, &dataStack, tempAns);

 createNumberToken_CMockExpectAndReturn(512, 120, tempAns2);

 push_CMockExpect(513, tempAns2, &dataStack);





 pop_CMockExpectAndReturn(516, &operatorStack, &add);

 pop_CMockExpectAndReturn(517, &dataStack, &number99);

 pop_CMockExpectAndReturn(518, &dataStack, tempAns2);

 createNumberToken_CMockExpectAndReturn(519, 219, tempAns3);

 push_CMockExpect(520, tempAns3, &dataStack);





 pop_CMockExpectAndReturn(523, &operatorStack, &minus);

 pop_CMockExpectAndReturn(524, &dataStack, &number20a);

 pop_CMockExpectAndReturn(525, &dataStack, tempAns3);

 createNumberToken_CMockExpectAndReturn(526, 199, finalAnswer);

 push_CMockExpect(527, finalAnswer, &dataStack);



 pop_CMockExpectAndReturn(529, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&dataStack,&operatorStack);

}











void test_tryEvaluateOperatorOnStaclThenPush_will_push_OperatorTOken_if_Operator_Stack_is_empty(void){

 Stack dataStack;

 Stack operatorStack;

 OperatorToken *opeToken;



 pop_CMockExpectAndReturn(543, &operatorStack, ((void *)0));

 push_CMockExpect(544, opeToken, &operatorStack);

 tryEvaluateOperatorOnStackThenPush(opeToken,&dataStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStaclThenPush_will_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_higher_than_previousToken(void)

{

 Stack dataStack;

 Stack operatorStack;



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=100};



 pop_CMockExpectAndReturn(556, &operatorStack, &plus);

 push_CMockExpect(557, &plus, &operatorStack);

 push_CMockExpect(558, &multiply, &operatorStack);

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



 Token *tempAns;



 pop_CMockExpectAndReturn(576, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(577, &dataStack, &number2);

 pop_CMockExpectAndReturn(578, &dataStack, &number1);

 createNumberToken_CMockExpectAndReturn(579, 2, tempAns);

 push_CMockExpect(580, tempAns, &dataStack);

 pop_CMockExpectAndReturn(581, &operatorStack, ((void *)0));

 push_CMockExpect(582, &plus, &operatorStack);



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



 Token *tempAns;



 pop_CMockExpectAndReturn(601, &operatorStack, &minus);

 pop_CMockExpectAndReturn(602, &dataStack, &number20);

 pop_CMockExpectAndReturn(603, &dataStack, &number100);

 createNumberToken_CMockExpectAndReturn(604, 80, tempAns);

 push_CMockExpect(605, tempAns, &dataStack);

 pop_CMockExpectAndReturn(606, &operatorStack, ((void *)0));

 push_CMockExpect(607, &minusA, &operatorStack);

 tryEvaluateOperatorOnStackThenPush(&minusA,&dataStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_1(void)

{

 Stack dataStack;

 Stack operatorStack;



 NumberToken number21 = {.type= NUMBER_TOKEN, .value=21};

 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=100};

 NumberToken number22 = {.type= NUMBER_TOKEN, .value=22};







 Token *tempAns1;



 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 NumberToken number30 = {.type= NUMBER_TOKEN, .value=30};

 OperatorToken divide = {.type= OPERATOR_TOKEN, .name = "/", .precedence=100};

 NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};





 pop_CMockExpectAndReturn(630, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(631, &dataStack, &number22);

 pop_CMockExpectAndReturn(632, &dataStack, &number21);

 createNumberToken_CMockExpectAndReturn(633, 462, tempAns1);

 push_CMockExpect(634, tempAns1, &dataStack);



 pop_CMockExpectAndReturn(636, &operatorStack, &plus);

 push_CMockExpect(637, &plus, &operatorStack);

 push_CMockExpect(638, &divide, &operatorStack);



 tryEvaluateOperatorOnStackThenPush(&divide,&dataStack,&operatorStack);

}



void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_2(void)

{

 Stack dataStack;

 Stack operatorStack;



 NumberToken number21 = {.type= NUMBER_TOKEN, .value=21};

 OperatorToken plus = {.type= OPERATOR_TOKEN, .name = "+", .precedence=70};

 NumberToken number22 = {.type= NUMBER_TOKEN, .value=22};



 OperatorToken bitwiseAND = {.type= OPERATOR_TOKEN, .name = "&", .precedence=20};

 NumberToken number30 = {.type= NUMBER_TOKEN, .value=30};

 OperatorToken bitwiseOR = {.type= OPERATOR_TOKEN, .name = "|", .precedence=10};

 NumberToken number6 = {.type= NUMBER_TOKEN, .value=6};









 Token *tempAns1;

 Token *tempAns2;





 pop_CMockExpectAndReturn(664, &operatorStack, &plus);

 pop_CMockExpectAndReturn(665, &dataStack, &number22);

 pop_CMockExpectAndReturn(666, &dataStack, &number21);

 createNumberToken_CMockExpectAndReturn(667, 43, tempAns1);

 push_CMockExpect(668, tempAns1, &dataStack);



 pop_CMockExpectAndReturn(670, &operatorStack, &bitwiseAND);

 pop_CMockExpectAndReturn(671, &dataStack, &number30);

 pop_CMockExpectAndReturn(672, &dataStack, &number6);

 createNumberToken_CMockExpectAndReturn(673, 6, tempAns2);

 push_CMockExpect(674, tempAns2, &dataStack);



 pop_CMockExpectAndReturn(676, &operatorStack, ((void *)0));

 push_CMockExpect(677, &bitwiseOR, &operatorStack);

 tryEvaluateOperatorOnStackThenPush(&bitwiseOR,&dataStack,&operatorStack);

}
