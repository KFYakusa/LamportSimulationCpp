#include <iostream>
#include <iomanip>
#include <stdlib.h>

// choosing which lib import in case of running linux

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "./Processo/Processo.h"
// n vetores para criação de n processos
// cada processo deve ter 20 posições



void Clear(){ // utilizar a função certa pra limpar dependendo do SO
    #if defined _WIN32
        system("cls");

    #elif defined (__LINUX__) || defined (__gnu_linux__) || defined(__linux)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

boolean sendMessage(std::vector<Processo*>& vetor,int origin, int destiny);

int main(){
    srand((unsigned int)time(NULL));
    int qtdProcessos;
    int qtdPosicoes;
    int menu;
//gather das main info
    std::vector<Processo*> vetorProcessos;
    std::cout<< "qtd processos: "<<std::endl;
    std::cin>>qtdProcessos;
    std::cout<< "numero de tempos nos processos: "<<std::endl;
    std::cin>>qtdPosicoes;

//  inicialização dos processos com os parâmetros dados
    for(int i=0;i<qtdProcessos;i++)
        vetorProcessos.push_back(new Processo(qtdPosicoes,0));


//  mostrando menu
    do{
        std::cout<<"-------------------------"<<std::endl;

        std::cout<<"MENU"<<std::endl
                <<"0 - EXIT"<<std::endl
                <<"1 - SHOW PROCESSES"<<std::endl
                <<"2 - SEND MESSAGE FROM X TO Y"<<std::endl;

        std::cin>>menu;

        std::cout<<"-------------------------"<<std::endl;
        while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout<<" apenas números"<<std::endl;
            std::cin>>menu;
        }

        switch(menu){
            
            case 0: 
                Clear();
                std::cout<< "exiting program..."<<std::endl;
                for(int j = 0;j<4;j++){
                    srand((unsigned int)time(NULL));
                    Sleep( rand()%1000 + 100);
                    std::cout<<"===";
                }
                break;
            case 1: 
                for(auto i : vetorProcessos)
                    i->showVetor();
                std::cout<<"------------------"<<std::endl;
                break;
            case 2:{
                srand((unsigned int)time(NULL));
                int sender = rand() % qtdProcessos;
                srand((unsigned int)time(NULL));
                int receiver = rand() % qtdProcessos;
                
                while(receiver == sender){
                    srand((unsigned int)time(NULL));
                    receiver = rand() % qtdProcessos;
                }
                std::cout<<" sending message from "<<sender <<" to "<<receiver<<std::endl;
                sendMessage(vetorProcessos,sender,receiver);
                break;
            }
            default:
                std::cout<<" nao existe nenhumm easter egg aqui!"<<std::endl;
                break;
        }
    }while(menu!=0);


// limpeza dos vetores antes de encerrar
    for(auto i:vetorProcessos){
        i->~Processo();
    }

    vetorProcessos.clear();

    return EXIT_SUCCESS;
}


boolean sendMessage(std::vector<Processo*>& vetor,int origin, int destiny){
    
    if ( vetor.at(origin)->getMarker() == vetor.size()  ||  vetor.at(destiny)->getMarker()== vetor.size() ){
        return false;
    }
    int originMarker = vetor.at(origin)->getMarker();
    int destinyMarker = vetor.at(destiny)->getMarker();

    srand((unsigned int)time(NULL));
    int originIndex = (rand()% ( (vetor.size() - originMarker) + 1) ) + originMarker;
    srand((unsigned int)time(NULL));
    int destinyIndex = (rand()% ( (vetor.size() - destinyMarker) + 1) ) + destinyMarker;
    
    vetor.at(origin)->attMarker(originIndex);
    vetor.at(destiny)->attMarker(destinyIndex);

    vetor.at(destiny)->atualizarVetor(vetor.at(origin)->getValue(originIndex));


    vetor.at(origin)->showVetor();
    vetor.at(destiny)->showVetor();

return true;
}

