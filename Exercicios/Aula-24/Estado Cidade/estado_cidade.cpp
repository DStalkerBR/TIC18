
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Estado {
    private:
    string nome, uf;

    public:
    
    Estado(string nome, string uf){
        this->nome = nome;
        this->uf = uf;
    }

    string get_nome(){
        return nome;
    }

    string get_uf(){
        return uf;
    }

};

class Cidade {
    private:
    string nome;
    Estado *estado;

    public: 
    Cidade(string nome, Estado* estado){
        this->nome = nome;
        this->estado = estado;
    }

    Cidade(){
    }

    void set_nome(string nome){
        this->nome = nome;
    }

    void set_estado(Estado* estado){
        this->estado = estado;
    }

    string get_nome(){
        return this->nome;
    }

    Estado* get_estado(){
        return this->estado;
    }
};

int main()
{
    vector<Estado> estados;
    vector<Cidade> cidades;
    string resposta = "s";
    string nome, uf;
    int num_estados, num_cidades;
    
    cout << "Digite quantos estados deseja criar: " << endl;
    cin >> num_estados;
    cin.ignore();

    for (int i=0; i<num_estados; i++) { 
        cout << "Informe o nome do estado" << endl;
        getline(cin, nome);
        cout << "Informe a UF do estado" << endl;
        getline(cin, uf);
        Estado novo_estado(nome, uf);
        estados.push_back(novo_estado);
        cout << "Adicionando estado:::::" << novo_estado.get_nome() << " - " << novo_estado.get_uf() << endl;
    }


    cout << "Digite quantas cidades deseja criar: " << endl;
    cin >> num_cidades;
    cin.ignore();

    for (int i=0; i<num_cidades; i++) { 
        cout << "Informe o nome da cidade" << endl;
        getline(cin, nome);
        cout << "Informe a UF do estado da cidade " << nome << endl;
        getline(cin, uf);
        Cidade nova_cidade;
        nova_cidade.set_nome(nome);
        for (int i=0; i < estados.size(); i++){
            if (estados[i].get_uf() == uf){
                cout << "Adicionando " << estados[i].get_nome() << endl;
                nova_cidade.set_estado(&estados[i]);
            }
        }
        cidades.push_back(nova_cidade);
        cout << "Adicionando cidade:::::" << nova_cidade.get_nome() << " - " << nova_cidade.get_estado()->get_nome() << "/"<< nova_cidade.get_estado()->get_uf()  << endl;
    }
 
    cout << endl << "Estados cadastrados: " << endl;
    for(auto estado:estados){

        cout << "Estado: " << estado.get_nome() << " - " << estado.get_uf() << endl;
    }

    cout << endl <<  "Cidades cadastradas: " << endl;
    for(auto cidade:cidades){
        cout << "Cidade: " << cidade.get_nome() << " - " << cidade.get_estado()->get_nome() << "/"<< cidade.get_estado()->get_uf()  << endl;
    }
    

    return 0;
}
