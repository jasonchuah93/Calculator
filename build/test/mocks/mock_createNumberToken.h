/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_CREATENUMBERTOKEN_H
#define _MOCK_CREATENUMBERTOKEN_H

#include "createNumberToken.h"

void mock_createNumberToken_Init(void);
void mock_createNumberToken_Destroy(void);
void mock_createNumberToken_Verify(void);




#define createNumberToken_IgnoreAndReturn(cmock_retval) createNumberToken_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void createNumberToken_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, Token* cmock_to_return);
#define createNumberToken_ExpectAndReturn(number, cmock_retval) createNumberToken_CMockExpectAndReturn(__LINE__, number, cmock_retval)
void createNumberToken_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int number, Token* cmock_to_return);
typedef Token* (* CMOCK_createNumberToken_CALLBACK)(int number, int cmock_num_calls);
void createNumberToken_StubWithCallback(CMOCK_createNumberToken_CALLBACK Callback);

#endif
