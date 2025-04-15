// Inclusão das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void menu();
void registerVehicle();
void fineVehicle();
void searchVehicle();
void pause();

// Variável globlal que recebe a opção que o usuário vai escolher
char op;

int main(){
  int running = 1; // Variavel para rodar o loop

  // Ciclo que irá funcionar o programa
  do{
    system("cls");
    menu();
    
    system("cls");

    switch (op){
      case 'C':
      case 'c':
        registerVehicle();
        break;
      case 'M':
      case 'm':
        fineVehicle();
        break;
      case 'B':
      case 'b':
        searchVehicle();
        break;
      case 'E':
      case 'e':
        printf("Programa encerrado com sucesso.");
        running = 0;
        break;
      default:
        printf("Alternativa invalida, insira novamente.\n");
        Sleep(2000);
        continue;
      }

      if (running) pause();


  } while (running);
  
  
  return 0;
}

// Função do menu
void menu(){
  printf("=====Bem Vindo ao Sistema de Transito=====\n");
  printf("\n           ===MENU PRINCIPAL===\n\n");
  printf("Escolha uma das opcoes abaixo: \n\n");
  printf("Cadastrar veiculo (C)\n");
  printf("Multar veiculo (M)\n");
  printf("Buscar veiculo (B)\n");
  printf("Encerrar programa (E)\n");
  scanf(" %c", &op);
  fflush(stdin);
}

// Função para pausa 'genérica'
void pause(){
  printf("\nPressione ENTER para voltar...");
  fflush(stdin);
  getchar(); // aguardar pressionamento real
}

// Função para registrar um veiculo
void registerVehicle(){
  printf("Funcao de cadastro de veiculo chamada.\n");
  pause();
}

// Função para multar um veiculo
void fineVehicle(){
  printf("Funcao de multar veiculo chamada.\n");
  pause();
}

// Função para buscar um veiculo
void searchVehicle(){
  printf("Funcao de buscar veiculo chamada.\n");
  pause();
}