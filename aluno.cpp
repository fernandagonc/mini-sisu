#include <iostream>
#include "aluno.hpp"

using namespace std;

Aluno::Aluno(){}

Aluno::Aluno(string nome, float nota, int curso1, int curso2, int indice){
    setNome(nome);
    setNota(nota);
    setCurso1(curso1);
    setCurso2(curso2);
    setIndice(indice);
    this->prox = NULL;
    is_classificado = false;
} 

string Aluno::getNome(){return this->_nome;}

void Aluno::setNome(string nome){this->_nome = nome;}

float Aluno::getNota(){return this->_nota;}

void Aluno::setNota(float nota){this->_nota = nota;}

int Aluno::getCurso1(){return this->_curso1;}

void Aluno::setCurso1(int curso1){this->_curso1 = curso1;}

int Aluno::getCurso2(){return this->_curso2;}

void Aluno::setCurso2(int curso2){this->_curso2 = curso2;}

int Aluno::getIndice(){return this->_indice;}

void Aluno::setIndice(int indice){this->_indice = indice;}

Aluno* Aluno::getProx(){return this->prox;}

void Aluno::setProx(Aluno* prox){this->prox = prox;}

void Aluno::setClassificado(bool is_classificado){this->is_classificado = is_classificado;}

bool Aluno::isClassificado(){return this->is_classificado;}