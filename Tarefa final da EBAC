#include <stdio.h>      // Biblioteca de Comunicação com o Usuário
#include <stdlib.h>     // Biblioteca de Alocação de Espaço em Memória
#include <locale.h>     // Biblioteca de Alocação de Texto por Região
#include <string.h>     // Biblioteca responsável por cuidar das Strings

int registro()  // Função responsável por cadastrar os usuários no sistema
{
    // Início da criação de variáveis/strings
    char Arquivo[40];
    char CPF[40];
    char Nome[40];
    char Sobrenome[40];
    char Cargo[40];
    // Final da criação de variáveis/strings

    printf("Digite o CPF a ser cadastrado: ");  // Coletando informação do usuário
    scanf("%s", CPF);  // %s refere-se a string

    strcpy(Arquivo, CPF);  // Responsável por copiar os valores das Strings

    FILE *file;  // Cria o arquivo em nosso banco de dados
    file = fopen(Arquivo, "w");  // Cria o arquivo e o "w" significa escrever, que em inglês seria "write"
    fprintf(file, "%s", CPF);  // Salvando valor da variável
    fclose(file);  // Fechar o arquivo

    file = fopen(Arquivo, "a");  // "a" significa que estamos atualizando a informação
    fprintf(file, ",");  // Salvando o valor da variável
    fclose(file);  // Fechando o arquivo

    printf("Digite um nome a ser cadastrado: ");  // Coletando informação do usuário
    scanf("%s", Nome);  // %s refere-se a string (variável)

    file = fopen(Arquivo, "a");  // Abrindo arquivo para atualizar
    fprintf(file, "%s", Nome);  // Salvando novas informações
    fclose(file);  // Fechando arquivo

    printf("Digite o sobrenome a ser cadastrado: ");  // Coletando informações do usuário
    scanf("%s", Sobrenome);  // %s refere-se a string (variável)

    file = fopen(Arquivo, "a");  // Abrindo arquivo para ser atualizado
    fprintf(file, ",%s", Sobrenome);  // %s refere-se a string (Variável)
    fclose(file);  // Fechando o arquivo

    printf("Digite o Cargo a ser cadastrado: ");  // Coletando informação do usuário
    scanf("%s", Cargo);  // %s refere-se a string (Variável)

    file = fopen(Arquivo, "a");  // Abrindo arquivo para ser atualizado
    fprintf(file, ",%s", Cargo);  // %s refere-se a string (Variável)
    fclose(file);  // Fechando o arquivo

    system("pause");  // Pausando textos para que o usuário consiga ler
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");  // Aqui estou definindo a linguagem

    char CPF[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", CPF);

    FILE *file;
    file = fopen(CPF, "r");

    if (file == NULL)
    {
        printf("Não localizamos o CPF.\n");
    }
    else
    {
        while (fgets(conteudo, 200, file) != NULL)
        {
            printf("\n Essas são as informações do usuário:  ");
            printf("%s", conteudo);
            printf("\n\n");
        }
    }

    system("pause");
}

int deletar()
{
    char CPF[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", CPF);

    remove(CPF);

    FILE *file;
    file = fopen(CPF, "r");

    if (file == NULL)
    {
        printf("Usuário não encontrado em sistema ou já deletado.\n");
        system("pause");
    }
}

int main()
{
    int opcao = 0;  // Aqui estou definindo as variáveis
    int x = 1;
    char senhadigitada[] = "a";

    printf("### Cartório da EBAC ###\n\n");  // Aqui é o início do menu
    printf("Login de administrador! \n\n Digite a sua senha: ");
    scanf("%s", senhadigitada);

    if (strcmp(senhadigitada, "admin") == 0)
    {
        for (x = 1; x == 1;)
        {
            system("cls");  // Responsável por limpar a tela

            setlocale(LC_ALL, "Portuguese");  // Aqui estou definindo a linguagem

            printf("### Cartório da EBAC ###\n\n");  // Aqui é o início do menu
            printf("Escolha a opção desejada no menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar os nomes\n");
            printf("\t3 - Deletar os nomes\n");
            printf("\t4 - Sair do sistema\n\n");
            printf("Opção:");  // Aqui é o final do menu

            scanf("%d", &opcao);

            system("cls");  // Responsável por limpar a tela

            switch (opcao)  // Aqui é o início da seleção do usuário
            {
            case 1:
                registro();  // Chamada de funções
                break;
            case 2:
                consulta();  // Chamada de funções
                break;
            case 3:
                deletar();  // Chamada de funções
                break;
            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                return 0;
                break;

            default:
                printf("Opção Inválida!\n");
                system("pause");
            }  // Aqui é o final da seleção do usuário
        }
    }
    else
    {
        printf("\nSenha incorreta");
    }

    return 0;
}
