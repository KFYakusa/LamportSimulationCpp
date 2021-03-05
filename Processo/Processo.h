#ifndef PROCESSO_H_INCLUDED
#define PROCESSO_H_INCLUDED

#include <vector>
#include <iostream>

class Processo 
{

public:
    Processo();
    Processo(int posNum,int taxa);
    ~Processo();
    
    void setTaxa(int taxa);
    void setNumeroPosicoes(int posNum);


    void atualizarVetor(int ref);
    
    void attMarker(int index);

    int getMarker();
    int getNumeroPosicoes();
    int getValue(int index);
    int getTaxa();
    void showVetor();


private:
    int taxaAumento;
    int numeroPosicoes;
    int marcador;
    
    std::vector<int> vetorTempos;

};

#endif