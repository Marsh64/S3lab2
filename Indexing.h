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



    static Dictionary<std::string, Person*, hashstr>* Indexing(Sequence<Person>& SeqOfPerson, Attributies attrib){
        auto* index = new Dictionary<std::string, Person*, hashstr>();

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

            if (!tohash.empty())
                index->Add(tohash, &SeqOfPerson.Get(i));
        }
        return index;
    }//все атрибуты переделаются в строку и запишутся в таблицу а в значение положиться указатель на человека с этими атрибутами
};

std::ostream &operator << (std::ostream &cout, IndexingForPerson::Attributies& attrib) {
    std::cout << "Атрибуты для индекса{\n";
    if (attrib.FirstName){
        if (attrib.CmpFirstName != nullptr)
            std::cout << "\t FirstName: сравнивается с "<< attrib.cmpfname << ";\n";
        else
            std::cout << "\t FirstName;\n";
    }
    if (attrib.MiddleName){
        if (attrib.CmpMiddleName != nullptr)
            std::cout << "\t MiddleName: сравнивается с "<< attrib.cmpmname << ";\n";
        else
            std::cout << "\t MiddleName;\n";
    }
    if (attrib.LastName){
        if (attrib.CmpLastName != nullptr)
            std::cout << "\t LastName: сравнивается с "<< attrib.cmplname << ";\n";
        else
            std::cout << "\t LastName;\n";
    }
    if (attrib.BirthYear){
        if (attrib.CmpBirthYear != nullptr)
            std::cout << "\t BirthYear: сравнивается с "<< attrib.cmpby << ";\n";
        else
            std::cout << "\t BirthYear;\n";
    }
    if (attrib.Age){
        if (attrib.CmpAge != nullptr)
            std::cout << "\t Age: сравнивается с "<< attrib.cmpage << ";\n";
        else
            std::cout << "\t Age;\n";
    }
    std::cout << "}\n";
    return std::cout;
}

#endif //S3_LABORATORY_WORK_2_INDEXING_H
