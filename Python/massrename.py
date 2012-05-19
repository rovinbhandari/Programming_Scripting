#!/usr/bin/python

#	TODO: Add functionality for recursive/non-recursive


import sys
import os
import string


def fix(name, fixtype, fixval):
	namenew = ''
	if fixtype == '--postfix':
		namenew = name + '#' + str(fixval) + '#'
	elif fixtype == '--prefix':
		namenew = '#' + str(fixval) + '#' + name
	elif fixtype == '--prechop':
		if fixval.isdigit():
			namenew = name[int(fixval):]
		else:
			print "fixval has to be an integer for chopping"
	elif fixtype == '--postchop':
		if fixval.isdigit():
			namenew = name[:(len(name) - int(fixval))]
		else:
			print "fixval has to be an integer for chopping"
	return namenew

def filenewname(filelist, fixtype, fixval):
	filelistnew = []
	for i in filelist:
		basename = (os.path.split(i))[0]
		filename = (os.path.split(i))[1]
		ext = ''
		name = ''
		filepathnew = ''
		if '.' in filename:
			namekeys = filename.split('.')
			for j in namekeys:
				if j == '':
					namekeys.remove(j)
			ext = namekeys[len(namekeys) - 1]
			name = string.rstrip(filename, '.' + ext)
			# attach/remove fix
			namenew = fix(name, fixtype, fixval)
			filepathnew = basename + '/' + namenew + '.' + ext
		else:
			name = filename
			# attach/remove fix
			namenew = fix(name, fixtype, fixval)
			filepathnew = basename + '/' + namenew
		filelistnew.append(filepathnew)
	return filelistnew

def subdirnewname(subdirlist, fixtype, fixval):
	subdirlistnew = []
	for i in subdirlist:
		basename = (os.path.split(i))[0]
		name = (os.path.split(i))[1]
		# attach/remove fix
		namenew = fix(name, fixtype, fixval)
		subdirnamenew = basename + '/' + namenew
		subdirlistnew.append(subdirnamenew)
	return subdirlistnew

def massrename(folder, fixtype, fixval, filterval = ''):
	filelist = []
	subdirlist = []
	for root, subFolders, files in os.walk(folder):
		for file in files:
			filepath = os.path.join(root, file)
			filelist.append(str(filepath))
		for subFolder in subFolders:
			subdirpath = os.path.join(root, subFolder)
			subdirlist.append(str(subdirpath))
	
	filelistnew = filenewname(filelist, fixtype, fixval)
		
	subdirlistnew = subdirnewname(subdirlist, fixtype, fixval)
	
	# rename filelist to filelistnew
	print "\nFiles :"
	for i in range(len(filelist)):
		print "\nold name = " + filelist[i]
		print "new name = " + filelistnew[i]
		os.rename(filelist[i], filelistnew[i])
	
	# rename subdirlist to subdirlistnew proceeding from deepest subdir to shallowest subdir
	print "\nSub-Directories :"
	subdirlist.reverse()
	subdirlistnew.reverse()
	for i in range(len(subdirlist)):
		print "\nold name = " + subdirlist[i]
		print "new name = " + subdirlistnew[i]
		os.rename(subdirlist[i], subdirlistnew[i])
		
def validate(argv):
	folder = argv[1]
	fixtype = argv[2]
	fixval = argv[3]
	filterval = ''
	if len(argv) > 4:
		filterval = sys.argv[4]
	
	if folder == '' or fixtype == '' or fixval == '':
		print "\nUsage : <pathto>/massrename.py <folder> <--prefix OR --postfix OR --prechop OR postchop> <prefix/postfix value in double quotes OR chop value (integer)> <filename_filter (optional)>"
		sys.exit(0)

	temppath = folder
	if not os.path.isabs(temppath):
		temppath = os.path.abspath(str(temppath))
	if os.path.exists(temppath):
		if os.path.isdir(temppath):
			print "path validated.\n"
			folder = temppath
		else:
			print "ERROR !", temppath + "\nis not a directory."
	else:
		print "ERROR !", temppath + "\nis not a correct path."
	
	temp = ['--prefix', '--postfix', '--prechop', '--postchop']
	if not fixtype in temp:
		print "\nUsage : <pathto>/massrename.py <folder> <--prefix OR --postfix OR --prechop OR postchop> <prefix/postfix value in double quotes OR chop value (integer)> <filename_filter (optional)>"
		sys.exit(0)
	
	print "folder = " + folder
	print "foxtype = " + fixtype
	print "fixval = " + str(fixval)
	print "filterval = " + filterval
	
	massrename(folder, fixtype, fixval, filterval)
	
	

if __name__ == "__main__":
	validate(sys.argv)
