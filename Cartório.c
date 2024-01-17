#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o
#include <string.h> // Biblioteca respons�vel pelas strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); // %s Refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); // Salvar o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fprintf(file, nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fprintf(file, sobrenome);
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
		
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");

}

int consulta() 
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
		
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
		
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema.\n\n");
		system("pause");	
	}
	
	else
	{
		if(remove(cpf) == 0) // Remove o CPF informado
		printf("\nUsu�rio deletado com sucesso!\n\n");
		system("pause");
	}
			
}

int main()
{
	int opcao=0; // Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("=== Cart�rio da EBAC ===\n\n"); // In�cio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t 1 - Registrar nomes\n");
		printf("\t 2 - Consultar nomes\n");
		printf("\t 3 - Deletar nomes\n\n");
		printf("\t 4 - Sair do Sistema\n\n");
		printf("Digite aqui o n�mero desejado: "); // Final do menu
		
		scanf("%d", &opcao); // Armazenando as informa��es
		
		system("cls"); // Respons�vel por limpar a tela
		
		
		switch(opcao) // In�cio da sele��o do menu
		{
			case 1:
			registro(); // Chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
									
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			// Fim da sele��o
		}
	}
}
