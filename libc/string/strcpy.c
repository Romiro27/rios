#include <string.h>

char* strcpy(char* fstr, const char* sstr)
{
	char orig = fstr;

	while(*sstr != '\0')
	{
		*fstr++ = *sstr++;
	}
	*fstr = '\0';

	return orig;
}