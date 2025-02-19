#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblooteda de aloca��es de texto por regi�o 
#include <string.h>  //biblioteca responsavel por cuidar das string


int registro()// fun��o responsavel do cadasteo de usu�rio
    {
    	//cria��p de vari�vveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final das vari�veis
     
    printf("digite o cfp a ser cadastrado: ");//registrando usu�rios
    scanf("%s", cpf);//%s ler sterings
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das string
    
    FILE *file;  //cria novo arquivo no arquivo ja existente
    file = fopen(arquivo, "w"); //modela o arquivo novo
    fprintf(file,cpf); //salvo o valor da variavel 
    fclose(file);  //fecha o arquivo
    
    file = fopen(arquivo, "a");// "a" atualiza o arquivo para novas atualiza��es
    fprintf(file, ",");// adiciona uma virgula ao arquivo
    fclose(file);//fecha o arquivo
    
    printf("digite o nome a ser cadastrado: ");//registro de nome
    scanf("%s", nome);// armazena o nome na vari�vel string
     
    file = fopen(arquivo, "a");//atualiza��o de arquivo
    fprintf(file,nome);//salva o nome no arquivo
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//atualiza��o de arquivo
    fprintf(file, ",");// virgula ao arquivo
    fclose(file);//fecha o arquivo
    
    printf("digite o sobrenome a ser cadastrado: ");//registro de sobrenome
    scanf("%s", sobrenome);//armazena o sobrenome na string
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//atualiza��o dp arquivo
    fprintf(file, sobrenome);//salva o sobrenome no arquivo
    fclose(file);//fecha o arquivio
	
	file = fopen(arquivo, "a");// atualiza�o de arquivo
    fprintf(file, ",");//virgula ao arquivio
    fclose(file);//fecha o arquivo
    
    printf("digite o cargo a ser cadastrado: ");//atualizando o cargo
    scanf("%s", cargo);//salvando o cargo ao arquivo da string
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//atualizando o arquivo
    fprintf(file, cargo);//adiciona cargo ao arquivo
    fclose(file);//fecha o arquivo
    
     

}

int consultar()//consulta de nomes
    {
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	//vari�veis
	char cpf[40];
	char conteudo[200];
	//fim das vari�veis
	
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);//escaneia a string em busca do cpf cadastrado
	
	FILE *file;//abre o arquivo
	file = fopen(cpf, "r");//"r" ler o arquivo
	
	if(file == NULL)//iguala o arquivo a nulo
	{
	printf("n�o foi possivel abrir o arquivo, inexistente.\n\n");//resposta se for nulo
    }
    
    
	while(fgets(conteudo, 200, file) != NULL)//enquanto haver conteudo no arquivo vai escanear e quando acabar vai mostrar na tela
	{
	
	printf("\n\nessas s�o as informa��es do usu�rio:\n");
	printf("%s", conteudo);// escaneia a string com o conteudo cadastrado
	printf("\n\n");
    }
	
	system("pause");//pausa o sistena
	
}

int deletar()//deletando usu�rios
    {
    setlocale(LC_ALL, "Portuguese");
	//vari�aeis 	
	char cpf[40];
	//fim das vari�veis
 
	printf("digite o CPF do usurio a ser deletado: \n");
	scanf("%s", cpf);//escaneia a string com o cpf desejado
 
	 remove(cpf);//remove o cpf
	 
	 printf("\tCPf deletado com sucesso.\n");
	 system("pause");
	 
	 
	 FILE *file;
	 file = fopen(cpf, "r");//le o arquivo em busca do cpf desejado
	 
	 if(file == NULL)//se arquivo igyal a nulo
	{
 	printf("CPF de usu�rio nao encontrado.\n");
	system("pause");
	}
	
}

int main ()
    {
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");//limpa a tela para melhor visual
	
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	    printf("### cart�rio da EBAC ###\n\n"); //inicio do menu
	     printf("escolha a op�ao desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n"); 
	    printf("\t4 - sair do programa.\n\n");
	    printf("op��o:"); //fim do menu

	    scanf("%d", &opcao); // armanzenando a escolha do usuarario
	
	    system("cls");
	    
	    
	    switch(opcao)//vari�vel de op��o 
	    {
		
	    case 1://em caso de primeira op��o
	    registro();//abre o registro
		break;//para o sistema
		
		case 2:
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4: 
		printf("obrigado por utilizar o sistema.");
		return 0;
		break;
		
		default:// em caso de nao existir a op��o selecionada
		printf("acabaram as op��es\n");
		system("pause");
			
		 
    	}
    }
}
