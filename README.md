# 🌿 Sistema di Gestione Serre Intelligenti

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.10+-green.svg)

Un sistema per la gestione intelligente di serre che monitora e controlla gli impianti di irrigazione per diverse tipologie di piante.

## 📋 Descrizione

Il progetto consiste in una libreria C++ che simula il funzionamento di una serra intelligente con diversi tipi di impianti di irrigazione, ognuno con caratteristiche specifiche in base alla tipologia di pianta associata.

## 🌱 Impianti supportati

- **Tropicale**: Irrigazione automatica ogni 2.5 ore
- **Desertico**: Irrigazione manuale
- **Mediterraneo**: Irrigazione adattiva basata sulla temperatura
- **Alpino**: Irrigazione automatica ogni 1 ora
- **Carnivoro**: Irrigazione automatica ogni 1.5 ore

## 🏗️ Struttura del progetto

```
SerraIntelligente/
├── include/
│   ├── Impianto.h
│   ├── Serra.h
│   ├── Orario.h
│   ├── ImpiantoAlpino.h
│   ├── ImpiantoCarnivoro.h
│   ├── ImpiantoDesertico.h
│   ├── ImpiantoMediterraneo.h
│   ├── ImpiantoTropicale.h
├── src/
│   ├── Impianto.cpp
│   ├── Serra.cpp
│   ├── Orario.cpp
│   ├── ImpiantoAlpino.cpp
│   ├── ImpiantoCarnivoro.cpp
│   ├── ImpiantoDesertico.cpp
│   ├── ImpiantoMediterraneo.cpp
│   ├── ImpiantoTropicale.cpp
├── CMakeLists.txt
├── main.cpp
└── README.md
```

## ⚙️ Requisiti

- Compilatore C++17 (g++ 7+, clang++ 5+)
- CMake 3.10+
- Sistema operativo: Windows/Linux/macOS

## 🛠️ Installazione

```bash
git clone https://github.com/AlePiga/SerraIntelligente.git
cd SerraIntelligente
```

## 📑 Comandi

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
| `exit`                      | Esce dal programma               |

## 👥 Autori

- @AlePiga
- @PietroCarlassara
- @Botbedi
- @NicolaPulvino
