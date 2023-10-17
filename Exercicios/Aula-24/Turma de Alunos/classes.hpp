#include<string>
#include<vector>

using namespace std;

class Aluno {
    private:
    string nome;
    int numero_id;

    public:
    Aluno(string nome, int numero_id);

    void exibirDetalhes();
    

};

class Turma {
    private:
    vector<Aluno*> alunos;

    public:
    void adicionarAluno(Aluno* aluno);

    void listarAlunos();
};