JAVA vs C (prevajanje)

Java:
$javac Main.javac (prevedemo program)
$java Main 
Main.java (javac)--> Main.class (java)--> izavajanje
            prevajanje              izvajanje (torej imam dva programa)

C:
$gcc main.C
$./a.out
main.c (gcc)--> a.out
    "prevajanje"
a.out -->
 izvajanje

 RAZLIKA: v datoteki a.out je preveden program v strojnem jeziku(ukazi ki jih razume nas procesor)
 za razliko od javanskega programa v Main.class (preveden program v janaski bytecodi)
 - te kode procesor nerazume, zato potrebujemo program java ki prevede to kodo
 Pri C programa ki bi ustrezal programu java ni (ga ne potrebujemo)

PREDNOSTI: c je hitrejsi, se izognemo prevajnju java
java je bolj prenosljiv 

-----------------------------------------------------------------------------------------------
$gcc -c main.c 
$ls (-l >>vidimo se velikost datotek)
... main.o <- rezultat prejsnega ukaza (strojni ukazi brez C-jevih funkcij)
$gcc -o main main.o
$ls
... main.o main <- rezultat prejsnega ukaza (strojni ukazi, izvrsliv program)

main.c -->  main.o  --> main
      gcc -c         gcc
      prevajanje     povezovanje

POVEZOVANJE IN PREVAJANJE : z enim samim ukazom [gcc -o main main.c]
-----------------------------------------------------------------------------------------------

gcc -S main.c 
program v zbirniku (ukazi ki jih procesore razume)
- ukazi ki jih razume procesor Intel/amd, ARM jih nerazume
-----------------------------------------------------------------------------------------------

Za c obstajajo tri prevajalniki:
>> gcc (gnujev prevajalnik)
>> Visual c++ (Microsoftov)
>> c (Intlov prevajanlik)


>>echo $? - vrne vrednost funkcije main