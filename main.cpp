#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

class KlasaA {
protected:
    std::string chronionePoleA;
private:
    std::string nazwaObiektu;
    std::string nazwaKlasy;
public:
    KlasaA(std::string p_nazwa, std::string p_klasa) : nazwaObiektu(p_nazwa), nazwaKlasy(p_klasa), chronionePoleA("ProtA") {}
    virtual ~KlasaA() = default;

    std::string pobierzNazwe() const { return nazwaObiektu; }
    void ustawNazwe(const std::string& p_nowaNazwa) { nazwaObiektu = p_nowaNazwa; }
    std::string pobierzNazweKlasy() const { return nazwaKlasy; }

    virtual void wyswietl() const = 0;

    virtual bool dziedziczyZ(const std::string& p_wezel) const {
        return p_wezel == "A";
    }

    virtual std::string serializuj() const {
        return nazwaKlasy + " " + nazwaObiektu;
    }
};

class KlasaB : public KlasaA {
protected:
    int chronionePoleB;
private:
    double prywatnePoleB;
public:
    KlasaB(std::string p_nazwa) : KlasaA(p_nazwa, "B"), chronionePoleB(20), prywatnePoleB(2.5) {}

    void wyswietl() const override {
        std::cout << "[Klasa B] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleB << ", Prywatne: " << prywatnePoleB << "\n";
    }

    bool dziedziczyZ(const std::string& p_wezel) const override {
        return p_wezel == "B" || KlasaA::dziedziczyZ(p_wezel);
    }
};

class KlasaC : public KlasaA {
protected:
    std::string chronionePoleC;
private:
    int prywatnePoleC;
public:
    KlasaC(std::string p_nazwa, std::string p_klasa) : KlasaA(p_nazwa, p_klasa), chronionePoleC("ProtC"), prywatnePoleC(30) {}

    void wyswietl() const override {}

    bool dziedziczyZ(const std::string& p_wezel) const override {
        return p_wezel == "C" || KlasaA::dziedziczyZ(p_wezel);
    }
};

class KlasaD : public KlasaA {
protected:
    bool chronionePoleD;
private:
    char prywatnePoleD;
public:
    KlasaD(std::string p_nazwa, std::string p_klasa) : KlasaA(p_nazwa, p_klasa), chronionePoleD(true), prywatnePoleD('D') {}

    void wyswietl() const override {}

    bool dziedziczyZ(const std::string& p_wezel) const override {
        return p_wezel == "D" || KlasaA::dziedziczyZ(p_wezel);
    }
};

class KlasaE : public KlasaA {
protected:
    float chronionePoleE;
private:
    long prywatnePoleE;
public:
    KlasaE(std::string p_nazwa, std::string p_klasa) : KlasaA(p_nazwa, p_klasa), chronionePoleE(5.5f), prywatnePoleE(50000) {}

    void wyswietl() const override {}

    bool dziedziczyZ(const std::string& p_wezel) const override {
        return p_wezel == "E" || KlasaA::dziedziczyZ(p_wezel);
    }
};

class KlasaF : public KlasaC {
protected:
    int chronionePoleF;
private:
    std::string prywatnePoleF;
public:
    KlasaF(std::string p_nazwa) : KlasaC(p_nazwa, "F"), chronionePoleF(60), prywatnePoleF("PrivF") {}

    void wyswietl() const override {
        std::cout << "[Klasa F] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleF << ", Prywatne: " << prywatnePoleF << "\n";
    }

    bool dziedziczyZ(const std::string& p_wezel) const override {
        return p_wezel == "F" || KlasaC::dziedziczyZ(p_wezel);
    }
};

class KlasaG : public KlasaC {
protected:
    double chronionePoleG;
private:
    bool prywatnePoleG;
public:
    KlasaG(std::string p_nazwa) : KlasaC(p_nazwa, "G"), chronionePoleG(7.7), prywatnePoleG(false) {}

    void wyswietl() const override {
        std::cout << "[Klasa G] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleG << ", Prywatne: " << prywatnePoleG << "\n";
    }

    bool dziedziczyZ(const std::string& p_wezel) const override {
        return p_wezel == "G" || KlasaC::dziedziczyZ(p_wezel);
    }
};

class KlasaH : public KlasaD {
protected:
    char chronionePoleH;
private:
    int prywatnePoleH;
public:
    KlasaH(std::string p_nazwa) : KlasaD(p_nazwa, "H"), chronionePoleH('H'), prywatnePoleH(80) {}

    void wyswietl() const override {
        std::cout << "[Klasa H] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleH << ", Prywatne: " << prywatnePoleH << "\n";
    }

    bool dziedziczyZ(const std::string& p_wezel) const override {
        return p_wezel == "H" || KlasaD::dziedziczyZ(p_wezel);
    }
};

class KlasaI : public KlasaD {
protected:
    std::string chronionePoleI;
private:
    float prywatnePoleI;
public:
    KlasaI(std::string p_nazwa) : KlasaD(p_nazwa, "I"), chronionePoleI("ProtI"), prywatnePoleI(9.9f) {}

    void wyswietl() const override {
        std::cout << "[Klasa I] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleI << ", Prywatne: " << prywatnePoleI << "\n";
    }

    bool dziedziczyZ(const std::string& p_wezel) const override {
        return p_wezel == "I" || KlasaD::dziedziczyZ(p_wezel);
    }
};

class KlasaJ : public KlasaE {
protected:
    bool chronionePoleJ;
private:
    double prywatnePoleJ;
public:
    KlasaJ(std::string p_nazwa) : KlasaE(p_nazwa, "J"), chronionePoleJ(true), prywatnePoleJ(10.1) {}

    void wyswietl() const override {
        std::cout << "[Klasa J] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleJ << ", Prywatne: " << prywatnePoleJ << "\n";
    }

    bool dziedziczyZ(const std::string& p_wezel) const override {
        return p_wezel == "J" || KlasE::dziedziczyZ(p_wezel);
    }
};

class MenedzerObiektow {
private:
    std::vector<KlasaA*> repozytorium;
    std::string biezacyWezel = "A";

    bool czyPrawidlowyWezel(const std::string& p_wezel) {
        std::vector<std::string> wezly = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
        return std::find(wezly.begin(), wezly.end(), p_wezel) != wezly.end();
    }

    bool czyJestLisciem(const std::string& p_wezel) {
        std::vector<std::string> liscie = {"B", "F", "G", "H", "I", "J"};
        return std::find(liscie.begin(), liscie.end(), p_wezel) != liscie.end();
    }

public:
    ~MenedzerObiektow() {
        for (auto ob : repozytorium) delete ob;
    }

    void komenda_CD(const std::string& p_wezel) {
        if (czyPrawidlowyWezel(p_wezel)) {
            biezacyWezel = p_wezel;
            std::cout << "Zmieniono wezel na: " << biezacyWezel << "\n";
        } else {
            std::cout << "Blad: Wezel '" << p_wezel << "' nie istnieje w strukturze.\n";
        }
    }

    void komenda_MO(const std::string& p_nazwa) {
        if (!czyJestLisciem(biezacyWezel)) {
            std::cout << "Blad: Obiekty mozna dodawac tylko do lisci (B, F, G, H, I, J).\n";
            return;
        }

        if (biezacyWezel == "B") repozytorium.push_back(new KlasaB(p_nazwa));
        else if (biezacyWezel == "F") repozytorium.push_back(new KlasaF(p_nazwa));
        else if (biezacyWezel == "G") repozytorium.push_back(new KlasaG(p_nazwa));
        else if (biezacyWezel == "H") repozytorium.push_back(new KlasaH(p_nazwa));
        else if (biezacyWezel == "I") repozytorium.push_back(new KlasaI(p_nazwa));
        else if (biezacyWezel == "J") repozytorium.push_back(new KlasaJ(p_nazwa));

        std::cout << "Utworzono obiekt '" << p_nazwa << "' w klasie " << biezacyWezel << ".\n";
    }

    void komenda_DO(const std::string& p_nazwa) {
        if (!czyJestLisciem(biezacyWezel)) {
            std::cout << "Blad: Usuwanie jest dozwolone tylko z poziomu liscia.\n";
            return;
        }

        for (auto it = repozytorium.begin(); it != repozytorium.end(); ++it) {
            if ((*it)->pobierzNazwe() == p_nazwa && (*it)->pobierzNazweKlasy() == biezacyWezel) {
                delete *it;
                repozytorium.erase(it);
                std::cout << "Usunieto obiekt '" << p_nazwa << "' z biezacego liscia.\n";
                return;
            }
        }
        std::cout << "Nie znaleziono obiektu o nazwie '" << p_nazwa << "' w biezacym lisciu.\n";
    }

    void komenda_MDO(const std::string& p_nazwa) {
        if (!czyJestLisciem(biezacyWezel)) {
            std::cout << "Blad: Modyfikacja jest dozwolona tylko z poziomu liscia.\n";
            return;
        }

        for (auto& ob : repozytorium) {
            if (ob->pobierzNazwe() == p_nazwa && ob->pobierzNazweKlasy() == biezacyWezel) {
                std::string nowaNazwa;
                std::cout << "Podaj nowa nazwe dla obiektu '" << p_nazwa << "': ";
                std::cin >> nowaNazwa;
                ob->ustawNazwe(nowaNazwa);
                std::cout << "Zmodyfikowano nazwe obiektu na '" << nowaNazwa << "'.\n";
                return;
            }
        }
        std::cout << "Nie znaleziono takiego obiektu w biezacym lisciu.\n";
    }

    void komenda_DIR() {
        std::cout << "--- Obiekty widoczne z wezla [" << biezacyWezel << "] ---\n";
        int licznik = 0;
        for (const auto& ob : repozytorium) {
            if (ob->dziedziczyZ(biezacyWezel)) {
                std::cout << "- " << ob->pobierzNazwe() << " (Klasa liscia: " << ob->pobierzNazweKlasy() << ")\n";
                licznik++;
            }
        }
        if (licznik == 0) std::cout << "Brak widocznych obiektow.\n";
    }

    void komenda_SHOW(const std::string& p_nazwa) {
        for (const auto& ob : repozytorium) {
            if (ob->pobierzNazwe() == p_nazwa) {
                ob->wyswietl();
                return;
            }
        }
        std::cout << "Obiekt '" << p_nazwa << "' nie istnieje w calym systemie.\n";
    }

    void komenda_TREE() {
        std::cout << "A (Korzen)\n"
                  << " |-- B (Lisc)\n"
                  << " |-- C\n"
                  << " |    |-- F (Lisc)\n"
                  << " |    |-- G (Lisc)\n"
                  << " |-- D\n"
                  << " |    |-- H (Lisc)\n"
                  << " |    |-- I (Lisc)\n"
                  << " |-- E\n"
                  << "      |-- J (Lisc)\n";
    }

    void komenda_SAVE() {
        std::ofstream plik("baza_obiektow.txt");
        if (plik.is_open()) {
            for (const auto& ob : repozytorium) {
                plik << ob->serializuj() << "\n";
            }
            std::cout << "Zapisano zbior obiektow do pliku 'baza_obiektow.txt'\n";
        } else {
            std::cout << "Blad otwarcia pliku do zapisu.\n";
        }
    }

    void komenda_READ() {
        std::ifstream plik("baza_obiektow.txt");
        if (plik.is_open()) {
            for (auto ob : repozytorium) delete ob;
            repozytorium.clear();

            std::string kl, nazwa;
            while (plik >> kl >> nazwa) {
                if (kl == "B") repozytorium.push_back(new KlasaB(nazwa));
                else if (kl == "F") repozytorium.push_back(new KlasaF(nazwa));
                else if (kl == "G") repozytorium.push_back(new KlasaG(nazwa));
                else if (kl == "H") repozytorium.push_back(new KlasaH(nazwa));
                else if (kl == "I") repozytorium.push_back(new KlasaI(nazwa));
                else if (kl == "J") repozytorium.push_back(new KlasaJ(nazwa));
            }
            std::cout << "Pomyslnie odczytano baze danych z pliku.\n";
        } else {
            std::cout << "Brak pliku zapisu lub blad odczytu.\n";
        }
    }
};

int main() {
    MenedzerObiektow menedzer;
    std::string komenda, argument;

    std::cout << "=== PROGRAM ROZPOZNAWANIA STRUKTURY KLAS ===\n";
    std::cout << "Wpisz 'TREE' aby wyswietlic strukture hierarchii.\n";

    while (true) {
        std::cout << "\nKONSOLA> ";
        if (!(std::cin >> komenda)) break;

        if (komenda == "EXIT" || komenda == "QUIT") {
            break;
        }
        else if (komenda == "TREE") {
            menedzer.komenda_TREE();
        }
        else if (komenda == "DIR") {
            menedzer.komenda_DIR();
        }
        else if (komenda == "SAVE") {
            menedzer.komenda_SAVE();
        }
        else if (komenda == "READ") {
            menedzer.komenda_READ();
        }
        else if (komenda == "CD") {
            std::cin >> argument;
            menedzer.komenda_CD(argument);
        }
        else if (komenda == "MO") {
            std::cin >> argument;
            menedzer.komenda_MO(argument);
        }
        else if (komenda == "DO") {
            std::cin >> argument;
            menedzer.komenda_DO(argument);
        }
        else if (komenda == "MDO") {
            std::cin >> argument;
            menedzer.komenda_MDO(argument);
        }
        else if (komenda == "SHOW") {
            std::cin >> argument;
            menedzer.komenda_SHOW(argument);
        }
        else {
            std::cout << "Blad: Nieznana komenda.\n";
            std::string smieci;
            std::getline(std::cin, smieci);
        }
    }

    return 0;
}