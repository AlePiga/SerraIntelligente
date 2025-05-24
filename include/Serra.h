#ifndef SERRA_H
#define SERRA_H

#include <vector>
#include <memory>
#include <string>
#include "Impianto.h"
#include "Orario.h"

using namespace std;

class Serra {
private:
    vector<unique_ptr<Impianto>> impianti;
    Orario orarioAttuale;
    int nextId;

public:
    Serra();

    void aggiungiImpianto(unique_ptr<Impianto> impianto);
    void rimuoviImpianto(int id);

    Impianto* trovaImpianto(const string& nome);
    Impianto* trovaImpianto(int id);

    void accendiImpianto(const string& nome);
    void spegniImpianto(const string& nome);

    void impostaTimer(const string& nome, const Orario& inizio, const Orario& fine);
    void impostaTimer(const string& nome, const Orario& inizio);
    void rimuoviTimer(const string& nome);

    void impostaOrario(const Orario& orario);
    Orario getOrarioAttuale() const;

    void resetTime();
    void resetTimers();
    void resetAll();

    void mostraStatoSerra() const;
    void mostraStatoImpianto(const string& nome) const;

    double getConsumoTotale() const;
};

#endif // SERRA_H
