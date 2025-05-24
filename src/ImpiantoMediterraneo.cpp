#include "../include/ImpiantoMediterraneo.h"
#include <iostream>
#include <sstream>
#include <random>
#include <chrono>

using namespace std;

ImpiantoMediterraneo::ImpiantoMediterraneo(int id, const string& nome)
    : Impianto(id, nome), temperatura(28.0),
      gen(random_device()()),
      distrDiminuzione(0.01, 0.05),
      distrAumento(0.75, 1.0) {}

void ImpiantoMediterraneo::aggiorna(const Orario& orarioAttuale, const Orario& orarioPrecedente) {
    int minutiTrascorsi = orarioAttuale.differenzaMinuti(orarioPrecedente);

    Orario oraCorrente(orarioPrecedente);
    
    for (int i = 0; i < minutiTrascorsi; i++) {

        int nuoviMinuti = oraCorrente.getMinuti() + 1;
        int nuoveOre = oraCorrente.getOre() + (nuoviMinuti / 60);
        oraCorrente.setOrario(nuoveOre % 24, nuoviMinuti % 60);

        if (!attivo) {
            temperatura -= distrDiminuzione(gen);
            
            if (temperatura < 25.0) {
                attivo = true;
                ultimaAttivazione = oraCorrente;
                cout << "[" << oraCorrente.toString() << "] Impianto " << nome << " acceso" << endl;
            }
        }
        else {
            if (oraCorrente.getMinuti() == 0) {
                temperatura += distrAumento(gen);
                
                if (temperatura >= 28.0) {
                    spegni(oraCorrente);
                    cout << "[" << oraCorrente.toString() << "] Impianto " << nome << " spento" << endl;
                }
            }
        }
    }
}

string ImpiantoMediterraneo::getTipo() const {
    return "Mediterraneo";
}

double ImpiantoMediterraneo::getTemperatura() const {
    return temperatura;
}

string ImpiantoMediterraneo::getDettagli() const {
    stringstream ss;
    ss << Impianto::getDettagli() << ", Temperatura: " << temperatura << "°C";
    return ss.str();
}