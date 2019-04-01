def matrix():
	#for 15 lists each with 10 elements i.e. 15 rows and 10 columns
	w,h=10,15

	matrix=[[0 for x in range(w)] for y in range(h)]

	#initalising 
	matrix[0][0]=1
	print matrix[0][0]

matrix()