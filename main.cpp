#include <iostream>
#include<string>
#include"sisu.hpp"
#include "lista.hpp"
#include "curso.hpp"
#include "aluno.hpp"

using std::string;

int main (){
    int qtdCursos, qtdAlunos;
    int i;
    string nomeCurso, nomeAluno;
    float notaAluno;
    int vagasCurso, curso1, curso2;
    Lista<Curso> listaCursos;
    Lista<Aluno> listaAlunos;    
    Aluno* aluno;
    Curso* curso;

    std::cin >> qtdCursos >> qtdAlunos;

    for(i=0; i < qtdCursos; i++){
        std::cin.ignore();
        std::getline(std::cin, nomeCurso);
        std::cin >> vagasCurso;
        curso = new Curso(nomeCurso, vagasCurso, i);
        listaCursos.insereFim(*curso);
    }

    for(i=0; i < qtdAlunos; i++){
        std::cin.ignore();
        std::getline(std::cin, nomeAluno);
        std::cin >> notaAluno;
        std::cin >> curso1;
        std::cin >> curso2;
        aluno = new Aluno(nomeAluno, notaAluno, curso1, curso2, i);
        listaAlunos.insereFim(*aluno);
    }

    

    listaAlunos.inicio = listaAlunos.quickSort(listaAlunos.inicio, listaAlunos.fim); //ordena a lista de alunos
    
    SistemaSisu sisu(listaCursos, listaAlunos); //classe auxiliar
    
    sisu.classificacao(); //classifica os alunos
    
};