#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct{
    ListaH *h;
    ListaB *b;
    ListaA *a;
    ListaS *s;
}Itens;

typedef struct{
    int codigo;
    char cpf[12];
    Itens itens;
}Pedido;

typedef struct noP{
    Pedido p;
    struct noP* prox;
}ListaP;

//Mostra o menu do registro de pedido
//Recebe: nada
//Retorna: opção escolhida
int mostrarMenuPedido();

//Lê os itens de um pedido
//Recebe: nada
//Retorna: os itens do pedido
Itens lerItens();

//Insere um dado na lista
//Recebe: lista de pedidos e um pedido
//Retorna: a nova lista com o pedido inserido
ListaP* insertP(ListaP *l, Pedido *p);

//Calcula o tamanho da lista
//Recebe: lista de pedidos
//Retorna: tamanho da lista
int calcTamanhoP(ListaP *l);

//Salva a quantidade de itens do pedido no arquivo auxiliar
//Recebe: o pedido e o nome do arquivo
//Retorna: nada
void salvar_aux(Pedido *p, char* arq);

//Salva uma lista de pedidos no arquivo binario
//Recebe: o nome do arquivo e a lista de pedidos
//Retorna: nada
void salvarPedidos(char* arq, ListaP *l);

//Lê os pedidos em um arquivo binario
//Recebe: nome do arquivo binario e nome do arquivo auxiliar
//Retorna: lista de pedidos
ListaP* lerPedidos(char* arq, char* arq2);

//Registra um pedido no arquivo binario
//Recebe: nada
//Retorna: nada
void registrarPedido();

//Mostra dados de um pedido
//Recebe: o pedido
//Retorna: nada
void mostrarPedidoInfo(Pedido *p);

//Mostra um pedido a partir de seu código
//Recebe: nada
//Retorna: nada
void mostrarPedido();

//Mostra a lista armazenada em um arquivo binario
//Recebe: o nome do arquivo binario e do arquivo auxiliar
//Retorna: nada
void mostrarPedidos(char* arq, char* arq2);

//Atende um pedido
//Recebe: nada
//Retorna: nada
void atenderPedido();

//Remove um dado da lista a partir do CPF do cliente
//Recebe: uma lista de pedidos e o cpf do cliente
//Retorna: a nova lista sem o registro deletado
ListaP* remover_por_cpf(ListaP *l, char* cpf);

//Desiste de um pedido
//Recebe: nada
//Retorna: nada
void desistirPedido();

#endif