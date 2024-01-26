/*
Titulo:Realizar un programa con funciones y parámetros
Auntor:Jose Eduardo Flores Saravia
Descripcion: Ejercicio Dos crear un menu con funciones y parametros
Fecha 2024-01-26
*/

//Librerias usadas
#include <iostream>// Proporciona funciones para entrada/salida estándar
#include <ctime>//proporciona funciones relacionadas con el tiempo
#include <cstdlib>//proporciona funciones relacionadas con la generación de números aleatorios.
#include <cmath>// Proporciona funciones matemáticas.
#include <vector>//Proporciona la implementación de contenedores de la STL (Standard Template Library
#include <cctype>//Proporciona funciones para trabajar con caracteres.

#ifdef _WIN32//Se utilizan para incluir la cabecera conio.h solo en sistemas operativos Windows 
#include <conio.h>
#else//proporciona funciones estándar del sistema operativo, y aquí se utiliza para pausar la ejecución del programa antes de limpiar la pantalla.
#include <unistd.h>
#endif

using namespace std;

// Definición de funciones

char obtenerOpcion() //Funcion para tomar la opcion del usuario
{
	char opcion;
	cin >> opcion;
	return tolower(opcion);
}

void generarNumeroAzar(int &numero) // Genera un número aleatorio entre 0 y 500 y lo devuelve a través del parámetro de referencia
{
	numero = rand() % 501;
}

void generarNumeroReal(double &numeroReal) //Genera un número real aleatorio y lo devuelve a través del parámetro de referencia
{
	numeroReal = static_cast<double>(rand()) / RAND_MAX;
}

int esPrimo(int numero) // Verifica si un número es primo. Retorna 1 si es primo y 0 si no lo es.
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

void generarNumerosPrimos(int N, vector<int> &primos) //Genera los primeros N números primos y los almacena en un vector proporcionado.
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

void mostrarNumerosPrimos(const vector<int> &primos) //  Muestra los números primos almacenados en un vector proporcionado.
{
	cout << "Números primos generados:" << endl;
	for (int i = 0; i < primos.size(); ++i)
	{
		cout << "[" << i << "]" << primos[i] << endl;
	}
}

void mostrarMenu() // Muestra un menú en la consola con diferentes opciones.
{
	cout << "MENU:" << endl;
	cout << "(1) -- Generar número aleatorio entre 0 y 500" << endl;
	cout << "(2) -- Generar número aleatorio real" << endl;
	cout << "(3) -- Generar N números primos" << endl;
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

void esperarTecla()// Pausa la ejecución del programa y espera a que el usuario presione Enter.
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
	srand(time(0));//Inicializa la semilla del generador de números aleatorios basada en el tiempo actual.
	char opcion;// Variable que almacenará la opción seleccionada por el usuario.
	
	do//Un bucle que continuará ejecutándose hasta que el usuario seleccione la opción 's' para salir.
	{
		limpiarPantalla();
		mostrarMenu();
		opcion = obtenerOpcion();
		/*El bucle contiene un menú interactivo que permite al usuario elegir entre generar números aleatorios, números reales o números primos, así como salir del programa.*/
		switch (opcion)//Las diferentes opciones del menú invocan a las funciones mencionadas anteriormente para realizar las operaciones correspondientes.
		{
		case '1':
		{
			int numeroAleatorio;
			generarNumeroAzar(numeroAleatorio);
			cout << "Número aleatorio entre 0 y 500: " << numeroAleatorio << endl;
			esperarTecla();
			break;
		}
		case '2':
		{
			double numeroRealAleatorio;
			generarNumeroReal(numeroRealAleatorio);
			cout << "Número aleatorio de tipo real: " << numeroRealAleatorio << endl;
			esperarTecla();
			break;
		}
		case '3':
		{
			int N;
			cout << "Ingrese la cantidad de números primos a generar: ";
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
			cout << "Opción no válida. Inténtelo de nuevo." << endl;
			esperarTecla();
		}
		
	} while (opcion != 's');
	
	return 0;
}
