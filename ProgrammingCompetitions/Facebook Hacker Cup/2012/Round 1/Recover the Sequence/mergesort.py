def merge_sort(arr):
	n = len(arr)
	if n <= 1:
		return arr

	# arr is indexed 0 through n-1, inclusive
	mid = int(n/2)

	first_half = merge_sort(arr[0:mid])
	second_half = merge_sort(arr[mid:n])
	
	return merge(first_half, second_half)

def merge(arr1, arr2):
	print "merging", arr1, "and", arr2
	
	result = []
	
	while len(arr1) > 0 and len(arr2) > 0:
		if arr1[0] < arr2[0]:
			print '1', "\t", arr1[0], "<", arr2[0] # for debugging
			result.append(arr1[0])
			arr1.remove(arr1[0])
		else:
			print '2', "\t", arr1[0], ">", arr2[0] # for debugging
			result.append(arr2[0])
			arr2.remove(arr2[0])
	    
	result.extend(arr1)
	result.extend(arr2)
	
	return result

a1 = [2, 4, 3, 1]

print merge_sort(a1);


