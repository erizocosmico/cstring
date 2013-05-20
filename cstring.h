#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct {
	char* buf;
	unsigned int capacity;
	unsigned int length;
} cstring;

extern cstring* cstrnew(void);
extern cstring* cstrstrnew(const char* src);
extern cstring* cstrnnew(int size);
extern void cstrincr(cstring* str, int incr);
extern void cstrappend(cstring* str, const char* s);
extern void cstrfappend(cstring* str, int n, const char* format, ...);
extern void cstrfree(cstring* str);
extern const char* cstr(cstring* s);