#include <iostream>
#include <string>

enum GENDER {
    U, M, F
};

// 1. Создать несколько Human. +
// 2. Добавить несколько дополнительных полей (не забывать добавить значимые поля в конструктор) +
// 3. Добавить getter'ы и setter'ы +
// 4. Продемонстрировать обращение к полям объектов дочерних и родительских классов +
// 5. Добавить несколько наследников от различных родителей (сделать дерево из 5 классов) +

class Human {
    int age;
    int tall;
    bool conviction;
    GENDER gender;
public:
    Human(int age, int tall, bool conviction, GENDER gender) : age(age), tall(tall), conviction(conviction) {
        this->gender = gender;
        this->conviction = conviction;
        this->age = age;
        this->tall = tall;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getTall() const {
        return tall;
    }

    void setTall(int tall) {
        this->tall = tall;
    }

    bool getConviction() const {
        return conviction;
    }

    void setConviction(bool conviction) {
        this->conviction = conviction;
    }

    GENDER getGender() const {
        return gender;
    }

    void setGender(GENDER gender) {
        this->gender = gender;
    }
};

class Student : public Human {
    std::string numberOfZachetka;
public:
    Student(int age, int tall, bool conviction, GENDER gender, const std::string &numberOfZachetka) : Human(age, tall,
                                                                                                            conviction,
                                                                                                            gender) {
        this->numberOfZachetka = numberOfZachetka;
    }

    const std::string &getNumberOfZachetka() const {
        return numberOfZachetka;
    }

    void setNumberOfZachetka(const std::string &numberOfZachetka) {
        this->numberOfZachetka = numberOfZachetka;
    }
};

class BadStudent : public Student {
    int valueOfDolgi;
public:
    BadStudent(int age, int tall, bool conviction, GENDER gender, const std::string &numberOfZachetka, int valueOfDolgi)
            : Student(age,
                      tall,
                      conviction,
                      gender, numberOfZachetka) {
        this->valueOfDolgi = valueOfDolgi;
    }

    int getValueOfDolgi() {
        return valueOfDolgi;
    }

    void setValueOfDolgi(int valueOfDolgi) {
        this->valueOfDolgi = valueOfDolgi;
    }

};

class GoodStudent : public Student {
    int valueOfAutomates;
public:
    GoodStudent(int age, int tall, bool conviction, GENDER gender, const std::string &numberOfZachetka,
                int valueOfAutomates)
            : Student(age,
                      tall,
                      conviction,
                      gender, numberOfZachetka) {
        this->valueOfAutomates = valueOfAutomates;
    }

    int getValueOfAutomates() {
        return valueOfAutomates;
    }

    void setValueOfAutomates(int valueOfAutomates) {
        this->valueOfAutomates = valueOfAutomates;
    }
};

class HardWorker : public Human {
    std::string proffession;
public:
    HardWorker(int age, int tall, bool conviction, GENDER gender, const std::string &profession) : Human(age, tall,
                                                                                                         conviction,
                                                                                                         gender) {
        this->proffession = profession;
    }

    const std::string &getProfession() {
        return proffession;
    }

    void setProfession(std::string &profession) {
        this->proffession = profession;
    }


};

int main() {
    Human vasya(24, 173, true, GENDER::M);
    Human slava(20, 181, false, GENDER::M);
    Human vladimir(19, 210, false, GENDER::M);

    Student olya(25, 146, false, GENDER::F, "648756568");

    std::cout << vasya.getAge() << std::endl;
    std::cout << vasya.getGender() << std::endl;
    std::cout << vasya.getTall() << std::endl;
    std::cout << vasya.getConviction() << std::endl;

    std::cout << olya.getAge() << std::endl;
    std::cout << olya.getGender() << std::endl;
    std::cout << olya.getTall() << std::endl;
    std::cout << olya.getConviction() << std::endl;
    std::cout << olya.getNumberOfZachetka() << std::endl;


    return 0;
}