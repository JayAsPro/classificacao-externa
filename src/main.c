/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 1 - Classificação Externa por Seleção com Substituição
    
    Código principal do programa. Baseado no código disponibilizado
    pela professora.
*/

#include <stdio.h>
#include <locale.h>
#include <utils.h>
#include <arquivoBinario.h>
#include <sort.h>

void menu(void) {
    limpar_tela();
    printf("******** Lista de produtos ********");
    printf("\n(1) Inserir");
    printf("\n(2) Mostrar todos");
    printf("\n(3) Recriar arquivo");
    printf("\n(4) Classificar arquivo");
    printf("\n(0) Sair");
    printf("\n***********************");
    printf("\n\nEscolha: ");
}

int main(void) {
    /*
        Desativa o buffer da saída padrão. Contorna o fato de que algumas
        implementações de C podem, por exemplo, não exibir imediatamente o
        resultado de um printf se ele não terminar com "\n", a não ser que
        se faça explicitamente um flush na saída padrão (ex.: musl).
    */
    setbuf(stdout, NULL);
    
    setlocale(LC_ALL, "Portuguese");
    
    char nome_arq[] = "arq.bin";    
    FILE* arq;
    
    char ch;
    int cod;
    float preco;
    
    arq = fopen(nome_arq, "a+b");
    if (arq == NULL) {
        printf("Erro na abertura do arquivo %s.", nome_arq);
        return 1;
    }
    
    ch = '\0';
    do {
        menu();
        ch = getchar();
        limpar_buffer();

        switch(ch) {
            case '1':
                printf("Informe o codigo: ");
                scanf("%d", &cod);
                limpar_buffer();

                printf("Informe o preco: ");
                scanf("%f", &preco);
                limpar_buffer();
                
                insere(arq, cod, preco);
                printf("\nProduto inserido com sucesso!");

                pausar();
                break;    
             case '2':
                printf("***** Lista de produtos *****");
                printf("\n\n");
                imprime_todos(arq);

                pausar();
                break;
            case '3':
                arq = recria_arquivo(arq, nome_arq);
                printf("\nArquivo recriado com sucesso!");

                pausar();
                break;
        }               
    } while (ch != '0');

    fclose(arq);
    limpar_tela();
   
    return 0;
}
