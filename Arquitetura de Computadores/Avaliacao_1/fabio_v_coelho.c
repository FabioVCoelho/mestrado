#include <stdio.h>
#include <limits.h>
int main() {
int vetor[] = {10, 5, 30, 15, 20, 8, 45, 22};
int indices = 8;
int i = 1;
int maior_valor = vetor[0];
int k = 0;
while (i < indices) {
if (vetor[i] > maior_valor) {
maior_valor = vetor[i]; // Atualiza o maior valor encontrado.
k = i;
// 'k' armazena o índice do maior valor atual.
}
i = i + 1; // Incrementa o contador do loop (alternativamente, i++;)
}
printf("Maior Valor: %d\n", maior_valor);
printf("Indice do valor: %d\n", k);
return 0;
}
