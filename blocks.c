#include <stdio.h>

int main()
{
time_t t;
//t=clock();
time(&t);
printf("%u",t);
    return 0;
}
