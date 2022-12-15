/**
 * main - Program entry
 * 
 * _isdigit - checks if input is digit between 0 - 9
 * Description above
 * @c: input
 *
 * Return: 1 if is digit, 0 if not
*/

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}