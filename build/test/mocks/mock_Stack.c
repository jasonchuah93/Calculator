/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_Stack.h"

typedef struct _CMOCK_stackNew_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  Stack* ReturnVal;
  int CallOrder;
  CEXCEPTION_T ExceptionToThrow;

} CMOCK_stackNew_CALL_INSTANCE;

typedef struct _CMOCK_push_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  void* Expected_data;
  Stack* Expected_stack;
  CEXCEPTION_T ExceptionToThrow;

} CMOCK_push_CALL_INSTANCE;

typedef struct _CMOCK_pop_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  void* ReturnVal;
  int CallOrder;
  Stack* Expected_stack;
  CEXCEPTION_T ExceptionToThrow;

} CMOCK_pop_CALL_INSTANCE;

static struct mock_StackInstance
{
  int stackNew_IgnoreBool;
  Stack* stackNew_FinalReturn;
  CMOCK_stackNew_CALLBACK stackNew_CallbackFunctionPointer;
  int stackNew_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE stackNew_CallInstance;
  int push_IgnoreBool;
  CMOCK_push_CALLBACK push_CallbackFunctionPointer;
  int push_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE push_CallInstance;
  int pop_IgnoreBool;
  void* pop_FinalReturn;
  CMOCK_pop_CALLBACK pop_CallbackFunctionPointer;
  int pop_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE pop_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_Stack_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.stackNew_IgnoreBool)
    Mock.stackNew_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.stackNew_CallInstance, cmock_line, "Function 'stackNew' called less times than expected.");
  if (Mock.stackNew_CallbackFunctionPointer != NULL)
    Mock.stackNew_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.push_IgnoreBool)
    Mock.push_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.push_CallInstance, cmock_line, "Function 'push' called less times than expected.");
  if (Mock.push_CallbackFunctionPointer != NULL)
    Mock.push_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.pop_IgnoreBool)
    Mock.pop_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.pop_CallInstance, cmock_line, "Function 'pop' called less times than expected.");
  if (Mock.pop_CallbackFunctionPointer != NULL)
    Mock.pop_CallInstance = CMOCK_GUTS_NONE;
}

void mock_Stack_Init(void)
{
  mock_Stack_Destroy();
}

void mock_Stack_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.stackNew_CallbackFunctionPointer = NULL;
  Mock.stackNew_CallbackCalls = 0;
  Mock.push_CallbackFunctionPointer = NULL;
  Mock.push_CallbackCalls = 0;
  Mock.pop_CallbackFunctionPointer = NULL;
  Mock.pop_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

Stack* stackNew(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_stackNew_CALL_INSTANCE* cmock_call_instance = (CMOCK_stackNew_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.stackNew_CallInstance);
  Mock.stackNew_CallInstance = CMock_Guts_MemNext(Mock.stackNew_CallInstance);
  if (Mock.stackNew_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.stackNew_FinalReturn;
    Mock.stackNew_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.stackNew_CallbackFunctionPointer != NULL)
  {
    return Mock.stackNew_CallbackFunctionPointer(Mock.stackNew_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'stackNew' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'stackNew' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'stackNew' called later than expected.");
  if (cmock_call_instance->ExceptionToThrow != CEXCEPTION_NONE)
  {
    Throw(cmock_call_instance->ExceptionToThrow);
  }
  return cmock_call_instance->ReturnVal;
}

void stackNew_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, Stack* cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_stackNew_CALL_INSTANCE));
  CMOCK_stackNew_CALL_INSTANCE* cmock_call_instance = (CMOCK_stackNew_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.stackNew_CallInstance = CMock_Guts_MemChain(Mock.stackNew_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExceptionToThrow = CEXCEPTION_NONE;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.stackNew_IgnoreBool = (int)1;
}

void stackNew_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, Stack* cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_stackNew_CALL_INSTANCE));
  CMOCK_stackNew_CALL_INSTANCE* cmock_call_instance = (CMOCK_stackNew_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.stackNew_CallInstance = CMock_Guts_MemChain(Mock.stackNew_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExceptionToThrow = CEXCEPTION_NONE;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void stackNew_StubWithCallback(CMOCK_stackNew_CALLBACK Callback)
{
  Mock.stackNew_CallbackFunctionPointer = Callback;
}

void stackNew_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, CEXCEPTION_T cmock_to_throw)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_stackNew_CALL_INSTANCE));
  CMOCK_stackNew_CALL_INSTANCE* cmock_call_instance = (CMOCK_stackNew_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.stackNew_CallInstance = CMock_Guts_MemChain(Mock.stackNew_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExceptionToThrow = CEXCEPTION_NONE;
  cmock_call_instance->ExceptionToThrow = cmock_to_throw;
}

void push(void* data, Stack* stack)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_push_CALL_INSTANCE* cmock_call_instance = (CMOCK_push_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.push_CallInstance);
  Mock.push_CallInstance = CMock_Guts_MemNext(Mock.push_CallInstance);
  if (Mock.push_IgnoreBool)
  {
    return;
  }
  if (Mock.push_CallbackFunctionPointer != NULL)
  {
    Mock.push_CallbackFunctionPointer(data, stack, Mock.push_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'push' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'push' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'push' called later than expected.");
  UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_data, data, cmock_line, "Function 'push' called with unexpected value for argument 'data'.");
  UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_stack), (void*)(stack), sizeof(Stack), cmock_line, "Function 'push' called with unexpected value for argument 'stack'.");
  if (cmock_call_instance->ExceptionToThrow != CEXCEPTION_NONE)
  {
    Throw(cmock_call_instance->ExceptionToThrow);
  }
}

void CMockExpectParameters_push(CMOCK_push_CALL_INSTANCE* cmock_call_instance, void* data, Stack* stack)
{
  cmock_call_instance->Expected_data = data;
  cmock_call_instance->Expected_stack = stack;
}

void push_CMockIgnore(void)
{
  Mock.push_IgnoreBool = (int)1;
}

void push_CMockExpect(UNITY_LINE_TYPE cmock_line, void* data, Stack* stack)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_push_CALL_INSTANCE));
  CMOCK_push_CALL_INSTANCE* cmock_call_instance = (CMOCK_push_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.push_CallInstance = CMock_Guts_MemChain(Mock.push_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExceptionToThrow = CEXCEPTION_NONE;
  CMockExpectParameters_push(cmock_call_instance, data, stack);
}

void push_StubWithCallback(CMOCK_push_CALLBACK Callback)
{
  Mock.push_CallbackFunctionPointer = Callback;
}

void push_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, void* data, Stack* stack, CEXCEPTION_T cmock_to_throw)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_push_CALL_INSTANCE));
  CMOCK_push_CALL_INSTANCE* cmock_call_instance = (CMOCK_push_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.push_CallInstance = CMock_Guts_MemChain(Mock.push_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExceptionToThrow = CEXCEPTION_NONE;
  CMockExpectParameters_push(cmock_call_instance, data, stack);
  cmock_call_instance->ExceptionToThrow = cmock_to_throw;
}

void* pop(Stack* stack)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_pop_CALL_INSTANCE* cmock_call_instance = (CMOCK_pop_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.pop_CallInstance);
  Mock.pop_CallInstance = CMock_Guts_MemNext(Mock.pop_CallInstance);
  if (Mock.pop_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.pop_FinalReturn;
    Mock.pop_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.pop_CallbackFunctionPointer != NULL)
  {
    return Mock.pop_CallbackFunctionPointer(stack, Mock.pop_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'pop' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'pop' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'pop' called later than expected.");
  UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_stack), (void*)(stack), sizeof(Stack), cmock_line, "Function 'pop' called with unexpected value for argument 'stack'.");
  if (cmock_call_instance->ExceptionToThrow != CEXCEPTION_NONE)
  {
    Throw(cmock_call_instance->ExceptionToThrow);
  }
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_pop(CMOCK_pop_CALL_INSTANCE* cmock_call_instance, Stack* stack)
{
  cmock_call_instance->Expected_stack = stack;
}

void pop_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, void* cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_pop_CALL_INSTANCE));
  CMOCK_pop_CALL_INSTANCE* cmock_call_instance = (CMOCK_pop_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.pop_CallInstance = CMock_Guts_MemChain(Mock.pop_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExceptionToThrow = CEXCEPTION_NONE;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.pop_IgnoreBool = (int)1;
}

void pop_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, Stack* stack, void* cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_pop_CALL_INSTANCE));
  CMOCK_pop_CALL_INSTANCE* cmock_call_instance = (CMOCK_pop_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.pop_CallInstance = CMock_Guts_MemChain(Mock.pop_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExceptionToThrow = CEXCEPTION_NONE;
  CMockExpectParameters_pop(cmock_call_instance, stack);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void pop_StubWithCallback(CMOCK_pop_CALLBACK Callback)
{
  Mock.pop_CallbackFunctionPointer = Callback;
}

void pop_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, Stack* stack, CEXCEPTION_T cmock_to_throw)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_pop_CALL_INSTANCE));
  CMOCK_pop_CALL_INSTANCE* cmock_call_instance = (CMOCK_pop_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.pop_CallInstance = CMock_Guts_MemChain(Mock.pop_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExceptionToThrow = CEXCEPTION_NONE;
  CMockExpectParameters_pop(cmock_call_instance, stack);
  cmock_call_instance->ExceptionToThrow = cmock_to_throw;
}

