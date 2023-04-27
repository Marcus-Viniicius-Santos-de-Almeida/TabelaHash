#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "log.h"
#define TAM 100

typedef struct Palavra {
    char palavra[TAM];
}Palavra;

bool comparaPalavras(void *key, void *data) {
    char *chave = (char*)key;
    Palavra *p = (Palavra*)data;
    return (strcmp (chave, p->palavra) == 0)?true:false;
}

void printPalavra(void *data) {
    Palavra *palavrav = (Palavra*)data;
    printf("{%s} - ", palavrav->palavra);
}

/*
int Colisoes (HashStruct * hashStruct, char *key)
{
  int hashValue = hash (key);
  int c = 0;
  for(int i=0; i<MAX; i++){
      if (hash(hashStruct->hashes[i].first->data)==hashValue){
          c++;
      }
  }
  return c;
}*/

int main() {
    FILE *file = fopen("program.log","w");
	log_set_level(LOG_INFO);
	log_add_fp(file, LOG_TRACE);
    FILE *ListaPalavras;
    FILE *Espalhamento;
    int n=0;
    char linha[TAM], VetorPalavras[40000][TAM];
    ListaPalavras = fopen("ListaDePalavrasPT.txt", "r");
    Espalhamento = fopen("Espalhamento.ppm", "w");

    HashStruct hashes;
    initHash(&hashes);

    while(fgets(linha, TAM, ListaPalavras)){
       sscanf(linha, "%s", VetorPalavras[n]);
       log_debug("VetorPalavras na posição %d: %s", n, VetorPalavras[n]);
       n++;
    }
    Palavra *p = (Palavra *)malloc(sizeof(Palavra));
    for(int i=0; i<n; i++){

    strcpy(p->palavra,VetorPalavras[i]);
    
        printf("%s\n",p->palavra);    
    put(&hashes, p->palavra, p, comparaPalavras);
    p = (Palavra *)malloc(sizeof(Palavra));
    
    }
    
    showHashStruct(&hashes, printPalavra);
    printf("%d ",maiorcolisao(&hashes));

    int inter=256/maiorcolisoo(&hashes);

    

/*    /*for(int k=0; k<MAX; k++){
        printf("palavra %d: %s\n", k, VetorPalavras[k]);
    }
    free(p);*/

    fclose(ListaPalavras);
    fclose(Espalhamento);

    /*HashStruct hashes;
    initHash(&hashes);
    printf("%d\n",hash("joao.preti@cba.ifmt.edu.br"));
    Cliente *c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Joao Paulo") ;
    strcpy(c->email,"joao.preti@cba.ifmt.edu.br");
    printf("%d\n",hash(c->email));
    put(&hashes, c->email, c, comparaChaves);
    printf("%d\n",hashes.hashes[hash("joao.preti@cba.ifmt.edu.br")].size);
    printf("%d\n",hashes.size);
    printf("%d\n",containsKey(&hashes, "joao.preti@cba.ifmt.edu.br", comparaChaves));
    Cliente *cliente = (Cliente*)get(&hashes, "joao.preti@cba.ifmt.edu.br", comparaChaves);
    printf("%s\n",cliente->nome);
    c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Maria") ;
    strcpy(c->email,"maria@email.br");
  , comparaChaves);
    c = (Cliente   put(&hashes, c->email, c*)malloc(sizeof(Cliente));
    strcpy(c->nome,"Pedro") ;
    strcpy(c->email,"pedro@email.com.br");
    put(&hashes, c->email, c, comparaChaves);
    c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Carla") ;
    strcpy(c->email,"carla@gmail.com.br");
    put(&hashes, c->email, c, comparaChaves);
    showHashStruct(&hashes, printCliente);*/
    return 0;
}