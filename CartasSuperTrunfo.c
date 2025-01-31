#include <stdio.h> //Entrada e saida de dados
#include <stdlib.h> //Aloção de memoria e conversões
#include <string.h> //Manipulação de strings

#define MAX_CIDADES 32 //Número maximo de cidades 

// Estrutura para armazenar informações das cidades
typedef struct {
    char codigo[4]; // Código da cidade (Ex: "A01")
    char nome[50]; // Nome da cidade
    unsigned long int populacao; // População da cidade
    float area; // Área da cidade em km²
    float pib; // PIB da cidade em bilhões
    int pontos_turisticos; // Número de pontos turísticos
    float densidade_populacional; // Calculado como população / área
    float pib_per_capita; // Calculado como PIB / população
    float super_poder; // Soma das propriedades ajustadas
} Cidade;

// Função para calcular o super poder de uma cidade
float calcularSuperPoder(Cidade cidade) {
    return cidade.populacao + cidade.area + cidade.pib + cidade.pontos_turisticos + (1 / cidade.densidade_populacional) + cidade.pib_per_capita;
}

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
    scanf("%lu", &nova.populacao);
    
    printf("Área (km²): ");
    scanf("%f", &nova.area);
    
    printf("PIB (em bilhões): ");
    scanf("%f", &nova.pib);
    
    printf("Número de pontos turísticos: ");
    scanf("%d", &nova.pontos_turisticos);
    
    // Cálculo das novas propriedades
    nova.densidade_populacional = nova.populacao / nova.area;
    nova.pib_per_capita = (nova.pib * 1000000000) / nova.populacao; // Convertendo PIB de bilhões para unidade monetária
    nova.super_poder = calcularSuperPoder(nova);
    
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
        printf("População: %lu\n", cidades[i].populacao);
        printf("Área: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2f bilhões\n", cidades[i].pib);
        printf("Pontos turísticos: %d\n", cidades[i].pontos_turisticos);
        printf("Densidade Populacional: %.2f hab/km²\n", cidades[i].densidade_populacional);
        printf("PIB per capita: %.2f\n", cidades[i].pib_per_capita);
        printf("Super Poder: %.2f\n", cidades[i].super_poder);
    }
}

// Função para comparar duas cidades
void compararCartas(Cidade c1, Cidade c2) {
    printf("\nComparação de Cartas:\n");
    printf("----------------------------------\n");
    printf("População: %s\n", (c1.populacao > c2.populacao) ? "Carta 1 vence" : "Carta 2 vence");
    printf("Área: %s\n", (c1.area > c2.area) ? "Carta 1 vence" : "Carta 2 vence");
    printf("PIB: %s\n", (c1.pib > c2.pib) ? "Carta 1 vence" : "Carta 2 vence");
    printf("Pontos turísticos: %s\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? "Carta 1 vence" : "Carta 2 vence");
    printf("Densidade Populacional: %s\n", (c1.densidade_populacional < c2.densidade_populacional) ? "Carta 1 vence" : "Carta 2 vence");
    printf("PIB per capita: %s\n", (c1.pib_per_capita > c2.pib_per_capita) ? "Carta 1 vence" : "Carta 2 vence");
    printf("Super Poder: %s\n", (c1.super_poder > c2.super_poder) ? "Carta 1 vence" : "Carta 2 vence");
}

// Função principal
int main() {
    Cidade cidades[MAX_CIDADES]; // Array para armazenar as cidades
    int totalCidades = 0; // Contador de cidades cadastradas
    int opcao;
    
    do {
        // Menu principal
        printf("\n===Super Trunfo - Países===\n\n");
        printf("1. Cadastrar Cidade\n");
        printf("2. Listar Cidades\n");
        printf("3. Comparar Cartas\n");
        printf("4. Sair\n");
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
                if (totalCidades < 2) {
                    printf("\nÉ necessário pelo menos duas cidades cadastradas para comparar.\n");
                } else {
                    int idx1, idx2;
                    printf("Digite o índice da primeira cidade (0 a %d): ", totalCidades - 1);
                    scanf("%d", &idx1);
                    printf("Digite o índice da segunda cidade (0 a %d): ", totalCidades - 1);
                    scanf("%d", &idx2);
                    compararCartas(cidades[idx1], cidades[idx2]);
                }
                break;
            case 4:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 4);
    
    return 0;
}
