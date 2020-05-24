#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>

#include <fstream>

#include <dirent.h>
#include <cstdlib>
#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <vector>



#include <stdio.h>  /* defines FILENAME_MAX */
#define WINDOWS  /* uncomment this line to use it for windows.*/
#ifdef WINDOWS
#include <direct.h>
#define endereco _getcwd
#else
#include <unistd.h>
#define endereco getcwd
#endif
#include<iostream>

#include <dirent.h>
#include <cstdlib>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "turma.h"
#include "nota.h"
#include "escola.h"

using namespace std;

vector<escola> TodasAsEscolas;

vector<string> save;
vector <string> codigo;


string GetEndereco() { //Funcao para pegar o endereço do programa
  char buff[FILENAME_MAX];
  endereco( buff, FILENAME_MAX );
  std::string endereco(buff);
  return endereco;
}

const string EnderecoPrograma = GetEndereco(); // Variavel com o endereco do programa


void CriarPasta(string nomedapasta) {

    const char* nome = nomedapasta.c_str();
    mkdir(nome);
}

ofstream arquivo;



//Funçoes Escola
void MenuEscolaGeral();
void MenuAdicionarEscola();
void MenuAcessarEscola();
void MenuEscola(escola &acessada);
void ListarEscolas();
void SalvarEscolas(escola &novaescola);

//Funçoes Turmas
void MenuAdicionarAluno(escola &acessada);
void ListarAlunos(escola &acessada);
void SalvarAluno(escola &acessada,aluno &novoAluno);

void MenuTurma(turma &acessada, escola &escolaPassada);
void MenuAcessarTurma(escola &acessada);
void MenuAdicionarTurma(escola &acessada);
void ListarTurmas(escola &acessada);
void SalvarTurmas(escola &acessada,turma &novaturma);

void MenuAdicionarProva(turma &acessada, escola &passada);
void MenuAdicionarNota(turma &acessada, escola &passada);
void MenuMatricularAluno(turma &acessada, escola &escolaPassada);
void ListarAlunosTurma(turma &acessada);
void ListarProvas(turma &acessada);
void SalvarAlunoTurma(escola &acessada,aluno &matriculado,turma &novaturma);
void SalvarProva(escola &acessada,prova &prova,turma &novaturma);
void SalvarNota(escola &acessada,nota &nota,turma &novaturma);

void ImprimirBoletim(turma &acessada, escola &escolaPassada);
void ImprimirBoletimTurma(turma &acessada);
void CarregarArquivoEspecifico(char *dir_name,string arquivo);
void CarregarArquivoEspecifico(char *dir_name,string arquivo,vector <string>save);
void CarregarArquivos();


int main()
{
    int ligado = 0;
    int escolha;
    string caminho,caminho2;
    string enderecop;


    CriarPasta("Memoria");


/*
    cout<<"Digite o nome da pasta: ";
    getline(cin,caminho);
    cout<<"Digite o nome da pasta: ";
    getline(cin,caminho2);
    enderecop= caminho + "/" + caminho2;
    cout<<enderecop;
    CriarPasta(caminho);
    CriarPasta(enderecop);
*/
/*
            aluno testeAluno;
            testeAluno.Setcodigo(123);
            testeAluno.Setnome("Nome aluno Teste");

            turma testeTurma;
            testeTurma.Setnome("Turma nome teste");
            testeTurma.Setcodigo("Codigo Turma Teste");

            escola testeEscola;
            testeEscola.Setnome("Nome escola Teste");
            testeEscola.Setcodigo("Codigo Escola Teste");
            testeEscola.SetAlunos(testeAluno);
            testeEscola.SetTurmas(testeTurma);


            MenuMatricularAluno(testeTurma,testeEscola);
            ListarAlunosTurma(testeTurma);

        */

        //mkdir(caminho,0700);


         cout<<"##################### PROGRAMA ESCOLA #####################" <<endl;
         cout<<"############## Desenvolvido por Joao Marcelo ##############" <<endl;
         cout<<"################### Ad Astra Per Aspera ###################" <<endl;
         system("pause>>null");


       while(ligado!=-1){
            system("cls");
             cout<<"##################### PROGRAMA ESCOLA #####################" <<endl;
            cout<<"Digite [1] para iniciar o programa"<<endl;
            cout<<"Digite [3] para listar as pastas"<<endl;
            cout<<"Digite [2] para sair do programa"<<endl;

            cout<< "Digite sua opcao: ";
            cin >> escolha;

            switch(escolha){
            case 1:
            MenuEscolaGeral();

            break;
            case 2:
                ligado=-1;
            break;
            case 3:
                CarregarArquivos();
                break;

            default:
                cout<<endl<<"Codigo Invalido!"<<endl;
                escolha=0;
            break;
            }

       }
    cout<<"###################### Programa encerrado ########################"<<endl;


    return 0;
}

void MenuEscolaGeral(){

    int escolha, ligado = 0;
    while(ligado!=-1){
    system("cls");

    cout<<endl<<"################## MENU GERAL DAS ESCOLAS #################"<<endl;

    cout<<"Digite [1] para adicionar uma escola"<<endl;
    cout<<"Digite [2] para acessar uma escola"<<endl;
    cout<<"Digite [3] para listar as escolas"<<endl;
    cout<<"Digite [4] para voltar"<<endl;

    cout<<"Digite sua opcao: ";
    cin >> escolha;

    switch(escolha){
        case 1:
            MenuAdicionarEscola();
        break;

        case 2:
            MenuAcessarEscola();
        break;

        case 3:
            ListarEscolas();
            break;

        case 4:
            ligado = -1;
            return;

        default:
            cout<<"Escolha Invalida!!!"<<endl;
        break;

    }

}

}
void MenuAdicionarEscola(){
    system("cls");
    escola novaescola;
    string codigo;
    string nome;

    cout<<endl<<"########## CRIANDO ESCOLA ##########"<<endl;

    cin.get();
    cout<<"Digite o codigo da escola: ";
    getline(cin,codigo);
    novaescola.Setcodigo(codigo);
    cout<<"Digite o nome da escola: ";
    getline(cin,nome);
    novaescola.Setnome(nome);
    for(int i = 0; i < TodasAsEscolas.size(); i++){
        if(novaescola.Getcodigo()==TodasAsEscolas[i].Getcodigo()){
            cout<<"Ja existe uma escola com esse codigo!"<<endl;
            system("PAUSE");
            return;
        }
    }
    TodasAsEscolas.push_back(novaescola);
    SalvarEscolas(novaescola);

    cout<<"Escola cadastrada com sucesso!"<<endl;
    system("PAUSE");

}

void MenuAcessarEscola(){
    system("cls");
    string codigo;
    int save=-1;
     cout<<"################## ACESSANDO ESCOLAS #############"<<endl;
    cin.get();
    cout<<"Digite o codigo da escola que deseja acessar: ";
    getline(cin,codigo);
        for(int i = 0; i<TodasAsEscolas.size(); i++){

            if(codigo == TodasAsEscolas[i].Getcodigo()){
                save = i;
                break;
            }
        }
        if(save==-1){
            cout<<"Nao existe escola cadastrada com esse numero"<<endl;
            }
        else{
        MenuEscola(TodasAsEscolas[save]);
        }
        system("PAUSE");
}

void MenuEscola(escola &acessada){

    int ligado = 0;

    int escolha;

    while(ligado!=-1){
    system("cls");
    cout<<endl<<"####################### MENU ESCOLA #######################"<<endl;
    cout<<"Escola: "<<acessada.Getnome()<<" | Codigo: "<<acessada.Getcodigo()<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"Digite [1] para adicionar uma turma"<<endl;
    cout<<"Digite [2] para adicionar um aluno"<<endl;
    cout<<"Digite [3] para acessar uma turma"<<endl;
    cout<<"Digite [4] para listar as turmas"<<endl;
    cout<<"Digite [5] para listar os alunos"<<endl;
    cout<<"Digite [6] para voltar"<<endl;

    cout<<"Digite sua opcao: ";
    cin >> escolha;

    switch(escolha){
        case 1:
            MenuAdicionarTurma(acessada); //FEITO
        break;

        case 2:
            MenuAdicionarAluno(acessada); //FEITO
        break;

        case 3:
            MenuAcessarTurma(acessada);
        break;

        case 4:
            ListarTurmas(acessada); //FEITO
        break;

        case 5:
            ListarAlunos(acessada);//FEITO
        break;

        case 6:
            ligado=-1;
        break;
        default:
            cout<<"Escolha Invalida!!!"<<endl;
        break;
    }
    }

}

void ListarEscolas(){
    system("cls");
    cout<<"################## LISTANDO ESCOLAS #############"<<endl;
    if(TodasAsEscolas.size()==0){
        cout<<"Nao existem escolas cadastradas"<<endl;
    }

    for(int i = 0; i < TodasAsEscolas.size(); i++){
        cout<<endl;
        cout<<"|Nome da escola: "<<TodasAsEscolas[i].Getnome();
        cout<<" | Codigo: "<< TodasAsEscolas[i].Getcodigo();
    }
    cout<<endl;
    system("PAUSE");
}


void MenuTurma(turma &acessada, escola &escolaPassada){

    int ligado = 0;
    int escolha;
    while(ligado != -1){
    system("cls");
    cout<<endl<<"######################## MENU TURMA #######################"<<endl;
    cout<<"Escola: "<<escolaPassada.Getnome()<<" | Codigo: "<<escolaPassada.Getcodigo()<<endl;
    cout<<"Turma: "<<acessada.Getnome()<<" | Codigo: "<<acessada.Getcodigo()<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"Digite [1] para adicionar uma prova"<<endl;
    cout<<"Digite [2] para adicionar uma nota"<<endl;
    cout<<"Digite [3] para matricular um aluno"<<endl;
    cout<<"Digite [4] para listar os alunos"<<endl;
    cout<<"Digite [5] para listar as provas"<<endl;
    cout<<"Digite [6] para listar as medias de um aluno"<<endl;
    cout<<"Digite [7] para listar as medias da turma"<<endl;
    cout<<"Digite [8] para voltar"<<endl;

    cout<<"Digite sua opcao: ";
    cin >> escolha;

    switch(escolha){
        case 1:
            MenuAdicionarProva(acessada,escolaPassada);
        break;

        case 2:
            MenuAdicionarNota(acessada,escolaPassada);
        break;

        case 3:
            MenuMatricularAluno(acessada, escolaPassada);
        break;

        case 4:
            ListarAlunosTurma(acessada);
        break;

        case 5:
            ListarProvas(acessada);
        break;

        case 6:
            ImprimirBoletim(acessada,escolaPassada);
        break;

        case 7:
            ImprimirBoletimTurma(acessada);
        break;

        case 8:
            ligado = -1;
        break;

        default:
            cout<<"Escolha Invalida!!!"<<endl;
        break;
    }

    }

}


void MenuAdicionarAluno(escola &acessada){
   system("cls");
    std::string codigo;
    string nome;
    aluno NovoAluno;
    cout<<endl<<"#################### ADICIONANDO ALUNO ####################"<<endl;

    cin.get();
    cout<<"Digite o codigo do aluno (apenas numeros): ";
    cin >> codigo;
    NovoAluno.Setcodigo(codigo);
    cin.get();
    cout<<"Digite o nome do aluno: ";
    getline(cin,nome);
    NovoAluno.Setnome(nome);

        for(int i = 0; i < acessada.Alunos.size(); i++){
        if(NovoAluno.Getcodigo()== acessada.Alunos[i].Getcodigo()){
            cout<<"Ja existe um aluno com esse codigo!"<<endl;
            system("PAUSE");
            return;
        }
    }

    acessada.SetAlunos(NovoAluno);

    SalvarAluno(acessada,NovoAluno);
    cout<<"Aluno matriculado com sucesso!"<<endl<<endl;
    system("PAUSE");

    cout<<"###########################################################"<<endl;


}

void MenuAdicionarTurma(escola &acessada){
    system("cls");
    string codigo;
    string nome;
    turma NovaTurma;

    cout<<endl<<"####################### CRIANDO TURMA #####################"<<endl;

    cin.get();
    cout<<"Digite o codigo da turma: ";
    getline(cin,codigo);
    NovaTurma.Setcodigo(codigo);
    cout<<"Digite o nome da turma: ";
    getline(cin,nome);
    NovaTurma.Setnome(nome);

        for(int i = 0; i < acessada.Turmas.size(); i++){
        if(NovaTurma.Getcodigo()== acessada.Turmas[i].Getcodigo()){
            cout<<"Ja existe uma turma com esse codigo!"<<endl;
            system("PAUSE");
            return;
        }
    }

    acessada.Turmas.push_back(NovaTurma);
    SalvarTurmas(acessada,NovaTurma);

    cout<<"Turma cadastrada com sucesso!"<<endl<<endl;
    cout<<"###########################################################"<<endl;
    system("PAUSE");

}

void ListarTurmas(escola &acessada){
    system("cls");

    cout<<endl<<"################### MENU LISTAR TURMAS ####################"<<endl;

    if(acessada.Turmas.size()==0){
        cout<<"Nao existem turmas cadastradas"<<endl;
    }

    for(int i = 0; i < acessada.Turmas.size(); i++){
        cout<<"|Turma: "<<acessada.Turmas[i].Getnome();
        cout<<" | Codigo: "<< acessada.Turmas[i].Getcodigo()<<endl;
    }


    cout<<endl<<"###########################################################"<<endl<<endl;
    system("PAUSE");
}

void ListarAlunos(escola &acessada){
    system("cls");

    cout<<endl<<"################### MENU LISTAR ALUNOS ####################"<<endl;

    if(acessada.Alunos.size()==0){
        cout<<"Nao existem alunos cadastrados"<<endl;
    }

    for(int i = 0; i < acessada.Alunos.size(); i++){
        cout<<"|Aluno: ";
        acessada.Alunos[i].Getnome();
        cout<<" | Codigo: "<< acessada.Alunos[i].Getcodigo()<<endl;
    }


    cout<<endl<<"###########################################################"<<endl<<endl;

    system("PAUSE");
}


void MenuAcessarTurma(escola &acessada){
    system("cls");
    string codigo;
    int save=-1;

     cout<<endl<<"################### MENU ACESSAR TURMA ####################"<<endl;

    cin.get();
    cout<<"Digite o codigo da turma que deseja acessar: ";
    getline(cin,codigo);
        for(int i = 0; i<acessada.Turmas.size(); i++){

            if(codigo == acessada.Turmas[i].Getcodigo()){
                save = i;
                break;
            }
        }
        if(save==-1){
            cout<<"Nao existe turma cadastrada com esse codigo!"<<endl;
                        }
        else{
        MenuTurma(acessada.Turmas[save],acessada);
        }
        system("PAUSE");
    cout<<"###########################################################"<<endl;
}


void MenuAdicionarProva(turma &acessada, escola &passada){
   system("cls");

    cout<<"################## MENU ADICIONAR PROVA ###################"<<endl;

    unsigned int peso;
    string nome;
    prova NovaProva;

    cin.get();
    cout<<"Digite o peso da prova: ";
    cin >> peso;
        //getline(cin,codigo);
    NovaProva.Setpeso(peso);
    cin.get();
    cout<<"Digite o nome da prova: ";
    getline(cin,nome);
    NovaProva.Setnome(nome);

        for(int i = 0; i < acessada.provas.size(); i++){
        if(NovaProva.Getnome()== acessada.provas[i].Getnome()){
            cout<<"Ja existe uma prova com esse nome!"<<endl;
            system("PAUSE");
            return;
        }
    }

    acessada.Setprovas(NovaProva);

    SalvarProva(passada,NovaProva,acessada);
    cout<<"Prova adicionada com sucesso!"<<endl<<endl;

    cout<<"###########################################################"<<endl;



}

void MenuAdicionarNota(turma &acessada, escola &passada){
    system("cls");

    cout<<"################### MENU ADICIONAR NOTA ###################"<<endl;

    double valor;
    int save, save2;
    std::string codigo;
    string nome;
    prova ProvaAplicada;
    nota NotaAplicada;
        if(acessada.provas.size()==0){
            cout<<"E preciso adicionar uma prova antes de dar nota"<<endl;
            return;
        }
        if(acessada.alunos.size()==0){
            cout<<"E preciso matricular alunos antes de dar nota"<<endl;
            return;
        }
    cin.get();
    cout<<"Digite a nota do aluno: ";
    cin >> valor;
    NotaAplicada.Setvalor(valor);
    cin.get();
    cout<<"Digite o codigo do aluno (apenas numeros): ";
    cin>>codigo;
    cin.get();
    cout<<"Digite a prova: ";
    getline(cin,nome);

            for(int i = 0; i<acessada.alunos.size(); i++){

            if(codigo == acessada.alunos[i].Getcodigo()){
                save = i;

            }
        }

        for(int i = 0; i<acessada.provas.size(); i++){

            if(nome == acessada.provas[i].Getnome()){
                save2 = i;

            }
        }


    NotaAplicada.Setaluno(acessada.alunos[save]);
    NotaAplicada.Setprova(acessada.provas[save2]);

    acessada.Setnotas(NotaAplicada);

    SalvarNota(passada,NotaAplicada,acessada);
    cout<<"Nota adicionada com sucesso!"<<endl<<endl;

    cout<<"###########################################################"<<endl;



}

void MenuMatricularAluno(turma &acessada, escola &escolaPassada){


    system("cls");

    cout<<"################## MENU MATRICULAR ALUNO ##################"<<endl;

    std::string codigo;
    int save=-1;
    aluno NovoAluno;

    cin.get();
    cout<<"Digite o codigo do aluno(apenas numeros): ";
    cin >> codigo;
    NovoAluno.Setcodigo(codigo);

        for(int i = 0; i<escolaPassada.Alunos.size(); i++){

            if(codigo == escolaPassada.Alunos[i].Getcodigo()){
                save = i;

            }
        }
        if(save == -1){
            cout<<"Nenhum aluno com esse codigo"<<endl;
            return;
        }

    acessada.alunos.push_back(escolaPassada.Alunos[save]);
    SalvarAlunoTurma(escolaPassada,escolaPassada.Alunos[save],acessada);
    cout<<"Aluno matriculado com sucesso!"<<endl<<endl;

    cout<<"###########################################################"<<endl;

}


void ListarAlunosTurma(turma &acessada){

    system("cls");

    cout<<"############### MENU LISTAR ALUNOS DA TURMA ###############"<<endl;

    if(acessada.alunos.size()==0){
        cout<<"Nao existem alunos matriculados"<<endl;
    }

    for(int i = 0; i < acessada.alunos.size(); i++){
        cout<<"|Aluno: ";
        acessada.alunos[i].Getnome();
        cout<<" | Codigo: "<< acessada.alunos[i].Getcodigo()<<endl;
    }


    cout<<endl<<"###########################################################"<<endl<<endl;

    system("PAUSE");
}

void ListarProvas(turma &acessada){
    system("cls");

    cout<<endl<<"################### MENU LISTAR PROVAS ####################"<<endl;

    if(acessada.provas.size()==0){
        cout<<"Nao existem provas cadastradas"<<endl;
    }

    for(int i = 0; i < acessada.provas.size(); i++){
        cout<<"|Prova: ";
        cout<<acessada.provas[i].Getnome();
        cout<<" | Peso: "<< acessada.provas[i].Getpeso()<<endl;
    }


    cout<<endl<<"###########################################################"<<endl<<endl;
    system("PAUSE");
}

void ImprimirBoletim(turma &acessada, escola &escolaPassada){
   int save = -1;
   bool teste = false;
   std::string codigo;
   aluno Media;
   cout<<"Digite o codigo do aluno que deseja imprimir o boletim (apenas numeros): ";
   cin>>codigo;
    for(int i = 0; i<acessada.alunos.size(); i++){
            if(codigo == acessada.alunos[i].Getcodigo()){
                save = i;
            }
        }

       if(save == -1){
           for(int k =0; k< escolaPassada.Alunos.size(); k++){
              if(codigo == escolaPassada.Alunos[k].Getcodigo()){
                   cout<<"Aluno nao matriculado na turma"<<endl;
                   system("PAUSE");
                   teste = true;

                   return;
                  }
                }
        if(teste == false){
            cout<<"Nenhum aluno com esse codigo"<<endl;
            system("PAUSE");
            return;
            }
        }

    acessada.GetMedia(save);
        for(int j = 0; j<acessada.notas.size();j++){
            if(codigo == acessada.notas[j].Getaluno().Getcodigo()){

            }
        cout<<endl;

        }
        system("PAUSE");
}

void ImprimirBoletimTurma(turma &acessada){
    if(acessada.alunos.size()==0){
        cout<<"Nao existem alunos nessa turma"<<endl;
        return;
    }else{
        acessada.GetMedia();
    }
    system("PAUSE");
}

//Funções de Salvar

void SalvarEscolas(escola &novaescola){
    fstream arquivo;
    string nome;
    const char* nomec;
    string nome2;
    const char* nomec2;

    CriarPasta("Memoria/"+ novaescola.Getnome());
    CriarPasta("Memoria/"+ novaescola.Getnome()+"/Alunos");
    CriarPasta("Memoria/"+ novaescola.Getnome()+"/Turmas");
   /* CriarPasta("Memoria/"+ novaescola.Getnome()+"/Turmas/Alunos Matriculados");
    CriarPasta("Memoria/"+ novaescola.Getnome()+"/Turmas/Provas");
    CriarPasta("Memoria/"+ novaescola.Getnome()+"/Turmas/Notas");*/

    nome = ("Memoria/"+ novaescola.Getnome()+"/Dados da escola.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);

    //arquivo << novaescola.Getnome()<<"\n";
    arquivo << novaescola.Getcodigo()<<"\n";

    arquivo.close();
    nome2 = ("Memoria/Nomes das escolas.txt");
    nomec2 = nome2.c_str();
    arquivo.open(nomec2,ios::out|ios::app);
    arquivo << novaescola.Getnome()<<"\n";
    arquivo.close();
}

void SalvarAluno(escola &novaescola,aluno &novoaluno){
    fstream arquivo;
    string nome;
    const char* nomec;

    nome = ("Memoria/"+ novaescola.Getnome()+"/Alunos/Codigo Alunos.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo<<novoaluno.Getcodigo()<<"\n";
    arquivo.close();

    nome = ("Memoria/"+ novaescola.Getnome()+"/Alunos/Nome Alunos.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo << novoaluno.Getnome()<<"\n";
    arquivo.close();
}

void SalvarTurmas(escola &acessada,turma &novaturma){
    fstream arquivo;
    string nome;
    const char* nomec;
    CriarPasta("Memoria/"+acessada.Getnome()+"/Turmas/"+novaturma.Getnome());
    nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/Codigo Turma.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo<<novaturma.Getcodigo()<<"\n";
    arquivo.close();

    nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/Nome Turma.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo << novaturma.Getnome()<<"\n";
    arquivo.close();


}

void SalvarAlunoTurma(escola &acessada,aluno &matriculado,turma &novaturma){
    fstream arquivo;
    string nome;
    const char* nomec;

    //CriarPasta("Memoria/"+acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"Alunos Matriculados");
    //nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"Alunos Matriculados/Codigo Aluno Matriculado.txt");
    nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"/Codigo Aluno Matriculado.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo<<matriculado.Getcodigo()<<"\n";
    arquivo.close();
/*
    nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"Codigo Turma Matriculada.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo << novaturma.Getcodigo()<<"\n";
    arquivo.close();
*/
}

void SalvarProva(escola &acessada,prova &prova,turma &novaturma){
    fstream arquivo;
    string nome;
    const char* nomec;

    CriarPasta("Memoria/"+acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"/Provas");
    //nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"Alunos Matriculados/Codigo Aluno Matriculado.txt");

    nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"/Provas/Nome Provas.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo<<prova.Getnome()<<"\n";
    arquivo.close();


    nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"/Provas/Peso Provas.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo<<prova.Getpeso()<<"\n";
    arquivo.close();
}

void SalvarNota(escola &acessada,nota &nota,turma &novaturma){
    fstream arquivo;
    string nome;
    const char* nomec;

     CriarPasta("Memoria/"+acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"/Notas/"+nota.Getprova().Getnome());
    //nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"Alunos Matriculados/Codigo Aluno Matriculado.txt");

    nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"/Provas/Nome Nota Aluno.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo<<nota.Getaluno().Getnome()<<"\n";
    arquivo.close();


    nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"/Provas/Peso Prova Nota.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo<<nota.Getprova().Getpeso()<<"\n";
    arquivo.close();

    nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"/Provas/Valor Nota.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo<<nota.Getvalor()<<"\n";
    arquivo.close();

    nome = ("Memoria/"+ acessada.Getnome()+"/Turmas/"+novaturma.Getnome()+"/Provas/Nome Prova Nota.txt");
    nomec = nome.c_str();
    arquivo.open(nomec,ios::out|ios::app);
    arquivo<<nota.Getprova().Getnome()<<"\n";
    arquivo.close();
}

//Funções Carregar
void CarregarArquivoEspecifico(char *dir_name,string arquivo){
    DIR *dir;
    struct dirent *entry;
    struct stat info;

    string textopuro = arquivo;
    string textotrabalhado = string(dir_name) + "/" + textopuro;
    const char *textodeacesso = textotrabalhado.c_str();


    ifstream arquivoE;
    string linha;

    dir = opendir(dir_name);
    if(!dir){
        //cout<<"erro"<<endl;
        return;
    }


    while( (entry=readdir(dir)) != NULL){



        if(entry->d_name[0]!= '.'){
        string path = string(dir_name)+"/"+string(entry->d_name);
        //cout<<"entry = "<< path<<endl;
        stat(path.c_str(), &info);


         if(path == textodeacesso){

        arquivoE.open(textodeacesso);

            if(arquivoE.is_open()){
                while(getline(arquivoE,linha)){
                   save.push_back(linha);
                   //cout<<"Arquivo Carregado"<<endl;
                }
                arquivoE.close();
            return;
        }else{
        //cout<<"Nao foi possivel abrir o arquivo"<<endl;
        }
        }
        if(S_ISDIR(info.st_mode)){
        CarregarArquivoEspecifico((char *)path.c_str(),arquivo);

        }

        }

    }

    closedir(dir);
}

void CarregarArquivoEspecifico(char *dir_name,string arquivo,vector <string> salvar){
    DIR *dir;
    struct dirent *entry;
    struct stat info;

    string textopuro = arquivo;
    string textotrabalhado = string(dir_name) + "/" + textopuro;
    const char *textodeacesso = textotrabalhado.c_str();


    ifstream arquivoE;
    string linha;

    dir = opendir(dir_name);
    if(!dir){
        cout<<"erro"<<endl;
        return;
    }


    while( (entry=readdir(dir)) != NULL){



        if(entry->d_name[0]!= '.'){
        string path = string(dir_name)+"/"+string(entry->d_name);
       // cout<<"entry = "<< path<<endl;
        stat(path.c_str(), &info);


         if(path == textodeacesso){

        arquivoE.open(textodeacesso);

            if(arquivoE.is_open()){
                while(getline(arquivoE,linha)){
                   salvar.push_back(linha);
                   cout<<"Arquivo Carregado"<<endl;
                }
                arquivoE.close();
            return;
        }else{
        cout<<"Nao foi possivel abrir o arquivo"<<endl;
        }
        }
        if(S_ISDIR(info.st_mode)){
        CarregarArquivoEspecifico((char *)path.c_str(),arquivo,salvar);

        }

        }

    }

    closedir(dir);

}

void CarregarArquivos(){
    ifstream arquivo;
    string linha;
    arquivo.open("Memoria/Nomes das escolas.txt");
    if(arquivo.is_open()){

        while(getline(arquivo,linha)){
          save.push_back(linha);
    }
    }else{
        cout<<"Nao foi possivel carregar os arquivos"<<endl;
        system("PAUSE");
    }

    for(int i=0; i<save.size(); i++){
        CarregarArquivoEspecifico("Memoria", save[i]);
        }

    for(int j=0; j<save.size(); j++){ //Coloca os nomes das escolas
        escola novaescola;
        novaescola.Setnome(save[j]);
        TodasAsEscolas.push_back(novaescola);
    }


    //APAGAR OS ELEMENTOS DO VETOR
    save.clear();

    for(int k=0; k<TodasAsEscolas.size();k++){
            CarregarArquivoEspecifico("Memoria", "Dados da escola.txt");
        }

    for(int l=0; l<TodasAsEscolas.size(); l++){ //Coloca os codigos das escolas
        TodasAsEscolas[l].Setcodigo(save[l]);
        }

    save.clear();


    //Preparando para carregar os alunos
    for(int o = 0; o<TodasAsEscolas.size();o++){
        string textopuro = "Memoria/"+TodasAsEscolas[o].Getnome()+"/Alunos";
        char *textodeacesso = new char[textopuro.size()+1];
        copy(textopuro.begin(), textopuro.end(), textodeacesso);
        textodeacesso[textopuro.size()] = '\0';
        CarregarArquivoEspecifico(textodeacesso, "Nome Alunos.txt");

    for(int n=0; n<save.size(); n++){ //Coloca os nomes dos alunos de cada escola

        aluno novoaluno;
        novoaluno.Setnome(save[n]);
        TodasAsEscolas[o].Alunos.push_back(novoaluno);
        }
    save.clear();

        for(int m=0; m<TodasAsEscolas.size();m++){
            CarregarArquivoEspecifico(textodeacesso, "Codigo Alunos.txt");
        }

    for(int z=0; z<TodasAsEscolas[o].Alunos.size(); z++){ //Coloca os cpdigos dos alunos na escola
           TodasAsEscolas[o].Alunos[z].Setcodigo(save[z]);
        }
       save.clear();

    }

    //Preparando para carregar as turmas
    for(int o = 0; o<TodasAsEscolas.size();o++){

        string textopuro = "Memoria/"+TodasAsEscolas[o].Getnome()+"/Turmas";
        char *textodeacesso = new char[textopuro.size()+1];
        copy(textopuro.begin(), textopuro.end(), textodeacesso);
        textodeacesso[textopuro.size()] = '\0';
        CarregarArquivoEspecifico(textodeacesso, "Nome Turma.txt");

        //  CarregarArquivoEspecifico("Memoria"+TodasAsEscolas[o].Getnome()+ "/Turmas","Nome Turma.txt");

    for(int n=0; n<save.size(); n++){ //Coloca os nomes dos alunos de cada escola

       turma novaturma;
        novaturma.Setnome(save[n]);
        TodasAsEscolas[o].Turmas.push_back(novaturma);
        }
    save.clear();

        for(int m=0; m<TodasAsEscolas.size();m++){
            CarregarArquivoEspecifico("Memoria", "Codigo Turma.txt");
        }

    for(int z=0; z<TodasAsEscolas[o].Turmas.size(); z++){ //Coloca os cpdigos dos alunos na escola
           TodasAsEscolas[o].Turmas[z].Setcodigo(save[z]);
        }
       save.clear();

    }

    //Preparando matricular os alunos
    for(int o = 0; o<TodasAsEscolas.size();o++){
        for(int p = 0; p< TodasAsEscolas[o].Turmas.size();p++){
            for(int q = 0;q<TodasAsEscolas[o].Alunos.size();q++){

            string textopuro = "Memoria/"+TodasAsEscolas[o].Getnome()+"/Turmas/"+TodasAsEscolas[o].Turmas[p].Getnome();
            char *textodeacesso = new char[textopuro.size()+1];
            copy(textopuro.begin(), textopuro.end(), textodeacesso);
            textodeacesso[textopuro.size()] = '\0';

            CarregarArquivoEspecifico(textodeacesso, "Codigo Aluno Matriculado.txt");

            for(int n=0; n<save.size(); n++){ //Coloca os nomes dos alunos de cada escola
                if(TodasAsEscolas[o].Alunos[q].Getcodigo()==save[n]){
                    TodasAsEscolas[o].Turmas[p].alunos.push_back(TodasAsEscolas[o].Alunos[q]);
                    }
                }
            save.clear();

            for(int m=0; m<TodasAsEscolas.size();m++){
                CarregarArquivoEspecifico("Memoria", "Codigo Turma.txt");
                }

            save.clear();
            }
        }
    }

    //Carregar as provas

    for(int o = 0; o<TodasAsEscolas.size();o++){
        for(int p = 0; p< TodasAsEscolas[o].Turmas.size();p++){
          vector<prova> carregadas;

            string textopuro = "Memoria/"+TodasAsEscolas[o].Getnome()+"/Turmas/"+TodasAsEscolas[o].Turmas[p].Getnome()+"/Provas";
            char *textodeacesso = new char[textopuro.size()+1];
            copy(textopuro.begin(), textopuro.end(), textodeacesso);
            textodeacesso[textopuro.size()] = '\0';


            CarregarArquivoEspecifico(textodeacesso, "Nome Provas.txt");
            if(save.size()>0){

            for(int l = 0; l<save.size();l++){
                prova nova;
                nova.Setnome(save[l]);
                carregadas.push_back(nova);
            }
            save.clear();

            CarregarArquivoEspecifico(textodeacesso, "Peso Provas.txt");

            for(int l = 0; l<save.size();l++){
                 int x = stold(save[l]);
                carregadas[l].Setpeso(x);
            }

            save.clear();
                TodasAsEscolas[o].Turmas[p].provas = carregadas;
            }
           save.clear();
        }
    }
    //carregar as notas
   for(int o = 0; o<TodasAsEscolas.size();o++){
        for(int p = 0; p< TodasAsEscolas[o].Turmas.size();p++){


            vector<nota> carregadas;
            vector <string> nomeprovas;
            vector <int> pesoprovas;

            string textopuro = "Memoria/"+TodasAsEscolas[o].Getnome()+"/Turmas/"+TodasAsEscolas[o].Turmas[p].Getnome()+"/Provas";
            char *textodeacesso = new char[textopuro.size()+1];
            copy(textopuro.begin(), textopuro.end(), textodeacesso);
            textodeacesso[textopuro.size()] = '\0';

            CarregarArquivoEspecifico(textodeacesso, "Nome Nota Aluno.txt");

           if(save.size()>0){
                    for(int l = 0; l<save.size() ;l++){
                        for(int i = 0; i < TodasAsEscolas[o].Turmas[p].alunos.size();i++){
                            nota nova;
                            nova.Setaluno(TodasAsEscolas[o].Turmas[p].alunos[i]);
                            carregadas.push_back(nova);
                        }
                    }


            save.clear();

            CarregarArquivoEspecifico(textodeacesso, "Nome Prova Nota.txt");

            for(int l = 0; l<save.size() ;l++){

                    nomeprovas.push_back(save[l]);

            }

            save.clear();

        CarregarArquivoEspecifico(textodeacesso, "Peso Prova Nota.txt");
        for(int l = 0; l<save.size() ;l++){

                  int y = stold(save[l]);
                   pesoprovas.push_back(y);

            }


                for(int i = 0; i < save.size();i++){
                    prova nova;
                   nova.Setpeso(pesoprovas[i]);
                   nova.Setnome(nomeprovas[i]);
                   carregadas[i].Setprova(nova);
               }


            save.clear();

            CarregarArquivoEspecifico(textodeacesso, "Valor Nota.txt");
               for(int l = 0; l<save.size() ;l++){
                for(int i = 0; i < carregadas.size();i++){
                         int x = stold(save[i]);
                    carregadas[i].Setvalor(x);
               }
            }

            save.clear();
                TodasAsEscolas[o].Turmas[p].notas = carregadas;
            }
            save.clear();
        }
    }





    //system("cls");
    cout<<"Arquivos Carregados com Sucesso!"<<endl;
    system("PAUSE");
}






