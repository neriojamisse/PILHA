#include <stdio.h>
#include <stdbool.h>
#define tamanhoPilha 100

void empilhar(char);
char desempilhar();
bool estaVazia();
char topoPilha();
bool corresponde(char, char);
void mostrarPilha();

char pilha[tamanhoPilha];
int topo = -1;

bool verificarBalanceamento(char expressao[]) {
    for (int i = 0; expressao[i] != '\0'; i++) {
        char caractereAtual = expressao[i];

        if (caractereAtual == '(' || caractereAtual == '{' || caractereAtual == '[') {
            empilhar(caractereAtual);
        }
        else if (caractereAtual == ')' || caractereAtual == '}' || caractereAtual == ']') {
            if (estaVazia() || !corresponde(topoPilha(), caractereAtual)) {
                return false;
            }
            desempilhar();
        }
    }
    return estaVazia();
}

void empilhar(char caractere) {
    if (topo == tamanhoPilha - 1) {
        printf("Erro: Pilha cheia.\n");
    } else {
        pilha[++topo] = caractere;
        printf("Empilhado: %c\n", caractere);
    }
}

char desempilhar() {
    if (estaVazia()) {
        printf("Erro: Pilha vazia.\n");
        return '\0';
    } else {
        printf("Desempilhado: %c\n", pilha[topo]);
        return pilha[topo--];
    }
}

bool estaVazia() {
    return topo == -1;
}

char topoPilha() {
    if (!estaVazia()) {
        return pilha[topo];
    }
    return '\0';
}

bool corresponde(char abertura, char fechamento) {
    if (abertura == '(' && fechamento == ')') return true;
    if (abertura == '{' && fechamento == '}') return true;
    if (abertura == '[' && fechamento == ']') return true;
    return false;
}

void mostrarPilha() {
    if (estaVazia()) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Estado atual da pilha: ");
        for (int i = 0; i <= topo; i++) {
            printf("%c ", pilha[i]);
        }
        printf("\n");
    }
}

int main() {
    int opcao;
    char elemento;
    char expressao[tamanhoPilha];

    do {
        printf("\n===== MENU =====\n");
        printf("1. Empilhar elemento\n");
        printf("2. Desempilhar elemento\n");
        printf("3. Verificar balanceamento de expressao\n");
        printf("4. Mostrar pilha\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o caractere a ser empilhado: ");
                scanf(" %c", &elemento);
                empilhar(elemento);
                break;
            case 2:
                desempilhar();
                break;
            case 3:
                printf("Digite a expressao para verificar balanceamento: ");
                scanf("%s", expressao);
                if (verificarBalanceamento(expressao)) {
                    printf("Expressao valida!\n");
                } else {
                    printf("Expressao invalida!\n");
                }
                break;
            case 4:
                mostrarPilha();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
