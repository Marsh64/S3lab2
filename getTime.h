//
// Created by adm on 28.11.2021.
//

#ifndef S3_LABORATORY_WORK_2_GETTIME_H
#define S3_LABORATORY_WORK_2_GETTIME_H
#include "ITimer.h"
#include <iostream>
#include "IDictionary.h"
#include "BarGraph.h"
#include "ArraySequence.h"
#include "Indexing.h"
#include "Caching.h"
#include "menu.h"

void GetTimeFCache();
double TimeIntervalFCache(Sequence<Person> *sequence, size_t cachesize);
double TimeIntervalOrdinaryFC(Sequence<Person> *sequence);

void GetTimeFIndexing();
double TimeIntervalFIndexing(Sequence<Person> &sequence);
double TimeIntervalOrdinaryFI(Sequence<Person> &sequence);

#endif //S3_LABORATORY_WORK_2_GETTIME_H
