// Program that illustrates a stack overflow
#include <stdio.h>

void strjoin(char *a, const char *b)
{
    // The key issue is that a needs to be large enough to accomodate both a and b
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
    scanf("%s", a); // There is a risk here of overflowing a, depending on how large the input is
    scanf("%s", b);
    strjoin(a, b);
    printf("Result is %s", a);
}
