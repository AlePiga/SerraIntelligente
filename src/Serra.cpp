#include "../include/Serra.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

// Costruttore di default
Serra::Serra() : nextId(1) {
    orarioAttuale = Orario(0, 0);
}

// Metodo per aggiungere un impianto
void Serra::aggiungiImpianto(unique_ptr<Impianto> impianto) {
    impianto->setId(nextId++);
    impianti.push_back(move(impianto));
}

// Metodo per rimuovere un impianto
void Serra::rimuoviImpianto(int id) {
    for(int i = 0; i < impianti.size(); ) {
        if(impianti[i]->getId() == id) {
            impianti.erase(impianti.begin() + i);
        }
        else {
            i++;
        }
    }
}

// Metodo per trovare un impianto dato il nome
Impianto* Serra::trovaImpianto(const string& nome) {
    for(int i = 0; i < impianti.size(); i++) {
        if(impianti[i]->getNome() == nome) {
            return impianti[i].get();
        }
    }
    return nullptr;
}

// Metodo per trovare un impianto dato l'ID
Impianto* Serra::trovaImpianto(int id) {
    for(int i = 0; i < impianti.size(); i++) {
        if(impianti[i]->getId() == id) {
            return impianti[i].get();
        }
    }
    return nullptr;
}

// Metodo per accendere un impianto
void Serra::accendiImpianto(const string& nome) {
    Impianto* impianto = trovaImpianto(nome);
    if (impianto) {
        impianto->accendi(orarioAttuale);
        cout << "[" << orarioAttuale.toString() << "] " << nome << " acceso" << endl;
    }
}

// Metodo per spegnere un impianto
void Serra::spegniImpianto(const string& nome) {
    Impianto* impianto = trovaImpianto(nome);
    if (impianto) {
        impianto->spegni(orarioAttuale);
        cout << "[" << orarioAttuale.toString() << "]" << nome << "spento" << endl;
    }
}

// Metodo per impostare un timer dato nome e orari d'inzio e fine
void Serra::impostaTimer(const string& nome, const Orario& inizio, const Orario& fine) {
    Impianto* impianto = trovaImpianto(nome);
    if (impianto) {
        impianto->impostaTimer(inizio, fine);
        cout << "[" << orarioAttuale.toString() << "] Timer impostato per: " << nome << endl;
    }
}

// Metodo per impostare un timer dato solo l'orario d'inizio
void Serra::impostaTimer(const string& nome, const Orario& inizio) {
    Impianto* impianto = trovaImpianto(nome);
    if (impianto) {
        impianto->impostaTimer(inizio);
        cout << "[" << orarioAttuale.toString() << "] Timer impostato per: " << nome << endl;
    }
}

// Metodo per rimuovere un timer
void Serra::rimuoviTimer(const string& nome) {
    Impianto* impianto = trovaImpianto(nome);
    if (impianto) {
        impianto->rimuoviTimer();
        cout << "[" << orarioAttuale.toString() << "] Timer rimosso per \"" << nome << "\"" << endl;
    }
}

// Metodo per impostare l'orario
void Serra::impostaOrario(const Orario& orario) {
    Orario vecchioOrario = orarioAttuale;
    
    for (auto& impianto : impianti) {
        impianto->aggiorna(orario, vecchioOrario);
    }
    
    orarioAttuale = orario;
    cout << "[" << orarioAttuale.toString() << "] Sono le " << orarioAttuale.toString() << endl;
}

// Getter per l'orario attuale
Orario Serra::getOrarioAttuale() const { return orarioAttuale; }

// Metodo per resettare l'orario a mezzanotte
void Serra::resetTime() {
    orarioAttuale = Orario(0, 0);
    
    for (auto& impianto : impianti) {
        if (impianto->isAttivo()) {
            impianto->spegni(orarioAttuale);
        }
        impianto->rimuoviTimer();
    }
    
    cout << "[00:00] L'orario è stato ripristinato a 00:00" << endl;
}

// Metodo per rimuovere tutti i timer
void Serra::resetTimers() {
    for (auto& impianto : impianti) {
        impianto->rimuoviTimer();
    }
    
    cout << "[" << orarioAttuale.toString() << "] Tutti i timer sono stati rimossi" << endl;
}

// Metodo per resettare l'orario e rimuovere tutti i timer
void Serra::resetAll() {
    resetTime();
    resetTimers();
}

// Metodo per ottenere informazioni sulla serra
void Serra::mostraStatoSerra() const {
    cout << "=== STATO SERRA ===" << endl;
    cout << "Orario attuale: " << orarioAttuale.toString() << endl;

    int attivi = 0;
    for(int i = 0; i < impianti.size(); i++) {
        if(impianti[i]->isAttivo()) {
            attivi++;
        }
    }
    cout << "Impianti attivi: " << attivi << "/" << impianti.size() << endl;

    cout << "Consumo totale: ";
    cout.precision(2);
    cout << fixed << getConsumoTotale() << " L" << endl;

    cout << "\nElenco impianti:" << endl;
    for(int i = 0; i < impianti.size(); i++) {
        cout << "- " << impianti[i]->getDettagli() << endl;
    }
}

// Metodo per ottenere informazioni su un'impianto
void Serra::mostraStatoImpianto(const string& nome) const {
    bool trovato = false;

    for(int i = 0; i < impianti.size(); i++) {
        if(impianti[i]->getNome() == nome) {
            cout << "=== DETTAGLI IMPIANTO ===" << endl;
            cout << impianti[i]->getDettagli() << endl;
            trovato = true;
            break;
        }
    }

    if(!trovato) {
        cout << "Impianto \"" << nome << "\" non trovato." << endl;
    }
}

// Metodo per ottenere il consumo totale della serra
double Serra::getConsumoTotale() const {
    double totale = 0.0;
    for (auto& impianto : impianti) {
        totale += impianto->getConsumoAcqua();
    }
    return totale;
}