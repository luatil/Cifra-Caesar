# Cifra-Caesar

* Parte 1

Criptografando textos - Entrega: 25 de setembro de 2020

Cifra de Cesar

É dado um texto em um arquivo composto por letras maiúsculas, minúsculas (sem acentos),
espaços em branco, ’, ’, ’.’, ’ !’, ’ ?’ e ’\n’, terminado pelo caractere de fim de arquivo ’EOF’.

O primeiro passo é transformar os caracteres especiais acima em letras da seguinte forma:


• brancos: são removidos
• , (vı́rgula): “vr”
• . (ponto): “pt”
• : (dois pontos): “dp”
• ! (exclamação): “ex”
• ? (interrogação): “in”
• nova linha: “nl”

Por exemplo:

Para um bom entendedor, meia palavra basta.

Paraumbomentendedorvrmeiapalavrabastapt

Depois desse passo, é aplicada uma rotação no alfabeto.

Mas uma para maiúsculas e outro para minúsculas.

Assim se aplicarmos d1 = 3 para as maiúsculas e d2 = 5 para as minúsculas. A frase acima seria:

Sfwfzrgtrjsyjsijitwawrjnfufqfawfgfxyfuy

E para o texto:

Em horas inda louras, lindas
Clorindas e Belindas, brandas
Brincam nos tempos das Berlindas
As vindas vendo das varandas.

Usando d 1 = 10 e d 2 = 7, (imprimindo em 80 colunas)

OtovyhzpukhsvbyhzcyspukhzusMsvypukhzlLlspukhzcyiyhukhzusLypujhtuvzaltwvzkhzLlysp
ukhzusKzcpukhzclukvkhzchyhukhzwa

* Parte 2: Como ler um arquivo? 

Seu EP deverá ler da entrada dois inteiros d1 e d2, deslocamento
das máiusculas e minúsculas, respectivamente. 

Além disso, deverá ler o nome de um arquivo de texto onde estará
o texto a ser criptografado. 

    char nome[80]; /* recebe o nome externo do arquivo a ser lido */

    printf("Digite o nome do arquivo que será criptografado: ");

Com isso, você poderá abrir o arquivo para leitura: 

    FILE * arq; /* variável que recebe um ponteiro para o arquivo que será lido */

    arq = fopen(nome, "r");
    if(arq == NULL) {
        printf("Não encontrei o arquivo %s, \n", nome);
    }

    tam = 0;
    while(!feof (arq)) {
        fscanf(arq, "%c", &text[tam]);
        tam++;
    }

A função feof verifica se o arquivo acabou (end of file).


Importante: Não é permitido o use neste EP de funções da biblioteca strings.

Parte 3: Desafio

- Texto 1:

AcivlwviakqdzcuivrwbwzbwvtlmaamaycmdqdmuviawujzivtlqaamlxFiqdzMiztwamfamzoickpmv
idqlixbvtvtKakiaiamaxqiuwapwumvavtycmkwzzmuibzialmuctpmzmaxbvtKbizlmbitdmhnwaami
hctdzvtviwpwcdmaambivbwalmamrwaxbvtvtYjwvlmxiaaikpmqwlmxmzvialxvtxmzviajzivkiaxz
mbiaiuizmtiaxbvtZiziycmbivbixmzvidzumcNmcadzvtxmzocvbiumckwzikiwxbvtZwzmuumcawtp
wavtviwxmzocvbiuvilixbvtvtYpwumuibzialwjqowlmvtmamzqwdzaquxtmamnwzbmxbvtAciamviw
kwvdmzaixbvtDmuxwckwadzzizwaiuqowavtwpwumuibzialwawkctwamlwjqowlmxbvtvtWmcNmcadz
xwzycmumijivlwviabmvtamaijqiaycmmcviwmziNmcavtamaijqiaycmmcmzinzikwxbvtvtWcvlwuc
vlwdiabwucvlwdzvtammcumkpiuiaamBiqucvlwvtamzqicuizquidzviwamzqicuiawtckiwxbvtWcv
lwucvlwdiabwucvlwdzvtuiqadiabwmumckwzikiwxbvtvtOcviwlmdqibmlqhmzvtuiamaaitcivtui
amaamkwvpiycmvtjwbiuiomvbmkwuwdqlwkwuwwlqijwxbvtvt

- Texto 2:

RmtixnggePhnixsexlmhftmxlixexxlxgjntkmbxklokgeRmtixwxnqgeexltnuxkzbgxlxmexlvhnkz
xmmxlxgkhgwxeexlimgeRmtixmkhblgeRfbgvxsexlihbokhglxgetfxeexlgeRmtixjntmkxgexmexh
bzghgxgkhnxeexlimgeRmtixvbgjgePatnyyxswxnqvnbeexkxltlhnixwxanbexwtglngxihxexgeRm
tixlbqgexmytbmxlryhgwkxexlhbzghglxmexlihbokhglimgeRmtixlximgeYhkljnxbellhgmmxgwk
xloktchnmxsexlmhftmxlokextbeatvaxokexmarfxmexetnkbxkimgeRmtixanbmgeFtexsokihbokx
sxmetbllxsfbchmxkwhnvxfxgmtvhnoxkmwnktgmjntkxgmvbgjfbgnmxlimgeRmtixgxnygeCxgwtgm
vxmxfilokikxitkxsexltnuxkzbgxlxmexlvhnkzxmmxlimStbmxlexlvnbkxlxitkxffxgmhnghgwtg
lexanbexwxheboxixgwtgmjnbgsxfbgnmxlimgeRmtixwbqgeIxkbybxsetvnbllhgwxlexznfxlihnk
jnxbelgxlhbxgmienlyxkfxlimNchnmxsexltehkltnfxetgzxwxmhftmxlxmikhehgzxsetvnbllhgl
nkmhnmixmbmyxnixgwtgmwbqfbgimgeRmtixhgsxgeFtexsxmihbokxslbuxlhbgimge

- Texto 3: 

EnjEzijsSjifpyntsawinjzwxuwzjslqnhmnsnmwjwUjcyxfrrqzslinjXtjwyjwHwzsixyzjhpxajwp
jmwxljsjmrnlzslxezxyfjsinlpjnyxzjgjwywflzslxajwtwiszslzsiSnsikqjnxhmjynpjyynjwzs
lxzjgjwbfhmzslxfzklfgjszjgjwywflzslxljxjyefqxqfjslxyjxzsiebjnyqfjslxyjxXtwynijsy
nknenjwymfyawsjssyfsiwnyyjwTyjqqjifxXtwyWjwpjmwxnskwfxywzpyzwknsfsenjwzslxljxjqq
xhmfkyawfgjwifinjCjkzlsnxxjinjxjwHjxjqqxhmfkynrxnjgjsCzhmxyfgjsqfjsljwjsWjwpjmwx
nskwfxywzpyzwknsfsenjwzslxljxjqqxhmfkyxljxjyeljwjljqyxnsiawljmtjwyifxXtwygjxyjsk
fqqxfsinjanjwyjTyjqqjuyUfyxfjhmqnhmbnwifgjwfzhmifxWjwpjmwxnskwfxywzpyzwknsfsenjw
zslxljxjqqxhmfkyxljxjyesthmizwhminjWjwrtjljsxeztwiszslxezxyfjsinlpjnyxzjgjwywflz
slxajwtwiszslljxhmqfljsuyNnyxjhmzsikzjskenlCzhmxyfgjsnxyinjxjxXtwynrNtrjsyijwfzx
xnhmyxwjnhmxyjLfsinifykzjwifxqfjslxyjsnhmytgxtqjyjXtwyijxEjzyxhmjsawifxfzxxhmqnj
xxqnhmrnyCzhmxyfgjsljxhmwnjgjsbnwi(ifezlqjnhmrjmw)uysq

