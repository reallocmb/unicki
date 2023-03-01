#include"ui.h"

int paddingStage = 0;

const char *TITLE = 
	COLOR_GREEN
	"\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\u2581\n"
	"\u258F                    \u2595\n"
	"\u258F     "COLOR_DEFAULT"Unit Tests"COLOR_GREEN"     \u2595\n"
	"\u258F      "COLOR_DEFAULT"[UNICKI]"COLOR_GREEN"      \u2595\n"
	"\u258F                    \u2595\n"
	"\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\u2594\n"
	COLOR_DEFAULT;

char *padding(int x) {
	char *str = calloc(x + 1, sizeof(char));
	int i;
	for (i = 0; i < x; i++) {
		str[i] = ' ';
	}
	str[i] = '\0';
	return str;
}

void printContent(const char *content) {
	printf("%s", content);
}
