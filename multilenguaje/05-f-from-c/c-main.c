
#include <stdio.h>
#include "c-sum.h"

#define NUM 200

int main(int argc, char **argv)
{
    int data[NUM], num, i, asum;

    num = NUM;
    for (i=0; i < num; i++) {
        data[i] = i - 100 + 1;  /* NOTE: difference in array numbering */  
    }
    sum_abs_(data, &num, &asum);
    printf("sum=%d\n", asum);
    return 0;
}
