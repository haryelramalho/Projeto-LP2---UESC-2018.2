#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>
#include <string.h>

int main(void)
{
	int i, aux = 0;
	char mat[3][10], op;

	strcpy(mat[0], "  JOGAR");
	strcpy(mat[1], "  SCORES");
	strcpy(mat[2], "  SAIR");

	mat[0][0] = 175;

	do
	{
        	system("cls");
		for(i = 0; i < 3; ++i)
		{
			printf("%s\n", mat[i]);
		}
		op = getch();
		switch(op)
		{
			case 'w':
				mat[aux][0] = ' ';
				aux = (aux == 0? 2: aux - 1);
				mat[aux][0] = 175;
				break;
			case 's':
				mat[aux][0] = ' ';
				aux = (aux == 2? 0: aux + 1);
				mat[aux][0] = 175;
				break;
		}
	}while(op != 13);

	if(mat[0][0] != ' ')
	{
		printf("JOGANDO!\n");
	}
	else
	{
		if(mat[1][0] != ' ')
		{
			printf("SCORES!\n");
		}
		else
		{
			printf("SAINDO!\n");
		}
	}

	return(0);
}
