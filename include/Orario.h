#ifndef ORARIO_H
#define ORARIO_H

#include <string>

using namespace std;

class Orario {
private:
    int ore;
    int minuti;
    
public:
    Orario();
    Orario(int h, int m);
    Orario(const std::string& time);
    
    int getOre() const;
    int getMinuti() const;
    
    void setOre(int h);
    void setMinuti(int m);
    void setOrario(int h, int m);
    void setOrario(const std::string& time);
    
    string toString() const;
    
    int differenzaMinuti(const Orario& altro) const;
    bool operator<(const Orario& altro) const;
    bool operator<=(const Orario& altro) const;
    bool operator>(const Orario& altro) const;
    bool operator>=(const Orario& altro) const;
    bool operator==(const Orario& altro) const;
    bool operator!=(const Orario& altro) const;
};

#endif