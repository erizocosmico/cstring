#include "cstring.h"

cstring* cstrnew(void)
{
	cstring* str = (cstring*) malloc(sizeof(cstring));
	if (str != NULL)
	{
		str->length = 0;
		str->capacity = 5;
		str->buf = (char*) malloc(sizeof(char)*6);
		str->buf[0] = 0x0;
	}
	else
		fprintf(stderr, "Error: unable to allocate memory for cstring.");
	return str;
}

cstring* cstrstrnew(const char* src)
{
	cstring* str = (cstring*) malloc(sizeof(cstring));
	int src_len = strlen(src), i;
	if (str != NULL)
	{
		str->length = src_len;
		str->capacity = src_len + 5;
		str->buf = (char*) malloc(sizeof(char) * (str->capacity + 1));
		strcpy(str->buf, src);
	}
	else
		fprintf(stderr, "Error: unable to allocate memory for cstring.");
	return str;
}

cstring* cstrsnew(int size)
{
	cstring* str = (cstring*) malloc(sizeof(cstring));
	if (str != NULL)
	{
		str->length = 0;
		str->capacity = size;
		str->buf = (char*) malloc(sizeof(char) * (size + 1));
		str->buf[0] = 0x0;
	}
	else
		fprintf(stderr, "Error: unable to allocate memory for cstring.");
	return str;
}

void cstrincr(cstring* str, int incr)
{
	char* buftmp;
	str->capacity += incr;
	str->buf, 
	buftmp = (char*) malloc(sizeof(char) * (str->capacity + 1));
	if (buftmp != NULL)
	{
		memcpy(buftmp, str->buf, str->length * sizeof(char));
		free(str->buf);
		str->buf = buftmp;
	}
	else
		fprintf(stderr, "Error: unable to reallocate memory for cstring.");
}

void cstrappend(cstring* str, const char* s)
{
	int s_len = strlen(s), i;
	if (str->capacity - str->length < s_len)
		cstrincr(str, ((str->length - str->capacity) + s_len) + 5);
	memcpy(str->buf + str->length, s, sizeof(char) * s_len);
	str->length += s_len;
	str->buf[str->length] = 0x0;
}

void cstrfappend(cstring* str, int n, const char* format, ...)
{
	char* tmp = (char*) malloc(sizeof(char) * (n + 1));
	int i;
	if (tmp != NULL)
	{
		va_list args;
		va_start(args, format);
		vsprintf(tmp, format, args);
		va_end(args);
		cstrappend(str, (const char*) tmp);
		free(tmp);
	}
	else
		printf("Error: unable to allocate memory for tmp in cstrfnappend()");
}

void cstrfree(cstring* str)
{
	free(str->buf);
	free(str);
}

const char* cstr(cstring* s)
{
	return (const char*) s->buf;
}