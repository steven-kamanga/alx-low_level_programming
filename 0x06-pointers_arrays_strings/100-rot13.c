#include <stdio.h>
#include <ctype.h>

/**
 * rot13 - encodes a string using the ROT13 cipher
 * @s: the string to be encoded
 */
void rot13(char *s)
{
  for (int i = 0; s[i] != '\0'; i++)
  {
    if (isalpha(s[i]))
    {
      if (isupper(s[i]))
      {
        s[i] = (s[i] - 'A' + 13) % 26 + 'A';
      }
      else
      {
        s[i] = (s[i] - 'a' + 13) % 26 + 'a';
      }
    }
  }
}
