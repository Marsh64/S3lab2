//
// Created by adm on 12.10.2021.
//

#ifndef S3_LABORATORY_WORK_2_BARGRAPH_H
#define S3_LABORATORY_WORK_2_BARGRAPH_H

#include "Sequence.h"
#include "IDictionary.h"
#include "Person.h"


namespace BarGraph {
    static std::string SignsToHashByFirstName(Person person){
        return person.GetFirstName();
    }
    static std::string SignsToHashByMiddleName(Person person){
        return person.GetMiddleName();
    }
    static std::string SignsToHashByLastName(Person person){
        return person.GetLastName();
    }
    static int SignsToHashByBirthYear(Person person){
        return person.GetBirthYear();
    }
    static int SignsToHashByAge(Person person){
        return person.GetAge();
    }

    static Dictionary<std::string, int, hashstr> SplittingByName(Sequence<Person>* list, std::string (*SignsToHash)(Person)){
        Dictionary<std::string, int, hashstr> dict;

        for (int i = 0 ; i < list->GetLength(); i++){
            if (!dict.ContainsKey(SignsToHash(list->Get(i))))
                dict.Add(SignsToHash(list->Get(i)), 0);
        }

        for (int i = 0; i < list->GetLength(); i++){
            if (dict.ContainsKey(SignsToHash(list->Get(i)))){
                dict.Swap(SignsToHash(list->Get(i)), dict.GetFirstHash(SignsToHash(list->Get(i))) + 1);
            }
            else{
                dict.Add(SignsToHash(list->Get(i)),  1);
            }
        }

        return dict;
    }
    static Dictionary<int, int, hashint> SplittingByYears(Sequence<Person>* list, int (*SignsToHash)(Person)){
        Dictionary<int, int, hashint> dict;

        for (int i = 0 ; i < list->GetLength(); i++){
            if (!dict.ContainsKey(SignsToHash(list->Get(i))))
                dict.Add(SignsToHash(list->Get(i)), 0);
        }

        for (int i = 0; i < list->GetLength(); i++){
            if (dict.ContainsKey(SignsToHash(list->Get(i)))){
                dict.Swap(SignsToHash(list->Get(i)), dict.GetFirstHash(SignsToHash(list->Get(i))) + 1);
            }
            else{
                dict.Add(SignsToHash(list->Get(i)),  1);
            }
        }

        return dict;
    }
};


#endif //S3_LABORATORY_WORK_2_BARGRAPH_H
