#ifndef ARBIN_H
#define ARBIN_H

#include "Nodo.h"
#include <string>

class Arbin
{

public:
	//Arbin(void);
	Arbin() : raiz(NULL), actual(NULL) {}
	Nodo * getRaiz (void) const;
	void setRaiz(Nodo *);
	bool insertarCuentaRecursivo(Nodo* *raiz,const int pCuenta,char pTipoCuenta, double pSaldo, string pNombreCliente);
	bool estaCuenta (const int &pCuenta);
	bool estaCuentaRecursivo(Nodo *r, const int &pCuenta);
	Nodo* buscarCuentaRecursivo(Nodo *r, const int &pCuenta);
	Nodo* Arbin::buscarCuentaNombreRecursivo(Nodo *r, string &pNombreCliente);
	void InOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
	int getNumCuenta(int pCuenta);
	int cuenta;
	bool buscar(Nodo * , int pcuenta);

//private:
	Nodo *raiz;
	Nodo *actual;
	int contador;
	int altura;
};

#endif