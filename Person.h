//
// Created by adm on 01.11.2021.
//

#ifndef S3_LABORATORY_WORK_2_PERSON_H
#define S3_LABORATORY_WORK_2_PERSON_H


class Person // Класс, который содержит немного информации о человеке.
{
private:
    struct DateOfBirth{
        unsigned int dayOB;
        unsigned int monthOB;
        unsigned int yearOB;
    };
    std::string firstname;
    std::string middlename;
    std::string lastname;
    DateOfBirth date{};

public:
    Person()
    {
        firstname = "";
        middlename = "";
        lastname = "";
        date = {0, 0, 0};
    }
    Person(std::string first, std::string middle, std::string last, unsigned int day, unsigned int month, unsigned int year)
    {
        this->firstname = first;
        this->middlename = middle;
        this->lastname = last;
        this->date = {day, month, year};
    }

    std::string GetFirstName(){
        return firstname;
    }
    std::string GetLastName(){
        return lastname;
    }
    std::string GetMiddleName(){
        return middlename;
    }
    std::string GetFullName(){
        return (lastname + " " + firstname + " " + middlename);
    }
    unsigned int GetBirthYear(){
        return date.yearOB;
    }
    unsigned int GetAge(){
        return (2021 - date.yearOB);
    }

    bool operator == (const Person &p) const {
        return  this->firstname == p.firstname && this->middlename == p.middlename && p.lastname == this->lastname
            && this->date.yearOB == p.date.yearOB && this->date.monthOB == p.date.monthOB && this->date.dayOB == p.date.dayOB;
    }

    friend std::ostream& operator<< (std::ostream &out, Person &p) {
        return std::cout << "[Name: " << p.firstname  << " " << p.middlename << " " << p.lastname
            << "; DateOB: "<< p.date.dayOB <<"."<< p.date.monthOB <<"."<< p.date.yearOB << "]";
    }

    friend std::ostream& operator<< (std::ostream &out, Person *p) {
        //return std::cout << "[Name: " << p->firstname  << " " << p->middlename << " " << p->lastname
        //                 << "; DateOB: "<< p->date.dayOB <<"."<< p->date.monthOB <<"."<< p->date.yearOB << "]";
        return std::cout << *p;
    }
};



#endif //S3_LABORATORY_WORK_2_PERSON_H
