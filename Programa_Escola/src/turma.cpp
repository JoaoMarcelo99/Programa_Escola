#include "turma.h"
#include <iostream>
#include <vector>

using namespace std;

turma::turma()
{
    this->numAlunos = 0;
    this->numNotas=0;
    this->numProvas=0;
}


void turma::Getalunos() {

    if(alunos.size() == 0){
        std::cout << "Nenhum aluno matriculado nessa turma"<<endl;
    }
    for(unsigned int i = 0; i < alunos.size(); i++){
        cout<<"|Aluno: ";
        alunos[i].Getnome();
        cout<<" | Matricula: "<<alunos[i].Getcodigo()<<" |" <<endl;
    }
}

void turma::Getnotas() {

    if(notas.size()==0){
        std::cout << "Nenhuma nota atribuida nessa turma"<<endl;
        return;
    }
    for(int i = 0; i <notas.size(); i++){
        std::cout << "|Aluno: ";
        notas[i].Getaluno().Getnome();
        std::cout<< " | Prova: ";
        notas[i].Getprova().Getnome();
        std::cout<<" | Nota: ";
        cout<<notas[i].Getvalor();
        cout<<endl;
    }
}

void turma::Getprovas() {

    if(provas.size() == 0){
        std::cout << "Nenhuma prova atribuida nessa turma"<<endl;
        return;
    }
    for(int i = 0; i == numProvas; i++){
        std::cout << "|Prova: ";
        provas[i].Getnome();
        std::cout << " | Peso: ";
        cout<< provas[i].Getpeso();
        std::cout<<endl;
    }
}

void turma::Setalunos(aluno val) {
    alunos.push_back(val);

}

void turma::Setprovas(prova val) {
    provas.push_back(val);

}

void turma::Setnotas(nota val) {
    notas.push_back(val);

}

void turma::GetMedia(){
    double MediaFinal;
    double media = 0;
    int peso = 0;

    for(int i=0; i<alunos.size();i++){
        for(int j=0; j<notas.size(); j++){

          if(notas[j].Getaluno().Getcodigo() == alunos[i].Getcodigo()){
                media+= (notas[j].Getvalor())*(notas[j].Getprova().Getpeso());
                peso+=notas[j].Getprova().Getpeso();
               }

        }

        MediaFinal = media/peso;

        cout<<"|Aluno: ";
        cout<<alunos[i].Getcodigo();
        cout<<" |Media Final: "<<MediaFinal<<" | "<<endl;

        //MediaFinal = 0;
        media = 0;
        peso = 0;


    }

}

void turma::GetMedia(int k){
     double MediaFinal;
    double media = 0;
    int peso = 0;

     for(int j=0; j<notas.size(); j++){
        cout<<"|Aluno: " << alunos[k].Getcodigo() <<" | "<<alunos[k].Getnome();
          if(notas[j].Getaluno().Getcodigo() == alunos[k].Getcodigo()){

                media+= (notas[j].Getvalor())*(notas[j].Getprova().Getpeso());
                peso+=notas[j].Getprova().Getpeso();
               }

        }
    MediaFinal = media/peso;

    cout<< " |Media Final: "<<MediaFinal<<endl;;


}
