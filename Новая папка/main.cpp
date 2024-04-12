#include <iostream>
#include <string>
#include <vector>
#include <fmt/format.h>

class Human {
protected:
    std::string name;

public:
    Human(const std::string& name) : name(name){
    };
    virtual void print() const{
        std::cout << name << '\n';
    }
    virtual std::string getRank() const=0;
};

class Student : virtual public Human {
private:
    int grade;
public:
   Student (const std::string& name, int grade) : Human(name), grade(grade) {};
   std::string getRank() const{
        return "Student";
    }
    void print() const{
        // Human::print();
        std::cout << grade << " " << name <<'\n';
    }
    
    
};

class Professor : virtual public Human {
private:
    int salary;
public:
   Professor (const std::string& name, int salary) : Human(name), salary(salary) {};
   std::string getRank() const{
        return "Professor";
    }
   void print() const{
        std::cout << fmt::format("{} {} {} \n",name,salary,getRank());
    }
    
    
};
class Assistant : public Professor, public Student {
private:
    int age;
public:
    Assistant (const std::string& name, int salary, int grade, int age) : Human(name), Professor(name, salary), Student(name, grade), age(age) {};
   
    void print() const{
        std::cout << Professor::name << '\n';
    }
    std::string getRank() const{
        return "Assistant";
    }
};

// class Hse : public std::vector<Human> {
// private:

// public:
    
// };
class Hse{
private:
    std::vector<Human*> humans;

public:
    void addHuman(Human* human){
        humans.push_back(human);
    }
    void print() const {
        for(const Human* human : humans){
            human->print();
        }
    }
};
int main(int, char**){
    //  Human human("John");
     Student student("studentName", 10);
     Professor professor("professorName", 100000);
     Assistant assistant("assistantName", 7000, 9, 20);
    //  human.print();
     student.print();
     professor.print();
     std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
     Hse hse;
    //  hse.addHuman(&human);
     hse.addHuman(&student);
     hse.addHuman(&professor);
     hse.addHuman(&assistant);
     hse.print();


}
