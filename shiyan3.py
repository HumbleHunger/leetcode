import re
def lfsr(ai,t):
array_init = ai
array_init_bin = '{:07b}'.format(array_init)
# print(array_init_bin) 调试用
array_new = '0'*len(array_init_bin)
array_new = list(array_new)
for i in range(len(array_init_bin)):
j = i+1
22
if(i == (len(array_init_bin)-1)):
if(len(t) == 2):
array_new[i] = str(int(array_init_bin[t[0]])^int(array_init_bin[t[1]]))
if(len(t) == 3):
array_new[i] = str(int(array_init_bin[t[0]])^int(array_init_bin[t[1]])^int(array_init_bin[t[2]]))
else:
array_new[i] = str(array_init_bin[j])
array_new = ''.join(array_new)
return int(array_new,2),array_init_bin
def LFSR():
choice = input("Please input 1 for p(x) or 2 for q(x):")
if choice == "1":
init = int(input("输入初始状态数字(十进制)(周期 127):"))
tap = [0,6]
length = int(input("输入密钥流长度:"))
out = []
for i in range(length):
init,bine = lfsr(init,tap)
out.append(bine[0])
out = ''.join(out)
print(out)
if choice == "2":
init = int(input("输入初始状态数字(十进制)(周期 21)(输入最佳 21):"))
tap = [1,3,6]
out = []
length = int(input("输入密钥流长度:"))
for i in range(length):
init,bine = lfsr(init,tap)
out.append(bine[0])
out = ''.join(out)
print(out)
return out
while True:
choice = input("Please input E for encryption or D for decryption:")
L = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'] #把英文字母和十进制数字
的对应关系存进一个数组中
if choice == "E":
pattern = re.compile('.{5}')
x = input("请输入加密数据:")
s = list(x)
23
p = []
cipher = []
cipher_list = []
for k in s:
k_new = '{:05b}'.format(L.index(k))
p.append(k_new)
str1 ="".join(p)
print("加密数据长度:",len(str1))
key = LFSR()
# print(str1) 调试用
for i in range(len(str1)):
cipher_list.append(str(int(str1[i])^int(key[i])))
# print(''.join(cipher_list)) 调试用
cipher_new = pattern.findall(''.join(cipher_list))
for j in range(len(cipher_new)):
cipher.append(L[int(cipher_new[j],2)])
print(''.join(cipher))
if choice == "D":
pattern = re.compile('.{5}')
x = input("请输入解密数据:")
s = list(x)
p = []
clear = []
clear_list = []
for k in s:
k_new = '{:05b}'.format(L.index(k))
p.append(k_new)
str1 ="".join(p)
print("解密密数据长度:",len(str1))
key = LFSR()
# print(str1) 调试用
for i in range(len(str1)):
clear_list.append(str(int(str1[i])^int(key[i])))
# print(''.join(clear_list)) 调试用
clear_new = pattern.findall(''.join(clear_list))
for j in range(len(clear_new)):
clear.append(L[int(clear_new[j],2)])
print(''.join(clear))