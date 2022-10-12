#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int opcao = 0;
void TelaMenu();

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    TelaMenu();
    return 0;
}

void TelaMenu()
{
    system("cls");

    FILE *pont_arq;
    int num=0;
    int opc;
    char dsem[50];
    char guar[50];
    char acom[50];
    char salad[50];
    char bebi[50];
    char sobr[50];

    while(num!=5)
    {
        system("cls");
        printf("***MENU PRINCIPAL***\n");
        printf("-------------------------------\n");
        printf("1. CADASTRAR CARDAPIO DO DIA \n");
        printf("2. EXCLUIR CARDAPIO\n");
        printf("3. EXIBIR CARDAPIO\n");
        printf("4. SOBRE O SISTEMA\n");
        printf("-------------------------------\n");
        printf("5. SAIR\n\n");
        printf("Digite a opcao: ");
        scanf("%d", &num);

    switch(num){

        case 1:
        system("cls");
        printf("***CADASTRAR CARDAPIO DO DIA***\n");
        printf("Todas as opcoes acompanham: ARROZ E FEIJAO\n\n");

            printf("GUARNICAO: ");
            fflush(stdin);
            scanf("%[^\n]s", guar);

            printf("ACOMPANHAMENTO: ");
            fflush(stdin);
            scanf("%[^\n]s", acom);

            printf("SALADA: ");
            fflush(stdin);
            scanf("%[^\n]s", salad);

            printf("BEBIDA: ");
            fflush(stdin);
            scanf("%[^\n]s", bebi);

            printf("SOBREMESA: ");
            fflush(stdin);
            scanf("%[^\n]s", sobr);

        while(opc!=2)
            {
            printf("SALVAR CARDAPIO?\n");
            printf("> 1. SIM\n");
            printf("> 2. NAO\n\n");
            printf("Digite a opcao: ");
            scanf("%d\\n", &opc);
            switch(opc){

            case 1:

                printf("\nPARA QUAL DIA DA SEMANA DESEJA CADASTRAR O CARDAPIO?\n");
                fflush(stdin);
                scanf("%[^> \n]s", dsem);

                system("pause");
                break;

                }

                system("cls");
                printf("\n\nCARDAPIO CADASTRADO COM SUCESSO\n");

                system("pause");
                break;

                }

            {
            pont_arq = fopen("CARDAPIO DO DIA.txt", "a");
                fprintf(pont_arq, "------------------------------\n");
                fprintf(pont_arq, "DIA DA SEMANA: %s\n", dsem);
                fprintf(pont_arq, "GUARNICAO: %s\n", guar);
                fprintf(pont_arq, "ACOMPANHAMENTO: %s\n", acom);
                fprintf(pont_arq, "SALADA: %s\n", salad);
                fprintf(pont_arq, "BEBIDA: %s\n", bebi);
                fprintf(pont_arq, "SOBREMESA: %s\n", sobr);
            fclose(pont_arq);
            }

        case 2:
            system("cls");
            printf("---- EXCLUIR CARDAPIO DO DIA ----\n");
            printf("NAO LEMBRO QUAL A CONDICAO PARA EXCLUSAO DE DADOS! TRISTE...\n\n");
            system("pause");
            break;

        case 3:
            system("cls");
            printf("---- EXIBIR CARDAPIO ----\n");
            printf("DIA DA SEMANA: %s\n", dsem);
            printf("------------------------------\n");
            printf("GUARNICAO: %s\n", guar);
            printf("ACOMPANHAMENTO: %s\n", acom);
            printf("SALADA: %s\n", salad);
            printf("BEBIDA: %s\n", bebi);
            printf("SOBREMESA: %s\n", sobr);
            system("pause");
            break;

        case 4:
            system("cls");
            printf("---- SOBRE O SISTEMA ----\n");
            printf(" Sistema estruturado para que o cliente realize o cadastro de um Cardapio do Dia,\n");
            printf(" onde apos definicao do cliente, os produtos sao cadastrados conforme necessidade de negocio.\n");
            printf(" Ficando assim o sistema disponivel para: cadastrar, apagar e exibir o cardapio do dia,\n");
            printf(" como tambem armazenar este cardapio em um arquivo .txt,\n");
            printf(" que apos seu registro ficara armazenado em disco local para consultas posteriores!\n\n");
            printf("-----------------------------------\n");
            printf(" RESPONSAVEIS PELO PROJETO: \n\n");
            printf(" BEATRIZ FRISO - RA: ????\n\n");
            printf(" GUSTAVO VALDO - RA: ????\n\n");
            printf(" JO�S ALMEIDA - RA: ????\n\n");
            printf(" LEONARDO - RA: ????\n\n");
            printf(" RENAN - RA: ????\n\n");
            printf("-----------------------------------\n");
            printf(" MODULO: PRATICA EXTENSIONISTA - ADS - USF \n\n");
            system("pause");
            break;
        }
    }
}

