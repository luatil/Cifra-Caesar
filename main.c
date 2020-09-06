#include <stdio.h>

// TODO Create unit tests for both functions


char * especiais_para_letras(char *frase) {
    char *p;
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
    return init;
}


// d1 aplica uma rotação para as maiúsculas
// d2 aplica uma rotação para as minúsculas
char * rotacao(char *frase2, char d1, char d2) {
    char *p2;
    char *init2 = p2;
    while(*frase2) {
        if(*frase2 >= 'A' && *frase2 <= 'Z')
            *p2 = *frase2 + d1;
        else if(*frase2 >= 'a' && *frase2 <= 'z')
            *p2 = *frase2 + d2;
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
    char *p = especiais_para_letras(d);
}

int main() {
    test_string_compare();
    return 0;

}
