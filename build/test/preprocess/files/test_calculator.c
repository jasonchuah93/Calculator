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





 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(56, &operatorStack, &plus);

 pop_CMockExpectAndReturn(57, &dataStack, &number1);

 pop_CMockExpectAndReturn(58, &dataStack, &number2);

 createNumberToken_CMockExpectAndReturn(59, 3, answer);

 push_CMockExpect(60, answer, &dataStack);



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





 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(87, &operatorStack, &minus);

 pop_CMockExpectAndReturn(88, &dataStack, &number100);

 pop_CMockExpectAndReturn(89, &dataStack, &number7);

 createNumberToken_CMockExpectAndReturn(90, 93, answer);

 push_CMockExpect(91, answer, &dataStack);



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





 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(118, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(119, &dataStack, &number60);

 pop_CMockExpectAndReturn(120, &dataStack, &number7);

 createNumberToken_CMockExpectAndReturn(121, 420, answer);

 push_CMockExpect(122, answer, &dataStack);



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





 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(149, &operatorStack, &divide);

 pop_CMockExpectAndReturn(150, &dataStack, &number60);

 pop_CMockExpectAndReturn(151, &dataStack, &number5);

 createNumberToken_CMockExpectAndReturn(152, 12, answer);

 push_CMockExpect(153, answer, &dataStack);



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





 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(180, &operatorStack, &modulus);

 pop_CMockExpectAndReturn(181, &dataStack, &number60);

 pop_CMockExpectAndReturn(182, &dataStack, &number7);

 createNumberToken_CMockExpectAndReturn(183, 4, answer);

 push_CMockExpect(184, answer, &dataStack);



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





 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(211, &operatorStack, &bitwiseand);

 pop_CMockExpectAndReturn(212, &dataStack, &number56);

 pop_CMockExpectAndReturn(213, &dataStack, &number30);

 createNumberToken_CMockExpectAndReturn(214, 24, answer);

 push_CMockExpect(215, answer, &dataStack);



 evaluateOperator(&dataStack,&operatorStack);

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

 Token *token1 = (Token*)&number90;



 OperatorToken bitwiseor = {.type= OPERATOR_TOKEN, .name = "|"};

 Token *token2 = (Token*)&bitwiseor;



 NumberToken number20 = {.type= NUMBER_TOKEN, .value=20};

 Token *token3 = (Token*)&number20;





 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(242, &operatorStack, &bitwiseor);

 pop_CMockExpectAndReturn(243, &dataStack, &number90);

 pop_CMockExpectAndReturn(244, &dataStack, &number20);

 createNumberToken_CMockExpectAndReturn(245, 94, answer);

 push_CMockExpect(246, answer, &dataStack);



 evaluateOperator(&dataStack,&operatorStack);

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

 Token *token1 = (Token*)&number99;



 OperatorToken bitwisexor = {.type= OPERATOR_TOKEN, .name = "^"};

 Token *token2 = (Token*)&bitwisexor;



 NumberToken number66 = {.type= NUMBER_TOKEN, .value=66};

 Token *token3 = (Token*)&number66;



 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(272, &operatorStack, &bitwisexor);

 pop_CMockExpectAndReturn(273, &dataStack, &number99);

 pop_CMockExpectAndReturn(274, &dataStack, &number66);

 createNumberToken_CMockExpectAndReturn(275, 33, answer);

 push_CMockExpect(276, answer, &dataStack);



 evaluateOperator(&dataStack,&operatorStack);

}



void test_evaluate_90_MINUS_35(void){

 Stack dataStack;

 Stack operatorStack;

 Token *tempToken;

 NumberToken *tempAns;

 int check;



 Tokenizer tokenizer = {.expression = "90-35", .startIndex = 0};



 NumberToken number90 = {.type= NUMBER_TOKEN, .value=90};

 Token *token1 = (Token*)&number90;



 OperatorToken minus = {.type= OPERATOR_TOKEN, .name = "-"};

 Token *token2 = (Token*)&minus;



 NumberToken number35 = {.type= NUMBER_TOKEN, .value=35};

 Token *token3 = (Token*)&number35;





 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(302, &operatorStack, &minus);

 pop_CMockExpectAndReturn(303, &dataStack, &number90);

 pop_CMockExpectAndReturn(304, &dataStack, &number35);

 createNumberToken_CMockExpectAndReturn(305, 55, answer);

 push_CMockExpect(306, answer, &dataStack);



 evaluateOperator(&dataStack,&operatorStack);

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

 Token *token1 = (Token*)&number16;



 OperatorToken bitwiseand = {.type= OPERATOR_TOKEN, .name = "&"};

 Token *token2 = (Token*)&bitwiseand;



 NumberToken number50 = {.type= NUMBER_TOKEN, .value=50};

 Token *token3 = (Token*)&number50;





 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(333, &operatorStack, &bitwiseand);

 pop_CMockExpectAndReturn(334, &dataStack, &number16);

 pop_CMockExpectAndReturn(335, &dataStack, &number50);

 createNumberToken_CMockExpectAndReturn(336, 16, answer);

 push_CMockExpect(337, answer, &dataStack);



 evaluateOperator(&dataStack,&operatorStack);

}



void test_evaluate_2_plus_3_plus_4(void){

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



 Token *finalAnswer = (Token*)&finalAnswer;





 pop_CMockExpectAndReturn(367, &operatorStack, &plus);

 pop_CMockExpectAndReturn(368, &dataStack, &number2);

 pop_CMockExpectAndReturn(369, &dataStack, &number3);

 createNumberToken_CMockExpectAndReturn(370, 5, tempAnswer);

 push_CMockExpect(371, tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(374, &operatorStack, &plus);

 pop_CMockExpectAndReturn(375, &dataStack, tempAnswer);

 pop_CMockExpectAndReturn(376, &dataStack, &number4);

 createNumberToken_CMockExpectAndReturn(377, 9, finalAnswer);

 push_CMockExpect(378, finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(379, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&dataStack,&operatorStack);

}



void test_evaluate_10_plus_3_multiply_9(void){

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



 Token *finalAnswer = (Token*)&finalAnswer;





 pop_CMockExpectAndReturn(409, &operatorStack, &plus);

 pop_CMockExpectAndReturn(410, &dataStack, &number10);

 pop_CMockExpectAndReturn(411, &dataStack, &number3);

 createNumberToken_CMockExpectAndReturn(412, 13, tempAnswer);

 push_CMockExpect(413, tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(416, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(417, &dataStack, tempAnswer);

 pop_CMockExpectAndReturn(418, &dataStack, &number9);

 createNumberToken_CMockExpectAndReturn(419, 117, finalAnswer);

 push_CMockExpect(420, finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(421, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&dataStack,&operatorStack);

}



void test_evaluate_100_divide_5_multiply_6(void){

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



 Token *finalAnswer = (Token*)&finalAnswer;





 pop_CMockExpectAndReturn(451, &operatorStack, &divide);

 pop_CMockExpectAndReturn(452, &dataStack, &number100);

 pop_CMockExpectAndReturn(453, &dataStack, &number5);

 createNumberToken_CMockExpectAndReturn(454, 20, tempAnswer);

 push_CMockExpect(455, tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(458, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(459, &dataStack, tempAnswer);

 pop_CMockExpectAndReturn(460, &dataStack, &number6);

 createNumberToken_CMockExpectAndReturn(461, 120, finalAnswer);

 push_CMockExpect(462, finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(463, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&dataStack,&operatorStack);

}



void test_evaluate_99_XOR_66_divide_11(void){

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



 Token *finalAnswer = (Token*)&finalAnswer;





 pop_CMockExpectAndReturn(493, &operatorStack, &XOR);

 pop_CMockExpectAndReturn(494, &dataStack, &number99);

 pop_CMockExpectAndReturn(495, &dataStack, &number66);

 createNumberToken_CMockExpectAndReturn(496, 33, tempAnswer);

 push_CMockExpect(497, tempAnswer, &dataStack);





 pop_CMockExpectAndReturn(500, &operatorStack, &divide);

 pop_CMockExpectAndReturn(501, &dataStack, tempAnswer);

 pop_CMockExpectAndReturn(502, &dataStack, &number11);

 createNumberToken_CMockExpectAndReturn(503, 3, finalAnswer);

 push_CMockExpect(504, finalAnswer, &dataStack);

 pop_CMockExpectAndReturn(505, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&dataStack,&operatorStack);

}



void test_evaluate_100_divide_5_multiply_6_plus_99_minus_20(void){

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



 Token *finalAnswer = (Token*)&finalAnswer;





 pop_CMockExpectAndReturn(549, &operatorStack, &divide);

 pop_CMockExpectAndReturn(550, &dataStack, &number100);

 pop_CMockExpectAndReturn(551, &dataStack, &number5);

 createNumberToken_CMockExpectAndReturn(552, 20, tempAns);

 push_CMockExpect(553, tempAns, &dataStack);





 pop_CMockExpectAndReturn(556, &operatorStack, &multiply);

 pop_CMockExpectAndReturn(557, &dataStack, tempAns);

 pop_CMockExpectAndReturn(558, &dataStack, &number6);

 createNumberToken_CMockExpectAndReturn(559, 120, tempAns2);

 push_CMockExpect(560, tempAns2, &dataStack);





 pop_CMockExpectAndReturn(563, &operatorStack, &add);

 pop_CMockExpectAndReturn(564, &dataStack, tempAns2);

 pop_CMockExpectAndReturn(565, &dataStack, &number99);

 createNumberToken_CMockExpectAndReturn(566, 219, tempAns3);

 push_CMockExpect(567, tempAns3, &dataStack);





 pop_CMockExpectAndReturn(570, &operatorStack, &minus);

 pop_CMockExpectAndReturn(571, &dataStack, tempAns3);

 pop_CMockExpectAndReturn(572, &dataStack, &number20a);

 createNumberToken_CMockExpectAndReturn(573, 199, finalAnswer);

 push_CMockExpect(574, finalAnswer, &dataStack);



 pop_CMockExpectAndReturn(576, &operatorStack, ((void *)0));



 evaluateAllOperatorOnStack(&dataStack,&operatorStack);

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





 tokenizerNew_CMockExpectAndReturn(632, "1+2", &tokenizer);



 nextToken_CMockExpectAndReturn(634, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(635, token1, 1);

 push_CMockExpect(636, token1, &dataStack);





 nextToken_CMockExpectAndReturn(639, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(640, token2, 0);

 isOperator_CMockExpectAndReturn(641, token2, 1);

 push_CMockExpect(642, token2, &operatorStack);





 nextToken_CMockExpectAndReturn(645, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(646, token3, 1);

 push_CMockExpect(647, token3, &dataStack);

 nextToken_CMockExpectAndReturn(648, &tokenizer, ((void *)0));



 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(652, &operatorStack, token2);

 pop_CMockExpectAndReturn(653, &dataStack, token1);

 pop_CMockExpectAndReturn(654, &dataStack, token3);

 createNumberToken_CMockExpectAndReturn(655, 3, answer);

 push_CMockExpect(656, answer, &dataStack);

 pop_CMockExpectAndReturn(657, &operatorStack, ((void *)0));



 evaluate("1+2",&dataStack,&operatorStack);



}



void test_should_return_12_for_4_multiply_3(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



 Tokenizer tokenizer = {.expression = "4*3", .startIndex = 0};



 NumberToken number4 = {.type= NUMBER_TOKEN, .value=4};

 Token *token1 = (Token*)&number4;



 OperatorToken multiply = {.type= OPERATOR_TOKEN, .name = "*", .precedence=70};

 Token *token2 = (Token*)&multiply;



 NumberToken number3 = {.type= NUMBER_TOKEN, .value=3};

 Token *token3 = (Token*)&number3;





 tokenizerNew_CMockExpectAndReturn(680, "4*3", &tokenizer);



 nextToken_CMockExpectAndReturn(682, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(683, token1, 1);

 push_CMockExpect(684, token1, &dataStack);





 nextToken_CMockExpectAndReturn(687, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(688, token2, 0);

 isOperator_CMockExpectAndReturn(689, token2, 1);

 push_CMockExpect(690, token2, &operatorStack);





 nextToken_CMockExpectAndReturn(693, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(694, token3, 1);

 push_CMockExpect(695, token3, &dataStack);

 nextToken_CMockExpectAndReturn(696, &tokenizer, ((void *)0));



 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(700, &operatorStack, token2);

 pop_CMockExpectAndReturn(701, &dataStack, token1);

 pop_CMockExpectAndReturn(702, &dataStack, token3);

 createNumberToken_CMockExpectAndReturn(703, 12, answer);

 push_CMockExpect(704, answer, &dataStack);

 pop_CMockExpectAndReturn(705, &operatorStack, ((void *)0));



 evaluate("4*3",&dataStack,&operatorStack);



}



void test_should_return_6_for_3_plus_4_plus_5_minus_6(void){

 Stack dataStack;

 Stack operatorStack;

 int check;



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





 tokenizerNew_CMockExpectAndReturn(749, "3+4+5-6", &tokenizer);



 nextToken_CMockExpectAndReturn(751, &tokenizer, token1);

 isNumber_CMockExpectAndReturn(752, token1, 1);

 push_CMockExpect(753, token1, &dataStack);



 nextToken_CMockExpectAndReturn(755, &tokenizer, token2);

 isNumber_CMockExpectAndReturn(756, token2, 0);

 isOperator_CMockExpectAndReturn(757, token2, 1);

 push_CMockExpect(758, token2, &operatorStack);



 nextToken_CMockExpectAndReturn(760, &tokenizer, token3);

 isNumber_CMockExpectAndReturn(761, token3, 1);

 push_CMockExpect(762, token3, &dataStack);



 nextToken_CMockExpectAndReturn(764, &tokenizer, token4);

 isNumber_CMockExpectAndReturn(765, token4, 1);

 push_CMockExpect(766, token4, &dataStack);





 nextToken_CMockExpectAndReturn(769, &tokenizer, token5);

 isNumber_CMockExpectAndReturn(770, token5, 1);

 push_CMockExpect(771, token5, &dataStack);



 nextToken_CMockExpectAndReturn(773, &tokenizer, token6);

 isNumber_CMockExpectAndReturn(774, token6, 1);

 push_CMockExpect(775, token6, &dataStack);





 nextToken_CMockExpectAndReturn(778, &tokenizer, token7);

 isNumber_CMockExpectAndReturn(779, token7, 1);

 push_CMockExpect(780, token7, &dataStack);

 nextToken_CMockExpectAndReturn(781, &tokenizer, ((void *)0));



 Token *answer = (Token*)&answer;



 pop_CMockExpectAndReturn(785, &operatorStack, token2);

 pop_CMockExpectAndReturn(786, &dataStack, token1);

 pop_CMockExpectAndReturn(787, &dataStack, token3);

 createNumberToken_CMockExpectAndReturn(788, 7, tempAns);

 push_CMockExpect(789, tempAns, &dataStack);





 pop_CMockExpectAndReturn(792, &operatorStack, token4);

 pop_CMockExpectAndReturn(793, &dataStack, tempAns);

 pop_CMockExpectAndReturn(794, &dataStack, token5);

 createNumberToken_CMockExpectAndReturn(795, 12, tempAns2);

 push_CMockExpect(796, tempAns2, &dataStack);





 pop_CMockExpectAndReturn(799, &operatorStack, token6);

 pop_CMockExpectAndReturn(800, &dataStack, tempAns2);

 pop_CMockExpectAndReturn(801, &dataStack, token7);

 createNumberToken_CMockExpectAndReturn(802, 6, finalAns);

 push_CMockExpect(803, finalAns, &dataStack);

 pop_CMockExpectAndReturn(804, &operatorStack, ((void *)0));

 evaluate("3+4+5-6",&dataStack,&operatorStack);



}
