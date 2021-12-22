import math
import random

def judge_prime(p):
#素数的判断
	if p <= 1:
		return False
	i = 2
	while i * i <= p
		if p % i == 0:
			return False
		i += 1
	return True

def get_generator(p):
#得到所有的原根
	a = 2
	list = []
	while a < p:
		flag = 1
		while flag != p:
			if (a ** flag) % p == 1:
				break
			flag += 1
		if flag == (p - 1):
			list.append(a)
		a += 1
	return list

#A， B 得到各自的计算数
def get_calculation(p, a, X):
	Y = (a ** X) % p
	return Y

#A， B 得到交换计算数后的密钥
def get_key(X, Y, p):
	key = (Y ** X) % p
	return key

if __name__ == "__main__":
	#得到规定的素数
	flag = False
	while flag == False:
		print('Please input a prime: ', end = '')
		p = input()
		p = int(p)
		flag = judge_prime(p)
	print(str(p) + ' is a prime! ')

	#得到素数的一个原根
	list = get_generator(p)
	i = input("请选择"+str(p)+"的第几个原根： ")
	print(str(p) + ' 的一个原根为： ', end = '')
	i = int(i)
	print(list[i])

	#得到 A 的私钥
	XA = input("请输入 A 的私钥(学号前 4 位):")
	XA = int(XA)

	print('A 的私钥为： %d' % XA)
	
	#得到 B 的私钥
	XB = input("请输入 B 的私钥(学号后 4 位):")
	XB = int(XB)
	print('B 的私钥为： %d' % XB)
	
	#得待 A 的计算数
	YA = get_calculation(p, int(list[-1]), XA)
	print('A 的计算数为： %d' % YA)
	
	#得到 B 的计算数
	YB = get_calculation(p, int(list[-1]), XB)
	print('B 的计算数为： %d' % YB)
	
	#交换后 A 的密钥
	key_A = get_key(XA, YB, p)
	print('A 的生成密钥为： %d' % key_A)

	#交换后 B 的密钥
	key_B = get_key(XB, YA, p)
	print('B 的生成密钥为： %d' % key_B)
	print('验证结果： ')
	
	print(key_A == key_B)