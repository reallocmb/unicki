#ifndef FLAG_H
#define FLAG_H

#define FLAG_TEST 0b1
#define FLAG_SUITEHASTEST 0b10

extern int flags;

void setFlag(int falg);

void popFlag(int flag);

#endif
