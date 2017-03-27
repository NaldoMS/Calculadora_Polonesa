typedef struct pilha Pilha;
typedef char* string;

Pilha * criar();
void destruir(Pilha * p);
int desempilhar(Pilha * p); // ou pop
void empilhar(Pilha * p, int x); // ou push
int tamanho(Pilha * p);
int topo(Pilha * p);
void imprimir(Pilha * p);
void limpar(Pilha * p);
void aplicarOperacao(Pilha * p, char op);
