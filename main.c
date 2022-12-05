#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hamburguer.h"
#include "bebida.h"
#include "acompanhamento.h"
#include "sobremesa.h"
#include "pedido.h"

#define MAX 10000

int mostrarMenu(){
  int opt;
  printf("\n[MENU DO SISTEMA]\n");
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

ListaS* lerSobremesas(){
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
    printf("\nInforme o codigo do acompanhamento: ");
    scanf("%d%*c", &a->codigo);
    printf("\nInforme o nome do acompanhamento: ");
    scanf("%[^\n]%*c", a->nome);
    printf("\nInforme se o acompanhamento esta disponivel(0 ou 1): ");
    scanf("%d%*c", &a->disponivel);
    printf("\nInforme o preco do acompanhamento: ");
    scanf("%f%*c", &a->preco);
    la = insertA(la, *a);
    salvarAcompanhamentos(la);
}

void cadastrarSobremesa(){
    ListaS *ls = lerSobremesas();
    Sobremesa *s = (Sobremesa*)malloc(sizeof(Sobremesa));
    printf("\nInforme o codigo da sobremesa: ");
    scanf("%d%*c", &s->codigo);
    printf("\nInforme o nome da sobremesa: ");
    scanf("%[^\n]%*c", s->nome);
    printf("\nInforme se a sobremesa esta disponivel(0 ou 1): ");
    scanf("%d%*c", &s->disponivel);
    printf("\nInforme o preco da sobremesa: ");
    scanf("%f%*c", &s->preco);
    ls = insertS(ls, *s);
    salvarSobremesas(ls);
}

void mostrarlistaH(int opt, ListaH *lh){ 
    ListaH *l;
    if(opt == 1) l = lh;
    else l = lerHamburguers();
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

void mostrarlistaB(int opt, ListaB *lb){ 
    ListaB *l;
    if(opt == 1) l = lb;
    else l = lerBebidas();
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

void mostrarlistaA(int opt, ListaA *la){ 
    ListaA *l;
    if(opt == 1) l = la;
    else l = lerAcompanhamentos();
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

void mostrarlistaS(int opt, ListaS *ls){
    ListaS *l;
    if(opt == 1) l = ls;
    else l = lerSobremesas();
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

int mostrarMenuPedido(){
    int opt;
    printf("\n[MENU DO PEDIDO]\n");
    printf("\t1)Inserir hamburguer\n");
    printf("\t2)Inserir bebida\n");
    printf("\t3)Inserir acompanhamento\n");
    printf("\t4)Inserir sobremesa\n");
    printf("\t5)Finalizar pedido\n");
    printf("Escolha a opcao: ");
    scanf("%d%*c", &opt);
    return opt;
}

Hamburguer* escolherHamburguer(){
    Hamburguer *h = (Hamburguer*) malloc(sizeof(Hamburguer));
    ListaH *l = lerHamburguers();
    int codigo;
    h->codigo = -1;
    printf("\n[LISTA DE HAMBURGUERS DISPONIVEIS]\n");
    mostrarlistaH(2, NULL);
    printf("Insira o codigo do hamburguer: ");
    scanf("%d%*c", &codigo);
    while(l != NULL){
        if(l->h.codigo == codigo) *h = l->h;
        l = l->prox;
    }
    if(h->codigo == -1){
        printf("Hamburguer nao encontrado");
        return NULL;
    }
    return h;
}

Bebida* escolherBebida(){
    Bebida *b = (Bebida*) malloc(sizeof(Bebida));
    ListaB *l = lerBebidas();
    int codigo;
    b->codigo = -1;
    printf("\n[LISTA DE BEBIDAS DISPONIVEIS]\n");
    mostrarlistaB(2, NULL);
    printf("Insira o codigo da bebida: ");
    scanf("%d%*c", &codigo);
    while(l != NULL){
        if(l->b.codigo == codigo) *b = l->b;
        l = l->prox;
    }
    if(b->codigo == -1){
        printf("Bebida nao encontrada");
        return NULL;
    }
    return b;
}

Acompanhamento* escolherAcompanhamento(){
    Acompanhamento *a = (Acompanhamento*) malloc(sizeof(Acompanhamento));
    ListaA *l = lerAcompanhamentos();
    int codigo;
    a->codigo = -1;
    printf("\n[LISTA DE ACOMPANHAMENTOS DISPONIVEIS]\n");
    mostrarlistaA(2, NULL);
    printf("Insira o codigo do acompanhamento: ");
    scanf("%d%*c", &codigo);
    while(l != NULL){
        if(l->a.codigo == codigo) *a = l->a;
        l = l->prox;
    }
    if(a->codigo == -1){
        printf("Acompanhamento nao encontrado");
        return NULL;
    }
    return a;
}

Sobremesa* escolherSobremesa(){
    Sobremesa *s = (Sobremesa*) malloc(sizeof(Sobremesa));
    ListaS *l = lerSobremesas();
    int codigo;
    s->codigo = -1;
    printf("\n[LISTA DE SOBREMESAS DISPONIVEIS]\n");
    mostrarlistaS(2, NULL);
    printf("Insira o codigo da sobremesa: ");
    scanf("%d%*c", &codigo);
    while(l != NULL){
        if(l->s.codigo == codigo) *s = l->s;
        l = l->prox;
    }
    if(s->codigo == -1){
        printf("Sobremesa nao encontrada");
        return NULL;
    }
    return s;
}

Itens lerItens(){
    Itens *itens = (Itens*) malloc(sizeof(Itens));
    Hamburguer *h;
    Bebida *b;
    Acompanhamento *a;
    Sobremesa *s;
    ListaH *lh = NULL;
    ListaB *lb = NULL;
    ListaA *la = NULL;
    ListaS *ls = NULL;
    int opt = 0;
    while(opt != 5){
        opt = mostrarMenuPedido();
        if(opt == 1){
            h = escolherHamburguer();
            if(h == NULL) continue;
            lh = insertH(lh, *h);
        }
        if(opt == 2){
            b = escolherBebida();
            if(b == NULL) continue;
            lb = insertB(lb, *b);
        }
        if(opt == 3){
            a = escolherAcompanhamento();
            if(a == NULL) continue;
            la = insertA(la, *a);
        }
        if(opt == 4){
            s = escolherSobremesa();
            if(s == NULL) continue;
            ls = insertS(ls, *s);
        }
    }
    itens->h = lh;
    itens->b = lb;
    itens->a = la;
    itens->s = ls;
    return *itens;
}

ListaP* insertP(ListaP *l, Pedido *p){
    ListaP *aux = (ListaP*) malloc(sizeof(ListaP));
    aux->p = *p;
    aux->prox = NULL;
    if(l == NULL) return aux;
    ListaP *temp = l;
    ListaP *ant = l;
    while(l != NULL){
        ant = l;
        l = l->prox;
    }
    ant->prox = aux;
    return temp;
}

int calcTamanhoH(ListaH *l){
    int n = 0;
    while(l != NULL){
        n++;
        l = l->prox;
    }
    return n;
}

int calcTamanhoB(ListaB *l){
    int n = 0;
    while(l != NULL){
        n++;
        l = l->prox;
    }
    return n;
}

int calcTamanhoA(ListaA *l){
    int n = 0;
    while(l != NULL){
        n++;
        l = l->prox;
    }
    return n;
}

int calcTamanhoS(ListaS *l){
    int n = 0;
    while(l != NULL){
        n++;
        l = l->prox;
    }
    return n;
}

int calcTamanhoP(ListaP *l){
    int n = 0;
    while(l != NULL){
        n++;
        l = l->prox;
    }
    return n;
}

void salvar_aux(Pedido *p){
    int tamanho = 0;
    FILE *fp = fopen("pedidoaux.txt", "a");
    fprintf(fp, "%d", p->codigo);
    fprintf(fp, "%s", ";");
    fprintf(fp, "%d", calcTamanhoH(p->itens.h));
    fprintf(fp, "%s", ";");
    fprintf(fp, "%d", calcTamanhoB(p->itens.b));
    fprintf(fp, "%s", ";");
    fprintf(fp, "%d", calcTamanhoA(p->itens.a));
    fprintf(fp, "%s", ";");
    fprintf(fp, "%d", calcTamanhoS(p->itens.s));
    fprintf(fp, "%s", "\n");
    fclose(fp);
}

void salvarPedidos(ListaP *l){
    Pedido *p = (Pedido*) malloc(sizeof(Pedido));
    ListaH *lh = (ListaH*) malloc(sizeof(ListaH));
    ListaB *lb = (ListaB*) malloc(sizeof(ListaB));
    ListaA *la = (ListaA*) malloc(sizeof(ListaA));
    ListaS *ls = (ListaS*) malloc(sizeof(ListaS));
    Hamburguer *h = (Hamburguer*) malloc(sizeof(Hamburguer));
    Bebida *b = (Bebida*) malloc(sizeof(Bebida));
    Acompanhamento *a = (Acompanhamento*) malloc(sizeof(Acompanhamento));
    Sobremesa *s = (Sobremesa*) malloc(sizeof(Sobremesa));
    int i;

    FILE *fp = fopen("pedido.bin", "wb");
    while(l != NULL){
        *p = l->p;
        lh = p->itens.h;
        lb = p->itens.b;
        la = p->itens.a;
        ls = p->itens.s;
        fwrite(&p->codigo, sizeof(int), 1, fp);
        fwrite(&p->cpf, sizeof(p->cpf), 1, fp);
        while(lh != NULL){
            *h = lh->h;
            fwrite(&h->nome, sizeof(h->nome), 1, fp);
            fwrite(&h->desc, sizeof(h->desc), 1, fp);
            fwrite(&h->codigo, sizeof(int), 1, fp);
            fwrite(&h->disponivel, sizeof(int), 1, fp);
            fwrite(&h->precoG, sizeof(float), 1, fp);
            fwrite(&h->precoM, sizeof(float), 1, fp);
            fwrite(&h->precoP, sizeof(float), 1, fp);
            lh = lh->prox;
        }
        while(lb != NULL){
            *b = lb->b;
            fwrite(&b->nome, sizeof(b->nome), 1, fp);
            fwrite(&b->codigo, sizeof(int), 1, fp);
            fwrite(&b->disponivel, sizeof(int), 1, fp);
            fwrite(&b->precoG, sizeof(float), 1, fp);
            fwrite(&b->precoM, sizeof(float), 1, fp);
            fwrite(&b->precoP, sizeof(float), 1, fp);
            lb = lb->prox;
        }
        while(la != NULL){
            *a = la->a;
            fwrite(&a->nome, sizeof(a->nome), 1, fp);
            fwrite(&a->codigo, sizeof(int), 1, fp);
            fwrite(&a->disponivel, sizeof(int), 1, fp);
            fwrite(&a->preco, sizeof(float), 1, fp);
            la = la->prox;
        }
        while(ls != NULL){
            *s = ls->s;
            fwrite(&s->nome, sizeof(s->nome), 1, fp);
            fwrite(&s->codigo, sizeof(int), 1, fp);
            fwrite(&s->disponivel, sizeof(int), 1, fp);
            fwrite(&s->preco, sizeof(float), 1, fp);
            ls = ls->prox;
        }
        l = l->prox;
    }
    fclose(fp);
    free(p);
    free(lh);
    free(lb);
    free(la);
    free(ls);
    free(h);
    free(b);
    free(a);
    free(s);
}

ListaH* emptyH(){
    ListaH *aux = NULL;
    return aux;
}

ListaB* emptyB(){
    ListaB *aux = NULL;
    return aux;
}

ListaA* emptyA(){
    ListaA *aux = NULL;
    return aux;
}

ListaS* emptyS(){
    ListaS *aux = NULL;
    return aux;
}

ListaP* lerPedidos(){
    ListaP *l = NULL;
    ListaH *lh;
    ListaB *lb;
    ListaA *la;
    ListaS *ls;
    Pedido *p = (Pedido*) malloc(sizeof(Pedido));
    Hamburguer *h = (Hamburguer*) malloc(sizeof(Hamburguer));
    Bebida *b = (Bebida*) malloc(sizeof(Bebida));
    Acompanhamento *a = (Acompanhamento*) malloc(sizeof(Acompanhamento));
    Sobremesa *s = (Sobremesa*) malloc(sizeof(Sobremesa));
    FILE *fp;
    int qh[MAX], qb[MAX], qa[MAX], qs[MAX];
    char *linha = (char*) malloc(100);
    char *aux = (char*) malloc(100);
    int i, j, k;
    fp = fopen("pedidoaux.txt", "r");
    for(i = 0; fgets(linha, 100, fp); i++){
        strcpy(aux, linha);
        aux = strtok(aux, ";");
        aux = strtok(NULL, ";");
        qh[i] = atoi(aux);
        aux = strtok(NULL, ";");
        qb[i] = atoi(aux);
        aux = strtok(NULL, ";");
        qa[i] = atoi(aux);
        aux = strtok(NULL, ";");
        qs[i] = atoi(aux);
    }
    fclose(fp);
    fp = fopen("pedido.bin", "rb");
    for(j = 0; j < i; j++){
        free(lh);
        free(lb);
        free(la);
        free(ls);
        lh = emptyH();
        lb = emptyB();
        la = emptyA();
        ls = emptyS();
        fread(&p->codigo, sizeof(int), 1, fp);
        fread(p->cpf, sizeof(p->cpf), 1, fp);
        for(k = 0; k < qh[j]; k++){
            fread(h->nome, sizeof(h->nome), 1, fp);
            fread(h->desc, sizeof(h->desc), 1, fp);
            fread(&h->codigo, sizeof(int), 1, fp);
            fread(&h->disponivel, sizeof(int), 1, fp);
            fread(&h->precoG, sizeof(float), 1, fp);
            fread(&h->precoM, sizeof(float), 1, fp);
            fread(&h->precoP, sizeof(float), 1, fp);
            lh = insertH(lh, *h);
        }
        for(k = 0; k < qb[j]; k++){
            fread(b->nome, sizeof(b->nome), 1, fp);
            fread(&b->codigo, sizeof(int), 1, fp);
            fread(&b->disponivel, sizeof(int), 1, fp);
            fread(&b->precoG, sizeof(float), 1, fp);
            fread(&b->precoM, sizeof(float), 1, fp);
            fread(&b->precoP, sizeof(float), 1, fp);
            lb = insertB(lb, *b);
        }
        for(k = 0; k < qa[j]; k++){
            fread(a->nome, sizeof(a->nome), 1, fp);
            fread(&a->codigo, sizeof(int), 1, fp);
            fread(&a->disponivel, sizeof(int), 1, fp);
            fread(&a->preco, sizeof(float), 1, fp);
            la = insertA(la, *a);
        }
        for(k = 0; k < qs[j]; k++){
            fread(s->nome, sizeof(s->nome), 1, fp);
            fread(&s->codigo, sizeof(int), 1, fp);
            fread(&s->disponivel, sizeof(int), 1, fp);
            fread(&s->preco, sizeof(float), 1, fp);
            ls = insertS(ls, *s);
        }
        p->itens.h = lh;
        p->itens.b = lb;
        p->itens.a = la;
        p->itens.s = ls;
        l = insertP(l, p);
    }
    fclose(fp);
    free(aux);
    free(linha);
    return l;
}

void registrarPedido(){
    ListaP *l = lerPedidos();
    Pedido *pedido = (Pedido*) malloc(sizeof(Pedido));
    printf("\nInforme o codigo do pedido: ");
    scanf("%d%*c", &pedido->codigo);
    printf("\nInforme o CPF do cliente: ");
    scanf("%[^\n]%*c", pedido->cpf);
    pedido->itens = lerItens();
    salvar_aux(pedido);
    l = insertP(l, pedido);
    salvarPedidos(l);
}

void mostrarPedido(){
    Pedido *p = (Pedido*) malloc(sizeof(Pedido));
    ListaP *l = lerPedidos();
    int codigo;
    p->codigo = -1;
    printf("Insira o codigo do pedido: ");
    scanf("%d%*c", &codigo);
    while(l != NULL){
        if(l->p.codigo == codigo) *p = l->p;
        l = l->prox;
    }
    if(p->codigo == -1){
        printf("\nPedido nao encontrado\n");
        return;
    }
    printf("\n[SANDUICHES DO PEDIDO]\n");
    mostrarlistaH(1, p->itens.h);
    printf("\n[BEBIDAS DO PEDIDO]\n");
    mostrarlistaB(1, p->itens.b);
    printf("\n[ACOMPANHAMENTOS DO PEDIDO]\n");
    mostrarlistaA(1, p->itens.a);
    printf("\n[SOBREMESAS DO PEDIDO]\n");
    mostrarlistaS(1, p->itens.s);
}

int main() {
    int opt = 0;
    while(opt != 12){
        opt = mostrarMenu();
        if(opt == 1) cadastrarHamburguer();
        if(opt == 2) cadastrarBebida();
        if(opt == 3) cadastrarSobremesa();
        if(opt == 4) cadastrarAcompanhamento();
        if(opt == 5) mostrarlistaH(2, NULL);
        if(opt == 6) mostrarlistaB(2, NULL);
        if(opt == 7) mostrarlistaS(2, NULL);
        if(opt == 8) mostrarlistaA(2, NULL);
        if(opt == 9) registrarPedido();
        if(opt == 10) mostrarPedido();
    }
    return 0 ;
}
