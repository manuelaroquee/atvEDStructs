#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    float preco;
} Produto;

// Entrar com os nomes e preços dos produtos
void entraProdutos(Produto produtos[], int qtdProdutos){
    printf("Entre com os nomes e preços dos produtos:\n");
    for (int i = 0; i < qtdProdutos; i++){
        printf("Produto %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", produtos[i].nome);
        printf("Preço: ");
        scanf("%f", &produtos[i].preco);
    }
}

// Calcular o total da compra
float calculaTotal(Produto produtos[], int qtdProdutos){
    float total = 0;
    for (int i = 0; i < qtdProdutos; i++){
        total += produtos[i].preco;
    }
    return total;
}

// Mostrar o produto mais caro
void produtoMaisCaro(Produto produtos[], int qtdProdutos){
    int indiceMaisCaro = 0;
    for (int i = 1; i < qtdProdutos; i++){
        if (produtos[i].preco > produtos[indiceMaisCaro].preco){
            indiceMaisCaro = i;
        }
    }
    printf("Produto mais caro: %s, Preço: %.2f\n", produtos[indiceMaisCaro].nome, produtos[indiceMaisCaro].preco);
}

// Mostrar o produto mais barato
void produtoMaisBarato(Produto produtos[], int qtdProdutos){
    int indiceMaisBarato = 0;
    for (int i = 1; i < qtdProdutos; i++){
        if (produtos[i].preco < produtos[indiceMaisBarato].preco){
            indiceMaisBarato = i;
        }
    }
    printf("Produto mais barato: %s, Preço: %.2f\n", produtos[indiceMaisBarato].nome, produtos[indiceMaisBarato].preco);
}

int main(){
    int qtdProdutos = 5;
    Produto produtos[qtdProdutos];
    int opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Entrar com nomes e preços dos produtos\n");
        printf("2. Calcular o total da compra\n");
        printf("3. Mostrar o produto mais caro\n");
        printf("4. Mostrar o produto mais barato\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                entraProdutos(produtos, qtdProdutos);
                break;
            case 2:
                printf("Total da compra: %.2f\n", calculaTotal(produtos, qtdProdutos));
                break;
            case 3:
                produtoMaisCaro(produtos, qtdProdutos);
                break;
            case 4:
                produtoMaisBarato(produtos, qtdProdutos);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

