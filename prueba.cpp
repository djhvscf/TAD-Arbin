#include <iostream>
#include <string>
#include "Arbin.h"

using namespace std;

int menu(void);
void Mostrar(int &d);

int main(void)
{
	int opcion=0,salir=0;
	int clienteNum = 0 ;
	double ingreso;
	double saldo;
	string _nombreCliente;
	Arbin c;
	Arbin d;
   do{
		opcion=menu();
      switch(opcion)
      {
         case 1:
         {
			cout << "Digite el número de cedula del cliente para la cuenta en DOLARES: " << endl;
			cin >> clienteNum;
			cout << "Digite el nombre del cliente dueño de la cuenta: " << endl;
			cin >> _nombreCliente;
			if(d.insertarCuentaRecursivo(&d.raiz,clienteNum,'d',0,_nombreCliente))
			{
				cout << "Ingresada la cuenta: " << clienteNum << endl;
				cout << "Nombre del Cliente: " << _nombreCliente <<endl;
				cout << "Saldo: 0" << endl;
			}
			else
			{
				cout << "La cuenta: " << clienteNum << " ya existe" << endl;
			}
            break;
         }

         case 2:
         {
			cout << "Digite el número de cedula del cliente para la cuenta en COLONES: " << endl;
			cin >> clienteNum;
			cout << "Digite el nombre del cliente dueño de la cuenta: " << endl;
			cin >> _nombreCliente;
			if(c.insertarCuentaRecursivo(&c.raiz,clienteNum,'c',0,_nombreCliente))
			{
				cout << "Ingresada la cuenta: " << clienteNum << endl;
				cout << "Nombre del Cliente: " << _nombreCliente <<endl;
				cout << "Saldo: 0" << endl;
			}
			else
			{
				cout << "La cuenta: " << clienteNum << " ya existe" << endl;
			}
            break;
         }

         case 3:
         {
			cout << "Ingrese el número de cuenta en COLONES del cliente a buscar: " << endl;
			cin >> clienteNum;
			Nodo* r = c.buscarCuentaRecursivo(c.raiz,clienteNum);
			if(r == NULL)
			{
				cout << "La cuenta no existe. "<< endl;
			}else
			{
				cout << "Numero de cuenta: " << r->_numeroCuenta <<endl;
				cout << "Nombre del cliente: " << r->_nombreCliente <<endl;
				cout << "Saldo: " << r->_saldoCuenta <<endl;
			}
			
            break;
         }

         case 4:
         {
			 cout << "Ingrese el número de cuenta en DOLARES del cliente a buscar: " << endl;
			cin >> clienteNum;
			Nodo* r = d.buscarCuentaRecursivo(d.raiz,clienteNum);
			if(r == NULL)
			{
				cout << "La cuenta no existe. "<< endl;
			}else
			{
				cout << "Numero de cuenta: " << r->_numeroCuenta <<endl;
				cout << "Nombre del cliente: " << r->_nombreCliente <<endl;
				cout << "Saldo: " << r->_saldoCuenta <<endl;
			}
			
            break;
         }

         case 5:
         {
            cout << "Ingrese el nombre del cliente dueño de la cuenta en DOLARES a buscar: " << endl;
			cin >> _nombreCliente;
			Nodo* r = d.buscarCuentaNombreRecursivo(d.raiz,_nombreCliente);
			if(r == NULL)
			{
				cout << "La cuenta no existe. "<< endl;
			}else
			{
				cout << "Numero de cuenta: " << r->_numeroCuenta <<endl;
				cout << "Nombre del cliente: " << r->_nombreCliente <<endl;
				cout << "Saldo: " << r->_saldoCuenta <<endl;
			}
			
            break;
         }

         case 6:
         {
            cout << "Ingrese el nombre del cliente dueño de la cuenta en COLONES a buscar: " << endl;
			cin >> _nombreCliente;
			Nodo* r = c.buscarCuentaNombreRecursivo(c.raiz,_nombreCliente);
			if(r == NULL)
			{
				cout << "La cuenta no existe. "<< endl;
			}else
			{
				cout << "Numero de cuenta: " << r->_numeroCuenta <<endl;
				cout << "Nombre del cliente: " << r->_nombreCliente <<endl;
				cout << "Saldo: " << r->_saldoCuenta <<endl;
			}
			
            break;
         }

         case 7:
         {
			cout << "Ingrese el número de cuenta en DOLARES del cliente a depositar: " << endl;
			cin >> clienteNum;
			Nodo* r = d.buscarCuentaRecursivo(d.raiz,clienteNum);
			if(r == NULL)
			{
				cout << "La cuenta no existe. "<< endl;
			}else
			{
				cout <<"Ingrese el saldo a depositar en la cuenta "<< r->_numeroCuenta << ": " << endl;
				cin >> saldo;
				r->_saldoCuenta += saldo;
				cout << "Saldo actual: " << r->_saldoCuenta << endl;
			}
			break;
         }

         case 8:
         {
			cout << "Ingrese el número de cuenta en COLONES del cliente a depositar: " << endl;
			cin >> clienteNum;
			Nodo* r = c.buscarCuentaRecursivo(c.raiz,clienteNum);
			if(r == NULL)
			{
				cout << "La cuenta no existe. "<< endl;
			}else
			{
				cout <<"Ingrese el saldo a depositar en la cuenta "<< r->_numeroCuenta << ": " << endl;
				cin >> saldo;
				r->_saldoCuenta += saldo;
				cout << "Saldo actual: " << r->_saldoCuenta << endl;
			}
			break;
         }

		 case 9:
			 {
				cout << "Ingrese el número de cuenta en COLONES del cliente a retirar: " << endl;
				cin >> clienteNum;
				Nodo* r = c.buscarCuentaRecursivo(c.raiz,clienteNum);
				if(r == NULL)
				{
					cout << "La cuenta no existe. "<< endl;
				}else
				{
					cout <<"Ingrese el saldo a retirar en la cuenta "<< r->_numeroCuenta << ": " << endl;
					cin >> saldo;
					if( r->_saldoCuenta  >= saldo)
					{
						r->_saldoCuenta -= saldo;
						cout << "Saldo actual: " << r->_saldoCuenta << endl;
					}
					else
					{
						cout << "No tiene saldo suficiente para retirar esta cantidad: " << saldo << endl;
						cout << "Saldo actual de la cuenta: " <<r->_saldoCuenta <<endl;
					}
				}
				break;
			 }

			case 10:
			 {
				cout << "Ingrese el número de cuenta en DOLARES del cliente a retirar: " << endl;
				cin >> clienteNum;
				Nodo* r = d.buscarCuentaRecursivo(d.raiz,clienteNum);
				if(r == NULL)
				{
					cout << "La cuenta no existe. "<< endl;
				}else
				{
					cout <<"Ingrese el saldo a retirar en la cuenta "<< r->_numeroCuenta << ": " << endl;
					cin >> saldo;
					if( r->_saldoCuenta  >= saldo)
					{
						r->_saldoCuenta -= saldo;
						cout << "Saldo actual: " << r->_saldoCuenta << endl;
					}
					else
					{
						cout << "No tiene saldo suficiente para retirar esta cantidad: " << saldo << endl;
						cout << "Saldo actual de la cuenta: " <<r->_saldoCuenta <<endl;
					}
				}
				break;
			 }
         case 11:
         {
			 cout <<"Imprimiendo cuentas bancarias..." <<endl;
			 cout << ""<<endl;
			 if(d.raiz != 0)
			 {
				 cout << "Imprimiendo cuentas bancarias en DOLARES..." <<endl;
				d.InOrden(Mostrar);
				cout << ""<<endl;
			 }
			 else
			 {
				 cout << "En el árbol de cuentas DOLARES no hay cuentas" << endl;
				 cout << ""<<endl;
			 }
			 if(c.raiz != 0)
			 {
				 cout << "Imprimiendo cuentas bancarias en COLONES..." <<endl;
				c.InOrden(Mostrar);
				cout << ""<<endl;
			 }
			 else
			 {
				 cout << "En el árbol de cuentas COLONES no hay cuentas" << endl;
				 cout << ""<<endl;
			 }
            break;
         }

         case 0:
         {
            salir=1;            
            break;
         }
      }
   }while(salir!=1);
  
   return 0;
}
void Mostrar(int &d)
{
	cout << d << ",";
}

int menu(void)
{
   int opcion=0;

   do{
      cout << "****************************************************************************" << endl;
      cout << "1. Crear cuenta en DOLARES." << endl;
      cout << "2. Crear cuenta en COLONES." << endl;
      cout << "3. Buscar cuenta en COLONES por número." << endl;
      cout << "4. Buscar cuenta en DOLARES por número. " << endl;
      cout << "5. Buscar cuenta en DOLARES por nombre de cliente." << endl;
	  cout << "6. Buscar cuenta en COLONES por nombre de cliente." << endl;
	  cout << "7. Depositar en cuenta en DOLARES." << endl;
      cout << "8. Depositar en cuenta en COLONES." << endl;
	  cout << "9. Retirar de cuenta en COLONES." << endl;
	  cout << "10. Retirar de cuenta en DOLARES." << endl;
	  cout << "11. Imprimir cuentas en INORDEN." << endl;
      cout << "0.  Salir." << endl;
      cout << "****************************************************************************" << endl;
      cout << "Introduce una opción: ";
      cin >> opcion;
      cout << endl;
   }while((opcion<0)||(opcion>11));

   return opcion;
}