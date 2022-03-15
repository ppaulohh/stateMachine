#include <stdio.h>
#include <stdlib.h>

//function pointer to designate wich function has to be executed in each moment
void (*Pointer)();

//Events declaration
void linkDown(void);
void linkStart(void);
void linkConfig(void);
void linkOk(void);


//Event implematation

// 1 - Link Down 
void linkDown(void){

  //Declaring state variable
	char state;
  //Cleaning input buffer
  	fflush(stdin);
  //Receiving input value
    scanf("%c", &state);
    //state = getch();
 //
    if (state == '1') //Interface nok
      Pointer = linkDown;
    if (state == '2') //Interface ok
      Pointer = linkStart;
    if (state == '3') //Pacote ok - recebido
      Pointer = linkDown;
    if (state == '4') //Pacote nok - recebido
      Pointer = linkDown;
    if (state == '5') //Não recebeu resposta
      Pointer = linkDown;
}


// 2 - Enviando start
void linkStart(void){

  //Declaring state variable
	char state;
  //Cleaning input buffer
  	fflush(stdin);
  //Receiving input value
    scanf("%c", &state);
    //state = getch();
 
  if (state == '1') //Interface nok
    Pointer = linkDown;
  /*if (state == '2') //Interface ok
    Pointer = linkStart;*/
  if (state == '3') //Pacote ok - recebido
    Pointer = linkConfig;
  if (state == '4') //Pacote nok - recebido
    Pointer = linkStart;
  if (state == '5') //Não recebeu resposta
    Pointer = linkStart;
}

// 3 - Enviando configuração
void linkConfig(void){

  //Declaring state variable
	char state;
  //Cleaning input buffer
  	fflush(stdin);
  //Receiving input value
    scanf("%c", &state);
    //state = getch();
 
  if (state == '1') //Interface nok
    Pointer = linkDown;
  /*if (state == '2') //Interface ok
    Pointer = linkStart;*/
  if (state == '3') //Pacote ok - recebido
    Pointer = linkOk;
  if (state == '4') //Pacote nok - recebido
    Pointer = linkConfig;
  if (state == '5') //Não recebeu resposta
    Pointer = linkStart;
}


// 4 - Keep alive
void linkOk(void){

  //Declaring state variable
	char state;
  //Cleaning input buffer
  	fflush(stdin);
  //Receiving input value
    printf("chegou no 4\n");
    scanf("%c", &state);
    //state = getch();
 
  if (state == '1') //Interface nok
    Pointer = linkDown;
  /*if (state == '2') //Interface ok
    Pointer = linkStart;*/
  if (state == '3') //Pacote ok - recebido
    Pointer = linkOk;
  if (state == '4') //Pacote nok - recebido
    Pointer = linkStart;
  if (state == '5') //Não recebeu resposta
    Pointer = linkStart;
}

int main(int argc, char *argv[])
{
  Pointer = linkDown; //aponta para o estado inicial. Nunca esquecer de informar um estado inicial (senão, nesse caso em específico, pode haver um erro fatal / hard fault).

  while(1)
  {
    printf("The value of s is: %p\n", Pointer);
    (*Pointer)();    //chama a função apontada pelo ponteiro de função (logo, chama o estado corrente)
  }
  system("PAUSE"); 
  return 0;
}