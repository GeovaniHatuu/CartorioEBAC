#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string

//Definindo as funções
int registro()//Registrar nomes
{
	//Definindo as variaveis de registro
	char arquivo[40];//[]Número de variaveis dentro da string arquivo
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Pedindo o numero do cpf
	printf("Digite CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//Copiando os arquivos da variavel(arquivo = cpf)
	
		FILE *file;//Criando um arquivo
		file = fopen(arquivo, "w");//Cria o arquivo("w" cria arquivo)
		fprintf(file, cpf);//Salva o valor da variavel cpf
		fclose(file);//Fecha o arquivo
	
		//Criando uma simples vírgula entre as informações
		file = fopen(arquivo, "a");//Abrindo um arquivo("a" abre o arquivo)
		fprintf(file,",");//Escrevendo a vírgula
		fclose(file);//Fecha o arquivo
	
	//Pedindo o nome
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
		
		file = fopen(arquivo, "a");//Abrindo o arquivo
		fprintf(file, nome);
		fclose(file);
	
		//Outra vírgula
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
	
	//Pedindo o sobrenome
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
	
		//Outra vírgula
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
	
	//Pedindo o cargo
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
	
	system("pause");
}

int consulta()//Consultar nomes
{
	setlocale(LC_ALL, "Portuguese");//Definindo o idioma nativo
	
	//Denindo as váriaveis
	char cpf[40];//Definindo a váriavel novamente
	char conteudo[200];//Váriavel com todo o conteudo
	char *token;
	
	//Pedindo o cpf para consultar
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;//FILE = file
	file = fopen(cpf, "r");//Abrindo o arquivo de texto com o cpf selecionado
	
	//Se o arquivo não foi encontrado
	if (file == NULL)
	{
		printf("CPF não foi encontrado\n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas foram as informações do usuário: \n");
		
		token = strtok(conteudo, ",");//Váriavel utilizada para a divisão da string em linhas
		printf("CPF: %s\n",token);//Texto antes de aparecer os dados
		
		token = strtok(NULL, ",");//Váriavel utilizada para a divisão da string em linhas
		printf("Nome: %s\n",token);//Texto antes de aparecer os dados
		
		token = strtok(NULL, ",");//Váriavel utilizada para a divisão da string em linhas
		printf("Sobrenome: %s\n",token);//Texto antes de aparecer os dados
		
		token = strtok(NULL, ",");//Váriavel utilizada para a divisão da string em linhas
		printf("Cargo: %s\n",token);//Texto antes de aparecer os dados
		
		printf("\n");
		
		system("pause");
	}
}

int deletar()//Deletar nomes
{
	//Definindo a váriavel e também a primekey
	char cpf[40];
	
	//Pedindo e pegando o CPF a deletar
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%S", cpf);
	
	remove(cpf);//Removendo o usuario cadastrado neste CPF
	
	FILE *file;//FILE = file
	file = fopen(cpf, "r");//Abrindo o arquivo onde está armazenado e lendo
	
	//Verifica se o CPF não foi encontrado
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema.\n\n");
		system("pause");
	}
	
	system("pause");
	
}	


//O menu principal
int main()
{
	
	int opcao = 0;//Definindo variavel de opção
	int laco = 1;//Definindo a variavel de loop de laço
	
	//Se laço for igual a 1 o código repete, o loop sempre vai acontecer por conta da definição 1
	for (laco == 1; laco == 1;)
	{
		system("cls");//Limpando o que foi escrito anteriormente
		
		setlocale(LC_ALL, "Portuguese");//Definindo o idioma nativo
		
		printf("### Cartório da EBAC ###\n\n");//Boas vindas
		
		//Pedindo para escolher uma das opções
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		
		printf("Opcão: ");//Só deixando mais bonito
		
		scanf("%d", &opcao);//Armezenando o numero escolhido pelo o usuario
		
		system("cls");//Apagando o que já foi escrito
		
		//Analizando qual opcão o usuário escolheu
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			                                                 
			default:
			printf("Por favor escolha uma das opções\n");
			system("pause");//Pausando para ler
			break;
		}//Fim do switch
		
	}
}

