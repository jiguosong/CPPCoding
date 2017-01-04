#!/bin/sh

MYCM=$1

bpath='/home/songjiguo/ClionProjects/InterviewCoding'

mkdir -p $MYCM/src
mkdir -p $MYCM/test

#echo >> CMakeLists.txt
echo add_subdirectory\($MYCM\) >> CMakeLists.txt

if [ ! -f $MYCM/CMakeLists.txt ]; then
    echo "add_subdirectory(test)" > $MYCM/CMakeLists.txt
fi

sed -e s/XXX/$MYCM/g $bpath/CMakeLists_template.txt >> $MYCM/test/CMakeLists.txt
sed -e s/XXX/$MYCM/g $bpath/header_template.h > $MYCM/src/$MYCM.h
sed -e s/XXX/$MYCM/g $bpath/cpp_template.cpp > $MYCM/src/$MYCM.cpp

sed -e s/XXX/$MYCM/g $bpath/gtest_template.cpp > $MYCM/test/$MYCM\_test.cpp
