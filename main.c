#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 256
#define CURSOS 20
#define TURMAS 10
#define ALUNOS 40

// ESTRUTURAS

typedef struct {
	char nome[MAX];
	char cpf[MAX];
	int idade;
} Discente;

typedef struct {
	char nome[MAX];
	char codigo[MAX];
	int horas;
	int nVagas;
	int nParticipantes;
} Curso;

typedef struct {
	int num;
	char cpf[MAX];
	char codigo[MAX];
	int ano;
	float nota;
	int horasParticipacao;
} Turma;

// PROTOTIPAÇÃO

// INTERFACES
void menu();
void opDefault();
void menuOpcoes();

// CADASTRO EM ARQUIVOS

void cadastrarDiscente();
void cadastrarCurso();
void cadastrarTurma();

// AUXILIARES
int contarLinhas(char *arquivo);
// CRUD
void listarDiscentes();
void editarDiscente();
void excluirDiscente();

// RELATORIOS
void pesquisarDiscente(char *info);
void listarTurmaDiscentes();

	/****************|
	|* MENU INICIAL *|
	|****************/

void menu(){
	int op;
	int escolha = 0;
	
	printf("\n\t\t===== Sistema TopArtBaré =====\n");
	printf("\n\t1 - Discentes");
	printf("\n\t2 - Cursos");
	printf("\n\t3 - Turmas");
	printf("\n\t4 - Relatórios");
	printf("\n\t0 - Sair");
	printf("\n\nEscolha: ");
	scanf("%d", &op);
	getchar();

	switch(op){
		case 1: // Discentes
			printf("\n\t\t===== TopArtBaré - Discentes =====\n");
			menuOpcoes();
			scanf("%d", &op);

			switch(op){
				case 1:
					cadastrarDiscente();
					break; // fim case 1
				case 2:
					printf("\n\t\t=== TopArtBaré - Editar Discente ===\n");
					printf("\n\tEscolha o registro para editar pelo número correspondente\n\n");
	
					listarDiscentes();

					printf("\n\nEscolha: ");
					scanf("%d", &escolha);
					
					editarDiscente(escolha);
					excluirDiscente(escolha);
					
					menu();
					break;

				case 3:
					printf("\n\t\t=== TopArtBaré - Excluir Discente ===\n");
					printf("\n\tEscolha o registro para excluir pelo número correspondente\n\n");
	
					listarDiscentes();

					printf("\n\nEscolha: ");
					scanf("%d", &escolha);
					getchar();

					excluirDiscente(escolha);
					printf("\n\tExclusão realizada.\nVoltar\n>");
					getchar();
					menu();
					break;
				
				case 0:
					menu();

				default:
					opDefault();
			}


			break; // fim case 1
				   
		case 2: // Cursos
			printf("\n\t\t===== TopArtBaré - Cursos =====\n");
			menuOpcoes();
			printf("\n\nEscolha: ");
			scanf("%d", &op);
			getchar();


			switch(op) {
				case 1: 
					cadastrarCurso();
					break;

				default:
					opDefault();
			}

			break; // fim case 2

		case 3: // Turmas

			printf("\n\t\t===== TopArtBaré - Turmas =====\n");
			menuOpcoes();
			printf("\n\nEscolha: ");
			scanf("%d", &op);
			getchar();

			switch(op) {
				case 1:
					cadastrarTurma();
					break;

			}


			break; //fim case 3

		case 4:// Relatorios
			printf("\n\t\t===== TopArtBaré - Relatorios =====\n");
			printf("\n\t1. Listagem dos Discentes");
			printf("\n\t2. Listagem de Cursos");
			printf("\n\t3. Pesquisa de Discentes");
			printf("\n\t4. Listagem de Turmas e Discentes");
			printf("\n\t5. Listagem de Turma, Discentes e Curso");
			printf("\n\t6. Listagem de Discente de acordo com a Turma (pelo código)");
			printf("\n\t7. Listagem de Turmas e Média de Notas");
			printf("\n\t0. Voltar");
			printf("\n\nEscolha: ");
			scanf("%d", &op);
			getchar();

			switch(op) {
				case 1:
					printf("\n\t\t===== TopArtBaré - Listagem dos Discentes =====\n\n");
					listarDiscentes();
					printf("\nVoltar\n>");
					getchar();

					menu();
					break;
				
				case 3:
					printf("\n\t\t===== TopArtBaré - Pesquisa de Discentes =====\n\n");
					char info[MAX];
					printf("\tInsira uma informação para pesquisar discente (Nome ou CPF)\n\n>");

					fgets(info, MAX, stdin);
					pesquisarDiscente(info);

					printf("\n\nVoltar\n>");
					menu();

					break;
				
				case 4:
					listarTurmaDiscentes();
					break;
				case 0:
					menu();
					break;
				default: 
					opDefault();
			}

			break; //fim case 4
		
		case 0: // Sair
			printf("\n\nSaindo...\n\n");
			break;
		
		default:
			opDefault();
			//fim default
			break;
	} // fim switch

} // fim menu()

void opDefault(){
	printf("\nOpção incorreta!! Selecione uma opção do menu\n>");
	getchar();
	menu();
}

void menuOpcoes(){
	printf("\n\t1 - Cadastrar");
	printf("\n\t2 - Editar");
	printf("\n\t3 - Excluir");
	printf("\n\t4 - Voltar");
	printf("\n\nEscolha: ");
}


	/****************************|
	|* 1 - CADASTRO DE DISCENTE *|
	|****************************/

void cadastrarDiscente() {
	FILE *f = fopen("./arquivos/discentes.txt", "a");
	// variavel temporaria para receber numero em char para passar para int
	char temp[MAX];

	if (f == NULL){
		printf("Erro- cadastrarDiscentes: abertura de arquivo");
		return;
	}
	
	Discente discente = {0};

	printf("\n\t\t===== TopArtBaré - Cadastrar discente =====\n");
	getchar();
	printf("Nome: ");
	fgets(discente.nome, MAX, stdin);
	// adiciona '\0' para garantir o final da string
	discente.nome[strcspn(discente.nome, "\n")] = '\0';

	printf("CPF: ");
	fgets(discente.cpf, MAX, stdin);
	discente.cpf[strcspn(discente.cpf, "\n")] = '\0'; 

	printf("Idade: ");
	// recebe numero como char
	fgets(temp, MAX, stdin);
	// passa char para int
	discente.idade = atoi(temp);
	
	// armazena os dados no arquivo
	fprintf(f, "%s|%s|%d\n", discente.nome, discente.cpf, discente.idade);
	
	fclose(f);

	printf("\n\tCadastro concluido!\n>");
	getchar();
	
	// retorna pro menu inicial
	menu();
}

int contarLinhas(char *arquivo){
	FILE *f = fopen(arquivo, "r");
	
	if (f == NULL) {
		printf("Erro - contarLinhas: abertura de arquivo");
		return 0;
	}

	char c;
	int linhas = 0;
	
	// verifica ocorrencia de '\n' para contar linhas
	while (!feof(f)){
		// percorre por caracteres individualmente
		c = fgetc(f);
		if (c == '\n') linhas++;
	}

	fclose(f);

	// retorna quantidade de linhas
	return linhas;
}

void listarDiscentes() {
    char *arquivo = "./arquivos/discentes.txt";
    
    int linhas = contarLinhas(arquivo);
    if (linhas <= 0) return;

    FILE *f = fopen(arquivo, "r");
    if (f == NULL) {
        printf("Erro - listarDiscentes: abertura de arquivo");
        return;
    }

    char registro[MAX];
    Discente discente[linhas];
    memset(discente, 0, sizeof(discente));

    for (int i = 0; i < linhas; i++) {
        fgets(registro, sizeof(registro), f);
		sscanf(registro, "%[^|]|%[^|]|%d", discente[i].nome, discente[i].cpf, &discente[i].idade);    
		printf("%d. Nome: %s | CPF: %s | Idade: %d\n", i+1, discente[i].nome, discente[i].cpf, discente[i].idade);
    }

    fclose(f);
}

void editarDiscente(int escolha) {

	char *arquivo = "./arquivos/discentes.txt";

    FILE *f = fopen(arquivo, "r+");
	if (f == NULL) {
		printf("Erro - editarDiscente: abertura de arquivo");
	}

	int linhas = contarLinhas(arquivo);
	char registro[MAX];

	printf("%d", escolha);
	Discente discente[linhas];
    memset(discente, 0, sizeof(discente));

	for (int i = 0; i < linhas; i++) {
			fgets(registro, sizeof(registro), f);
			sscanf(registro, "%[^|]|%[^|]|%d", discente[i].nome, discente[i].cpf, &discente[i].idade);    

		if (i+1 == escolha){
			printf("\n\tEscolha a informação que deseja editar\n\n");
			printf("\n1. Nome: %s \n2. CPF: %s \n3. Idade: %d\n", discente[i].nome, discente[i].cpf, discente[i].idade);
			
			printf("\n\nEscolha: ");
			scanf("%d", &escolha);

			getchar();


			switch(escolha){
				case 1:
					printf("\n\nEditar nome: ");
					fgets(discente[i].nome, MAX, stdin);
					// adiciona '\0' para garantir o final da string
					discente[i].nome[strcspn(discente[i].nome, "\n")] = '\0';
					
					printf("\n\nNome alterado com sucesso!!");
					printf("\nNome: %s | CPF: %s | Idade: %d\n", discente[i].nome, discente[i].cpf, discente[i].idade);
					
					fseek(f, 0, SEEK_END);
					fprintf(f, "%s|%s|%d\n", discente[i].nome, discente[i].cpf, discente[i].idade);
					break;

				case 2:
					printf("\n\nEditar CPF: ");
					fgets(discente[i].cpf, MAX, stdin);
					discente[i].cpf[strcspn(discente[i].cpf, "\n")] = '\0'; 
						
					printf("\n\nCPF alterado com sucesso!!");
					printf("\nNome: %s | CPF: %s | Idade: %d\n", discente[i].nome, discente[i].cpf, discente[i].idade);
					fseek(f, 0, SEEK_END);
					fprintf(f, "%s|%s|%d\n", discente[i].nome, discente[i].cpf, discente[i].idade);
					break;

				case 3:
					printf("\n\nEditar idade: ");
					char temp[MAX];

					// recebe numero como char
					fgets(temp, MAX, stdin);
					// passa char para int
					discente[i].idade = atoi(temp);
		
					printf("\n\nIdade alterada com sucesso!!");
					printf("\nNome: %s | CPF: %s | Idade: %d\n", discente[i].nome, discente[i].cpf, discente[i].idade);
					fseek(f, 0, SEEK_END);
					fprintf(f, "%s|%s|%d\n", discente[i].nome, discente[i].cpf, discente[i].idade);
					break;

				default:
					opDefault();

			}
		}
	}

	fclose(f);

}
void excluirDiscente(int linha) {
	char *arquivo = "./arquivos/discentes.txt";
	char *temp = "./arquivos/temp.txt";
	
	int linhas = contarLinhas(arquivo);
	char registro[1024];

	FILE *discente = fopen(arquivo, "r");
	FILE *temporario = fopen(temp, "w");

	if (discente == NULL || temporario == NULL) {
		printf("ERRO - excluirDiscente: erro ao abrir um dos arquivos");
	}

	for(int i = 0; i < linhas; i++) {
		fgets(registro, sizeof(registro), discente);
		if (i != linha-1) {
			fputs(registro, temporario);
		}
		
	}

	fclose(discente);
	fclose(temporario);
	
	remove(arquivo);
	rename(temp, arquivo);
	
}

void cadastrarCurso() {
	FILE *f = fopen("./arquivos/cursos.txt", "a");

	if (f == NULL) {
		printf("Erro - cadastrarCurso: abertura de arquivo");
	}

	Curso curso = {0};
	char temp[MAX];

	printf("=== CADASTRAR CURSO ===\n");
	getchar();
	printf("Nome: ");
	fgets(curso.nome, MAX, stdin);
	curso.nome[strcspn(curso.nome, "\n")] = '\0';

	printf("Codigo: ");
	fgets(curso.codigo, MAX, stdin);
	curso.codigo[strcspn(curso.codigo, "\n")] = '\0';

	printf("Horas: ");
	fgets(temp, MAX, stdin);
	curso.horas = atoi(temp);

	printf("Numero de vagas: ");
	fgets(temp, MAX, stdin);
	curso.nVagas = atoi(temp);

	printf("Numero de participantes: ");
	fgets(temp, MAX, stdin);
	curso.nParticipantes = atoi(temp);

	fprintf(f, "%s|%s|%d|%d|%d\n", 
			curso.nome, curso.codigo, curso.horas, curso.nVagas, curso.nParticipantes);
	
	fclose(f);

}

void cadastrarTurma() {
	FILE *f = fopen("./arquivos/turmas.txt", "a");

	if (f == NULL) {
		printf("Erro - cadastrarTurma: abertura de arquivo");
	}

	Turma turma = {0};
	char temp[MAX];

	printf("\n=== CADASTRAR TURMA ===\n");
	getchar();
	
	printf("Numero: ");
	fgets(temp, MAX, stdin);
	turma.num = atoi(temp);

	printf("CPF: ");
	fgets(turma.cpf, MAX, stdin);
	turma.cpf[strcspn(turma.cpf, "\n")] = '\0';

	printf("Codigo: ");
	fgets(turma.codigo, MAX, stdin);
	turma.codigo[strcspn(turma.codigo, "\n")] = '\0';
	
	printf("Ano: ");
	fgets(temp, MAX, stdin);
	turma.ano = atoi(temp);
	
	printf("Nota: ");
	fgets(temp, MAX, stdin);
	turma.nota = atof(temp);

	printf("Horas de participacao: ");
	fgets(temp, MAX, stdin);
	turma.horasParticipacao = atoi(temp);

	fprintf(f, "%d|%s|%s|%d|%f|%d\n", turma.num, turma.cpf, turma.codigo, turma.ano, turma.nota, turma.horasParticipacao);

	fclose(f);

}

void pesquisarDiscente(char *info) {
	FILE *f = fopen("./arquivos/discentes.txt", "r");
	if (f == NULL) {
		printf("Erro - pesquisarDiscente: abertura de arquivo");
		return;
	}

    info[strcspn(info, "\n")] = '\0';
	char linha[MAX];
	Discente discente;

	printf("\n\t=== Resultados encontrados ===");
	while(fgets(linha, MAX, f) != NULL) {
		if (strstr(linha, info) != NULL){
			if (sscanf(linha, "%[^|]|%[^|]|%d", discente.nome, discente.cpf, &discente.idade) == 3) {
				printf("\n* Nome: %s | CPF: %s | Idade: %d Anos", discente.nome, discente.cpf, discente.idade);
			}
		}
	}

	fclose(f);
}

void listarTurmaDiscentes() {
	FILE *arqDiscentes = fopen("./arquivos/discentes.txt", "r");
	FILE *arqTurmas = fopen("./arquivos/turmas.txt", "r");
	
	if (arqDiscentes == NULL || arqTurmas == NULL) {
		printf("Erro - listarTurmaDiscentes: abertura de um dos arquivos");
		return;
	}
		
	char linhaTurma[MAX];
	char linhaDiscente[MAX];

	Discente discente;
	Turma turma;
	int i = 0;
	while(fgets(linhaTurma, MAX, arqTurmas) != NULL) {
		sscanf(linhaTurma, "%d|%[^|]|%[^|]|%d|%f|%d", &turma.num, turma.cpf, turma.codigo, &turma.ano, 
													&turma.nota, &turma.horasParticipacao);
		printf("\n\tTurma: %d\n", turma.num);
		
		fgets(linhaDiscente, MAX, arqDiscentes);
		do {
			sscanf(linhaDiscente, "%[^|]|%[^|]|%d", discente.nome, discente.cpf, &discente.idade);    
			if (strstr(discente.cpf, turma.cpf) != NULL){
				printf("\n* Nome %s | CPF: %s | Nota: %f", discente.nome, discente.cpf, turma.nota);
				i++;	
			} 
	
		} while(fgets(linhaDiscente, MAX, arqDiscentes) != NULL);
		}

printf("\n%d", i);
	fclose(arqDiscentes);
	fclose(arqTurmas);

}


void main () {
	setlocale(LC_ALL, "Portuguese");
	menu();
}
