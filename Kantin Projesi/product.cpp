#include <iostream>
#include <string>
#include <iomanip>
#include "product.h"
using namespace std;
//operator Overloading-------------------------------------------------------------------------------------------------------------
ostream &operator<<(ostream &output,product &urun)
{
    output<<"Urun    ID: "<<urun.geturunid()<<endl
	<<"Urun  Isim: "<<urun.geturunisim()<<endl
	<<"Urun Fiyat: "<<urun.geturunsatisfiyati()<<endl
	<<"Urun  Adet: "<<urun.geturunadet()<<endl;
    return output;
}


product &product::operator-=(int AzaltialcakMiktari)
{
	urunSayisiAzalt(AzaltialcakMiktari);
	return *this;
}

product product::operator--()
{
	urunSayisiAzalt();
	return *this;	
}

product &product::operator+=(int ArtisMiktari)
{
	urunSayisiArttir(ArtisMiktari);
	return *this;
}

product product::operator++()
{
	urunSayisiArttir();
	return *this;	
}	
	
//Yapýcý Fonks-------------------------------------------------------------------------------------------------------------
		product::product(int id,int ti,string isim,float al,float sat,int adet)
		{
			urunduzenle(id,ti,isim,al,sat,adet)	;	
		}
		product::product(string isim,int id,int ti)
		{
			urunduzenle( id, isim, ti);
		}
//Yýkýcý Fonks---------------------------------------------------------------------------------------------------
		product::~product()
		{
			urunduzenle();
		  cout<<urunid<<" idli urun silindi."<<endl;	
		}
		
//Fonks------------------------------------------------------------------------------------------------------
		void product::urunduzenle(int id,int ti,string isim,float al,float sat,int adet)
		{
			seturunid(id);
			
			seturunadet(adet);
			
			settedarikciid(ti);
			
			seturunsatisfiyati(sat);
			
			seturunalisfiyati(al);
			
			seturunisim(isim);
			
		}
		void product::urunduzenle(int id,string isim,int  ti)
		{
			seturunid(id);

			settedarikciid(ti);

			seturunisim(isim);
		}
		void product::urunbilgi()
		{
			if (urunid!=0)
			{
			cout<<"Id:"<< urunid;
			cout<<" Isim:"<< urunisim;
			cout<<" Adet:"<<urunadet<<endl;
			cout<<"Alis Fiyati:"<<urunalisfiyati;
			cout<<" Satis Fiyati:"<<urunsatisfiyati;
			cout<<" Kar:"<<urunsatisfiyati - urunalisfiyati<<endl;
			cout<<endl;
			}
		
		}
		
void product::urunSayisiArttir(int ArtisMiktari)
{
	int Miktar;
	Miktar=geturunadet();
	Miktar+=ArtisMiktari;
	seturunadet(Miktar);
}

void product::urunSayisiAzalt(int AzaltialcakMiktari)
{
	int Miktar;
	Miktar=geturunadet();
	Miktar-=AzaltialcakMiktari;
	seturunadet(Miktar);
}

	
//Sets-----------------------------------------------------------------------------------------
				void 	product::seturunisim(string _urunisim)
		{
			urunisim=_urunisim;
		}
		
		
		void 	product::seturunalisfiyati(float _urunalisfiyati)
		{
				if (_urunalisfiyati>=0)
			{
				urunalisfiyati=_urunalisfiyati;	
			}
			else
			{
				cerr<<"Gecersiz Alis fiyati!"<<endl;	
			}	
		}
		
		
		void 	product::seturunsatisfiyati(float _urunsatisfiyati)
		{
			if (_urunsatisfiyati >= 0)
			{
				urunsatisfiyati=_urunsatisfiyati;	
			}
			else
			{
				cerr<<"Gecersiz Satis fiyati!"<<endl;	
			}	
		}
		
		
		void 	product::settedarikciid(int _tedarikciid)
		{
			if (_tedarikciid<600)
			{	
				tedarikciid=_tedarikciid;	
			}
			else
			{
				cerr<<"Gecersiz tedarikci id!"<<endl;	
			}
		}
		
		void 	product::seturunadet(int _urunadet )
		{
			urunadet=_urunadet;
		}
		
		void 	product::seturunid(int _urunid)
		{
			if (_urunid<600)
			{
				urunid=_urunid;
			}
			else
			{
				cerr<<"Gecersiz id"<<endl;	
			}	
		}
		
//Gets------------------------------------------------------------------------------------------------------------------------
		int 	product::geturunid()const
		{
			return urunid;
		}
		
		int 	product::geturunadet()const
		{
			return urunadet;
		}

		int 	product::gettedarikciid()const
		{
			return tedarikciid;
		}
	
		float 	product::geturunsatisfiyati()const
		{
			return urunsatisfiyati;
		}
	
		float 	product::geturunalisfiyati()const
		{
			return urunalisfiyati;
		}

		string 	product::geturunisim()const
		{
			return urunisim;
		}
		
		


