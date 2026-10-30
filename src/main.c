#include <stdio.h>
#include <math.h>

int main(void) {
    int tipo_projeto;
    float tamanho_projeto, esforco_projeto, tempo_dev, pessoas_projeto, coef_esforco, exp_esforco, coef_tempo, exp_tempo, custo_projeto, salario_projeto;

    do {
        printf("Defina o tipo de projeto: (1 - Organico, 2 - Geminado, 3 - Integrado)\n");
        scanf("%d", &tipo_projeto);
    }
    while (tipo_projeto <= 0 || tipo_projeto >= 4);

    do {
        printf("Defina o tamanho do projeto em KLOCs: \n");
        scanf("%f", &tamanho_projeto);
    }
    while (tamanho_projeto <= 0);

    do {
        printf("Defina a media salarial dos funcionarios do projeto em reais: \n");
        scanf("%f", &salario_projeto);
    }
    while (salario_projeto <= 0);

    switch (tipo_projeto) {
        case 1:
            printf("O modelo e Organico\n");
            coef_esforco = 2.4f;
            exp_esforco = 1.05f;
            coef_tempo = 2.5f;
            exp_tempo = 0.38f;
            break;
        case 2:
            printf("O modelo e Geminado\n");
            coef_esforco = 3.0f;
            exp_esforco = 1.12f;
            coef_tempo = 2.5f;
            exp_tempo = 0.35f;
            break;
        case 3:
            printf("O modelo e Integrado\n");
            coef_esforco = 3.6f;
            exp_esforco = 1.2f;
            coef_tempo = 2.5f;
            exp_tempo = 0.32f;
            break;
        default:
            printf("Modelo invalido\n");
            return 1;
            break;
    }

    esforco_projeto = coef_esforco * (pow(tamanho_projeto, exp_esforco));
    tempo_dev = coef_tempo * (pow(esforco_projeto, exp_tempo));
    pessoas_projeto = esforco_projeto / tempo_dev;
    custo_projeto = esforco_projeto * salario_projeto;

    printf("Esforco = %.2f Pessoa-Mes\n", esforco_projeto);
    printf("Tempo de desenvolvimento = %.2f meses\n", tempo_dev);
    printf("Para desenvolver esse projeto, serao necessarios em media %.0f funcionarios \n", ceil(pessoas_projeto));
    printf("O custo total do projeto sera de R$ %.2f \n", custo_projeto);

    return 0;
}