#ifndef EstruturaDeDados_Hash_h
#define EstruturaDeDados_Hash_h
#include "DoublyLinkedList.h"
#define MAX 3025

typedef struct HashStruct {
    DoublyLinkedList hashes[MAX];
    int size;
}HashStruct;

void initHash(HashStruct *hashStruct);
bool isHashEmpty(HashStruct *hashStruct);
int hash(char *key);
void gravarq(HashStruct *hashStruct,int num);
int maiorcolisao(HashStruct *hashStruct);
int put(HashStruct *hashStruct, char *key, void *data, compare equal);
bool containsKey(HashStruct *hashStruct, char *key, compare equal);
void* get(HashStruct *hashStruct, char *key, compare equal);
void* removeKey(HashStruct *hashStruct, char *key, compare equal);
void showHashStruct(HashStruct *hashStruct, printNode print);

#endif