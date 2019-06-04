#include <iostream>
#include <algorithm>
#include"lista.hpp"
#include "curso.hpp"
#include "aluno.hpp"

template<class Sisu> Lista<Sisu>::Lista(Sisu s){
    inicio = new Sisu;
	fim = inicio;
}

template<class Sisu> Lista<Sisu>::Lista(){
    inicio = NULL;
    fim = NULL;
}

template<class Sisu> int Lista<Sisu>::Lista::tamanhoLista(){
    if(inicio == NULL)
        return 0;

    Sisu* s = inicio;
    int tam = 0;
    
    while (s){
        s = s->getProx();
        tam++;
    }
    
    return tam;
}

//imprime os dados que interessam ao problema: nome do curso ou aluno e nota de corte do curso ou nota do aluno
template<class Sisu> void Lista<Sisu>::Lista::percorreLista(){
    Sisu* s = inicio;

    if(inicio == NULL)
        return;
    else{
        while(s){
            std::cout << s->getNome() << " " << s->getNota() << "\n";
            s = s->getProx();
        }
    }
}


template<class Sisu> void Lista<Sisu>::Lista::insereFim(Sisu s){
    Sisu* novo = new Sisu(s);

    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }
    else{
        fim->setProx(novo);
        fim = novo;
    }
    fim->setProx(NULL);
}

template<class Sisu> void Lista<Sisu>::insereComeco(Sisu s){
    Sisu* novo = new Sisu(s);

    if(inicio == NULL){
        inicio = novo;
        fim = novo;
        fim->setProx(NULL);
    }
    else{
        novo->setProx(inicio);
        inicio = novo;
    }
} 

//https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/ - Código referência 
//utilizado na adaptação da função quickSort

template <>
Aluno* Lista<Aluno>::divideLista(Aluno *cabeca, Aluno *f ,Aluno **novoInicio, Aluno **novoFim){ 
    Aluno *pivo = f;
    Aluno *anterior = NULL, *atual = cabeca, *cauda = pivo; 
   
    //Durante a divisão, a cabeca e a cauda podem mudar, por isso damos update em novoInicio e novoFim 
    while (atual != pivo) { 
        if (atual->getNota() > pivo->getNota() || (atual->getIndice() < pivo->getIndice() && atual->getNota() == pivo->getNota()) ){ 
            //O primeiro nó que tem um valor de nota maior do que o pivô ou possui a mesma nota mas entrou antes no sistema
            //vira a nova cabeça da lista
            if ((*novoInicio) == NULL) 
                (*novoInicio) = atual; 

            anterior = atual;   
            atual = atual->getProx(); 
        } 
        else{ //Se o nó atual é menor do que o pivo, move-se esse nó para o fim da lista
                //tornando-se o próximo da cauda antiga e tornando-se a nova cauda
            if(anterior) 
                anterior->setProx(atual->getProx()); 
           
            Aluno *aux = atual->getProx(); 
            atual->setProx(NULL); 
            cauda->setProx(atual); 
            cauda = atual; 
            atual = aux; 
        } 
    } 

    //Se a nota do pivo é o menor elemento da lista, o pivô torna-se a cabeca
    if ((*novoInicio) == NULL) 
        (*novoInicio) = pivo; 
  
    //Update novoInicio para o último nó atual
    (*novoFim) = cauda; 

    //Retorna o nó pivô
    return pivo; 
} 

template <>
Aluno* Lista<Aluno>::quickSort(Aluno* cabeca, Aluno* cauda){ 
    // Condição de parada
    if (!cabeca || cabeca == cauda) 
        return cabeca; 
  
    Aluno *novoInicio = NULL, *novoFim = NULL; 
    //Divide a lista, o novoInicio e o novoFim serão atualizados na função divideLista
    Aluno *pivo = divideLista(cabeca, cauda, &novoInicio, &novoFim); 

    //Se o pivô é o menor elemento, não há necessidade de recursão para o lado esquerdo da divisão feita 
    if (novoInicio != pivo) {      
        //Set o nó anterior ao pivô como NULL
        Aluno *aux = novoInicio; 

        while (aux->getProx() != pivo){
            aux = aux->getProx(); 
        }
        aux->setProx(NULL); 

        //Chamada recursiva para organizar a lista antes do pivô (lado esquerdo)
        novoInicio = quickSort(novoInicio, aux); 

        //Muda o próximo do último nó da lista do lado esquerdo        
        aux = novoInicio;
        while (aux != NULL && aux->getProx() != NULL) 
            aux = aux->getProx(); 
        
        aux->setProx(pivo); 
    } 
    //Chamada recursiva para organizar a lista depois do pivô (lado direito)
    Aluno *aluno=quickSort(pivo->getProx(), novoFim); 
    pivo->setProx(aluno); 
  
    return novoInicio; 
} 

template class Lista<Aluno>;
template class Lista<Curso>;
