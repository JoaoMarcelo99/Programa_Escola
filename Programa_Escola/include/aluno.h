#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <iostream>
#include <iomanip>

class aluno
{
    public:
        aluno();

        std::string Getcodigo() { return codigo; }
        void Setcodigo(std::string val) { codigo = val; }
        std::string Getnome() { std::cout << nome; return nome;}
        void Setnome(std::string val) { nome = val; }

    protected:

    private:
        std::string codigo;
        std::string nome;
};

#endif // ALUNO_H
