#include <stdio.h>
#include <string.h>

#define MAX_STR 50

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[MAX_STR];
    char codigo[MAX_STR];
    char nomeCidade[MAX_STR];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePop;
    float pibPerCapita;
} Carta;

// Função para cadastrar carta
void cadastrarCarta(Carta *carta) {
    printf("\n=== Cadastro da Carta ===\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);
    printf("Código da carta: ");
    scanf(" %[^\n]", carta->codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos derivados
    carta->densidadePop = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir informações de uma carta
void exibirCarta(Carta carta) {
    printf("\n=== Carta: %s (%s) ===\n", carta.nomeCidade, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePop);
    printf("PIB per Capita: %.2f\n", carta.pibPerCapita);
}

// Função para comparar dois atributos e retornar 1 se a primeira carta vence, -1 se a segunda vence, 0 se empate
int compararAtributo(Carta c1, Carta c2, int atributo) {
    switch (atributo) {
        case 1: // População
            return (c1.populacao > c2.populacao) ? 1 : (c1.populacao < c2.populacao) ? -1 : 0;
        case 2: // Área
            return (c1.area > c2.area) ? 1 : (c1.area < c2.area) ? -1 : 0;
        case 3: // PIB
            return (c1.pib > c2.pib) ? 1 : (c1.pib < c2.pib) ? -1 : 0;
        case 4: // Pontos Turísticos
            return (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : (c1.pontosTuristicos < c2.pontosTuristicos) ? -1 : 0;
        case 5: // Densidade Populacional (menor vence)
            return (c1.densidadePop < c2.densidadePop) ? 1 : (c1.densidadePop > c2.densidadePop) ? -1 : 0;
        case 6: // PIB per Capita
            return (c1.pibPerCapita > c2.pibPerCapita) ? 1 : (c1.pibPerCapita < c2.pibPerCapita) ? -1 : 0;
        default:
            return 0;
    }
}

// Função para exibir o nome do atributo
void exibirNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Populacional"); break;
        case 6: printf("PIB per Capita"); break;
        default: printf("Desconhecido");
    }
}

int main() {
    Carta carta1, carta2;
    int atributo1, atributo2, resultado1, resultado2;
    float soma1 = 0, soma2 = 0;

    printf("=== SUPER TRUNFO - Nível Mestre ===\n");

    // Cadastro das cartas
    printf("\n--- Carta 1 ---\n");
    cadastrarCarta(&carta1);
    printf("\n--- Carta 2 ---\n");
    cadastrarCarta(&carta2);

    // Exibir cartas cadastradas
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Menu dinâmico: escolha do primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo para comparação:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
    scanf("%d", &atributo1);

    // Menu dinâmico: escolha do segundo atributo (excluindo o primeiro)
    printf("\nEscolha o SEGUNDO atributo para comparação (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != atributo1) {
            printf("%d. ", i);
            exibirNomeAtributo(i);
            printf("\n");
        }
    }
    scanf("%d", &atributo2);

    // Comparação do primeiro atributo
    resultado1 = compararAtributo(carta1, carta2, atributo1);
    if (atributo1 == 5) { // Densidade Pop
        soma1 += (resultado1 == 1) ? 1 : 0;
        soma2 += (resultado1 == -1) ? 1 : 0;
    } else {
        soma1 += (carta1.populacao + carta1.area + carta1.pib + carta1.pontosTuristicos + carta1.densidadePop + carta1.pibPerCapita, atributo1);
        soma2 += (carta2.populacao + carta2.area + carta2.pib + carta2.pontosTuristicos + carta2.densidadePop + carta2.pibPerCapita, atributo1);
    }

    // Comparação do segundo atributo
    resultado2 = compararAtributo(carta1, carta2, atributo2);

    // Somatório final (aqui soma real dos valores para desempate)
    float valor1A1 = (atributo1 == 1) ? carta1.populacao :
                     (atributo1 == 2) ? carta1.area :
                     (atributo1 == 3) ? carta1.pib :
                     (atributo1 == 4) ? carta1.pontosTuristicos :
                     (atributo1 == 5) ? carta1.densidadePop :
                                        carta1.pibPerCapita;

    float valor1A2 = (atributo2 == 1) ? carta1.populacao :
                     (atributo2 == 2) ? carta1.area :
                     (atributo2 == 3) ? carta1.pib :
                     (atributo2 == 4) ? carta1.pontosTuristicos :
                     (atributo2 == 5) ? carta1.densidadePop :
                                        carta1.pibPerCapita;

    float valor2A1 = (atributo1 == 1) ? carta2.populacao :
                     (atributo1 == 2) ? carta2.area :
                     (atributo1 == 3) ? carta2.pib :
                     (atributo1 == 4) ? carta2.pontosTuristicos :
                     (atributo1 == 5) ? carta2.densidadePop :
                                        carta2.pibPerCapita;

    float valor2A2 = (atributo2 == 1) ? carta2.populacao :
                     (atributo2 == 2) ? carta2.area :
                     (atributo2 == 3) ? carta2.pib :
                     (atributo2 == 4) ? carta2.pontosTuristicos :
                     (atributo2 == 5) ? carta2.densidadePop :
                                        carta2.pibPerCapita;

    float somaTotal1 = valor1A1 + valor1A2;
    float somaTotal2 = valor2A1 + valor2A2;

    // Exibir resultados detalhados
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Atributo 1: ");
    exibirNomeAtributo(atributo1);
    printf("\nCarta 1: %.2f | Carta 2: %.2f\n", valor1A1, valor2A1);

    printf("Atributo 2: ");
    exibirNomeAtributo(atributo2);
    printf("\nCarta 1: %.2f | Carta 2: %.2f\n", valor1A2, valor2A2);

    printf("\nSoma dos atributos:\nCarta 1: %.2f | Carta 2: %.2f\n", somaTotal1, somaTotal2);

    if (somaTotal1 > somaTotal2)
        printf("\nResultado Final: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    else if (somaTotal2 > somaTotal1)
        printf("\nResultado Final: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    else
        printf("\nResultado Final: Empate!\n");

    return 0;
}