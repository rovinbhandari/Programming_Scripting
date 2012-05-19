import os
import sys
import string
import hashlib

def hashit(fp, filesize):
	chunksize = 128 * 64
	bytecount = 0
	m = hashlib.md5()
	while bytecount != filesize:
		if (filesize - bytecount) < chunksize:
			chunksize = filesize - bytecount
		chunkdata = fp.read(chunksize)
		m.update(chunkdata)
		bytecount += chunksize
	filehash = str(m.hexdigest())
	return filehash
	
	
path = str(sys.argv[1])
f = open(path, 'rb')
fsize = os.path.getsize(path)
print hashit(f, fsize)
