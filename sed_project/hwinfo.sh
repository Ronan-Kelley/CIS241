#!/bin/env bash

# print processors
lscpu | sed -n '/^CPU(s)/p' | sed -r 's/\s+/ /g'
# print physical memory stats
echo "======="
echo "Memory:"
echo "======="
free -h | sed -n '1,2p' | sed -r 's/Gi/ Gigabytes/g;s/Mi/ Megabytes/g;s/\s\s+/   /g'
# print disk info
echo ""
echo "======="
echo "Disks: "
echo "======="
df -h | sed -r -n '1p;/.*\d*T/p'
# date
echo ""
echo "======="
echo "Date:  "
echo "======="
# yes, this is supposed to be multiline, I know. However, I wrote it out this way,
# and I'm kind of proud of the spaghetti monster I have created.
date | sed -r 's/Sun/Sunday,/;s/Mon/Monday,/;s/Tues/Tuesday,/;s/Wed/Wednesday,/;s/Thurs/Thursday,/;s/Fri/Friday,/;s/Sat/Saturday,/;s/Jan/January/;s/Feb/February/;s/Aug/August/;s/Sept/September/;s/Oct/October/;s/Nov/November/;s/Dec/December/;s/AM/a.m./;s/PM/p.m./;s/EST/Eastern Standard/;s/([a-zA-Z]*, [a-zA-Z]* [0-9]{2} )([0-9]{2}:[0-9]{2}:[0-9]{2} [a-z]\.[a-z]\. [a-zA-Z]* [a-zA-Z]*) ([0-9]{4})/\1\3.\2/'

# vim: syntax=sh
