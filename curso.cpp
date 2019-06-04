#include <iostream>
#include "curso.hpp"

using namespace std;

Curso::Curso(){}

Curso::Curso(string nome, int vagas, int indice){
    setNome(nome);
    setVagas(vagas);
    setIndice(indice);
    this->_notaCorte = 0;
    this->prox = NULL;
    this->_matriculados = 0;
} 

string Curso::getNome(){return this->_nome;}

void Curso::setNome(string nome){this->_nome = nome;}

int Curso::getVagas(){return this->_vagas;}

void Curso::setVagas(int vagas){this->_vagas = vagas;}

int Curso::getIndice(){return this->_indice;}

void Curso::setIndice(int indice){this->_indice = indice;}

float Curso::getNota(){return this->_notaCorte;}

void Curso::setNota(float nota){this->_notaCorte = nota;}

Curso* Curso::getProx(){return this->prox;}

void Curso::setProx(Curso* prox){this->prox = prox;}

void Curso::printClassificados(){
    std::cout << "Classificados \n";
    alunosDesseCurso.percorreLista();
}
void Curso::addAlunoDesseCurso(Aluno aluno){
    alunosDesseCurso.insereFim(aluno);
}

void Curso::printListaEspera(){
    std::cout << "Lista de espera \n";
    listaEspera.percorreLista();
}

void Curso::addListaEspera(Aluno aluno){
    listaEspera.insereFim(aluno);
}

int Curso::getNumeroMatriculados (){return this->_matriculados;}

void Curso::setNumeroMatriculados(int matriculados){this->_matriculados = matriculados;}