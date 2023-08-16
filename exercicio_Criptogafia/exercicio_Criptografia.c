#include <stdio.h>
#include <string.h>

void decode(char string[])
{
    char alfabetoMinusculas[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char alfabetoMaiusculas[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char aux;
    int a = 0, b = 1, c = strlen(string) - 1, d = strlen(string) - 2;

    printf("\n%s", string);
    printf("\n--------------------\nMensagem decodificada:\n--------------------");

    while (b != d && b < d)
    {
        aux = string[a];
        string[a] = string[d];
        string[d] = aux;
        aux = string[b];
        string[b] = string[c];
        string[c] = aux;
        a = a + 4;
        b = b + 4;
        c = c - 4;
        d = d - 4;
        // printf("\n %i %i %i %i", a, b, c ,d);
    }
    a = 0;
    b = 1;

    while (b <= strlen(string))
    {
        aux = string[a];
        string[a] = string[b];
        string[b] = aux;
        a = a + 2;
        b = b + 2;
    }

    for (int j = 0; j < strlen(string); j++)
    {
        for (int i = 0; i < 26; i++)
        {

            if (i >= 5)
            {
                if (string[j] == alfabetoMaiusculas[i])
                {
                    string[j] = alfabetoMaiusculas[i - 5];
                    break;
                }
                if (string[j] == alfabetoMinusculas[i])
                {
                    string[j] = alfabetoMinusculas[i - 5];
                    break;
                }
            }
            else
            {
                if (string[j] == alfabetoMaiusculas[i])
                {
                    string[j] = alfabetoMaiusculas[26 - (5 - i)];
                    break;
                }
                if (string[j] == alfabetoMinusculas[i])
                {
                    string[j] = alfabetoMinusculas[26 - (5 - i)];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '#')
        {
            string[i] = ' ';
        }
    }

    string[strlen(string)] = '\0';
    printf("\n%s", string);
}

int main()
{
    FILE *p;
    int i = 0;
    char str[80], string[100];

    // Le um nome para o arquivo a ser aberto:
    printf("Digite o nome do arquivo: ");
    scanf("%s", str); // Não é necessário o operador de endereço (&) aqui

    // Abre para a leitura
    if (!(p = fopen(str, "r")))
    {
        printf("Erro! Impossivel abrir o arquivo!\n");
        return (0);
    }
    printf("--------------------\nMensagem codificada:\n--------------------");

    // Imprime conteudo do arquivo
    string[i] = fgetc(p);
    while (!feof(p))
    {
        i++;
        string[i] = fgetc(p);
    }
    string[i] = '\0';

    fclose(p);

    decode(string);

    return 0;
}