/*Das Spiel Tic Tac Toe in C
* (c)Christian Falkner, 17.01.2020
* Version 2.1
*/

//Headerfiles einbinden
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Globales Array
int spielfeld [9] = {1,2,3,4,5,6,7,8,9};

/*Zur Compilerberuhigung
* Damit die Funktionen dem Copiler vorher bekannt sind, da die Funktionen erst nch der main-Funktion definiert sind
*/
void spielfeldausgabe();
void spielfeldclear();
void abfragespieler(int spieler, int computer);
int gewinnpruefer(int spieler);


int main(){
//Variablen
int auswahl = 0;
char neueRunde;

printf("*========================================*\n");
printf("\tWillkommen in Tic Tac Toe!\n");
printf("\tSpieler 1: x  Spieler 2: o\n");
printf("*========================================*\n");

//Erstmalige Spielmodus Auswahl
printf("Spielmodi:\n");
printf("[1] 2 Spieler\n");
printf("[2] Computer\n");
scanf("%d", &auswahl);

do{
//Konsole clear    
system("cls");

spielfeldausgabe();
//Spieler 1 Abfrage
abfragespieler(1, 0);

//Konsole clear    
system("cls");

//Gewinnpruefung Spieler 1
if ((gewinnpruefer(11) == 1) || (gewinnpruefer(11) == 3))
{
if(gewinnpruefer(11) == 1){
    spielfeldausgabe();
    printf("Spieler 1 hat Gewonnen!");
}    
if(gewinnpruefer(11) == 3)
{
    spielfeldausgabe();
    printf("Unentschieden!");
} 
printf("\nNoch mal? (Y/N)\n");
fflush(stdin);
scanf("%c", &neueRunde);

if(neueRunde == 'y' || neueRunde == 'Y'){

    //Spielmodi Auswahl
    printf("\nSpielmodi:\n");
    printf("[1] 2 Spieler\n");
    printf("[2] Computer\n");
    scanf("%d", &auswahl);

    //Spielfeld clear
    spielfeldclear();
    //Spielfeld ausgabe
    spielfeldausgabe();
    goto ende;
}
else
{
    return 0;
}
}

//Spieler 2 Abfrage (Mensch)
if(auswahl == 1){
    //Spielfeld ausgabe test
    spielfeldausgabe();
    abfragespieler(2,0);
}

else{
//Computer
abfragespieler(2, 1);
}

spielfeldausgabe();

//Konsole clear    
system("cls");

//Gewinnpruefung Spieler 2
if ((gewinnpruefer(22) == 1) || (gewinnpruefer(22) == 3))
{
if(auswahl == 2)
{
    if(gewinnpruefer(22) == 1)
    {
        spielfeldausgabe();
        printf("Der Computer hat Gewonnen!");
    }    
}
else
{
    if(gewinnpruefer(22) == 1)
    {
        spielfeldausgabe();
        printf("Spieler 2 hat Gewonnen!");
    } 
}

if(gewinnpruefer(22) == 3)
{
    spielfeldausgabe();
    printf("Unentschieden!");
} 
printf("\nNoch mal? (Y/N)\n");
fflush(stdin);
scanf("%c", &neueRunde);

if(neueRunde == 'y' || neueRunde == 'Y'){

    //Spielmodi Auswahl
    printf("\nSpielmodi:\n");
    printf("[1] 2 Spieler\n");
    printf("[2] Computer\n");
    scanf("%d", &auswahl);

    //Spielfeld clear
    spielfeldclear();

    goto ende;
}
else
{
    return 0;
}
}
ende :
printf("\n");

}while (1);
return 0;
}


void spielfeldausgabe()
{
//Array ausgeben, Spielfeld anzeigen
//0-2, 3-5, 6-8

int i;
//Reihe 1
for(i=0; i<=2;i++){
    if(spielfeld[i] == 11)
    {
        //Für die Vertikalen Striche
        if(i == 1)
        {
            printf("|\e[1;34m x \e[0m|");  
        }
        else
        {
            printf("\e[1;34m x \e[0m");
        }   
    }
    else if(spielfeld[i] == 22)
    {
        //Für die Vertikalen Striche
        if(i == 1)
        {
            printf("|\e[1;31m o \e[0m|");  
        }
        else
        {
            printf("\e[1;31m o \e[0m");
        }
    }
    else
    {
        //Für die Vertikalen Striche
        if(i == 1)
        {
            printf("| %d |", spielfeld[i]);  
        }
        else
        {
            printf(" %d ", spielfeld[i]);
        }
    }
}

printf("\n-----------\n");

//Reihe 2
for(i=3; i<=5;i++)
{
    if(spielfeld[i] == 11)
    {
        if(i == 4)
        {
            printf("|\e[1;34m x \e[0m|");  
        }
        else{
            printf("\e[1;34m x \e[0m");
        }  
    }
    else if(spielfeld[i] == 22)
    {
        if(i == 4)
        {
            printf("|\e[1;31m o \e[0m|");  
        }
        else
        {
            printf("\e[1;31m o \e[0m");
        }
    }
    else{
        if(i == 4)
        {
            printf("| %d |", spielfeld[i]);  
        }
        else
        {
            printf(" %d ", spielfeld[i]);
        }
    }
}
printf("\n-----------\n");

//Reihe 3
for(i=6; i<=8;i++)
{
    if(spielfeld[i] == 11)
    {
        if(i == 7)
        {
            printf("|\e[1;34m x \e[0m|");  
        }
        else
        {
            printf("\e[1;34m x \e[0m");
        } 
    }
    else if(spielfeld[i] == 22)
    {
        if(i == 7)
        {
            printf("|\e[1;31m o \e[0m|");  
        }
        else
        {
            printf("\e[1;31m o \e[0m");
        }
    }
    else
    {
        if(i == 7)
        {
          printf("| %d |", spielfeld[i]);  
        }
        else
        {
            printf(" %d ", spielfeld[i]);
        }
    }
}
printf("\n\n");
}

int gewinnpruefer(int spieler)
{
//Ausgabe: Gewonnen=1, Nicht gewonnen=2, Unentschieden=3
//Eingabewert: Spieler1: 11, Spieler2: 22
if((spielfeld[0] == spieler) && (spielfeld[1] == spieler) && (spielfeld[2] == spieler)){
    return 1;
}
if((spielfeld[3] == spieler) && (spielfeld[4] == spieler) && (spielfeld[5] == spieler)){
    return 1;
}
if((spielfeld[6] == spieler) && (spielfeld[7] == spieler) && (spielfeld[8] == spieler)){
    return 1;
}
if((spielfeld[0] == spieler) && (spielfeld[3] == spieler) && (spielfeld[6] == spieler)){
    return 1;
}
if((spielfeld[1] == spieler) && (spielfeld[4] == spieler) && (spielfeld[7] == spieler)){
    return 1;
}
if((spielfeld[2] == spieler) && (spielfeld[5] == spieler) && (spielfeld[8] == spieler)){
    return 1;
}
if((spielfeld[0] == spieler) && (spielfeld[4] == spieler) && (spielfeld[8] == spieler)){
    return 1;
}
if((spielfeld[6] == spieler) && (spielfeld[4] == spieler) && (spielfeld[2] == spieler)){
    return 1;
}
if(spielfeld[0] != 1 && spielfeld[1] != 2 && spielfeld[2] != 3 && spielfeld[3] != 4 && spielfeld[4] != 5 && spielfeld[5] != 6 
&& spielfeld[6] != 7 && spielfeld[7] != 8 && spielfeld[8] != 9){
    //Unentschieden
    return 3;
}
else{
    //Spiel noch nicht gewonnen
    return 2;
}   
}

void spielfeldclear(){
for(int j = 1; j <= 9; j++){
    spielfeld[j-1]= j;
}
}

//Noch Sehr langsam, durch srand und 1Dim-Array
void abfragespieler(int spieler, int computer){
//Diese Funktion fragt den Spieler nach seinem Feld ab und speichert die Position ab 
//int computer: 0: Menschlicher Spieler, 1: Computer   

//Variablen der Funktion abfragespieler
int eingabe = 0;
time_t t;

//Zufallsgenerator initialisieren
srand((unsigned) time(&t));

//Ueberpruefen, ob Feld schon belegt ist mit goto :-)
AbfrageSpieler :

if(computer == 1){

//Zufallszahl erstellen und in Eingabe schreiben
eingabe = rand() %  9 + 1;
}

if(computer == 0){

//Spieler 1 oder 2 Abfrage
if(spieler == 1){
printf("Spieler 1 (x): Bitte Spielfeld eingeben:\n");
}
else{
printf("Spieler 2 (o): Bitte Spielfeld eingeben:\n");    
}
scanf("%d", &eingabe);
}

if(spielfeld[eingabe - 1] == eingabe)
{
    if(spieler == 1){
    //Spielerzeichen Spieler 1 in Array schreiben
    spielfeld[eingabe - 1]  = 11;
    }
    if(spieler == 2){
    //Spielerzeichen Spieler 2 in Array schreiben
    spielfeld[eingabe - 1]  = 22;
    }
}
else
{
    if(computer == 0){
    printf("Spielfeld ist schon belegt!\n");
    }
    goto AbfrageSpieler;
}
}