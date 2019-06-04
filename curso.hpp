#ifndef CURSO_H
#define CURSO_H

#include <iostream>
#include <string>
#include"aluno.hpp"
#include"lista.hpp"
using std::string;

class Curso{
    private:
        int _vagas, _indice, _matriculados, _tam;
        float _notaCorte;
        string _nome;
        Curso* prox;
        Lista<Aluno> alunosDesseCurso;
        Lista<Aluno> listaEspera;
        
    public:
        Curso();
        Curso(string nome, int vagas, int indice);
        string getNome();
        void setNome(string nome);
        int getVagas();
        void setVagas(int vagas);
        int getIndice ();
        void setIndice(int indice);
        float getNota ();
        void setNota(float nota);
        Curso* getProx();
		void setProx(Curso* prox);
        void printClassificados();
        void addAlunoDesseCurso(Aluno aluno);
        void printListaEspera();
        void addListaEspera(Aluno aluno);
        int getNumeroMatriculados ();
        void setNumeroMatriculados (int matriculados);

};

#endif
