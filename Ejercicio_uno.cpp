/*
Titulo:Crear un Menu con variables globales
Auntor:Jose Eduardo Flores Saravia
Descripcion: Generar un programa con el uso de variables globales
Fecha 2024-01-26
*/
#include <iostream>
#include <cctype>
#include <cstdlib> // Para la función system en sistemas UNIX
#include <unistd.h> // Para la función usleep en sistemas UNIX

using namespace std;

// Variables globales
int n1, n2;//Almacenan los dos números ingresados por el usuario.
char opcion;// Almacena la opción seleccionada por el usuario.
double res_num;//Almacena el resultado de operaciones numéricas.
string palabra_uno, palabra_dos;//Almacenan dos frases ingresadas por el usuario.

void IngresoFrace()// Pide al usuario que ingrese dos frases y las almacena
{
	cout << "Ingrese la primera frase: " << endl;
	cin >> palabra_uno;
	cout << "Ingrese la segunda frase: " << endl;
	cin >> palabra_dos;
}

void concatenar()// Concatena las dos frases y muestra el resultado.
{
	cout << "La concatenacion es: " + palabra_uno + " " + palabra_dos << endl;
}

void SubMenu()//Muestra un submenú con opciones adicionales para operaciones numéricas.
{
	cout << "----------SUBMENU--------------" << endl;
	cout << "1) -- Suma de 2 numeros" << endl;
	cout << "2) -- Division de 2 numeros" << endl;
	cout << "(m/M) -- Volver al menu principal" << endl;
	cin >> opcion;
}

void sumar()// Suma los dos números ingresados y muestra el resultado.
{
	res_num = n1 + n2;
	cout << "La suma total es: " << res_num << endl;
}

void divi()//Divide los dos números ingresados y muestra el resultado. Si el segundo número es 0, muestra un mensaje de error.
{
	if (n2 != 0)
	{
		res_num = static_cast<double>(n1) / static_cast<double>(n2);
		cout << "La respuesta de la division es: " << res_num << endl;
	}
	else
	{
		cout << "!!!No es posible dividir entre 0!!!" << endl;
	}
}

void IngresoValores()//Pide al usuario que ingrese dos valores y los almacena en n1 y n2.
{
	cout << "Ingrese el primer valor: ";
	cin >> n1;
	cout << "Ingrese el segundo valor: ";
	cin >> n2;
}

void MenuPrincipal()// Muestra el menú principal con opciones para operaciones numéricas y concatenación de cadenas.
{
	cout << "----------MENU--------------" << endl;
	cout << "(1) -- Operacion con Nùmeros" << endl;
	cout << "(2) -- Concatenar 2 cadenas" << endl;
	cout << "(s/S) -- Salir" << endl;
	cin >> opcion;
}

void limpiarPantalla()//Limpia la pantalla de la consola.
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void esperarTecla()//Pausa la ejecución y espera a que el usuario presione Enter.
{
#ifdef _WIN32
	system("pause");
#else
	cout << "Presione Enter para continuar...";
	cin.ignore();
	cin.get();
#endif
}

int main(int argc, char *argv[])
{
	/*El bucle contiene un menú principal que permite al usuario elegir entre realizar operaciones numéricas o concatenar cadenas.*/
	do//Un bucle principal que se ejecuta mientras el usuario no elija salir (s).
	{
		limpiarPantalla();
		MenuPrincipal();
		opcion = tolower(opcion);
		
		switch (opcion)
		{
		case '1':
			do
			{
				limpiarPantalla();
				SubMenu();
				switch (opcion)
				{
				case '1':
					IngresoValores();
					sumar();
					esperarTecla();
					break;
				case '2':
					IngresoValores();
					divi();
					esperarTecla();
					break;
				case 'm':
					cout << "Volviendo al Menú Principal" << endl;
					esperarTecla();
					break;
				default:
					cout << "NO ES UNA OPCION VALIDA" << endl;
					esperarTecla();
				}
			} while (opcion != 'm');
			break;
		case '2':
			IngresoFrace();
			concatenar();
			esperarTecla();
			break;
		case 's':
			cout << "Saliendo" << endl;
			break;
		default:
			cout << "NO ES UNA OPCION VALIDA" << endl;
			esperarTecla();
		}
		
	} while (opcion != 's');
	return 0;
}
