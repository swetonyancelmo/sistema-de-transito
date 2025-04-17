// Inclusão das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Estrutura para armazenar os dados do veículo
typedef struct Vehicle{
  char plate[8];  // Placa do veículo
  char model[20]; // Modelo do veículo
  char brand[20]; // Marca do veículo
  char type;      // Tipo do veículo (C ou M)
  int code;       // Código do veículo
} Vehicle;

// Prototipação das funções
void menu();
void registerVehicle();
void fineVehicle();
void listVehicle();
void pause();
void registerVehicleDetails();
void clearInputBuffer();

#define MAX_VEHICLES 100 // Limite máximo de veículos

Vehicle vehicles[MAX_VEHICLES]; // Array para armazenar os veículos cadastrados
int vehicleCount = 0;           // Contador de veículos cadastrados

// Variável global que recebe a opção que o usuário vai escolher
char op;

// Função principal
int main(){
  int running = 1;

  do{
    system("cls");
    menu();

    system("cls");

    switch (op)
    {
    case 'C':
    case 'c':
      registerVehicle();
      break;
    case 'M':
    case 'm':
      fineVehicle();
      break;
    case 'L':
    case 'l':
      listVehicle();
      break;
    case 'E':
    case 'e':
      printf("Programa encerrado com sucesso.\n");
      running = 0;
      break;
    default:
      printf("Alternativa inválida, insira novamente.\n");
      Sleep(2000);
      continue;
    }

    if (running)
      pause();

  } while (running);

  return 0;
}

// Função do menu
void menu(){
  printf("===== Bem-vindo ao Sistema de Trânsito =====\n\n");
  printf("           === MENU PRINCIPAL ===\n\n");
  printf("Escolha uma das opções abaixo:\n");
  printf("Cadastrar veículo (C)\n");
  printf("Multar veículo (M)\n");
  printf("Listar veículos  (L)\n");
  printf("Encerrar programa (E)\n");
  printf("\nOpção: ");
  scanf(" %c", &op);
  clearInputBuffer(); // Limpa o buffer após a entrada
}

// Função de pausa genérica
void pause(){
  printf("\nPressione ENTER para voltar...");
  clearInputBuffer();
  getchar(); // Aguarda ENTER
}

// Limpa o buffer de entrada
void clearInputBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Função para cadastrar veículo
void registerVehicle()
{
  printf("           === CADASTRO DE VEÍCULO ===\n\n");
  printf("Iniciar cadastro? (S/N)\n");
  printf("Voltar (V)\n");
  printf("Opção: ");
  scanf(" %c", &op);
  clearInputBuffer();

  switch (op){
  case 'S':
  case 's':
    registerVehicleDetails();
    break;
  case 'N':
  case 'n':
    printf("Cadastro cancelado.\n");
    return;
  case 'V':
  case 'v':
    printf("Voltando ao menu principal...\n");
    return;
  default:
    printf("Opção inválida.\n");
    return;
  }
}

// Função para registrar detalhes do veículo
void registerVehicleDetails(){
  if (vehicleCount >= MAX_VEHICLES){
    printf("Limite de veículos cadastrados atingido.\n");
    return;
  }

  Vehicle vehicle;

  printf("\n--- Dados do veículo ---\n");

  printf("Código do veículo: ");
  scanf("%d", &vehicle.code);
  clearInputBuffer();

  printf("Carro ou Moto? (C/M): ");
  scanf(" %c", &vehicle.type);
  clearInputBuffer();

  printf("Placa: ");
  scanf(" %7s", vehicle.plate); // máximo 7 caracteres + \0
  clearInputBuffer();

  printf("Modelo: ");
  scanf(" %19s", vehicle.model);
  clearInputBuffer();

  printf("Marca: ");
  scanf(" %19s", vehicle.brand);
  clearInputBuffer();

  vehicles[vehicleCount] = vehicle; // Armazena o veículo no array global
  vehicleCount++;

  printf("\n✅ Cadastro realizado com sucesso!\n");
}

// Função para multar veículo (ainda não implementada)
void fineVehicle(){
  if (vehicleCount == 0) {
    printf("Nenhum veículo cadastrado ainda.\n");
    return;
  }

  int code;
  printf("Digite o código do veículo a ser multado: ");
  scanf(" %d", &code);
  clearInputBuffer();

  // Busca pelo veículo com o código informado
  int found = 0; // para verificar se o veiculo foi encontrado
  for (int i = 0; i < vehicleCount; i++){
    if (vehicles[i].code == code){
      found = 1; // Veículo encontrado
      printf("Veículo encontrado:\n");
      printf("Código: %d\n", vehicles[i].code);
      printf("Tipo: %s\n", (vehicles[i].type == 'C' || vehicles[i].type == 'c') ? "Carro" : "Moto");
      printf("Placa: %s\n", vehicles[i].plate);
      printf("Modelo: %s\n", vehicles[i].model);
      printf("Marca: %s\n", vehicles[i].brand);
      
      // Pergunta o valor e o motivo da multa
      float fineValue;
      char fineReason[100];

      printf("Digite o valor da multa: R$ ");
      scanf("%f", &fineValue);
      clearInputBuffer();

      printf("Digite o motivo da multa: ");
      fgets(fineReason, sizeof(fineReason), stdin);
      fineReason[strcspn(fineReason, "\n")] = 0; // Remove o newline

      // Exibe os dados da multa
      printf("\n=== MULTA REGISTRADA ===\n");
      printf("Veículo: %s\n", vehicles[i].plate);
      printf("Valor da multa: R$ %.2f\n", fineValue);
      printf("Motivo: %s\n", fineReason);
      printf("Multa registrada com sucesso!\n");

      return;
    }
  }

  if (!found) {
    printf("Veículo com código %d não encontrado.\n", code);
  }
}

// Função para listar os veículos cadastrados
void listVehicle(){
  if (vehicleCount == 0){
    printf("Nenhum veículo cadastrado ainda.\n");
    return;
  }

  printf("=== LISTA DE VEÍCULOS CADASTRADOS ===\n\n");

  for (int i = 0; i < vehicleCount; i++){
    Vehicle v = vehicles[i];
    printf("Veículo #%d\n", i + 1);
    printf("Código: %d\n", v.code);
    printf("Tipo: %s\n", (v.type == 'C' || v.type == 'c') ? "Carro" : "Moto");
    printf("Placa: %s\n", v.plate);
    printf("Modelo: %s\n", v.model);
    printf("Marca: %s\n", v.brand);
    printf("-----------------------------\n");
  }
}
