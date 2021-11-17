//
// Created by adm on 17.11.2021.
//

#ifndef S3_LABORATORY_WORK_2_SORTEDSEQUENCE_H
#define S3_LABORATORY_WORK_2_SORTEDSEQUENCE_H
#include "ArraySequence.h"



template<class T>
class SortedSequence : private ArraySequence<T> {
private:
    bool cmp_default(const T& t1, const T& t2) {return t1 > t2;}

    bool(*cmp)(const T& t1, const T& t2) = cmp_default;
public:
    class IndexOutOfRange : ArraySequence<T> :: IndexOutOfRange{};

    SortedSequence() : ArraySequence<T>(){};

    const T& Get(int index){
        return this->Get(index);
    }
    const T& GetFirst(){
        return this->GetFirst();
    }
    const T& GetLast(){
        return this->GetLast();
    }
    int GetLenght(){
        return this->GetLength();
    }
    void Remove(int from, int to){
        this->Remove(from, to);
    }
    void RemoveLast(){
        this->Pop();//TODO а он значение возвращает, что сделать
    }

    void Add(const T& ob){
        if (this->GetLenght() == 0){
            this->Append(ob);
            return;
        }

        //this->ArraySequence<T>::append(element);
        int left = 0;
        int right = GetLenght() - 1;

        while (left < right){
            int mid = (right + left) / 2;
            if (cmp(ob, this->Get(mid)))
                right = mid;
            else
                left = mid + 1;
        }

        this->InsertAt(ob, left);
    }//Вставляет элемнет в нужную позицию(элементов становитсья на 1 больше)

    T &operator[](int index) {
        return this->Get(index);
    }//TODO что блять не так

};

template<class T>
std::ostream& operator<< (std::ostream &out, SortedSequence<T> &seq){
    for (int i = 0; i < seq.GetLenght(); i++){
        std::cout << seq.Get(i) << " ";
    }
    return std::cout << std::endl;
}

#endif //S3_LABORATORY_WORK_2_SORTEDSEQUENCE_H
