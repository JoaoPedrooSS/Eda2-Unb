#include <stdio.h>

#include <stdlib.h>



typedef struct no {

    int x;

    struct no *prox;

} no;



typedef struct {

    no *tabela;

    int M;

} th;



th * criar_hash(int M) {

    th *hash = malloc(sizeof(th)); // alocamos a estrutura hash

    hash->tabela = calloc(M, sizeof(no)); // alocamos o vetor de cabeças da tabela com calloc(NULL)

    hash->M = M; // guardamos o tamanho da tabela

    return hash;

}



void destruir(th *hash){

    for(int i = 0; i < hash->M; i++){ // para cada cabeça da tabela

        no *elemento = hash->tabela[i].prox; // pegamos o primeiro elemento da lista encadeada

        while(elemento != NULL){ // enquanto não chegamos no fim da lista

            no *aux = elemento; // guardamos o elemento

            elemento = elemento->prox; // atualizamos o elemento

            free(aux); // liberamos o elemento

        }

    }

    free(hash->tabela); // liberamos o vetor de cabeças

    free(hash); // liberamos a estrutura hash

}



// X é a chave, M o tamanho da tabela

int função_hash(int x, int M){

    //return x % M; // função de hash simples/modular

    return ((1 * x + 4387) % 140009) % M; // hash universal

}



void inserir(th *hash, int x){

    int i = função_hash(x, hash->M); // calculamos o índice dessa chave na tabela

    no *novo = malloc(sizeof(no)); // alocamos um novo nó

    novo->x = x; // guardamos a chave

    novo->prox = hash->tabela[i].prox; // o novo é inserido abaixo da cabeça e acima dos demais

    hash->tabela[i].prox = novo; // a cabeça aponta para o novo nó

}





// X é a chave que procuramos

int busca(th *hash, int x){

    int i = função_hash(x, hash->M); // calculamos o índice dessa chave na tabela

    no *elemento = hash->tabela[i].prox; // pegamos a cabeça da lista encadeada

    while(elemento != NULL){ // enquanto não chegamos no fim da lista daquela posição

        if(elemento->x == x) return 1; // se encontramos a chave, retornamos 1

        elemento = elemento->prox; // se não, vamos para o próximo elemento

    }

    return 0; // se chegamos no fim da lista e não encontramos a chave, retornamos 0



}



int main() {

    int N;

    scanf("%d", &N);

    th *hash = criar_hash(N);

    for(int i = 0; i < N; i++){

        int x;

        scanf("%d", &x);

        inserir(hash, x);

    }

    int y;

    while(scanf("%d", &y) != EOF){

        if(busca(hash, y)) printf("sim\n");

        else printf("não\n");

    }

    destruir(hash);

    return 0;

}