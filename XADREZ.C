#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

// ==================================================================
// PROTÓTIPOS DAS FUNÇÕES RECURSIVAS (NÍVEL MESTRE)
// ==================================================================
// Declara as funções que serão usadas na 'main' antes de suas implementações.

void moverTorreRecursivo(int passos_restantes);
void moverRainhaRecursivo(int passos_restantes);
void moverBispoRecursivo(int passos_totais, int passo_atual);

// ==================================================================
// FUNÇÃO PRINCIPAL
// ==================================================================
int main() {
    // Imprime um título para a simulação
    printf("--- Simulação de Movimentos de Peças de Xadrez (Nível Mestre) ---\n\n");
    
    // 1. Movimento da Torre (implementação substituída por função recursiva)
    const int casas_torre = 5;
    printf("Movimento da Torre (%d casas para a direita):\n", casas_torre);
    // A lógica de loop 'for' foi substituída pela chamada da função recursiva.
    moverTorreRecursivo(casas_torre);
    printf("\n");
    
    // 2. Movimento do Bispo (implementação substituída por função recursiva com loops aninhados)
    const int casas_bispo = 5;
    printf("Movimento do Bispo (%d casas na diagonal para cima e direita):\n", casas_bispo);
    // A lógica 'do-while' foi substituída pela chamada da função recursiva.
    moverBispoRecursivo(casas_bispo, 1);
    printf("\n");
    
    // 3. Movimento da Rainha (implementação substituída por função recursiva)
    const int casas_rainha = 8;
    printf("Movimento da Rainha (%d casas para a esquerda):\n", casas_rainha);
    // A lógica 'while' foi substituída pela chamada da função recursiva.
    moverRainhaRecursivo(casas_rainha);
    printf("\n");

    // =======================================================
    // 4. Nível Mestre - Movimentação do Cavalo com Loops Complexos
    // =======================================================
    // A lógica anterior do Cavalo foi substituída para atender aos novos requisitos.
    
    const int casas_cavalo_vertical = 2;
    const int casas_cavalo_horizontal = 1;
    const int total_passos_cavalo = casas_cavalo_vertical + casas_cavalo_horizontal;
    
    printf("Movimento do Cavalo (%d para cima, %d para a direita):\n", casas_cavalo_vertical, casas_cavalo_horizontal);

    // Loop complexo com múltiplas variáveis ('passo', 'movimentos_verticais_feitos')
    // e controle de fluxo avançado com 'continue' e 'break'.
    for (int passo = 1, movimentos_verticais_feitos = 0; passo <= total_passos_cavalo; passo++) {
        
        // Condição para os 2 movimentos verticais
        if (movimentos_verticais_feitos < casas_cavalo_vertical) {
            printf("Cima\n");
            movimentos_verticais_feitos++;
            // 'continue' força o loop a pular para a próxima iteração.
            continue; 
        }

        // Esta parte só é alcançada após os movimentos verticais.
        // Realiza o movimento horizontal.
        if (movimentos_verticais_feitos == casas_cavalo_vertical) {
            printf("Direita\n");
            // 'break' encerra o loop permanentemente, pois o movimento completo foi feito.
            break;
        }
    }


    printf("\n--- Fim da Simulação ---\n");

    // Retorna 0 para indicar que o programa foi executado com sucesso
    return 0;
}

// ==================================================================
// IMPLEMENTAÇÃO DAS FUNÇÕES (NÍVEL MESTRE)
// ==================================================================
// O código abaixo define o que cada função recursiva faz.

/**
 * @brief Move a Torre recursivamente para a direita.
 * @param passos_restantes O número de casas que ainda faltam para mover.
 */
void moverTorreRecursivo(int passos_restantes) {
    // Caso Base (condição de parada): se não há mais passos, a função retorna.
    if (passos_restantes <= 0) {
        return;
    }
    
    // Passo Recursivo: imprime o movimento e chama a si mesma com um passo a menos.
    printf("Direita\n");
    moverTorreRecursivo(passos_restantes - 1);
}

/**
 * @brief Move a Rainha recursivamente para a esquerda.
 * @param passos_restantes O número de casas que ainda faltam para mover.
 */
void moverRainhaRecursivo(int passos_restantes) {
    // Caso Base: condição de parada da recursão.
    if (passos_restantes <= 0) {
        return;
    }

    // Passo Recursivo: imprime o movimento e chama a si mesma.
    printf("Esquerda\n");
    moverRainhaRecursivo(passos_restantes - 1);
}

/**
 * @brief Move o Bispo recursivamente na diagonal (cima, direita).
 * Esta função também demonstra o uso de loops aninhados conforme o desafio.
 * @param passos_totais O número total de passos do movimento.
 * @param passo_atual O número do passo atual (para impressão).
 */
void moverBispoRecursivo(int passos_totais, int passo_atual) {
    // Caso Base: para quando o passo atual excede o total de passos.
    if (passo_atual > passos_totais) {
        return;
    }

    // Passo Recursivo:
    // Para cumprir o requisito de loops aninhados, usamos um loop externo para
    // a parte vertical e um interno para a horizontal de um único passo diagonal.
    for (int v = 0; v < 1; v++) {       // Loop externo (vertical)
        for (int h = 0; h < 1; h++) {   // Loop interno (horizontal)
            printf("Passo %d: Cima, Direita\n", passo_atual);
        }
    }
    
    // Chama a si mesma para o próximo passo.
    moverBispoRecursivo(passos_totais, passo_atual + 1);
}
