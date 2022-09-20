/********************************************************************************
* smart_ptr.hpp: Inneh�ller funktionalitet f�r smarta pekare via en egenskapad
*                klass smart_ptr. Via denna klass kan enbart en pekare komma
*                �t allokerat minne och det g�r inte att kopia en given pekare.
*                D�remot g�r det att f�rflytta minne via funktionen std::move.
********************************************************************************/
#ifndef SMART_PTR_HPP_
#define SMART_PTR_HPP_

/* Inkluderingsdirektiv: */
#include <iostream>
#include <cstdlib>

/********************************************************************************
* smart_ptr: Klasstemplate f�r implementering av generiska smarta pekare. Denna
*            klass fungerar likt klassen unique_ptr fr�n C++ standardbibliotek.
********************************************************************************/
template<class T>
class smart_ptr
{
private:
   T* data = nullptr; /* Pekare till det dynamiska f�ltet. */
public:
   /********************************************************************************
   * smart_ptr: Standardkonstruktor, initierar ny tom smart pekare.
   ********************************************************************************/
   smart_ptr(void) { }

   /********************************************************************************
   * smart_ptr: Initierar ny smart pekare, som pekar p� angivet f�lt.
   * 
   *            - data: Pekare till det dynamiska f�lt som aktuell smart pekare
   *                    skall anv�nda.
   ********************************************************************************/
   smart_ptr(T* data)
   {
      this->data = data;
      return;
   }

   /********************************************************************************
   * smart_ptr: Initierar ny smart pekare, som pekar p� refererat f�lt.
   *
   *            - data: Referens till det dynamiska f�lt som aktuell smart pekare
   *                    skall anv�nda.
   ********************************************************************************/
   smart_ptr(T& data)
   {
      this->data = &data;
      return;
   }

   /********************************************************************************
   * ~smart_ptr: Destruktor, frig�r automatiskt minne f�r det dynamiska f�ltet n�r
   *             aktuell smart pekare g�r ur scope (raderas fr�n stacken).
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
   * smart_ptr: F�rflyttningskonstruktor, m�jligg�r att minne kan f�rflyttas fr�n
   *            en smart pekare till en annan via anrop av funktionen std::move.
   *            Minne f�rlyttas fr�n angiven k�lla source till aktuellt objekt
   *            this, f�ljt av att angiven k�lla s�tts till att peka p� null.
   *            Efter f�rflyttningen �r det endast aktuellt objekt this som
   *            har tillg�ng till minnet.
   * 
   *            - source: Referens till den smarta pekare som minnet tas fr�n.
   ********************************************************************************/
   smart_ptr(smart_ptr&& source) noexcept
   {
      this->data = source.data;
      source.data = nullptr;
      return;
   }

   /********************************************************************************
   * get: Returnerar det f�lt som pekas p� av aktuell smart pekare.
   ********************************************************************************/
   T* get(void) const
   {
      return this->data;
   }

   /********************************************************************************
   * set: S�tter aktuell smart pekare till att peka p� angivet f�lt.
   * 
   *      - data: Pekare till det f�lt som den smarta pekaren skall peka p�.
   ********************************************************************************/
   void set(T* data)
   {
      this->clear();
      this->data = data;
      return;
   }

   /********************************************************************************
   * set: S�tter aktuell smart pekare till att peka p� refererat f�lt.
   *
   *      - data: Referens till det f�lt som den smarta pekaren skall peka p�.
   ********************************************************************************/
   void set(T& data)
   {
      this->clear();
      this->data = &data;
      return;
   }

   /********************************************************************************
   * clear: Frig�r minne allokerat f�r dynamiskt f�lt som pekas p� av aktuell
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