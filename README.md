# Astronautas

Este projeto foi desenvolvido como parte da Atividade 1 da disciplina de Linguagem de Programação 1 (LP1) do Instituto Metrópole Digital (IMD/UFRN). O sistema simula o controle de astronautas e voos de uma agência espacial, gerenciando estados de missões, saúde dos tripulantes e histórico de voos.

## Funcionalidades

O sistema processa comandos via terminal para realizar as seguintes operações:

- [cite_start]**Cadastrar Astronautas**: Registro por CPF, nome e idade[cite: 88, 89].
- [cite_start]**Cadastrar Voos**: Criação de missões espaciais identificadas por um código[cite: 97, 98].
- [cite_start]**Gestão de Tripulação**: Adicionar ou remover astronautas de voos que ainda estão em fase de planejamento[cite: 104, 115].
- [cite_start]**Lançamento de Voos**: Altera o estado do voo para "Em curso", validando se há tripulação e se todos estão disponíveis e vivos[cite: 125, 132, 133].
- **Finalização de Missões**:
  - [cite_start]**Sucesso**: Retorna os astronautas para o estado "Disponível"[cite: 147, 155].
  - [cite_start]**Explosão**: Altera o estado dos astronautas para "Morto"[cite: 136, 144].
- **Relatórios**:
  - [cite_start]Listagem de voos agrupados por estado (Planejado, Em Curso, Sucesso, Explosão)[cite: 157, 158].
  - [cite_start]Listagem de astronautas mortos com histórico de missões das quais participaram[cite: 169, 176].

## Tecnologias Utilizadas

- **C++11** (ou superior)
- [cite_start]**Biblioteca Standard (STL)**: Uso de `vector`, `string` e `iostream`[cite: 12, 13, 14].
- [cite_start]**Programação Orientada a Objetos (POO)**: Classes mínimas Astronauta e Voo separadas em módulos[cite: 34, 35].

## Estrutura do Projeto

- [cite_start]`Astronauta.hpp`: Definição da classe Astronauta com atributos de identificação, saúde e disponibilidade[cite: 36, 37].
- [cite_start]`Voo.hpp`: Definição da classe Voo com código, lista de passageiros e estados[cite: 44, 45, 49].
- [cite_start]`main.cpp`: Lógica principal, processamento de comandos e controle de regras de negócio[cite: 55, 62].

## Como Executar

1. **Clonar o repositório**:
   ```bash
   git clone [https://github.com/seu-usuario/nome-do-repositorio.git](https://github.com/seu-usuario/nome-do-repositorio.git)
