#include <stdio.h> //Essa biblioteca em especifico serve para comunica��o com o us�ario
#include <stdlib.h> //Essa biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //bibliote de aloca��o de texto po regi�o
#include <string.h> //Bibliote resposavel pelas strings

int registrar()
{
	//printf("voc� escolheu o registro de nomes!\n") 
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
	scanf("%s",cpf); // Armazenando a variavel "cpf" utilizando a fun��o string "%s"
  	
	FILE *file;
	file = fopen(cpf,"r"); // Abre o arquivo cpf e o l� usando "r" ( Read ) para localizar todos e mostrar os dados
  	
  	
  	
	if(file == NULL)
	{
		printf(" N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // While = enquanto, enquanto for esses dados seguir as fun��es caso n�o ser� nulo ( NULL )
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		
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
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;

  file = fopen(cpf, "r"); // Tenta abrir o arquivo para leitura

	if (file == NULL) 
	{
   		printf("O usu�rio n�o existe!\n");
   		system("pause");

  	} 

	else
  	{
    	remove(cpf); 
  		printf("Usu�rio deletado!\n");
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
	
		printf("### Cat�rio da EBAC ###\n\n"); //Inico Menu
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o:  ");//Fim menu
		///printf("Esse software � uso de Anthony S. Fonseca"); essa op��o voltar� mais tarde
	
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
			printf("Est� op��o n�o est� disponivel!\n\n");
			system("pause");
			break;
			}//Fim da sess�o
		
		system("cls");
	}
}
