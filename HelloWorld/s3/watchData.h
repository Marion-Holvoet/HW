/*
 * watchData.h
 *
 *  Created on: Jan 21, 2019
 *      Author: Yves Holvoet
 */

#ifndef WATCHDATA_H_
#define WATCHDATA_H_

typedef struct {
	unsigned long long timestamp;
	struct {
		float x, y, z;
	} acceleration;
	struct {
		float x, y, z;
		struct {
			float x, y, z;
		} drift;
	} gyroscope;
} WatchData;

#endif /* WATCHDATA_H_ */
