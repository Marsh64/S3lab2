//
// Created by adm on 25.11.2021.
//
#ifndef S3_LABORATORY_WORK_2_TESTS_CPP
#define S3_LABORATORY_WORK_2_TESTS_CPP

#include <iostream>
#include <cassert>
#include "tests.h"


ArraySequence<Person> MakeRandomPerson(int count){
    if (count <= 0)
        return ArraySequence<Person>();

    srand(679);
    ArraySequence<Person> sequence;
    for (int i = 0; i < count; i++){
        std::string firstname = "";
        for (int j = 0; j < rand()%5 + 1; j++){
            char t = (char)(rand()%25 + 97);
            firstname+=t;
        }

        std::string middlename = "";
        for (int j = 0; j < rand()%5 + 1; j++){
            char t = (char)(rand()%25 + 97);
            middlename+=t;
        }

        std::string lastname = "";
        for (int j = 0; j < rand()%5 + 1; j++){
            char t = (char)(rand()%25 + 97);
            lastname+=t;
        }

        int dayOB = rand()%30 + 1;
        int monthOB = rand()%12 + 1;
        int yearOB = rand()%90 + 1930;

        Person p(firstname, middlename, lastname, dayOB, monthOB, yearOB);

        sequence.Append(p);
    }

    return sequence;
}
void testBarGraph(){
    std::cout << "Тестирование гистограммы:\n";
    ArraySequence<Person> sequence = MakeRandomPerson(100);

    Dictionary<std::string, int, hashstr> byfirstname = BarGraph::SplittingByName(&sequence, BarGraph::SignsToHashByFirstName);
    for (int i = 0; i < sequence.GetLength(); i++){
        int countbyfirstname = 0;
        for (int j = 0; j < sequence.GetLength(); j++)
            if (sequence.Get(j).GetFirstName() == sequence.Get(i).GetFirstName())
                countbyfirstname++;
        assert(byfirstname.Get(sequence.Get(i).GetFirstName()) == countbyfirstname);
    }
    std::cout << "\tС гистограммой по FirstName все хорошо!!!" << std::endl;

    Dictionary<std::string, int, hashstr> bymiddlename = BarGraph::SplittingByName(&sequence, BarGraph::SignsToHashByMiddleName);
    for (int i = 0; i < sequence.GetLength(); i++){
        int countbymiddlename = 0;
        for (int j = 0; j < sequence.GetLength(); j++)
            if (sequence.Get(j).GetMiddleName() == sequence.Get(i).GetMiddleName())
                countbymiddlename++;
        assert(bymiddlename.Get(sequence.Get(i).GetMiddleName()) == countbymiddlename);
    }
    std::cout << "\tС гистограммой по MiddleName все хорошо!!!" << std::endl;

    Dictionary<std::string, int, hashstr> bylastname = BarGraph::SplittingByName(&sequence, BarGraph::SignsToHashByLastName);
    for (int i = 0; i < sequence.GetLength(); i++){
        int countbylastname = 0;
        for (int j = 0; j < sequence.GetLength(); j++)
            if (sequence.Get(j).GetLastName() == sequence.Get(i).GetLastName())
                countbylastname++;
        assert(bylastname.Get(sequence.Get(i).GetLastName()) == countbylastname);
    }
    std::cout << "\tС гистограммой по LastName все хорошо!!!" << std::endl;

    Dictionary<int, int, hashint> bybirthyear = BarGraph::SplittingByYears(&sequence, BarGraph::SignsToHashByBirthYear);
    for (int i = 0; i < sequence.GetLength(); i++){
        int countbyby = 0;
        for (int j = 0; j < sequence.GetLength(); j++)
            if (sequence.Get(j).GetBirthYear() == sequence.Get(i).GetBirthYear())
                countbyby++;
        assert(bybirthyear.Get(sequence.Get(i).GetBirthYear()) == countbyby);
    }
    std::cout << "\tС гистограммой по BirthYear все хорошо!!!" << std::endl;

    Dictionary<int, int, hashint> byage = BarGraph::SplittingByYears(&sequence, BarGraph::SignsToHashByAge);
    for (int i = 0; i < sequence.GetLength(); i++){
        int countbyage = 0;
        for (int j = 0; j < sequence.GetLength(); j++)
            if (sequence.Get(j).GetAge() == sequence.Get(i).GetAge())
                countbyage++;
        assert(byage.Get(sequence.Get(i).GetAge()) == countbyage);
    }
    std::cout << "\tС гистограммой по Age все хорошо!!!" << std::endl;
}
void testCaching(){
    std::cout << "Тестирование кеширования:\n";
    ArraySequence<Person> sequence = MakeRandomPerson(100);

    Caching cache(&sequence, 10);
    srand(600);
    int add1 = rand()%25 + 31;
    int add2 = rand()%80 + 46;
    int add3 = rand()%12 + 431;
    int add4 = rand()%91 + 5;
    int add5 = rand()%76 + 80;

    for (int i = 0; i < add1; i++){
        cache.Add(sequence.Get( add1 % 100));
    }
    for (int i = 0; i < add2; i++){
        cache.Add(sequence.Get( add2 % 100));
    }
    for (int i = 0; i < add3; i++){
        cache.Add(sequence.Get( add3 % 100));
    }
    for (int i = 0; i < add4; i++){
        cache.Add(sequence.Get( add4 % 100));
    }
    for (int i = 0; i < add5; i++){
        cache.Add(sequence.Get( add5 % 100));
    }

    for (int j = 0; j < cache.GetCacheSize(); j++){
        if (*cache.GetCache().Get(j).person == sequence.Get( add1 % 100)){
            assert(cache.GetCache().Get(j).callcount == add1);
        }
        if (*cache.GetCache().Get(j).person == sequence.Get( add2 % 100)){
            assert(cache.GetCache().Get(j).callcount == add2);
        }
        if (*cache.GetCache().Get(j).person == sequence.Get( add3 % 100)){
            assert(cache.GetCache().Get(j).callcount == add3);
        }
        if (*cache.GetCache().Get(j).person == sequence.Get( add4 % 100)){
            assert(cache.GetCache().Get(j).callcount == add4);
        }
        if (*cache.GetCache().Get(j).person == sequence.Get( add5 % 100)){
            assert(cache.GetCache().Get(j).callcount == add5);
        }
    }

    std::cout << "\tС кешированием все хорошо!!!" << std::endl;
}
void testIndexing(){
    std::cout << "Тестирование индексирования:\n";
    ArraySequence<Person> sequence = MakeRandomPerson(100);

    IndexingForPerson::Attributies attrib1 = {true, "", nullptr, false,
                                               "", nullptr, false, "",
                                               nullptr, false, 0, nullptr,
                                               false, 0, nullptr};
    Dictionary<std::string, Person*, hashstr> dictionary1 = *(IndexingForPerson::Indexing(sequence, attrib1));

    for (int i = 0; i < sequence.GetLength(); i++){
        assert(dictionary1.ContainsKey(sequence.Get(i).GetFirstName()));
    }

    IndexingForPerson::Attributies attrib2 = {false, "", nullptr, true,
                                              "", nullptr, true, "",
                                              nullptr, false, 0, nullptr,
                                              false, 0, nullptr};
    Dictionary<std::string, Person*, hashstr> dictionary2 = *(IndexingForPerson::Indexing(sequence, attrib2));

    for (int i = 0; i < sequence.GetLength(); i++){
        assert(dictionary2.ContainsKey(sequence.Get(i).GetMiddleName() + sequence.Get(i).GetLastName()));
    }

    IndexingForPerson::Attributies attrib3 = {false, "", nullptr, false,
                                              "", nullptr, false, "",
                                              nullptr, false, 0, nullptr,
                                              true, 50, CmpFuncForAttributies::cmpEquals<int>};
    Dictionary<std::string, Person*, hashstr> dictionary3 = *(IndexingForPerson::Indexing(sequence, attrib3));

    for (int i = 0; i < sequence.GetLength(); i++){
        if (sequence.Get(i).GetAge() == 50)
            assert(dictionary3.ContainsKey(std::to_string(sequence.Get(i).GetAge())));
    }

    std::cout << "\tС индексированием все хорошо!!!" << std::endl;
}

void tests(){
    testBarGraph();
    testCaching();
    testIndexing();
};

#endif //S3_LABORATORY_WORK_2_TESTS_CPP