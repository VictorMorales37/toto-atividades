Nome: Victor Matheus Marques Morales

Turma: M1

Matrícula: 25100782

# Agenda em C - Algoritmos e Estruturas de Dados I - UFPEL

Sistema de agenda desenvolvido em C utilizando apenas um único bloco de memória dinâmica (`pBuffer`) para armazenar variáveis e dados das pessoas.

## Funcionalidades

* Adicionar pessoa
* Remover pessoa
* Buscar pessoa
* Listar pessoas

## Conceitos utilizados

* `malloc`
* `realloc`
* `free`
* Aritmética de ponteiros
* Manipulação manual de memória

## Estrutura da memória

```text id="ohjlwm"
pBuffer:
[int choice]
[int personCounter]
[int counter]
[int totalSize]
[int buffer]
[person][next person...]
```

Pessoa:

```text id="l2fajc"
[int size][nome][idade][email]
```

## Objetivo
Praticar gerenciamento de memória dinâmica e ponteiros em C.
