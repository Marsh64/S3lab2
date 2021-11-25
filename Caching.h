//
// Created by adm on 08.11.2021.
//

#ifndef S3_LABORATORY_WORK_2_CACHING_H
#define S3_LABORATORY_WORK_2_CACHING_H
#include "Sequence.h"
#include "Person.h"
#include "SortedSequence.h"
#include <iostream>

class Caching {
private:
    struct NodePerson{
        int callcount;
        Person* person;

        bool operator > (const NodePerson &ndp) const {
            return this->callcount > ndp.callcount;
        }

        friend std::ostream& operator<< (std::ostream &out, const  NodePerson &ndp){
            return std::cout << "[ " << ndp.person<< " : " << ndp.callcount << " ]   ";
        }
    };

    SortedSequence<NodePerson> cache;
    Sequence<Person>* seq;
    size_t cachesize;
public:
    class SizeMismatch{};

    Caching(Sequence<Person>* SeqOfPerson, size_t newcachesize){
        seq = SeqOfPerson;
        cachesize = newcachesize;
        if (newcachesize > SeqOfPerson->GetLength())
            throw SizeMismatch();
        for (int i = 0; i < cachesize; i++){
            cache.Add({0, &SeqOfPerson->Get(i)});
        }
    }

    int FindInCache(const Person& person){
        for (int i = 0; i < cachesize; i++)
            if (person == *cache[i].person)
                return i;
        return -1;
    }

    bool ContainInCache(const Person& person){
        if (cachesize == 0)
            return false;
        if(FindInCache(person) >= 0)
            return true;
        else
            return false;
    }

    void Add(const Person& person){
        if (ContainInCache(person)){
            int index = FindInCache(person);
            NodePerson ndm = {cache[index].callcount + 1, cache[index].person};
            if (index == cachesize - 1)
                cache.RemoveLast();
            else
                cache.Remove(index, index + 1);
            cache.Add(ndm);
        }
        else{
            cache.RemoveLast();
            cache.Add(NodePerson{1, new Person(person)});
        }
    }

    SortedSequence<NodePerson>& GetCache(){
        return cache;
    }

    int GetCacheSize(){
        return cachesize;
    }
};


#endif //S3_LABORATORY_WORK_2_CACHING_H
