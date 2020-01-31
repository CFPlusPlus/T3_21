//Das Spiel Tic Tac Toe in C
//(c)Christian Falkner, 16.01.2020
//Version 1.0

//Headerfiles einbinden
#include <stdio.h>
#include <stdlib.h>

//Globales Array
int spielfeld [9] = {0,1,2,3,4,5,6,7,8};

//Zur Compilerberuhigung
void spielfeldausgabe();
void spielfeldclear();
int gewinnpruefer();


int main(){
//Variablen
int eingabe;
int neustart;
char neueRunde;

printf("Willkommen in Tic Tac Toe!\n");
printf("Spieler 1: x    Spieler 2: o\n\n");
//Erstmalige Spielfeldausgabe
spielfeldausgabe();

do{
//Abfrage, Spieler 1,2
//Ueberpruefen, ob Feld schon belegt ist [goto :-)]
AbfrageSpieler1 :

//Spieler 1 Abfrage
printf("Spieler 1: Bitte Spielfeld eingeben (0-8):\n");
scanf("%d", &eingabe);

if(spielfeld[eingabe] == eingabe)
{
//Spielerzeichen in Array schreiben
spielfeld[eingabe]  = 11;
}
else
{
    printf("Spielfeld ist schon belegt!\n");
    goto AbfrageSpieler1;
}

spielfeldausgabe();

//Gewinnpruefung Spieler 1
if ((gewinnpruefer() == 1) || (gewinnpruefer() == 3))
{
if(gewinnpruefer() == 1){printf("Spieler 1 hat Gewonnen!");}    
if(gewinnpruefer() == 3){printf("Unentschieden!");} 
printf("\nNoch mal? (Y/N)\n");
fflush(stdin);
scanf("%c", &neueRunde);

if(neueRunde == 'y' || neueRunde == 'Y'){
    //Spielfeld clear
    spielfeldclear();
    //Spielfeld ausgabe
    spielfeldausgabe();
    goto ende;
}
else{
    return 0;
}
}


//Ueberpruefen, ob Feld schon belegt ist [goto :-)]
AbfrageSpieler2 :

//Spieler 2 Abfrage
printf("Spieler 2: Bitte Spielfeld eingeben (0-8):\n");
scanf("%d", &eingabe);

if(spielfeld[eingabe] == eingabe)
{
//Spielerzeichen in Array schreiben
spielfeld[eingabe]  = 22;
}
else
{
    printf("Spielfeld ist schon belegt!\n");
    goto AbfrageSpieler2;
}

spielfeldausgabe();

//Gewinnpruefung Spieler 2
if ((gewinnpruefer() == 1) || (gewinnpruefer() == 3))
{
if(gewinnpruefer() == 1){printf("Spieler 2 hat Gewonnen!");}    
if(gewinnpruefer() == 3){printf("Unentschieden!");} 
printf("\nNoch mal? (Y/N)\n");
fflush(stdin);
scanf("%c", &neueRunde);

if(neueRunde == 'y' || neueRunde == 'Y'){
    //Spielfeld clear
    spielfeldclear();
    //Spielfeld ausgabe
    spielfeldausgabe();
    goto ende;
}
else{
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
    if(spielfeld[i] == 11){
        printf(" x ");
    }
    else if(spielfeld[i] == 22){
        printf(" o ");
    }
    else{
        printf(" %d ", spielfeld[i]);
    }
}

printf("\n");

//Reihe 2
for(i=3; i<=5;i++){
        if(spielfeld[i] == 11){
        printf(" x ");
    }
    else if(spielfeld[i] == 22){
        printf(" o ");
    }
    else{
        printf(" %d ", spielfeld[i]);
    }
}
printf("\n");

//Reihe 3
for(i=6; i<=8;i++){
    if(spielfeld[i] == 11){
        printf(" x ");
    }
    else if(spielfeld[i] == 22){
        printf(" o ");
    }
    else{
        printf(" %d ", spielfeld[i]);
    }
}
printf("\n\n");
}

int gewinnpruefer()
{
    //Ausgabe: Gewonnen=1, Nicht gewonnen=2, Unentschieden=3
if((spielfeld[0] == 11) && (spielfeld[1] == 11) && (spielfeld[2] == 11) || ((spielfeld[0] == 22) && (spielfeld[1] == 22) && (spielfeld[2] == 22))){
    return 1;
}
if((spielfeld[3] == 11) && (spielfeld[4] == 11) && (spielfeld[5] == 11) || ((spielfeld[3] == 22) && (spielfeld[4] == 22) && (spielfeld[5] == 22))){
    return 1;
}
if((spielfeld[6] == 11) && (spielfeld[7] == 11) && (spielfeld[8] == 11) || ((spielfeld[6] == 22) && (spielfeld[7] == 22) && (spielfeld[8] == 22))){
    return 1;
}
if((spielfeld[0] == 11) && (spielfeld[3] == 11) && (spielfeld[6] == 11) || ((spielfeld[0] == 22) && (spielfeld[3] == 22) && (spielfeld[6] == 22))){
    return 1;
}
if((spielfeld[1] == 11) && (spielfeld[4] == 11) && (spielfeld[7] == 11) || ((spielfeld[1] == 22) && (spielfeld[4] == 22) && (spielfeld[7] == 22))){
    return 1;
}
if((spielfeld[2] == 11) && (spielfeld[5] == 11) && (spielfeld[8] == 11) || ((spielfeld[2] == 22) && (spielfeld[5] == 22) && (spielfeld[8] == 22))){
    return 1;
}
if((spielfeld[0] == 11) && (spielfeld[4] == 11) && (spielfeld[8] == 11) || ((spielfeld[0] == 22) && (spielfeld[4] == 22) && (spielfeld[8] == 22))){
    return 1;
}
if((spielfeld[6] == 11) && (spielfeld[4] == 11) && (spielfeld[2] == 11) || ((spielfeld[6] == 22) && (spielfeld[4] == 22) && (spielfeld[2] == 22))){
    return 1;
}
if(spielfeld[0] != 0 && spielfeld[1] != 1 && spielfeld[2] != 2 && spielfeld[3] != 3 && spielfeld[4] != 4 && spielfeld[5] != 5 
&& spielfeld[6] != 6 && spielfeld[7] != 7 && spielfeld[8] != 8){
    //Unentschieden
    return 3;
}
else{
    return 2;
}   
}

void spielfeldclear(){
for(int j = 0; j <= 8; j++){
    spielfeld[j]= j;
}
}