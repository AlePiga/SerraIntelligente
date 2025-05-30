#include "../include/ImpiantoCarnivoro.h"
#include <iostream>

using namespace std;

ImpiantoCarnivoro::ImpiantoCarnivoro(int id, const std::string& nome)
    : Impianto(id, nome) {}

void ImpiantoCarnivoro::aggiorna(const Orario& orarioAttuale, const Orario& orarioPrecedente) {
    Orario orarioCorrente(orarioPrecedente);

    while (orarioCorrente < orarioAttuale) {

        if ((orarioCorrente.getOre() * 60 + orarioCorrente.getMinuti())%(int)(ATTIVAZIONE*60) == 0) {
            if (!attivo) {
                attivo = true;
                ultimaAttivazione = orarioCorrente;
                cout << "[" << orarioCorrente.toString() << "] Impianto " << nome << " acceso" << endl;
            }
        }
        else if (attivo && (orarioCorrente.differenzaMinuti(ultimaAttivazione) >= DURATA_IRRIGAZIONE)) {
            attivo = false;
            consumoAcqua += (DURATA_IRRIGAZIONE / 60.0) * 10.0;
            cout << "[" << orarioCorrente.toString() << "] Impianto " << nome << " spento" << endl;
        }

        int nuoviMinuti = orarioCorrente.getMinuti() + 1;
        int nuoveOre = orarioCorrente.getOre() + (nuoviMinuti / 60);
        orarioCorrente.setOrario(nuoveOre % 24, nuoviMinuti % 60);
    }
}

string ImpiantoCarnivoro::getTipo() const {
    return "Carnivoro";
}
