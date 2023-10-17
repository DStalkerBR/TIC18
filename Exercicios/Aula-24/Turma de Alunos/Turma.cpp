#include "classes.hpp"

void Turma::adicionarAluno(Aluno* aluno){
    this->alunos.push_back(aluno);
}

void Turma::listarAlunos(){
    for (Aluno* aluno:this->alunos){
        aluno->exibirDetalhes();
    }
}
