# <span style="color:red">__INPUT / OUTPUT in C__</span>

## <span style="color:yellow">__ODPIRANJE/ZAPIRANJE DATOTEK__</span>
* Datoteka je __zaporedje bytov__(STREAM) shranjenih na disku.
* v C za datoteko uporabljamo podatkovni tip __FILE__
* Struktura FILE vsebuje podatke kako priti do datoteke na disku.
    * Datoteko povezemo z funkcijo ```fopen(char* pathName, char* mode)```
> Opomba: argument __mode__ pove "nacin" odpiranja datoteke: 
> | char* mode      | Description |
> | ----------- | ----------- |
> | r      | Open text file for reading.  The stream is positioned at the beginning of the file.       |
> | r+   | Open for reading and writing.  The stream is positioned at the beginning of the file.       |
> |w | Truncate  file to zero length or create text file for writing.  The stream is positioned at the beginning of the file.
> |w+ | Open for reading and writing.  The file is created if it does not exist, otherwise  it  is  truncated.   The stream is positioned at the beginning of the file.
> |a | Open for appending (writing at end of file).  The file is created if it does not exist.  The stream is posi‐tioned at the end of the file.
> |a+ | Open for reading and appending (writing at end of file).  The file is created if it does not exist.   Output is  always appended to the end of the file.  POSIX is silent on what the initial read position is when using this mode.  For glibc, the initial file position for reading is at the beginning of the file,  but  for  An‐droid/BSD/MacOS, the initial file position for reading is at the end of the file.

* Zgled uporabe:
    ```C
    #include <stdio.h>

    FILE* input = fopen("input.txt", "r");  // datoteka za branje
    FILE* output = fopen("output.txt", "w"); // datoteka za pisanje
    ```
    > opomba: ce fopen() ni uspesno izvedena vrne NULL

    ```C
    if (input == NULL) {
        printf("ERROR!\n"); 
        return 1;
    }
    ```

* Datoteke vedno zapiramo z ```int fclose(FILE* stream)```
    ```C
    int a = fclose(input); // funkcija vrne 0(uspesna)/EOF(neuspesna)
    if (a == 0) printf("Datoteka je bila uspesno zaprta\n");
    int b = fclose(output);
    if (b == 0) printf("Datoteka je bila uspesno zaprta\n");
    ```
    > Opomba: funkcija ```fclose``` vraca vrednost:
    > * <span style="color:green">__0__</span> (ko je datoteka uspesna zaprta)
    > * <span style="color:green">__EOF__</span> (datoteka ni bila uspesna zaprta)

<br>

___

## <span style="color:yellow">__STANDARDNI TIPI DATOTEK__</span>
* po defaultu imamo v C vgrajene tri "posebne" tipe datotek:
    * ```extern FILE* stdin``` (datoteka, ki ustreza tipkovnici)
    * ```extern FILE* stdout``` (datoteka, ki ustreza zaslonu)
    * ```extern FILE* stderr``` (datoteka, za izpis napak)
    ```c
    FILE* input = stdin;    // sedaj beremo iz tipkovnice(terminal)
    FILE* output = stdout;  // sedaj pisemo na zaslon(terminal)
    ```
* uporaba ```stderr``` za izpis napak, na prejsnem zgledu
    ```c
    if (input == NULL) {
        fprintf(stderr, "NAPAKA: datoteka ni bila najdena\n");
    }
    ```
<br>

---

## <span style="color:yellow">BRANJE/PISANJE PODATKOV __TEXT DATOTEK__</span>
### __1. Branje__
*  ```int fgetc(FILE* stream)``` <-- branje posameznih znakov
    ```C
    int ch;
    int ch = fgetc(input);
    ```
  
*  ```char* fgets(char* s, int size, FILE* stream)``` <-- branje vrstic(do znaka __\n__)
    ```C
    #define MAX_LINE_LEN 10000 // najdalsa mozna dolzina vrstice

    char* line = malloc(sizeof(char) * MAX_LINE_LEN + 1) // +1 za /0 char
    while (fgets(line, MAX_LINE_LEN+1, input) != NULL) {
        int len = strlen(line); // dolzina prebrane vrstice
        if (len > 10) 
            printf("Prebrali smo vrstico dalso od 10ih znakov");
    }
    ```
    > fgets avtomatsko doda __\0__ na konec prebrane vrstice <br>
    > fgets vrne prebrani char*/EOF (end of the file)
    
*  ```int fscanf(FILE* stream, const char* FORMAT, ...)``` <-- branje formatov
    > On  success,  these functions return the number of input items successfully matched and assigned; this can be fewer than provided for, or even zero, in the event of an early matching failure.<br>
    > The value EOF is returned if the end of input is reached before either the first successful conversion or a  match‐ing  failure occurs.  EOF is also returned if a read error occurs, in which case the error indicator for the stream(see ferror(3)) is set, and errno is set to indicate the error.
    ```c
    FILE* input = fopen("oseba.txt", "r");
    int cifraOsebe;
    char spol;
    char* ime;
    int stUspesnoPrebranih = fscanf(input, "%d %c %s", &cifraOsebe, &spol, ime);
    printf("cifra: %d, spol: %c, ime: %s, stUspesnoPrebranih: %d\n", cifraOsebe, spol, ime, stUspesnoPrebranih);
    //cifra: 1234, spol: M, ime: Nik_Mohar, stZnakov: 3
    ```
    ```c
    int a;
    fscanf(stdin, "%d", &a);    // branje iz zaslona
    ```

___


### __2. Pisanje__

* ```int fputc(ch, FILE* stream)```
    ```C
    char ch = 'A';
    fputc(ch, output);    // na izhod zapisemo A
    fputc(ch, stdout);    // na zaslon izpisemo A
    ```
* ```int fputs(const char *s, FILE* stream)``` <-- izpis Stringa
    ```C
    FILE* output = fopen("output.txt", "w");
    static char stavek[50] = "Danes ni moj dan, niti vceraj ni bil!\n";
    fputs(stavek, output);    // na izhod zapisemo A
    fputs(stavek, stdout);    // na zaslon izpisemo A
    fputs("NAPAKA: pojdi se stusirat!\n", stderr);
    ```
    > fputs vrne: nenegativno vrednost/EOF (neuspesno)
* ```int fprintf(FILE* stream, const char*format, ...)```
    ```C
    FILE* output = fopen(argv[2], "w");
    int sirina = 3; int visina = 2;
    fprintf(output, "P5\n");
    fprintf(output, "%d %d\n", sirina, visina);
    fprintf(stdout, "Cas za spanec kekw");
    ```
    > Vrne stevilo uspesno izpisanih characters (excluding the null byte used to end output to strings).

<br>

___

## <span style="color:yellow">__BRANJE/PISANJE BINARNIH DATOTEK__</span>
* Branje iz binarne datoteke
    * ```fread(const void* ptr, size_t size, size_t nmemb, FILE* stream)```
        ```C
        FILE* vhod = fopen(argv[1], "rb");  // binary input file
        unsigned char* byteValues = malloc(sizeof(unsigned char) * 20); //preberemo 20 bytov (2'K -> unsigned vrednost [0-255]
        fread(byteValues, sizeof(unsigned char), 20, vhod);
        ```
    * ZGLED: branje podatkov v blokih, za izracun dolzine datoteke
        ```C
        static unsigned char block[1024];
        int len = 0;
        while(1) {
            int n = fread(block, sizeof(unsigned char), 1024, input);
            len += n;
            if (n < 1024) break;
        }
        printf("LENGTH: %d\n", len);        
        ```
* Pisanje na binarno datoteko
    * ```fwrite(const void* ptr, size_t size, size_t nmemb, FILE* stream)```
        ```C
        FILE* izhod = fopen(argv[2], "wb");
        unsigned char* byteValues = malloc(sizeof(unsigned char)*256);
        for (int i = 0; i < 256; i++) {
            byteValues[i] = i;
        }
        fwrite(byteValues, sizeof(unsigned char), 256, izhod);
        
        // stanje na datoteki po izvedbi programa 
        /*
        00000000  00 01 02 03 04 05 06 07  08 09 0a 0b 0c 0d 0e 0f  
        00000010  10 11 12 13 14 15 16 17  18 19 1a 1b 1c 1d 1e 1f  
        00000020  20 21 22 23 24 25 26 27  28 29 2a 2b 2c 2d 2e 2f  
        00000030  30 31 32 33 34 35 36 37  38 39 3a 3b 3c 3d 3e 3f  
        00000040  40 41 42 43 44 45 46 47  48 49 4a 4b 4c 4d 4e 4f  
        00000050  50 51 52 53 54 55 56 57  58 59 5a 5b 5c 5d 5e 5f  
        00000060  60 61 62 63 64 65 66 67  68 69 6a 6b 6c 6d 6e 6f  
        00000070  70 71 72 73 74 75 76 77  78 79 7a 7b 7c 7d 7e 7f  
        00000080  80 81 82 83 84 85 86 87  88 89 8a 8b 8c 8d 8e 8f  
        00000090  90 91 92 93 94 95 96 97  98 99 9a 9b 9c 9d 9e 9f  
        000000a0  a0 a1 a2 a3 a4 a5 a6 a7  a8 a9 aa ab ac ad ae af  
        000000b0  b0 b1 b2 b3 b4 b5 b6 b7  b8 b9 ba bb bc bd be bf 
        000000c0  c0 c1 c2 c3 c4 c5 c6 c7  c8 c9 ca cb cc cd ce cf  
        000000d0  d0 d1 d2 d3 d4 d5 d6 d7  d8 d9 da db dc dd de df  
        000000e0  e0 e1 e2 e3 e4 e5 e6 e7  e8 e9 ea eb ec ed ee ef  
        000000f0  f0 f1 f2 f3 f4 f5 f6 f7  f8 f9 fa fb fc fd fe ff  
        00000100 */
        ```
> Funkciji vrneta:
> * stevilo prebranih/zapisanih podatkov
> * v nasprotnem primeru 0

<br>

___
### <span style="color:yellow">__IZPIS BINARNE IN TEKST DATOTEKE__</span>
* Izpis preverjamo lahko z komando: ```hexdump```
* Razlika med text in binarnim zapisom:
```c
int main() 
{   
    FILE* outputTxt = fopen("output.txt", "w");
    FILE* outputBin = fopen("outputBin.bin", "wb");
    static int temp[1];
    for (int i = 0; i < 100; i++) {
        temp[0] = i;
        fprintf(outputTxt, "%d", i);
        fwrite(temp, sizeof(int), 1, outputBin);
    }
    fclose(outputTxt);
    fclose(outputBin);
}

/*
1. TEKSTOVNA DATOTEKA
    - vidimo ascii vrednosti stevilk (30-39)
    - ni presledkov
    - vsaka stevka svoj byte:
    012345678910111213...
00000000  30 31 32 33 34 35 36 37  38 39 31 30 31 31 31 32  
00000010  31 33 31 34 31 35 31 36  31 37 31 38 31 39 32 30 
00000020  32 31 32 32 32 33 32 34  32 35 32 36 32 37 32 38  
00000030  32 39 33 30 33 31 33 32  33 33 33 34 33 35 33 36  
00000040  33 37 33 38 33 39 34 30  34 31 34 32 34 33 34 34  
00000050  34 35 34 36 34 37 34 38  34 39 35 30 35 31 35 32  
00000060  35 33 35 34 35 35 35 36  35 37 35 38 35 39 36 30  
00000070  36 31 36 32 36 33 36 34  36 35 36 36 36 37 36 38  
00000080  36 39 37 30 37 31 37 32  37 33 37 34 37 35 37 36  
00000090  37 37 37 38 37 39 38 30  38 31 38 32 38 33 38 34  
000000a0  38 35 38 36 38 37 38 38  38 39 39 30 39 31 39 32  
000000b0  39 33 39 34 39 35 39 36  39 37 39 38 39 39        
000000be

2. BINARNA DATOTEKA
    - vidimo da vsaka cifra zasede 4 byte (sizeof(int))
    - format je little Endian
00000000  00 00 00 00 01 00 00 00  02 00 00 00 03 00 00 00  
00000010  04 00 00 00 05 00 00 00  06 00 00 00 07 00 00 00  
00000020  08 00 00 00 09 00 00 00  0a 00 00 00 0b 00 00 00  
00000030  0c 00 00 00 0d 00 00 00  0e 00 00 00 0f 00 00 00  
00000040  10 00 00 00 11 00 00 00  12 00 00 00 13 00 00 00  
00000050  14 00 00 00 15 00 00 00  16 00 00 00 17 00 00 00  
00000060  18 00 00 00 19 00 00 00  1a 00 00 00 1b 00 00 00  
00000070  1c 00 00 00 1d 00 00 00  1e 00 00 00 1f 00 00 00  
00000080  20 00 00 00 21 00 00 00  22 00 00 00 23 00 00 00  
00000090  24 00 00 00 25 00 00 00  26 00 00 00 27 00 00 00 
000000a0  28 00 00 00 29 00 00 00  2a 00 00 00 2b 00 00 00  
000000b0  2c 00 00 00 2d 00 00 00  2e 00 00 00 2f 00 00 00  
000000c0  30 00 00 00 31 00 00 00  32 00 00 00 33 00 00 00  
000000d0  34 00 00 00 35 00 00 00  36 00 00 00 37 00 00 00  
000000e0  38 00 00 00 39 00 00 00  3a 00 00 00 3b 00 00 00  
000000f0  3c 00 00 00 3d 00 00 00  3e 00 00 00 3f 00 00 00  
00000100  40 00 00 00 41 00 00 00  42 00 00 00 43 00 00 00  
00000110  44 00 00 00 45 00 00 00  46 00 00 00 47 00 00 00  
00000120  48 00 00 00 49 00 00 00  4a 00 00 00 4b 00 00 00  
00000130  4c 00 00 00 4d 00 00 00  4e 00 00 00 4f 00 00 00  
00000140  50 00 00 00 51 00 00 00  52 00 00 00 53 00 00 00  
00000150  54 00 00 00 55 00 00 00  56 00 00 00 57 00 00 00  
00000160  58 00 00 00 59 00 00 00  5a 00 00 00 5b 00 00 00  
00000170  5c 00 00 00 5d 00 00 00  5e 00 00 00 5f 00 00 00  
00000180  60 00 00 00 61 00 00 00  62 00 00 00 63 00 00 00  
00000190
*/
```



    
