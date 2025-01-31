#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 32 //Número maximo de cidades 

typedef struct {// Estrutura para armazenar informações das cidades
    char codigo[4]; // Código da cidade (Ex: "A01")
    char nome[50]; // Nome da cidade
    int populacao; // População da cidade
    float area; // Área da cidade em km²
    float pib; // PIB da cidade em bilhões
    int pontos_turisticos; // Número de pontos turísticos
    float densidade_populacional; // Calculado como população / área
    float pib_per_capita; // Calculado como PIB / população
} Cidade;

// Função para cadastrar uma nova cidade
void cadastrarCidades(Cidade cidades[], int *totalCidades) {
    if (*totalCidades >= MAX_CIDADES) { // Verifica se atingiu o limite de cidades
        printf("\nLimite de cidades atingido!\n");
        return;
    }
    
    Cidade nova;
    printf("\nDigite o código da cidade (Ex: A01, B02): ");
    scanf(" %3s", nova.codigo);
    
    printf("Nome da cidade: ");
    getchar(); // Limpa buffer do teclado
    fgets(nova.nome, sizeof(nova.nome), stdin);
    nova.nome[strcspn(nova.nome, "\n")] = '\0'; // Remove a quebra de linha do nome

    printf("População: ");
    scanf("%d", &nova.populacao);
    
    printf("Área (km²): ");
    scanf("%f", &nova.area);
    
    printf("PIB (em bilhões): ");
    scanf("%f", &nova.pib);
    
    printf("Número de pontos turísticos: ");
    scanf("%d", &nova.pontos_turisticos);
    
    // Cálculo das novas propriedades
    nova.densidade_populacional = nova.populacao / nova.area;
    nova.pib_per_capita = (nova.pib * 1000000000) / nova.populacao; // Convertendo PIB de bilhões para unidade monetária
    
    // Adiciona a nova cidade ao array
    cidades[*totalCidades] = nova;
    (*totalCidades)++;
    
    printf("\nCidade cadastrada com sucesso!\n");
}

// Função para listar todas as cidades cadastradas
void listarCidades(Cidade cidades[], int totalCidades) {
    if (totalCidades == 0) { // Verifica se há cidades cadastradas
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
        printf("Densidade Populacional: %.2f hab/km²\n", cidades[i].densidade_populacional);
        printf("PIB per capita: %.2f\n", cidades[i].pib_per_capita);
    }
}

// Função principal
int main() {
    Cidade cidades[MAX_CIDADES]; // Array para armazenar as cidades
    int totalCidades = 0; // Contador de cidades cadastradas
    int opcao;
    
    do {
        // Menu principal
        printf("\nSuper Trunfo - Países\n");
        printf("1. Cadastrar Cidade\n");
        printf("2. Listar Cidades\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        // Execução da opção escolhida pelo usuário
        switch (opcao) {
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
