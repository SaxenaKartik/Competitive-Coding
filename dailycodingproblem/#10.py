import time,datetime

def some() -> int:
	"""Some function to schedule
		
	Example:
		>>> some()
		5

	Returns:
		int: 5 on each call

	"""
	return 5

def schedule(func, msec:int)->None:
	"""Function to execute the scheduling
	

	Example: 
		>>> schedule(f1,10)
		Call to function f1 at timestamp T
		Call to function f1 at timestamp T+10ms
		Call to function f1 at timestamp T+20ms	

	Args:
		func (str): The function to schedule/call
		msec (int): The time interval (in milliseconds) between successive calls

	Returns: 
		None
	
	Note:
		Prints the calls to the function after successive 

	"""
	while(True):
		print("Call to function "+str(func)+" at timestamp" + str(datetime.datetime.now()))
		eval(func)()
		""" eval converts string to function name """
		time.sleep(msec/1000)

def main():
	"""Main function to recieve input from the user
		
	Example:  For running the program,

			$ python3 #10.py
			f1 10

	Attributes: 
		f(function): Module level variable f to take input the function name
		n(int): Module level variable n to input the milliseconds
		
	"""
	f,n = input().split()
	n = int(n)
	schedule(f,n)



if __name__ == '__main__':

	main()
