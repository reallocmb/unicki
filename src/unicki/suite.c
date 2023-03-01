#include"suite.h"

void printTestInfo(void) {
	putchar('\n');
	printf(COLOR_GREEN "PASSED: %5d\n",
			testInfo[PASSED]);
	printf(COLOR_RED "FAILED: %5d\n", 
			testInfo[FAILED]);
	printf(COLOR_DEFAULT "PENDING:%5d\n",
			testInfo[PENDING]);
}
