#include <stdio.h>

void strjoin(char *a, const char *b)
{
    while (*(a++)) 
        ;
    char *str = a - 1;
    while (*b) 
        *(str++) = *(b++);

}


int main(void)
{
    char a[10];
    char b[10];
    scanf("%s", a);
    scanf("%s", b);
    strjoin(a, b);
    printf("Result is %s", a);
}
