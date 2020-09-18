#include <stdio.h>
#include <stdlib.h>

// TODO test bigger than 26 values
// TODO solve valgrind jump depends on uninitialised value(s)
// TODO test the chalenges

char * especiais_para_letras(char *frase, int tamanho_da_frase);
char * rotacao(char *frase2, char d1, char d2, int tamanho_da_frase);
char * aplicar_rotacao(char * p, int d1, int d2, int tamanho_da_frase);
char * realocar_memoria(char * p, int *tamanho);

int main() {
    int d1, d2;
    printf("Digite o valor dos deslocamentos d1 e d2: \n");
    scanf("%d %d", &d1, &d2);

    printf("Digite o nome do arquivo a ser lido:\n");
    char nome[80];
    scanf("%s", nome);
    FILE * arq;
    arq = fopen(nome, "r");
    if(arq == NULL) {
        printf("Não encontrei o arquivo %s, \n", nome);
    }
    else {
        int tam = 0;
        int tamanho_original = 100;
        char *text = malloc(tamanho_original * sizeof(char));
        while(!feof (arq)) {
            if(tam >= tamanho_original)
                text = realocar_memoria(text, &tamanho_original);
            fscanf(arq, "%c", &text[tam]);
            tam++;
        }
        text[tam-2] = '\0';
        char *frase_cifrada = aplicar_rotacao(text, d1, d2, tam);
        printf("%s\n", frase_cifrada);
        free(frase_cifrada);
        free(text);
        fclose(arq);
    }

    return 0;
}

char * realocar_memoria(char * p, int * tamanho) {
    char *novo = malloc(*tamanho * 2 * sizeof(char));
    for(int i = 0; i < *tamanho; i++) 
        novo[i] = p[i];
    free(p);
    *tamanho *= 2;
    return novo;
}

char * especiais_para_letras(char *frase, int tamanho_da_frase) {
    char *p = malloc(tamanho_da_frase * sizeof(char));
    char *init = p;
    while(*frase) {
        switch(*frase) {
            case ' ':
                p--;
                break;
            case ',':
                *p = 'v';
                *++p = 'r'; 
                break;
            case '.':
                *p = 'p';
                *++p = 't';
                break;
            case ':':
                *p = 'd';
                *++p = 'p';
                break;
            case '!':
                *p = 'e';
                *++p = 'x';
                break;
            case '?':
                *p = 'i';
                *++p = 'n';
                break;
            case '\n':
                *p = 'n';
                *++p = 'l';
                break;
            default:
                *p = *frase;
        } 
        p++;
        frase++;
    }
    p++;
    p = '\0';
    return init;
}


// d1 aplica uma rotação para as maiúsculas
// d2 aplica uma rotação para as minúsculas
char * rotacao(char *frase2, char d1, char d2, int tamanho_da_frase) {
    char *p2 = malloc(tamanho_da_frase * sizeof(char));
    char *init2 = p2;
    while(*frase2) {
        if(*frase2 >= 'A' && *frase2 <= 'Z')
            *p2 = 'A' + ((*frase2 - 'A' + d1) % 26);
        else if(*frase2 >= 'a' && *frase2 <= 'z')
            *p2 = 'a' + ((*frase2 - 'a' + d2) % 26);
        else 
            *p2 = *frase2;
        p2++;
        frase2++;
    }
    p2++;
    *p2 = '\0';
    return init2; 
}


char * aplicar_rotacao(char * p, int d1, int d2, int tamanho_da_frase) {
    char * f1 = especiais_para_letras(p, tamanho_da_frase);
    char * f2 = rotacao(f1, (char)d1, (char)d2, tamanho_da_frase);
    free(f1);
    return f2;
}


