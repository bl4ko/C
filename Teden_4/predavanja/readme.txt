KAZALCI
kazalec = spremenljivka, ki vsebuje naslov

(POMNILNIK : code, stat.data, HEAP, STACK), 

Kazalcni tip:
int *pi; //pointer na int
char *pc; //pointer na char
double *pd; //pointer na double

pi = &x mu priredim naslov
&pi = 7; spremenim vrednost na katero kaze pi

DVA OPERATORJA
& --> vrne naslov kazalaca
* --> vrednost na naslovu

SCANF
scanf("%d", &i);
//funkciji dam naslov spremenljivke i, na katero lahko pise

i=0;
scanf("%d",i);
poslem vrednost 0 v funkcijo scanf (torej pise na naslov 0);
Torej vrednost 0 v funkciji scanf je razumljena kot naslov 0;
(na naslov 0 ne smemo pisat, v ta del pomnilnika rac. programi nesmejo dostopat)
(operacijski sistem prepove dostopat do tega naslova)
--> segmentation fault; zeleli smo dostopati do kosa pomnilnika do katerega nimamo pravic
