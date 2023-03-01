#include"flag.h"

int flags = 0;

void setFlag(int flag) {
	flags |= flag;
}

void popFlag(int flag) {
	flags &= ~flag;
}
