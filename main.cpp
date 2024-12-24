#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <locale>
// ������ 1. ����� ���
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

// ������ 2. ����� �������
class Person {
private:
    std::string name;
    int height;

public:
    Person(const std::string& name, int height) : name(name), height(height) {}

    std::string toString() const {
        return name + ", ����: " + std::to_string(height);
    }

    void print() const {
        std::cout << toString() << std::endl;
    }
};

// ������ 3. ������� � ������
class PersonWithName {
private:
    Name name;
    int height;

public:
    PersonWithName(const Name& name, int height) : name(name), height(height) {}

    std::string toString() const {
        return name.toString() + ", ����: " + std::to_string(height);
    }

    void print() const {
        std::cout << toString() << std::endl;
    }
};

// ������ 4 � 5. ����� �����
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

// ������ 6. ����� �����
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
    // ��������� ������ ��� ������ � �������� ���������
    std::locale::global(std::locale(""));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());

    // ������ 1


    Name cleopatra("", "���������", "");
    Name pushkin("������", "���������", "���������");
    Name mayakovsky("����������", "��������", "");
    cleopatra.print();
    pushkin.print();
    mayakovsky.print();

    // ������ 2
    Person person1("���������", 152);
    Person person2("������", 167);
    Person person3("��������", 189);
    person1.print();
    person2.print();
    person3.print();

    // ������ 3
    PersonWithName pwn1(cleopatra, 152);
    PersonWithName pwn2(pushkin, 167);
    PersonWithName pwn3(mayakovsky, 189);
    pwn1.print();
    pwn2.print();
    pwn3.print();

    // ������ 4 � 5
    City cityA("����� A");
    cityA.addConnection("����� B", 5);
    cityA.addConnection("����� F", 1);
    cityA.addConnection("����� D", 6);

    City cityB("����� B");
    cityB.addConnection("����� A", 5);
    cityB.addConnection("����� F", 1);
    cityB.addConnection("����� C", 3);

    City cityC("����� C");
    cityC.addConnection("����� B", 3);
    cityC.addConnection("����� D", 4);

    City cityD("����� D");
    cityD.addConnection("����� A", 6);
    cityD.addConnection("����� E", 2);
    cityD.addConnection("����� C", 4);

    City cityE("����� E");
    cityE.addConnection("����� D", 2);
    cityE.addConnection("����� F", 2);

    City cityF("����� F");
    cityF.addConnection("����� A", 1);
    cityF.addConnection("����� B", 1);
    cityF.addConnection("����� E", 2);

    cityA.print();
    cityB.print();
    cityC.print();
    cityD.print();
    cityE.print();
    cityF.print();

    // ������ 6
    Fraction f1(1, 3), f2(2, 3), f3(3, 4);
    f1.print();
    f2.print();
    f3.print();


    Fraction result = f1.add(f2).divide(f3).subtract(Fraction(5, 1));
    std::cout << "���������: " << result.toString() << std::endl;

    return 0;
}
