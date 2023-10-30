#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <iomanip>
#include "tercih.h"

using namespace std;

//----------------------------------------Ansayfa  Ekraný--------------------------------------------------------------------------------------------------------------------------------------------------

void screen::KarsilamaMesaji()
{
    cout<<"    Kantin Yonetim Sistemine"<<endl;
    cout<<"         Hos Geldiniz.."<< endl;
}

void screen::anasayfa()
{
	BaslangicDosyaIslemleri();
    int islem;
	KarsilamaMesaji();
    cout<<"     _____________________"<<endl;
    cout<<"    |    TERCIH  PANELI   |"<<endl;
    cout<<"    |1.Urun Islemleri     |"<<endl;
    cout<<"    |2.Tedarikci Islemleri|"<<endl;
    cout<<"    |3.Siparisler         |"<<endl;
    cout<<"    |4.Cikis              |"<<endl;
    cout<<"    ---------------------- "<<endl;
    cout<<"    Lutfen islem numarasi giriniz:";
    cin>> islem;
	anasayfatercih(islem);
} 

int screen::anasayfatercih(int islem )
{
    switch(islem){
        case 1:
        urunislemleripaneli();
        break;
        case 2:
        tedarikciislempaneli();
        break;
        case 3:
        siparisTercih();
        break;
        case 4:
        return 0;
        break;
        default:
        anasayfa();
        break;

    }
}

//----------------------------------------Urun  Ekraný--------------------------------------------------------------------------------------------------------------------------------------------------
void screen::urunislemleripaneli()
{
    // urun ekle, ??kart duzenle 
    int islem;
    cout<<"        Urun  Islemleri  "<<endl;
    cout<<"     _____________________"<<endl;
    cout<<"    |    TERCIH  PANELI   |"<<endl;
    cout<<"    |1.Urun Ekleme        |"<<endl;
    cout<<"    |2.Urun Silme         |"<<endl;
    cout<<"    |3.Urun Duzenleme     |"<<endl;
    cout<<"    |4.Urun Listesi       |"<<endl;
    cout<<"    |5.Geri Don           |"<<endl;
    cout<<"    ---------------------- "<<endl;
    cout<<"    Lutfen islem numarasi giriniz:";
    cin>> islem;
    
    switch (islem)
	{
        case 1:
        	urunekleme();
        break;
        case 2:
        	urunsil();
        break;
        case 3:
        	urunDuzenle();
        break;
        case 4:
        	urunbilgileri();
        break;
        case 5:
        anasayfa();
        break;

    }

}

//----------------------------------------Tedarikci  Ekraný--------------------------------------------------------------------------------------------------------------------------------------------------

void screen::tedarikciislempaneli(){
    //tedarik?i ekle , sil ,d?zenle
    int islem;
    cout<<"      Tedarikci  Islemleri  "<<endl;
    cout<<"     _____________________"<<endl;
    cout<<"    |    TERCIH  PANELI   |"<<endl;
    cout<<"    |1.Tedarikci Ekle     |"<<endl;
    cout<<"    |2.Tedarikci Sil      |"<<endl;
    cout<<"    |3.Tedarikci Duzenle  |"<<endl;
    cout<<"    |4.Tedarikci Listesi  |"<<endl;
    cout<<"    |5.Geri Don           |"<<endl;
    cout<<"    ---------------------- "<<endl;
    cout<<"    Lutfen islem numarasi giriniz:";
    cin>> islem;
    switch (islem){
        case 1:
        	tedarikciEkle();
        break;
        case 2:
        	tedarikciSil();
        break;
        case 3:
        	tedarikciDuzenle();
        break;
        case 4:
        	tedarikciBilgileri();
        	anasayfa();
        break;
        case 5:
        anasayfa();
        break;
    }
}

//----------------------------------------Siparis Ekran----------------------------------------------------------------------------------------------------------------------------------------------------------

void screen::siparisTercih()
{

	int islem;
    cout<<"      Siparis  Islemleri  "<<endl;
    cout<<"     _____________________"<<endl;
    cout<<"    |    TERCIH  PANELI   |"<<endl;
    cout<<"    |1.Siparis Ver        |"<<endl;
    cout<<"    |2.Musteri Siparisleri|"<<endl;
    cout<<"    |3.Siparis Listesi    |"<<endl;
    cout<<"    |4.Geri Don           |"<<endl;
    cout<<"    ---------------------- "<<endl;
    cout<<"    Lutfen islem numarasi giriniz:";
    cin>> islem;
    
    switch (islem)
	{
        case 1:
        	siparisTedarik();
        break;
        case 2:
        	siparisSatis();
        break;
        case 3:
        	siparisBilgi();
        break;
        case 4:
        anasayfa();
        break;
        default:
        	cout<<"Yanlis Tuslama!"<<endl;
        	siparisTercih();
        break;

    }


}

//----------------------------------------Urun Fonks--------------------------------------------------------------------------------------------------------------------------------------------------------------
void screen::urunekleme()
{
	system("cls");
	tedarikciBilgileri();
	static int sayac =1;
	sayac=staticUrunEkle();
	int ti,adet;
	float al,sat;
	string isim;		
	cout<<"Urun Isim Olusturunuz:";
	cin>>isim;
		
	cout<<"Tedarikci Id:";
	cin>>ti;
		if (tedarikciler[ti].getTedarikciMarka()=="null" || ti==0)
	{
		cout<<endl<<endl;
		cerr<<"Gecerli Tedarikci Bulunamadi"<<endl;
		cout<<endl<<endl<<endl<<endl;
		urunislemleripaneli();
			
	}
	else 
	{
	cout<<"Urun Alis Fiyati Giriniz:";
	cin>>al;
	cout<<"Urun Satis Fiyati Giriniz:";
	cin>>sat;
	cout<<"Urun Adet Giriniz:";
	cin>>adet;
	urunler[sayac].urunduzenle(sayac,ti,isim,al,sat,adet);
	cout<<"Urun Ekleme Basarili!!"<<endl;
	sayac++;
	UrunEkleTutucu(sayac);
	DosyaUrunEkle();
	anasayfa();	
	}
}

void screen::urunList()
{
	int sayac;
	for (sayac=1;sayac<10;sayac++)
	{
		urunler[sayac].urunbilgi();
	}
}
	
void screen::urunbilgileri()
{
	system("cls");

	urunList();
	anasayfa();
}

void screen::urunsil()
{
	system("cls");
	urunList();
	int id;
	cout<<"Silinecek Urun ID:";
	cin>>id;
	cout<<endl;
	urunsil(id);
		
}

void screen::urunsil(int ID)
{
	urunler[ID].~product();
	DosyaUrunEkle();
	anasayfa();
}

void screen::urunDuzenle()
{
	system("cls");
	urunList();
	int id;
	cout<<"Duzenlenecek Urun ID:";
	cin>>id;
	cout<<endl;
	urunDuzenle(id);
	
}		

void screen::urunDuzenle(int ID)
{

	int ti,adet;
	float al,sat;
	string isim;		
	cout<<"Yeni Urun Isim:";
	cin>>isim;
		
	cout<<"Yeni Tedarikci Id:";
	cin>>ti;
	if (tedarikciler[ti].getTedarikciMarka()=="null" || ti==0 )
	{
		cout<<endl<<endl;
		cerr<<"Gecerli Tedarikci Bulunamadi"<<endl;
		cout<<endl<<endl<<endl<<endl;
		urunDuzenle(ID);	
	}
	else
	{
		cout<<"Yeni Alis Fiyati:";
		cin>>al;
		cout<<"Yeni Satis Fiyati:";
		cin>>sat;
		cout<<"Yeni Adet:";
		cin>>adet;
		urunler[ID].urunduzenle(ID,ti,isim,al,sat,adet);
		DosyaUrunEkle();
		cout<<"Urun Guncelle Basarili!!"<<endl;

	anasayfa();	
	}	
	
}


//----------------------------------------Tedarikci Fonks----------------------------------------------------------------------------------------------------------------------------------------------------------
void screen::tedarikciBilgileri()
{
	int sayac;
	for (sayac=1;sayac<10;sayac++)
	{
		tedarikciler[sayac].TedarikciBilgi();
	}
	
}
	
void screen::tedarikciEkle()
{
	system("cls");

	static int sayac = 1;
	sayac=staticTedarikciEkle();
	
	string isim,tin;
		
	cout<<"Tedarikci Marka'nin Ismi:";
	cin>>isim;

	cout<<"Tedarikci Iletisim No:";
	cin>>tin;

	tedarikciler[sayac].TedarikciDuzenle(sayac,isim,tin);
	DosyaTedarikciEkle();
	cout<<"Tedarikci Ekleme Basarili!!"<<endl;
	sayac++;
	TedarikciEkleTutucu(sayac);
	
	anasayfa();	
}
	
void screen::tedarikciSil()
{
	system("cls");
	tedarikciBilgileri();
	int id;
	cout<<"Silinecek Tedarikci ID:";
	cin>>id;
	cout<<endl;
	tedarikciSil(id);
	anasayfa();
}
	
void screen::tedarikciSil(int ID)
{
	tedarikciler[ID].~Tedarikci();
	tedarikciler[ID].TedarikciDuzenle();
	DosyaTedarikciEkle();
}
	
void screen::tedarikciDuzenle()
{
	system("cls");
	tedarikciBilgileri();
	
	int id;
	cout<<"Duzenlenecek Tedarikci ID:";
	cin>>id;
	cout<<endl;
	tedarikciDuzenle(id);
}
	
void screen::tedarikciDuzenle(int ID)
{
	string isim,tin;		
	cout<<"Yeni Tedarikci Marka:";
	cin>>isim;
	cout<<endl;	
	cout<<"Yeni Tedarikci Iletisim No:";
	cin>>tin;
	cout<<endl;
	tedarikciler[ID].TedarikciDuzenle(ID,isim,tin);
	DosyaTedarikciEkle();
	cout<<"Tedarikci Guncelleme Basarili!!"<<endl;
	anasayfa();	

}

//----------------------------------------Siparis Fonks----------------------------------------------------------------------------------------------------------------------------------------------------------

void screen::siparisTedarik()
{
	system("cls");
	static int i=1;
	i=staticSiparisTedarik();
	int id,ilkdeger;
	int adet,tercih;
	cout<<"Mevcut Urunler"<<endl;
	AlBilgi();
	cout<<endl<<endl;
	cout<<"Urun ID:";
	cin>>id;
	if(urunler[id].geturunid()==0 || urunler[id].geturunisim()==" ")
	{
		cout<<"Urun Bulunamadi!";
		siparisTercih();
	}
	else
	{
		cout<<"Siparis Adeti:";
		cin>>adet;
		Ver[i].SiparisVer(adet,id,urunler[id]);
		DosyaUrunEkle();
		DosyaSatSepetEkle();
		++i;
		SiparisTedarikTutucu(i);
		siparisTercih();
	}

	
}

void screen::siparisSatis()
{
	system("cls");
	static int i=1;
	i=staticSiparisSatis();
	string musteriAdi;
	int id,ilkdeger;
	int adet,tercih;
	cout<<"Mevcut Urunler"<<endl;
	SatBilgi();
	cout<<endl<<endl;
	cout<<"Musteri Ismi: ";
	cin>>musteriAdi;
	cout<<"Urun ID:";
	cin>>id;
	if(urunler[id].geturunid()==0 || urunler[id].geturunisim()==" ")
	{
		cout<<"Urun Bulunamadi!";
		siparisTercih();
	}
	else 
	{
		cout<<"Siparis Adeti:";
		cin>>adet;
		Al[i].SiparisAl(musteriAdi,id,adet,urunler[id]);
		DosyaUrunEkle();
		DosyaAlSepetEkle();
		++i;
		SiparisSatisTutucu(i);
		siparisTercih();
	}
	
}
	
void screen::siparisBilgi()
{
	system("cls");
	int id,index;
	cout<<"Tedarikcilere Verilen Siparisler"<<endl;
	int i;
	for (i=1;i<10;i++)
	{
		if(Ver[i].getId()!=0)
		{
			id=Ver[i].getId();
			index=urunler[id].gettedarikciid();
			cout<<"Tedarikci : "<<tedarikciler[index].getTedarikciMarka()<<endl;
			cout<<"Urun : "<<urunler[id].geturunisim()<<endl;
			cout<<"Adet : "<<Ver[i].getAdet()<<endl;
			cout<<"Maliyet :"<<Ver[i].getmaliyet()<<endl;
		}
	}
	cout<<"Musterilerin Verdigi Siparisler"<<endl;
	int a;
	for (a=1;a<10;a++)
	{
		if(Al[a].getId()!=0)
		{
			id=Al[a].getId();
			index=urunler[id].gettedarikciid();
			cout<<"Musteri : "<<Al[a].getAd()<<endl;
			cout<<"Urun : "<<urunler[id].geturunisim()<<endl;
			cout<<"Adet : "<<Al[a].getAdet()<<endl;
			cout<<"Maliyet :"<<Al[a].getmaliyet()<<endl;
		}
	}
	siparisTercih();
}

void screen::AlBilgi()
{
	int sayac;
	for (sayac=1;sayac<10;sayac++)
	{
		if(urunler[sayac].geturunid()!=0)
		{
			cout<<"Urun ID: "<<urunler[sayac].geturunid()<<endl;
			cout<<"Urun Isim: "<<urunler[sayac].geturunisim()<<endl;
			cout<<"Urun Alis Fiyat: "<<urunler[sayac].geturunalisfiyati()<<endl;
			cout<<"Urun Adet: "<<urunler[sayac].geturunadet();
			cout<<endl;
		}
		
	}
}

void screen::SatBilgi()
{
		int sayac;
	for (sayac=1;sayac<10;sayac++)
	{
		if(urunler[sayac].geturunid()!=0)
		{
			cout<<"Urun ID: "<<urunler[sayac].geturunid()<<endl;
			cout<<"Urun Isim: "<<urunler[sayac].geturunisim()<<endl;
			cout<<"Urun Satis Fiyat: "<<urunler[sayac].geturunsatisfiyati()<<endl;
			cout<<"Urun Adet: "<<urunler[sayac].geturunadet();
			cout<<endl;
		}
		
	}
}
//----------------------------------------Dosya Iþleleri------------------------------------------------------------------------------------

void screen::DosyaUrunEkle()
{
	int i;
	remove("Urun.txt");
	ofstream UrunEkle;
	UrunEkle.open("Urun.txt",ios::app);
	for(i=1;i<10;i++)
	{
		if(urunler[i].geturunid()!=0)
		{
			UrunEkle<<endl<<urunler[i].geturunid()<<setw(20)<<urunler[i].gettedarikciid()<<setw(20)<<urunler[i].geturunisim()<<setw(20)<<urunler[i].geturunalisfiyati()<<setw(20)<<urunler[i].geturunsatisfiyati()<<setw(20)<<urunler[i].geturunadet();
		}
	}

}

void screen::DosyaUrunDuzenle()
{
	int id,ti,adet;
	float al,sat;
	string isim;
	ifstream UrunDuzenle("Urun.txt");
	while(!(UrunDuzenle.eof()))
	{
		UrunDuzenle>>id>>ti>>isim>>al>>sat>>adet;
		urunler[id].urunduzenle(id,ti,isim,al,sat,adet);
	}
	UrunDuzenle.close();
	
} 

void screen::DosyaTedarikciEkle()
{
	int i;
	remove("Tedarikci.txt");
	ofstream TedarikciEkle;
	TedarikciEkle.open("Tedarikci.txt",ios::app);
	for(i=1;i<10;++i)
	{
		if(tedarikciler[i].getTedarikciID()!=0)
		{
			TedarikciEkle<<endl<<tedarikciler[i].getTedarikciID()<<setw(20)<<tedarikciler[i].getTedarikciMarka()<<setw(20)<<tedarikciler[i].getTedarikciIletisimNo();
		}
	}
}

void screen::DosyaTedarikciDuzenle()
{
	int id;
	string marka,no;
	ifstream TedarikciDuzenle("Tedarikci.txt");
	while(!(TedarikciDuzenle.eof()))
	{
		TedarikciDuzenle>>id>>marka>>no;
		tedarikciler[id].TedarikciDuzenle(id,marka,no);
	}
	TedarikciDuzenle.close();
}

void screen::DosyaAlSepetEkle()
{
	int i;
	remove("AlinanSiparisler.txt");

	ofstream SiparisEkle;
	SiparisEkle.open("AlinanSiparisler.txt",ios::app);
	for(i=1;i<10;i++)
	{
		if(Al[i].getId()!=0)
		{
			SiparisEkle<<endl<<Al[i].getAd()<<setw(10)<<Al[i].getId()<<setw(10)<<Al[i].getAdet()<<setw(10)<<Al[i].getmaliyet();
		}
	}
}

void screen::DosyaAlSepetDuzenle()
{
	int Id,Adet,i=1;
	float maliyet;
	string musteriAdi;
	ifstream SiparisDuzenle("AlinanSiparisler.txt");
	while(!(SiparisDuzenle.eof()))
	{
		SiparisDuzenle>>musteriAdi>>Id>>Adet>>maliyet;
		Al[i].Al(musteriAdi,Id,Adet,maliyet);
		++i;
	}
	SiparisDuzenle.close();
}

void screen::DosyaSatSepetEkle()
{
	int i=1;
	remove("VerilenSiparisler.txt");

	ofstream SatSiparisEkle;
	SatSiparisEkle.open("VerilenSiparisler.txt",ios::app);
	for(i=1;i<10;i++)
	{
		if(Ver[i].getId()!=0)
		{
			SatSiparisEkle<<endl<<Ver[i].getId()<<setw(10)<<Ver[i].getAdet()<<setw(10)<<Ver[i].getmaliyet();
		}
	}
}

void screen::DosyaSatSepetDuzenle()
{
	int i=1;
	int Id,Adet;
	float maliyet;
	string musteriAdi;
	ifstream SatSiparisDuzenle("VerilenSiparisler.txt");
	while(!(SatSiparisDuzenle.eof()))
	{
		SatSiparisDuzenle>>Id>>Adet>>maliyet;
		Ver[i].Ver(Adet, Id, maliyet);
		++i;
	}
	SatSiparisDuzenle.close();
}

//-----------------------------------------Static Tutucular-----------------------------------------------------------------------------------------------------------

void screen::BaslangicDosyaIslemleri()
{
	ofstream SatSiparisEkle;
	SatSiparisEkle.open("VerilenSiparisler.txt",ios::app);
	ofstream SiparisEkle;
	SiparisEkle.open("AlinanSiparisler.txt",ios::app);
	SiparisEkle.close();
	ofstream TedarikciEkle;
	TedarikciEkle.open("Tedarikci.txt",ios::app);
	TedarikciEkle.close();
	ofstream UrunEkle;
	UrunEkle.open("Urun.txt",ios::app);
	UrunEkle.close();
	ofstream static1;
	static1.open("static1.txt",ios::app);
	static1.close();
	ofstream static2;
	static2.open("static2.txt",ios::app);
	static2.close();
	ofstream static3;
	static3.open("static3.txt",ios::app);
	static3.close();
	ofstream static4;
	static4.open("static4.txt",ios::app);
	static4.close();
	
	
	SatSiparisEkle.close();
	DosyaAlSepetDuzenle();
	DosyaSatSepetDuzenle();
	DosyaTedarikciDuzenle();
	DosyaUrunDuzenle();
	
}

void screen::UrunEkleTutucu(int a)
{
	remove("static1.txt");
	ofstream static1;
	static1.open("static1.txt",ios::app);
	static1<<a;
}

int screen::staticUrunEkle()
{
	int a;
	ifstream static1("static1.txt");
	static1>>a;

	return a;
}

void screen::TedarikciEkleTutucu(int a)
{
	remove("static2.txt");
	ofstream static2;
	static2.open("static2.txt",ios::app);
	static2<<a;
}

int screen::staticTedarikciEkle()
{
	int a;
	ifstream static2("static2.txt");
	static2>>a;

	return a;
}

void screen::SiparisTedarikTutucu(int a)
{
	remove("static3.txt");
	ofstream static3;
	static3.open("static3.txt",ios::app);
	static3<<a;
}

int screen::staticSiparisTedarik()
{
	int a;
	ifstream static3("static3.txt");
	static3>>a;

	return a;
}
void screen::SiparisSatisTutucu(int a)
{
	remove("static4.txt");
	ofstream static4;
	static4.open("static4.txt",ios::app);
	static4<<a;
}
int screen::staticSiparisSatis()
{
	int a;
	ifstream static4("static4.txt");
	static4>>a;
	
	
	return a;
}
