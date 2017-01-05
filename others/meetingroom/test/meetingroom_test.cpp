/*
 * meetingroom_test.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "meetingroom.h"
#include "gtest/gtest.h"

TEST(testcase_OK1, canmeetingroom)
{
	meetingroom_sol c;
	vector<Interval> intervals {Interval(0,30), Interval(5,10),Interval(15,20)};

	for(Interval e : intervals) std::cout << e.s << ' ' << e.e << std::endl;
	ASSERT_FALSE(c.canAttendMeetings(intervals));
}

TEST(testcase_OK2, minmeetingroom)
{
	meetingroom_sol c;
	vector<Interval> intervals {Interval(900,902), Interval(902,904),Interval(904,906),
								Interval(906,908),Interval(908,910),Interval(910,912)};

	for(Interval e : intervals) std::cout << e.s << ' ' << e.e << std::endl;
	ASSERT_EQ(2,c.minMeetingRooms(intervals));
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

