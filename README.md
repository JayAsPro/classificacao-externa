O arquivo principal do código do programa é o `arquivoBinario.c`. Ele foi criado originalmente pela professora da disiciplina, e foi modificado pelos alunos para a realização do trabalho. Além da adição da funcionalidade de classificação, que era o objetivo do trabalho, foram feitas algumas modificações extras:

- Para melhorar a portabilidade do código, que foi feito originalmente para Windows, substituiu-se a função `getch` e a chamada para o comando de sistema `cls` por duas funções próprias, `` e ``, respectivamente, que tentam reproduzir o mesmo comportamento sem utilizar funções fora da biblioteca padrão do C.
- Por uma questão de gosto estético, os espaços após `(` e antes de `)` foram removidos.

A formatação dos commits é inspirada na proposta em [Padrões de commits, de Iuri Silva](https://github.com/iuricode/padroes-de-commits).