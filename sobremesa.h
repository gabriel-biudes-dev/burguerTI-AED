#ifndef SOBREMESA_H
#define SOBREMESA_H

typedef struct{
    int codigo;
    int disponivel;
    char nome[51];
    float preco;
}Sobremesa;

typedef struct noS{
    struct noS* prox;
    Sobremesa s;
}ListaS;

//Insere em uma lista
//Recebe: a lista e a sobremesa
//Retorna: a lista com a sobremesa inserida
ListaS* insertS(ListaS* slist, Sobremesa s);

//Salva no arquivo binario
//Recebe: uma lista de sobremesas
//Retorna: nada
void salvarSobremesas(ListaS *l);

//Lê dados de um arquivo binario
//Recebe: nada
//Retorna: lista de sobremesas
ListaS* lerSobremesas();

//Registra um dado no arquivo binario
//Recebe: nada
//Retorna: nada
void cadastrarSobremesa();

//Mostra os dados de uma lista
//Recebe: lista de sobremesas, opt1 define se a lista é recebida via parametro ou deve-se ler a lista no arquivo binario, opt2 define se está mostrando um item por si ou um item de um pedido
//Retorna: nada
void mostrarlistaS(int opt, ListaS *ls);

//Mostra os itens cadastrados
//Recebe: nada
//Retorna: sobremesa escolhida
Sobremesa* escolherSobremesa();

//Calcula o tamanho da lista
//Recebe: lista de sobremesas
//Retorna: tamanho da lista
int calcTamanhoS(ListaS *l);

//Cria uma lista vazia
//Recebe: nada
//Retorna: lista vazia de sobremesas
ListaS* emptyS();

#endif