//
// Created by adm on 22.11.2021.
//

#ifndef S3_LABORATORY_WORK_2_MENU_H
#define S3_LABORATORY_WORK_2_MENU_H
#include <iostream>
#include "IDictionary.h"
#include "BarGraph.h"
#include "ArraySequence.h"
#include "Indexing.h"
#include "Caching.h"

void menu();
void MenuDataSearch();
void MenuBarGraph();
ArraySequence<Person> MakeSequenceOfRandomPerson(int count);
void DoUWTS(ArraySequence<Person>&);
IndexingForPerson::Attributies MakeAttributies();
void MenuCaching();
void MenuIndexing();
#endif //S3_LABORATORY_WORK_2_MENU_H
