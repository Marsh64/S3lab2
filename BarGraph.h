//
// Created by adm on 12.10.2021.
//

#ifndef S3_LABORATORY_WORK_2_BARGRAPH_H
#define S3_LABORATORY_WORK_2_BARGRAPH_H
#include "Sequence.h"
#include "IDictionary.h"
#include "Person.h"


namespace BarGraph {
    std::string SignsToHashByFirstName(Person person){
        return person.GetFirstName();
    }
    std::string SignsToHashByMiddleName(Person person){
        return person.GetMiddleName();
    }
    std::string SignsToHashByLastName(Person person){
        return person.GetLastName();
    }
    int SignsToHashByBirthYear(Person person){
        return person.GetBirthYear();
    }
    int SignsToHashByAge(Person person){
        return person.GetAge();
    }

    Dictionary<std::string, int, hashstr> SplittingByName(Sequence<Person>* list, std::string (*SignsToHash)(Person)){
        Dictionary<std::string, int, hashstr> dict;

        //std::cout << "keys: ";
        for (int i = 0 ; i < list->GetLength(); i++){
            if (!dict.ContainsKey(SignsToHash(list->Get(i))))
                dict.Add(SignsToHash(list->Get(i)), 0);
                //std::cout << SignsToHash(list->Get(i)) << ' ';
            //}
        }
        //std::cout << std::endl;

        std::cout << dict << std::endl;
        //std::cout << dict.GetCollumn() << std::endl;

        for (int i = 0; i < list->GetLength(); i++){
            if (dict.ContainsKey(SignsToHash(list->Get(i)))){
                //std::cout << i << std::endl;
                //std::cout << hashstr(SignsToHash(list->Get(i)), 256) << std::endl;
                //std::cout << dict.GetFirstHash(SignsToHash(list->Get(i))) + 1 << std::endl;
                dict.Swap(SignsToHash(list->Get(i)), dict.GetFirstHash(SignsToHash(list->Get(i))) + 1);
                //int count = dict.GetFirstHash(SignsToHash(list->Get(i)));
                //dict.Remove(SignsToHash(list->Get(i)));
                //dict.Add(SignsToHash(list->Get(i)), count + 1);
            }
            else{
                dict.Add(SignsToHash(list->Get(i)),  1);
            }
        }

        return dict;
    }
    Dictionary<int, int, hashint> SplittingByYears(Sequence<Person>* list, int (*SignsToHash)(Person)){
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
