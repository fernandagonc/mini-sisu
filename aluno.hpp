#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include<string>

using std::string;

class Aluno{
    private:
        int _curso1, _curso2, _indice;
        float _nota;
        string _nome;
        bool is_classificado;
        Aluno* prox;
        
    public:
        Aluno();
        Aluno(string nome, float nota, int curso1, int curso2, int indice);
        string getNome();
        void setNome(string nome);
        float getNota();
        void setNota(float nota);
        int getCurso1();
        void setCurso1(int curso1);
        int getCurso2();
        void setCurso2(int curso2);
        int getIndice ();
        void setIndice(int indice);
        Aluno* getProx();
		void setProx(Aluno* prox);
        void setClassificado(bool is_classificado);
        bool isClassificado();
};

#endif
