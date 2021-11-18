//
// Created by adm on 12.10.2021.
//

#ifndef S3_LABORATORY_WORK_2_BARGRAPH_H
#define S3_LABORATORY_WORK_2_BARGRAPH_H
#include "Sequence.h"
#include "IDictionary.h"
#include "Person.h"

std::string SignsToHashByName(Person persone){
    return persone.GetFirstName();
}

class BarGraph {
public:
    Dictionary<std::string, int, hashstr> SplittingByName(Sequence<Person>* list, std::string (*SignsToHash)(Person)){
        Dictionary<std::string, int, hashstr> dict;

        for (int i = 0; i < list->GetLength(); i++){
            if (dict.ContainsKey(SignsToHash(list->Get(i)))){
                int count = dict.GetOne(SignsToHash(list->Get(i)));
                dict.Remove(SignsToHash(list->Get(i)));
                dict.Add(SignsToHash(list->Get(i)), count + 1);
            }
            else{
                dict.Add(SignsToHash(list->Get(i)),  1);
            }
        }

        return dict;
    }
};


#endif //S3_LABORATORY_WORK_2_BARGRAPH_H
