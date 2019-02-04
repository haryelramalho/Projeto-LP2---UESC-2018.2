#include "functions.c"

int main(void)
{
    FILE *arq;
    int i, j, aux = 9, resp = 1;
	char matriz[21][39] = {' '}, op, esc, a;

	arq = fopen("jogadores.txt", "r");
    fscanf(arq, "%d", &qtd);

    if(qtd != 0)
    {
        vj = (struct jogador *) malloc(qtd * sizeof(struct jogador));
    }
    else
    {
        vj = (struct jogador *) malloc(1 * sizeof(struct jogador));
    }

    for(i = 0; i < qtd; ++i)
    {
        a = fgetc(arq);
        fscanf(arq, "%s%s%d", vj[i].nome, vj[i].senha, &vj[i].score);
    }

    fclose(arq);

    strcpy(matriz[0], "                  0");
    strcpy(matriz[1], "                 000");
    strcpy(matriz[2], "                00 00");
    strcpy(matriz[3], "               00   00");
    strcpy(matriz[4], "              00     00");
    strcpy(matriz[5], "             00       00");
    strcpy(matriz[6], "            00         00");
    strcpy(matriz[7], "000000000000             000000000000");
    strcpy(matriz[8], " 00                               00");
    strcpy(matriz[9], "   00           JOGAR           00");
    strcpy(matriz[10],"     00         CONTA        00");
    strcpy(matriz[11],"       00       SCORE      00");
    strcpy(matriz[12],"        000     SAIR     000");
    strcpy(matriz[13],"        00                00");
    strcpy(matriz[14],"       00       0000       00");
    strcpy(matriz[15],"      00     00      00     00");
    strcpy(matriz[16],"     00    00          00    00");
    strcpy(matriz[17],"    00  00                00  00");
    strcpy(matriz[18],"   0000                      0000");
    strcpy(matriz[19],"  000                          000");
    strcpy(matriz[20]," 0                                0");

	matriz[9][14] = 175;
    while(resp != 0)
    {
        do
        {
            system("cls");

            if(ind_j != -1)
            {
                printf("\t\t\t\t\t\t\t\t\tUsuario: %s\n", jog.nome);
                printf("\t\t\t\t\t\t\t\t\tSCORE: %d\n\n\n", jog.score);
            }

            printf("\n\n\n\n");
            for(i = 0; i < 21; ++i)
            {
                printf("\t\t\t\t");
                for(j = 0; j < 39; ++j)
                {
                    printf("%c", matriz[i][j]);
                }
                printf("\n");
            }

            op = getch();
            switch(op)
            {
                case 72:
                    matriz[aux][14] = ' ';
                    aux = (aux == 9? 12: aux - 1);
                    matriz[aux][14] = 175;
                    break;
                case 80:
                    matriz[aux][14] = ' ';
                    aux = (aux == 12? 9: aux + 1);
                    matriz[aux][14] = 175;
                    break;
            }
        }while(op != 13);

        if(matriz[9][14] != ' ')
        {
            game();
        }
        else
        {
            if(matriz[10][14] != ' ')
            {
                system("cls");
                printf("\n\n\n\n\t\t\t\t1 - CADASTRAR\n\t\t\t\t2 - LOGIN\n\n\n\n\n");
                esc = getch();
                if(esc == '1')
                {
                    cad_jog();
                }
                else
                {
                    if(esc == '2')
                    {
                        login();
                    }
                }
            }
            else
            {
                if(matriz[11][14] != ' ')
                {
                    scores();
                }
                else
                {
                    arq = fopen("jogadores.txt", "w");

                    fprintf(arq, "%d\n", qtd);

                    if(qtd > 0)
                    {
                        if(ind_j != -1)
                        {
                            vj[ind_j] = jog;
                        }
                        for(i = 0; i < qtd; ++i)
                        {
                            fprintf(arq, "%s\n%s\n%d\n", vj[i].nome, vj[i].senha, vj[i].score);
                        }
                    }
                    resp = 0;
                }
            }
        }
    }
    fclose(arq);
	return(0);
}
