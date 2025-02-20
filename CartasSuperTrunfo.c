#include <stdio.h> //Entrada e saida de dados
#include <stdlib.h> //Aloção de memoria e conversões
#include <string.h> //Manipulação de strings

#define MAX_CIDADES 32 //Número maximo de cidades 

typedef struct { //Define as propriedades de uma cidade
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

void cadastrarCidades(Cidade cidades[], int *totalCidades) { //Rensposavel por cadastrar uma nova cidade ver se o limite foi atingido
    if (*totalCidades >= MAX_CIDADES) {
        printf("\nLimite de cidades atingido!\n");
        return;
    }

    Cidade nova;
    printf("\nDigite o código da cidade: "); //Ex-> A01, B02
    scanf(" %3s", &nova.codigo);
    printf("Nome da cidade: ");
    scanf(" %49[^\n]", &nova.nome);
    getchar();
    printf("Populacao: ");
    scanf("%d", &nova.populacao);
    printf("Área (km²): ");
    scanf("%f", &nova.area);
    printf("PIB (Bilhões): ");
    scanf("%f", &nova.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &nova.pontos_turisticos);

    cidades[*totalCidades] = nova;
    (*totalCidades)++;
    printf("\nCidade cadastrada com sucesso!\n");
}

void listarCidades(Cidade cidades[], int totalCidades) { //Exibe lista de cidades cadastradas
    if (totalCidades == 0) {
        printf("\nNenhuma cidade cadastrada.\n");
        return;
    }
    printf("\nLista de Cidades:\n");
    for (int i = 0; i < totalCidades; i++) {
        printf("-----------------------------\n");
        printf("Código: %s\n", cidades[i].codigo);
        printf("Nome: %s\n", cidades[i].nome);
        printf("População: %d\n", cidades[i].populacao);
        printf("Área: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2f bilhões\n", cidades[i].pib);
        printf("Pontos turísticos: %d\n", cidades[i].pontos_turisticos);
    }
} 

//função principal apresenta menu ao usuário para cadastrar,listar cidades
int main() { 
    Cidade cidades[MAX_CIDADES];
    int totalCidades = 0;
    int opcao;

    do { //Exibe o menu e processa a escolha do usuário
        printf("\n--Super Trunfo - Países--\n\n");
        printf("1. Cadastrar Cidade\n");
        printf("2. Listar Cidades\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) { //Estrutura de controle determina a ação com base na escolha do usuario
            case 1:
                cadastrarCidades(cidades, &totalCidades);
                break;
            case 2:
                listarCidades(cidades, totalCidades);
                break;
            case 3:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}
