#ifndef TEDARIkCI_H
#define TEDARIKCI_H
#include <iostream>
#include <string>
using namespace std;
 class Tedarikci
{
	friend ostream &operator<<(ostream &output,Tedarikci &tedarik);
	private:
		int tedarikciID;
		string tedarikciMarka;
		string tedarikciIletisimNo;
		void setTedarikciID(int TedarikciID);
		void setTedarikciMarka(string Marka);
		void settedarikciIletisimNo(string TelNo);
	
	

	public:
		string getTedarikciMarka()const;
		explicit Tedarikci(int TedarikciID=0,string TedarikciMarka="null");
		explicit Tedarikci(int TedarikicID, string TedarikciMarka,string TedarikciIletisimNo);
		~Tedarikci();
		string getTedarikciIletisimNo()const;
		void TedarikciDuzenle(int TedarikicID, string TedarikciMarka,string TedarikciIletisimNo);
		void TedarikciDuzenle(int TedarikicID=0, string TedarikciMarka="null");
		void TedarikciBilgi() const;
		int getTedarikciID()const;
		
};

#endif
