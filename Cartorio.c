#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblooteda de alocações de texto por região 
#include <string.h>  //biblioteca responsavel por cuidar das string


int registro()// função responsavel do cadasteo de usuário
    {
    	//criaçãp de variávveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final das variáveis
     
    printf("digite o cfp a ser cadastrado: ");//registrando usuários
    scanf("%s", cpf);//%s ler sterings
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das string
    
    FILE *file;  //cria novo arquivo no arquivo ja existente
    file = fopen(arquivo, "w"); //modela o arquivo novo
    fprintf(file,cpf); //salvo o valor da variavel 
    fclose(file);  //fecha o arquivo
    
    file = fopen(arquivo, "a");// "a" atualiza o arquivo para novas atualizações
    fprintf(file, ",");// adiciona uma virgula ao arquivo
    fclose(file);//fecha o arquivo
    
    printf("digite o nome a ser cadastrado: ");//registro de nome
    scanf("%s", nome);// armazena o nome na variável string
     
    file = fopen(arquivo, "a");//atualização de arquivo
    fprintf(file,nome);//salva o nome no arquivo
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//atualização de arquivo
    fprintf(file, ",");// virgula ao arquivo
    fclose(file);//fecha o arquivo
    
    printf("digite o sobrenome a ser cadastrado: ");//registro de sobrenome
    scanf("%s", sobrenome);//armazena o sobrenome na string
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//atualização dp arquivo
    fprintf(file, sobrenome);//salva o sobrenome no arquivo
    fclose(file);//fecha o arquivio
	
	file = fopen(arquivo, "a");// atualizaão de arquivo
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

	//variáveis
	char cpf[40];
	char conteudo[200];
	//fim das variáveis
	
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);//escaneia a string em busca do cpf cadastrado
	
	FILE *file;//abre o arquivo
	file = fopen(cpf, "r");//"r" ler o arquivo
	
	if(file == NULL)//iguala o arquivo a nulo
	{
	printf("não foi possivel abrir o arquivo, inexistente.\n\n");//resposta se for nulo
    }
    
    
	while(fgets(conteudo, 200, file) != NULL)//enquanto haver conteudo no arquivo vai escanear e quando acabar vai mostrar na tela
	{
	
	printf("\n\nessas são as informações do usuário:\n");
	printf("%s", conteudo);// escaneia a string com o conteudo cadastrado
	printf("\n\n");
    }
	
	system("pause");//pausa o sistena
	
}

int deletar()//deletando usuários
    {
    setlocale(LC_ALL, "Portuguese");
	//variáaeis 	
	char cpf[40];
	//fim das variáveis
 
	printf("digite o CPF do usurio a ser deletado: \n");
	scanf("%s", cpf);//escaneia a string com o cpf desejado
 
	 remove(cpf);//remove o cpf
	 
	 printf("\tCPf deletado com sucesso.\n");
	 system("pause");
	 
	 
	 FILE *file;
	 file = fopen(cpf, "r");//le o arquivo em busca do cpf desejado
	 
	 if(file == NULL)//se arquivo igyal a nulo
	{
 	printf("CPF de usuário nao encontrado.\n");
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
	
	    printf("### cartório da EBAC ###\n\n"); //inicio do menu
	     printf("escolha a opçao desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n"); 
	    printf("\t4 - sair do programa.\n\n");
	    printf("opção:"); //fim do menu

	    scanf("%d", &opcao); // armanzenando a escolha do usuarario
	
	    system("cls");
	    
	    
	    switch(opcao)//variável de opção 
	    {
		
	    case 1://em caso de primeira opção
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
		
		default:// em caso de nao existir a opção selecionada
		printf("acabaram as opções\n");
		system("pause");
			
		 
    	}
    }
}
