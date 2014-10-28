#ifndef Cuenta_H
#define Cuenta_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cuenta{

public:
		Cuenta(const int pCuenta, const char tipoCuenta, double saldo, string _nombreCliente, Cuenta *izq=NULL, Cuenta *der=NULL) :
		_numeroCuenta(pCuenta), _tipoCuenta(tipoCuenta),_saldoCuenta(saldo),_nombreCliente(_nombreCliente), hijoIzq(izq), hijoDer(der) {}

		int getInfo (void) const;
		Cuenta * getHijoIzq (void) const ;
		Cuenta * getHijoDer (void) const;
		void setInfo (int x);
		void setHijoIzq(Cuenta *);
		void setHijoDer(Cuenta *);
		void imprimirCuenta (void);
		
		bool ingresarDinero(double dinero);
		bool retirarDinero(double dinero);
		double getSaldo(void);
		bool getEstado(void);
		int getNumCuenta(void);
		bool cerrarCuenta(void);
		void setSaldo(double dinero);
		void setEstado(bool estado);
		void setNumCuenta(int numCuenta);
//private:

		Cuenta * hijoIzq;
		Cuenta * hijoDer;
		
		double _saldoCuenta;
		int _numeroCuenta;
		char _tipoCuenta;
		string _nombreCliente;
		bool _estado;
};
#endif