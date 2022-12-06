#ifndef ACOMPANHAMENTO_H
#define ACOMPANHAMENTO_H

typedef struct{
    int codigo;
    int disponivel;
    char nome[51];
    float preco;
}Acompanhamento;

typedef struct noA{
    struct noA* prox;
    Acompanhamento a;
}ListaA;

//Insere em uma lista
//Recebe: a lista e o acompanhamento
//Retorna: a lista com o acompanhamento inserido
ListaA* insertA(ListaA* alist, Acompanhamento a);

//Salva no arquivo binario
//Recebe: uma lista de acompanhamentos
//Retorna: nada
void salvarAcompanhamentos(ListaA *l);

//Lê dados de um arquivo binario
//Recebe: nada
//Retorna: lista de acompanhamentos
ListaA* lerAcompanhamentos();

//Registra um dado no arquivo binario
//Recebe: nada
//Retorna: nada
void cadastrarAcompanhamento();

//Mostra os dados de uma lista
//Recebe: lista de acompanhamentos, opt1 define se a lista é recebida via parametro ou deve-se ler a lista no arquivo binario, opt2 define se está mostrando um item por si ou um item de um pedido
//Retorna: nada
void mostrarlistaA(int opt, ListaA *la);

//Mostra os itens cadastrados
//Recebe: nada
//Retorna: acompanhamento escolhido
Acompanhamento* escolherAcompanhamento();

//Calcula o tamanho da lista
//Recebe: lista de acompanhamentos
//Retorna: tamanho da lista
int calcTamanhoA(ListaA *l);

//Cria uma lista vazia
//Recebe: nada
//Retorna: lista vazia de acompanhamentos
ListaA* emptyA();

#endif