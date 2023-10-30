#ifndef SEPET_H
#define SEPET_H
#include <iostream>
#include <string>
#include "product.h"


using namespace std;
class Sepet 
{
	public:
		~Sepet();
		explicit Sepet();
		
		
		
		void setmaliyet(float );
		void setMusteriAdi(string );
		void setadet(int );
		void setId(int );
		
		int getAdet()const;
		string getAd()const;
		int getId();
		float getmaliyet()const;
		
		void Al(string _MusteriAdi,int UrunId,int Adet,float _maliyet);
		void Ver(int Adet ,int UrunId ,float _maliyet);
		void SiparisVer(int Adet,int UrunId, product& Urun);
		void SiparisAl(string _MusteriAdi,int UrunId,int Adet,product& Urun);
		void Sil();
	private:
		string MusteriAdi;
		int adet;
		int ID;
		product Urun;
		float maliyet;
};






#endif
