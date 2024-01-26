/*
Titulo:Realizar un programa con funciones y par�metros
Auntor:Jose Eduardo Flores Saravia
Descripcion: Ejercicio Dos crear un menu con funciones y parametros
Fecha 2024-01-26
*/

//Librerias usadas
#include <iostream>// Proporciona funciones para entrada/salida est�ndar
#include <ctime>//proporciona funciones relacionadas con el tiempo
#include <cstdlib>//proporciona funciones relacionadas con la generaci�n de n�meros aleatorios.
#include <cmath>// Proporciona funciones matem�ticas.
#include <vector>//Proporciona la implementaci�n de contenedores de la STL (Standard Template Library
#include <cctype>//Proporciona funciones para trabajar con caracteres.

#ifdef _WIN32//Se utilizan para incluir la cabecera conio.h solo en sistemas operativos Windows 
#include <conio.h>
#else//proporciona funciones est�ndar del sistema operativo, y aqu� se utiliza para pausar la ejecuci�n del programa antes de limpiar la pantalla.
#include <unistd.h>
#endif

using namespace std;

// Definici�n de funciones

char obtenerOpcion() //Funcion para tomar la opcion del usuario
{
	char opcion;
	cin >> opcion;
	return tolower(opcion);
}

void generarNumeroAzar(int &numero) // Genera un n�mero aleatorio entre 0 y 500 y lo devuelve a trav�s del par�metro de referencia
{
	numero = rand() % 501;
}

void generarNumeroReal(double &numeroReal) //Genera un n�mero real aleatorio y lo devuelve a trav�s del par�metro de referencia
{
	numeroReal = static_cast<double>(rand()) / RAND_MAX;
}

int esPrimo(int numero) // Verifica si un n�mero es primo. Retorna 1 si es primo y 0 si no lo es.
{
	if (numero <= 1)
		return 0;
	
	int limite = sqrt(numero);
	
	for (int i = 2; i <= limite; ++i)
	{
		if (numero % i == 0)
			return 0;
	}
	
	return 1;
}

void generarNumerosPrimos(int N, vector<int> &primos) //Genera los primeros N n�meros primos y los almacena en un vector proporcionado.
{
	int numero = 2;
	
	while (primos.size() < N)
	{
		if (esPrimo(numero))
		{
			primos.push_back(numero);
		}
		++numero;
	}
}

void mostrarNumerosPrimos(const vector<int> &primos) //  Muestra los n�meros primos almacenados en un vector proporcionado.
{
	cout << "N�meros primos generados:" << endl;
	for (int i = 0; i < primos.size(); ++i)
	{
		cout << "[" << i << "]" << primos[i] << endl;
	}
}

void mostrarMenu() // Muestra un men� en la consola con diferentes opciones.
{
	cout << "MENU:" << endl;
	cout << "(1) -- Generar n�mero aleatorio entre 0 y 500" << endl;
	cout << "(2) -- Generar n�mero aleatorio real" << endl;
	cout << "(3) -- Generar N n�meros primos" << endl;
	cout << "(s/S) -- Salir" << endl;
}

void limpiarPantalla()//Limpia la pantalla de la consola.
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void esperarTecla()// Pausa la ejecuci�n del programa y espera a que el usuario presione Enter.
{
#ifdef _WIN32
	system("pause");
#else
	cout << "Presione Enter para continuar...";
	cin.ignore();
	cin.get();
#endif	
}


int main() // Funcion principal
{
	srand(time(0));//Inicializa la semilla del generador de n�meros aleatorios basada en el tiempo actual.
	char opcion;// Variable que almacenar� la opci�n seleccionada por el usuario.
	
	do//Un bucle que continuar� ejecut�ndose hasta que el usuario seleccione la opci�n 's' para salir.
	{
		limpiarPantalla();
		mostrarMenu();
		opcion = obtenerOpcion();
		/*El bucle contiene un men� interactivo que permite al usuario elegir entre generar n�meros aleatorios, n�meros reales o n�meros primos, as� como salir del programa.*/
		switch (opcion)//Las diferentes opciones del men� invocan a las funciones mencionadas anteriormente para realizar las operaciones correspondientes.
		{
		case '1':
		{
			int numeroAleatorio;
			generarNumeroAzar(numeroAleatorio);
			cout << "N�mero aleatorio entre 0 y 500: " << numeroAleatorio << endl;
			esperarTecla();
			break;
		}
		case '2':
		{
			double numeroRealAleatorio;
			generarNumeroReal(numeroRealAleatorio);
			cout << "N�mero aleatorio de tipo real: " << numeroRealAleatorio << endl;
			esperarTecla();
			break;
		}
		case '3':
		{
			int N;
			cout << "Ingrese la cantidad de n�meros primos a generar: ";
			cin >> N;
			
			if (N > 0)
			{
				vector<int> primos;
				generarNumerosPrimos(N, primos);
				mostrarNumerosPrimos(primos);
			}
			else
			{
				cout << "La cantidad debe ser mayor que 0." << endl;
			}
			esperarTecla();
			break;
		}
		case 's':
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opci�n no v�lida. Int�ntelo de nuevo." << endl;
			esperarTecla();
		}
		
	} while (opcion != 's');
	
	return 0;
}
