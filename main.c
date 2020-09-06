#include <stdio.h>
#include <stdlib.h>

// TODO Create unit tests for both functions

#define TAMANHO_DA_FRASE 100

char * especiais_para_letras(char *frase) {
    char *p = malloc(TAMANHO_DA_FRASE);
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
char * rotacao(char *frase2, char d1, char d2) {
    char *p2 = malloc(TAMANHO_DA_FRASE);
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

int string_compare(char *s1, char *s2) {
    while(*s1 != '\0') {
        if(*s1++ != *s2++)
            return 0;
    }
    if(*s2 == '\0')
        return 1;
    return 0;
}

void test_string_compare() {
    if (!string_compare("oi", "oi")) 
        printf("Primeiro test de string_compare falhou\n");
    else if(string_compare("oi", "oio"))
        printf("Segundo teste de string_compare falhou\n");
    else if(!string_compare("", ""))
        printf("Terceiro teste de string_compare falhou\n");
    else if(!string_compare("Hello how are you", "Hello how are you"))
        printf("Quarto teste de string_compare falhou\n");
    else 
        printf("Todos os testes de string_compare passaram\n");
}

void test_especiais_para_letras() {
    char *d = "Para um bom entendedor, meia palavra basta.";
    char *t = especiais_para_letras(d);
    if(!string_compare(t, "Paraumbomentendedorvrmeiapalavrabastapt")) {
        printf("Primeiro test de especiais_para_letras falhou\n");
    }
    else 
        printf("Todos os testes de especiais_para_letras passaram\n");
    free(t);
}

void test_rotacao() {
    char *d = "Paraumbomentendedorvrmeiapalavrabastapt";
    char *t = rotacao(d, 3, 5);
    char *target = "Sfwfzrgtrjsyjsijitwawrjnfufqfawfgfxyfuy";
    if(!string_compare(t, target))  {
        printf("Primeiro test de rotacao falhou\n");
        printf("%s\n", t);
        printf("%s\n", target);
    }
    else 
        printf("Os testes de rotacao() passaram\n");
}

int main() {
    test_especiais_para_letras();
    test_rotacao();
    return 0;
}
