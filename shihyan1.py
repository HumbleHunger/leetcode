#加密密钥矩阵
K_LIST = [[8, 6, 9, 5],
					[6, 9, 5, 10],
					[5, 8, 4, 9],
					[10, 6, 11, 4]]
#解密密钥矩阵
K_INV_LIST = [[23,2,2,25],
							[20,11,20,2],
							[5,18,6,22],
							[1,1,25,25]]
#26 个字母列表：方便找出对应下标
ALPHABET = ["A","B","C","D","E","F","G",
						"H","I","J","K","L","M","N",
						"O","P","Q","R","S","T","U",
						"V","W","X","Y","Z"]
def get_index(alphabet):
	"""
	获得字母在字母表中的对应位置(下标)
	:param alphabet: 明文字母
	:return: 下标
	"""
	alphabet = alphabet.upper()
	return ALPHABET.index(alphabet)
def deal_index(list_index):
	"""
	加密处理 C＝KP
	:param list_index: 每一组明文字母的下标
	:return: 加密后密文的下标
	"""
	deal_list = [0,0,0,0]
	for i in range(len(K_LIST)):
		for j in range(len(K_LIST[i])):
			deal_list[i] += list_index[j] * K_LIST[i][j]
		deal_list[i] = (deal_list[i] % 26)
	return deal_list
def dec_index(list_index):
	"""
	解密处理 C＝K_INV*P
	:param list_index: 每一组明文字母的下标
	:return: 加密后密文的下标
	"""
	dec_list = [0,0,0,0]
	for i in range(len(K_INV_LIST)):
		for j in range(len(K_INV_LIST[i])):
			dec_list[i] += list_index[j] * K_INV_LIST[i][j]
		dec_list[i] = (dec_list[i] % 26)
	return dec_list
def get_alphabet(deal_list):
	"""
	通过字母的下标获得对应字母
	:param deal_list: 下标的列表
	:return: 返回密文字母列表
	"""
	cipher_list = []
	for i in deal_list:
		cipher_list.append(ALPHABET[i])
	return cipher_list
def encryption(clear_text):
	"""
	加密时调用的函数
	:param clear_text:输入的明文
	:return: 加密后的密文
	"""
	list_clear_text = list(clear_text.strip().replace(" ", ""))
	print(list_clear_text)
	#明文每 3 个一组，不足则补充字母 Z
	cipher_list = [] #用来存入密文
	#明文每 4 个为一组，找出每组在字母表中的位置(用一个列表来保存)
	x = get_index(list_clear_text[0])
	y = get_index(list_clear_text[1])
	z = get_index(list_clear_text[2])
	a = get_index(list_clear_text[3])
	list_index = [x, y, z, a]
	print(list_index)
		#调用 deal_inde 函数进行加密 矩阵 K 与明文 P 运算得到密文 C，即 C＝KP
	deal_list = deal_index(list_index)
	part_cipher_list = get_alphabet(deal_list) #返回一组密文
	cipher_list.extend(part_cipher_list)
	print(cipher_list)
	return "".join(cipher_list)
def decryption(cipher_text):
	list_cipher_text = list(cipher_text.strip().replace(" ", ""))
	print(list_cipher_text)
	#明文每 3 个一组，不足则补充字母 Z
	cipher_list = [] #用来存入密文
	#明文每 4 个为一组，找出每组在字母表中的位置(用一个列表来保存)
	x = get_index(list_cipher_text[3])
	y = get_index(list_cipher_text[2])
	z = get_index(list_cipher_text[1])
	a = get_index(list_cipher_text[0])
	list_index = [x, y, z, a]
	print(list_index)
	#调用 deal_inde 函数进行加密 矩阵 K 与明文 P 运算得到密文 C，即 C＝KP
	dec_list = dec_index(list_index)
	part_cipher_list = get_alphabet(dec_list) #返回一组密文
	cipher_list.extend(part_cipher_list)
	print(cipher_list)
	return "".join(cipher_list)
if __name__ == "__main__":
	while True:
		choice = input("Please input E for encryption or D for decryption:")
		if choice == "E":
			clear_text = input("请输入明文:")
			print("加密成功！密文:%s" % encryption(clear_text))
		if choice == "D":
			cipher_text = input("请输入密文:")
			print("解密成功！密文:%s" % encryption(cipher_text))