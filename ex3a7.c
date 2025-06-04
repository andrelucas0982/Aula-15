#include <stdio.h>
#include <string.h>

int abertura(FILE * arquivo);
void retangulo(FILE *pArquivo);
void circulo(FILE *pArquivo);
void linha(FILE *pArquivo);
void texto(FILE *pArquivo);
void fechamento(FILE *pArquivo);

int main(void) {
    char nome[50] = "";

    while (1) {
        printf("Digite o nome do arquivo ou F para sair: ");
        scanf("%s", nome);

        if (strcmp(nome, "F") == 0) {
            break;
        }

        FILE *pArquivo = NULL;
        pArquivo = fopen(nome, "w");

        if (pArquivo == NULL) {
            printf("Erro ao criar/abrir o arquivo.\n");
            continue;
        }
    

        fprintf(pArquivo, "<svg version='1.1' width='300' height='200' xmlns='http://www.w3.org/2000/svg'>");
        retangulo(pArquivo);
        circulo(pArquivo);
        linha(pArquivo);
        texto(pArquivo);

        fechamento(pArquivo);
        fclose(pArquivo);
    }

    return 0;
}

int abertura(FILE * arquivo) {
    int retorno = fprintf(arquivo, "<svg version=\"1.1\" ");

    if (retorno < 0) {
      return 0;
    }

    retorno = fprintf(arquivo, "width=\"300\" height=\"200\" ");

    if (retorno < 0) {
      return 0;
    }

    retorno = fprintf(arquivo, "xmlns=\"http://www.w3.org/2000/svg\">");

    if (retorno < 0) {
      return 0;
    }

    return 1;
  }

void retangulo(FILE *pArquivo) {
    int x, y, largura, altura;

    printf("Digite a posicao X de um retangulo: ");
    scanf("%d", &x);
    printf("Digite a posicao Y de um retangulo: ");
    scanf("%d", &y);
    printf("Digite a largura (width) do retangulo: ");
    scanf("%d", &largura);
    printf("Digite a altura (height) do retangulo: ");
    scanf("%d", &altura);

    fprintf(pArquivo, "  <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" />\n", x, y, largura, altura);
}

void circulo(FILE *pArquivo) {
    int x, y, raio;

    printf("Digite o centro do circulo na posicao X: ");
    scanf("%d", &x);
    printf("Digite o centro do circulo na posicao Y: ");
    scanf("%d", &y);
    printf("Digite o raio do circulo: ");
    scanf("%d", &raio);

    fprintf(pArquivo, "  <circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"blue\" />\n", x, y, raio); 
}

void linha(FILE *pArquivo) {
    int x1, y1, x2, y2;
    char cor[50] = "";

    printf("Digite a posicao inicial X da linha: ");
    scanf("%d", &x1);
    printf("Digite a posicao inicial Y da linha: ");
    scanf("%d", &y1);
    printf("Digite a posicao final X da linha: ");
    scanf("%d", &x2);
    printf("Digite a posicao final Y da linha: ");
    scanf("%d", &y2);
    printf("Digite a cor da linha: ");
    scanf("%s", cor);

    fprintf(pArquivo, "  <line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"2\" />\n", x1, y1, x2, y2, cor);
}

void texto(FILE *pArquivo) {
    int x, y, tamanho;
    char cor[50] = "";
    char texto[50] = "";

    printf("Digite o texto do arquivo: ");
    scanf("%s", texto);
    printf("Digite a posicao X do texto: ");
    scanf("%d", &x);
    printf("Digite a posicao Y do texto: ");
    scanf("%d", &y);
    printf("Digite a cor do texto em ingles: ");
    scanf("%s", cor);
    printf("Digite o tamanho do texto: ");
    scanf("%d", &tamanho);

    fprintf(pArquivo, "  <text x=\"%d\" y=\"%d\" fill=\"%s\" font-size=\"%d\">%s</text>\n", x, y, cor, tamanho, texto);
}

void fechamento(FILE *pArquivo) {
    fprintf(pArquivo, "</svg>\n");
}
