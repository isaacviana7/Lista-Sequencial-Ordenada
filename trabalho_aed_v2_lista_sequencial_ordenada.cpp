#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

struct tpNo {
    int numReg;
};

struct tpNo L[7];
int m = 7;
int n = 0;

int busca_Ord(int x){
    int I = 1;
    int busca_Ord = 0;

    if (n != 0){
        L[n + 1].numReg = x;
        I = 1;
        while (L[I].numReg < x)
        {
            I++;
        }
        if (I == n + 1 || (L[I].numReg != x)){ 
            return busca_Ord;
        }else {
            return busca_Ord = I;
        }
    }
}

void Inserir(){
    int chave;
    cout << "Digite o registro a ser inserido: ";
    cin >> chave;

    if(n < m){
        int posicaoDaChave = n;

        while (posicaoDaChave > 0 && L[posicaoDaChave].numReg > chave){
            posicaoDaChave--;
        }
        
        if (busca_Ord(chave) != 0)
        {
            cout << "Registro já existente." << endl;
        } else {

            for (int i = n; i > posicaoDaChave; i--){
                L[i + 1].numReg = L[i].numReg;
            }
            L[posicaoDaChave + 1].numReg = chave;
            n++;

            // L[n+1].numReg = chave;
            // n++;
            cout << "Registro: " << L[posicaoDaChave + 1].numReg << " inserido com sucesso." << endl;
            cout << "" << endl;
        }
        
    } else {
        cout << "Lista cheia." << endl;
        cout << "" << endl;
    }
    
}

void Excluir(){
    int chave1; int posLista;
    cout << "Digite o registro a ser excluído: ";
    cin >> chave1;

    if (n < 1){
        cout << "Lista vazia." << endl;
    } else {
        posLista = busca_Ord(chave1);
        if (posLista < 1){
            cout << "Não existe esse registro." << endl;
        } else {
            while (posLista < n){
                L[posLista].numReg = L[posLista + 1].numReg;
                posLista++;
            }
            n = n - 1;
            cout << "Registro excluído com sucesso." << endl;
            cout << "" << endl;
        }
    }
}

void ExcluirDoAlterar(int chave1){
    int posLista;
    
        posLista = busca_Ord(chave1);

        while (posLista < n){
            L[posLista].numReg = L[posLista + 1].numReg;
            posLista++;
        }
        n = n - 1;  
}

void InserirDoAlterar(int x){
    
    int posicaoDaChave = n;

    while (posicaoDaChave > 0 && L[posicaoDaChave].numReg > x){
        posicaoDaChave--;
    }
        
    for (int i = n; i > posicaoDaChave; i--){
        L[i + 1].numReg = L[i].numReg;
    }
    L[posicaoDaChave + 1].numReg = x;
    n++;
    
}

void Alterar(){
    int numeroRegistroASerAlterado;
    int indiceNumero;
    int novoNumeroRegistrado;

    if (n != 0){

        cout << "Digite o número do registro que deseja alterar: ";
        cin >> numeroRegistroASerAlterado;

        indiceNumero = busca_Ord(numeroRegistroASerAlterado);
        if (indiceNumero != 0){
                
                int chave;
                cout << "Digite o novo registro a ser inserido: ";
                cin >> novoNumeroRegistrado;

                int indiceDaChave = busca_Ord(novoNumeroRegistrado);

                if (indiceDaChave != 0)
                {
                    cout << "Esse número ja está registrado na lista." << endl;
                } else {
                
                    ExcluirDoAlterar(numeroRegistroASerAlterado);
                    InserirDoAlterar(novoNumeroRegistrado);

                    cout << "Registro: " << numeroRegistroASerAlterado << " alterado para: " << novoNumeroRegistrado << " com sucesso!" << endl;
                } 
        } else { cout << "Número de registro não encontrado." << endl; cout << "" << endl;}    
    } else { cout << "Lista vazia." << endl; cout << "" << endl;}
}

void Listar(){
    int z = 1;
    if (n < 1){
        cout << "A lista está vazia." << endl;
        cout << "" << endl;
    } else {
        cout << "LISTA DE REGISTRO DE FUNCIONÁRIOS: " << endl;
        while (z <= n)
        {
            cout << "Funcionário Nº " << z << " - " << "Registro: " << L[z].numReg << endl;
            z++;
        }
        cout << endl;
    }
}

int main(int argc, char** argv){
    
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    int numOption;
    
    cout << "";
    cout << "1- Inserir novo funcionário" << endl;
    cout << "2- Buscar registro do funcionário" << endl;
    cout << "3- Alterar registro" << endl;
    cout << "4- Excluir funcionário" << endl;
    cout << "5- Listar todos os funcionários" << endl;
    cout << "6- Sair" << endl; 
    cout << "";
    
    cin >> numOption;
    
    while (numOption != 6)
    {            
        switch (numOption)
        {
        case 1:
            cout << "Novo Funcionário - ";
            Inserir();
            break;

        case 2 :
            int numBusca;
            cout << "Número de registro: " << endl;;
            cin >> numBusca;
            if (busca_Ord(numBusca) == 0)
            {
                cout << "Registro inexistente." << endl;
                cout << "" << endl;
                }
            else {
                cout << "Funcionário de registro: " << numBusca << " encontrado na posição: " << busca_Ord(numBusca) << "." << endl;
                cout << "" << endl;
                }
            break;
        case 3 :
            Alterar();
            break;
        case 4 :
            Excluir();      
            break;
        case 5 :
            Listar();
            break;
        case 6 :
            break;
        }
        
        cout << "";
        cout << "1- Inserir novo funcionário" << endl;
        cout << "2- Buscar registro do funcionário" << endl;
        cout << "3- Alterar registro" << endl;
        cout << "4- Excluir funcionário" << endl;
        cout << "5- Listar todos os funcionários" << endl;
        cout << "6- Sair" << endl;
        cout << "";
        cin >> numOption;
        
    }
    return 0;
}