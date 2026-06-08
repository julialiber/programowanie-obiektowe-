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
        std::cout << "[Klasa B - Pionek] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleB << ", Prywatne: " << prywatnePoleB << "\n";
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
        std::cout << "[Klasa F - Wieza] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleF << ", Prywatne: " << prywatnePoleF << "\n";
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
        std::cout << "[Klasa G - Goniec] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleG << ", Prywatne: " << prywatnePoleG << "\n";
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
        std::cout << "[Klasa H - Skoczek] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleH << ", Prywatne: " << prywatnePoleH << "\n";
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
        std::cout << "[Klasa I - Hetman] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleI << ", Prywatne: " << prywatnePoleI << "\n";
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
        std::cout << "[Klasa J - Krol] Nazwa: " << pobierzNazwe() << ", Chronione: " << chronionePoleJ << ", Prywatne: " << prywatnePoleJ << "\n";
    }

    bool dziedziczyZ(const std::string& p_wezel) const override {
        return p_wezel == "J" || KlasaE::dziedziczyZ(p_wezel);
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
            std::cout << "Wybrano kategorie bierek: " << biezacyWezel << "\n";
        } else {
            std::cout << "Blad: Kategoria '" << p_wezel << "' nie istnieje w strukturze szachowej.\n";
        }
    }

    void komenda_MO(const std::string& p_nazwa) {
        if (!czyJestLisciem(biezacyWezel)) {
            std::cout << "Blad: Konkretne figury mozna ustawiac tylko w liscach struktury (B, F, G, H, I, J).\n";
            return;
        }

        if (biezacyWezel == "B") repozytorium.push_back(new KlasaB(p_nazwa));
        else if (biezacyWezel == "F") repozytorium.push_back(new KlasaF(p_nazwa));
        else if (biezacyWezel == "G") repozytorium.push_back(new KlasaG(p_nazwa));
        else if (biezacyWezel == "H") repozytorium.push_back(new KlasaH(p_nazwa));
        else if (biezacyWezel == "I") repozytorium.push_back(new KlasaI(p_nazwa));
        else if (biezacyWezel == "J") repozytorium.push_back(new KlasaJ(p_nazwa));

        std::cout << "Ustawiono nowa figure '" << p_nazwa << "' w klasie " << biezacyWezel << ".\n";
    }

    void komenda_DO(const std::string& p_nazwa) {
        if (!czyJestLisciem(biezacyWezel)) {
            std::cout << "Blad: Zbijanie jest dozwolone tylko z poziomu konkretnego liscia.\n";
            return;
        }

        for (auto it = repozytorium.begin(); it != repozytorium.end(); ++it) {
            if ((*it)->pobierzNazwe() == p_nazwa && (*it)->pobierzNazweKlasy() == biezacyWezel) {
                delete *it;
                repozytorium.erase(it);
                std::cout << "Zbito figure '" << p_nazwa << "' z biezacej pozycji szachowej.\n";
                return;
            }
        }
        std::cout << "Nie znaleziono figury o nazwie '" << p_nazwa << "' do zbicia na tym poziomie.\n";
    }

    void komenda_MDO(const std::string& p_nazwa) {
        if (!czyJestLisciem(biezacyWezel)) {
            std::cout << "Blad: Promocja/modyfikacja jest dozwolona tylko z poziomu liscia.\n";
            return;
        }

        for (auto& ob : repozytorium) {
            if (ob->pobierzNazwe() == p_nazwa && ob->pobierzNazweKlasy() == biezacyWezel) {
                std::string nowaNazwa;
                std::cout << "Podaj nowa nazwe identyfikacyjna dla figury '" << p_nazwa << "': ";
                std::cin >> nowaNazwa;
                ob->ustawNazwe(nowaNazwa);
                std::cout << "Zmieniono status figury na '" << nowaNazwa << "'.\n";
                return;
            }
        }
        std::cout << "Nie znaleziono takiej figury w biezacym liscie.\n";
    }

    void komenda_DIR() {
        std::cout << "--- Figury widoczne z poziomu kategorii [" << biezacyWezel << "] ---\n";
        int licznik = 0;
        for (const auto& ob : repozytorium) {
            if (ob->dziedziczyZ(biezacyWezel)) {
                std::cout << "- " << ob->pobierzNazwe() << " (Typ: " << ob->pobierzNazweKlasy() << ")\n";
                licznik++;
            }
        }
        if (licznik == 0) std::cout << "Brak ustawionych figur w tej gałęzi.\n";
    }

    void komenda_SHOW(const std::string& p_nazwa) {
        for (const auto& ob : repozytorium) {
            if (ob->pobierzNazwe() == p_nazwa) {
                ob->wyswietl();
                return;
            }
        }
        std::cout << "Figura '" << p_nazwa << "' nie istnieje na szachownicy.\n";
    }

    void komenda_TREE() {
        std::cout << "A (Bierka Szachowa - Korzen)\n"
                  << " |-- B (Pionek - Lisc)\n"
                  << " |-- C (Figury Liniowe)\n"
                  << " |    |-- F (Wieza - Lisc)\n"
                  << " |    |-- G (Goniec - Lisc)\n"
                  << " |-- D (Figury Specjalne)\n"
                  << " |    |-- H (Skoczek - Lisc)\n"
                  << " |    |-- I (Hetman - Lisc)\n"
                  << " |-- E (Krolestwo)\n"
                  << "      |-- J (Krol - Lisc)\n";
    }

    void komenda_SAVE() {
        std::ofstream plik("baza_obiektow.txt");
        if (plik.is_open()) {
            for (const auto& ob : repozytorium) {
                plik << ob->serializuj() << "\n";
            }
            std::cout << "Zapisano aktualny stan partii do pliku 'baza_obiektow.txt'\n";
        } else {
            std::cout << "Blad zapisu stanu partii.\n";
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
            std::cout << "Pomyslnie wczytano stan partii z pliku.\n";
        } else {
            std::cout << "Brak zapisanego stanu partii szachowej.\n";
        }
    }
};

int main() {
    MenedzerObiektow menedzer;
    std::string komenda, argument;

    std::cout << "=== SYSTEM ZARZADZANIA HIERARCHIA BIEREK SZACHOWYCH ===\n";
    std::cout << "Wpisz 'PLANSZA' aby zobaczyc strukture klasyfikacji.\n";

    while (true) {
        std::cout << "\nSZACHY> ";
        if (!(std::cin >> komenda)) break;

        if (komenda == "EXIT" || komenda == "QUIT") {
            break;
        }
        else if (komenda == "PLANSZA") {
            menedzer.komenda_TREE();
        }
        else if (komenda == "WIDOK") {
            menedzer.komenda_DIR();
        }
        else if (komenda == "ZAPISZ_PARTIE") {
            menedzer.komenda_SAVE();
        }
        else if (komenda == "WCZYTAJ_PARTIE") {
            menedzer.komenda_READ();
        }
        else if (komenda == "WYBIERZ") {
            std::cin >> argument;
            menedzer.komenda_CD(argument);
        }
        else if (komenda == "USTAW") {
            std::cin >> argument;
            menedzer.komenda_MO(argument);
        }
        else if (komenda == "ZBIJ") {
            std::cin >> argument;
            menedzer.komenda_DO(argument);
        }
        else if (komenda == "PROMUJ") {
            std::cin >> argument;
            menedzer.komenda_MDO(argument);
        }
        else if (komenda == "STATUS") {
            std::cin >> argument;
            menedzer.komenda_SHOW(argument);
        }
        else {
            std::cout << "Blad: Nieprawidlowy ruch lub komenda szachowa.\n";
            std::string smieci;
            std::getline(std::cin, smieci);
        }
    }

    return 0;
}