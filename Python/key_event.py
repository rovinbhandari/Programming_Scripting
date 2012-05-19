#!/usr/bin/python

import curses as c
import sys

def doKeyEvent(key):
    if key == '\x00' or key == '\xe0': # non ASCII key
       key = screen.getch() # fetch second character
    screen.addstr(str(key)+' ')

def doQuitEvent():
    sys.exit()

# clear the screen of clutter, stop characters auto 
# echoing to screen and then tell user what to do to quit

screen = c.initscr()
c.noecho()
screen.addstr("Hit space to end...\n")

# Now mainloop runs "forever"
while True:
     ky = screen.getch()
     if ky != -1:
       # send events to event handling functions
       if ky == ord(" "): # check for quit event
	 doQuitEvent()
       else: 
	 doKeyEvent(ky)

c.endwin()

