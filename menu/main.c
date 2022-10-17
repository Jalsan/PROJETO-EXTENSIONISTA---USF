#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define numberOfControlOptions 5
#define maxLength 100
#define daysOfWeek 7

typedef struct
{
    int numberOfMenus;
    char mainFood[daysOfWeek][maxLength];
    char sideDish[daysOfWeek][maxLength];
    char salad[daysOfWeek][maxLength];
    char drink[daysOfWeek][maxLength];
    char dessert[daysOfWeek][maxLength];
    char* defaultFood;
    char dayOfWeek[daysOfWeek][maxLength];
}  Menu;

int chooseMenuControlOptions()
{
    int option;
    char menuControlOptions[numberOfControlOptions][maxLength] =
    {
        {"1. CADASTRAR CARDAPIO DO DIA"},
        {"2. EXCLUIR CARDAPIO"},
        {"3. EXIBIR CARDAPIO"},
        {"4. SOBRE O SISTEMA"},
        {"5. SAIR"}
    };

    printf("***MENU PRINCIPAL***\n\n");
    for(int i = 0; i < numberOfControlOptions; i++)
    {
        printf(menuControlOptions[i]);
        printf("\n");
    }
    printf("\nDigite a opcao: ");
    scanf("%d", &option);

    while(verifyOption(option) != 1)
    {
        printf("Digite uma opcao Valida! \n");
        scanf("%d", &option);
    }

    return option;
}

int verifyOption(int option)
{
    for(int i = 1; i < numberOfControlOptions + 1; i++)
    {
        if(option == i)
        {
            return 1;
        }
    }
    return 0;
}

Menu registerMenu()
{
    Menu menu;

    system("cls");
    printf("***CADASTRAR CARDAPIO DO DIA***\n");
    printf("Todas as opcoes acompanham: ARROZ E FEIJAO\n\n");

    printf("Quantos Cardapios deseja criar: ");
    scanf("%i", &menu.numberOfMenus);

    for(int i = 0; i < menu.numberOfMenus; i++)
    {
        printf("\n-----------------\n");
        printf("GUARNICAO: ");
        fflush(stdin);
        gets(menu.mainFood[i]);
        printf("ACOMPANHAMENTO: ");
        gets(menu.sideDish[i]);
        printf("SALADA: ");
        gets(menu.salad[i]);
        printf("BEBIDA: ");
        gets(menu.drink[i]);
        printf("SOBREMESA: ");
        gets(menu.dessert[i]);
        printf("Dia da semana: ");
        gets(menu.dayOfWeek[i]);
    }
    menu.defaultFood = "Arroz e Feijao";
    return menu;
}

void showMenu(Menu menu, char fileDescription[])
{

    FILE *file = fopen(fileDescription, "rt");
    char row[200];
    char *result;
    int i;

    printf("\n");
    if(file)
    {
        while (!feof(file))
        {
            result = fgets(row, 200, file);
            if(result)
            {
                printf("%s", row);
                i++;
            }
        }
        fclose(file);
    }
    else
    {
        printf("Erro ao ler o arquivo!");
    }
    printf("\n");
}

int questionToSaveOrNotMenu()
{
    int option;
    printf("\n\nSALVAR CARDAPIO?\n");
    printf("> 1. SIM\n");
    printf("> 2. NAO\n\n");
    printf("Digite a opcao: ");
    scanf("%d\\n", &option);
    printf("\n");

    if(option == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void saveMenu(Menu menu, char fileDescription[])
{
    int option = questionToSaveOrNotMenu();

    if(option == 1)
    {
        FILE *fileTarget;
        fileTarget = fopen(fileDescription, "a");
            for(int i = 0; i < menu.numberOfMenus; i++)
            {
                fprintf(fileTarget, "------------------------------\n");
                fprintf(fileTarget, "DIA DA SEMANA: %s\n", menu.dayOfWeek[i]);
                fprintf(fileTarget, "Comida comum: %s\n", menu.defaultFood);
                fprintf(fileTarget, "GUARNICAO: %s\n", menu.mainFood[i]);
                fprintf(fileTarget, "ACOMPANHAMENTO: %s\n", menu.sideDish[i]);
                fprintf(fileTarget, "SALADA: %s\n", menu.salad[i]);
                fprintf(fileTarget, "BEBIDA: %s\n", menu.drink[i]);
                fprintf(fileTarget, "SOBREMESA: %s\n", menu.dessert[i]);
            }
        fclose(fileTarget);
        printf("Menu cadastrado!\n\n");
    }
    else
    {
        printf("O Menu não foi cadastrado!\n\n");
    }
}

void deleteMenu(char fileDescription[])
{
    int status = remove(fileDescription);

    if(status == 0)
    {
        printf("O Arquivo foi excluido com sucesso!\n\n");
    }
    else
    {
        printf("O arquivo nao existe!\n\n");
    }
}

void aboutUs()
{
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
    printf(" JO S ALMEIDA - RA: ????\n\n");
    printf(" LEONARDO - RA: ????\n\n");
    printf(" RENAN - RA: ????\n\n");
    printf("-----------------------------------\n");
    printf(" MODULO: PRATICA EXTENSIONISTA - ADS - USF \n\n");
}

void menuInterface()
{
    backPoint:
    system("cls");
    int menuOptioncontrol = chooseMenuControlOptions();
    char fileDescription[] = "CARDAPIO DO DIA.txt";
    Menu menu;

    switch(menuOptioncontrol)
    {
        case 1:
            menu = registerMenu();
            saveMenu(menu, fileDescription);
            system("pause");
            goto backPoint;
            break;
        case 2:
            deleteMenu(fileDescription);
            system("pause");
            goto backPoint;
            break;
        case 3:
            showMenu(menu, fileDescription);
            system("pause");
            goto backPoint;
            break;
        case 4:
            aboutUs();
            system("pause");
            goto backPoint;
            break;
        case 5:
            break;
    }
}

int main()
{
    menuInterface();
    return 0;
}
