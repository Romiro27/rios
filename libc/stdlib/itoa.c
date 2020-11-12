#include <stdlib.h>
#include <string.h>

char* strinv(char* str)
{
    int i;
    unsigned int n = strlen(str);
    char buff[n + 2];
    char* curr = buff;

    for(i = n - 1; i >= 0; --i)
    {
        *curr++ = str[i];
    }
    *curr++ = '\0';

    strcpy(str, buff);

    return str;
}

char* itoa(unsigned int value, char* str, unsigned int base)
{
    char* orig = str;
    char digit;

    do
    {
        digit = value % base;
        value = value / base;

        if(digit < 10)
        {
            *str++ = digit | 0x30;
        }
        else if(digit < 16)
        {
            *str++ = ((digit - 10) | 0x40) + 1;
        }
        else
        {
            *str++ = '?';
        }
    } while(value > 0);

    if(base == 16)
    {
        *str++ = 'x';
        *str++ = '0';
    }
    else if(base == 8)
    {
        *str++ = 'o';
        *str++ = '0';
    }
    else if(base == 2)
    {
        *str++ = 'b';
        *str++ = '0';
    }
    *str++ = '\0';

    strinv(orig);

    return str;
}