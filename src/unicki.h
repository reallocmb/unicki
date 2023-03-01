#ifndef UNICKI_H
#define UNICKI_H

// ui.h
#include<stdio.h>
#include<stdlib.h>

#define COLOR_DEFAULT "\x1B[0m"
#define COLOR_RED "\x1B[31m"
#define COLOR_GREEN "\x1B[32m"
#define COLOR_WHITE "\x1B[47m"

#define PASSED_SIGN "\x1B[32m\u2714\x1B[0m"
#define FAILED_SIGN COLOR_RED "\u2718" COLOR_DEFAULT
#define PENDING_SIGN "-"

#define PADDING_SIZE 3

#define _P padding(paddingStage * PADDING_SIZE)

extern int paddingStage;

extern const char *TITLE;

char *padding(int x);

void printContent(const char *content);
// end ui.h

// flag.h
#define FLAG_TEST 0b1
#define FLAG_SUITEHASTEST 0b10

extern int flags;

void setFlag(int falg);

void popFlag(int flag);
// end flag.h

// test.h
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define test(inputDesc) \
	tearDownTest(); \
	strcpy(currentTest->description, (inputDesc)); \
	currentTest->status = PENDING; \
	setFlag(FLAG_TEST | FLAG_SUITEHASTEST);

enum { FAILED, PASSED, PENDING };

typedef struct test_t {
	char description[150];
	char errorMessage[500];
	int status;
} test_t;

enum { DEFAULT, QUIET };

#define modus(x) \
	modus = x;

extern int modus;
extern int isLastTestPassed;

extern test_t *currentTest;
extern int testInfo[3];

char *getSignOfStatus(int status);

void tearDownTest();
// end test.h

// suite.h
#include<stdio.h>

#define suite(x) \
	tearDownTest(); \
	if (flags & FLAG_SUITEHASTEST) { printf("\n"); } \
	popFlag(FLAG_SUITEHASTEST); \
	printf("%s%s:\n", _P, (x)); \
	paddingStage++;

#define _end \
	tearDownTest(); \
	paddingStage--; \
	isLastTestPassed = 0

void printTestInfo(void);
// end suite.h 

#include<stdbool.h>
#include<string.h>

#define _testSection_ \
	int main(int argc, char **argv) { \
	printContent(TITLE); \
	currentTest = malloc(sizeof(test_t)); \
	strcpy(currentTest->description, ""); \
	strcpy(currentTest->errorMessage, ""); \
	currentTest->status = PENDING;


#define _endSection_ \
	printTestInfo(); \
	return 0; \
	}

#define errorDummy(type, ...) \
	{ type errorDummy = __VA_ARGS__; \
	

#define catchErrorPtr(errorPtr, ptr) \
	if (ptr == NULL) { \
		(errorPtr) = &errorDummy; \
	}

#define _endDummy }

void assertCharEq(char expected, char received);

void assertIntEq(int expected, int received);

void assertIntGt(int expected, int received);

void assertIntLt(int expected, int received);

void assertIntDiff(int expected, int received);

void assertFloatEq(float expected, float received);

void assertFloatGt(float expected, float received);

void assertFloatLt(float expected, float received);

void assertFloatDiff(float expected, float received);

void assertStrEq(char *expected, char *received);

void assertStrDiff(char *expected, char *received);

void assertPtrIsNull(void *ptr);

void assertBoolEq(bool expected, bool received);

void assertBoolDiff(bool expected, bool received);

#endif
