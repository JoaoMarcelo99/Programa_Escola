#include "escola.h"
#include "turma.h"
#include "aluno.h"
#include <vector>

escola::escola()
{
    //ctor
}

void escola::GetTurmas(){
     if(Turmas.size() == 0){
        std::cout << "Nenhuma turma cadastrada nessa escola"<<endl;
    }
    for(int i = 0; i < Turmas.size(); i++){
        cout<<"|Turma: ";
       cout<< Turmas[i].Getnome();
        cout<<" | Codigo: "<<Turmas[i].Getcodigo()<<" |" <<endl;

    }

}


void escola::GetAlunos(){
    if(Alunos.size() == 0){
        std::cout << "Nenhum aluno matriculado na escola"<<endl;
    }
    for(int i = 0; i < Alunos.size(); i++){
        cout<<"|Aluno: ";
       Alunos[i].Getnome();
        cout<<" | Matricula: "<<Alunos[i].Getcodigo()<<" |" <<endl;
    }
}

void escola::SetAlunos(aluno val){
    Alunos.push_back(val);
}

void escola::SetTurmas(turma val){
    Turmas.push_back(val);
}
