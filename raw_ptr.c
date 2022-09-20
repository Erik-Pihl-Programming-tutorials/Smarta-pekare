/********************************************************************************
* raw_ptr.c: Demonstration av råa pekare i C. Detta exempel utgör en C-version
*            av exemplet med smarta pekare i filen unique_ptr.cpp.
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/********************************************************************************
* main: Implementerar en rå pekare ptr1, som rymmer tio heltal. Det dynamiska
*       fält som ptr1 pekar på tilldelas heltal 0 - 9. Därefter förflyttas
*       minnet för fältet till en ny rå pekare ptr2, följt av att dess
*       innehåll skrivs ut i terminalen.
********************************************************************************/
int main(void)
{
   int* ptr1 = (int*)malloc(sizeof(int) * 10);
   int* ptr2 = 0;
   if (!ptr1) return 1;

   for (int i = 0; i < 10; ++i)
   {
      ptr1[i] = i;
   }

   ptr2 = ptr1;
   ptr1 = 0;

   for (int* i = ptr2; i < ptr2 + 10; ++i)
   {
      printf("%d\n", *i);
   }

   return 0;
}