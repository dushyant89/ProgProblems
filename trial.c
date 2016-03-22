#include<stdio.h>
#include<string.h>

int fun(int *f) {
    *f=10;
    return 0;
}
int main()
{
    typedef char(*(*arrfptr[3])())[10];

    arrfptr x;

    return 0;
}
