#ifndef SECOND_FREQUENT_H
#define SECOND_FREQUENT_H

#include "input_error.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


unsigned int * parseFile(char * filename);
void merge(unsigned int arr[], unsigned int low, unsigned int high, unsigned int mid);
void mergeSort(unsigned int * arr, unsigned int low, unsigned int high);
unsigned int secondFrequent(unsigned int *, unsigned int);
int checkLine(std::string string);

#endif