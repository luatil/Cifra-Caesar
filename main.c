#include <stdio.h>

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

int main() {
      char *d = "Para um bom entendedor, meia palavra basta.";
      char *t = especiais_para_letras(d);
//      char *f = rotacao("Para um bom" , 3, 5);
//      printf("%s\n", f);
      printf("%s\n", t);
    return 0;

}
