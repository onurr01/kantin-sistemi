#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;
class product
{
	friend class sepet;
	friend ostream &operator<<(ostream &output,product &urun);
	protected:
		int urunid;
		int tedarikciid;
		string urunisim;
		float urunsatisfiyati;
		float urunalisfiyati;
		int urunadet;

		void seturunid(int );
		void seturunadet(int );
		void settedarikciid(int );
		void seturunsatisfiyati(float );
		void seturunalisfiyati(float );
		void seturunisim(string );
		
	public:
		explicit product(int id=0,int ti=0,string isim=" ",float al=0,float sat=0,int adet=0);
		explicit product(string isim,int id,int  ti);
		
		~product();
		
		void urunduzenle(int id,int ti,string isim,float al,float sat,int adet);
		void urunduzenle(int id=0,string isim=" ",int  ti=0);
		void urunbilgi();
		void urunSayisiAzalt(int AzaltialcakMiktari=1);
		void urunSayisiArttir(int ArtisMiktari=1);
		
		
		int geturunadet()const;
		int gettedarikciid()const;
		float geturunsatisfiyati()const;
		float geturunalisfiyati()const;
		int geturunid()const;
		string geturunisim()const;
		
		product &operator-=(int AzaltialcakMiktari);
		product operator--();
		product &operator+=(int ArtisMiktari);
		product operator++();
};
#endif

