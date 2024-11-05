# Pilha

# Introdução

Este projeto contém um exercício em C, onde para alem de empilhar e desempilhar elementos, escolhi criar funcao que usa o algoritmo da pilha para verificar o balaceamento de parenteses duma expressao matematica. 

---

## Pesquisa Linear

```bash
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
```
<img src="images\Screenshot (26).png" alt="Console" width="300" height="300">

<img src="images\Screenshot (27).png" alt="Console" width="300" height="300">