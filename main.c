#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 256

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

/*********************************/
/* PROTÓTIPOS DE TODAS AS FUNÇÕES*/
/*********************************/

// TELAS DE INTERAÇÃO
void menu(); 	// MENU INICIAL
void opDefault(); // FUNÇÃO PARA DEFAULT DE SWITCH
void menuOpcoes(); // MENU DE OPÇÕES CRUD

// FUNÇÃO AUXILIAR
int contarLinhas(char *arquivo); // CONTA O TOTAL DE LINHAS DE UM ARQUIVO

/********************/
/* CRUD DE ARQUIVOS */
/********************/

// CRUD DISCENTES
void cadastrarDiscente();
void listarDiscentes();
void editarDiscente(int escolha);
void excluirDiscente();

// CRUD CURSOS
void cadastrarCurso();
void listarCursos();
void editarCurso(int escolha);
void excluirCurso(int escolha);

// CRUD TURMAS
void cadastrarTurma();
void listarTurmas();
void editarTurma(int escolha);
void excluirTurma(int escolha);

/**************/
/* RELATÓRIOS */
/**************/
void pesquisarDiscente(char *info); // EXIBE TODOS OS DISCENTES
void listarTurmaDiscentes();		// LISTA TURMAS E SEUS DISCENTES
void listarTurmaDiscenteCurso();	// LISTA TURMAS, DISCENTES E CURSOS RELACIONADOS
void listarTurmaCodigo(int escolha); // LISTA UMA TURMA PELO CÓDIGO ATRIBUIDO
void listarTurmaMedia();			//LISTA A MÉDIA DE CADA TURMA

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
					break;

				default:
					opDefault();
			}


			break; // fim case 1

		case 2: // Cursos
			printf("\n\t\t===== TopArtBaré - Cursos =====\n");
			menuOpcoes();
			scanf("%d", &op);
			getchar();


			switch(op) {
				case 1: 
					cadastrarCurso();
					break;

				case 2: 
					printf("\n\t\t=== TopArtBaré - Editar Curso ===\n");
					printf("\n\tEscolha o registro para excluir pelo número correspondente\n\n");

					listarCursos();

					printf("\n\nEscolha: ");
					scanf("%d", &escolha);
					getchar();

					editarCurso(escolha);
					excluirCurso(escolha);
					printf("\n\tExclusão realizada.\nVoltar\n>");
					getchar();
					menu();
					break;

				case 3: 
					printf("\n\t\t=== TopArtBaré - Excluir Curso ===\n");
					printf("\n\tEscolha o registro para excluir pelo número correspondente\n\n");

					listarCursos();

					printf("\n\nEscolha: ");
					scanf("%d", &escolha);
					getchar();

					excluirCurso(escolha);
					printf("\n\tExclusão realizada.\nVoltar\n>");
					getchar();
					menu();
					break;
				case 0:
					menu();
					break;

				default:
					opDefault();
			}

			break; // fim case 2

		case 3: // Turmas

			printf("\n\t\t===== TopArtBaré - Turmas =====\n");
			menuOpcoes();
			scanf("%d", &op);
			getchar();

			switch(op) {
				case 1:
					cadastrarTurma();
					break;
				case 2:
					printf("\n\t\t=== TopArtBaré - Editar Turma ===\n");
					printf("\n\tEscolha o registro para editar pelo número correspondente\n\n");

					listarTurmaDiscentes();

					printf("\n\nEscolha: ");
					scanf("%d", &escolha);

					editarTurma(escolha);
					excluirTurma(escolha);
					menu();
					break;
				case 3:
					printf("\n\t\t=== TopArtBaré - Excluir Turma ===\n");
					printf("\n\tEscolha o registro para excluir pelo número correspondente\n\n");

					listarTurmaDiscentes();

					printf("\n\nEscolha: ");
					scanf("%d", &escolha);
					getchar();

					excluirTurma(escolha);
					printf("\n\tExclusão realizada.\nVoltar\n>");
					getchar();
					menu();
					break;
				case 0:
					menu();
					break;
				default:
					opDefault();
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

				case 2:
					printf("\n\t\t===== TopArtBaré - Listagem dos Cursos =====\n\n");
					listarCursos();
					printf("\n\nVoltar\n>");
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
					printf("\n\t\t===== TopArtBaré - Listagem de Turmas e Discentes =====\n");
					listarTurmaDiscentes();

					printf("\n\nVoltar\n>");
					getchar();
					menu();
					break;

				case 5:
					printf("\n\t\t===== TopArtBaré - Listagem de Turmas, Discentes e Cursos =====\n");
					listarTurmaDiscenteCurso();
					printf("\n\nVoltar\n>");
					getchar();
					menu();
					break;

				case 6: 
					printf("\n\t\t===== TopArtBaré - Listagem de Turmas por número =====\n\n");
					printf("\tEscolha o número de uma das turmas para listar\n");
					listarTurmas();
					printf("\n\nEscolha: ");
					scanf("%d", &escolha);
					getchar();
					listarTurmaCodigo(escolha);
					printf("\n\nVoltar\n>");
					getchar();
					menu();
					break;

				case 7:
					printf("\n\t\t===== TopArtBaré - Listagem de Turmas e Média de notas =====\n\n");
					listarTurmaMedia();
					printf("\n\nVoltar\n>");
					getchar();
					menu();
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

// FUNÇÃO PARA DEFAULT DE UM SWITCH
void opDefault(){
	printf("\nOpção incorreta!! Selecione uma opção do menu\n>");
	getchar();
	menu();
}

// MENU DE OPÇÕES CRUD
void menuOpcoes(){
	printf("\n\t1 - Cadastrar");
	printf("\n\t2 - Editar");
	printf("\n\t3 - Excluir");
	printf("\n\t0 - Voltar");
	printf("\n\nEscolha: ");
}

// FUNÇÃO DE CONTAR LINHAS DE UM ARQUIVO
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


/**************************************************/
/****************  CRUD DISCENTES   ***************/
/**************************************************/

// 1. CADASTRO DE UM DISCENTE
void cadastrarDiscente() {
	FILE *f = fopen("./arquivos/discentes.txt", "a");
	// variavel temporaria para receber numero em char para passar para int
	char temp[MAX];
	
	// confirma abertura de arquivo
	if (f == NULL){
		printf("Erro- cadastrarDiscentes: abertura de arquivo");
		return;
	}
	// inicia estrutura discente zerada
	Discente discente = {0};

	printf("\n\t\t===== TopArtBaré - Cadastrar discente =====\n");
	getchar(); // previne que o nome seja o /n anterior
			   
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

// 2. LISTAR TODOS OS DISCENTES
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

// 3. EDITAR UM DISCENTE
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

	for (int i = 1; i < linhas; i++) {
		fgets(registro, sizeof(registro), f);
		sscanf(registro, "%[^|]|%[^|]|%d", discente[i].nome, discente[i].cpf, &discente[i].idade);    

		if (i == escolha){
			printf("\n\tEscolha a informação que deseja editar - %d %d\n\n",i, escolha);
			printf("\n1. Nome: %s \n2. CPF: %s \n3. Idade: %d\n", discente[i].nome, discente[i].cpf, discente[i].idade);

			int opcao = 0;
			printf("\n\nEscolha: ");
			scanf("%d", &opcao);

			getchar();

			switch(opcao){
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

// 4. EXCLUIR UM DISCENTE
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

/**************************************************/
/**************   CRUD TURMA   ********************/
/**************************************************/

// 1. CADASTAR UM REGISTRO EM TURMA
void cadastrarTurma() {
	FILE *f = fopen("./arquivos/turmas.txt", "a");

	if (f == NULL) {
		printf("Erro - cadastrarTurma: abertura de arquivo");
	}

	Turma turma = {0};
	char temp[MAX];

	printf("\n\t\t===== TopArtBaré - Cadastrar Turma =====\n");
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
	printf("\n\tCadastro concluido!\n>");
	getchar();

	// retorna pro menu inicial
	menu();

}

// 2. LISTAR TURMAS
void listarTurmas() {
	char *nomeTur = "./arquivos/turmas.txt";

	int qtdTur = contarLinhas(nomeTur);

	FILE *arqTurmas = fopen(nomeTur, "r");

	if (arqTurmas == NULL) {
		printf("Erro - listarTurmaDiscentes: abertura de um dos arquivos");
		return;
	}

	char linhaTurma[MAX];
	Turma turma[qtdTur];
	int totalTurmas = 0;

	for (int j = 0; j < qtdTur; j++) {
		if (fgets(linhaTurma, MAX, arqTurmas) == NULL) break;

		sscanf(linhaTurma, "%d|%[^|]|%[^|]|%d|%f|%d", &turma[j].num, turma[j].cpf, turma[j].codigo, &turma[j].ano,
				&turma[j].nota, &turma[j].horasParticipacao);

	}

	for (int j = 0; j < qtdTur; j++) {
		int i;
		for (i = 0; i < j; i++) {
			if (turma[i].num == turma[j].num) {
				break; 
			}
		}
		if (i == j) {
			printf("\n* Turma %d", turma[i].num );
		}
	}	
	fclose(arqTurmas);

}

// 3. EDITAR UM REGISTRO DE TURMA
void editarTurma (int escolha) {
	
	char *arquivo = "./arquivos/turmas.txt";

	FILE *f = fopen(arquivo, "r+");
	if (f == NULL) {
		printf("Erro - editarTurma: abertura de arquivo");
	}

	int linhas = contarLinhas(arquivo);
	char registro[MAX];

	printf("%d", escolha);
	Turma turma[linhas];
	memset(turma, 0, sizeof(turma));

	for (int i = 1; i < linhas; i++) {
		fgets(registro, sizeof(registro), f);

		sscanf(registro, "%d|%[^|]|%[^|]|%d|%f|%d", &turma[i].num, turma[i].cpf, turma[i].codigo, &turma[i].ano,
							&turma[i].nota, &turma[i].horasParticipacao);

		if (i == escolha){

			printf("\n\tEscolha a informação que deseja editar - %d\n\n", i);

			printf("\n1. Numero: %d", turma[i].num);
			printf("\n2. CPF: %s", turma[i].cpf);
			printf("\n3. Codigo: %s", turma[i].codigo);
			printf("\n4. Ano: %d", turma[i].ano);
			printf("\n5. Nota: %.2f", turma[i].nota);
			printf("\n6. Horas de participacao: %d\n", turma[i].horasParticipacao);
			int opcao = 0;
			printf("\n\nEscolha: ");
			scanf("%d", &opcao);

			getchar();

			switch(opcao){
				case 1:
					printf("\n\nEditar numero: ");
					char temp1[MAX];
					fgets(temp1, MAX, stdin);
					turma[i].num = atoi(temp1);

					printf("\nAlterado com sucesso!\n");

					fseek(f, 0, SEEK_END);
					fprintf(f, "%d|%s|%s|%d|%f|%d\n", turma[i].num, turma[i].cpf, turma[i].codigo,
						turma[i].ano, turma[i].nota, turma[i].horasParticipacao);
					break;

				case 2:
					printf("\n\nEditar CPF: ");
					fgets(turma[i].cpf, MAX, stdin);
					turma[i].cpf[strcspn(turma[i].cpf, "\n")] = '\0';

					printf("\nAlterado com sucesso!\n");

					fseek(f, 0, SEEK_END);
					fprintf(f, "%d|%s|%s|%d|%f|%d\n", turma[i].num, turma[i].cpf, turma[i].codigo,
						turma[i].ano, turma[i].nota, turma[i].horasParticipacao);
				
					break;

				case 3:
					printf("\n\nEditar codigo: ");
					fgets(turma[i].codigo, MAX, stdin);
					turma[i].codigo[strcspn(turma[i].codigo, "\n")] = '\0';

					printf("\nAlterado com sucesso!\n");

					fseek(f, 0, SEEK_END);
					fprintf(f, "%d|%s|%s|%d|%f|%d\n", turma[i].num, turma[i].cpf, turma[i].codigo,
						turma[i].ano, turma[i].nota, turma[i].horasParticipacao);
			
					break;

				case 4:
					printf("\n\nEditar ano: ");
					char temp2[MAX];
					fgets(temp2, MAX, stdin);
					turma[i].ano = atoi(temp2);

					printf("\nAlterado com sucesso!\n");

					fseek(f, 0, SEEK_END);
					fprintf(f, "%d|%s|%s|%d|%f|%d\n", turma[i].num, turma[i].cpf, turma[i].codigo,
						turma[i].ano, turma[i].nota, turma[i].horasParticipacao);
				
					break;

				case 5:
					printf("\n\nEditar nota: ");
					char temp3[MAX];
					fgets(temp3, MAX, stdin);
					turma[i].nota = atof(temp3);

					printf("\nAlterado com sucesso!\n");

					fseek(f, 0, SEEK_END);
					fprintf(f, "%d|%s|%s|%d|%f|%d\n", turma[i].num, turma[i].cpf, turma[i].codigo,
						turma[i].ano, turma[i].nota, turma[i].horasParticipacao);
					
					break;

				case 6:
					printf("\n\nEditar horas de participacao: ");
					char temp4[MAX];
					fgets(temp4, MAX, stdin);
					turma[i].horasParticipacao = atoi(temp4);

					printf("\nAlterado com sucesso!\n");

					fseek(f, 0, SEEK_END);
					fprintf(f, "%d|%s|%s|%d|%f|%d\n", turma[i].num, turma[i].cpf, turma[i].codigo,
						turma[i].ano, turma[i].nota, turma[i].horasParticipacao);
					
					break;

				default:
					opDefault();
			}
		}
	}

	fclose(f);

}

// 4. EXCLUIR UM REGISTRO DE TURMA
void excluirTurma(int linha) {
	char *arquivo = "./arquivos/turmas.txt";
	char *temp = "./arquivos/temp.txt";

	int linhas = contarLinhas(arquivo);
	char registro[1024];

	FILE *turma = fopen(arquivo, "r");
	FILE *temporario = fopen(temp, "w");

	if (turma == NULL || temporario == NULL) {
		printf("ERRO - excluirTurma: erro ao abrir um dos arquivos");
	}

	for(int i = 0; i < linhas; i++) {
		fgets(registro, sizeof(registro), turma);

		if (i != linha-1) {
			fputs(registro, temporario);
		}
	}

	fclose(turma);
	fclose(temporario);

	remove(arquivo);
	rename(temp, arquivo);
}

/**************************************************/
/**************   CRUD CURSO    *******************/
/**************************************************/


// 1. CADASTRAR CURSO
void cadastrarCurso() {
	FILE *f = fopen("./arquivos/cursos.txt", "a");

	if (f == NULL) {
		printf("Erro - cadastrarCurso: abertura de arquivo");
	}

	Curso curso = {0};
	char temp[MAX];

	printf("\n\t\t===== TopArtBaré - Cadastrar Curso =====\n");
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
	printf("\n\tCadastro concluido!\n>");
	getchar();

	// retorna pro menu inicial
	menu();

}

// 2. LISTAR TODOS OS CURSOS
void listarCursos() {
	char *arquivo = "./arquivos/cursos.txt";

	int linhas = contarLinhas(arquivo);
	if (linhas <= 0) return;

	FILE *f = fopen(arquivo, "r");
	if (f == NULL) {
		printf("Erro - listarCursos: abertura de arquivo");
		return;
	}

	char registro[MAX];
	Curso curso[linhas];
	memset(curso, 0, sizeof(curso));

	for (int i = 0; i < linhas; i++) {
		fgets(registro, sizeof(registro), f);

		sscanf(registro, "%[^|]|%[^|]|%d|%d|%d", curso[i].nome, curso[i].codigo,
			&curso[i].horas, &curso[i].nVagas, &curso[i].nParticipantes);

		printf("%d. Nome: %s | Codigo: %s | Horas: %d | Vagas: %d | Participantes: %d\n", i+1, curso[i].nome,
			curso[i].codigo, curso[i].horas, curso[i].nVagas, curso[i].nParticipantes);
	}

	fclose(f);
}

// 3. EDITAR CURSO
void editarCurso(int escolha) {

	char *arquivo = "./arquivos/cursos.txt";

	FILE *f = fopen(arquivo, "r+");
	if (f == NULL) {
		printf("Erro - editarCurso: abertura de arquivo");
	}

	int linhas = contarLinhas(arquivo);
	char registro[MAX];

	printf("%d", escolha);
	Curso curso[linhas];
	memset(curso, 0, sizeof(curso));

	for (int i = 1; i < linhas; i++) {
		fgets(registro, sizeof(registro), f);

		sscanf(registro, "%[^|]|%[^|]|%d|%d|%d", curso[i].nome, curso[i].codigo, &curso[i].horas,
			&curso[i].nVagas, &curso[i].nParticipantes);

		if (i == escolha){

			printf("\n\tEscolha a informação que deseja editar\n\n");

			printf("\n1. Nome: %s", curso[i].nome);
			printf("\n2. Codigo: %s", curso[i].codigo);
			printf("\n3. Horas: %d", curso[i].horas);
			printf("\n4. Numero de vagas: %d", curso[i].nVagas);
			printf("\n5. Numero de participantes: %d\n", curso[i].nParticipantes);

			int opcao = 0;
			printf("\n\nEscolha: ");
			scanf("%d", &opcao);
			getchar();

			switch(opcao){
				case 1:
					printf("\n\nEditar nome: ");
					fgets(curso[i].nome, MAX, stdin);
					curso[i].nome[strcspn(curso[i].nome, "\n")] = '\0';

					printf("\nAlterado com sucesso!\n");

					fseek(f, 0, SEEK_END);
					fprintf(f, "%s|%s|%d|%d|%d\n", curso[i].nome, curso[i].codigo, curso[i].horas, curso[i].nVagas, curso[i].nParticipantes);
					break;

				case 2:
					printf("\n\nEditar codigo: ");
					fgets(curso[i].codigo, MAX, stdin);
					curso[i].codigo[strcspn(curso[i].codigo, "\n")] = '\0';

					printf("\nAlterado com sucesso!\n");

					fseek(f, 0, SEEK_END);
					fprintf(f, "%s|%s|%d|%d|%d\n", curso[i].nome, curso[i].codigo, curso[i].horas, curso[i].nVagas, curso[i].nParticipantes);
					break;

				case 3:
					printf("\n\nEditar horas: ");
					char temp1[MAX];
					fgets(temp1, MAX, stdin);
					curso[i].horas = atoi(temp1);

					printf("\nAlterado com sucesso!\n");

					fseek(f, 0, SEEK_END);
					fprintf(f, "%s|%s|%d|%d|%d\n", curso[i].nome, curso[i].codigo, curso[i].horas, curso[i].nVagas, curso[i].nParticipantes);
					break;

				case 4:
					printf("\n\nEditar numero de vagas: ");
					char temp2[MAX];
					fgets(temp2, MAX, stdin);
					curso[i].nVagas = atoi(temp2);

					printf("\nAlterado com sucesso!\n");

					fseek(f, 0, SEEK_END);
					fprintf(f, "%s|%s|%d|%d|%d\n", curso[i].nome, curso[i].codigo, curso[i].horas, curso[i].nVagas, curso[i].nParticipantes);
					break;

				case 5:
					printf("\n\nEditar numero de participantes: ");
					char temp3[MAX];
					fgets(temp3, MAX, stdin);
					curso[i].nParticipantes = atoi(temp3);

					printf("\nAlterado com sucesso!\n");

					fseek(f, 0, SEEK_END);
					fprintf(f, "%s|%s|%d|%d|%d\n", curso[i].nome, curso[i].codigo, curso[i].horas, curso[i].nVagas, curso[i].nParticipantes);
					break;

				default:
					opDefault();
			}
		}
	}

	fclose(f);
}

// 4. EXCLUIR UM CURSO
void excluirCurso(int linha) {
	char *arquivo = "./arquivos/cursos.txt";
	char *temp = "./arquivos/temp.txt";

	int linhas = contarLinhas(arquivo);
	char registro[1024];

	FILE *curso = fopen(arquivo, "r");
	FILE *temporario = fopen(temp, "w");

	if (curso == NULL || temporario == NULL) {
		printf("ERRO - excluirCurso: erro ao abrir um dos arquivos");
	}

	for(int i = 0; i < linhas; i++) {
		fgets(registro, sizeof(registro), curso);

		if (i != linha-1) {
			fputs(registro, temporario);
		}
	}

	fclose(curso);
	fclose(temporario);

	remove(arquivo);
	rename(temp, arquivo);
}

/*******************************************/
/*************  RELATÓRIOS  ****************/
/*******************************************/

// PESQUISAR DISCENTE 

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
		if (strcasestr(linha, info) != NULL){
			if (sscanf(linha, "%[^|]|%[^|]|%d", discente.nome, discente.cpf, &discente.idade) == 3) {
				printf("\n\t* Nome: %s | CPF: %s | Idade: %d Anos", discente.nome, discente.cpf, discente.idade);
			}
		}
	}

	fclose(f);
}


// listar TURMA DISCECNTE 

void listarTurmaDiscentes() {
	char *nomeDisc = "./arquivos/discentes.txt";
	char *nomeTur = "./arquivos/turmas.txt";

	int qtdDisc =  contarLinhas(nomeDisc);
	int qtdTur = contarLinhas(nomeTur);

	FILE *arqDiscentes = fopen(nomeDisc, "r");
	FILE *arqTurmas = fopen(nomeTur, "r");


	if (arqDiscentes == NULL || arqTurmas == NULL) {
		printf("Erro - listarTurmaDiscentes: abertura de um dos arquivos");
		return;
	}

	char linhaTurma[MAX];
	char linhaDiscente[MAX];

	Discente discente[qtdDisc];
	Turma turma[qtdTur];
	for (int i = 0; i < qtdDisc; i++) {
		if (fgets(linhaDiscente, MAX, arqDiscentes) == NULL) break;

		sscanf(linhaDiscente, "%[^|]|%[^|]|%d", discente[i].nome, discente[i].cpf, &discente[i].idade);
	}

	for (int j = 0; j < qtdTur; j++) {
		if (fgets(linhaTurma, MAX, arqTurmas) == NULL) break;

		sscanf(linhaTurma, "%d|%[^|]|%[^|]|%d|%f|%d", &turma[j].num, turma[j].cpf, turma[j].codigo, &turma[j].ano,
				&turma[j].nota, &turma[j].horasParticipacao);
	}


	for(int i = 0; i < qtdDisc; i++) {	
		for(int j = 0; j < qtdTur; j++){

			if (strcmp(discente[i].cpf, turma[j].cpf) == 0) {
				printf("\n\t%d. Turma: %d | Nome: %s | CPF: %s | Nota: %.2f", i+1, turma[j].num, discente[i].nome, 
						discente[i].cpf, turma[j].nota);

			}
		}
	}

	fclose(arqDiscentes);
	fclose(arqTurmas);
}


// LISTAR TURMA DISCENTE CURSO 
void listarTurmaDiscenteCurso(){
	char *nomeDisc = "./arquivos/discentes.txt";
	char *nomeTur = "./arquivos/turmas.txt";
	char *nomeCur = "./arquivos/cursos.txt";

	int qtdDisc =  contarLinhas(nomeDisc);
	int qtdTur = contarLinhas(nomeTur);
	int qtdCur = contarLinhas(nomeCur);

	FILE *arqDiscentes = fopen(nomeDisc, "r");
	FILE *arqTurmas = fopen(nomeTur, "r");
	FILE *arqCursos = fopen(nomeCur, "r");

	if (arqDiscentes == NULL || arqTurmas == NULL || arqCursos == NULL) {
		printf("Erro - listarTurmaDiscenteCurso: abertura de um dos arquivos");
		return;
	}

	char linhaTurma[MAX];
	char linhaDiscente[MAX];
	char linhaCurso[MAX];

	Discente discente[qtdDisc];
	Turma turma[qtdTur];
	Curso curso[qtdCur];

	for (int i = 0; i < qtdDisc; i++) {
		if (fgets(linhaDiscente, MAX, arqDiscentes) == NULL) break;

		sscanf(linhaDiscente, "%[^|]|%[^|]|%d", discente[i].nome, discente[i].cpf, &discente[i].idade);
	}

	for (int j = 0; j < qtdTur; j++) {
		if (fgets(linhaTurma, MAX, arqTurmas) == NULL) break;

		sscanf(linhaTurma, "%d|%[^|]|%[^|]|%d|%f|%d", &turma[j].num, turma[j].cpf, turma[j].codigo, &turma[j].ano,
				&turma[j].nota, &turma[j].horasParticipacao);
	}

	for (int k = 0; k < qtdCur; k++) {
		if (fgets(linhaCurso, MAX, arqCursos) == NULL) break;

		sscanf(linhaCurso, "%[^|]|%[^|]|%d|%d|%d", curso[k].nome, curso[k].codigo, &curso[k].horas, &curso[k].nVagas, &curso[k].nParticipantes);
	}

	for(int i = 0; i < qtdDisc; i++) {	
		for(int j = 0; j < qtdTur; j++){
			for (int k = 0; k < qtdCur; k++){
				if (strcmp(discente[i].cpf, turma[j].cpf) == 0 && strcmp(curso[k].codigo, turma[j].codigo) == 0) {
					printf("\n\t* Turma: %d | Nome: %s | CPF: %s | Nota: %.2f \n\t-> Curso: %s | Codigo: %s\n", 
							turma[j].num, discente[i].nome, 
							discente[i].cpf, turma[j].nota, curso[k].nome, curso[k].codigo);
				}

			}
		}
	}

	fclose(arqDiscentes);
	fclose(arqTurmas);
	fclose(arqCursos);

}

// LISTAR TURMA CODIGO 
void listarTurmaCodigo(int escolha) {
	char *nomeDisc = "./arquivos/discentes.txt";
	char *nomeTur = "./arquivos/turmas.txt";

	int qtdDisc =  contarLinhas(nomeDisc);
	int qtdTur = contarLinhas(nomeTur);
	FILE *arqDiscentes = fopen(nomeDisc, "r");
	FILE *arqTurmas = fopen(nomeTur, "r");


	if (arqDiscentes == NULL || arqTurmas == NULL) {
		printf("Erro - listarTurmaCodigo: abertura de um dos arquivos");
		return;
	}

	char linhaTurma[MAX];
	char linhaDiscente[MAX];

	Discente discente[qtdDisc];
	Turma turma[qtdTur];
	
	for (int i = 0; i < qtdDisc; i++) {
		if (fgets(linhaDiscente, MAX, arqDiscentes) == NULL) break;

		sscanf(linhaDiscente, "%[^|]|%[^|]|%d", discente[i].nome, discente[i].cpf, &discente[i].idade);
	}
	
	int encontrado = 0;

	for (int j = 0; j < qtdTur; j++) {
		if (fgets(linhaTurma, MAX, arqTurmas) == NULL) break;

		sscanf(linhaTurma, "%d|%[^|]|%[^|]|%d|%f|%d", &turma[j].num, turma[j].cpf, turma[j].codigo, &turma[j].ano,
				&turma[j].nota, &turma[j].horasParticipacao);
		if (escolha == turma[j].num) { 
			encontrado++;	
		} 
	}

	if (encontrado == 0) {
		printf("\n\t* Turma não encontrada!!");
	}
	
	encontrado = 0;
	
	for (int i = 0; i < qtdDisc; i++){
		for (int j = 0; j < qtdTur; j++) {
			if (escolha == turma[j].num && strcmp(turma[j].cpf, discente[i].cpf) == 0) {
				if (encontrado == 0) {
					printf("\n\tTurma %d", turma[j].num);
					encontrado++;
				}
				printf("\n\t* Nome: %s | CPF: %s | Nota: %.2f", discente[i].nome, discente[i].cpf, turma[j].nota);

			}

		}
	}
	fclose(arqDiscentes);
	fclose(arqTurmas);
}

// LISTAR TURMA MEDIA
void listarTurmaMedia(){
	char *nomeTur = "./arquivos/turmas.txt";

	int qtdTur = contarLinhas(nomeTur);

	FILE *arqTurmas = fopen(nomeTur, "r");

	if (arqTurmas == NULL) {
		printf("Erro - listarTurmaDiscentes: abertura de um dos arquivos");
		return;
	}

	char linhaTurma[MAX];
	Turma turma[qtdTur];
	int totalTurmas = 0;

	for (int j = 0; j < qtdTur; j++) {
		if (fgets(linhaTurma, MAX, arqTurmas) == NULL) break;

		sscanf(linhaTurma, "%d|%[^|]|%[^|]|%d|%f|%d", &turma[j].num, turma[j].cpf, turma[j].codigo, &turma[j].ano,
				&turma[j].nota, &turma[j].horasParticipacao);

	}

	for (int j = 0; j < qtdTur; j++) {
		int i;
		for (i = 0; i < j; i++) {
			if (turma[i].num == turma[j].num) {
				break; 
			}
		}
		if (i == j) {
			totalTurmas++;
		}
	}

	float acm = 0;
	int totalDisc = 0;
	for (int i = 0; i < totalTurmas; i++) {
		for (int j = 0; j < qtdTur; j++) {
			if (turma[j].num == turma[i].num) {
				acm = acm + turma[j].nota;
				totalDisc++;
			}
		}
			printf("\n\t* Turma %d - Média: %.2f", turma[i].num, acm/totalDisc);
	}
	
	fclose(arqTurmas);

}
void main () {
	setlocale(LC_ALL, "Portuguese");
	menu();
}
