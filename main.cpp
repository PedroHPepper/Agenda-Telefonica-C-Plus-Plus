#include <iostream>

using namespace std;

typedef struct contatos{
    string nome;
    int telefone;
    struct contatos *proximo;

}contatos;

typedef struct categorias{
    char letra;
    struct contatos *contatos;

}categorias;


struct contatos *atual, *aux, *novocontato;
struct categorias *novo;


int chave(string);
void imprimir(int);
void inserir(string, int);
void buscar(int, string);

int main()
{
    int i, opcao;
    int posicao;
    string nome;
    struct categorias categoria[26];
    novo = categoria;

    for(i = 0; i<26; i++){
        categoria[i].letra='a'+ i;
        categoria[i].contatos=NULL;
    }

    do{
        cout<<"1 - Inserir contato:\n"
        <<"2 - Imprimir Contatos:\n"
        <<"3 - Buscar Contato:\n";
        cin>>opcao;
        switch(opcao){
            case 1:
                cout<< "Insira um nome: ";
                cin>>nome;

                posicao=chave(nome);

                inserir(nome, posicao);
                //categorias[posicao]=novo;
                break;

            case 2:
                for(i=0; i<26; i++){

                    imprimir(i);
                }

                break;
            case 3:
                cout<< "Insira um nome: ";
                cin>>nome;
                posicao=chave(nome);
                buscar(posicao, nome);
        }
    }while(opcao!=4);




    return 0;
}

void inserir(string nome, int posicao){
    int telefone;

    novocontato=(contatos*)malloc(sizeof(contatos));

    cout<<"Insira um Numero de Telefone: ";
    cin>>telefone;

    novocontato->nome=nome;
    novocontato->telefone=telefone;

    atual = novo[posicao].contatos;
    aux=atual;

    if(atual==NULL){
        novo[posicao].contatos=novocontato;
    }

    while(atual!=NULL){



        if(novocontato->nome.compare(atual->nome) > 0 || novocontato->nome.compare(atual->nome)==0){
            aux=atual;
            if(atual->proximo==NULL){
                atual->proximo=novocontato;
                break;
            }
            atual=atual->proximo;


        }else if(novocontato->nome.compare(atual->nome)<0){
            if(atual==aux){
                novocontato->proximo=atual;
                novo[posicao].contatos=novocontato;
                break;
            }else{
                aux->proximo=novocontato;
                novocontato->proximo=atual;
                break;

            }
        }
    }
}

void imprimir(int posicao){

    atual=novo[posicao].contatos;

    while(atual!=NULL){

        cout<<"\nNome: " << atual->nome << "\nNumero: " << atual->telefone << "\n";
        atual=atual->proximo;

    }

}

void buscar(int posicao, string nome){
  atual = novo[posicao].contatos;

  while(atual!=NULL){
    if(atual->nome.compare(nome)==0){
      cout << "\nNome: " << nome <<
      "\nTelefone: " << atual->telefone<<
      "\n";
      atual=atual->proximo;
    }else if(atual->nome.compare(nome)>0){
      break;
    }else if(atual->nome.compare(nome)<0){
      atual=atual->proximo;
    }

  }

}

int chave(string nome){

    return((int)nome[0] - 97);
}
