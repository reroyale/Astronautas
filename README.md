# Astronautas

Este projeto foi desenvolvido como parte da Atividade 1 da disciplina de Linguagem de Programação 1 (LP1) do Instituto Metrópole Digital (IMD/UFRN). O sistema simula o controle de astronautas e voos de uma agência espacial, gerenciando estados de missões, saúde dos tripulantes e histórico de voos.

## Funcionalidades

O sistema processa comandos via terminal para realizar as seguintes operações:

- **Cadastrar Astronautas**: Registro por CPF, nome e idade.
- **Cadastrar Voos**: Criação de missões espaciais identificadas por um código.
- **Gestão de Tripulação**: Adicionar ou remover astronautas de voos que ainda estão em fase de planejamento.
- **Lançamento de Voos**: Altera o estado do voo para "Em curso", validando se há tripulação e se todos estão disponíveis e vivos.
- **Finalização de Missões**:
  -**Sucesso**: Retorna os astronautas para o estado "Disponível".
  -**Explosão**: Altera o estado dos astronautas para "Morto".
- **Relatórios**:
  - Listagem de voos agrupados por estado (Planejado, Em Curso, Sucesso, Explosão).
  - Listagem de astronautas mortos com histórico de missões das quais participaram.

## Tecnologias Utilizadas

- **C++11** (ou superior)
- **Biblioteca Standard (STL)**: Uso de `vector`, `string` e `iostream`.
- **Programação Orientada a Objetos (POO)**: Classes mínimas Astronauta e Voo separadas em módulos.

## Estrutura do Projeto

- `Astronauta.hpp`: Definição da classe Astronauta com atributos de identificação, saúde e disponibilidade.
- `Voo.hpp`: Definição da classe Voo com código, lista de passageiros e estados.
- `main.cpp`: Lógica principal, processamento de comandos e controle de regras de negócio.

## Como Executar

1. **Clonar o Repositório**:
   ```bash
   git clone https://github.com/reroyale/Astronautas.git C:\Users\Public\Downloads\Astronautas


2. **Compilar o Código**:]
   ```bash
   cd\
   cd C:\Users\Public\Downloads\Astronautas
   g++ -o astronautas.exe main.cpp

3. **Executar**:]
   ```bash
   ./astronautas.exe
