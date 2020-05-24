#ifndef NOTA_H
#define NOTA_H
#include "prova.h"
#include "aluno.h"

class nota
{
    public:
        nota();

        double Getvalor() { return valor; }
        void Setvalor(double val) { valor = val; }
        prova Getprova() { return Prova; }
        void Setprova(prova val) { Prova = val; }
        aluno Getaluno() { return Aluno; }
        void Setaluno(aluno val) { Aluno = val; }


    protected:

    private:
        double valor;
        prova Prova;
        aluno Aluno;
};

#endif // NOTA_H
