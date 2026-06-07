#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

// ==========================================
// HIERARCHIA KLAS (Zgodna ze schematem PDF)
// ==========================================

// --- POZIOM 1: KORZEŃ ---
class ClassA {
protected:
    std::string protectedFieldA;
private:
    std::string objectName;
    std::string className;
public:
    ClassA(std::string name, std::string cls) : objectName(name), className(cls), protectedFieldA("ProtA") {}
    virtual ~ClassA() = default;

    std::string getName() const { return objectName; }
    void setName(const std::string& newName) { objectName = newName; }
    std::string getClassName() const { return className; }

    virtual void show() const = 0;

    virtual bool inheritsFrom(const std::string& node) const {
        return node == "A";
    }

    virtual std::string serialize() const {
        return className + " " + objectName;
    }
};

// --- POZIOM 2: WĘZŁY POŚREDNIE I LIŚĆ B ---

// Liść B (bezpośredni potomek A)
class ClassB : public ClassA {
protected:
    int protectedFieldB;
private:
    double privateFieldB;
public:
    ClassB(std::string name) : ClassA(name, "B"), protectedFieldB(20), privateFieldB(2.5) {}

    void show() const override {
        std::cout << "[Klasa B] Nazwa: " << getName() << ", Prot: " << protectedFieldB << ", Priv: " << privateFieldB << "\n";
    }

    bool inheritsFrom(const std::string& node) const override {
        return node == "B" || ClassA::inheritsFrom(node);
    }
};

// Węzeł C
class ClassC : public ClassA {
protected:
    std::string protectedFieldC;
private:
    int privateFieldC;
public:
    ClassC(std::string name, std::string cls) : ClassA(name, cls), protectedFieldC("ProtC"), privateFieldC(30) {}

    void show() const override {} // Węzeł pośredni

    bool inheritsFrom(const std::string& node) const override {
        return node == "C" || ClassA::inheritsFrom(node);
    }
};

// Węzeł D
class ClassD : public ClassA {
protected:
    bool protectedFieldD;
private:
    char privateFieldD;
public:
    ClassD(std::string name, std::string cls) : ClassA(name, cls), protectedFieldD(true), privateFieldD('D') {}

    void show() const override {} // Węzeł pośredni

    bool inheritsFrom(const std::string& node) const override {
        return node == "D" || ClassA::inheritsFrom(node);
    }
};

// Węzeł E
class ClassE : public ClassA {
protected:
    float protectedFieldE;
private:
    long privateFieldE;
public:
    ClassE(std::string name, std::string cls) : ClassA(name, cls), protectedFieldE(5.5f), privateFieldE(50000) {}

    void show() const override {} // Węzeł pośredni

    bool inheritsFrom(const std::string& node) const override {
        return node == "E" || ClassA::inheritsFrom(node);
    }
};

// --- POZIOM 3: LIŚCIE ---

// Liść F (dziedziczy po C)
class ClassF : public ClassC {
protected:
    int protectedFieldF;
private:
    std::string privateFieldF;
public:
    ClassF(std::string name) : ClassC(name, "F"), protectedFieldF(60), privateFieldF("PrivF") {}

    void show() const override {
        std::cout << "[Klasa F] Nazwa: " << getName() << ", Prot: " << protectedFieldF << ", Priv: " << privateFieldF << "\n";
    }

    bool inheritsFrom(const std::string& node) const override {
        return node == "F" || ClassC::inheritsFrom(node);
    }
};

// Liść G (dziedziczy po C)
class ClassG : public ClassC {
protected:
    double protectedFieldG;
private:
    bool privateFieldG;
public:
    ClassG(std::string name) : ClassC(name, "G"), protectedFieldG(7.7), privateFieldG(false) {}

    void show() const override {
        std::cout << "[Klasa G] Nazwa: " << getName() << ", Prot: " << protectedFieldG << ", Priv: " << privateFieldG << "\n";
    }

    bool inheritsFrom(const std::string& node) const override {
        return node == "G" || ClassC::inheritsFrom(node);
    }
};

// Liść H (dziedziczy po D)
class ClassH : public ClassD {
protected:
    char protectedFieldH;
private:
    int privateFieldH;
public:
    ClassH(std::string name) : ClassD(name, "H"), protectedFieldH('H'), privateFieldH(80) {}

    void show() const override {
        std::cout << "[Klasa H] Nazwa: " << getName() << ", Prot: " << protectedFieldH << ", Priv: " << privateFieldH << "\n";
    }

    bool inheritsFrom(const std::string& node) const override {
        return node == "H" || ClassD::inheritsFrom(node);
    }
};

// Liść I (dziedziczy po D)
class ClassI : public ClassD {
protected:
    std::string protectedFieldI;
private:
    float privateFieldI;
public:
    ClassI(std::string name) : ClassD(name, "I"), protectedFieldI("ProtI"), privateFieldI(9.9f) {}

    void show() const override {
        std::cout << "[Klasa I] Nazwa: " << getName() << ", Prot: " << protectedFieldI << ", Priv: " << privateFieldI << "\n";
    }

    bool inheritsFrom(const std::string& node) const override {
        return node == "I" || ClassD::inheritsFrom(node);
    }
};

// Liść J (dziedziczy po E)
class ClassJ : public ClassE {
protected:
    bool protectedFieldJ;
private:
    double privateFieldJ;
public:
    ClassJ(std::string name) : ClassE(name, "J"), protectedFieldJ(true), privateFieldJ(10.1) {}

    void show() const override {
        std::cout << "[Klasa J] Nazwa: " << getName() << ", Prot: " << protectedFieldJ << ", Priv: " << privateFieldJ << "\n";
    }

    bool inheritsFrom(const std::string& node) const override {
        return node == "J" || ClassE::inheritsFrom(node);
    }
};

// ==========================================
// SYSTEM ZARZĄDZANIA OBIEKTAMI
// ==========================================
class ObjectManager {
private:
    std::vector<ClassA*> repository;
    std::string currentNode = "A";

    bool isValidNode(const std::string& node) {
        std::vector<std::string> nodes = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
        return std::find(nodes.begin(), nodes.end(), node) != nodes.end();
    }

    bool isLeaf(const std::string& node) {
        std::vector<std::string> leaves = {"B", "F", "G", "H", "I", "J"};
        return std::find(leaves.begin(), leaves.end(), node) != leaves.end();
    }

public:
    ~ObjectManager() {
        for (auto obj : repository) delete obj;
    }

    void command_CD(const std::string& node) {
        if (isValidNode(node)) {
            currentNode = node;
            std::cout << "Zmieniono wezel na: " << currentNode << "\n";
        } else {
            std::cout << "Blad: Wezel '" << node << "' nie istnieje w strukturze.\n";
        }
    }

    void command_MO(const std::string& name) {
        if (!isLeaf(currentNode)) {
            std::cout << "Blad: Obiekty mozna dodawac tylko do lisci (B, F, G, H, I, J).\n";
            return;
        }

        if (currentNode == "B") repository.push_back(new ClassB(name));
        else if (currentNode == "F") repository.push_back(new ClassF(name));
        else if (currentNode == "G") repository.push_back(new ClassG(name));
        else if (currentNode == "H") repository.push_back(new ClassH(name));
        else if (currentNode == "I") repository.push_back(new ClassI(name));
        else if (currentNode == "J") repository.push_back(new ClassJ(name));

        std::cout << "Utworzono obiekt '" << name << "' w klasie " << currentNode << ".\n";
    }

    void command_DO(const std::string& name) {
        if (!isLeaf(currentNode)) {
            std::cout << "Blad: Usuwanie jest dozwolone tylko z poziomu liscia.\n";
            return;
        }

        auto it = std::remove_if(repository.begin(), repository.end(),
            [&](ClassA* p) { return p->getName() == name && p->getClassName() == currentNode; });

        if (it != repository.end()) {
            delete *it;
            repository.erase(it, repository.end());
            std::cout << "Usunieto obiekt '" << name << "' z biezacego liscia.\n";
        } else {
            std::cout << "Nie znaleziono obiektu o nazwie '" << name << "' w biezacym lisciu.\n";
        }
    }

    void command_MDO(const std::string& name) {
        if (!isLeaf(currentNode)) {
            std::cout << "Blad: Modyfikacja jest dozwolona tylko z poziomu liscia.\n";
            return;
        }

        for (auto& obj : repository) {
            if (obj->getName() == name && obj->getClassName() == currentNode) {
                std::string newName;
                std::cout << "Podaj nowa nazwe dla obiektu '" << name << "': ";
                std::cin >> newName;
                obj->setName(newName);
                std::cout << "Zmodyfikowano nazwe obiektu na '" << newName << "'.\n";
                return;
            }
        }
        std::cout << "Nie znaleziono takiego obiektu w biezacym lisciu.\n";
    }

    void command_DIR() {
        std::cout << "--- Obiekty widoczne z wezla [" << currentNode << "] ---\n";
        int count = 0;
        for (const auto& obj : repository) {
            if (obj->inheritsFrom(currentNode)) {
                std::cout << "- " << obj->getName() << " (Klasa liścia: " << obj->getClassName() << ")\n";
                count++;
            }
        }
        if (count == 0) std::cout << "Brak widocznych obiektow.\n";
    }

    void command_SHOW(const std::string& name) {
        for (const auto& obj : repository) {
            if (obj->getName() == name) {
                obj->show();
                return;
            }
        }
        std::cout << "Obiekt '" << name << "' nie istnieje w calym systemie.\n";
    }

    void command_TREE() {
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

    void command_SAVE() {
        std::ofstream file("baza_obiektow.txt");
        if (file.is_open()) {
            for (const auto& obj : repository) {
                file << obj->serialize() << "\n";
            }
            std::cout << "Zapisano zbiór obiektów do pliku 'baza_obiektow.txt'\n";
        } else {
            std::cout << "Blad otwarcia pliku do zapisu.\n";
        }
    }

    void command_READ() {
        std::ifstream file("baza_obiektow.txt");
        if (file.is_open()) {
            // Czyszczenie obecnego repozytorium przed wczytaniem nowej bazy
            for (auto obj : repository) delete obj;
            repository.clear();

            std::string cls, name;
            while (file >> cls >> name) {
                if (cls == "B") repository.push_back(new ClassB(name));
                else if (cls == "F") repository.push_back(new ClassF(name));
                else if (cls == "G") repository.push_back(new ClassG(name));
                else if (cls == "H") repository.push_back(new ClassH(name));
                else if (cls == "I") repository.push_back(new ClassI(name));
                else if (cls == "J") repository.push_back(new ClassJ(name));
            }
            std::cout << "Pomyslnie odczytano baze danych z pliku.\n";
        } else {
            std::cout << "Brak pliku zapisu lub blad odczytu.\n";
        }
    }
};

// ==========================================
// INTERFEJS KONSOLOWY (CLI)
// ==========================================
int main() {
    ObjectManager manager;
    std::string command, arg;

    std::cout << "=== PROGRAM ROZPOZNAWANIA STRUKTURY KLAS ===\n";
    std::cout << "Wpisz 'TREE' aby wyswietlic strukture hierarchii.\n";

    while (true) {
        std::cout << "\nKONSOLA> ";
        if (!(std::cin >> command)) break;

        if (command == "EXIT" || command == "QUIT") {
            break;
        }
        else if (command == "TREE") {
            manager.command_TREE();
        }
        else if (command == "DIR") {
            manager.command_DIR();
        }
        else if (command == "SAVE") {
            manager.command_SAVE();
        }
        else if (command == "READ") {
            manager.command_READ();
        }
        else if (command == "CD") {
            std::cin >> arg;
            manager.command_CD(arg);
        }
        else if (command == "MO") {
            std::cin >> arg;
            manager.command_MO(arg);
        }
        else if (command == "DO") {
            std::cin >> arg;
            manager.command_DO(arg);
        }
        else if (command == "MDO") {
            std::cin >> arg;
            manager.command_MDO(arg); // Bezpieczne wywołanie - zapyta o nową nazwę wewnątrz funkcji
        }
        else if (command == "SHOW") {
            std::cin >> arg;
            manager.command_SHOW(arg);
        }
        else {
            std::cout << "Blad: Nieznana komenda.\n";
            // Czyszczenie linii w przypadku wpisania błędnych argumentów
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    }

    return 0;

}x