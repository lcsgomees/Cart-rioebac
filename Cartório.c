#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca responsável pelas strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
	// Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cpf); // %s Refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); // Salvar o valor da variável
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
		printf("Não foi possível abrir o arquivo, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
		
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
		
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema.\n\n");
		system("pause");	
	}
	
	else
	{
		if(remove(cpf) == 0) // Remove o CPF informado
		printf("\nUsuário deletado com sucesso!\n\n");
		system("pause");
	}
			
}

int main()
{
	int opcao=0; // Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("=== Cartório da EBAC ===\n\n"); // Início do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t 1 - Registrar nomes\n");
		printf("\t 2 - Consultar nomes\n");
		printf("\t 3 - Deletar nomes\n\n");
		printf("\t 4 - Sair do Sistema\n\n");
		printf("Digite aqui o número desejado: "); // Final do menu
		
		scanf("%d", &opcao); // Armazenando as informações
		
		system("cls"); // Responsável por limpar a tela
		
		
		switch(opcao) // Início da seleção do menu
		{
			case 1:
			registro(); // Chamada de funções
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
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
			// Fim da seleção
		}
	}
}
