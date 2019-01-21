/*
 * storage.h
 *
 *  Created on: Jan 22, 2019
 *      Author: Yves Holvoet
 */

#ifndef STORAGE_H_
#define STORAGE_H_

#include "watchData.h"

// Max Size
int stCapacityInWatchData();
int stCapacityInChars();

// Percentage filled (between 0.0 and 1.0)
double stPercentageFilled();

// Write
void stMakeEmpty();
// Returns 0 if full, 1 otherwise
int stAddWatchData(WatchData wd);
// Returns 0 if full, actual number
// of char added otherwise.
int stAddChars(const char* data, int lg);

// Read
typedef struct {
	const WatchData* base;
	int lg;
	int max;
} WatchDataArray;
WatchDataArray getAsWatchDataArray();

typedef struct {
	const char* base;
	int lg;
	int max;
} CharArray;
CharArray getAsCharArray();

#endif /* STORAGE_H_ */
