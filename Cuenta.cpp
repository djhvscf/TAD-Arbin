#include "Cuenta.h"


int Cuenta::getInfo(void) const 
	{
		return 0;
		//return info;
	}

	Cuenta* Cuenta::getHijoIzq (void) const 
	{
		return hijoIzq;
	}

	Cuenta * Cuenta::getHijoDer (void) const 
	{
		return hijoDer;
	}

	void Cuenta::setInfo(int x)
	{
		_numeroCuenta = x;
	}

	void Cuenta::setHijoIzq(Cuenta * p)
	{
		 hijoIzq = p;
	}

	void Cuenta::setHijoDer(Cuenta * p) 
	{
		hijoDer = p;
	}

	void  Cuenta::imprimirCuenta (void)
	{
		cout << _numeroCuenta << endl;
	}

	bool Cuenta::ingresarDinero(double dinero)
	{
		_saldoCuenta +=dinero;
		return true;
	}

	bool Cuenta::retirarDinero(double dinero)
	{
		if(getSaldo() >= dinero)
		{
			_saldoCuenta -=dinero;
			return true;
		}
		else
		{
			return false;
		}
	}

	double Cuenta::getSaldo()
	{
		return _saldoCuenta;
	}

	bool Cuenta::getEstado()
	{
		return _estado;
	}

	int Cuenta::getNumCuenta()
	{
		return _numeroCuenta;
	}

	bool Cuenta::cerrarCuenta()
	{
		if(_estado ==true)
		{
			_estado ==false;
			return true;
		}
		else
		{
			return false;
		}
	}
	void Cuenta::setSaldo(double dinero)
	{
		_saldoCuenta = dinero;
	}

	void Cuenta::setEstado(bool estado)
	{
		_estado = estado;
	}

	void Cuenta::setNumCuenta(int numCuenta)
	{
		_numeroCuenta = numCuenta;
	}