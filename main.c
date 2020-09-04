#include <stdio.h>

char * especiais_para_letras(char *frase) {
    char *p;
    char *init = p;
    char c;
    while(*frase) {
        switch(*frase) {
            case ' ':
                p--;
                break;
            case ',':
                *p = 'v';
                p++;
                *p = 'r'; 
                break;
            case '.':
                *p = 'p';
                p++;
                *p = 't';
                break;
            case ':':
                *p = 'd';
                p++;
                *p = 'p';
                break;
            case '!':
                *p = 'e';
                p++;
                *p = 'x';
                break;
            case '?':
                *p = 'i';
                p++;
                *p = 'n';
                break;
            case '\n':
                *p = 'n';
                p++;
                *p = 'l';
                break;
            default:
                *p = *frase;
        } 
        p++;
        frase++;
    }
    return init;
}

int main() {
    char *d = "Para: um?! bom\n ...entendedor, meia palavra basta.";
    char *p = especiais_para_letras(d);
    printf("%s\n", d);
    printf("%s\n", p);
    return 0;
}
