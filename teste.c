#include <stdio.h>
int main(void) {
    
    int x, y, c;

    do {
        printf("Digite o numero de pes: ");
        scanf("%d", &x);
    } while (x % 2);

    printf("Digite o numero de cabecas: ");
    scanf("%d", &y);

    c = x / 4 + (x / 4 + x % 4 / 2 - y);

    if ((c > y) || (c < 0)) {
        printf("Combinacao invalida de valores!\n");
    } else {
        printf("Numero de coelhos: %d\n", c);
        printf("Numero de patos: %d\n", y - c);
    }

	return (0);
}

