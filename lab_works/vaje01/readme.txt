dostop do c diska na linuxu
cd --> mnt/c

PREVAJANJE PROGRAMA

gcc hello.c -o hello -std=c99 -Wall -pedantic

-std (STANDARD - kateri C bomo uporabljali, c99 omogoca for (int i), in line metode)
-Wall (omogoci Warninge(okoli 60): npr definiramo spremenljivke pa je ne inicializeramo)
-pedantic (prtozi se ??)

Ko poganjamo program uporabimo ./(iz trenutne mape pozene program) :
(windowsi naprej pogledajo ali se file nahaja v trenutni mapi, potem gre gledat v path)
(linux gleda ce se navaja datoteka v path - ne gleda v trenutni mapi)

Stack and heap memory C programs (vaje) -size hello
What is heap memory stack memory?
Stack memory is used to store items which have a very short life like local variables,
 a reference variable of objects. Heap memory is allocated to store objects and JRE classes.


 #TESTIRNAJE PROGRAMA
 