#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// struct Contato
// armazena os dados do contato
struct Contato {
    int id; // id do contato
    char nome[50]; // nome do contato
    char telefone[11]; // telefone do contato
    char email[100]; // email do contato
};

void formataTelefone(char telefone[]) {
    // formata o telefone para o formato (31) 99999-9999
    char telefoneFormatado[16];
    snprintf(telefoneFormatado, sizeof(telefoneFormatado), "(%c%c) %c%c%c%c%c-%c%c%c%c", 
             telefone[0], telefone[1], telefone[2], telefone[3], telefone[4], telefone[5], 
             telefone[6], telefone[7], telefone[8], telefone[9], telefone[10]);
    printf("Telefone: %s\n", telefoneFormatado);
}

void imprimirContato(struct Contato contatos[], int i) {
    printf("\nID: %d\n", contatos[i].id);
    printf("Nome: %s\n", contatos[i].nome);
    formataTelefone(contatos[i].telefone); //TODO: transformar o telefone para o formato (31) 99999-9999
    printf("Email: %s\n", contatos[i].email);
}

// função authEmail
// verifica se o email é válido
bool authEmail(char email[]) {
    char *p = strchr(email, '@'); // verifica se existe o @
    if (p != NULL) { 
        printf("Email válido\n");
        return true; // retorna verdadeiro se o email for válido
    } else {
        printf("Email inválido\n");
        return false; // retorna falso se o email for inválido
    }
}

// procedimento preenche
// preenche os dados do contato
// recebe como parâmetro o vetor de contatos e o contador de contatos
void preenche(struct Contato contatos[], int cont) {
    for (int i = cont; i == cont; i++) {
        contatos[i].id = i + 1; // atribui o id do contato
        printf("digite o telefone (31999999999): "); 
        scanf("%s", &contatos[i].telefone); // atribui o telefone do contato
        fflush(stdin);
        printf("digite o nome do contato:"); 
        scanf("%s", &contatos[i].nome); // atribui o nome do contato
        fflush(stdin);
        do { // em loop até o email ser válido
        printf("digite o email do contato:"); 
        scanf("%s", &contatos[i].email); // atribui o email do contato
        fflush(stdin);
        }while (!authEmail(contatos[i].email));

        printf("Contato %d adicionado com sucesso!\n", contatos[i].id); // imprime mensagem de sucesso
    }
}

// procedimento listar
// imprime a lista de contatos
void listar(struct Contato contatos[], int cont) {
    printf("Lista de contatos:\n"); 
    for (int i = 0; i < cont; i++) {
        imprimirContato(contatos, i); // chama a função imprimirContato para imprimir os dados do contato
        printf("------------------------\n");
    }
}

int main() {
    int max_len = 10; // tamanho máximo do vetor de contatos
    int op = 0; // variável para armazenar a opção do usuário
    int cont = 0; // contador de contatos
    // aloca memória para o vetor de contatos
    struct Contato *contatos = (struct Contato*)malloc(max_len * sizeof(struct Contato));
    
    
    do { // loop até o usuário digitar -1
        printf("\tMenu:\t\n1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("digite a opção: ");
        scanf("%d", &op);
        fflush(stdin);
        printf("\n");

        switch (op)
        {
        case 1: // adiciona contato
            preenche(contatos, cont);
            cont++; // incrementa o contador de contatos
            break;
        
        case 2: // lista contatos
            listar(contatos, cont);
            break;
        
        default:
            printf("Opção inválida!");
            break;
        }
    }while (op != -1);
        
    free(contatos); // libera a memória alocada para o vetor de contatos
    contatos = NULL; // zera o ponteiro para evitar acesso a memória liberada
    
}
    