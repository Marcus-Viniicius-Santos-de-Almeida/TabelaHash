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

void gravarq(HashStruct *hashStruct, int num){
    FILE *Espalhamento;
    Espalhamento = fopen("Espalhamento.ppm", "wb");

    if(Espalhamento == NULL){ 
        printf("Problemas no arquivo");
        exit(0);
    }

    fprintf(Espalhamento,"P3 \n 55 55 \n 255\n");

    for(int i=0;i<MAX;i++){
        fprintf(Espalhamento," 0 %d 0",num*hashStruct->hashes[i].size);
    }
    fclose(Espalhamento);
}

int main() {
    FILE *file = fopen("program.log","w");
	log_set_level(LOG_INFO);
	log_add_fp(file, LOG_TRACE);
    FILE *ListaPalavras;
   
    int n=0;
    char linha[TAM], VetorPalavras[40000][TAM];
    ListaPalavras = fopen("ListaDePalavrasPT.txt", "r");
    

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
    int inter=256/maiorcolisao(&hashes);
    
    gravarq(&hashes,inter);
    fclose(ListaPalavras);

    return 0;
}