#include "classes.hpp"
#include <iostream>

Aluno::Aluno(string nome, int numero_id){
    this->nome = nome;
    this->numero_id = numero_id;
}

void Aluno::exibirDetalhes(){
    cout << "Nome: " << this->nome << endl; 
    cout << "Numero de Identificao: " << this->numero_id << endl;
}