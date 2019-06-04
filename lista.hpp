#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "aluno.hpp"

template <class Sisu> 
class Lista{
    public:
     	Sisu* inicio; 
        Sisu* fim; 

	    Lista(); 
        Lista(Sisu s);
        
        void percorreLista();
        int tamanhoLista();
        void insereFim(Sisu s);
        void insereComeco(Sisu s);
        Aluno* divideLista(Aluno *cabeca, Aluno *f, Aluno **novoInicio, Aluno **novoFim);
        Aluno* quickSort(Aluno* cabeca, Aluno* cauda);
};
#endif
