//Trabalho ILC Jo�o Pedro Castilho Diniz Cardoso e Ana Luisa Girio Berlingieri
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
/*O c�digo funciona da seguinte forma: ele pede ao usu�rio para que digite uma string, ent�o ele procura por palavras chaves como "nao" e "implica"
quando ele acha essas palavras ele substitui elas pelos s�mbolos definidos nos defines, eles precisam ter somente um caracter*/

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


    if ((vetor[0] == 'n' || vetor[0] == 'N')&& vetor[1] == 'a' && vetor[2] == 'o' && vetor[3] == ' ') //Esse if analisa se a primeira coisa digitada eh um nao
        {
            vetor[3] = NEGACAO;

            for (i = 0; i < 3; i++)//substitui as posi��es antes do s�mbolo de nega��o por espa�os
            {
                vetor[i] = ' ';
            }
            for (k = 0; k < TAMANHO_NEGACAO; k++)//retrai o vetor no n�mero de letras que a palavra chave de nega��o t�m, nesse caso, 3.
                for (j = 0; vetor[j] != '\0'; j++)
                    vetor[j] = vetor[j+1];
        }
    for (i = 1; vetor[i] != '\0'; i++) //analisa da posi��o 1 at� a posi��o final do vetor
    {
        if (vetor[i - 1] == ' ' && vetor[i + 1] == ' ' && (vetor[i] == 'e' || vetor[i] == 'E'))//substitui "e" pelo s�mbolo desejado.
            vetor[i] = E;

        else if (vetor[i - 1] == ' ' && vetor[i] == 'o' && vetor[i+1] == 'u' && vetor[i+2] == ' ')//substitui "ou" pelo s�mbolo desejado.
        {
            vetor[i] = OU;

            for (j = i+1; vetor[j] != '\0'; j++)//como "ou" tem 2 caracteres, o vetor precisa ser retra�do uma posi��o
                vetor[j] = vetor[j+1];
        }
        else if (vetor[i - 1] == ' ' && vetor[i] == 'n' && vetor[i+1] == 'a' && vetor[i+2] == 'o' && vetor[i + 3] == ' ')//substitui "nao" pelo s�mbolo desejado.
        {
            vetor[i+3] = NEGACAO;

            for (j = i; j < i + 3; j++)//come as letras antes do s�mbulo de nega��o, e substitui por espa�os
            {
                vetor[j] = ' ';
            }
            for (k = 0; k < TAMANHO_NEGACAO; k++)//como "nao" tem 3 caracteres, o vetor precisa ser retra�do duas posi��es
                for (j = i; vetor[j] != '\0'; j++)
                    vetor[j] = vetor[j+1];
        }
        else if (EhImplicacao(vetor, i)) //chama a fun��o EhImplica��o
            vetor[i] = IMPLICA;
    }
}
//Essa fun��o verifica se na string, no intervalo certo est� escrito "implica", se essa condi��o se concretizar, ela retorna 1
int EhImplicacao (char vetor[], int posicao)
{
    char vetor_comparativo [TAMANHO_IMPLICACAO] = {' ', 'i', 'm', 'p', 'l', 'i', 'c', 'a', ' '};
    int flag_implica = 1, i, comeco, fim, j = 0;

    comeco = posicao - 1;
    fim = comeco + TAMANHO_IMPLICACAO;


    for (i = comeco; i < fim && flag_implica; i++)//compara o vetor onde est� escrito "implica" com o intervalo da fun��o.
    {
        if (vetor [i] != vetor_comparativo[j])
            flag_implica = 0;
        j++;
    }
    if (flag_implica)
    {
        for (i = posicao + 1; vetor[i] != ' '; i++)//Se a palavra no intervalo for implica, ele apaga as posi��es anteriores e retrai o vetor.
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
