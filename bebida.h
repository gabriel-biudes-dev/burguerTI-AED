#ifndef BEBIDA_H
#define BEBIDA_H

typedef struct{
    int codigo;
    int disponivel;
    char nome[51];
    float precoP;
    float precoM;
    float precoG;
    float preco_escolhido;
}Bebida;

typedef struct noB{
    struct noB* prox;
    Bebida b;
}ListaB;

//Insere em uma lista
//Recebe: a lista e a bebida
//Retorna: a lista com a bebida inserida
ListaB* insertB(ListaB* blist, Bebida b);

//Salva no arquivo binario
//Recebe: uma lista de bebidas
//Retorna: nada
void salvarBebidas(ListaB *l);

//Lê dados de um arquivo binario
//Recebe: nada
//Retorna: lista de bebidas
ListaB* lerBebidas();

//Registra um dado no arquivo binario
//Recebe: nada
//Retorna: nada
void cadastrarBebida();

//Mostra os dados de uma lista
//Recebe: lista de bebidas, opt1 define se a lista é recebida via parametro ou deve-se ler a lista no arquivo binario, opt2 define se está mostrando um item por si ou um item de um pedido
//Retorna: nada
void mostrarlistaB(int opt, ListaB *lb, int opt2);

//Mostra os itens cadastrados
//Recebe: nada
//Retorna: bebida escolhida
Bebida* escolherBebida();

//Calcula o tamanho da lista
//Recebe: lista de bebidas
//Retorna: tamanho da lista
int calcTamanhoB(ListaB *l);

//Cria uma lista vazia
//Recebe: nada
//Retorna: lista vazia de bebidas
ListaB* emptyB();

#endif