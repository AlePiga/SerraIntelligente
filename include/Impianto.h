#ifndef IMPIANTO_H
#define IMPIANTO_H

#include <string>
#include <memory>
#include "Orario.h"

using namespace std;

class Impianto {
protected:
    int id; // Identificativo dell'impianto
    string nome; // Nome dell'impianto
    bool attivo;
    bool timerImpostato;
    double consumoAcqua;

    Orario ultimaAttivazione;
    Orario orarioAccensione;
    Orario orarioSpegnimento;

public:
    Impianto(int id, const string& nome); // Costruttore
    virtual ~Impianto() = default; // Distruttore

    // Getter
    int getId() const;
    string getNome() const;
    bool isAttivo() const;
    double getConsumoAcqua() const;
    Orario getUltimaAttivazione() const;

    // Setter
    void setId(int id);
    void setNome(const string& nome);

    // Controllo di accensione e spegnimento
    virtual void accendi(const Orario& orarioAttuale);
    virtual void spegni(const Orario& orarioAttuale);

    // Timer
    void impostaTimer(const Orario& inizio, const Orario& fine);
    void impostaTimer(const Orario& inizio);
    void rimuoviTimer();
    bool hasTimer() const;

    // Aggiorna lo stato dell'impianto
    virtual void aggiorna(const Orario& orarioAttuale, const Orario& orarioPrecedente) = 0;

    // Ritorna il tipo dell'impianto
    virtual string getTipo() const = 0;

    // Ritorna i dettagli dell'impianto
    virtual string getDettagli() const;
};

#endif