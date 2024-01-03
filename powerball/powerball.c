#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/timeb.h>

/* author: terry hawkins */

int compare(const void* a, const void* b)
{
    const int* ia = (const int*)a;
    const int* ib = (const int*)b;

    return (*ia > *ib) - (*ia < *ib);
}

int main(int argc, char **argv) 
{
   int i, j, k;
   int how_many;
   int rn[6];
   time_t t;    

   srand((unsigned)time(&t));
   
   if (argc == 2)
      how_many = atoi(argv[1]);
   else
   {
      fprintf(stderr,"How many combinations do you want? ");
      scanf("%i", &how_many);
   }

   for (i = 0; i < how_many; i++)
   {
      for (j = 0; j < 5; j++)
      {
         // generate the balls
         rn[j] = ((rand() >> 2) % 69) +1;

         // skip duplicates
         for (k=0 ; k < j; k++)
            if(rn[k] == rn[j]) j--;
      }

      // order the balls
      qsort(rn, 5, sizeof(int), compare);

      // generate the powerball
      rn[5] = ((rand() >> 2) % 26) + 1;

      printf("\n #%d: ", i+1);
      
      for (j = 0; j < 5; j++)
        printf(" %2d", rn[j]);

      printf("   pb:%2d\n",rn[5]);
   }

   return 0; 
}


