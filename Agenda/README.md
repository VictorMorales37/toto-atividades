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

RESULTADO VALGRIND:
1- Adicionar Pessoa (Nome, Idade, email)
2- Remover Pessoa
3- Buscar Pessoa
4- Listar todos
5- Sair
Input: 1
Nome: joao silva
Idade: 32
E-mail: joaosilva@gmail.com
==88355== Invalid read of size 4
==88355==    at 0x10A19A: main (agendaMD.c:443)
==88355==  Address 0x4a86040 is 0 bytes inside a block of size 20 free'd
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x10931B: AddPerson (agendaMD.c:31)
==88355==    by 0x10A168: main (agendaMD.c:455)
==88355==  Block was alloc'd at
==88355==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x10A0A4: main (agendaMD.c:433)
==88355== 
==88355== Invalid write of size 4
==88355==    at 0x10A0F0: main (agendaMD.c:444)
==88355==  Address 0x4a86040 is 0 bytes inside a block of size 20 free'd
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x10931B: AddPerson (agendaMD.c:31)
==88355==    by 0x10A168: main (agendaMD.c:455)
==88355==  Block was alloc'd at
==88355==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x10A0A4: main (agendaMD.c:433)
==88355== 

1- Adicionar Pessoa (Nome, Idade, email)
2- Remover Pessoa
3- Buscar Pessoa
4- Listar todos
5- Sair
Input: 1
==88355== Invalid write of size 4
==88355==    at 0x48E1146: __vfscanf_internal (vfscanf-internal.c:1976)
==88355==    by 0x48D0EC5: __isoc99_scanf (isoc99_scanf.c:30)
==88355==    by 0x10A129: main (agendaMD.c:449)
==88355==  Address 0x4a86040 is 0 bytes inside a block of size 20 free'd
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x10931B: AddPerson (agendaMD.c:31)
==88355==    by 0x10A168: main (agendaMD.c:455)
==88355==  Block was alloc'd at
==88355==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x10A0A4: main (agendaMD.c:433)
==88355== 
==88355== Invalid read of size 4
==88355==    at 0x10A133: main (agendaMD.c:452)
==88355==  Address 0x4a86040 is 0 bytes inside a block of size 20 free'd
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x10931B: AddPerson (agendaMD.c:31)
==88355==    by 0x10A168: main (agendaMD.c:455)
==88355==  Block was alloc'd at
==88355==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x10A0A4: main (agendaMD.c:433)
==88355== 
Nome: maria oliveira
Idade: 32
E-mail: email

1- Adicionar Pessoa (Nome, Idade, email)
2- Remover Pessoa
3- Buscar Pessoa
4- Listar todos
5- Sair
Input: 2
Busque por nome para excluir: joao silva
==88355== Invalid read of size 4
==88355==    at 0x1098DB: RemovePerson (agendaMD.c:184)
==88355==    by 0x10A176: main (agendaMD.c:459)
==88355==  Address 0x4a884fc is 12 bytes inside a block of size 89 free'd
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x1098C8: RemovePerson (agendaMD.c:181)
==88355==    by 0x10A176: main (agendaMD.c:459)
==88355==  Block was alloc'd at
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x109825: RemovePerson (agendaMD.c:162)
==88355==    by 0x10A176: main (agendaMD.c:459)
==88355== 
==88355== Invalid read of size 4
==88355==    at 0x10999E: RemovePerson (agendaMD.c:199)
==88355==    by 0x10A176: main (agendaMD.c:459)
==88355==  Address 0x4a88b4c is 12 bytes inside a block of size 98 free'd
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x10998B: RemovePerson (agendaMD.c:196)
==88355==    by 0x10A176: main (agendaMD.c:459)
==88355==  Block was alloc'd at
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x1098C8: RemovePerson (agendaMD.c:181)
==88355==    by 0x10A176: main (agendaMD.c:459)
==88355== 
Pessoa removida

1- Adicionar Pessoa (Nome, Idade, email)
2- Remover Pessoa
3- Buscar Pessoa
4- Listar todos
5- Sair
Input: 3 
Busque por nome: maria oliveira
==88355== Invalid read of size 4
==88355==    at 0x109C97: SearchPerson (agendaMD.c:294)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355==  Address 0x4a88d2c is 12 bytes inside a block of size 50 free'd
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x109C84: SearchPerson (agendaMD.c:291)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355==  Block was alloc'd at
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x109BE1: SearchPerson (agendaMD.c:272)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355== 
==88355== Invalid read of size 4
==88355==    at 0x109CC8: SearchPerson (agendaMD.c:297)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355==  Address 0x4a88d28 is 8 bytes inside a block of size 50 free'd
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x109C84: SearchPerson (agendaMD.c:291)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355==  Block was alloc'd at
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x109BE1: SearchPerson (agendaMD.c:272)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355== 
==88355== Invalid read of size 4
==88355==    at 0x109D5A: SearchPerson (agendaMD.c:309)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355==  Address 0x4a8942c is 12 bytes inside a block of size 63 free'd
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x109D47: SearchPerson (agendaMD.c:306)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355==  Block was alloc'd at
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x109C84: SearchPerson (agendaMD.c:291)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355== 
==88355== Invalid read of size 4
==88355==    at 0x109D9A: SearchPerson (agendaMD.c:313)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355==  Address 0x4a89428 is 8 bytes inside a block of size 63 free'd
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x109D47: SearchPerson (agendaMD.c:306)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355==  Block was alloc'd at
==88355==    at 0x484DB80: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==88355==    by 0x109C84: SearchPerson (agendaMD.c:291)
==88355==    by 0x10A184: main (agendaMD.c:463)
==88355== 
Nome: maria oliveira
Idade: 32
E-mail: email
1- Adicionar Pessoa (Nome, Idade, email)
2- Remover Pessoa
3- Buscar Pessoa
4- Listar todos
5- Sair
Input: 5
==88355== 
==88355== HEAP SUMMARY:
==88355==     in use at exit: 0 bytes in 0 blocks
==88355==   total heap usage: 89 allocs, 89 frees, 7,300 bytes allocated
==88355== 
==88355== All heap blocks were freed -- no leaks are possible
==88355== 
==88355== For lists of detected and suppressed errors, rerun with: -s
==88355== ERROR SUMMARY: 58 errors from 10 contexts (suppressed: 0 from 0)
