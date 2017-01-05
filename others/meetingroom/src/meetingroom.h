/*
 * meetingroom.h
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#ifndef MEETINGROOM_H_
#define MEETINGROOM_H_

#include <vector>
using std::vector;

struct Interval {
	int s;
	int e;
	Interval(int x, int y): s(x), e(y) {};
};

class meetingroom_sol {
public:
	int minMeetingRooms(vector<Interval>& intervals);
	bool canAttendMeetings(vector<Interval>& intervals);
};



#endif /* MEETINGROOM_H_ */
