#include "Arbin.h"
#include <string>
	
	/*Arbin::Arbin(void)
	{
		raiz = 0;
	}*/
	
	Nodo* Arbin::getRaiz (void) const 
	{
		return raiz;
	}
	
	void Arbin::setRaiz(Nodo * r)
	{
		raiz = r;
	}

	bool Vacio(Nodo *r) { 	// Comprobar si el árbol está vacío:
      return r==NULL;
   }
	//Se inserta la cuenta
	bool Arbin::insertarCuentaRecursivo(Nodo* *r,const int pCuenta, char pTipoCuenta, double pSaldo, string pNombreCliente)
	{
		Nodo * n;
		if(estaCuenta(pCuenta) == true)
		{
			return false;
		}
		else if(*r == 0)
		{
			*r = new Nodo(pCuenta, pTipoCuenta,pSaldo,pNombreCliente);
		}
		else if(pCuenta > (*r)->_numeroCuenta)
		{
			return insertarCuentaRecursivo (&((*r)->hijoDer), pCuenta, pTipoCuenta, pSaldo, pNombreCliente);
		}
		else
		{
			return insertarCuentaRecursivo (&((*r)->hijoIzq), pCuenta, pTipoCuenta, pSaldo, pNombreCliente);
		}
	}

	bool Arbin::estaCuenta (const int &pCuenta) {
	//retorna true si pCuenta está en el árbol, false si no
		return estaCuentaRecursivo(raiz, pCuenta);
	}
	//Define si está la cuenta en el arbol antes de insertar
	bool Arbin::estaCuentaRecursivo(Nodo *r, const int &pCuenta)
	{
		Nodo* padre = NULL;
		if (r == 0) {
			return false;
		}else if (r->_numeroCuenta == pCuenta) {
			return true;
		}else if (pCuenta > r->_numeroCuenta) {
			return estaCuentaRecursivo(r->hijoDer , pCuenta);
		}
		else if (pCuenta < r->getNumCuenta()) {
			return estaCuentaRecursivo(r->hijoIzq, pCuenta);
		}
	}

	//Busca la cuenta por numero de cuenta
	Nodo* Arbin::buscarCuentaRecursivo(Nodo *r, const int &pCuenta)
	{
		if (r == 0) {
			return false;
		}else if (r->_numeroCuenta == pCuenta) {
			return r;
		}else if (pCuenta > r->_numeroCuenta) {
			return buscarCuentaRecursivo(r->hijoDer , pCuenta);
		}
		else if (pCuenta < r->_numeroCuenta) {
			return buscarCuentaRecursivo(r->hijoIzq, pCuenta);
		}
	}

	//Busca la cuenta por nombre del cliente
	Nodo* Arbin::buscarCuentaNombreRecursivo(Nodo *r, string &pNombreCliente)
	{
		if (r == 0) {
			return false;
		}else if (r->_nombreCliente == pNombreCliente) {
			return r;
		}else if (r->hijoDer->_nombreCliente == pNombreCliente) {
			return buscarCuentaNombreRecursivo(r->hijoDer , pNombreCliente);
		}
		else if (r->hijoIzq->_nombreCliente == pNombreCliente) {
			return buscarCuentaNombreRecursivo(r->hijoIzq, pNombreCliente);
		}
	}

	//Imprime en Inorden
	void Arbin::InOrden(void (*func)(int&) , Nodo *nodo, bool r)
	{
		if(r) nodo = raiz;
		if(nodo->hijoIzq) InOrden(func, nodo->hijoIzq, false);
		func(nodo->_numeroCuenta);
		if(nodo->hijoDer) InOrden(func, nodo->hijoDer, false);
	}

