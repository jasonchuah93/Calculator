/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_OPERATOREVALUATE_H
#define _MOCK_OPERATOREVALUATE_H

#include "operatorEvaluate.h"

void mock_operatorEvaluate_Init(void);
void mock_operatorEvaluate_Destroy(void);
void mock_operatorEvaluate_Verify(void);




#define evaluateAllOperatorOnStack_Ignore() evaluateAllOperatorOnStack_CMockIgnore()
void evaluateAllOperatorOnStack_CMockIgnore(void);
#define evaluateAllOperatorOnStack_Expect(numberStack, operatorStack) evaluateAllOperatorOnStack_CMockExpect(__LINE__, numberStack, operatorStack)
void evaluateAllOperatorOnStack_CMockExpect(UNITY_LINE_TYPE cmock_line, Stack* numberStack, Stack* operatorStack);
typedef void (* CMOCK_evaluateAllOperatorOnStack_CALLBACK)(Stack* numberStack, Stack* operatorStack, int cmock_num_calls);
void evaluateAllOperatorOnStack_StubWithCallback(CMOCK_evaluateAllOperatorOnStack_CALLBACK Callback);

#endif