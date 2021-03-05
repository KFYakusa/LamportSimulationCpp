#include "Processo.h"
#include <cstdlib>
#include <ctime>
using namespace std;


Processo::Processo(){
    numeroPosicoes=0;
    taxaAumento=0;
    marcador=0;
}


Processo::~Processo(){
    vetorTempos.clear();
}
Processo::Processo(int posNum, int taxa){
    marcador=0;

    if(posNum!= NULL && posNum > 0)
        numeroPosicoes = posNum;
    else
        numeroPosicoes = rand()%20;
    if(taxa != NULL && taxa>0)
        taxaAumento = taxa;
    else
        taxaAumento = rand()%20 + 1;

    for (size_t i = 0; i < numeroPosicoes; i++)
    {
        vetorTempos.push_back( i*taxaAumento);
    }   
    
}

void Processo::setTaxa(int taxa){

    if(taxa != NULL && taxa>0)
        taxaAumento = taxa;
    else
        taxaAumento = rand() % 20;
    return;
}


void Processo::atualizarVetor(int ref){
    if(getValue(marcador) < ref){
        for(int i= 0; i<vetorTempos.size() - marcador ;i++){
            if(i==0){
                vetorTempos.at(i+marcador) = ref + 1;
            }else{
                vetorTempos.at(i+marcador) = vetorTempos.at(i+marcador-1) + taxaAumento;
            }   
        }
    }
    return;
    
}

int Processo::getValue(int index){
    return vetorTempos.at(index);
}



void Processo::attMarker(int index){
    marcador = index;
}




void Processo::setNumeroPosicoes(int posNum){
    if(posNum!= NULL && posNum > 0)
        numeroPosicoes = posNum;
    else
        numeroPosicoes = rand()%20;
}

int Processo::getNumeroPosicoes(){
    return numeroPosicoes;
}

int Processo::getTaxa(){
    return taxaAumento;
}

void Processo::showVetor(){
    for(auto i = vetorTempos.begin(); i!= vetorTempos.cend();++i)
        cout<< *i << " | ";
    cout<<endl;
}

int Processo::getMarker(){
    return marcador;
}

