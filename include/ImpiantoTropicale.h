#ifndef IMPIANTO_TROPICALE_H
#define IMPIANTO_TROPICALE_H

#include "Impianto.h"

using namespace std;

class ImpiantoTropicale : public Impianto {
private:
    static const int DURATA_IRRIGAZIONE = 30; // 1.5h di irrigazione
    const double ATTIVAZIONE = 2.5;

public:
    ImpiantoTropicale(int id, const string& nome);

    void aggiorna(const Orario& orarioAttuale, const Orario& orarioPrecedente) override;
    string getTipo() const override;
};

#endif