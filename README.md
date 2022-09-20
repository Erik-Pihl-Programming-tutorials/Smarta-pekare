# Smarta-pekare
Demonstration av smarta pekare i C++, båda via klassen std::unique_ptr samt en egenskapad klass smart_ptr.

Filen unique_ptr.cpp demonstrerar implementering av smarta pekare i C++ via klassen std::unique_ptr. 
Här demonstreras förflyttning av minne via klassens förflyttningskonstruktor, anropad via funktionen std::move.

Filen raw_ptr.c demonstrerar motsvarande C-kod med råa pekare. Förflyttning av minne sker manuellt genom att byta adresser mellan pekare.

Filen smart_ptr.hpp innehåller en egenskapad generisk klass för implmentering av smarta pekare, som efterliknar klassen std::unique_ptr.
Här demonstreras konstruktorer, förflyttningskonstruktorer, get- och set-metoder med mera. I filen main.cpp används två smarta pekare
av denna klass likt ovanstående exempel.

Se video tutorial här:
https://youtu.be/_EhHd6hsHz0
