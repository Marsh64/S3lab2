//
// Created by adm on 28.11.2021.
//
#ifndef S3_LABORATORY_WORK_2_GETTIME_CPP
#define S3_LABORATORY_WORK_2_GETTIME_CPP
#include "getTime.h"
#include "ITimer.h"
#include <iostream>
double TimeIntervalFCache(Sequence<Person> *sequence, size_t cachesize){
    srand(600);
    int add1 = rand()%25 + 318;
    int add2 = rand()%80 + 467;
    int add3 = rand()%12 + 4315;
    int add4 = rand()%91 + 52;
    int add5 = rand()%76 + 809;

    ITimer timer;
    Caching cache(sequence, cachesize);

    for (int i = 0; i < add1; i++){
        cache.Add(sequence->Get(add1 % sequence->GetLength()));
    }
    for (int i = 0; i < add2; i++){
        cache.Add(sequence->Get(add2 % sequence->GetLength()));
    }
    for (int i = 0; i < add3; i++){
        cache.Add(sequence->Get(add3 % sequence->GetLength()));
    }
    for (int i = 0; i < add4; i++){
        cache.Add(sequence->Get(add4 % sequence->GetLength()));
    }
    for (int i = 0; i < add5; i++){
        cache.Add(sequence->Get(add5 % sequence->GetLength()));
    }

    return timer.Time();

}
double TimeIntervalOrdinaryFC(Sequence<Person> *sequence){
    srand(600);
    int add1 = rand()%25 + 318;
    int add2 = rand()%80 + 467;
    int add3 = rand()%12 + 4315;
    int add4 = rand()%91 + 52;
    int add5 = rand()%76 + 809;

    Person person;
    ITimer timer;
    for (int i = 0; i < add1; i++){
        for (int j = 0; j < sequence->GetLength(); j++){
            if (j == add1 % 100){
                person = sequence->Get(j);
                continue;
            }
        }
    }
    for (int i = 0; i < add2; i++){
        for (int j = 0; j < sequence->GetLength(); j++){
            if (j == add2 % 100){
                person = sequence->Get(j);
                continue;
            }
        }
    }
    for (int i = 0; i < add3; i++){
        for (int j = 0; j < sequence->GetLength(); j++){
            if (j == add3 % 100){
                person = sequence->Get(j);
                continue;
            }
        }
    }
    for (int i = 0; i < add4; i++){
        for (int j = 0; j < sequence->GetLength(); j++){
            if (j == add4 % 100){
                person = sequence->Get(j);
                continue;
            }
        }
    }
    for (int i = 0; i < add5; i++){
        for (int j = 0; j < sequence->GetLength(); j++){
            if (j == add5 % 100){
                person = sequence->Get(j);
                continue;
            }
        }
    }

    return timer.Time();
}
void GetTimeFCache(){
    std::cout << "Измерение времени выбора эементов с использованием кеша:\n"
                 "\t \t     Без использования кеша:"
                 "\t \t \t С использование кеша:" << std::endl;

    ArraySequence<Person> sequenceH = MakeSequenceOfRandomPerson(100);
    ArraySequence<Person> sequence10T = MakeSequenceOfRandomPerson(10000);
    ArraySequence<Person> sequence100T = MakeSequenceOfRandomPerson(100000);
    ArraySequence<Person> sequenceM = MakeSequenceOfRandomPerson(1000000);

    std::cout << "100(cs 10):"
                 "\t \t     " <<  TimeIntervalOrdinaryFC(&sequenceH) <<
              "\t \t \t \t           " << TimeIntervalFCache(&sequenceH, 10) << std::endl;
    std::cout << "10.000(cs 100):"
                 "\t \t     " <<  TimeIntervalOrdinaryFC(&sequence10T) <<
              "\t \t \t \t           " << TimeIntervalFCache(&sequence10T, 100) << std::endl;
    std::cout << "100.000(cs 1000):"
                 "\t \t     " <<  TimeIntervalOrdinaryFC(&sequence100T) <<
              "\t \t \t \t           " << TimeIntervalFCache(&sequence100T, 1000) << std::endl;
    std::cout << "1.000.000(cs 1000):"
                 "\t \t     " <<  TimeIntervalOrdinaryFC(&sequenceM) <<
              "\t \t \t \t           " << TimeIntervalFCache(&sequenceM, 1000) << std::endl;
    std::cout << "1.000.000(cs 10000):"
                 "\t \t     " <<  TimeIntervalOrdinaryFC(&sequenceM) <<
              "\t \t \t \t           " << TimeIntervalFCache(&sequenceM, 10000) << std::endl;

}

double TimeIntervalFIndexing(Sequence<Person> &sequence){
    srand(600);
    int add1 = rand()%25 + 318;
    int add2 = rand()%80 + 467;
    int add3 = rand()%12 + 4315;

    ITimer timer;
    IndexingForPerson::Attributies attrib = {false, "", nullptr, true,
                                             "", nullptr, false, "",
                                             nullptr, false, 0, nullptr,
                                             false, 0, nullptr};
    Dictionary<std::string, Person*, hashstr> dictionary = *(IndexingForPerson::Indexing(sequence, attrib));

    Person person;
    std::string string;
    for (int i = 0; i < sequence.GetLength(); i+=10){
        string = sequence.Get(i).GetMiddleName();
        for (int j = 0; j < add1; j++){
            person = *dictionary.Get(string);
        }
    }
    for (int i = 0; i < sequence.GetLength(); i+=10){
        string = sequence.Get(i).GetMiddleName();
        for (int j = 0; j < add2; j++){
            person = *dictionary.Get(string);
        }
    }
    for (int i = 0; i < sequence.GetLength(); i+=10){
        string = sequence.Get(i).GetMiddleName();
        for (int j = 0; j < add3; j++){
            person = *dictionary.Get(string);
        }
    }

    return timer.Time();
}
double TimeIntervalOrdinaryFI(Sequence<Person> &sequence){
    srand(600);
    int add1 = rand()%25 + 318;
    int add2 = rand()%80 + 467;
    int add3 = rand()%12 + 4315;

    ITimer timer;
    Person person;
    std::string string;
    for (int i = 0; i < sequence.GetLength(); i+=10){
        string = sequence.Get(i).GetMiddleName();
        for (int j = 0; j < add1; j++){
            for (int k = 0; k < sequence.GetLength(); k++)
                if (sequence.Get(k).GetMiddleName() == string)
                    person = sequence.Get(k);
        }
    }
    for (int i = 0; i < sequence.GetLength(); i+=10){
        string = sequence.Get(i).GetMiddleName();
        for (int j = 0; j < add2; j++){
            for (int k = 0; k < sequence.GetLength(); k+=10)
                if (sequence.Get(k).GetMiddleName() == string)
                    person = sequence.Get(k);
        }
    }for (int i = 0; i < sequence.GetLength(); i+=10){
        string = sequence.Get(i).GetMiddleName();
        for (int j = 0; j < add3; j++){
            for (int k = 0; k < sequence.GetLength(); k++)
                if (sequence.Get(k).GetMiddleName() == string)
                    person = sequence.Get(k);
        }
    }

    return timer.Time();
}
void GetTimeFIndexing(){
    std::cout << "Измерение времени выбора эементов с использованием индесирования:\n"
                 "\t \t     Без использования индекса:"
                 "\t \t \t С использование индекса:" << std::endl;

    ArraySequence<Person> sequenceH = MakeSequenceOfRandomPerson(100);
    ArraySequence<Person> sequenceT = MakeSequenceOfRandomPerson(1000);
    ArraySequence<Person> sequence10T = MakeSequenceOfRandomPerson(10000);

    std::cout << "100:"
                 "\t \t     " <<  TimeIntervalOrdinaryFI(sequenceH) <<
              "\t \t \t \t           " << TimeIntervalFIndexing(sequenceH) << std::endl;
    std::cout << "1000:"
                 "\t \t     " <<  TimeIntervalOrdinaryFI(sequenceT) <<
              "\t \t \t \t           " << TimeIntervalFIndexing(sequenceT) << std::endl;
    //std::cout << "10000:"
    //             "\t \t     " <<  TimeIntervalOrdinaryFI(sequence10T) <<
    //          "\t \t \t \t           " << TimeIntervalFIndexing(sequence10T) << std::endl;
}


#endif //S3_LABORATORY_WORK_2_GETTIME_CPP