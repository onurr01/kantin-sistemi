#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <string>
#include "product.h"
#include "Tedarikci.h"
#include "Sepet.h"
using namespace std;
class screen
{
	public:
		static void KarsilamaMesaji();
		
		
		void tedarikciislempaneli();
		int anasayfatercih(int islem );
		void urunislemleripaneli();
		void anasayfa();
		
		void urunekleme();
		void urunbilgileri();
		void urunsil(int ID);
		void urunsil();
		void urunDuzenle(int ID);
		void urunDuzenle();
		void urunList();
		
		void tedarikciBilgileri();
		void tedarikciEkle();
		void tedarikciSil(int ID);
		void tedarikciSil();
		void tedarikciDuzenle(int ID);
		void tedarikciDuzenle();
		
		void siparisTercih();
		void siparisBilgi();
		void siparisTedarik();
		void siparisSatis();
		int siparisHesapla(int);
		void AlBilgi();
		void SatBilgi();
		
		void DosyaUrunEkle();
		void DosyaUrunDuzenle();
		void DosyaTedarikciEkle();
		void DosyaTedarikciDuzenle();
		void DosyaAlSepetEkle();
		void DosyaAlSepetDuzenle();
		void DosyaSatSepetEkle();
		void DosyaSatSepetDuzenle();
		void BaslangicDosyaIslemleri();
		void UrunEkleTutucu(int a);
		int staticUrunEkle();
		void TedarikciEkleTutucu(int a);
		int staticTedarikciEkle();
		void SiparisTedarikTutucu(int a);
		int staticSiparisTedarik();
		void SiparisSatisTutucu(int a);
		int staticSiparisSatis();

	private:
		product urunler[10];
		Tedarikci tedarikciler[10];
		Sepet Al[10];
		Sepet Ver[10];
};

#endif
