#ifndef IMPIANTO_ALPINO_H
#define IMPIANTO_ALPINO_H

#include "Impianto.h"

using namespace std;

class ImpiantoAlpino : public Impianto {
private:
    static const int DURATA_IRRIGAZIONE = 20; // 1h di irrigazione
    const double ATTIVAZIONE = 1;
    
public:
    // Costruttore
    ImpiantoAlpino(int id, const string& nome);
    
    void aggiorna(const Orario& orarioAttuale, const Orario& orarioPrecedente) override;
    string getTipo() const override;
};

#endif