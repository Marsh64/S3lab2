//
// Created by adm on 23.10.2021.
//

#ifndef S3_LABORATORY_WORK_2_IDICTIONARY_H
#define S3_LABORATORY_WORK_2_IDICTIONARY_H
#include <iostream>
#include <string>
#include "DynamicArray.cpp"
static int hashstr(const std::string& key, size_t size)
{
    int asciisum = 0;
    for (char i : key)
    {
        asciisum += i;
    }
    return int (asciisum % size);
}
static int hashint(const int& key, size_t size){
    return key % size;
}

template <class TKey, class TElement, int (*hashfunction)(const TKey&, size_t)>
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
                    int newindex = hashfunction(temp->key, newsize);

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
    }//Увеличивает таблицу, пересобирает

public:
    class AbsenceOfIndex{};

    Dictionary(){
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

    Dictionary(const Dictionary& dict){
        table = dict.table;
        size = dict.size;
        amount = dict.amount;

    }

    void Add(TKey key, const TElement& element){
        int index = hashfunction(key, size);
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
    };//Добавить элемент с заданным ключом.

    void Remove(TKey key){
        int index = hashfunction(key, size);

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
    // (Удаляет все элементы с этим ключом)
    const DynamicArray<TElement>& Get(TKey key){
        int index = hashfunction(key, size);

        if (table[index] == nullptr)
            throw AbsenceOfIndex();

        DynamicArray<TElement> arr;

        for (auto temp = table[index]; temp->next != nullptr; temp = temp->next){
            arr.Resize(arr.GetLenght() + 1);
            //arr.Relen(arr.Relen() + 1);
            arr.Set(arr.GetLenght() - 1, temp->element);
        }

        return &arr;
    }//Дает массив элементов таблицы с этим ключом
    const TElement& GetOne(TKey key){
        int index = hashfunction(key, size);

        if (table[index] == nullptr)
            throw AbsenceOfIndex();

        return table[index]->element;
    } //Дает первый элемент из столбца с этим ключом из таблицы
    bool ContainsKey(TKey key){
        int index = hashfunction(key, size);

        if (table[index] == nullptr)
            return false;
        else
            return true;
    };//Проверка, что в таблице уже есть элемент с заданным ключом.
    int GetCollumn(){
        return size;
    }//Дает кол-во столбцов в словаре
    int GetCapasity(){
        return amount;
    }//Дает кол-во элементов в словаре

    Dictionary<TKey, TElement, hashfunction> &operator = (Dictionary<TKey, TElement, hashfunction> dict){
        std::swap(table, dict.table);
        size = dict.size;
        amount = dict.amount;
        return *this;
    }
};

#endif //S3_LABORATORY_WORK_2_IDICTIONARY_H
