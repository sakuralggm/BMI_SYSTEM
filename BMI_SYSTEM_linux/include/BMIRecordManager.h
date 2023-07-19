#ifndef _BMIRECORDMANAGER_H
#define _BMIRECORDMANAGER_H

#include <fstream>
#include <sstream>
#include "DataStructure.h"

bool loadRecord(string username, RECORD &records);
bool savaRecord(string username, RECORD &records);
#endif