#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Contato {
    int id;
    char nome[50];
    char telefone[11];
    char email[100];
};

bool authEmail(char email[]) {
    char *p = strchr(email, '@');
    if (p != NULL) {
        printf("Email válido\n");
        return true;
    } else {
        printf("Email inválido\n");
        return false;
    }
}

void preenche(struct Contato contatos[], int id) {
    for (int i = id; i == id; i++) {
        contatos[i].id = i * 1.00;
        printf("digite o telefone (31999999999): ");
        scanf("%s", &contatos[i].telefone);
        fflush(stdin);
        printf("digite o nome do contato:");
        scanf("%s", &contatos[i].nome);
        fflush(stdin);
        do {
        printf("digite o email do contato:");
        scanf("%s", &contatos[i].email);
        fflush(stdin);
        }while (!authEmail(contatos[i].email));

        printf("Contato %d adicionado com sucesso!\n", contatos[i].id + 1);
    }
}

void listar(struct Contato contatos[], int id) {
    printf("Lista de contatos:\n");
    for (int i = 0; i < id; i++) {
        printf("\nID: %d\n", contatos[i].id);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("Email: %s\n", contatos[i].email);
        printf("------------------------\n");
    }
}

int main() {
    int max_len = 10;
    int op = 0;
    int id = 0;
    struct Contato *contatos = (struct Contato*)malloc(max_len * sizeof(struct Contato));
    do {
        printf("\tMenu:\t\n1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("digite a opção: ");
        scanf("%d", &op);
        fflush(stdin);
        printf("\n");

        switch (op)
        {
        case 1:
            preenche(contatos, id);
            id++;
            break;
        
        case 2:
            listar(contatos, id);
            
            break;
        
        default:
            printf("Opção inválida!");
            break;
        }
    }while (op != -1);
        
    
    
}
    