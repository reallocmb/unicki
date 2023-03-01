#include"unicki.h"

int getSum(int x, int y) {
	return x + y;
}

bool isEven(int value) {
	if (value % 2) { return false; }
	return true;
}

_testSection_
modus(QUIET);
suite("calculation") {
	suite("getSum") {
		test("return sum of x, y") {
			int result = getSum(10, 15);
			assertIntEq(25, result);
		}
	}_end;
	suite("isEven") {
		test("check if 11 is a odd number") {
			bool result = isEven(11);
			assertBoolEq(false, result);
		}
		test("check if 10 is a even number") {
			bool result = isEven(10);
			assertBoolEq(true, result);
		}
	}_end;
	suite("greather then") {
		test("is 10 is greather then 5") {
			assertIntGt(10, 5);
			assertIntLt(4, 5);
			assertBoolDiff(true, false);
		}
	}_end;
}_end;

_endSection_
