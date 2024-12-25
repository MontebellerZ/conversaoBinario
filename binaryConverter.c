//INCLUSÃO DE BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // para a função toupper



//FUNÇÕES
void limparArqSaida(){ // zera o arquivo de saida
    FILE *saida; //cria um ponteiro para o arquivo de dados

    saida = fopen("saidaBin.bin","wb");// reseta o arquivo para escrita
    fclose(saida);
    
    saida = fopen("saidaCar.txt","wt");// reseta o arquivo para escrita
    fclose(saida);
}

void carToBin(){
	FILE *entrada; //cria um ponteiro para o arquivo de dados
	FILE *saida;
	char caracter;

	entrada = fopen("entradaCar.txt","rt");// abre o arquivo para leitura
	if(!entrada){
        printf("Erro!!! Arquivo nao encontrado!");
    }
    else{
        saida = fopen("saidaBin.bin", "ab");
		if(saida==NULL){
			printf("Erro na abertura do arquivo!");
	    	exit(1);
		}
        
    	while(1){
            caracter = fgetc(entrada); //lê o conteúdo do arquivo
            if(caracter==EOF){ // se o ponteiro chegou no fim do arquivo
		    	break; // sai da estrutura
	    	}
			
			fwrite(&caracter,sizeof(char),1,saida);
        }
		fclose(saida);
	}
	fclose(entrada);
}

void binToCar(){
	FILE *entrada; //cria um ponteiro para o arquivo de dados
	FILE *saida;
	char caracter;
	
	entrada = fopen("entradaBin.bin","rb");// abre o arquivo para leitura
	if(!entrada){
        printf("Erro!!! Arquivo nao encontrado!");
    }
    else{
        saida = fopen("saidaCar.txt", "at");
		if(saida==NULL){
			printf("Erro na abertura do arquivo!");
	    	exit(1);
		}
        
    	while(fread(&caracter,sizeof(caracter),1,entrada)==1){
    		printf("%c",caracter);
			fputc(caracter,saida);
        }
		fclose(saida);
	}
	fclose(entrada);
}

void informar(){ // é a ajuda do programa para o usuário saber do que o mesmo trata, o que faz e como utilizar
    printf("Programa que faz a conversao ...blablabla...");   
}

//MAIN
int main(){
    int opcao; // variável utilizada para decidir conversão fazer
 
    while(1){
        system("cls"); // para o linux

        printf("\n\n\n\nPrograma conversor de Niveis de Linguagem.\n\n");
        printf("1 - Texto -> Binario\n");
        printf("2 - Binario -> Texto\n");
        printf("3 - Limpar o arquivo de saida\n");
        printf("4 - Informacoes sobre o programa\n");
        printf("...\n");
        printf("9 - Sair do programa\n");
        printf("Sua opcao: ");
        scanf("%d", &opcao);

		if(opcao==9){
			break;
		}
        
        switch(opcao){ // SE a opção escolhida foi a de conversões, é feita a leitura do arquivo
        	case 1:
	            carToBin(); 
				printf("O arquivo foi convertido com sucesso!!!");
        		break;
        	case 2:
	            binToCar(); 
				printf("O arquivo foi convertido com sucesso!!!");
        		break;
        	case 3:
	            limparArqSaida(); 
				printf("O arquivo de saida esta em branco!!!");  
        		break;
        	case 4:
	            informar();
				printf("\n");
        		break;
        	default: // usado quando a opção digitada não faz parte do MENU
	            printf("Opcao invalida! Favor escolher uma opcao do Menu.\n");
        		break;
		}
		system("pause");
    }
    
    getchar();
    return 0; 
}

