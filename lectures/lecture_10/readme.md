# INPUT / OUTPUT in C

* fokus: datoteke
    * datoteka je __zaporedje bytov__ shranjenih na disku.
    * v C za datoteko uporabljamo podatkovni tip __FILE__
        
### struktura FILE v C

* __FILE *f__ (f je kazalec na tip(strukturo) FILE)
* Struktura FILE vsebuje podatke kako priti do datoteke na disku.


### input

* stdin <-- "datoteka", ki ustreza tipkovnici (ce ni doloceno drugace)
* stdout <-- "datoteka", ki ustreza zaslonu (ce ni dolcoeno drugace)
* stderror <-- za izpis sporocil o napakah

### razlika med text in binarnim zapisom
```java
    for (int i = 0; i < 10; I++) {
        printf("%d\n", i);
    }
    //V DATOTEKI TXT:
    /*
    '1' '\n' '2' '\n'......'1' '0' '\n'
    */
    int a[10] = {1,2, ..., 10};
    sizeof(int) = 4;
    sizeof(int[10]) = 40;

    // V DATOTEKI BIN
    //   0           1           2   ....    10
    //   000...000   000...001   000...010   000...1010
    