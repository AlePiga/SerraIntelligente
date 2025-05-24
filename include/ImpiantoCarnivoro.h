#ifndef IMPIANTO_CARNIVORO_H
#define IMPIANTO_CARNIVORO_H

#include "Impianto.h"

using namespace  std;

class ImpiantoCarnivoro : public Impianto {
private:
    static const int DURATA_IRRIGAZIONE = 30; // 1.5h di irrigazione
    const double ATTIVAZIONE = 1.5;
    
public:
    ImpiantoCarnivoro(int id, const string& nome);
    
    void aggiorna(const Orario& orarioAttuale, const Orario& orarioPrecedente) override;
    string getTipo() const override;
};

#endif