#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h> 
#include "Pilha.h"

int main() {
	Pilha * p = criar();
	char ch[100];
	int num;
	int i = 0, j = 0, cont = 0;
	string s = malloc(100+1);

	printf("--------------------------\n");
	printf("| \t \t \t |\n");
	printf("| Calculadora Polonesa   |\n");
	printf("| \t \t \t |\n");
	printf("--------------------------\n");
	while (1)
	{
		printf(">");
		gets(ch);
			if (isdigit(ch[j]) || (ch[j] == '-' && ch[j+1] != '\0')) {
				while (ch[j] != '\0')
				{
					if (ch[j] != ' ') {
						while (ch[j] != ' ' && ch[j] != '\0') {
							s[i] = ch[j];
							j++;
							i++;
						}
						num = atoi(s);
						empilhar(p, num);
						system("cls");
						printf("--------------------------\n");
						printf("| \t \t \t |\n");
						printf("| Calculadora Polonesa   |\n");
						printf("| \t \t \t |\n");
						printf("--------------------------\n");
						cont = 0;
					}

					else if ((ch[j] == '-' && isdigit(ch[j+1])) || (ch[j] == ' ' && ch[j+1] == '-' && isdigit(ch[j + 2]))){
						free(s);
						s = malloc(100 + 1);
						j++;
						while (ch[j] != ' ' && ch[j] != '\0') {
							s[i-1] = ch[j];
							j++;
							i++;
						}
						num = atoi(s);
						empilhar(p, num);
					}

					else if (ch[j] == ' ') {
						j++;
						if (isdigit(ch[j])) {
							num = ch[j] - 48;
							j++;
							i++;
							empilhar(p, num);
							system("cls");
							printf("--------------------------\n");
							printf("| \t \t \t |\n");
							printf("| Calculadora Polonesa   |\n");
							printf("| \t \t \t |\n");
							printf("--------------------------\n");
							cont = 0;
						}

						else {
							aplicarOperacao(p, ch[j]);
							j++;
							cont = 0;
						}
					}

					else if (ch[j] == '+' || ch[j] == '-' || ch[j] == '*' || ch[j] == '/') {
						aplicarOperacao(p, ch[j]);
						cont = 0;
					}
				}
				
			}

			else{
				if (ch[j] == '\0') {
					if (cont == 0) {
						system("cls");
						printf("--------------------------\n");
						printf("| \t \t \t |\n");
						printf("| Calculadora Polonesa   |\n");
						printf("| \t \t \t |\n");
						printf("--------------------------\n");
						limpar(p);
						printf("A pilha foi limpa!\n\nAperte <enter> novamente para encerrar o programa\n");
						cont++;
					}

					else {
						exit(EXIT_FAILURE);
					}
				}

				else {
					system("cls");
					printf("--------------------------\n");
					printf("| \t \t \t |\n");
					printf("| Calculadora Polonesa   |\n");
					printf("| \t \t \t |\n");
					printf("--------------------------\n");
					aplicarOperacao(p, ch[j]);
				}
			}
			
			j = 0;
			i = 0;
			free(s);
			s = malloc(100 + 1);
			printf("Estado atual da pilha: ");
			imprimir(p);
		}
	system("PAUSE");
	return 0;
}