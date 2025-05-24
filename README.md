# 🌿 Sistema di Gestione Serre Intelligenti

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.10+-green.svg)
![License](https://img.shields.io/badge/License-MIT-orange.svg)

Un sistema per la gestione intelligente di serre che monitora e controlla gli impianti di irrigazione per diverse tipologie di piante.

## 📋 Descrizione

Il progetto consiste in una libreria C++ che simula il funzionamento di una serra intelligente con diversi tipi di impianti di irrigazione, ognuno con caratteristiche specifiche in base alla tipologia di pianta associata.

## 🌱 Tipologie di impianti supportati

- **Tropicale**: Irrigazione automatica ogni 2.5 ore
- **Desertica**: Irrigazione manuale
- **Mediterranea**: Irrigazione adattiva basata sulla temperatura
- **Alpina**: Irrigazione automatica ogni 1 ora
- **Carnivora**: Irrigazione automatica ogni 1.5 ore

## 🏗️ Struttura del progetto

```
serra-intelligente/
├── CMakeLists.txt          # File di configurazione CMake
├── include/                # File header
│   ├── Impianto.h          # Classe base Impianto
│   ├── Serra.h             # Classe principale Serra
│   ├── Orario.h            # Gestione del tempo
│   └── ...                 # Altre classi specifiche per tipologia
├── src/                    # File sorgente
│   ├── Impianto.cpp
│   ├── Serra.cpp
│   ├── Orario.cpp
│   └── ...                 # Implementazioni specifiche
├── main.cpp                # Programma principale
└── README.md               # Questo file
```

## ⚙️ Requisiti

- Compilatore C++17 (g++ 7+, clang++ 5+)
- CMake 3.10+
- Sistema operativo: Windows/Linux/macOS

## 🛠️ Installazione e compilazione

```bash
# Clonare il repository
git clone https://github.com/tuoutente/serra-intelligente.git
cd serra-intelligente

# Creare la build directory
mkdir build && cd build

# Configurare e compilare
cmake ..
make
```

## 🎮 Comandi disponibili

| Comando                     | Descrizione                                      |
|-----------------------------|-------------------------------------------------|
| `set ${PLANTNAME} on`       | Accende l'impianto manualmente                  |
| `set ${PLANTNAME} off`      | Spegne l'impianto manualmente                   |
| `set ${PLANTNAME} ${START} ${STOP}` | Imposta accensione/spegnimento automatico      |
| `rm ${PLANTNAME}`           | Rimuove un timer associato all'impianto         |
| `show`                      | Mostra tutti gli impianti con stato e consumo   |
| `show ${PLANTNAME}`         | Mostra lo stato di un singolo impianto          |
| `set time ${TIME}`          | Imposta l'orario attuale del sistema            |
| `reset time`                | Ripristina l'orario a 00:00                     |
| `reset timers`              | Rimuove tutti i timer                           |
| `reset all`                 | Ripristina le condizioni iniziali               |

## 📝 Logging (opzionale)

Il sistema può registrare eventi su file di log con il seguente formato:
```
[HH:MM] Messaggio di evento
```

## 👥 Autori

- [Nome Autore 1](link-profilo)
- [Nome Autore 2](link-profilo)

## 📄 Licenza

Questo progetto è rilasciato sotto licenza MIT. Vedi il file [LICENSE](LICENSE) per maggiori dettagli.
