#ifndef IMPIANTO_MEDITERRANEO_H
#define IMPIANTO_MEDITERRANEO_H

#include "Impianto.h"
#include <random>

using namespace std;

class ImpiantoMediterraneo : public Impianto {
private:
    double temperatura;
    mt19937 gen;
    uniform_real_distribution<> distrDiminuzione;
    uniform_real_distribution<> distrAumento;
    
public:
    ImpiantoMediterraneo(int id, const string& nome);
    
    void aggiorna(const Orario& orarioAttuale, const Orario& orarioPrecedente) override;
    string getTipo() const override;
    string getDettagli() const override;
    
    double getTemperatura() const;
};

#endif