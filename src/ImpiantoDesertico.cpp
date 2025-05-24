#include "../include/ImpiantoDesertico.h"
#include <iostream>

using namespace std;

ImpiantoDesertico::ImpiantoDesertico(int id, const string& nome)
    : Impianto(id, nome) {}

void ImpiantoDesertico::aggiorna(const Orario& orarioAttuale, const Orario& orarioPrecedente) {
    if (timerImpostato) {
        if (orarioPrecedente <= orarioAccensione && orarioAttuale > orarioAccensione) {
            accendi(orarioAccensione);
            cout << "[" << orarioAccensione.toString() << "] Impianto " << nome << " acceso" << endl;
        }
        
        if (attivo && orarioPrecedente <= orarioSpegnimento && orarioAttuale > orarioSpegnimento) {
            spegni(orarioSpegnimento);
            cout << "[" << orarioSpegnimento.toString() << "] Impianto " << nome << " spento" << endl;
        }
    }
}

string ImpiantoDesertico::getTipo() const {
    return "Desertico";
}