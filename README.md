# Sistema de Gerenciamento de Veículos 🚗

Bem-vindo ao **Sistema de Gerenciamento de Veículos**, um projeto desenvolvido em C para gerenciar o cadastro, listagem e aplicação de multas em veículos. Este projeto foi criado como parte do meu aprendizado em programação, com o objetivo de consolidar conceitos fundamentais da linguagem C e boas práticas de desenvolvimento.

---

## 📋 Funcionalidades

O sistema oferece as seguintes funcionalidades:
- **Cadastrar Veículos**: Permite registrar veículos com informações como código, tipo (Carro ou Moto), placa, modelo e marca.
- **Listar Veículos**: Exibe todos os veículos cadastrados no sistema.
- **Aplicar Multas**: Permite buscar um veículo pelo código, registrar o valor e o motivo da multa.
- **Menu Interativo**: Um menu simples e intuitivo para navegar entre as opções.
- **Validações**: Verifica se há veículos cadastrados antes de listar ou aplicar multas.

---

## 🛠️ Tecnologias e Ferramentas Utilizadas

- **Linguagem C**: Para implementar a lógica do sistema.
- **Compilador GCC**: Para compilar o código.
- **Windows API (`windows.h`)**: Para funcionalidades como `Sleep` e limpeza de tela (`system("cls")`).
- **Visual Studio Code**: Como ambiente de desenvolvimento.

---

## 📚 O que eu aprendi

Durante o desenvolvimento deste projeto, aprendi e pratiquei diversos conceitos importantes, como:

1. **Estruturas (`struct`)**:
   - Como criar e usar estruturas para organizar dados complexos, como os veículos.
   - Exemplo: A estrutura `Vehicle` foi usada para armazenar informações como placa, modelo, marca, tipo e código.

2. **Manipulação de Arrays**:
   - Uso de arrays para armazenar múltiplos veículos e iterar sobre eles para exibição ou busca.

3. **Funções**:
   - Modularização do código em funções para melhorar a organização e reutilização.
   - Exemplo: Funções como `registerVehicle`, `listVehicle` e `fineVehicle`.

4. **Entrada e Saída de Dados**:
   - Uso de `scanf` e `fgets` para capturar entradas do usuário.
   - Tratamento de problemas com o buffer de entrada usando `clearInputBuffer`.

5. **Laços e Condicionais**:
   - Uso de `for`, `if` e `switch` para implementar a lógica do sistema.

6. **Validações**:
   - Verificação de condições, como impedir o cadastro de mais veículos além do limite ou evitar operações em listas vazias.

7. **Boas Práticas**:
   - Organização do código com comentários e prototipação de funções.
   - Uso de constantes (`#define MAX_VEHICLES 100`) para facilitar a manutenção.

---

## 🚀 Como executar o projeto

### Pré-requisitos
- Um compilador C, como o **GCC**.
- Sistema operacional Windows (devido ao uso de `windows.h`).

### Passos para compilar e executar:
1. Clone este repositório:
   ```bash
   git clone https://github.com/swetonyancelmo/sistema-de-transito.git
   cd sistema-de-transito
