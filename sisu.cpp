#include <iostream>
#include <algorithm> 
#include "sisu.hpp"

SistemaSisu::SistemaSisu(){}

SistemaSisu::SistemaSisu(Lista<Curso> listaCurso, Lista<Aluno> listaAluno){
    this->cursos = listaCurso;
    this->alunos = listaAluno;
}

//Função que organiza os alunos na lista de classificados e de espera para cada curso

void SistemaSisu::classificacao(){ 
    
    Curso* auxC= NULL;  //variável auxiliar para percorrer a lista de cursos
    int matriculados; // variável auxiliar para inserir alunos apenas se houver vagas

    Aluno* auxA = alunos.inicio; //variável auxiliar para percorrer a lista de alunos

    //Laço de repetição que a cada aluno o classifica ou coloca na lista de espera do seu primeiro curso
    //se não for classificado para a primeira opção, verificamos a segunda opção e o classificamos ou colocamos
    //na lista de espera
    while (auxA != NULL){
        auxC = cursos.inicio;
        while(auxC){
            if (auxA->getCurso1() != auxC->getIndice()){ //procura a primeira opção de curso do aluno
                auxC = auxC->getProx();
            }
            else{
                matriculados = auxC->getNumeroMatriculados();
                if(matriculados < auxC->getVagas()){ // verifica se ainda existem vagas no curso         
                    auxC->addAlunoDesseCurso(*auxA); //se sim, o aluno é matriculado
                    auxA->setClassificado(true); //colocamos o atributo de classificado como true, para evitar passar pelo segundo curso atoa
                    auxC->setNumeroMatriculados(matriculados+1); //aumentamos em um o número de classificados
                    auxC->setNota(auxA->getNota()); //atualizamos a nota de corte do curso
                } 
                else{// se não houver vagas, colocamos o aluno na lista de espera da sua primeira opção de curso
                    auxC->addListaEspera(*auxA);
                }
                auxC = auxC->getProx(); 
            }
            
        }
        //verifica se o aluno já foi classificado na sua primeira opção
        //se não, verificamos a segunda opção, se sim, passamos para o próximo aluno
        if(!auxA->isClassificado()){
            auxC = cursos.inicio; //voltamos ao início da lista para procurar a segunda opção do aluno
            //essa parte é análoga à classificação para a primeira opção
            while(auxC){     
                if (auxA->getCurso2() != auxC->getIndice()){
                    auxC = auxC->getProx();
                }
                else{
                    matriculados = auxC->getNumeroMatriculados(); 
                    if(matriculados < auxC->getVagas()){  
                        auxC->addAlunoDesseCurso(*auxA);
                        auxC->setNumeroMatriculados(matriculados+1);
                        auxC->setNota(auxA->getNota());
                    } 
                    else{
                        auxC->addListaEspera(*auxA);
                    } 
                    auxC = auxC->getProx(); 
                }
            }  
        }
        //depois de classificar o aluno, passamos ao próximo até que não haja próximos (getProx == NULL)
        auxA = auxA->getProx(); 
    }

    //Imprime a saída do algoritmo: classificados e lista de espera de cada curso
    auxC = cursos.inicio;
    while(auxC){
        std::cout << auxC->getNome() << " " << auxC->getNota() << "\n"; 
        auxC->printClassificados();
        auxC->printListaEspera();

        std::cout << "\n";
        
        auxC = auxC->getProx(); 
    }


}
