#ifndef IMPIANTO_DESERTICO_H
#define IMPIANTO_DESERTICO_H

#include "Impianto.h"

using namespace std;

class ImpiantoDesertico : public Impianto {
public:
    ImpiantoDesertico(int id, const string& nome);
    
    void aggiorna(const Orario& orarioAttuale, const Orario& orarioPrecedente) override;
    string getTipo() const override;
};

#endif