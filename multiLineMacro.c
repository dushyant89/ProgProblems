#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int i;
    int *ptr = (int *) malloc(5 * sizeof(int));

    for (i=0; i<5; i++)
        *(ptr + i) = i;

    printf("%d\n", *ptr++);
    for (i=0; i<5; i++)
        printf("%d ",*(ptr + i));
    printf("\n");

    printf("%d\n", (*ptr)++);
    for (i=0; i<5; i++)
        printf("%d ",*(ptr + i));
    printf("\n");

    printf("%d\n", *ptr);
    for (i=0; i<5; i++)
        printf("%d ",*(ptr + i));
    printf("\n");

    printf("%d\n", *++ptr);
    for (i=0; i<5; i++)
        printf("%d ",*(ptr + i));
    printf("\n");

    printf("%d ", ++*ptr);
}
