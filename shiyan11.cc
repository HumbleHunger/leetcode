#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int affine(string Inform)
{
    int n = 36;
    string c;
    int buff[32], len = 0, key1 = 0, key2 = 0;
    cout << "输入key1:";
    cin >> key1;
    cout << "输入key2:";
    cin >> key2;
    //把明文转化成10进制整数,0-9,a-z分别代表十进制0-36
    for (int i = 0; Inform[i] != '\0'; i++)
    {
        //字母转10进制整数
        if (Inform[i] > '9')
            buff[i] = Inform[i] - 87;
        else
            buff[i] = Inform[i] - 48;//0ASCII为48
        len++;
    }
    //加密运算,C=k1*m+k2 mod n;
    for (int i = 0; i < len; i++)
    {
        buff[i] = (buff[i] * key1 + key2) % n;
    }
    //把数字对应为密文空间内的字符
    for (int i = 0; i < len; i++)
    {
        if (buff[i] < 10)
            Inform[i] = buff[i] + 48;
        else
            Inform[i] = buff[i] + 87;
        
    }
    cout << "密文：" << endl;
    for (int i = 0; i<len; i++)
    {
        cout << Inform[i];
    }
    cout << endl;
    return 0;
}

int main()
{
	string s;
	cout << "输入明文" << endl;
	cin >> s;
	affine(s);
	return 0;
}