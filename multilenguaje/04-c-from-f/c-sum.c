#include <stdlib.h>
#include "c-sum.h"

void sum_abs_(int *in, int *num, int *sum) {
   int i;

   for (i=0,*sum=0; i < *num; ++i) {
       *sum += abs(in[i]);
   }
  
}
 
