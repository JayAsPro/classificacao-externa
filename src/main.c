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
    printf("\n(5) Popular com dados de teste");
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
                if(scanf("%d", &cod) != 1) {
                    printf("\n✗ Código inválido!\n");
                    limpar_buffer();
                    pausar();
                    break;
                }
                limpar_buffer();

                printf("Informe o preco: ");
                if(scanf("%f", &preco) != 1) {
                    printf("\n✗ Preço inválido!\n");
                    limpar_buffer();
                    pausar();
                    break;
                }
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
                if(arq != NULL) {
                    printf("\nArquivo recriado com sucesso!");
                } else {
                    printf("\nErro ao recriar arquivo!");
                }

                pausar();
                break;
            case '4':
                printf("***** Classificação Externa *****\n");
                printf("Gerando partições ordenadas...\n\n");
                
                size_t num_part = classificacao_externa(arq);
                
                if(num_part > 0) {
                    printf("\n✓ %zu partições geradas com sucesso!\n", num_part);
                    imprime_particoes(num_part);
                } else {
                    printf("\n✗ Nenhuma partição foi gerada.\n");
                }
                
                pausar();
                break;
            case '5':
                popular_dados_teste(arq);
                
                pausar();
                break;
        }               
    } while (ch != '0');

    fclose(arq);
    limpar_tela();
   
    return 0;
}
