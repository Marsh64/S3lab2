//
// Created by adm on 22.11.2021.
//
#ifndef S3_LABORATORY_WORK_2_MENU_CPP
#define S3_LABORATORY_WORK_2_MENU_CPP

#include "menu.h"
#include "tests.h"
#include "getTime.h"

ArraySequence<Person> MakeSequenceOfRandomPerson(int count){
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
void menu(){
    while(true) {
        int k;
        std::cout << "Чем вы хотите заняться?:\n"
                     "\t 1. Поиском данных\n"
                     "\t 2. Распределением объектов на группы\n"
                     "\t 3. Тесты\n"
                     "\t 4. Таймирование\n"
                     "\t (Выход - любая отличная цифра)\n"
                     ":::";
        std::cin >> k;

        if (k <= 0 || k > 4)
            break;

        switch (k) {
            case 1:
                MenuDataSearch();
                break;
            case 2:
                MenuBarGraph();
                break;
            case 3:
                tests();
                break;
            case 4:
            {
                GetTimeFCache();
                GetTimeFIndexing();
                break;
            }
            default:
                break;
        }
    }
}
void DoUWTS(ArraySequence<Person>& sequence){
    int a;
    std::cout << "Хотите посмотреть на последовательность?:\n"
                 "\t1. Да\n"
                 "\t2. Нет\n"
                 ":::";
    std::cin >> a;
    if (a == 1){
        for (int i = 0; i < sequence.GetLength(); i++) {
            std::cout << sequence.Get(i) << " ";
        }
        std::cout << std::endl;
    }
}
IndexingForPerson::Attributies MakeAttributies(){
    std::cout << "По каким атрибутам хотите создать индекс:\n"
              << "\t1. FirstName\n"
              << "\t2. MiddleName\n"
              << "\t3. LastName\n"
              << "\t4. BirthYear\n"
              << "\t5. Age\n"
              << "Нажмите 0 для прекращения выбора." << std::endl;

    IndexingForPerson::Attributies attributies{false, "", nullptr, false,
                                               "", nullptr, false, "",
                                               nullptr, false, 0, nullptr,
                                               false, 0, nullptr};
    int k = 1;

    while(k){
        std::cin >> k;
        if (k > 5 || k < 0){
            std::cout << "Введено неправильное значение!!!\n";
            continue;
        }

        if (k == 1)
            attributies.FirstName = true;
        if (k == 2)
            attributies.MiddleName = true;
        if (k == 3)
            attributies.LastName = true;
        if (k == 4)
            attributies.BirthYear = true;
        if (k == 5)
            attributies.Age = true;
    }

    std::cout << "Хотите ли вы использовать функции для индексирования?(0, 1)\n";
    int cmpTF;
    std::cin >> cmpTF;
    if(cmpTF){
        int fatr = 1;
        while(fatr){
            std::cout << "Для какого атрибута хотите добавить функцию:\n"
                      << "\t1. FirstName\n"
                      << "\t2. MiddleName\n"
                      << "\t3. LastName\n"
                      << "\t4. BirthYear\n"
                      << "\t5. Age\n"
                      << "Нажмите 0 для прекращения выбора." << std::endl;
            std::cin >> fatr;

            if (fatr == 0)
                break;

            if (fatr > 5 || fatr < 0) {
                std::cout << "Введено неправильное значение!!!\n";
                continue;
            }

            std::cout << "Какой тип функции для арибута хотите использовать:\n"
                      << "\t1. ==\n"
                      << "\t2. >\n"
                      << "\t3. <\n"
                      << "\t4. !=\n";
            int fcmp;
            std::cin >> fcmp;

            int cmpint;
            std::string cmpstr;

            std::cout << "С чем хотите сравнить?:\n";
            if (fatr < 4)
                std::cin >> cmpstr;
            else
                std::cin >> cmpint;

            switch(fatr){
                case 1:
                    attributies.cmpfname = cmpstr;
                    switch(fcmp){
                        case 1:
                            attributies.CmpFirstName = CmpFuncForAttributies::cmpEquals<std::string>; break;
                        case 2:
                            attributies.CmpFirstName = CmpFuncForAttributies::cmpBigger<std::string>; break;
                        case 3:
                            attributies.CmpFirstName = CmpFuncForAttributies::cmpLess<std::string>; break;
                        case 4:
                            attributies.CmpFirstName = CmpFuncForAttributies::cmpNoEquals<std::string>; break;
                    }
                    break;
                case 2:
                    attributies.cmpmname = cmpstr;
                    switch(fcmp){
                        case 1:
                            attributies.CmpMiddleName = CmpFuncForAttributies::cmpEquals<std::string>; break;
                        case 2:
                            attributies.CmpMiddleName = CmpFuncForAttributies::cmpBigger<std::string>; break;
                        case 3:
                            attributies.CmpMiddleName = CmpFuncForAttributies::cmpLess<std::string>; break;
                        case 4:
                            attributies.CmpMiddleName = CmpFuncForAttributies::cmpNoEquals<std::string>; break;
                    }
                    break;
                case 3:
                    attributies.cmplname = cmpstr;
                    switch(fcmp){
                        case 1:
                            attributies.CmpLastName = CmpFuncForAttributies::cmpEquals<std::string>; break;
                        case 2:
                            attributies.CmpLastName = CmpFuncForAttributies::cmpBigger<std::string>; break;
                        case 3:
                            attributies.CmpLastName = CmpFuncForAttributies::cmpLess<std::string>; break;
                        case 4:
                            attributies.CmpLastName = CmpFuncForAttributies::cmpNoEquals<std::string>; break;
                    }
                    break;
                case 4:
                    attributies.cmpby = cmpint;
                    switch(fcmp){
                        case 1:
                            attributies.CmpBirthYear = CmpFuncForAttributies::cmpEquals<int>; break;
                        case 2:
                            attributies.CmpBirthYear = CmpFuncForAttributies::cmpBigger<int>; break;
                        case 3:
                            attributies.CmpBirthYear = CmpFuncForAttributies::cmpLess<int>; break;
                        case 4:
                            attributies.CmpBirthYear = CmpFuncForAttributies::cmpNoEquals<int>; break;
                    }
                    break;
                case 5:
                    attributies.cmpage = cmpint;
                    switch(fcmp){
                        case 1:
                            attributies.CmpAge = CmpFuncForAttributies::cmpEquals<int>; break;
                        case 2:
                            attributies.CmpAge = CmpFuncForAttributies::cmpBigger<int>; break;
                        case 3:
                            attributies.CmpAge = CmpFuncForAttributies::cmpLess<int>; break;
                        case 4:
                            attributies.CmpAge = CmpFuncForAttributies::cmpNoEquals<int>; break;
                    }
                    break;
            }
        }
    }

    return attributies;
}

void MenuCaching(){
    int count;
    std::cout << "Из скольки элементов хотите последовательность?:\n"
                 ":::";
    std::cin >> count;
    if (count <= 0){
        std::cout << "Последовательность не может быть такого размера, значит будет 1000!!!\n";
        count = 1000;
    }
    ArraySequence<Person> sequence = MakeSequenceOfRandomPerson(count);
    std::cout << "Последовательность готова!!!" << std::endl;
    DoUWTS(sequence);

    int cachesize;
    std::cout << "Из скольки элементов хотите кеш?:\n"
                 ":::";
    std::cin >> cachesize;
    if (cachesize <= 0){
        std::cout << "Вы ввели неправильный разер кеша, он будет заменен на 10!!!" << std::endl;
        cachesize = 10;
    }

    Caching cache(&sequence, cachesize);

    while (true){
        int want;
        std::cout << "Хотите посмотреть на кеш или запросить элементы?\n"
                     "\t1. Хочу запросить элемент\n"
                     "\t2. Хочу посмотреть на кеш\n"
                     "\t (Выход - любая отличная цифра)\n"
                     ":::";
        std::cin >> want;

        if (want <= 0 || want > 2)
            break;

        switch (want) {
            case 1:
                int manyTF;
                std::cout << "Хотите запросить элементы пачкой?:\n"
                             "\t1. Да\n"
                             "\t2. Нет\n"
                             ":::";
                std::cin >> manyTF;

                if (manyTF != 1)
                    manyTF = 0;

                if (manyTF){
                    int findindex, findcount;
                    std::cout << "Введите кол-во запросов и индекс закпрашиваемого объекта из массива:\n";
                    std::cin >> findcount;
                    std::cin >> findindex;

                    for (int i = 0; i < findcount; i++)
                        cache.Add(sequence.Get(findindex));
                }
                else{
                    int findindex;
                    std::cout << "Введите индекс закпрашиваемого объекта из массива:\n";
                    std::cin >> findindex;

                    cache.Add(sequence.Get(findindex));
                }
                break;
            case 2:
                std::cout << cache.GetCache() << std::endl;
            default:
                break;
        }
    }
}
void MenuIndexing(){
    int count;
    std::cout << "Из скольки элементов хотите последовательность?:\n"
                 ":::";
    std::cin >> count;
    if (count <= 0){
        std::cout << "Последовательность не может быть такого размера, значит будет 1000!!!\n";
        count = 1000;
    }
    ArraySequence<Person> sequence = MakeSequenceOfRandomPerson(count);
    std::cout << "Последовательность готова!!!" << std::endl;
    DoUWTS(sequence);

    while (true){
        int rwant;
        std::cout << "Хотите индексировать последовательность?:\n"
                     "\t1. Да\n"
                     "\t2. Нет\n"
                     ":::";
        std::cin >> rwant;

        if (rwant!= 1)
            break;

        IndexingForPerson::Attributies attrib = MakeAttributies();
        int want;
        std::cout << "Хотите посмотреть на атрибуты?:\n"
                     "\t1. Да\n"
                     "\t2. Нет\n"
                     ":::";
        std::cin >> want;

        if (want!= 1)
            want = 0;

        if (want)
            std::cout << attrib << std::endl;

        std::cout << *(IndexingForPerson::Indexing(sequence, attrib)) << std::endl;
    }
}

void MenuDataSearch(){
    while (true){
        int type;
        std::cout << "Что вы хотите использовать?:\n"
                     "\t 1. Кеширование данных\n"
                     "\t 2. Индексирование данных\n"
                     "\t (Выход - любая отличная цифра)\n"
                     ":::";
        std::cin >> type;

        if (type!= 1 && type != 2)
            break;

        if (type == 1)
            MenuCaching();
        else
            MenuIndexing();

        if (type!= 1 && type != 2)
            break;
    }
}

void MenuBarGraph(){
    int count;
    std::cout << "Из скольки элементов хотите последовательность?:\n"
                 ":::";
    std::cin >> count;
    if (count <= 0){
        std::cout << "Последовательность не может быть такого размера, значит будет 1000!!!\n";
        count = 1000;
    }
    ArraySequence<Person> sequence = MakeSequenceOfRandomPerson(count);
    std::cout << "Последовательность готова!!!" << std::endl;
    DoUWTS(sequence);

    int param;
    while (true){
        std::cout << "Для какого из параметров объекта Person хотите создать гистограмму?:\n"
                     "\t1. FirstName\n"
                     "\t2. MiddleName\n"
                     "\t3. LastName\n"
                     "\t4. BirthYear\n"
                     "\t5. Age\n"
                     "\t (Выход - любая отличная цифра)\n"
                     ":::";
        std::cin >> param;

        if (param <= 0 || param > 5)
            break;

        Dictionary<std::string, int, hashstr> dictionary1;
        Dictionary<int, int, hashint> dictionary2;

        switch(param){
            case 1:
                dictionary1 = BarGraph::SplittingByName(&sequence, BarGraph::SignsToHashByFirstName);
                break;
            case 2:
                dictionary1 = BarGraph::SplittingByName(&sequence, BarGraph::SignsToHashByMiddleName);
                break;
            case 3:
                dictionary1 = BarGraph::SplittingByName(&sequence, BarGraph::SignsToHashByLastName);
                break;
            case 4:
                dictionary2 = BarGraph::SplittingByYears(&sequence, BarGraph::SignsToHashByBirthYear);
                break;
            case 5:
                dictionary2 = BarGraph::SplittingByYears(&sequence, BarGraph::SignsToHashByAge);
                break;
            default:
                break;
        }

        if (param < 4)
            std::cout << dictionary1 << std::endl;
        else
            std::cout << dictionary2 << std::endl;
    }
};


#endif //S3_LABORATORY_WORK_2_MENU_CPP