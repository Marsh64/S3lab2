//
// Created by adm on 17.11.2021.
//

#ifndef S3_LABORATORY_WORK_2_SORTEDSEQUENCE_H
#define S3_LABORATORY_WORK_2_SORTEDSEQUENCE_H
#include "ArraySequence.h"



template<class T>
class SortedSequence : private ArraySequence<T> {
private:
    static bool cmp_default(const T& t1, const T& t2) {return t1 > t2;}
    bool(*cmp)(const T& t1, const T& t2) = cmp_default;
public:
    class IndexOutOfRange : ArraySequence<T> :: IndexOutOfRange{};
    SortedSequence() : ArraySequence<T>(){};

    T& Get(int index){
        return this->ArraySequence<T>::Get(index);
    }
    T GetFirst(){
        return this->ArraySequence<T>::GetFirst();
    }
    T GetLast(){
        return this->ArraySequence<T>::GetLast();
    }
    int GetLength(){
        return this->ArraySequence<T>::GetLength();
    }
    void Remove(int from, int to){
        this->ArraySequence<T>::Remove(from, to);
    }
    void RemoveLast(){
        this->ArraySequence<T>::Pop();//TODO а он значение возвращает, что сделать
    }

    void Add(const T& ob){
        if (this->GetLength() == 0){
            this->Append(ob);
            return;
        }

        //this->ArraySequence<T>::append(element);
        int left = 0;
        int right = GetLength() - 1;

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
        return this->ArraySequence<T>::operator[](index);
    }
};

template<class T>
std::ostream &operator << (std::ostream &cout, SortedSequence<T> &seq) {
    cout << '{';
    for (int i = 0; i < seq.GetLength(); i++) {
        cout << seq.Get(i);
        if (i != seq.GetLength() - 1) {
            cout << ", ";
        }
    }
    cout << '}';
    return cout;
}

#endif //S3_LABORATORY_WORK_2_SORTEDSEQUENCE_H
