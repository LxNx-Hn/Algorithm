array=[9,8,7,6,5,4,3,2,1,0]

def selection_sort(array):
	n = len(array)
	for i in range(n):
		min_index = i
		for j in range(i + 1, n):
			if array[j] < array[min_index]:
				min_index = j
		array[i], array[min_index] =  array[min_index], array[i]
		print(array[:i+1])
		
print("before: ",array)
selection_sort(array)
print("after:", array)