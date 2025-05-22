Sistema de Gerenciamento de Contatos em C
License: MIT

📌 Visão Geral
Sistema de gerenciamento de contatos desenvolvido em C que armazena dados em formato CSV, com interface de linha de comando intuitiva e validação de dados.

📋 Funcionalidades Principais
CRUD de Contatos (Create, Read, Update*)

Validação de dados:

Formato de telefone (11 dígitos)

E-mail (validação básica com @)

Múltiplos critérios de busca

Persistência em arquivo CSV

Gerenciamento automático de IDs

*Atualmente suporta criação e leitura, atualização será implementada na próxima versão

⚙️ Configuração do Ambiente
Pré-requisitos
Compilador GCC

Sistema Windows (para compatibilidade com _mkdir())

Compilação
bash
gcc main.c -o contatos -Wall -Wextra
🚀 Guia Rápido
Iniciar o programa:

bash
./contatos
Menu Principal:

1 - Adicionar contato
2 - Listar contatos
3 - Buscar contato
5 - Sair
Exemplo de Uso:

bash
# Adicionar novo contato
> 1
Telefone (apenas números): 21999998888
Nome: João da Silva  
Email: joao@empresa.com
📂 Estrutura de Arquivos
/
├── database/
│   ├── contatos.csv      # Armazena todos os contatos
│   └── contador.txt      # Mantém o último ID usado
└── contatos.exe          # Executável compilado
🔍 Métodos de Busca
Opção	Campo	Exemplo de Entrada
1	ID	5
2	Nome	Maria
3	Telefone	21999998888
4	E-mail	exemplo@dominio.com
📊 Estrutura de Dados
c
struct Contato {
    int id;               // Identificador único
    char nome[50];        // Nome do contato
    char telefone[12];    // Telefone (11 dígitos + null)
    char email[100];      // Endereço de e-mail
};
🛠️ Funções Principais
load_contatos()
Carrega contatos do arquivo CSV para memória:

c
int load_contatos(struct Contato **contatos, int *cont, int *max_len)
create()
Adiciona novo contato ao arquivo CSV:

c
void create(struct Contato *contato)
Validação
authEmail(): Verifica presença de @

Formatação automática de telefone

📈 Roadmap
Versão 1.0 - CRD básico

Versão 1.1 - Atualização de contatos

Versão 2.0 - Interface gráfica

🤝 Como Contribuir
Reporte issues no repositório

Faça fork e envie PRs

Sugira melhorias na documentação

📄 Licença
MIT License - Consulte o arquivo LICENSE para detalhes completos.

Desenvolvido para fins educacionais - 2023

