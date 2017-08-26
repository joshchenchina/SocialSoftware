#!/bin/bash
#This will serve as a means of pulling all of the log data and dumping it into a text file

NEWFI='CompleteLogHistory.txt'

svn log -r HEAD:1 -v svn+ssh://cs205_2016_Grp00@compute211.cs.lafayette.edu/usr11/cs205_2016_Grp00/cs205_proj_repo > $NEWFI
