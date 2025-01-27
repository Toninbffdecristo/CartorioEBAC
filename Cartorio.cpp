#include <stdio.h> //Essa biblioteca em especifico serve para comunicação com o usúario
#include <stdlib.h> //Essa biblioteca de alocação de espaço em memória 
#include <locale.h> //bibliote de alocação de texto po região
#include <string.h> //Bibliote resposavel pelas strings

int registrar()
{
	//printf("você escolheu o registro de nomes!\n") 
	//system("pause");
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: "); // CPF
	scanf("%s", cpf); //Armazena a string
	
	strcpy(arquivo, cpf); //Responsavel pelo valor da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); //Salva o valor do arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); // NOME
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // SOBRENOME
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); // CARGO
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	char *token;	 
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); // Armazenando a variavel "cpf" utilizando a função string "%s"
  	
	FILE *file;
	file = fopen(cpf,"r"); // Abre o arquivo cpf e o lê usando "r" ( Read ) para localizar todos e mostrar os dados
  	
  	
  	
	if(file == NULL)
	{
		printf(" Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // While = enquanto, enquanto for esses dados seguir as funções caso não será nulo ( NULL )
	{
		printf("\nEssas são as informações do usuário: \n");
		
		token = strtok(conteudo, ",");
		printf("CPF: %s\n",token);
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n",token);
		
		token = strtok(NULL, ",");
		printf("Sobrenome: %s\n",token);
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n",token);
		
	}
  	printf("\n");
	system ("pause");
}	

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;

  file = fopen(cpf, "r"); // Tenta abrir o arquivo para leitura

	if (file == NULL) 
	{
   		printf("O usuário não existe!\n");
   		system("pause");

  	} 

	else
  	{
    	remove(cpf); 
  		printf("Usuário deletado!\n");
   		system("pause");
		
		fclose(file);
  }
}

int main()
{
	int opcao=0; //Definindo a Variavel
	int laco=1;
	
	while(laco=1)
	{
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a lingua
	
		printf("### Catório da EBAC ###\n\n"); //Inico Menu
		printf("Escolha a opção desejada:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:  ");//Fim menu
		///printf("Esse software é uso de Anthony S. Fonseca"); essa opção voltará mais tarde
	
		scanf("%d", &opcao); //Armazendando escolha usuario
	
		system("cls"); //Comando do Win para limpar tela do usuario
	
		switch(opcao)
		{
			case 1:
			registrar();
			break;
	
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			default:
			printf("Está opção não está disponivel!\n\n");
			system("pause");
			break;
			}//Fim da sessão
		
		system("cls");
	}
}
