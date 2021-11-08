//
// Created by adm on 23.10.2021.
//

#ifndef S3_LABORATORY_WORK_2_IDICTIONARY_H
#define S3_LABORATORY_WORK_2_IDICTIONARY_H
#include <iostream>
#include <string>
#include "DynamicArray.cpp"

template <class TKey, class TElement>
class Dictionary {
private:
    struct Node{
        TKey key;
        TElement element;
        Node* next;
    };

    DynamicArray<Node*> table;

    //size_t capasity; //Сколько ячеек в массиве
    size_t size = table.GetLenght(); //Кол-во ячеек в массиве
    size_t amount; //Кол-во элементов во всей таблице

    // Самая простоя хеш-функция. Считает сумму ASCII кодов, делит на константу и
    // получает остаток от деления.
    static int hash(const std::string& str, size_t size)
    {
        int asciisum = 0;
        for (char i : str)
        {
            asciisum += i;
        }
        return int (asciisum % size);
    }


    void Magnification(){
        double occupacity = double (amount)/ size;
        if (occupacity >= 0.75){
            int newsize = table.GetLenght() * 2;

            int CountMemory;
            if (newsize >= table.GetCountMemory()){
                CountMemory = int(newsize * 1.5);
            }else{
                CountMemory = table.GetCountMemory();
            }
            DynamicArray<Node*> newtable (newsize, CountMemory);

            for (int i = 0; i < newtable.GetLenght(); i++) {
                newtable[i] = nullptr;
            }

            for (int index = 0; index < table.GetLenght(); index++){
                for (auto temp = table[index]; temp != nullptr; temp = temp->next){
                    int newindex = hash(temp->key, newsize);

                    if (newtable[newindex] == nullptr){
                        newtable.Set(newindex, new Node{temp->key, temp->element, nullptr});
                        //newtable[newindex] = new Node{table[index]->key, temp->element, nullptr};
                        //newtable.Relen(newtable.GetCountMemory() + 1);
                        continue;
                    }//появляется новый столбец(поэтому меням len)

                    auto tmp = newtable[newindex];
                    for (tmp; tmp->next != nullptr; tmp = tmp->next){}
                    tmp->next = new Node{temp->key, temp->element, nullptr};
                }
            }

            size = newtable.GetLenght();

            //Удаляем предыдущую
            for (int i = 0; i < table.GetLenght(); i++) {
                auto temp = table[i];
                while (temp != nullptr) {
                    auto del = temp;
                    temp = temp->next;
                    delete del;
                }
            }

            //table.Delete_DynamicArray();
            table = newtable;
        }
    }//Увеличивает таблицу, пересобирает//TODO вроде готово

public:
    class AbsenceOfIndex{};

    Dictionary()
    {
        table.Resize(8);
        amount = 0;
        size = table.GetLenght();
    }// По-умолчанию делает словарь из 8 элементов
    explicit Dictionary(int newsize){
        table.Resize(newsize);
        size = newsize;
        amount = 0;
    }

    ~Dictionary(){
        for (int i = 0; i < table.GetLenght(); i++) {
            auto temp = table[i];
            while (temp != nullptr) {
                auto del = temp;
                temp = temp->next;
                delete del;
            }
        }
    };
    //Все проверить, сделать копирующий конструктор, перегрузить операторы


    void Add(TKey key, const TElement& element){
        int index = hash(key, size);
        amount+=1;

        if (table[index] == nullptr){
            table.Set(index, new Node{key, element, nullptr});
            //table[index] = new Node{key, element, nullptr};
            //table.Relen(table.GetCountMemory() + 1);
            return;
        }//появляется новый столбец(поэтому меням len)

        auto tmp = table[index];
        for (tmp; tmp->next != nullptr; tmp = tmp->next){}
        tmp->next = new Node{key, element, nullptr};

        Magnification();
    };//Добавить элемент с заданным ключом. //TODO вроде готово

    void Remove(TKey key){
        int index = hash(key, size);

        if (table[index] == nullptr)
            throw AbsenceOfIndex();

        auto temp = table[index];
        while (temp != nullptr) {
            auto del = temp;
            temp = temp->next;
            delete del;
            amount-=1;
        }
    };//Удаляет элемент с заданным ключом.
    // Выбрасывает исключение, если заданный ключ отсутствует в таблице.
    // (Удаляет все элементы с этим ключом)//TODO вроде готово
    const DynamicArray<TElement>& Get(TKey key){
        int index = hash(key, size);

        if (table[index] == nullptr)
            throw AbsenceOfIndex();

        DynamicArray<TElement> arr;

        for (auto temp = table[index]; temp->next != nullptr; temp = temp->next){
            arr.Resize(arr.GetLenght() + 1);
            //arr.Relen(arr.Relen() + 1);
            arr.Set(arr.GetLenght() - 1, temp->element);
        }

        return &arr;
    }//Дает массив элементов таблицы с этим ключом//TODO вроде готово
    const TElement& GetOne(TKey key){
        int index = hash(key, size);

        if (table[index] == nullptr)
            throw AbsenceOfIndex();

        return table[index]->element;
    } //Дает первый элемент из столбца с этим ключом из таблицы//TODO готово
    bool ContainsKey(TKey key){
        int index = hash(key, size);

        if (table[index] == nullptr)
            return false;
        else
            return true;
    };//Проверка, что в таблице уже есть элемент с заданным ключом.//TODO готово
    int GetCollumn(){
        return size;
    }//Дает кол-во столбцов в словаре//TODO готово
    int GetCapasity(){
        return amount;
    }//Дает кол-во элементов в словаре//TODO готово
};


/*
public:


    // Вставляет элемент в таблицу
    void push ( string firstname, string lastname, int age )
    {
        int hashNumber = hash(firstname);
        Person *pers = new Person(firstname, lastname, age);
        Person *place = table[hashNumber];
        if ( place == NULL )
        {
            table[hashNumber] = pers;
            return;
        }

        while ( place->next != NULL )
        {
            place = place->next;
        }
        place->next = pers;
    }

    // Получает элемент из таблицы по его имени.
    Person* find ( string firstname )
    {
        int hashNumber = hash ( firstname );
        Person *result = table[hashNumber];
        if ( !result )
        {
            cout << "Element not found" << endl;
            return NULL;
        }
        while ( result->firstname != firstname )
        {
            if ( !result->next )
            {
                cout << "Element not found" << endl;
                break;
            }
            result = result->next;
        }
        return result;
    }
};
 */

#endif //S3_LABORATORY_WORK_2_IDICTIONARY_H
