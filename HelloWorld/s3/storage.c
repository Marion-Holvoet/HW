/*
 * storage.c
 *
 *  Created on: Jan 22, 2019
 *      Author: Yves Holvoet
 */

#include "storage.h"

// Some handy compile-time constants
enum {
	oneKilo = (1<<10),
	oneMega = (oneKilo*oneKilo),
	oneGiga = (oneKilo*oneMega),
	nbMaxWatchData = (oneGiga/sizeof(WatchData)),
	nbMaxChars = (nbMaxWatchData*sizeof(WatchData))
};

// The one giga static buffer
static union {
	WatchData wdArray[nbMaxWatchData];
	char charArray[nbMaxChars];
} buffer;
static int lgBufferInChar=0;

// Max Size
int stCapacityInWatchData() {
	return getAsWatchDataArray().max;
}
int stCapacityInChars() {
	return getAsCharArray().max;
}

// Percentage filled
double stPercentageFilled() {
	double result = lgBufferInChar;
	return result/stCapacityInChars();
}



// Write
void stMakeEmpty() {
	lgBufferInChar = 0;
}

// Returns 0 if full, 1 otherwise
int stAddWatchData(WatchData wd) {
	int result = stAddChars((const char*)&wd,
			sizeof(wd));
	return (result==0)?0:1;
}

// Returns 0 if full, actual number
// of char added otherwise.
int stAddChars(const char* data, int lg) {
	int result = 0;
	for (int i=0; i<lg; i++) {
		if (lgBufferInChar < (stCapacityInChars()-1)) {
			// Can add one more
			buffer.charArray[lgBufferInChar] = data[i];
			lgBufferInChar++;
			result++;
		} else {
			// Buffer is full, let's get the
			// hell out of here.
			break;
		}
	}
	return result;
}

// Read
WatchDataArray getAsWatchDataArray() {
	WatchDataArray wda;
	wda.base = buffer.wdArray;
	wda.lg = lgBufferInChar/sizeof(WatchData);
	wda.max = nbMaxWatchData;
	return wda;
}

CharArray getAsCharArray() {
	CharArray ca;
	ca.base = buffer.charArray;
	ca.lg = lgBufferInChar;
	ca.max = nbMaxChars;
	return ca;
}
