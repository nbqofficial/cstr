#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _cstr
{
	char* buffer;
	size_t size;
	size_t max_size;
}cstr, *pcstr;

/* PRINTS AND DISPLAYS */

void cstr_print(pcstr str)
{
	for (int i = 0; i < str->size; i++)
	{
		printf("%c", str->buffer[i]);
	}
}

void cstr_info(pcstr str)
{
	cstr_print(str);
	printf("\nsize: %d\n", str->size);
	printf("max_size: %d\n", str->max_size);
}

/* INIT AND DELETE */

void cstr_set(pcstr str, const char* str_buffer)
{
	strcpy(str->buffer, str_buffer);
}

void cstr_init(pcstr str, const char* str_buffer, size_t str_size)
{
	str->buffer = (char*)malloc(str_size);
	str->size = str_size;
	str->max_size = str_size;
	cstr_set(str, str_buffer);
}

void cstr_delete(pcstr str)
{
	free(str->buffer);
	str->size = 0;
	str->max_size = 0;
}

/* CAPACITY */

size_t cstr_length(pcstr str)
{
	return str->size;
}

size_t cstr_max_length(pcstr str)
{
	return str->max_size;
}

void cstr_resize(pcstr str, size_t str_size)
{
	str->buffer = (char*)realloc(str->buffer, str_size);
	str->max_size = str_size;
}

void cstr_clear(pcstr str)
{
	memset(str->buffer, 0, str->size);
	str->size = 0;
}

int cstr_is_empty(pcstr str)
{
	if (str->size == 0)
	{
		return 1;
	}
	return 0;
}

void cstr_shrink(pcstr str)
{
	str->buffer = (char*)realloc(str->buffer, str->size);
	str->max_size = str->size;
}

/* ELEMENT ACCESS */

char cstr_at(pcstr str, size_t index)
{
	return str->buffer[index];
}

char cstr_first(pcstr str)
{
	return str->buffer[0];
}

char cstr_last(pcstr str)
{
	return str->buffer[str->size - 1];
}

/* MODIFIERS */

void cstr_append(pcstr str, const char* str_buffer, size_t str_size)
{
	strcpy(str->buffer + str->size, str_buffer);
	str->size += str_size;
}

void cstr_push(pcstr str, const char char_buffer)
{
	memset(str->buffer + str->size, char_buffer, 1);
	str->size++;
}

void cstr_pop(pcstr str)
{
	memset(str->buffer + str->size, 0, 1);
	str->size--;
}

/* OPERATIONS */

char* cstr_c_str(pcstr str)
{
	return str->buffer;
}

int cstr_cmp(pcstr str1, pcstr str2)
{
	if (str1->size != str2->size) { return 0; }

	for (int i = 0; i < str1->size; i++)
	{
		if (str1->buffer[i] != str2->buffer[i]) { return 0; }
	}

	return 1;
}