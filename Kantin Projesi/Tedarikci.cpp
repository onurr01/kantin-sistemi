#include <iostream>
#include <string>
#include <stdexcept>
#include "Tedarikci.h"
using namespace std;
//-----------------------------------------------------Operator Overloading------------------------------------------------------------------------
ostream &operator<<(ostream &output,Tedarikci &tedarik)
{
	output<<tedarik.getTedarikciMarka();
	return output;
}
//  ---------------------------------------------------Yapýcý-Yýkýcý Fonks-------------------------------------------------------------------------
	Tedarikci::Tedarikci(int TedarikciID,string TedarikciMarka)
	{
		TedarikciDuzenle(TedarikciID,TedarikciMarka);
	}
	Tedarikci::Tedarikci(int TedarikciID, string TedarikciMarka,string TedarikciIletisimNo)
	{
		TedarikciDuzenle( TedarikciID,TedarikciMarka);
	}
	Tedarikci::~Tedarikci()
	{
		cout<<tedarikciID<<" ID li Tedarikci Silme Islemi Basarili.."<<endl;
	}
//  ----------------------------------------------------- Fonks-------------------------------------------------------------------------

	void Tedarikci::TedarikciDuzenle(int TedarikciID, string TedarikciMarka,string TedarikciIletisimNo)
	{
		setTedarikciID(TedarikciID);
		setTedarikciMarka(TedarikciMarka);
		settedarikciIletisimNo(TedarikciIletisimNo);
	}
	void Tedarikci::TedarikciDuzenle(int TedarikciID, string TedarikciMarka)
	{
		setTedarikciID(TedarikciID);
		setTedarikciMarka(TedarikciMarka);
		
	}
	void Tedarikci::TedarikciBilgi() const
	{
		if(tedarikciID!=0)
		{
			cout<<"Tedarikci ID:"<< tedarikciID;
			cout <<" Tedarikci Marka:"<< tedarikciMarka;
			cout <<" Tedarikci Iletisim No:"<< getTedarikciIletisimNo()<<endl;
		}
	}
//  ---------------------------------------------------Set Fonks-------------------------------------------------------------------------

	void Tedarikci::setTedarikciID(int TedarikciID)
	{
		tedarikciID=TedarikciID;
	}
	void Tedarikci::setTedarikciMarka(string Marka)
	{	
		if( Marka == " " || Marka.length() == 1)
		{
			throw invalid_argument( "Marka degeri bos olmaz!!");
		}
		else
		{
			tedarikciMarka=Marka;	
		}
		
	}
	void Tedarikci::settedarikciIletisimNo(string TelNo)
	{
		tedarikciIletisimNo=TelNo;
	}
//  ---------------------------------------------------Get Fonks-------------------------------------------------------------------------

	int Tedarikci::getTedarikciID()const
	{
		return tedarikciID;
	}
	string Tedarikci::getTedarikciMarka()const
	{
		return tedarikciMarka;
	}
	string Tedarikci::getTedarikciIletisimNo()const
	{
		return tedarikciIletisimNo;
	}
