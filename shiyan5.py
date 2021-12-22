import math
def Fast_mode_power(a,n,m):
	x = 1
	for i in range(n):
		x = (x*a)%m
	print("x={}".format(x))
	return x
def ModReverse(a,m):
	u1,u2,u3 = 1,0,a
	v1,v2,v3 = 0,1,m
	while v3!=0:
		q = u3//v3
		v1,v2,v3,u1,u2,u3 = (u1-q*v1),(u2-q*v2),(u3-q*v3),v1,v2,v3
	return u1%m
def main():
	print("********************")
	print("** 1. 模幂 **")
	print("** 2. 求逆 **")
	print("** 请选择操作: **")
	print("********************")
	choice = input()
	if choice == '1':
		print("a^n = x (mod m)")
		a = int(input("请输入正整数 a "))
		n = int(input("请输入 n "))
		m = int(input("请输入 m "))
		x = Fast_mode_power(a,n,m)
		print(x)
	elif choice == '2':
		print("a * b = 1 (mod m)")
		a = int(input("请输入正整数 a "))
		m = int(input("请输入 m "))
		b = ModReverse(a,m)
		print(b)
	else:
		print("输入错误!")
	return 0