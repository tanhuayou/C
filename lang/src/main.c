#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "head.h"

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = add(a,b);
    
    printf("%d\n",argc );
    printf("%s %s\n",argv[1],argv[2] );
    printf("%d + %d = %d\n",a,b,c );


    return 0;
}
