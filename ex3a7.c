#include <stdio.h>
#include <string.h>


int abertura(FILE * arquivo);
int retangulo(void);
int circulo(void);
int linha(void);
int texto(void);


int main(void){

   char funcao[50] = "";
   
   while(1){

    printf("Escolha a função que deseja executar (Retangulo, Circulo, Linha, Texto) ou F para sair: ");
    scanf("%s", funcao);
    
    if(strcmp(funcao, "Retangulo") == 0){
        retangulo();
    }else if(strcmp(funcao, "Circulo") == 0){
        circulo();
    }else if(strcmp(funcao, "Linha") == 0){
        linha();
    }else if(strcmp(funcao, "Texto") == 0){
        texto();
    }
    
   if(strcmp(funcao, "F") == 0){
        break;
    }
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

int retangulo(void){

    char nome[50] = "";
    int x = 0;
    int y = 0;
    int largura = 0;
    int altura = 0;

     FILE *pArquivo = NULL;

    printf("Digite o nome do arquivo do retangulo: ");
    scanf("%s", nome);
    printf("Digite a posicao X de um retangulo: ");
    scanf("%d", &x);
    printf("Digite a posicao Y de um retangulo: ");
    scanf("%d", &y);
    printf("Digite  a largura (width) do retangulo: ");
    scanf("%d", &largura);
    printf("Digite a altura (height) do retangulo: ");
    scanf("%d", &altura);

    
    pArquivo = fopen(nome, "w");

     if (pArquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    abertura(pArquivo);
    fprintf(pArquivo, "<rect x='%d' y='%d' width='%d' height='%d' fill='red' />", x, y, largura, altura);
    fprintf(pArquivo, "</svg>");

    fclose(pArquivo);

    return 0;}
int circulo(void){


    char nome[50] = "";
    int x = 0;
    int y = 0;
    int raio = 0;

    FILE *pArquivo = NULL;

    printf("Digite o nome do arquivo do circulo: ");
    scanf("%s", nome);
    printf("Digite o centro do circulo na posicao X: ");
    scanf("%d", &x);
    printf("Digite o centro do circulo na posicao Y: ");
    scanf("%d", &y);
    printf("Digite  o raio do circulo: ");
    scanf("%d", &raio);

    
    pArquivo = fopen(nome, "w");

     if (pArquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    abertura(pArquivo);
    fprintf(pArquivo, "<circle cx='%d' cy='%d' r='%d'/>", x, y, raio);
    fprintf(pArquivo, "</svg>");
    fclose(pArquivo);

    return 0;}

int linha(void){

    char nome[50] = "";
    int x = 0;
    int y = 0;
    int largura = 0;
    int altura = 0;

     FILE *pArquivo = NULL;

    printf("Digite o nome do arquivo da linha: ");
    scanf("%s", nome);
    printf("Digite a posicao X da linha: ");
    scanf("%d", &x);
    printf("Digite a posicao Y da  linha: ");
    scanf("%d", &y);
    printf("Digite  a largura (width) da linha: ");
    scanf("%d", &largura);

    
    pArquivo = fopen(nome, "w");

     if (pArquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    abertura(pArquivo);
    fprintf(pArquivo, "<rect x='%d' y='%d' width='%d' height='1' fill='red' />", x, y, largura);
    fprintf(pArquivo, "</svg>");

    fclose(pArquivo);

    return 0;}

int texto(void) {

    char nome[50] = "";
    int x = 0;
    int y = 0;
    char cor[50] = "";
    char texto[50] = "";
    int tamanho = 0;

     FILE *pArquivo = NULL;

    printf("Digite o nome do arquivo do texto: ");
    scanf("%s", nome);
    printf("Digite o texto do arquivo: ");
    scanf("%s", texto);
    printf("Digite a posicao X do texto: ");
    scanf("%d", &x);
    printf("Digite a posicao Y do texto: ");
    scanf("%d", &y);
    printf("Digite  a cor do texto em ingles: ");
    scanf("%s", cor);
    printf("Digite o tamanho do texto: ");
    scanf("%d", &tamanho);

    
    pArquivo = fopen(nome, "w");

     

    if (pArquivo == NULL) {
        printf("Erro: Arquivo não aberto.\n");
        return 0;
    }
    abertura(pArquivo);
    fprintf(pArquivo, "<text x='%d' y='%d' fill='%s' font-size='%d'>%s</text>\n", x, y, cor, tamanho, texto);
    fprintf(pArquivo, "</svg>");
    fclose(pArquivo);


    return 0;
}