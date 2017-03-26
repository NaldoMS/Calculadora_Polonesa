#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h>
#include "Pilha.h"

void aplicarOperacao(Pilha * p, char op)
{
	int lhs, rhs, result;

	if (tamanho(p) >= 2) {
		rhs = desempilhar(p);
		lhs = desempilhar(p);
		switch (op) {
		case '+':
			result = lhs + rhs;
			empilhar(p, result);
			break;

		case '-':
			result = lhs - rhs;
			empilhar(p, result);
			break;

		case '*':
			result = lhs * rhs;
			empilhar(p, result);
			break;

		case '/':
			if (rhs != 0) {
				result = lhs / rhs;
				empilhar(p, result);
				break;
			}
			else {
				printf("Impossivel a divisao por zero\n");
				empilhar(p, lhs);
				empilhar(p, rhs);
			}
			break;

		default: printf("Operacao invalida\n");
			empilhar(p, lhs);
			empilhar(p, rhs);

		}
	}

	else
	{
		printf("Voce nao pode realizar uma operacao com menos de dois numeros\n");
	}
}

//string getLine(void)
//{
//	string line;
//	int n, ch;
//	n = 0;
//	line = malloc(100 + 1);
//	if (line == NULL) {
//		exit(EXIT_FAILURE);
//	}
//
//	while ((ch = getc(stdin)) != '\n') {
//		if (n >= 100) {
//			free(line);
//			exit(EXIT_FAILURE);
//		}
//		line[n++] = ch;
//	}
//	line[n] = '\0';
//	return line;
//}

//string getLine(void);

int main() {
	Pilha * p = criar();
	char ch[100];
	int num, n;
	int i = 0, j = 0, cont = 0;
	string s = malloc(100+1);

	while (1)
	{
		printf(">");
		gets(ch);
			if (isdigit(ch[j])) {
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
					}

					else if (ch[j] == ' ') {
						j++;
						if (isdigit(ch[j])) {
							num = ch[j] - 48;
							j++;
							i++;
							empilhar(p, num);
						}
						
						else {
							aplicarOperacao(p, ch[j]);
							imprimir(p);
							j++;
						}
					}

					else if (ch[j] == '+' || ch[j] == '-' || ch[j] == '*' || ch[j] == '/') {
						aplicarOperacao(p, ch[j]);
						imprimir(p);
					}
				}
				
			}

			else{
				if (ch[j] == '\0') {
					if (cont == 0) {
						printf("A pilha foi limpa\n\nAperte <enter> novamente para encerrar o programa\n");
						limpar(p);
						imprimir(p);
						cont++;
					}

					else {
						exit(EXIT_FAILURE);
					}
				}

				else {
					aplicarOperacao(p, ch[j]);
					imprimir(p);
				}
			}
			
			j = 0;
			i = 0;
			free(s);
			s = malloc(100 + 1);
			imprimir(p);
		}
	system("PAUSE");
	return 0;
}