ctr=0

def checkMatrix(matrix):
	for i in range(4):
		ctr=0
		for j in range(4):
			if (matrix[i][j] ==1): ctr+=1;
		
		if (ctr!=2):
			return False

	for j in range(4):
		ctr=0
		for i in range(4):
			if (matrix[i][j] ==1):
				ctr+=1;
		
		if (ctr!=2):
			return False

	return True

def find(row,col,matrix):
	global ctr
	if (row>3):
		if (checkMatrix(matrix)):
			print ctr
			ctr+=1
			for i in range(4):
				print matrix[i]
	else:
		matrix2 = matrix

		col2 = col+1
		row2 = row
		if (col2==4):
			row2+=1
			col2=0

		#print row2, col2
		if (row2<4):
			matrix[row2][col2] = 0
			matrix2[row2][col2] = 1
			find(row2,col2,matrix)
			find(row2,col2,matrix2)
		else:
			find(4,0,matrix)



Matrix = [[0 for x in range(4)] for x in range(4)] 

#print Matrix

find(0,0,Matrix)