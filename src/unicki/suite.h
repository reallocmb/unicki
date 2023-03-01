#ifndef SUITE_H
#define SUITE_H

#include<stdio.h>

#include"test.h"

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

#endif
