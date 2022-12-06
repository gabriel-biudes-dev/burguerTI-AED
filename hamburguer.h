#ifndef HAMBURGUER_H
#define HAMBURGUER_H

typedef struct{
    int codigo;
    int disponivel;
    char nome[51];
    char desc[201];
    float precoP;
    float precoM;
    float precoG;
    float preco_escolhido;
}Hamburguer;

typedef struct noH{
    struct noH* prox;
    Hamburguer h;
}ListaH;

//Insere em uma lista
//Recebe: a lista e o hamburguer
//Retorna: a lista com o hamburguer inserido
ListaH* insertH(ListaH* hlist, Hamburguer h);

//Salva no arquivo binario
//Recebe: uma lista de hamburguers
//Retorna: nada
void salvarHamburguers(ListaH *l);

//Lê dados de um arquivo binario
//Recebe: nada
//Retorna: lista de hamburguers
ListaH* lerHamburguers();

//Registra um dado no arquivo binario
//Recebe: nada
//Retorna: nada
void cadastrarHamburguer();

//Mostra os dados de uma lista
//Recebe: lista de hamburguers, opt1 define se a lista é recebida via parametro ou deve-se ler a lista no arquivo binario, opt2 define se está mostrando um item por si ou um item de um pedido
//Retorna: nada
void mostrarlistaH(int opt, ListaH *lh, int opt2);

//Mostra os itens cadastrados
//Recebe: nada
//Retorna: hamburguer escolhido
Hamburguer* escolherHamburguer();

//Calcula o tamanho da lista
//Recebe: lista de hamburguers
//Retorna: tamanho da lista
int calcTamanhoH(ListaH *l);

//Cria uma lista vazia
//Recebe: nada
//Retorna: lista vazia de hamburguers
ListaH* emptyH();

#endif