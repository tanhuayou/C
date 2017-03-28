#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 1;
    int b = 2;
    int c = 4;
    int d = (int)sizeof(c = a + b);
    printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d );
    return 0;
}
