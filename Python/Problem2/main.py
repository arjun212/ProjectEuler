
def isEven(i):
	return i % 2 == 0

def lessFour(i):
	return i < 4000000

def fibonacci(i):
	if i  == 1:
		return i
	if i == 2:
		return i
	return fibonacci(i -1) + fibonacci(i-2)


def main():
	i = 1
	acc = 0
	fibValue = fibonacci(i)

	while lessFour(fibValue):
		if isEven(fibValue):
			acc += fibValue
		i += 1
		fibValue = fibonacci(i)


	print(acc)



if __name__ == '__main__':
	main()