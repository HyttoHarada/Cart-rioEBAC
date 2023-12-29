#include <stdio.h>//Biblioteca de Comunica��o com o Usu�rio
#include <stdlib.h>//Biblioteca de Aloca��o de Espa�o em Mem�ria
#include <locale.h>//Biblioteca de Aloca��o de Texto por Regi�o
#include <string.h>// Biblioteca respons�vel por cuidar das String

int registro()//Fun��o respons�vel por cadastrar os usuarios no sistema
{
	//Inicio da cria��o de vari�veis/string
    char Arquivo[40];   
    char CPF[40];
    char Nome[40];
    char Sobrenome[40];
    char Cargo[40];
    //Final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: ");//Coletando informa��o do usu�rio
    scanf("%s", CPF);//%s refere-se a string
     
    strcpy(Arquivo, CPF);//Respons�vel por copiar os valores das String
     
    FILE *file;//Cria o arquivo em nosso banco de dados
    file = fopen(Arquivo,"w");//Cria o arquivo e o "w" significa escrever, que ingl�s seria "write"
    fprintf(file, "%s", CPF);//Salvando valor da var�avel
    fclose(file);//Fechar o arquivo
     
    file = fopen(Arquivo, "a");// "a" significa que estamos atualizando a informa��o
    fprintf(file, ",");//Salvando o valor da vari�vel
    fclose(file);//Fechando o arquivo
     
    printf("Digite um nome a ser cadastrado: ");//Coletando informa��o do usu�rio
    scanf("%s", Nome);// %s refere-se a string(variavel)
     
    file = fopen(Arquivo,"a");//Abrindo arquivo para atualizar
    fprintf(file, "%s", Nome);//Salvando novas informa��es
    fclose(file);//Fechando arquivo
     
    printf("Digite o sobrenome a ser cadastrado: ");//Coletando informa��es do usu�rio
    scanf("%s", Sobrenome);//%s refere-se a string(variavel)
     
    file = fopen(Arquivo, "a");//Abrindo arquivo para ser atualizado
    fprintf(file, "%s", Sobrenome);//%s refere-se a string (Variavel)
    fclose(file);//Fechando o arquivo
     
    printf("Digite o Cargo a ser cadastrado: ");//coletando informa��o do usu�rio
    scanf("%s", Cargo);//%s refere-se a string (Variavel)
     
    file = fopen(Arquivo, "a");//Abrindo arquivo para ser atualizado
    fprintf(file, "%s", Cargo);//%s refere-se a string (Variavel)
    fclose(file);//Fechando o arquivo
     
    system("pause");//pausando textos para que o usu�rio consiga ler
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");//Aqui estou definindo a linguagem
	    
    char CPF[40];
    char conteudo[200];
	    
    printf("Digite o CPF a ser consultado");
    scanf("%s",CPF);
	    
    FILE *file;
    file = fopen(CPF,"r");
	    
    if(file == NULL)
    {
        printf("N�o localizamos o CPF. \n");	
    }
    else
    {
        while(fgets(conteudo, 200, file) != NULL)
        {
            printf("\n Essas s�o as informa��es do usu�rio:  ");
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
    scanf("%s",CPF);
    
    remove(CPF);
    
    FILE *file;
    file = fopen(CPF, "r");
    
    
    if(file == NULL)
    {
    	printf("Usu�rio n�o encontrado em sistema ou j� deletado. \n");
    	system("pause");
	}
    
}

int main() 
{
    int opcao = 0;//Aqui estou definindo as variaveis
    int x = 1;

    for (x = 1; x == 1;) 
    {
        system("cls");//Respons�vel por limpar a tela
        
        setlocale(LC_ALL, "Portuguese");//Aqui estou definindo a linguagem

        printf("### Cart�rio da EBAC ###\n\n");//Aqui � o inicio do menu
        printf("Escolha a op��o desejada no menu:\n\n");        
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar os nomes\n");
        printf("\t3 - Deletar os nomes\n\n");
        printf("Op��o:");//Aqui � o final do menu

        scanf("%d", &opcao);

        system("cls");//Respons�vel por limpar a tela

        switch (opcao) //Aqui � o inicio da sele��o do usu�rio
        {
            case 1:
                registro();//Chamada de fun��es
                break;     
            case 2:
                consulta();//Chamada de fun��es
                break;                
            case 3:
                deletar();//Chamada de fun��es
                break;          
                
            default:
                printf("Op��o Inv�lida!\n");
                system("pause");
        }//Aqui � o final da sele��o do usu�rio
    }

    return 0;
}
