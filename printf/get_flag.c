#include "main.h"

/**
 *get_flag - finction to turn on a flag it _printf finds a flag modifier
  * @s: character that holds the flag specifier
 * @f: pointer to the struct flags in which we turn the flags on
 *Return : 1 for flag and else 0
 *
*/
int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
