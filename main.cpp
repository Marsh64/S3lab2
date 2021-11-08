#include <iostream>
//#include "IHashTableHARD.h"
#include "IDictionary.h"
#include "string"
#include "BarGraph.h"
#include "ArraySequence.h"
#include "Indexing.h"
int main() {

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

    Dictionary<std::string, int> bargraph(graph.SplittingByName(*list, SignsToHashByName(Person)));
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
