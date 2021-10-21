﻿
#include <iostream>

using namespace std;

/*Task 1
Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
Определить методы переназначения имени, изменения возраста и веса.
Создать производный класс Student (студент), имеющий поле года обучения. 
Определить методы переназначения и увеличения этого значения. 
Создать счетчик количества созданных студентов.
В функции main() создать несколько студентов. По запросу вывести определенного человека.*/

class Person
{
private:
    static int count; 
protected:
    string n_name;
    int n_age;
    string n_gender;
    int n_wight;
public:
    static int GetCount() { return count; } 
    
    Person(const string& name, const int& age, const string& gender, const int& wight)
        : n_name(name), n_age(age), n_wight(wight), n_gender(gender)
    {
        count++; 
    }

    string GetName() { return n_name; } 
    int GetAge() { return n_age; }
    int GetWighr() { return n_wight; }
    virtual void Print()   
    {
        cout << n_name << ' ' << n_age << ' ' << n_gender << ' ' << n_wight << endl;
    }
};

class Student : public Person 
{
private:
    int n_year;
public:
    Student(int year, const string& name, const int age, const string& gender, const int wight)
        :Person(name, age, gender, wight), n_year(year) {}

    int GetYear() { return n_year; } 
    void AddYear(int addValue) 
    {
        n_year += addValue;
    }
    void AddYear()
    {
        n_year++; 
    }
    void Print()
    {
        cout << n_year << ' ';
        Person::Print();
    }
};

int Person::count = 0;

/*Task 2
Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
У Fruit есть две переменные-члена: name (имя) и color (цвет).
Добавить новый класс GrannySmith, который наследует класс Apple.
*/
class Fruit
{
public:
    string name;
    string color;

    Fruit(string name, string color) : name(name), color(color) {}
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return color;
    }
};


class Banana : public Fruit
{
public:
    Banana(string name = "Banana", string color = "Yellow") : Fruit(name, color) {}
};

class Apple : public Fruit
{
public:
    Apple(string name = "Apple", string color = "Red") : Fruit(name, color) {}
};

class GrannySmith : public Apple
{
public:
    GrannySmith(string name = "Granny Smith", string color = "Green") : Apple(name, color) {}
};

void BlackJack()
{
        cout << "\nСоздаем классы: Dealer, Player, Hands(Руки), Deck(Колода), Deckpile(Раздача карт).";
        cout << "\nКлассы Dealer, Player базовые, остальные производные.";
}


    int main()
    {
        {
            setlocale(LC_ALL, "rus");
            //Task 1
            cout << "\nTask 1" << "\n\n";
            auto student1 = new Student(3, "Smith", 24, "male", 60);
            auto student2 = new Student(4, "Oleg", 24, "male", 63);
            auto student3 = new Student(2, "Dmitry", 25, "male", 70);
            auto student4 = new Student(1, "Danya", 15, "male", 56);
            auto student5 = new Student(5, "Volodya", 36, "male", 53);
            student1->Print();
            student2->Print();
            student3->Print();
            student4->Print();
            student5->Print();
            delete student1;
            delete student2;
            delete student3;
            delete student4;
            delete student5;            
        }
        //Task 2
        {
            cout << "\nTask 2" << "\n\n";
            Apple a("red");
            Banana b;
            GrannySmith c;

            cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
            cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
            cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
        }
        //Task 3
        {
            cout << "\nTask 3" << "\n";
            BlackJack();
            cout << endl;
        }

        return 0;

    }





