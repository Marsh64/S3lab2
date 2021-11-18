//
// Created by adm on 07.11.2021.
//

#ifndef S3_LABORATORY_WORK_2_INDEXING_H
#define S3_LABORATORY_WORK_2_INDEXING_H
#include "IDictionary.h"
#include "Sequence.h"
#include "Person.h"

namespace CmpFuncForAttributies{
    template<typename T>
    bool cmpEquals(const T& a, const T& b){
        return (a == b);
    }// ==

    template<class T>
    bool cmpLess(const T& a, const T& b){
        return (a < b);
    }// <

    template<class T>
    bool cmpBigger(const T& a, const T& b){
        return (a > b);
    }// >

    template<class T>
    bool cmpNoEquals(const T& a, const T& b){
        return (a != b);
    }// !=
}

class IndexingForPerson {
private:
    int makeAttrib(Sequence<std::string>& SeqOfAttrib){
        int a;
        if (SeqOfAttrib.GetLength() != 0){
            a = SeqOfAttrib.GetLength();

            for (int i = 0; i < a; i++) {
                a *= 10;

                int b;
                if (SeqOfAttrib.Get(i) == "FirstName")
                    b = 1;
                else if (SeqOfAttrib.Get(i) == "MiddleName")
                    b = 2;
                else if (SeqOfAttrib.Get(i) == "LastName")
                    b = 3;
                else if (SeqOfAttrib.Get(i) == "BirthYear")
                    b = 4;
                else if (SeqOfAttrib.Get(i) == "Age")
                    b = 5;

                a+= b;
            }
        }
        else{
            a = 0;
        }
        return a;
    }

public:

    struct Attributies{
        bool FirstName;
        std::string cmpfname;
        bool (*CmpFirstName)(const std::string&, const std::string&);
        bool MiddleName;
        std::string cmpmname;
        bool (*CmpMiddleName)(const std::string&, const std::string&);
        bool LastName;
        std::string cmplname;
        bool (*CmpLastName)(const std::string&, const std::string&);
        bool BirthYear;
        int cmpby;
        bool (*CmpBirthYear)(const int&, const int&);
        bool Age;
        int cmpage;
        bool (*CmpAge)(const int&, const int&);
    };

    Dictionary<std::string, Person*, hashstr>* Indexing(Sequence<Person>& SeqOfPerson, Attributies attrib){
        Dictionary<std::string, Person*, hashstr>* index;

        for (int i = 0; i < SeqOfPerson.GetLength(); i++){
            std::string tohash = "";
            //Составляющие по которым создасться ключ для хэш таблицы

            if (attrib.FirstName){
                if (attrib.CmpFirstName != nullptr){
                    if (attrib.CmpFirstName(SeqOfPerson.Get(i).GetFirstName(), attrib.cmpfname))
                        tohash += SeqOfPerson.Get(i).GetFirstName();
                }
                else
                    tohash += SeqOfPerson.Get(i).GetFirstName();
            }
            if (attrib.MiddleName){
                if (attrib.CmpMiddleName != nullptr){
                    if (attrib.CmpMiddleName(SeqOfPerson.Get(i).GetMiddleName(), attrib.cmpmname))
                        tohash += SeqOfPerson.Get(i).GetMiddleName();
                }
                else
                    tohash += SeqOfPerson.Get(i).GetMiddleName();
            }
            if (attrib.LastName){
                if (attrib.CmpLastName != nullptr){
                    if (attrib.CmpLastName(SeqOfPerson.Get(i).GetLastName(), attrib.cmplname))
                        tohash += SeqOfPerson.Get(i).GetLastName();
                }
                else
                    tohash += SeqOfPerson.Get(i).GetLastName();
            }
            if (attrib.BirthYear){
                if (attrib.CmpBirthYear != nullptr){
                    if (attrib.CmpBirthYear(SeqOfPerson.Get(i).GetBirthYear(), attrib.cmpby))
                        tohash += std::to_string(SeqOfPerson.Get(i).GetBirthYear());
                }
                else
                    tohash += std::to_string(SeqOfPerson.Get(i).GetBirthYear());
            }
            if (attrib.Age){
                if (attrib.CmpAge != nullptr){
                    if (attrib.CmpAge(SeqOfPerson.Get(i).GetAge(), attrib.cmpage))
                        tohash += std::to_string(SeqOfPerson.Get(i).GetAge());
                }
                else
                    tohash += std::to_string(SeqOfPerson.Get(i).GetAge());
            }

            index->Add(tohash, &SeqOfPerson.Get(i));
            return index;
        }
    }//все атрибуты переделаются в строку и запишутся в таблицу а в значение положиться указатель на человека с этими атрибутами
};


#endif //S3_LABORATORY_WORK_2_INDEXING_H
