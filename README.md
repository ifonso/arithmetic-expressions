# Trabalho de AEDI

Trabalho referente a tipos de notações de expressões aritiméticas e estruturas de dados abstratas.

**Objetivos**
- Descrever as formas que podem ser representadas expressões aritméticas.
- Identificar os valores e operações de um TDA para representar expressões aritméticas.
- Implementar operações para um TDA que representar expressões aritméticas e avalia essas expressões.
- Analisar as implementações das operações.

## Compilar (Makefile)
> É necessário o `gcc` instalado e o `make` para utilizar o makefile (você não precisa se preocupar com isso se estiver em um sistema UNIX like).

No terminal executo seguinte comando para compilar o arquivo.
```shell
$ make
```

## Compilar (gcc)
No terminal executo seguinte comando para compilar o arquivo.
```shell
$ gcc -I src main.c src/expression.c -o output
```

--- 
> Após executar o comando, o arquivo binário `output` deve ter sido gerado e você poder abrir ele para executar o programa.