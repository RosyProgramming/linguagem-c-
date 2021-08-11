#include <stdio.h>
#include <stdlib.h>

struct elemFila
{
    char alf;
    struct elemFila *proximo;
};

typedef struct Fila{
    int tamanho_maximo;
    struct elemFila *inicio;
    struct elemFila *final;
} Fila;

//Função para inicialização da Fila;
Fila *criarFila(int tamanho_maximo)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->tamanho_maximo = tamanho_maximo;
    fila->final = NULL;
    fila->inicio = NULL;

    return fila;
}

int fila_vazia(Fila *fila)
{
    int quantidade;
    elemFila *elemFila = fila->inicio;

    for (quantidade = 0; elemFila != NULL; quantidade++)
    {
        elemFila = elemFila->proximo;
    }

    return quantidade;
}

int fila_Cheia(Fila *fila)
{
    if (fila_vazia(fila) < fila->tamanho_maximo)
    {
        return 0;
    }

    return 1;
}


//Função para inserir um novo elemento na Fila;
int inserir_elemento(Fila *fila, char valor)
{
     elemFila *elemFila;

    if (fila_Cheia(fila))
    {
        printf("\nOPERACAO BLOQUEADA: Fila cheia!\n");
        return 0;
    }
    
     elemFila = (elemFila *)malloc(sizeof(elemFila));
     Fila -> dado = valor;
     Fila -> proximo = NULL;

    if (fila->final == NULL) {
        fila->inicio = elemFila;
    } else {
        fila->final->proximo =  elemFila;
    }
    fila->final =  elemFila;

    return 1;
}

//Função para remover um novo elemento da Fila;
int remover_elemento(Fila *fila)
{
     elemFila *elemFila;

    elemFila = fila->inicio;
    fila->inicio =  elemFila->proximo;
    free(elemFila);

    return 1;
}

//Função para imprimir os elementos da Fila.
int exibir_Fila(Fila *fila)
{
    int i;
    No * elemFila_atual = fila-> inicio;

    printf("\nFILA: {");

    for (i = 0;  elemFila_atual != NULL; i++)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%c",  elemFila_atual->dado);

         elemFila_atual =  elemFila_atual -> proximo;
    }

}

int menu()
{
    int opcao;

    printf("\n ======== MENU ========\n");
    printf("1 - INSERIR ELEMENTO NA FILA\n");
    printf("2 - REMOVER ELEMENTO DA FILA\n");
    printf("3 - EXIBIR A FILA\n");
    printf("\n0 - SAIR\n");
    printf("\n === INSIRA UMA DAS OPCOES:==== ");

    scanf("%d", &opcao);

    return opcao;
}

int main()
{
    int opcao;

    Fila *fila;

    char valor;

    fila = criarFila(10);

    while (1)
    {
        opcao = menu();

        if (opcao == 1)
        {
            printf("Insira uma letra: ");
            scanf(" %c", &valor);

            inserir_elemento(fila, valor);
        }
        else if (opcao == 2)
        {
            remover_elemento(fila);
        }
        else if (opcao == 3)
        {
            exibir_Fila(fila);
        }
        else if (opcao == 0)
        {
            break;
        }
        else
        {
            printf("\nOPCAO INVALIDA!\n");
        }

        printf("\n");
        system("pause");
    }
}
