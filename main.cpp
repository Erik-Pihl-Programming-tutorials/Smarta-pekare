/********************************************************************************
* main.cpp: Demonstration av smarta pekare i C++.
********************************************************************************/
#include "smart_ptr.hpp"

/********************************************************************************
* main: Implementerar en smart pekare ptr1, som rymmer tio heltal. Det dynamiska
*       f�lt som ptr1 pekar p� tilldelas heltal 0 - 9. D�refter f�rflyttas
*       minnet f�r f�ltet till en ny smart pekare ptr2, f�ljt av att dess
*       inneh�ll skrivs ut i terminalen.
********************************************************************************/
int main(void)
{
   smart_ptr<int> ptr1(new int[10]);

   for (auto i = 0; i < 10; ++i)
   {
      ptr1.get()[i] = i;
   }

   smart_ptr<int> ptr2 = std::move(ptr1);

   for (auto i = ptr2.get(); i < ptr2.get() + 10; ++i)
   {
      std::cout << *i << "\n";
   }

   return 0;
}