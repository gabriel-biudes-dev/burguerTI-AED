#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hamburguer.h"
#include "bebida.h"
#include "acompanhamento.h"
#include "sobremesa.h"
#include "pedido.h"

int mostrarMenu(){
  int opt;
  printf("[MENU DO SISTEMA]\n");
  printf("\t1)Cadastrar sanduiche\n");
  printf("\t2)Cadastrar bebida\n");
  printf("\t3)Cadastrar sobremesa\n");
  printf("\t4)Cadastrar acompanhamentos\n");
  printf("\t5)Imprimir lista de sanduiches\n");
  printf("\t6)Imprimir lista de bebidas\n");
  printf("\t7)Imprimir lista de sobremesas\n");
  printf("\t8)Imprimir lista de extras\n");
  printf("\t9)Registrar novo pedido\n");
  printf("\t10)Imprimir pedido\n");
  printf("\t11)Imprimir lista de pedidos atendidos\n");
  printf("\t12)Sair\n");
  printf("Opcao: ");
  scanf("%d%*c", &opt);
  return opt;
}

ListaH* insertH(ListaH* hlist, Hamburguer h){//insert hamburger
    ListaH* aux = (ListaH*) malloc(sizeof(ListaH));
    aux->h = h;
    aux->prox = hlist;
    return aux;
}

ListaA* insertA(ListaA* alist, Acompanhamento a){//insert acompanhamento
    ListaA* aux = (ListaA*) malloc(sizeof(ListaA));
    aux->a = a;
    aux->prox = alist;
    return aux;
}

ListaB* insertB(ListaB* blist, Bebida b){//insert bebida
    ListaB* aux = (ListaB*) malloc(sizeof(ListaB));
    aux->b = b;
    aux->prox = blist;
    return aux;
}

ListaS* insertS(ListaS* slist, Sobremesa s){//insert sobremesa
    ListaS* aux = (ListaS*) malloc(sizeof(ListaS));
    aux->s = s;
    aux->prox = slist;
    return aux;
}

void salvarHamburguers(ListaH *l){
    Hamburguer *h = (Hamburguer*) malloc(sizeof(Hamburguer));
    FILE *fp = fopen("hamburguer.bin", "wb");
    while(l != NULL){
        *h = l->h;
        fwrite(&h->nome, sizeof(h->nome), 1, fp);
        fwrite(&h->desc, sizeof(h->desc), 1, fp);
        fwrite(&h->codigo, sizeof(int), 1, fp);
        fwrite(&h->disponivel, sizeof(int), 1, fp);
        fwrite(&h->precoG, sizeof(float), 1, fp);
        fwrite(&h->precoM, sizeof(float), 1, fp);
        fwrite(&h->precoP, sizeof(float), 1, fp);
        l = l->prox;
    }
    fclose(fp);
    free(h);
}

void salvarBebidas(ListaB *l){
    Bebida *b = (Bebida*) malloc(sizeof(Bebida));
    FILE *fp = fopen("bebida.bin", "wb");
    while(l != NULL){
        *b = l->b;
        fwrite(&b->nome, sizeof(b->nome), 1, fp);
        fwrite(&b->codigo, sizeof(int), 1, fp);
        fwrite(&b->disponivel, sizeof(int), 1, fp);
        fwrite(&b->precoG, sizeof(float), 1, fp);
        fwrite(&b->precoM, sizeof(float), 1, fp);
        fwrite(&b->precoP, sizeof(float), 1, fp);
        l = l->prox;
    }
    fclose(fp);
    free(b);
}

void salvarAcompanhamentos(ListaA *l){
    Acompanhamento *a = (Acompanhamento*) malloc(sizeof(Acompanhamento));
    FILE *fp = fopen("acompanhamento.bin", "wb");
    while(l != NULL){
        *a = l->a;
        fwrite(&a->nome, sizeof(a->nome), 1, fp);
        fwrite(&a->codigo, sizeof(int), 1, fp);
        fwrite(&a->disponivel, sizeof(int), 1, fp);
        fwrite(&a->preco, sizeof(float), 1, fp);
        l = l->prox;
    }
    fclose(fp);
    free(a);
}

void salvarSobremesas(ListaS *l){
    Sobremesa *s = (Sobremesa*) malloc(sizeof(Sobremesa));
    FILE *fp = fopen("sobremesa.bin", "wb");
    while(l != NULL){
        *s = l->s;
        fwrite(&s->nome, sizeof(s->nome), 1, fp);
        fwrite(&s->codigo, sizeof(int), 1, fp);
        fwrite(&s->disponivel, sizeof(int), 1, fp);
        fwrite(&s->preco, sizeof(float), 1, fp);
        l = l->prox;
    }
    fclose(fp);
    free(s);
}

ListaH* lerHamburguers(){
    ListaH *l = NULL;
    Hamburguer *h = (Hamburguer*) malloc(sizeof(Hamburguer));
    FILE *fp = fopen("hamburguer.bin", "rb");
    while(1){
        fread(h->nome, sizeof(h->nome), 1, fp);
        if(feof(fp)) break;
        fread(h->desc, sizeof(h->desc), 1, fp);
        fread(&h->codigo, sizeof(int), 1, fp);
        fread(&h->disponivel, sizeof(int), 1, fp);
        fread(&h->precoG, sizeof(float), 1, fp);
        fread(&h->precoM, sizeof(float), 1, fp);
        fread(&h->precoP, sizeof(float), 1, fp);
        l = insertH(l, *h);
    }
    fclose(fp);
    return l;
}

ListaB* lerBebidas(){
    ListaB *l = NULL;
    Bebida *b = (Bebida*) malloc(sizeof(Bebida));
    FILE *fp = fopen("bebida.bin", "rb");
    while(1){
        fread(b->nome, sizeof(b->nome), 1, fp);
        if(feof(fp)) break;
        fread(&b->codigo, sizeof(int), 1, fp);
        fread(&b->disponivel, sizeof(int), 1, fp);
        fread(&b->precoG, sizeof(float), 1, fp);
        fread(&b->precoM, sizeof(float), 1, fp);
        fread(&b->precoP, sizeof(float), 1, fp);
        l = insertB(l, *b);
    }
    fclose(fp);
    return l;
}

ListaA* lerAcompanhamentos(){
    ListaA *l = NULL;
    Acompanhamento *a = (Acompanhamento*) malloc(sizeof(Acompanhamento));
    FILE *fp = fopen("acompanhamento.bin", "rb");
    while(1){
        fread(a->nome, sizeof(a->nome), 1, fp);
        if(feof(fp)) break;
        fread(&a->codigo, sizeof(int), 1, fp);
        fread(&a->disponivel, sizeof(int), 1, fp);
        fread(&a->preco, sizeof(float), 1, fp);
        l = insertA(l, *a);
    }
    fclose(fp);
    return l;
}

ListaA* lerSobremesas(){
    ListaS *l = NULL;
    Sobremesa *s = (Sobremesa*) malloc(sizeof(Sobremesa));
    FILE *fp = fopen("sobremesa.bin", "rb");
    while(1){
        fread(s->nome, sizeof(s->nome), 1, fp);
        if(feof(fp)) break;
        fread(&s->codigo, sizeof(int), 1, fp);
        fread(&s->disponivel, sizeof(int), 1, fp);
        fread(&s->preco, sizeof(float), 1, fp);
        l = insertS(l, *s);
    }
    fclose(fp);
    return l;
}

void cadastrarHamburguer(){
    ListaH *lh = lerHamburguers();
    Hamburguer *h = (Hamburguer*) malloc(sizeof(Hamburguer));
    printf("\nInforme o codigo do sanduiche: ");
    scanf("%d%*c", &h->codigo);
    printf("\nInforme o nome do sanduiche: ");
    scanf("%[^\n]%*c", h->nome);
    printf("\nInforme se o sanduiche esta disponivel (0 ou 1): ");
    scanf("%d%*c", &h->disponivel);
    printf("\nInforme a descricao do sanduiche: ");
    scanf("%[^\n]%*c", h->desc);
    printf("\nInforme o preco para tamanho grande: ");
    scanf("%f", &h->precoG);
    printf("\nInforme o preco para tamanho medio: ");
    scanf("%f", &h->precoM);
    printf("\nInforme o preco para tamanho pequeno: ");
    scanf("%f", &h->precoP);
    lh = insertH(lh, *h);
    salvarHamburguers(lh);
}

void cadastrarBebida(){
    ListaB *lb = lerBebidas();
    Bebida *b = (Bebida*) malloc(sizeof(Bebida));
    printf("\nInforme o codigo da Bebida: ");
    scanf("%d%*c", &b->codigo);
    printf("\nInforme o nome da Bebida: ");
    scanf("%[^\n]%*c", b->nome);
    printf("\nInforme se a Bebida esta disponivel(0 ou 1): ");
    scanf("%d%*c", &b->disponivel);
    printf("\nInforme o preco para o tamanho grande: ");
    scanf("%f", &b->precoG);
    printf("\nInforme o preco para o tamanho medio: ");
    scanf("%f", &b->precoM);
    printf("\nInforme o preco para o tamanho pequeno: ");
    scanf("%f", &b->precoP);
    lb = insertB(lb, *b);
    salvarBebidas(lb);
}

void cadastrarAcompanhamento(){
    ListaA *la = lerAcompanhamentos();
    Acompanhamento *a = (Acompanhamento*)malloc(sizeof(Acompanhamento));
    printf("\nInforme o codigo do acompanhamento:");
    scanf("%d%*c", &a->codigo);
    printf("\nInforme o nome do acompanhamento:");
    scanf("%[^\n]%*c", a->nome);
    printf("\nInforme se o acompanhamento esta disponivel(0 ou 1):");
    scanf("%d%*c", &a->disponivel);
    printf("\nInforme o preco do acompanhamento):");
    scanf("%f%*c", &a->preco);
    la = insertA(la, *a);
    salvarAcompanhamentos(la);
}

void cadastrarSobremesa(){
    ListaS *ls = lerSobremesas();
    Sobremesa *s = (Sobremesa*)malloc(sizeof(Sobremesa));
    printf("\nInforme o codigo da sobremesa:");
    scanf("%d%*c", &s->codigo);
    printf("\nInforme o nome da sobremesa:");
    scanf("%[^\n]%*c", s->nome);
    printf("\nInforme se a sobremesa esta disponivel(0 ou 1):");
    scanf("%d%*c", &s->disponivel);
    printf("\nInforme o preco da sobremesa):");
    scanf("%f%*c", &s->preco);
    ls = insertS(ls, *s);
    salvarSobremesas(ls);
}

void mostrarlistaH(){ 
    ListaH *l = lerHamburguers();
    if(l == NULL) printf("A lista esta vazia\n");
    while(l != NULL){
        printf("Codigo: %d\n", l->h.codigo);
        printf("Nome: %s\n", l->h.nome);
        printf("Descricao: %s\n", l->h.desc);
        if(l->h.disponivel) printf("Disponivel: sim\n");
        else printf("Disponivel: nao\n");
        printf("Preco G: %.2f\n", l->h.precoG);
        printf("Preco M: %.2f\n", l->h.precoM);
        printf("Preco P: %.2f\n\n", l->h.precoP);
        l = l->prox;
    }
}

void mostrarlistaB(){ 
    ListaB *l = lerBebidas();
    if(l == NULL) printf("A lista esta vazia\n");
    while(l != NULL){
        printf("Codigo: %d\n", l->b.codigo);
        printf("Nome: %s\n", l->b.nome);
        if(l->b.disponivel) printf("Disponivel: sim\n");
        else printf("Disponivel: nao\n");
        printf("Preco G: %.2f\n", l->b.precoG);
        printf("Preco M: %.2f\n", l->b.precoM);
        printf("Preco P: %.2f\n\n", l->b.precoP);
        l = l->prox;
    }
}

void mostrarlistaA(){ 
    ListaA *l = lerAcompanhamentos();
    if(l == NULL) printf("A lista esta vazia\n");
    while(l != NULL){
        printf("Codigo: %d\n", l->a.codigo);
        printf("Nome: %s\n", l->a.nome);
        if(l->a.disponivel) printf("Disponivel: sim\n");
        else printf("Disponivel: nao\n");
        printf("Preco: %.2f\n\n", l->a.preco);
        l = l->prox;
    }
}

void mostrarlistaS(){ 
    ListaS *l = lerSobremesas();
    if(l == NULL) printf("A lista esta vazia\n");
    while(l != NULL){
        printf("Codigo: %d\n", l->s.codigo);
        printf("Nome: %s\n", l->s.nome);
        if(l->s.disponivel) printf("Disponivel: sim\n");
        else printf("Disponivel: nao\n");
        printf("Preco: %.2f\n\n", l->s.preco);
        l = l->prox;
    }
}

int main() {
    int opt = 0;
    while(opt != 12){
        opt = mostrarMenu();
        if(opt == 1) cadastrarHamburguer();
        if(opt == 2) cadastrarBebida();
        if(opt == 3) cadastrarSobremesa();
        if(opt == 4) cadastrarAcompanhamento();
        if(opt == 5) mostrarlistaH();
        if(opt == 6) mostrarlistaB();
        if(opt == 7) mostrarlistaS();
        if(opt == 8) mostrarlistaA();
    }
    return 0 ;
}