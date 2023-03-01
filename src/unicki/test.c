#include"test.h"

int modus = 0;

test_t *currentTest = NULL;
int testInfo[3] = { 0 };

char *getSignOfStatus(int status) {
	switch (status) {
		case FAILED: return FAILED_SIGN; break;
		case PASSED: return PASSED_SIGN; break;
		default: return PENDING_SIGN; break;
	}
}

int isLastTestPassed = 0;

void tearDownTest() {
	if (!(flags & FLAG_TEST))
		return;

	if (modus && currentTest->status == PASSED) {
		if (isLastTestPassed) {
			printf("%s",
				   getSignOfStatus(currentTest->status));
		} else {
			printf("%s%s", _P,
				   getSignOfStatus(currentTest->status));
		}
		isLastTestPassed = 1;
	} else {
		if (isLastTestPassed) {
			isLastTestPassed = 0;
			putchar('\n');
			putchar('\n');
		}
		printf("%s%s %s \n", _P,
			   getSignOfStatus(currentTest->status),
			   currentTest->description);
	}

	if (currentTest->status == FAILED)
		printf("%s", currentTest->errorMessage);

	testInfo[currentTest->status]++;
	strcpy(currentTest->errorMessage, "");
	popFlag(FLAG_TEST);
}
