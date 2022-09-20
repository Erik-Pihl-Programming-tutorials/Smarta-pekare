/********************************************************************************
* raw_ptr.c: Demonstration av r�a pekare i C. Detta exempel utg�r en C-version
*            av exemplet med smarta pekare i filen unique_ptr.cpp.
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/********************************************************************************
* main: Implementerar en r� pekare ptr1, som rymmer tio heltal. Det dynamiska
*       f�lt som ptr1 pekar p� tilldelas heltal 0 - 9. D�refter f�rflyttas
*       minnet f�r f�ltet till en ny r� pekare ptr2, f�ljt av att dess
*       inneh�ll skrivs ut i terminalen.
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