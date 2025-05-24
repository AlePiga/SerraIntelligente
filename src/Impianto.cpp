#include "../include/Impianto.h"
#include <sstream>
#include <iomanip>

using namespace std;

// Costruttore
Impianto::Impianto(int id, const string& nome)
    : id(id), nome(nome), attivo(false), consumoAcqua(0.0), timerImpostato(false) {}

// Getter
int Impianto::getId() const { return id; }
string Impianto::getNome() const { return nome; }
bool Impianto::isAttivo() const { return attivo; }
double Impianto::getConsumoAcqua() const { return consumoAcqua; }
Orario Impianto::getUltimaAttivazione() const { return ultimaAttivazione; }

// Setter
void Impianto::setId(int newId) { id = newId; }
void Impianto::setNome(const string& newNome) { nome = newNome; }

// Metodo per accendere l'impianto
void Impianto::accendi(const Orario& orarioAttuale) {
    if (!attivo) {
        attivo = true;
        ultimaAttivazione = orarioAttuale;
    }
}

// Metodo per spegnere l'impianto
void Impianto::spegni(const Orario& orarioAttuale) {
    if (attivo) {
        attivo = false;
        consumoAcqua += (orarioAttuale.differenzaMinuti(ultimaAttivazione) / 60.0) * 10.0;
    }
}

// Metodo per impostare un timer
void Impianto::impostaTimer(const Orario& inizio, const Orario& fine) {
    orarioAccensione = inizio;
    orarioSpegnimento = fine;
    timerImpostato = true;
}

void Impianto::impostaTimer(const Orario& inizio) {
    orarioAccensione = inizio;
    timerImpostato = true;
}

void Impianto::rimuoviTimer() {
    timerImpostato = false;
}

bool Impianto::hasTimer() const {
    return timerImpostato;
}

string Impianto::getDettagli() const {
    stringstream ss;
    ss << "ID: " << id << ", Nome: " << nome << ", Tipo: " << getTipo() 
       << ", Stato: " << (attivo ? "Attivo" : "Spento")
       << ", Consumo Acqua: " << fixed << setprecision(2) << consumoAcqua << "L";
    
    if (timerImpostato) {
        ss << ", Timer: " << orarioAccensione.toString();
    }
    
    return ss.str();
}