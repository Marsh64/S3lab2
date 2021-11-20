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

    SortedSequence<NodePerson> cache;
    //Dictionary<int, Person*, hashint> dict;
    Sequence<Person>* seq;

    size_t cachesize;
public:
    Caching(Sequence<Person>* SeqOfPerson, size_t newcachesize){
        seq = SeqOfPerson;
        cachesize = newcachesize;
        for (int i = 0; i < cache.GetLenght(); i++){
            cache.Add({1, &SeqOfPerson->Get(i)});
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
            //cache[index].person;
            //cache[index].callcount;
            NodePerson ndm = {cache[index].callcount + 1, cache[index].person};
            if (index == cachesize)
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

    const SortedSequence<NodePerson>& GetCache(){
        return cache;
    }

    int GetCacheSize(){
        return cachesize;
    }
};


#endif //S3_LABORATORY_WORK_2_CACHING_H
