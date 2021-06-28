//Khai bao thu vien
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "fstream"


//---------------------
//Khai bao cau truc, hang so (neu co)
#define MAXSIZE 200
using namespace std;
//Ham struct
typedef struct BigNum{
	int value[100];//chuoi gia tri//
	int sign;//dau//
	int n;//so chu so cua so nguyen//
}BigNum;
//Khai bao ham con - prototype
void menu();
void thucThi();

BigNum sinhBigNum(int sign, int soCS);
BigNum catTrai(BigNum X);
BigNum catPhai(BigNum Y);
BigNum cong2BigNum(BigNum A, BigNum B);
void swapBigNum(BigNum &x, BigNum &y);
BigNum nhanBigNum10Mu(BigNum X,int k);
BigNum Nhan2BignNum(BigNum X, BigNum Y);

void NhapN(int &n);
void Xuat(int a[],int n);

void Try(int Bool[],int a[],int n, int k);

void NhapMN(int &n,int &m);
void xuat(BigNum X);
//int  Distribute(int m,int n);
int DistributeA(int n,int m);
int DistributeB(int n,int m);
int DistributeC(int n,int m);
//Than chuong trinh
void main(){

	menu();
	thucThi();

	getch();
}
//Menu chuong trinh
void menu(){

	printf("\n\n=============Chuong Trinh thuc Thi buoi 6===========");
	printf("\n1.Nhan 2 so nguyen lon dung thuat toan chia de tri");
	printf("\n2.Xuat cac hoan vi day A co n phan tu");
	printf("\n\n0. Thoat chuong trinh: .");
}
void thucThi(){
	int n,V,W,x,m;
	int Bool[MAXSIZE] = { 0 };
	int a[MAXSIZE];
	int chon = -1;
	BigNum X;
	BigNum Y;
	BigNum nhan;
	while (chon!=0)
	{
		printf("\nMoi nhap so can thuc thi: ");
		scanf("%d", &chon);
		switch(chon)
		{
		case 0: exit(1);
			break;
		case 1:
			{printf("Big numm thu nhat: ");
			X=sinhBigNum(-1,2);
			xuat(X);
			printf("\n");
			printf("Big numm thu hai:  ");
			Y=sinhBigNum(1,2);
			xuat(Y);
			printf("\n");
			nhan=Nhan2BignNum(X,Y);				
			printf("Tich cua 2 big num: ");
			if(X.sign==Y.sign)
			{
				nhan.sign=1;
			}
			else
			{
				nhan.sign=-1;
			}
			xuat(nhan);
			printf("\n");
			break;
			}
		case 2:
			{
				NhapN(n);
				Try(Bool,a,n,1);
				break;
			}
		default: printf("Gia tri chon khong phu hop"); 
			break;
		}
	}
}
BigNum sinhBigNum(int sign, int soCS)//sinh giá trị cho random cho BigNum//
{
	BigNum X;
	X.sign=sign;
	X.n=soCS;
	if(soCS==1)
	{
		X.value[0]=rand()%9;
	}
	else
	{
		X.value[0]=rand()%9+1; 
		for(int i=1;i<soCS;i++)
		{
			X.value[i]=rand()%10;
		}
	}	
	return X;
}
void xuat(BigNum X)
{
	if(X.sign==-1)
	{
		printf("-");
	}
	for(int i=0;i<X.n;i++)
	{
		printf("%d",X.value[i]);
	}
}
BigNum catTrai(BigNum X)
{
	BigNum trai;
	trai.n=X.n/2;
	for (int i = 0; i < X.n/2; i++)
	{
		trai.value[i]=X.value[i];
	}
	return trai;
}
BigNum catPhai(BigNum Y)
{
	BigNum phai;
	phai.n=Y.n-(Y.n/2);
	int so=0;
	for (int i = Y.n/2; i < Y.n; i++)
	{
		phai.value[so]=Y.value[i];
		so++;//giá trị vị trí của BigNum Phải//
	}
	return phai;
}
BigNum cong2BigNum(BigNum A, BigNum B)
{
	BigNum tong;
	if(A.n < B.n)
	{
		swapBigNum(A, B);
	}
	tong.n = A.n + 1;
	int soNho = 0;
	int kc = A.n - B.n;
	for(int i = A.n - 1; i >= 0; i--)
	{
		int t = 0;
		if(i - kc < 0)
		{
			t = A.value[i] + soNho;
			soNho = 0;
		}
		else
		{
			t = A.value[i] + B.value[i-kc] + soNho;
			soNho = 0;
		}
		if(t < 10)
		{
			tong.value[i+1] = t;
		}
		else
		{
			tong.value[i+1] = t % 10;
			soNho = t / 10;
		}
	}
	if(soNho == 0)
	{
		for(int i = 0; i < tong.n - 1; i++)
			tong.value[i] = tong.value[i+1];
		tong.n--;
	}
	else
		tong.value[0] = soNho;
	return tong;
}

void swapBigNum(BigNum &x, BigNum &y)
{
	BigNum temp = x;
	x = y;
	y = temp;
}
BigNum nhanBigNum10Mu(BigNum X,int k)
{
	int soCS=X.n;
	X.n=X.n+k;
	for(int i=soCS;i<X.n;i++)
	{
		X.value[i]=0;
	}
	return X;
}
BigNum Nhan2BignNum(BigNum X, BigNum Y)//n là số chữ của bignum A, m là số chữ số của bignum B
{
	BigNum tich;
	tich.sign=X.sign*Y.sign;
	if(X.n==0||Y.n==0)
	{
		tich.n=0;
	}
	else
	{
		if((X.n==1&&X.value[0]==0)||(Y.n==1&&Y.value[0]==0))
		{
			tich.n=1;
			tich.value[0]=0;
		}
		else if(X.n==1&&X.value[0]==1)
		{
			tich=Y;
		}
		else if(Y.n==1&&Y.value[0]==1)
		{
			tich=X;
		}
		else 
		{
			if(X.n==1&&Y.n==1)
			{
				int tichphu=X.value[0]*Y.value[0];
				if(tichphu>9)
				{
					tich.n=2;
					tich.value[0]=tichphu/10;
					tich.value[1]=tichphu%10;
				}
				else
				{
					tich.n=1;
					tich.value[0]=tichphu;
				}
			}
			else
			{
				BigNum A,B,C,D,m1,m2,m3,m4;
				A=catTrai(X);
				B=catPhai(X);
				C=catTrai(Y);
				D=catPhai(Y);
				m1=Nhan2BignNum(A,C);
				m2=Nhan2BignNum(A,D);
				m3=Nhan2BignNum(B,C);
				m4=Nhan2BignNum(B,D);
				m1=nhanBigNum10Mu(m1,(X.n-X.n/2)+(Y.n-Y.n/2));
				m2=nhanBigNum10Mu(m2,X.n-X.n/2);
				m3=nhanBigNum10Mu(m3,Y.n-Y.n/2);
				BigNum tong1=cong2BigNum(m1,m2);
				BigNum tong2=cong2BigNum(m3,m4);
				return cong2BigNum(tong1,tong2);
			}
		}
	}
	return tich;

}
void NhapN(int &n)
{
	printf("Nhap n:");
	scanf("%d", &n);
}
void Xuat(int a[],int n)
{
	for (int i = 1; i <=n ; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Try(int Bool[],int a[],int n, int k)
{
	for (int i = 1; i <=n; i++)
	{
		if (!Bool[i])
		{
			a[k] = i;
			Bool[i]=1;
			if(k==n)
				Xuat(a,n);
			else
				Try(Bool,a,n,k+1);
			Bool[i]=0;
		}
	}
}