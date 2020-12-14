#include "cstr.h"

int main()
{
	cstr str = { 0 };				// declare string variable
	cstr_init(&str, "hello", 5);	// allocate and initialize the string
	cstr_info(&str);				// display string info (buffer, size, max_size);

	// here you can use any of the string functions

	cstr_delete(&str);				// delete string and free it's memory
	return 0;
}