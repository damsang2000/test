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
	typedef struct products{
		char ten[50];
		int khoiluong;
		double giatri;
		int soluong;
		int solanchon;
		float dongia;
	}products;
	//Khai bao ham con - prototype
	void menu();
	void thucThi();
	void readFile(products prd[],int &n,int &W);
	void writeFile(products prd[],int n,int tongkhoiluong,int tonggiatri);

	void output(products prd[],int n);
	void ChonNhieuLan(products prd[],int n,int W);
	void Chon1Vat1Lan(products prd[],int n,int W);
	void Chon1VatTheoSolannhatdinh(products prd[],int n,int W);

	void NhapN(int &n);
	void Xuat(int a[],int n);
	void Try(int Bool[],int a[],int n, int k);

	void NhapMN(int &n,int &m);
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
		printf("\n1.Nhap du lieu tu file ");
		printf("\n2.Chon vat voi so luong khong gioi han");
		printf("\n3.Chon 1 vat 1 lan");
		printf ("\n4.Chon 1 vat theo so luong cho truoc");
		printf("\n=====================BAI 3===========================");
		printf("\n5.Nhap N");
		printf("\n6.In hoan vi day A");
		printf("\n=====================BAI 4===========================");
		printf("\n7.Nhap N va M");
		printf("\n8.m>=2n");
		printf("\n9.m = n");
		printf("\n10.m>2n và moi hoc sinh deu co qua");
		printf("\n\n0. Thoat chuong trinh: .");
	}
	void thucThi(){
		int n,V,W,x,m;
		int Bool[MAXSIZE] = { 0 };
		int a[MAXSIZE];
		products prd[MAXSIZE];
		int chon = -1;
		while (chon!=0)
		{
			printf("\nMoi nhap so can thuc thi: ");
			scanf("%d", &chon);
			switch(chon)
			{
			case 0: exit(1);
				break;
			case 1:
				{
					readFile(prd,n,W);
					output(prd,n);
					printf("\nNhap file thanh cong!");
					break;
				}
			case 2:
				{
					readFile(prd,n,W);
					ChonNhieuLan(prd,n,W);
					output(prd,n);
					break;
				}
			case 3:
				{
					readFile(prd,n,W);
					Chon1Vat1Lan(prd,n,W);
					output(prd,n);
					break;
				}
			case 4:
				{
					readFile(prd,n,W);
					Chon1VatTheoSolannhatdinh(prd,n,W);
					output(prd,n);
					break;
				}
			case 5:
				{
					NhapN(n);
					break;
				}
			case 6:
				{
					Try(Bool,a,n,1);
					break;
				}
			case 7:
				{
					NhapMN(n,m);
					break;
				}
			case 8:
				{
					printf("so cach chia thuong=%d",DistributeA(n,m));
					break;
				}
			case 9:
				{
					printf("so cach chia thuong=%d",DistributeB(n,m));
					break;
				}
			case 10:
				{
					printf("so cach chia thuong=%d",DistributeC(n,m));
					break;
				}

			default: printf("Gia tri chon khong phu hop"); 
				break;
			}
		}
	}

//cac Ham
//Ham doc  file
void readFile(products prd[],int &n,int &W)
{
	ifstream in;
	in.open("../Dulieu/Input.txt");
	if (in){
		in>>W;
		in>>n;
		for (int i=0;i<n;i++)
		{
			in>>prd[i].ten;
			in>>prd[i].khoiluong;
			in>>prd[i].giatri;
			in>>prd[i].soluong;
			prd[i].dongia=(float)prd[i].giatri/prd[i].khoiluong;
		}
	}
	in.close();
}

//Ham ghi file
void writeFile(products prd[],int n,int tongkhoiluong,int tonggiatri)
{
	ofstream(out);
	out.open("../Dulieu/Output.txt");
	if (out)
	{
		out<<"Tong khoi luong ba lo co chua duoc: "<<tongkhoiluong<<"\n";
		out<<"Tong gia tri dat duoc:"<<tonggiatri<<"\n";
		out<<"Vat"<<"\t"<<"So luong chon\n";
		for(int i=0;i<n;i++)
		{
			int t=prd[i].solanchon;
			if(t>0)
			{
				out<<prd[i].ten<<"\t";
				out<<t<<"\n";
			}
		}
	}
	out.close();
}

void output(products prd[],int n){
	printf("%-10s %-10s %-15s %-10s %-10s %-10s %-10s\n","Order","Name","Weight","Quanity","Cost","unitPrice");
	for (int i = 0; i < n; i++)
	{
		printf("%-10d  %-15s %-10d %-10d %-10.2f %-10.2f\n",i+1,prd[i].ten,prd[i].khoiluong,prd[i].soluong,prd[i].giatri,prd[i].dongia);
	}
}

//Ham hoan vi
void Hoanvi(products &a,products &b)
{
	products temp=a;
	a=b;
	b=temp;
}
//Ham sap xep vat theo don gia
void Sort_Price(products prd[],int n)
{
	for(int i=0;i<n;i++)
	{
		prd[i].dongia=(float)prd[i].giatri/prd[i].khoiluong;

	}
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (prd[i].dongia<prd[j].dongia)
				Hoanvi(prd[i],prd[j]);
		}
	}
}

//Ham chon vat voi so lan khong gioi han
void ChonNhieuLan(products prd[],int n,int W)
{
	Sort_Price(prd,n);
	float tongkhoiluong=0,tonggiatri=0;
	for (int i=0;i<n;i++)
	{
		int t=0;
		while (prd[i].khoiluong+tongkhoiluong<=W)
		{
			tongkhoiluong=tongkhoiluong+(float)prd[i].khoiluong;
			tonggiatri=tonggiatri+prd[i].giatri;
			t++;
		}
		prd[i].solanchon=t;
		writeFile(prd,n,tongkhoiluong,tonggiatri);
	}

}

//Ham chon 1 vat 1 lan
void Chon1Vat1Lan(products prd[],int n,int W)
{
	Sort_Price(prd,n);
	float tongkhoiluong=0,tonggiatri=0;
	for (int i=0;i<n;i++)
	{
		int t=0;
		if (prd[i].khoiluong+tongkhoiluong<=W)
		{
			tongkhoiluong=tongkhoiluong+(float)prd[i].khoiluong;
			tonggiatri=tonggiatri+prd[i].giatri;
			t++;
		}
		prd[i].solanchon=t;
		writeFile(prd,n,tongkhoiluong,tonggiatri);
	}
}
//Ham chon 1 vat theo so lan nhat dinh
void Chon1VatTheoSolannhatdinh(products prd[],int n,int W)
{
	Sort_Price(prd,n);
	float tongkhoiluong=0,tonggiatri=0;
	for(int i=0;i<n;i++)
	{
		int t=0;
		while (prd[i].khoiluong+tongkhoiluong<=W && prd[i].solanchon<=prd[i].soluong)
		{
			tongkhoiluong+=(float)prd[i].khoiluong;
			tonggiatri+=prd[i].giatri;
			t++;
		}
		prd[i].solanchon=t;
	}
	writeFile(prd,n,tongkhoiluong,tonggiatri);
}
//======bài 3======//
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
//=====Bài 4======//
void NhapMN(int &n,int &m)
{
	printf("Nhap n:");
	scanf("%d",&n);
	printf("Nhap m:");
	scanf("%d",&m);
}
//int  Distribute(int m,int n)
//{
//	if(m==0||n==1)
//		return 1;
//	if(n==0)
//		return 0;
//	if(m==2*n)
//		return 4;
//	else 
//		return Distribute(m-n,n);
//	if(n>m)
//		return Distribute(m,m);
//	if(m>=n)
//		return  Distribute(m,n-1)+Distribute(m-n,n);
//	if(m==n)
//		return Distribute(m,n-1)+1;
//}
int DistributeA(int n,int m)
{
	if(m == 0)
		return 1;
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	if(m == 2*n)
		return 4;
	if(m < n)
		return DistributeA(m,m);
	return  DistributeA(n,m-1)+DistributeA(n,m-n);
}
int DistributeB(int n,int m)
{
	if(m==0)
		return 1;
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else
		return DistributeB(n-1,m)+1;
}
int DistributeC(int n,int m)
{
	if(m ==0)
		return 1;
	if(n==0)
		return 0;
	if(n ==1 )
		return 1;
	if(m == 2*n)
		return 4;
	return DistributeC(n,m-n);
}

