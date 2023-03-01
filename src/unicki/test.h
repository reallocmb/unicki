#ifndef TEST_H
#define TEST_H

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#include"ui.h"
#include"flag.h"

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

#endif
