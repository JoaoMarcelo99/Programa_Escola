#ifndef TURMA_H
#define TURMA_H
#include <string>
#include <iomanip>
#include <vector>
#include "aluno.h"
#include "prova.h"
#include "nota.h"

class turma
{
    public:
        turma();

        std::string Getcodigo() { return codigo; }
        void Setcodigo(std::string val) { codigo = val; }

        std::string Getnome() { return nome; }
        void Setnome(std::string val) { nome = val; }

        void Getprovas();
        void Setprovas(prova val);

        void Getnotas();
        void Setnotas(nota val);

        void Getalunos();
        void Setalunos(aluno val);

        void GetMedia();
        void GetMedia(int i);

        std::vector<prova> provas;
        std::vector<nota> notas;
        std::vector<aluno> alunos;

    protected:

    private:

        unsigned int numAlunos;
        unsigned int numNotas;
        unsigned int numProvas;

        std::string codigo;
        std::string nome;


};

#endif // TURMA_H
