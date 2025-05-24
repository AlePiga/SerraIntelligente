#include "../include/Orario.h"
#include <sstream>
#include <iomanip>

using namespace std;

// Costruttore di default
Orario::Orario() : ore(0), minuti(0) {}

// Costruttore con due parametri
Orario::Orario(int h, int m) {
    setOrario(h, m);
}

// Costruttore per impostare l'orario data una stringa
Orario::Orario(const string& time) {
    setOrario(time);
}

// Getter
int Orario::getOre() const { return ore; }
int Orario::getMinuti() const { return minuti; }

// Setter
void Orario::setOre(int h) {
    if (h >= 0 && h < 24) {
        ore = h;
    }
}

void Orario::setMinuti(int m) {
    if (m >= 0 && m < 60) {
        minuti = m;
    }
}

// Metodo per impostare un orario data una stringa
void Orario::setOrario(const string& time) {
    int h = 0, m = 0;
    sscanf(time.c_str(), "%d:%d", &h, &m);
    setOrario(h, m);
}
void Orario::setOrario(int h, int m) {
    setOre(h);
    setMinuti(m);
}

// Metodo toString
string Orario::toString() const {
    stringstream ss;
    ss << setfill('0') << setw(2) << ore << ":" << setw(2) << minuti;
    return ss.str();
}

// Metodo per ottenere la differenza tra due orari
int Orario::differenzaMinuti(const Orario& altro) const {
    int minutiQuesto = ore * 60 + minuti;
    int minutiAltro = altro.ore * 60 + altro.minuti;
    return minutiQuesto - minutiAltro;
}

// Override degli operator per operazioni con gli orari
bool Orario::operator<(const Orario& altro) const {
    if (ore < altro.ore) return true;
    if (ore > altro.ore) return false;
    return minuti < altro.minuti;
}

bool Orario::operator<=(const Orario& altro) const { return *this < altro || *this == altro; }
bool Orario::operator>(const Orario& altro) const { return !(*this <= altro); }
bool Orario::operator>=(const Orario& altro) const { return !(*this < altro); }
bool Orario::operator==(const Orario& altro) const { return ore == altro.ore && minuti == altro.minuti; }
bool Orario::operator!=(const Orario& altro) const { return !(*this == altro); }