#include <stdio.h>
#include <string.h>

#define N 1024
#define TAMANHO_IMPLICACAO 9
#define TAMANHO_NEGACAO 3

#define IMPLICA '>'
#define NEGACAO '~'
#define E '&'
#define OU '|'

void SubstituiSinais(char v[]);
int EhImplicacao (char vetor[], int posicao);

int main()
{
    char preposicao[N];
    int i;

    fgets(preposicao, N, stdin);

    SubstituiSinais(preposicao);

    printf("%s", preposicao);

    return 0;
}

void SubstituiSinais(char vetor[])
{
    int i, j, k;


    if ((vetor[0] == 'n' || vetor[0] == 'N')&& vetor[1] == 'a' && vetor[2] == 'o' && vetor[3] == ' ')
        {
            vetor[3] = NEGACAO;

            for (i = 0; i < 3; i++)
            {
                vetor[i] = ' ';
            }
            for (k = 0; k < TAMANHO_NEGACAO; k++)
                for (j = 0; vetor[j] != '\0'; j++)
                    vetor[j] = vetor[j+1];
        }
    for (i = 1; vetor[i] != '\0'; i++)
    {
        if (vetor[i - 1] == ' ' && vetor[i + 1] == ' ' && (vetor[i] == 'e' || vetor[i] == 'E'))
            vetor[i] = E;

        else if (vetor[i - 1] == ' ' && vetor[i] == 'o' && vetor[i+1] == 'u' && vetor[i+2] == ' ')
        {
            vetor[i] = OU;

            for (j = i+1; vetor[j] != '\0'; j++)
                vetor[j] = vetor[j+1];
        }
        else if (vetor[i - 1] == ' ' && vetor[i] == 'n' && vetor[i+1] == 'a' && vetor[i+2] == 'o' && vetor[i + 3] == ' ')
        {
            vetor[i+3] = NEGACAO;

            for (j = i; j < i + 3; j++)
            {
                vetor[j] = ' ';
            }
            for (k = 0; k < TAMANHO_NEGACAO; k++)
                for (j = i; vetor[j] != '\0'; j++)
                    vetor[j] = vetor[j+1];
        }
        else if (EhImplicacao(vetor, i))
            vetor[i] = IMPLICA;
    }
}

int EhImplicacao (char vetor[], int posicao)
{
    char vetor_comparativo [TAMANHO_IMPLICACAO] = {' ', 'i', 'm', 'p', 'l', 'i', 'c', 'a', ' '};
    int flag_implica = 1, i, comeco, fim, j = 0;

    comeco = posicao - 1;
    fim = comeco + TAMANHO_IMPLICACAO;


    for (i = comeco; i < fim; i++)
    {
        if (vetor [i] != vetor_comparativo[j])
            flag_implica = 0;
        j++;
    }
    if (flag_implica)
    {
        for (i = posicao + 1; vetor[i] != ' '; i++)
        {
            vetor[i] = ' ';
        }
        for (j = 0; j < TAMANHO_IMPLICACAO - 3; j++)
            for (i = posicao + 1; vetor[i] != '\0'; i++)
            {
                vetor[i] = vetor[i+1];
            }
    }
    return (flag_implica);
}
