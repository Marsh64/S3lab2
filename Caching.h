//
// Created by adm on 08.11.2021.
//

#ifndef S3_LABORATORY_WORK_2_CACHING_H
#define S3_LABORATORY_WORK_2_CACHING_H
#include "Sequence.h"
#include "Person.h"
#include "SortedSequence.h"

class Caching {
private:
    struct NodePerson{
        int callcount;
        Person* person;

        bool operator > (const NodePerson &ndp) const {
            return this->callcount > ndp.callcount;
        }

        friend std::ostream& operator<< (std::ostream &out, const  NodePerson &ndp){
            return std::cout << "{ " << ndp.callcount << " : " << ndp.person << " }   ";
        }
    };

    SortedSequence<NodePerson> cashe;//TODO что с тобой блять не так
    //Dictionary<int, Person*, hashint> dict;
    Sequence<Person>* seq;
    size_t cachesize;
public:
    Caching(Sequence<Person>* SeqOfPerson, size_t newcachesize){
        seq = SeqOfPerson;
        cachesize = newcachesize;
        for (int i = 0; i < cashe.GetLenght(); i++){
            cashe.Add({1, &SeqOfPerson->Get(i)});
        }
    }

    int FindInCashe(const Person& person){
        for (int i = 0; i < cachesize; i++)
            if (person == *cashe[i].person)
                return i;
        return -1;
    }
    bool ContainInCashe(const Person& person){
        if (cachesize == 0)
            return false;
        if(FindInCashe(person) >= 0)
            return true;
        else
            return false;
    }

    void Add(const Person& person){
        if (ContainInCashe(person)){
            int index = FindInCashe(person);
            //cashe[index].person;
            //cashe[index].callcount;
            NodePerson ndm = {cashe[index].callcount + 1, cashe[index].person};
            if (index == cachesize)
                cashe.RemoveLast();
            else
                cashe.Remove(index, index + 1);
            cashe.Add(ndm);
        }
        else{
            cashe.RemoveLast();
            cashe.Add({1, person});//TODO заебала
        }
    }

};


#endif //S3_LABORATORY_WORK_2_CACHING_H
