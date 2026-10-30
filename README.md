# COCOMO I CLI Estimator

Motor de terminal desenvolvido em Linguagem C (padrão C99) para cálculo paramétrico de esforço, prazo de desenvolvimento, dimensionamento de equipes e custo financeiro de projetos de software, baseado no modelo clássico **COCOMO (Constructive Cost Model)**.

---

## 📌 Contexto e Fundamentos de Engenharia

O modelo COCOMO Básico estima o esforço e o tempo nominal de desenvolvimento a partir da métrica de dimensão em **KLOC** (milhares de linhas de código-fonte entregues). As equações variam de acordo com o nível de complexidade e o modo do projeto:

| Modo de Projeto | Multiplicador de Esforço ($a$) | Expoente de Esforço ($b$) | Multiplicador de Tempo ($c$) | Expoente de Tempo ($d$) |
| :--- | :---: | :---: | :---: | :---: |
| **1. Orgânico** | 2.4 | 1.05 | 2.5 | 0.38 |
| **2. Geminado (Semiacoplado)** | 3.0 | 1.12 | 2.5 | 0.35 |
| **3. Integrado (Embutido)** | 3.6 | 1.20 | 2.5 | 0.32 |

### Equações Utilizadas:
* **Esforço ($E$):** $E = a \times (\text{KLOC})^b$ `[pessoas-mês]`
* **Tempo de Desenvolvimento ($Tdev$):** $Tdev = c \times (E)^d$ `[meses]`
* **Pessoal Médio Necessário:** $P = \frac{E}{Tdev}$ `[arredondado para cima com ceil()]`
* **Custo Total:** $C = E \times \text{Salário Médio}$ `[R$]`

---

## 🛡️ Práticas de Engenharia Aplicadas

* **Programação Defensiva:** Laços de validação impedem avanço com valores inconsistentes (tamanho menor ou igual a zero, identificadores de modo fora da faixa permitida e salários negativos).
* **Tratamento de Ponto Flutuante:** Controle de precisão decimal com especificadores de formato e funções matemáticas da biblioteca `<math.h>`.
* **Separação de Responsabilidades:** Leitura e cálculos centralizados fora da estrutura de seleção `switch-case`, respeitando o princípio *Don't Repeat Yourself (DRY)*.

---

## 🚀 Como Compilar e Executar

### Pré-requisitos
* Compilador C (GCC, Clang ou MinGW) com suporte ao padrão C99.
* CMake (versão 3.20 ou superior).

### Opção 1: Via CMake (Recomendado)
```bash
# Gerar arquivos de build
cmake -B build

# Compilar o executável
cmake --build build

# Executar o programa
./build/cocomo_cli_estimator       # Linux/macOS
.\build\Debug\cocomo_cli_estimator # Windows
```

### Opção 2: Linha de comando direta com GCC
```bash
gcc -Wall -Wextra -std=c99 src/main.c -o cocomo_estimator -lm
./cocomo_estimator
```

---

## 🧪 Exemplo de Execução

```text
Defina o tipo de projeto: (1 - Organico, 2 - Geminado, 3 - Integrado)
3
Defina o tamanho do projeto em KLOCs:
25
Defina a media salarial dos funcionarios do projeto em reais:
6500
O modelo e Integrado
Esforco = 171.33 Pessoa-Mes
Tempo de desenvolvimento = 12.96 meses
Para desenvolver esse projeto, serao necessarios em media 14 funcionarios 
O custo total do projeto sera de R\$ 1113637.62 
```
