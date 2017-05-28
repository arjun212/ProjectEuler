
def main():

	acc = 0
	
	for x in range(1,1000):
		if x % 3 == 0 or x % 5 == 0:
			acc = acc + x

	acc = sum([x for x in range (1000) if x % 3 == 0 or x % 5 == 0])

	print(acc)

if __name__ == '__main__':
	main()