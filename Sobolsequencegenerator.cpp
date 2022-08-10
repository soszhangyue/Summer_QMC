#include <iostream>
using namespace std;

int Binaryint(int n)
{
	int s;
	int i = 0;
	int bin = 0;
	while (n != 0)
	{
		s = n % 2;
		n = n / 2;
		bin = bin + s * pow(10, i);
		i++;
	}
	return bin;
}

int Decimalint(int n)
{
	int number,temp;
	int ans = 0;
	number = log10(n) + 1;
	for (int i = 0; i < number; i++)
	{
		temp = n % 10;
		ans = ans + pow(2, i)*temp;
		n = n / 10;
	}
	return ans;
}

//���ڼ��㲻��1��ʮ����ת������
double Binarydouble(double m)
{
	double bin = 0;
	int i = -1;
	while (m != 0)
	{
		m = m * 2;
		if (m >= 1)
		{
			double temp = 1;
			for (int j = 1; j <= -i; j++)
			{
				temp = temp / 10;
			}
			bin = bin + temp;
			m = m - 1;
		}
		i--;
	}
	return bin;
}

double Decimaldouble(double m,int number)
{
	double ans = 0;
	double temp;
	for (int i = 1; i <= number; i++)
	{
		temp = m * pow(10, i);
		temp = (int)temp % 10;
		ans = ans + pow(2, -i)*temp;
	}
	return ans;
}

int main(void) 
{
	//����һ��һά������
	int m[1000];
	int a[1000];
	double v[1000];
	int d=3;//����ʽ�Ĵ���
	//���Ǿ���x^3+x+1Ϊ��,֮����Ե���Ϊ����
	a[0] = 1;
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	//�����ʼֵ��֮����Ե���Ϊ����
	m[1] = 1;
	m[2] = 3;
	m[3] = 7;
	for (int i = d+1; i < 1000; i = i++)
	{
		int counter = 1;
		int test;
		m[i] = 2 * a[1] * m[i - counter];
		while (counter < d)
		{
			counter++;
			test = pow(2, counter) * a[counter] * m[i - counter];
			m[i] = m[i] ^ test;
		}
		m[i] = m[i] ^ m[i - d];  
	}

	for (int j = 1; j < 1000; j = j++)
	{
		v[j] = m[j] / pow(2, j);
	}

	for (int n = 1; n < 1000; n = n++)
	{
		int number;
		int temp;
		double result;
		int chn;
		chn = Binaryint(n);
		number = log10(chn) + 1;
		int ans=0;
		for (int i = 1; i <= number; i++)
		{
			temp = chn / pow(10, i - 1);
		    temp = temp % 10;//����ȡ��n�ڶ����Ʊ���еĵ�nλ
			temp = temp * Binarydouble(v[i]) * pow(10, i);//v[i]��iλС������ʱtempû��С��
			ans = ans * 10; 
			ans = Decimalint(ans);
			temp = Decimalint(temp);
			ans = ans ^ temp;
			ans = Binaryint(ans);
		}
		result = ans / pow(10, number);
		result = Decimaldouble(result, number);
		cout << result << endl;
	}
	
	return 0;
}
