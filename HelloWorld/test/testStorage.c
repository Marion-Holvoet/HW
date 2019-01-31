/*
 * testStorage.c
 *
 *  Created on: Jan 22, 2019
 *      Author: Yves Holvoet
 */

#include <assert.h>

static unsigned long long getRandomLongLong() {
	return
		((unsigned long)rand() << 32) |
		((unsigned long)rand());
}

static float getRandomFloat() {
	return (float)rand();
}

static WatchData getRandomWatchData() {
	WatchData wd;
	wd.acceleration.x = getRandomLongLong();
	wd.acceleration.y = getRandomLongLong();
	wd.acceleration.z = getRandomLongLong();
	wd.gyroscope.x = getRandomLongLong();
	wd.gyroscope.y = getRandomLongLong();
	wd.gyroscope.z = getRandomLongLong();
	wd.gyroscope.drift.x = getRandomLongLong();
	wd.gyroscope.drift.y = getRandomLongLong();
	wd.gyroscope.drift.z = getRandomLongLong();
	return wd;
}

static bool isEquals(Watchdata wd1, wd2) {
	return
		(wd1.acceleration.x == wd2.acceleration.x) &&
		(wd1.acceleration.y == wd2.acceleration.y) &&
		(wd1.acceleration.z == wd2.acceleration.z) &&
		(wd1.gyroscope.x == wd2.gyroscope.x) &&
		(wd1.gyroscope.y == wd2.gyroscope.y) &&
		(wd1.gyroscope.z == wd2.gyroscope.z) &&
		(wd1.gyroscope.drift.x == wd1.gyroscope.drift.x) &&
		(wd1.gyroscope.drift.y == wd2.gyroscope.drift.y) &&
		(wd1.gyroscope.drift.z == wd2.gyroscope.drift.z);
}


