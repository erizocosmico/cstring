#include "cstring.c"

int main(int argc, char** argv)
{
	cstring* str = cstrstrnew("-Hey, buddy!\n");
	cstrappend(str, "-How are you?\n");
	cstrappend(str, "-I'm fine. What about you? How old are you?\n");
	cstrfappend(str, 40, "-I'm %s. I have %d years old.\n", "fine", 10);
	puts(cstr(str));
	return 0;
}