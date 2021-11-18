#include <iostream>
#include "IDictionary.h"
//#include "string"
#include "BarGraph.h"
#include "ArraySequence.h"
#include "Indexing.h"
#include "Caching.h"

#include "Person.h"

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
IndexingForPerson::Attributies MakeAttributies(){
    std::cout << "По каким атрибутам хотите создать индекс:\n"
        << "\t1. FirstName\n"
        << "\t2. MiddleName\n"
        << "\t3. LastName\n"
        << "\t4. BirthYear\n"
        << "\t5. Age\n"
        << "Нажмите 0 для прекращения выбора." << std::endl;

    IndexingForPerson::Attributies attributies{false, nullptr, false, nullptr, false, nullptr, false, nullptr, false, nullptr};
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
            if (fatr > 5 || fatr < 0) {
                std::cout << "Введено неправильное значение!!!\n";
                continue;
            }

            std::cout << "Какой тип функции для арибута хотите использовать:\n"
                      << "\t1. ==\n"
                      << "\t2. >\n"
                      << "\t3. <\n"
                      << "\t4. !=\n"
                      << "Нажмите 0 для прекращения выбора." << std::endl;
            int fcmp;
            std::cin >> fcmp;

            //сделать много функций в namespace а потом их раскидывать


        }



    }


}

int main() {

    ArraySequence<Person> p = MakeSequenceOfRandomPerson(100);
    std::cout << "Hello, World!" << std::endl;
    std::cout << p.Get(50) << std::endl;
    std::cout << p.Get(60) << std::endl;
    /*
    Dictionary<std::string,int> dick;
    int cost1 = 2500;
    int cost2 = 2600;
    int cost3 = 2700;
    int cost4 = 2800;
    int cost5 = 2900;

    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,13,14,15,16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,28,29,30};

    for (int i = 1; i < 30; i++){
        dick.Add("car", a[i]);
    }
    dick.Add("car1", cost1);
    dick.Add("car2", cost2);
    dick.Add("car3", cost3);
    dick.Add("car4", cost4);
    dick.Add("car5", cost5);

    Person p1("a", "b", 100);
    BarGraph graph;
    Sequence<Person> list();
    list().Append(p1);

    //Dictionary<std::string, int> bargraph(graph.SplittingByName(*list, SignsToHashByName(Person)));
    //IHashTable<std::string> map();

    //bool b = map().Add(a);
    //std::cout << map().Find(a) << std::endl;
    //std::cout << map().Find(b) << std::endl;
    /*
    std::cout << "Hello, World!" << std::endl;
    std::cout << dick.ContainsKey("car") << std::endl;
    std::cout << dick.ContainsKey("car3") << std::endl;
    std::cout << dick.ContainsKey("car6") << std::endl;


    std::cout << dick.GetCapasity() << std::endl;
    std::cout << dick.GetCollumn() << std::endl;


    std::cout << dick.GetOne("car") << std::endl;
    std::cout << dick.GetOne("car1") << std::endl;
    std::cout << dick.GetOne("car2") << std::endl;
    std::cout << dick.GetOne("car3") << std::endl;
    std::cout << dick.GetOne("car4") << std::endl;
    std::cout << dick.GetOne("car5") << std::endl;
     */

    //std::cout << dick. << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
