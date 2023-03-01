#ifndef UI_H
#define UI_H

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

#endif
