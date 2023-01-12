#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro(){

    int opcao = 0;

	setlocale(LC_ALL, "Portuguese");

    printf("Você escolheu registro de nomes! \n");

    char arquivo[40] = "arquivo";
    char cpf[40] = "000.000.000";
    char nome[40] = "Nome da Silva";
    char sobrenome[40] = "Sobrenome Fulano";
    char cargo[40] = "Cargo de alguem";

    printf("Digite o CPF a ser cadastrado: \n");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);//copia valores das strings

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, "CPF: ");
    fprintf(file, "%s", cpf);
    fprintf(file, "\n");
    fclose(file);

    printf("Digite o nome a ser cadastrado: \n");
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file, "NOME: ");
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, "\n");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: \n");
    scanf("%s",sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "SOBRENOME: ");
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, "\n");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: \n");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "CARGO: ");
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ".");
    fclose(file);

    printf("Usuário cadastrado com sucesso! \n");
    printf("Para voltar ao Menu digite (1) para cadastrar outro usuário digite (2) \n");
    scanf("%d", &opcao);

    if(opcao == 1)
        {
        main();
        }
    if(opcao == 2)
        {
        registro();
        }
    return 0;
}

int consulta(){

    int opcao = 0;

	setlocale(LC_ALL, "Portuguese");

    printf("Você escolheu consultar os nomes! \n");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: \n");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL){
        printf("Este CPF não foi localizado! \n");
        printf("Para voltar ao Menu digite (1) para consultar outro usuário digite (2) \n");
        scanf("%d", &opcao);

        if(opcao == 1)
            {
            main();
            }
        if(opcao == 2)
            {
            consulta();
            }
    }

    while(fgets(conteudo, 200, file) != NULL){
        printf("\n Essas são as informações do usuário: \n");
        printf("%s", conteudo);
        printf("\n\n");
    }
    fclose(file);

    printf("Para voltar ao Menu digite (1) para consultar outro usuário digite (2) \n");
    scanf("%d", &opcao);

    if(opcao == 1)
        {
        main();
        }
    if(opcao == 2)
        {
        consulta();
        }

	return 0;
}

int deleta(){

    int opcao = 0;

	setlocale(LC_ALL, "Portuguese");

    printf("Você escolheu deletar nomes! \n");

    char cpf[40];

    printf("Digite o CPF que deseja deletar; \n");
    scanf("%s", cpf);

    remove(cpf);
    printf("Usuário removido do sistema! \n");
    printf("Esse CPF não foi encontrado! \n");
    printf("Para voltar ao Menu digite (1) para deletar outro usuário digite (2) \n");
    scanf("%d", &opcao);

    if(opcao == 1)
        {
        main();
        }
    if(opcao == 2)
        {
        deleta();
        }

    return 0;

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("Esse CPF não foi encontrado! \n");
        printf("Para voltar ao Menu digite (1) para deletar outro usuário digite (2) \n");
        scanf("%d", &opcao);

        if(opcao == 1)
            {
            main();
            }
        if(opcao == 2)
            {
            deleta();
            }

    }
    fclose(file);
	return 0;
}

int main()
{

	int opcao1 = 0;

	int laco = 1;

	for(laco=1;laco==1;)
    {

        setlocale(LC_ALL, "Portuguese");

        printf("\t #### CARTÓRIO EBAC ####\n");
        printf("\t Digite para selecionar sua opção: \n");
        printf("\t 1 - Registrar Nomes: \n");
        printf("\t 2 - Consultar Nomes: \n");
        printf("\t 3 - Deletar Nomes: \n");
        printf("\t 4 - Sair do Sistema. \n");
        scanf("%d", &opcao1);

        switch(opcao1)
        {
        case 1:
            registro();
            break;
        case 2:
            consulta();
            break;
        case 3:
            deleta();
            break;
        case 4:
            printf("Obrigado por utilizar o sistema. \n");
            return 0;
            break;
        default:
            printf("Opção Inválida! \n");
            break;

        }
	}

	return 0;

}
