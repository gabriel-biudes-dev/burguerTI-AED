#ifndef MAIN_H
#define MAIN_H

//Mostra o menu principal
//Recebe: nada
//Retorna: a opção escolhida
int mostrarMenu();

//Remove uma linha do arquivo de texto
//Recebe: nome do arquivo e numero da linha (começando em 0)
//Retorna: nada
void remover_linha(char* arq, int n);

//Troca todas as ocorrências de x por y em uma string
//Recebe: a string e os caracteres x e y
//Retorna: a nova string
char* trocar(char *str, char x, char y);

//Registra um produto a partir de uma string
//Recebe: a string
//Retorna: nada
void registrarProduto(char *str);

//Carrega os dados de um arquivo de texto para o programa
//Recebe: nada
//Retorna: nada
void carregarArquivo();

#endif