/*
 * meetingroom.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "meetingroom.h"

#include <map>
#include <iostream>
#include <algorithm>

using std::map;

/*Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.*/
bool meetingroom_sol::canAttendMeetings(vector<Interval>& intervals) {
	sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {return a.s < b.s;});
	for (int i = 1; (size_t)i < intervals.size(); ++i) {
		if (intervals[i].s < intervals[i - 1].e) {
			return false;
		}
	}
	return true;
}


/* Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.*/
int meetingroom_sol::minMeetingRooms(vector<Interval>& intervals)
{
    vector<int> starts, ends;
	int res = 0, endpos = 0;
	for (auto a : intervals) {
		starts.push_back(a.s);
		ends.push_back(a.e);
	}
	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());

	for (int i = 0; (size_t)i < intervals.size(); ++i) {
		if (starts[i] <= ends[endpos]) ++res;
		else ++endpos;
	}
	return res;
}
