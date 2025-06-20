/*
 * Documentação do Projeto: Jogo Educativo "Caça ao Foco do Aedes"
 *
 * Instituição: Instituto Federal de Educação, Ciência e Tecnologia de São Paulo (IFSP) - Campus Capivari
 * Curso: Especialização em Desenvolvimento de Sistemas Web e Aplicativos Móveis
 * Disciplina: Algoritmos e Programação
 * Professora: Adriana Belon
 * Aluno: Carlos Gracioli Neto
 * Data de Criação: 12.06.2025
 *
 * Descrição:
 * Este programa implementa um jogo educativo interativo com o objetivo de conscientizar
 * os usuários sobre a prevenção de arboviroses (Dengue, Chikungunya e Zika) através
 * da identificação e eliminação de focos do mosquito Aedes aegypti. O jogo simula a
 * inspeção de diferentes áreas e utiliza lógica aleatória para determinar a presença
 * e o tipo de foco. O jogador ganha pontos ao realizar as ações preventivas corretas.
 *
 * Restrições de Desenvolvimento:
 * - Uso exclusivo de estruturas de repetição (for e/ou while), estruturas sequenciais
 * e condicionais (if, else if, else).
 * - Uso obrigatório do comando rand().
 * - Proibida a utilização de vetores, matrizes, funções e procedimentos definidos pelo usuário.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int pontuacao = 0;
    int chances = 5;
    int escolhaArea, chanceFoco, tipoFoco, acao;

    srand(time(NULL)); // Inicializa a semente do random

    printf("=======================================\n");
    printf(" Bem-vindo ao jogo 'Caça ao Foco do Aedes'!\n");
    printf(" Você terá %d chances para inspecionar áreas e eliminar focos.\n", chances);
    printf("=======================================\n");

    while (chances > 0) {
        printf("\nChances restantes: %d | Pontuação atual: %d\n", chances, pontuacao);
        printf("Escolha uma área para inspecionar:\n");
        printf("1. Piscina\n2. Vaso de Planta\n3. Pneus Velhos\n4. Calhas\n5. Lixo Acumulado\n");
        printf("Digite sua escolha (1 a 5): ");
        scanf("%d", &escolhaArea);

        chances--;

        chanceFoco = rand() % 100 + 1; // Número entre 1 e 100

        if (chanceFoco <= 60) {
            // 60% de chance de ser foco
            tipoFoco = rand() % 3 + 1;

            printf("\nALERTA! Você encontrou um foco do mosquito!\n");

            if (tipoFoco == 1) {
                // Água parada
                printf("Foco de água parada identificado!\n");

                if (escolhaArea == 1)
                    printf("Piscina sem tratamento!\n");
                else if (escolhaArea == 3)
                    printf("Pneu com água acumulada!\n");
                else
                    printf("Outro recipiente com água parada!\n");

                printf("Escolha a ação:\n");
                printf("1. Escoar a água e limpar.\n2. Cobrir o recipiente.\n3. Deixar como está.\n");
                scanf("%d", &acao);

                if (acao == 1 || acao == 2) {
                    printf("Parabéns! Você eliminou o foco!\n");
                    pontuacao += 10;
                } else {
                    printf("Essa ação não foi eficaz. O foco permanece!\n");
                }

            } else if (tipoFoco == 2) {
                // Lixo acumulado
                printf("Foco encontrado: lixo acumulado!\n");
                printf("Escolha a ação:\n");
                printf("1. Descartar corretamente o lixo.\n2. Queimar o lixo.\n");
                scanf("%d", &acao);

                if (acao == 1) {
                    printf("Excelente! Foco eliminado.\n");
                    pontuacao += 10;
                } else {
                    printf("Cuidado! Queimar lixo é perigoso e ineficaz.\n");
                }

            } else {
                // Plantas com água
                printf("Foco encontrado: vaso de planta com água parada!\n");
                printf("Escolha a ação:\n");
                printf("1. Eliminar a água e colocar areia.\n2. Regar as plantas.\n");
                scanf("%d", &acao);

                if (acao == 1) {
                    printf("Ótimo! Foco eliminado.\n");
                    pontuacao += 10;
                } else {
                    printf("Cuidado! Água parada atrai mosquitos.\n");
                }
            }

        } else {
            printf("Boa notícia! A área inspecionada está limpa.\n");
        }
    }

    printf("\n=======================================\n");
    printf("Fim do jogo! Sua pontuação final foi: %d pontos.\n", pontuacao);

    if (pontuacao >= 30) {
        printf("Parabéns! Você é um verdadeiro caçador de focos do Aedes!\n");
    } else {
        printf("Continue praticando! A prevenção é essencial.\n");
    }

    return 0;
}
