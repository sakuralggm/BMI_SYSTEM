#ifndef _BMILOGS_H
#define _BMILOGS_H

#include "DataStructure.h"
#include "BMILogSort.h"
#include "clock.h"

void bmiLogList(USERDATA &records, int start, int increment, string format);
void bmiLogGraph(USERDATA &records, int start, int increment, string format);
void bmiHistory(RECORD &records);
void bmiLogMenu(bool state);
#endif