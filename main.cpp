#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <stdexcept>
#include "include/Orario.h"
#include "include/ImpiantoTropicale.h"
#include "include/ImpiantoDesertico.h"
#include "include/ImpiantoMediterraneo.h"
#include "include/ImpiantoAlpino.h"
#include "include/ImpiantoCarnivoro.h"
#include "include/Serra.h"

using namespace std;

vector<string> splitString(const string& input, char delimiter) {
    vector<string> tokens;
    stringstream ss(input);
    string token;

    while (getline(ss, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    return tokens;
}
void processCommand(const string &command, Serra &serra, const Orario &now);
void logMessage(const Orario &time, const string &message, const int &errorLevel);
vector<string> commandParser(const string &command);

int main() {
    system("chcp 65001"); // Per scrivere la è accentata
    cout << "Digita 'help' per l'elenco dei comandi" << endl;
    cout << "  _________                            .__        __         .__  .__  .__                      __          " << endl;
    cout << " /   _____/ _______________________    |__| _____/  |_  ____ |  | |  | |__| ____   ____   _____/  |_  ____  " << endl;
    cout << " \\_____  \\_/ __ \\_  __ \\_  __ \\__  \\   |  |/    \\   __\\/ __ \\|  | |  | |  |/ ___\\_/ __ \\ /    \\   __\\/ __ \\ " << endl;
    cout << " /        \\  ___/|  | \\/|  | \\// __ \\_ |  |   |  \\  | \\  ___/|  |_|  |_|  / /_/  >  ___/|   |  \\  | \\  ___/ " << endl;
    cout << "/_______  /\\___  >__|   |__|  (____  / |__|___|  /__|  \\___  >____/____/__\\___  / \\___  >___|  /__|  \\___  >" << endl;
    cout << "        \\/     \\/                  \\/          \\/          \\/            /_____/      \\/     \\/          \\/ " << endl;
    cout << endl;
    Serra serra;

    serra.aggiungiImpianto(make_unique<ImpiantoTropicale>(1, "Tropicale"));
    serra.aggiungiImpianto(make_unique<ImpiantoDesertico>(2, "Desertico"));
    serra.aggiungiImpianto(make_unique<ImpiantoMediterraneo>(3, "Mediterraneo"));
    serra.aggiungiImpianto(make_unique<ImpiantoAlpino>(4, "Alpino"));
    serra.aggiungiImpianto(make_unique<ImpiantoCarnivoro>(5, "Carnivoro"));

    serra.impostaTimer("Tropicale", Orario(0, 0));
    serra.impostaTimer("Alpino", Orario(0, 0));
    serra.impostaTimer("Carnivoro", Orario(0, 0));

    string input;
    bool running = true;

    while (running) {
        cout << "> ";
        getline(cin, input);

        if (input.empty()) continue;

        try {
            Orario now = serra.getOrarioAttuale();
            processCommand(input, serra, now);
        }
        catch (const exception &e) {
            Orario now = serra.getOrarioAttuale();
            logMessage(now, e.what(), 1);
        }
    }

    return 0;
}

void processCommand(const string &command, Serra &serra, const Orario &now) {
    logMessage(now, "L'orario attuale è " + now.toString(),0);
    vector<string> tokens = commandParser(command);

    if (tokens.empty()) {
        throw invalid_argument("Errore: comando vuoto.");
    }

    const string &action = tokens[0];

    if (action == "set") {
        if (tokens.size() < 2) {
            throw invalid_argument("Errore: comando 'set' incompleto.");
        }

        const string &deviceName = tokens[1];

        if (deviceName == "time") {
            if (tokens.size() != 3) {
                throw invalid_argument("Errore: formato per 'set timè non valido. Usa: set time HH:MM");
            }

            serra.impostaOrario(Orario(tokens[2]));
        }
        else {
            if (tokens.size() < 3) {
                throw invalid_argument("Errore: comando 'set' incompleto per dispositivo.");
            }

            const string &operation = tokens[2];

            if (operation == "on") {
                serra.accendiImpianto(deviceName);
            }
            else if (operation == "off") {
                serra.spegniImpianto(deviceName);
            }
            else {
                Orario start(operation);
                if (tokens.size() == 4) {
                    Orario stop(tokens[3]);
                    serra.impostaTimer(deviceName, start, stop);
                }
                else {
                    serra.impostaTimer(deviceName, start);
                }
            }
        }
    }
    else if (action == "rm") {
        if (tokens.size() != 2) {
            throw invalid_argument("Errore: comando 'rm' non valido. Usa: rm ${DEVICENAME}");
        }

        serra.rimuoviTimer(tokens[1]);
    }
    else if (action == "show") {
        if (tokens.size() == 1) {
            serra.mostraStatoSerra();
        }
        else if (tokens.size() == 2) {
            serra.mostraStatoImpianto(tokens[1]);
        }
        else {
            throw invalid_argument("Errore: comando 'show' non valido. Usa: show oppure show ${DEVICENAME}");
        }
    }
    else if (action == "reset") {
        if (tokens.size() != 2) {
            throw invalid_argument("Errore: comando 'reset' non valido.");
        }
        const string &resetType = tokens[1];
        if (resetType == "time") {
            serra.resetTime();
        }
        else if (resetType == "timers") {
            serra.resetTimers();
        }
        else if (resetType == "all") {
            serra.resetAll();
        }
        else {
            throw invalid_argument("Errore: opzione 'reset' non valida. Usa: reset time | reset timers | reset all");
        }
    }
    else if (action == "help") {
        cout << "set ${PLANTNAME} on\t\tAccende l'impianto manualmente\n";
        cout << "set ${PLANTNAME} off\t\tSpegne l'impianto manualmente\n";
        cout << "set ${PLANTNAME} ${START} ${STOP}\tImposta accensione/spegnimento automatico\n";
        cout << "rm ${PLANTNAME}\t\t\tRimuove un timer associato all'impianto\n";
        cout << "show\t\t\t\tMostra tutti gli impianti con stato e consumo\n";
        cout << "show ${PLANTNAME}\t\tMostra lo stato di un singolo impianto\n";
        cout << "set time ${TIME}\t\tImposta l'orario attuale del sistema\n";
        cout << "reset time\t\t\tRipristina l'orario a 00:00\n";
        cout << "reset timers\t\t\tRimuove tutti i timer\n";
        cout << "reset all\t\t\tRipristina le condizioni iniziali\n";
    }
    else {
        throw invalid_argument("Errore: comando '" + action + "' non riconosciuto.");
    }
}

void logMessage(const Orario &time, const string &message, const int &errorLevel = 0) {
    if (errorLevel == 0) {
        cout << "[" << time.toString() << "]\t" << message << endl;
    }
    else if (errorLevel == 1) {
        cerr << "[" << time.toString() << "]\t" << message << endl;
    }
}

vector<string> commandParser(const string &command) {
    vector<string> tokens;
    istringstream ss(command);
    string token;

    bool isDeviceName = false;
    string deviceName;

    while (ss >> token) {
        // Avvia la raccolta del nome dispositivo dopo un comando
        if (token == "set" || token == "rm" || token == "show" || token == "reset") {
            tokens.push_back(token);
            isDeviceName = true;
            deviceName.clear();
            continue;
        }

        // Se stiamo leggendo il nome del dispositivo
        if (isDeviceName) {
            if (token == "on" || token == "off" || token.find(':') != string::npos) {
                if (!deviceName.empty()) {
                    tokens.push_back(deviceName);
                    deviceName.clear();
                }
                isDeviceName = false;
            }
        }

        if (isDeviceName) {
            if (!deviceName.empty()) {
                deviceName += " ";
            }
            deviceName += token;
        }
        else {
            tokens.push_back(token);
        }
    }

    if (!deviceName.empty()) {
        tokens.push_back(deviceName);
    }

    return tokens;
}