#include "classes.hpp"

int main(int argc, char const *argv[])
{
    Aluno aluno1("Romario Santana", 1);
    Aluno aluno2("Ronaldinho Gaucho", 2);
    Aluno aluno3("Bruno Monteiro", 3);
    Turma turma;
    turma.adicionarAluno(&aluno1);
    turma.adicionarAluno(&aluno2);
    turma.adicionarAluno(&aluno3);
    turma.listarAlunos();
    return 0;
}

