#include <stdio.h>
#include <stdlib.h>

typedef struct reg_no {
    float valor;
    struct reg_no *ant;
    struct reg_no *prox;
} no;

typedef struct reg_lista {
    int tamanho;
    no *inicio;
    no *fim;
} list;

list criar_lista() {
    list novaLista;
    novaLista.inicio = NULL;
    novaLista.fim = NULL;
    novaLista.tamanho = 0;

    return novaLista;
}

no *criar_no(float valor) {
    no *novono = (no *)malloc(sizeof(no));
    novono->ant = NULL;
    novono->prox = NULL;
    novono->valor = valor;

    return novono;
}

list append(list lista, float valor) {
    no *novono = criar_no(valor);

    if(lista.inicio == NULL) {
        lista.inicio = novono;
        lista.fim = novono;
    } else {
        lista.fim->prox = novono;
        novono->ant = lista.fim;
        lista.fim = novono;
    }

    lista.tamanho++;
    return lista;
}

void imprime_nos_reverso(list lista) {
    no *noAtual = lista.fim;
    while(noAtual != NULL) {
        printf("%f ", noAtual->valor);
        noAtual = noAtual->ant;
    }
    printf("\n");
}

void imprime(list lista) {
    no *noAtual = lista.inicio;
    while(noAtual != NULL) {
        printf("%f ", noAtual->valor);
        noAtual = noAtual->prox;
    }
    printf("\n");
    printf("tamanho: %d\n", lista.tamanho);
}

list insere_no_inicio(list lista, float valor) {
    
    no *novono = criar_no(valor);
    
    if (lista.inicio == NULL) {
        lista.inicio = novono;
        lista.fim = novono;
    } else {
        lista.inicio->ant = novono;
        novono->prox = lista.inicio;
        lista.inicio = novono;
    }

    lista.tamanho++;
    return lista;
}

int busca_no(list lista, float valor_b) {
    no *noAtual = lista.inicio;
    while(noAtual != NULL) {
        if(noAtual->valor == valor_b) {
            return 1;
        }
        noAtual = noAtual->prox;
    }
    return 0;
}

void printa_busca_no(list lista, float valor_b) {
    int resultado = busca_no(lista, valor_b);

    if(resultado == 1) {
        printf("valor esta na lista\n");
    } else {
        printf("valor nao esta na lista\n");
    }
}

list remove_no_valor(list lista, float valor_b) {
    no *noAtual = lista.inicio;

    while(noAtual != NULL) {
        if(noAtual->valor == valor_b) {
            // Remover no início
            if(noAtual->ant == NULL) {
                lista.inicio = noAtual->prox;
                if(lista.inicio != NULL) {
                    lista.inicio->ant = NULL;
                }
            } else {
                noAtual->ant->prox = noAtual->prox;
            }

            // Remover no fim
            if(noAtual->prox == NULL) {
                lista.fim = noAtual->ant;
                if(lista.fim != NULL) {
                    lista.fim->prox = NULL;
                }
            } else {
                noAtual->prox->ant = noAtual->ant;
            }

            free(noAtual);
            lista.tamanho--;
            return lista;
        }
        noAtual = noAtual->prox;
    }
    return lista;
}
int verifica_valor_na_posicao(list lista, int posicao){
    int contador = 0;
    
    no *noAtual = lista.inicio;

    while(noAtual != NULL){
        if(contador != posicao){
        noAtual = noAtual ->prox;
        contador++;
    }else{
        printf("%f\n", noAtual->valor);
        return noAtual->valor;
    }

}
}

list insere_na_posicao(list lista, int posicao, float valor_p){
    int contador = 0;
    no *novono = criar_no(valor_p);

    no *noAtual = lista.inicio;

    while(noAtual != NULL){
        if(contador != posicao){
            noAtual = noAtual -> prox;
            contador++;
        }else{
            
            novono -> prox = noAtual;
            novono -> ant = noAtual ->ant;
            noAtual -> ant -> prox = novono;
            noAtual -> ant = novono;
            

            break;
        }
    }
    lista.tamanho++;
    return lista;
}



int main() {
    list minhaLista = criar_lista();
    minhaLista = append(minhaLista, 1.5);
    minhaLista = append(minhaLista, 2.8);
    minhaLista = append(minhaLista, 3.7);

    printf("Lista de elementos: \n");
    imprime(minhaLista);
    printf("lista no reverso: \n");
    imprime_nos_reverso(minhaLista);

    printf("Valor adicinado esta no inicio: \n");
    minhaLista = insere_no_inicio(minhaLista, 5.6);
    imprime(minhaLista);

    printa_busca_no(minhaLista, 5.6);

    printf("remove no na lista: \n");
    minhaLista = remove_no_valor(minhaLista, 2.8);
    imprime(minhaLista);
    
    printf("verificando valor na posicao pedida: \n");
    verifica_valor_na_posicao(minhaLista, 1);

    printf("inserido na lista: \n");
    minhaLista = insere_na_posicao(minhaLista, 1, 10);
    imprime(minhaLista);
    
    

    return 0;
}