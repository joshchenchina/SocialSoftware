#!/bin/bash
#This will serve as a means of displaying the last 5 logs

svn log -l5 -r HEAD:1 -v svn+ssh://cs205_2016_Grp00@compute211.cs.lafayette.edu/usr11/cs205_2016_Grp00/cs205_proj_repo
