// "printf" mostra para o usuario o que esta escrito
#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espca�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de testo por regi�o
#include <string.h> //biblioteca das strings
int registro() //Fun��o registro (CADASTRAR USUARIO NO SISTEMA	)
{
	//inicio cria��o de vari�vel/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variavel
	printf("Digite o cpf a ser cadrastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //"%s" esta armazenando as strings
	
	strcpy(arquivo, cpf); //respondavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");// abre o arquivo e baseado na letra entre "" ele faz algo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file =fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); // pausar o sistema na tela para conseguir ler
}


int consulta()
{
	setlocale (LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("arquivo n�o encontrado no sistema!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL )
	{
		printf ("\nEssas s�o as informa��es do usu�rio: ");
		printf ("%s", conteudo);
		printf ("\n\n"); 
	}
	
	system("pause");
} 

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Usuario n�o encontrado no sistema.\n");
		system("pause");
	}
}
int main() //DEFININDO VARIAVEIS 
{ 
	int opcao = 0; // definindo a opcao como um numero inteiro
	int x = 1;
 	
	for (x = 1; x = 1;)
	 {
		
		system ("cls");
		
		setlocale (LC_ALL, "Portuguese"); // setando a nossa lingua para podermos usar acentos 
		
		printf ("##### Cart�rio da EBAC ####\n\n"); // INICIO DO MENU
		
		printf ("Escolha a op��o desejada:\n\n");
		
		printf ("\t1 - Registrar nomes\n");
		
		printf ("\t2 - Consultar os nomes\n");
		
		printf ("\t3 - Deletar nomes\n");
		
		printf ("\t4 - sair do sistema\n");
		
		printf ("op��o: ");	//FIM DO MENU
		
		scanf  ("%d", &opcao); // armazenando as informacoes (escolha do usuario)
		
		system ("cls"); // limpar a tela
		
		switch(opcao) // inicio da sele��o de menu
		{
			case 1:
			registro(); //chamada de fun��o registro
			break;
			
			case 2:
			consulta(); //chamada de fun��o consultar
			break;
			
			case 3:
			deletar(); //chamada de fun��o de deletar
			break;
			
			case 4:
			printf("obrigado por utilizar o sistema\n ");
			return 0;	
			break;
			
			default:
			printf ("Voc� escolheu uma op��o inexistente\n");
			system ("pause");
			break;
		}
	 }
} //Final da sele��o
	
		
