/********************************************************************************
* smart_ptr.hpp: Innehåller funktionalitet för smarta pekare via en egenskapad
*                klass smart_ptr. Via denna klass kan enbart en pekare komma
*                åt allokerat minne och det går inte att kopia en given pekare.
*                Däremot går det att förflytta minne via funktionen std::move.
********************************************************************************/
#ifndef SMART_PTR_HPP_
#define SMART_PTR_HPP_

/* Inkluderingsdirektiv: */
#include <iostream>
#include <cstdlib>

/********************************************************************************
* smart_ptr: Klasstemplate för implementering av generiska smarta pekare. Denna
*            klass fungerar likt klassen unique_ptr från C++ standardbibliotek.
********************************************************************************/
template<class T>
class smart_ptr
{
private:
   T* data = nullptr; /* Pekare till det dynamiska fältet. */
public:
   /********************************************************************************
   * smart_ptr: Standardkonstruktor, initierar ny tom smart pekare.
   ********************************************************************************/
   smart_ptr(void) { }

   /********************************************************************************
   * smart_ptr: Initierar ny smart pekare, som pekar på angivet fält.
   * 
   *            - data: Pekare till det dynamiska fält som aktuell smart pekare
   *                    skall använda.
   ********************************************************************************/
   smart_ptr(T* data)
   {
      this->data = data;
      return;
   }

   /********************************************************************************
   * smart_ptr: Initierar ny smart pekare, som pekar på refererat fält.
   *
   *            - data: Referens till det dynamiska fält som aktuell smart pekare
   *                    skall använda.
   ********************************************************************************/
   smart_ptr(T& data)
   {
      this->data = &data;
      return;
   }

   /********************************************************************************
   * ~smart_ptr: Destruktor, frigör automatiskt minne för det dynamiska fältet när
   *             aktuell smart pekare går ur scope (raderas från stacken).
   ********************************************************************************/
   ~smart_ptr(void)
   {
      this->clear();
      return;
   }

   /********************************************************************************
   * Raderar kopieringskonstruktorn och tilldelningsoperatorn.
   ********************************************************************************/
   smart_ptr(smart_ptr&) = delete;
   smart_ptr& operator= (smart_ptr&) = delete;

   /********************************************************************************
   * smart_ptr: Förflyttningskonstruktor, möjliggör att minne kan förflyttas från
   *            en smart pekare till en annan via anrop av funktionen std::move.
   *            Minne förlyttas från angiven källa source till aktuellt objekt
   *            this, följt av att angiven källa sätts till att peka på null.
   *            Efter förflyttningen är det endast aktuellt objekt this som
   *            har tillgång till minnet.
   * 
   *            - source: Referens till den smarta pekare som minnet tas från.
   ********************************************************************************/
   smart_ptr(smart_ptr&& source) noexcept
   {
      this->data = source.data;
      source.data = nullptr;
      return;
   }

   /********************************************************************************
   * get: Returnerar det fält som pekas på av aktuell smart pekare.
   ********************************************************************************/
   T* get(void) const
   {
      return this->data;
   }

   /********************************************************************************
   * set: Sätter aktuell smart pekare till att peka på angivet fält.
   * 
   *      - data: Pekare till det fält som den smarta pekaren skall peka på.
   ********************************************************************************/
   void set(T* data)
   {
      this->clear();
      this->data = data;
      return;
   }

   /********************************************************************************
   * set: Sätter aktuell smart pekare till att peka på refererat fält.
   *
   *      - data: Referens till det fält som den smarta pekaren skall peka på.
   ********************************************************************************/
   void set(T& data)
   {
      this->clear();
      this->data = &data;
      return;
   }

   /********************************************************************************
   * clear: Frigör minne allokerat för dynamiskt fält som pekas på av aktuell
   *        smart pekare.
   ********************************************************************************/
   void clear(void)
   {
      delete[] this->data;
      this->data = nullptr;
      return;
   }
};

#endif /* SMART_PTR_HPP_ */