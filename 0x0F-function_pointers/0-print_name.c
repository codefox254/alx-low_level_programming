#include "function_pointers.h"
	#include <stdio.h>
	/**
	 * print_name - prints name using pointer to function
	 * @name: string to addition
	 * @f: points to function
	 * Return: null
	 **/
	void print_name(char *name, void (*f)(char *))
	{
		if (name == NULL || f == NULL)
			return;


		f(name);
	}

