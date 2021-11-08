//
// Created by adm on 01.11.2021.
//

#ifndef S3_LABORATORY_WORK_2_PERSON_H
#define S3_LABORATORY_WORK_2_PERSON_H


class Person // Класс, который содержит немного информации о человеке.
{
private:
    struct DateOfBirth{
        unsigned int monthOB;
        unsigned int yearOB;
        unsigned int dayOB;
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
};



#endif //S3_LABORATORY_WORK_2_PERSON_H
