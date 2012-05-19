#!/usr/bin/python

import sys
import string

class test(object):
	def out(self, msg):
		print str(msg)+"\n"
	def call(self):
		self.out("blah")

if __name__ == "__main__":
	obj = test()
	obj.call()
	sys.exit(0)
