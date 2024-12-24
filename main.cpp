#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <locale>
// Задача 1. Класс Имя
class Name {
private:
    std::string lastName;
    std::string firstName;
    std::string middleName;

public:
    Name(const std::string& last = "", const std::string& first = "", const std::string& middle = "")
        : lastName(last), firstName(first), middleName(middle) {}

    std::string toString() const {
        std::string result;
        if (!lastName.empty()) result += lastName;
        if (!firstName.empty()) {
            if (!result.empty()) result += " ";
            result += firstName;
        }
        if (!middleName.empty()) {
            if (!result.empty()) result += " ";
            result += middleName;
        }
        return result;
    }

    void print() const {
        std::cout << toString() << std::endl;
    }
};

// Задача 2. Класс Человек
class Person {
private:
    std::string name;
    int height;

public:
    Person(const std::string& name, int height) : name(name), height(height) {}

    std::string toString() const {
        return name + ", рост: " + std::to_string(height);
    }

    void print() const {
        std::cout << toString() << std::endl;
    }
};

// Задача 3. Человек с Именем
class PersonWithName {
private:
    Name name;
    int height;

public:
    PersonWithName(const Name& name, int height) : name(name), height(height) {}

    std::string toString() const {
        return name.toString() + ", рост: " + std::to_string(height);
    }

    void print() const {
        std::cout << toString() << std::endl;
    }
};

// Задачи 4 и 5. Класс Город
class City {
private:
    std::string cityName;
    std::map<std::string, int> connections;

public:
    City(const std::string& name) : cityName(name) {}

    void addConnection(const std::string& destination, int cost) {
        connections[destination] = cost;
    }

    std::string toString() const {
        std::string result = cityName + ":";
        for (const auto& connection : connections) {
            const std::string& dest = connection.first;
            int cost = connection.second;
            result += " " + dest + ":" + std::to_string(cost);
        }
        return result;
    }

    void print() const {
        std::cout << toString() << std::endl;
    }
};

// Задача 6. Класс Дробь
class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        return b == 0 ? a : gcd(b, a % b);
    }

    void reduce() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) throw std::invalid_argument("Denominator cannot be zero");
        reduce();
    }

    std::string toString() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    Fraction add(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction subtract(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction multiply(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction divide(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    void print() const {
        std::cout << toString() << std::endl;
    }
};

int main() {
    // Настройка локали для работы с русскими символами
    std::locale::global(std::locale(""));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());

    // Задача 1


    Name cleopatra("", "Клеопатра", "");
    Name pushkin("Пушкин", "Александр", "Сергеевич");
    Name mayakovsky("Маяковский", "Владимир", "");
    cleopatra.print();
    pushkin.print();
    mayakovsky.print();

    // Задача 2
    Person person1("Клеопатра", 152);
    Person person2("Пушкин", 167);
    Person person3("Владимир", 189);
    person1.print();
    person2.print();
    person3.print();

    // Задача 3
    PersonWithName pwn1(cleopatra, 152);
    PersonWithName pwn2(pushkin, 167);
    PersonWithName pwn3(mayakovsky, 189);
    pwn1.print();
    pwn2.print();
    pwn3.print();

    // Задачи 4 и 5
    City cityA("Город A");
    cityA.addConnection("Город B", 5);
    cityA.addConnection("Город F", 1);
    cityA.addConnection("Город D", 6);

    City cityB("Город B");
    cityB.addConnection("Город A", 5);
    cityB.addConnection("Город F", 1);
    cityB.addConnection("Город C", 3);

    City cityC("Город C");
    cityC.addConnection("Город B", 3);
    cityC.addConnection("Город D", 4);

    City cityD("Город D");
    cityD.addConnection("Город A", 6);
    cityD.addConnection("Город E", 2);
    cityD.addConnection("Город C", 4);

    City cityE("Город E");
    cityE.addConnection("Город D", 2);
    cityE.addConnection("Город F", 2);

    City cityF("Город F");
    cityF.addConnection("Город A", 1);
    cityF.addConnection("Город B", 1);
    cityF.addConnection("Город E", 2);

    cityA.print();
    cityB.print();
    cityC.print();
    cityD.print();
    cityE.print();
    cityF.print();

    // Задача 6
    Fraction f1(1, 3), f2(2, 3), f3(3, 4);
    f1.print();
    f2.print();
    f3.print();


    Fraction result = f1.add(f2).divide(f3).subtract(Fraction(5, 1));
    std::cout << "Результат: " << result.toString() << std::endl;

    return 0;
}
