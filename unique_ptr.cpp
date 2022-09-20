/********************************************************************************
* unique_ptr.cpp: Demonstration av smarta pekare i C++ via klassen unique_ptr
*                 från C++ standardbibliotek.
********************************************************************************/
#include <iostream>
#include <memory>

/********************************************************************************
* main: Implementerar en smart pekare ptr1, som rymmer tio heltal. Det dynamiska
*       fält som ptr1 pekar på tilldelas heltal 0 - 9. Därefter förflyttas
*       minnet för fältet till en ny smart pekare ptr2, följt av att dess
*       innehåll skrivs ut i terminalen.
********************************************************************************/
int main(void)
{
   std::unique_ptr<int> ptr1(new int[10]);

   for (auto i = 0; i < 10; ++i)
   {
      ptr1.get()[i] = i;
   }

   std::unique_ptr<int> ptr2 = std::move(ptr1);

   for (auto i = ptr2.get(); i < ptr2.get() + 10; ++i)
   {
      std::cout << *i << "\n";
   }

   return 0;
}