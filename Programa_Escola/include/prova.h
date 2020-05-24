#ifndef PROVA_H
#define PROVA_H
#include <string>
#include <iostream>
#include <iomanip>

class prova
{
    public:
        prova();

        void Setnome(std::string val) { nome = val; }
        unsigned int Getpeso() { return peso; }
        void Setpeso(unsigned int val) { peso = val; }
        std::string Getnome() { /*std::cout << nome;*/ return nome;}

    protected:

    private:
        std::string nome;
        unsigned int peso;
};

#endif // PROVA_H
