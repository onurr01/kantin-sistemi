#include <iostream>
#include <string>
#include "Sepet.h"
#include "product.h"
using namespace std;

Sepet::Sepet()
{
	setMusteriAdi(" ");
	setadet(0);
	setId(0);	
}

Sepet::~Sepet()
{
	setMusteriAdi(" ");
	setadet(0);
	setId(0);
	cout<<"Siparsi Iptal Edildi!"<<endl;
}


//--------------------------Set Fonks-------------------------------------------------

void Sepet::setMusteriAdi(string Ad)
{
	MusteriAdi=Ad;
}

void Sepet::setadet(int Adet)
{
	adet=Adet;
}

void Sepet::setId(int Id )
{
	ID=Id;
}

		
		
void Sepet::setmaliyet(float fiyat)
{
	maliyet=fiyat;
}
//--------------------------Get Fonks-------------------------------------------------

float Sepet::getmaliyet()const
{
	return maliyet;
}

int Sepet::getAdet()const
{
	return adet;
}
string Sepet::getAd()const
{
	return MusteriAdi;
}

int Sepet::getId()
{
	return ID;
}

//--------------------------Fonks-------------------------------------------------

void Sepet::Al(string _MusteriAdi,int UrunId,int Adet,float _maliyet)
{
	setmaliyet(_maliyet);
	setMusteriAdi(_MusteriAdi);
	setadet(Adet);
	setId(UrunId);
}

void Sepet::Ver(int Adet,int UrunId,float _maliyet)
{
	setmaliyet(_maliyet);
	setadet(Adet);
	setId(UrunId);
	
}

void Sepet::SiparisVer(int Adet,int UrunId,product& Urun)
{
	float maliyet;
	int fiyat,tercih;
	setadet(Adet);
	setId(UrunId);
	
	maliyet=Urun.geturunalisfiyati()*Adet;
	setmaliyet(maliyet);

	cout<<"Toplam Tutar: "<<maliyet<<endl;
	cout<<"Onay Icin [1]"<<endl;
	cout<<"Iptal Icin [0]"<<endl;
	cout<<"Secenekleri Tuslayiniz:";
	cin>>tercih;
	switch(tercih)
	{
		case 1:
			cout<<"Satis Onaylandi"<<endl;
			Urun+=Adet;
		break;
		default :
			Sil();	
		break;
		case 2:
			Sil();
			cout<<"Siparsi Iptal Edildi!"<<endl;
		break;
	}
		
			
}

void Sepet::SiparisAl(string _MusteriAdi,int UrunId,int Adet,product& Urun)
{
	setId(UrunId);
	float maliyet;
	int fiyat,tercih;
	setMusteriAdi(_MusteriAdi);
	setadet(Adet);
	maliyet=Urun.geturunsatisfiyati()*Adet;
	setmaliyet(maliyet);
	if(Adet<Urun.geturunadet())
	{
		
		cout<<"Toplam Tutar: "<<maliyet<<endl;
		cout<<"Onay Icin [1]"<<endl;
		cout<<"Iptal Icin [0]"<<endl;
		cout<<"Secenekleri Tuslayiniz:";
		cin>>tercih;
		switch(tercih)
		{
			case 1:
				cout<<"Satis Onaylandi"<<endl;
				Urun-=Adet;
			break;
			default :
				cout<<"Gecersiz Deger:"<<endl;
				Sil();
					
			break;
			case 2:
				Sil();
			break;
		}
		
	}
	
}
void Sepet::Sil()
{
	setMusteriAdi(" ");
	setadet(0);
	setId(0);
	cout<<"Siparsi Iptal Edildi!"<<endl;
}

