#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

void setTimeout(int milliseconds) // contagem de tempo [função auxiliar]
{
    if (milliseconds <= 0)
    {
        fprintf(stderr, "Count milliseconds for timeout is less or equal to 0\n");
        return;
    }
    int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    int end = milliseconds_since + milliseconds;

    do
    {
        milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    }
    while (milliseconds_since <= end);
}

int chartoint(char s[]) // atribuir inteiro a uma string ou char [função auxiliar]
{
    int i, n = 0;
    for (i = 0; isdigit(s[i]); ++i)
    {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

void menu_principal(char* input[], int* cod)// menu principal
{
    do
    {
        printf("\n---------Restaurante----------\n");
        printf("\n        Menu Principal        \n");
        printf("\nSEÇÃO.....................CÓDIGO\n");
        printf("Massas........................10\n");//
        printf("Vegetariano...................20\n");//
        printf("Sopas.........................30\n");//
        printf("Carnes........................40\n");//
        printf("Bebidas.......................50\n");//
        printf("Sobremesa.....................60\n");//
        printf("\nDigite o código da seção ou 1 para finalizar a compra:\n");
        scanf("%199s", input);
        *cod = chartoint(input);
        system("cls");
        if (*cod != 1 && *cod != 10 && *cod != 20 && *cod != 30 && *cod != 40 && *cod != 50 && *cod != 60)
        {
            printf("\nCódigo inválido, retornando...\n");
            setTimeout(2000);
            system("cls");
        }
    }
    while (*cod != 1 && *cod != 10 && *cod != 20 && *cod != 30 && *cod != 40 && *cod != 50 && *cod != 60);
}

void submenu_massas(char* input[], int* cod, int* macarrao_carbo, int* macarrao_bolo, int* lasanha)//submenu 1
{
    do
    {
        printf("\n----------------Seção: Massas----------------\n");
        printf("\nPRODUTO...............CÓDIGO.......PREÇO..Qtd\n");
        printf("Macarrão a Carbonara.....100....R$.18,90..x%d\n", *macarrao_carbo);
        printf("Macarrão a Bolonhesa.....101....R$.17,90..x%d\n", *macarrao_bolo);
        printf("Lasanha..................102....R$.19,90..x%d\n", *lasanha);
        printf("\nDigite o código do prato ou 1 para voltar ao menu principal:\n");
        scanf("%199s", input);
        *cod = chartoint(input);
        system("cls");
        if (*cod != 1 && *cod < 100 || *cod > 102)
        {
            printf("\nCódigo inválido, retornando...\n");
            setTimeout(2000);
            system("cls");
        }
    }
    while (*cod != 1 && (*cod < 100 || *cod > 102));
}

void submenu_vegetariano(char* input[], int* cod, int* hamburguer_soja, int* tortilha_bat, int* salada_ceasar)//submenu 2
{
    do
    {
        printf("\n----------------Seção: Vegetarianos----------------\n");
        printf("\nPRODUTO................CÓDIGO.......PREÇO..Qtd\n");
        printf("Hamburguer de Soja........200....R$.12,50..x%d\n", *hamburguer_soja);
        printf("Tortilha de batata........201....R$..9,90..x%d\n", *tortilha_bat);
        printf("Salada Ceasar.............202....R$.11,90..x%d\n", *salada_ceasar);
        printf("\nDigite o código do produto ou 1 para voltar ao menu principal:\n");
        scanf("%199s", input);
        *cod = chartoint(input);
        system("cls");
        if (*cod != 1 && (*cod < 200 || *cod > 202))
        {
            printf("\nCódigo inválido, retornando...\n");
            setTimeout(2000);
            system("cls");
        }
    }
    while (*cod != 1 && (*cod < 200 || *cod > 202));
}

void submenu_sopas(char* input[], int* cod, int* sopa_frango, int* sopa_carne, int* sopa_legumes)//submenu 3
{
    do
    {
        printf("\n----------------Seção: Sopas----------------\n");
        printf("\nPRODUTO..............CÓDIGO.......PREÇO..Qtd\n");
        printf("Sopa de Frango..........300....R$.10,90..x%d\n", *sopa_frango);
        printf("Sopa de Carne...........301....R$.11,50..x%d\n", *sopa_carne);
        printf("Sopa de Legumes.........302....R$..9,50..x%d\n", *sopa_legumes);
        printf("\nDigite o código do produto ou 1 para voltar ao menu principal:\n");
        scanf("%199s", input);
        *cod = chartoint(input);
        system("cls");
        if (*cod != 1 && (*cod < 300 || *cod > 302))
        {
            printf("\nCódigo inválido, retornando...\n");
            setTimeout(2000);
            system("cls");
        }
    }
    while (*cod != 1 && (*cod < 300 || *cod > 302));
}

void submenu_carnes(char* input[], int* cod, int* carne_bovina, int* frango, int* porco)//submenu 4
{
    do
    {
        printf("\n----------------Seção: Carnes----------------\n");
        printf("\nPRODUTO..............CÓDIGO.......PREÇO..Qtd\n");
        printf("Carne Bovina kg.........400....R$.39,90..x%d\n", *carne_bovina);
        printf("Frango kg...............401....R$.12,90..x%d\n", *frango);
        printf("Carne Suína kg..........402....R$.29,90..x%d\n", *porco);
        printf("\nDigite o código do produto ou 1 para voltar ao menu principal:\n");
        scanf("%199s", input);
        *cod = chartoint(input);
        system("cls");
        if (*cod != 1 && (*cod < 400 || *cod > 402))
        {
            printf("\nCódigo inválido, retornando...\n");
            setTimeout(2000);
            system("cls");
        }
    }
    while (*cod != 1 && (*cod < 400 || *cod > 402));
}

void submenu_bebidas(char* input[], int* cod, int* suco, int* refrigerante, int* agua)//submenu 5
{
    do
    {
        printf("\n----------------Seção: Bebidas----------------\n");
        printf("\nPRODUTO..............CÓDIGO......PREÇO..Qtd\n");
        printf("Suco 500mL..............500....R$.6,50...x%d\n", *suco);
        printf("Refrigerante Lata.......501....R$.4,50...x%d\n", *refrigerante);
        printf("Água Mineral............502....R$.2,00...x%d\n", *agua);
        printf("\nDigite o código do prato ou 1 para voltar ao menu principal:\n");
        scanf("%199s", input);
        *cod = chartoint(input);
        system("cls");
        if (*cod != 1 && (*cod < 500 || *cod > 502))
        {
            printf("\nCódigo inválido, retornando...\n");
            setTimeout(2000);
            system("cls");
        }
    }
    while (*cod != 1 && (*cod < 500 || *cod > 502));
}

void submenu_sobremesas(char* input[], int* cod, int* bolo, int* petit_gateau, int* mousse)//submenu 6
{
    do
    {
        printf("\n----------------Seção: Sobremesas----------------\n");
        printf("\nPRODUTO..............CÓDIGO.......PREÇO..Qtd\n");
        printf("Bolo....................600....R$..7,90..x%d\n", *bolo);
        printf("Petit Gateau............601....R$.14,90..x%d\n", *petit_gateau);
        printf("Mousse..................602....R$..6,90..x%d\n", *mousse);
        printf("\nDigite o código do produto ou 1 para voltar ao menu principal:\n");
        scanf("%199s", input);
        *cod = chartoint(input);
        system("cls");
        if (*cod != 1 && (*cod < 600 || *cod > 602))
        {
            printf("\nCódigo inválido, retornando...\n");
            setTimeout(2000);
            system("cls");
        }
    }
    while (*cod != 1 && (*cod < 600 || *cod > 602));
}

void resumo(int* macarrao_carbo, int* macarrao_bolo, int* lasanha,
            int* hamburguer_soja, int* tortilha_bat, int* salada_ceasar,
            int* sopa_frango, int* sopa_carne, int* sopa_legumes,
            int* carne_bovina, int* frango, int* porco,
            int* suco, int* refrigerante, int* agua,
            int* bolo, int* petit_gateau, int* mousse)
{
    printf("\n------ RESUMO DO PEDIDO ------\n\n");

    if (*macarrao_carbo > 0)
    {
        printf("Macarrão ao Carbonara: Massa com molho à base de ovos, queijo e bacon\n");
        printf("%d x R$18,90 = R$%.2f\n\n", *macarrao_carbo, *macarrao_carbo * 18.90);
    }
    if (*macarrao_bolo > 0)
    {
        printf("Macarrão à Bolonhesa: Massa com molho de carne moída e tomate\n");
        printf("%d x R$17,90 = R$%.2f\n\n", *macarrao_bolo, *macarrao_bolo * 17.90);
    }
    if (*lasanha > 0)
    {
        printf("Lasanha: Prato em camadas com massa, molho e recheio de carne e queijo\n");
        printf("%d x R$19,90 = R$%.2f\n\n", *lasanha, *lasanha * 19.90);
    }
    if (*hamburguer_soja > 0)
    {
        printf("Hambúrguer de Soja: Alternativa vegetariana feita com base vegetal\n");
        printf("%d x R$12,50 = R$%.2f\n\n", *hamburguer_soja, *hamburguer_soja * 12.50);
    }
    if (*tortilha_bat > 0)
    {
        printf("Tortilha de Batata: Omelete estilo espanhol com batatas\n");
        printf("%d x R$9,90 = R$%.2f\n\n", *tortilha_bat, *tortilha_bat * 9.90);
    }
    if (*salada_ceasar > 0)
    {
        printf("Salada Ceasar: Alface, croutons, parmesão e molho especial\n");
        printf("%d x R$11,90 = R$%.2f\n\n", *salada_ceasar, *salada_ceasar * 11.90);
    }
    if (*sopa_frango > 0)
    {
        printf("Sopa de Frango: Caldo quente com pedaços de frango\n");
        printf("%d x R$10,90 = R$%.2f\n\n", *sopa_frango, *sopa_frango * 10.90);
    }
    if (*sopa_carne > 0)
    {
        printf("Sopa de Carne: Caldo nutritivo com carne bovina\n");
        printf("%d x R$11,50 = R$%.2f\n\n", *sopa_carne, *sopa_carne * 11.50);
    }
    if (*sopa_legumes > 0)
    {
        printf("Sopa de Legumes: Leve e saudável, feita com legumes variados\n");
        printf("%d x R$9,50 = R$%.2f\n\n", *sopa_legumes, *sopa_legumes * 9.50);
    }
    if (*carne_bovina > 0)
    {
        printf("Carne Bovina: Corte grelhado ou assado de boi\n");
        printf("%d x R$39,90 = R$%.2f\n\n", *carne_bovina, *carne_bovina * 39.90);
    }
    if (*frango > 0)
    {
        printf("Frango: Opção de carne branca, grelhada ou assada\n");
        printf("%d x R$12,90 = R$%.2f\n\n", *frango, *frango * 12.90);
    }
    if (*porco > 0)
    {
        printf("Carne Suína: Sabor marcante, preparada ao forno ou grelhada\n");
        printf("%d x R$29,90 = R$%.2f\n\n", *porco, *porco * 29.90);
    }
    if (*suco > 0)
    {
        printf("Suco Natural 500ml: Bebida natural e refrescante\n");
        printf("%d x R$6,50 = R$%.2f\n\n", *suco, *suco * 6.50);
    }
    if (*refrigerante > 0)
    {
        printf("Refrigerante Lata: Bebida gaseificada tradicional\n");
        printf("%d x R$4,50 = R$%.2f\n\n", *refrigerante, *refrigerante * 4.50);
    }
    if (*agua > 0)
    {
        printf("Água Mineral: Opção saudável e essencial\n");
        printf("%d x R$2,00 = R$%.2f\n\n", *agua, *agua * 2.00);
    }
    if (*bolo > 0)
    {
        printf("Bolo Fatia: Fatia de bolo, sabor variável\n");
        printf("%d x R$7,90 = R$%.2f\n\n", *bolo, *bolo * 7.90);
    }
    if (*petit_gateau > 0)
    {
        printf("Petit Gateau: Bolinho quente com recheio de chocolate, servido com sorvete\n");
        printf("%d x R$14,90 = R$%.2f\n\n", *petit_gateau, *petit_gateau * 14.90);
    }
    if (*mousse > 0)
    {
        printf("Mousse: Sobremesa aerada, geralmente de chocolate ou maracujá\n");
        printf("%d x R$6,90 = R$%.2f\n\n", *mousse, *mousse * 6.90);
    }
}

int main()//função principal
{
    setlocale(LC_ALL, "Portuguese");
    float total, total_armazenado;
    char input[200], input_2[200];
    int fimouvolta, cod,
        macarrao_carbo = 0, macarrao_bolo = 0, lasanha = 0,
        hamburguer_soja = 0, tortilha_bat = 0, salada_ceasar = 0,
        sopa_frango = 0, sopa_carne = 0, sopa_legumes = 0,
        carne_bovina = 0, frango = 0, porco = 0,
        suco = 0, refrigerante = 0, agua = 0,
        bolo = 0, petit_gateau = 0, mousse = 0;

    do
    {
        macarrao_carbo = 0, macarrao_bolo = 0, lasanha = 0,
        hamburguer_soja = 0, tortilha_bat = 0, salada_ceasar = 0,
        sopa_frango = 0, sopa_carne = 0, sopa_legumes = 0,
        carne_bovina = 0, frango = 0, porco = 0,
        suco = 0, refrigerante = 0, agua = 0,
        bolo = 0, petit_gateau = 0, mousse = 0;

        menu_principal(&input, &cod);
        while (cod != 1)
        {
            switch (cod)
            {
            case 10:
                submenu_massas(&input, &cod, &macarrao_carbo, &macarrao_bolo, &lasanha);
                while (cod != 1)
                {
                    switch (cod)
                    {
                    case 100:
                        macarrao_carbo++;
                        break;
                    case 101:
                        macarrao_bolo++;
                        break;
                    case 102:
                        lasanha++;
                        break;
                    }
                    submenu_massas(&input, &cod, &macarrao_carbo, &macarrao_bolo, &lasanha);
                }
                break;
            case 20:
                submenu_vegetariano(&input, &cod, &hamburguer_soja, &tortilha_bat, &salada_ceasar);
                while (cod != 1)
                {
                    switch (cod)
                    {
                    case 200:
                        hamburguer_soja++;
                        break;
                    case 201:
                        tortilha_bat++;
                        break;
                    case 202:
                        salada_ceasar++;
                        break;
                    }
                    submenu_vegetariano(&input, &cod, &hamburguer_soja, &tortilha_bat, &salada_ceasar);
                }
                break;
            case 30:
                submenu_sopas(&input, &cod, &sopa_frango, &sopa_carne, &sopa_legumes);
                while (cod != 1)
                {
                    switch (cod)
                    {
                    case 300:
                        sopa_frango++;
                        break;
                    case 301:
                        sopa_carne++;
                        break;
                    case 302:
                        sopa_legumes++;
                        break;
                    }
                    submenu_sopas(&input, &cod, &sopa_frango, &sopa_carne, &sopa_legumes);
                }
                break;
            case 40:
                submenu_carnes(&input, &cod, &carne_bovina, &frango, &porco);
                while (cod != 1)
                {
                    switch (cod)
                    {
                    case 400:
                        carne_bovina++;
                        break;
                    case 401:
                        frango++;
                        break;
                    case 402:
                        porco++;
                        break;
                    }
                    submenu_carnes(&input, &cod, &carne_bovina, &frango, &porco);
                }
                break;
            case 50:
                submenu_bebidas(&input, &cod, &suco, &refrigerante, &agua);
                while (cod != 1)
                {
                    switch (cod)
                    {
                    case 500:
                        suco++;
                        break;
                    case 501:
                        refrigerante++;
                        break;
                    case 502:
                        agua++;
                        break;
                    }
                    submenu_bebidas(&input, &cod, &suco, &refrigerante, &agua);
                }
                break;
            case 60:
                submenu_sobremesas(&input, &cod, &bolo, &petit_gateau, &mousse);
                while (cod != 1)
                {
                    switch (cod)
                    {
                    case 600:
                        bolo++;
                        break;
                    case 601:
                        petit_gateau++;
                        break;
                    case 602:
                        mousse++;
                        break;
                    }
                    submenu_sobremesas(&input, &cod, &bolo, &petit_gateau, &mousse);
                }
                break;
            }
            menu_principal(&input, &cod);
        }
        float total = (macarrao_carbo * 18.90) + (macarrao_bolo * 17.90) + (lasanha * 19.90) +
                      (hamburguer_soja * 12.50) + (tortilha_bat * 9.90) + (salada_ceasar * 11.90) +
                      (sopa_frango * 10.90) + (sopa_carne * 11.50) + (sopa_legumes * 9.50) +
                      (carne_bovina * 39.90) + (frango * 12.90) + (porco * 29.90) +
                      (suco * 6.50) + (refrigerante * 4.50) + (agua * 2.00) +
                      (bolo * 7.90) + (petit_gateau * 14.90) + (mousse * 6.90);
        total_armazenado = total;

        do
        {
            resumo(&macarrao_carbo, &macarrao_bolo, &lasanha,
                   &hamburguer_soja, &tortilha_bat, &salada_ceasar,
                   &sopa_frango, &sopa_carne, &sopa_legumes,
                   &carne_bovina, &frango, &porco,
                   &suco, &refrigerante, &agua,
                   &bolo, &petit_gateau, &mousse);
            printf("TOTAL A PAGAR: R$%.2f\n", total);
            printf("\nDeseja finalizar o pedido ou zerar o carrinho e voltar ao menu? [1 - Finalizar] [2 - Voltar]:\n");
            scanf("%s", &input_2);
            fimouvolta = chartoint(input_2);
            system("cls");
            if (fimouvolta < 1 || fimouvolta > 2)
            {
                printf("\nValor incorreto, retornando...\n");
                setTimeout(2000);
                system("cls");
            }
        }
        while (fimouvolta < 1 || fimouvolta > 2);

        if (fimouvolta == 2)
        {
            printf("\nZerando e retornando...\n");
            setTimeout(2000);
            system("cls");
        }
    }
    while (fimouvolta == 2);

    if (fimouvolta == 1)
    {
        resumo(&macarrao_carbo, &macarrao_bolo, &lasanha,
               &hamburguer_soja, &tortilha_bat, &salada_ceasar,
               &sopa_frango, &sopa_carne, &sopa_legumes,
               &carne_bovina, &frango, &porco,
               &suco, &refrigerante, &agua,
               &bolo, &petit_gateau, &mousse);
        printf("TOTAL A PAGAR: R$%.2f\n", total_armazenado);
        printf("\nAgradecemos sua compra!\n");
    }
    return 0;
}
