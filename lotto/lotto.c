#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/timeb.h>

/* author: terry hawkins */

int compare(const void* a, const void* b)
{
    const int* ia = a;
    const int* ib = b;

    return (ia > ib) - (ia < ib);
}

void main(int argc, char **argv)
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
      for (j = 0; j < 6; j++)
      {
         rn[j] = ((rand() >> 2) % 54) +1;
         for (k=0 ; k < j; k++)
            if(rn[k] == rn[j]) j--;
      }
      printf("\n #%d: ", i+1);

      qsort(rn, 6, sizeof(int), compare);

      for (j = 0; j < 6; j++)
        printf(" %2d", rn[j]);

      printf("\n");
   }
   return 0;
}


