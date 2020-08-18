#include <iostream>

using namespace std;

struct TPerfume
{
    string nome, marca, aroma;
    int cod;
    float preco;
};

struct TCelula
{
    TPerfume perfume;
    TCelula *proximo;
};

struct TPilha
{
    TCelula *fundo;
    TCelula *topo;
};

struct TNoh
{
    TPerfume perfume;
    TNoh *esq,*dir;
};

struct TArvore
{
    TNoh *raiz;
    int contador;
};

void IniciarArvore(TArvore &a)
{
    a.raiz = NULL;
    a.contador = 0;
}

bool ArvEstaVazia(TArvore a) // Verifica se a �rvore esta vazia
{
    return a.raiz == NULL;
}

void InserirArv(TPerfume i, TNoh *&n, TArvore &a) // Fun��o destinada a inserir as op��es do perfume na �rvore
{
    if (n == NULL)
    {
        n = new TNoh;
        n->perfume = i;
        n->esq = NULL;
        n->dir = NULL;
        if (a.raiz == NULL)
        {
            a.raiz = n;
        };
        a.contador++;
    }
    else
    {
        if (i.cod < n->perfume.cod)
        {
            InserirArv(i,n->esq,a);
        }
        else
        {
            if (i.cod > n->perfume.cod)
            {
                InserirArv(i,n->dir,a);
            }
            else
            {
                cout << "Valor j� existe na �rvore!";
            }
        }
    }
}

void percorrerINOrdem(TNoh *&a)
{
    if(a!=NULL)
    {
        percorrerINOrdem(a->esq);
        cout << " ===================================== " << endl;
        cout <<" C�digo do perfume: " << a->perfume.cod << endl;
        cout <<" Nome do perfume: " << a->perfume.nome << endl;
        cout <<" Marca do perfume: " << a->perfume.marca << endl;
        cout <<" Aroma do perfume: " << a->perfume.aroma << endl;
        cout <<" Pre�o do perfume: " << a->perfume.preco << endl;

        percorrerINOrdem(a->dir);
    }
}

void percorrerPREOrdem(TNoh *&a)
{
    if(a!=NULL)
    {
        cout << " ===================================== " << endl;
        cout <<" Codigo do perfume: " << a->perfume.cod << endl;
        cout <<" Nome do perfume: " << a->perfume.nome << endl;
        cout <<" Marca do perfume: " << a->perfume.marca << endl;
        cout <<" Aroma do perfume: " << a->perfume.aroma << endl;
        cout <<" Preco do perfume: " << a->perfume.preco << endl;

        percorrerPREOrdem(a->esq);
        percorrerPREOrdem(a->dir);
    }
}

void percorrerPOSOrdem(TNoh *&a)
{
    if(a!=NULL)
    {
        percorrerPOSOrdem(a->esq);
        percorrerPOSOrdem(a->dir);
       cout << " ===================================== " << endl;
        cout <<" Codigo do perfume: " << a->perfume.cod << endl;
        cout <<" Nome do perfume: " << a->perfume.nome << endl;
        cout <<" Marca do perfume: " << a->perfume.marca << endl;
        cout <<" Aroma do perfume: " << a->perfume.aroma << endl;
        cout <<" Preco do perfume: " << a->perfume.preco << endl;
    }
}

void mostrarArvore(TArvore a){
    cout << " ====== MOSTRANDO ARVORE ====== " << endl;
    cout << "   IN Ordem: ";
    percorrerINOrdem(a.raiz);
    cout << endl ;
    cout << "   PRE Ordem: ";
    percorrerPREOrdem(a.raiz);
    cout << endl ;
    cout << "   POS Ordem: ";
    percorrerPOSOrdem(a.raiz);
    cout << endl << "-----------------------------" << endl;
}

void pesquisar(int i, TNoh *&n, TArvore a){

    if (n == NULL){
        cout << "Registro n�o localizado na �rvore" << endl;
    }
    else {
        if (i < n->perfume.cod){
            pesquisar(i, n->esq, a);
        }
        else {
            if (i > n->perfume.cod)
                {
                pesquisar(i, n->dir, a);
            }
            else{
                cout << "C�digo encontrado:  " << n->perfume.cod << endl;
            }
        }
    }
}

void pegarAnterior(TNoh *a, TNoh *&b){

    if (b->dir != NULL){
        pegarAnterior(a, b->dir);
    }
    else{
        a->perfume = b->perfume;
        a = b;
        b = b->esq;
        delete a;
    }
}

void retirar(TPerfume i, TNoh *&p){
TNoh *aux;

    if (p == NULL){
        cout << "Registro n�o encontrado" << endl;
    }
    else{
        if (i.cod < p->perfume.cod){
            retirar(i, *&p->esq);
        }
        else{
            if (i.cod > p->perfume.cod){
                retirar(i, *&p->dir);
            }
            else{
                if (p->dir == NULL){
                    aux = p;
                    p = p->esq;
                    delete aux;
                }
                else{
                    if (p->esq != NULL){
                        pegarAnterior(p, p->esq);
                    }
                    else{
                        aux = p;
                        p = p->dir;
                        delete aux;

                    }
                }
            }
        }
    }
}

void criaPilhaVazia(TPilha &p)
{
    p.fundo = new TCelula;
    p.topo = p.fundo;
    p.fundo->proximo = NULL;
    cout << " =========== PILHA CRIADA ============ " << endl;
}

bool EstaVazia(TPilha &p)
{
    return (p.topo == p.fundo);
}

bool VerificaSeForIgual(TPilha pilha, int cod)
{
    TCelula *aux;
    aux = pilha.topo->proximo;
    while(aux != NULL)
    {
        if(aux->perfume.cod == cod)
        {
            return true;
        }
        else
        {
            aux = aux->proximo;
        }
        return false;
    }
}

void EmpilharPerfumes(TPilha &p, TPerfume perfume)
{
    TCelula *celAux = new TCelula;
    p.topo->perfume = perfume;
    celAux->proximo = p.topo;
    p.topo = celAux;
}

void Cadastrar(TPilha &p)
{
    TPerfume perfume;
    string op;

    cout << " ===================================== " << endl;
    cout << " ======== CADASTRO DE PERFUME ======== " << endl;
    cout << " ===================================== " << endl;

    do
    {
        cout << "Digite um c�digo de QUATRO n�meros " << endl;
        cin >> perfume.cod;

        while(perfume.cod < 1000 || perfume.cod > 10000)
        {
            cout << "ERRO! Digite um c�digo de QUATRO digitos. " << endl;
            cout << "Digite um c�digo de 4 n�meros " << endl;
            cin >> perfume.cod;
        }
        while(VerificaSeForIgual(p, perfume.cod) != false)
        {
            cout << "ERRO! C�DIGO J� CADASTRADO.  " << endl;
            cout << "Digite outro c�digo. " << endl;
            cin >> perfume.cod;}

        cout << "Digite o nome do perfume: " << endl;
        cin >> perfume.nome;
        cout << "Digite a marca do perfume: " << endl;
        cin >> perfume.marca;
        cout << "Digite o aroma do perfume " << endl;
        cin >> perfume.aroma;
        cout << "Digite o pre�o do perfume: R$";
        cin >> perfume.preco;
        cout << "------------------------------" << endl;

        EmpilharPerfumes(p, perfume);
        cout << "Continuar inserindo? s/n: ";
        cin >> op;
    }
    while(op!="n");

}

TPerfume DesempilhaPega(TPilha &pilha)
{

    TCelula *desempilha;
    TPerfume aux;
    if(EstaVazia(pilha))
    {
        cout<<"N�o h� perfumes para Desempilhar"<<endl;
    }
    else
    {
        desempilha = pilha.topo;
        aux = desempilha->proximo->perfume;
        pilha.topo = desempilha->proximo;
        delete desempilha;
    }
    return aux;
}

void MostrarPilha(TPilha pilha)
{
    TCelula *PCelaux;
    PCelaux = pilha.topo->proximo;

    if (EstaVazia(pilha))
    {
        cout<<"Erro! N�o H� mais perfumes!!!"<<endl;
    }
    else
    {
        while(PCelaux != NULL)
        {
            cout << "C�digo: " << PCelaux->perfume.cod << endl;
            cout << " Nome: " << PCelaux->perfume.nome << endl;
            cout << " Marca: " << PCelaux->perfume.marca << endl;
            cout << " Aroma: " << PCelaux->perfume.aroma << endl;
            cout << " Pre�o: " << PCelaux->perfume.preco << endl;
            PCelaux = PCelaux->proximo;
        }
    }
}

void TransferenciaPilhaParaArvore(TPilha &pilha,TArvore &a)
{
    TPerfume p;
    TCelula *aux;

    aux = pilha.topo->proximo;

    while(aux != NULL)
    {
        p = DesempilhaPega(pilha);
        aux = aux->proximo;
        InserirArv(p,a.raiz, a);
    }
    cout << " ===== DADOS TRANSFERIDOS COM SUCESSO ===== " << endl;
}

int SairMenu(TArvore a){
    cout << "========== OPERA��O FINALIZADA =========== " << endl;
    return 0;
}

void MenuArvore(TArvore a, TNoh *n, TPilha &pilha)
{
    int opcao;
    int cod;

    do
    {
        cout <<endl;
        cout << " ===================================== " << endl;
        cout << "    1 - Cadastrar perfumes na pilha" << endl;
        cout << "    2 - Mostrar elementos na pilha" << endl;
        cout << "    3 - Transferir de pilha para a �rvore" << endl;
        cout << "    4 - Pesquisar por c�digo do perfume " << endl;
        cout << "    5 - Mostrar �rvore" << endl;
        cout << "    6 - Sair " << endl;
        cout << " ===================================== " << endl;
        cout << "Op��o: " << endl;
        cin >> opcao;

        switch(opcao){
            case 1:
            criaPilhaVazia(pilha);
            Cadastrar(pilha);
            break;
        case 2:
            MostrarPilha(pilha);
            break;
        case 3:
            IniciarArvore(a);
            TransferenciaPilhaParaArvore(pilha,a);
            break;
        case 4:
            cout << "Digite o c�digo que deseja pesquisar: " << endl;
            cin >> cod;
            MostrarPilha(pilha);
            pesquisar(cod,n,a);
            break;
        case 5:
            mostrarArvore(a);
            percorrerINOrdem(a.raiz);
            percorrerPREOrdem(a.raiz);
            percorrerPOSOrdem(a.raiz);
            break;
        case 6:
            SairMenu(a);
            break;


        default:
            cout << "Op��o invalida!" << endl;
        }
    }
    while((opcao>0) && (opcao!=7));
}

int main(){

    TPilha pilha;
    TArvore a;
    TNoh *n;
    IniciarArvore(a);
    setlocale(LC_ALL, "Portuguese");
    MenuArvore(a, n, pilha);
}







