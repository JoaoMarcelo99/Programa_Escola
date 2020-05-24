#ifndef ESCOLA_H
#define ESCOLA_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "turma.h"
#include "aluno.h"


using namespace std;

class escola
{
    public:
        escola();

        string Getcodigo() { return codigo; }
        void Setcodigo(string val) { codigo = val; }

        string Getnome() { return nome; }
        void Setnome(string val) { nome = val; }

        void GetTurmas();
        void SetTurmas(turma val);

        void GetAlunos();
        void SetAlunos(aluno val);

        std::vector<turma> Turmas;
        std::vector<aluno> Alunos;

    protected:

    private:
        string codigo;
        string nome;


};

#endif // ESCOLA_H
