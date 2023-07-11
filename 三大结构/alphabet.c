#include <stdio.h>

int main()
{
    char ch = 0;
    while((ch=getchar())!=EOF)
    {
        getchar();
        if(('A'<=ch&&'Z'>=ch)||('a'<=ch&&'z'>=ch))
            printf("%c is an alphabet.\n",ch);
        else
            printf("%c is not an alphabet.\n",ch);
    }
    return 0;
}



