#!/bin/bash

# Author : Rajat Khanduja
# Date : 16 Sep 2010
# Purpose : To create a script to read a file (speech)

FILE=$1

cat $FILE | festival --tts
