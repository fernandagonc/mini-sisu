#ifndef SISU_H
#define SISU_H

#include <iostream>
#include<string>
#include<vector>
#include"aluno.hpp"
#include"curso.hpp"
#include"lista.hpp"


class SistemaSisu{
    public:
        Lista<Curso> cursos;
        Lista<Aluno> alunos;

        SistemaSisu();
        SistemaSisu(Lista<Curso> listaCurso, Lista<Aluno> listaAluno);
        void classificacao();
};

#endif
