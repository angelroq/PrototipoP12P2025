#include "Industrias.h"
#include <iostream>
using namespace std;

void Industrias::llamaciclo()
{
    float camaraIndustria[numeroEmpresas][aniosDeVentas + 1];
    float camaraConstruccion[numeroEmpresas][aniosDeVentas + 1];
    float camaraTransporte[numeroEmpresas][aniosDeVentas + 1];
    char opcion;  //Variable que controla el ciclo de repeticiòn
    bool repetir = true;  //Variable booleana del ciclo de repeticiòn
    //Declaraciòn de variables flotantes para el calculo de promedios
    float promedioIndustria;
    float promedioConstruccion;
    float promedioTransporte;
    //Declaraciòn de matriz que almacenarà los nombres de los alumnos
    char empresas[numeroEmpresas][MAXIMA_LONGITUD_CADENA] = {"Empresa 1","Empresa 2","Empresa 3","Empresa 4","Empresa 5"};
    do
    {
        system("cls");
        //Inicializar los promedios por facultad
        promedioIndustria=0;
        promedioConstruccion=0;
        promedioTransporte=0;
        cout << "*** Comparativo de Industrias ***" << endl << endl;
        llenarMatriz(camaraIndustria); //Calculo de las notas por facultad
        promedioIndustria = imprimirMatriz(camaraIndustria, empresas, "Camara de Industria"); //Despliegue de valores por facultad
        llenarMatriz(camaraConstruccion);
        promedioConstruccion = imprimirMatriz(camaraConstruccion, empresas, "Camara de la construccion");
        llenarMatriz(camaraTransporte);
        promedioTransporte = imprimirMatriz(camaraTransporte, empresas, "Camara de transporte");
        //Calculo del mejor promedio de las facultades
        if (promedioIndustria > promedioConstruccion && promedioIndustria > promedioTransporte)
        {
            //Facultad 1 es mayor
            cout << " La industria con el mejor promedio es : " << "Camara de industria" << " Promedio: " << promedioIndustria << endl;
        } else
        if (promedioConstruccion > promedioIndustria && promedioConstruccion > promedioTransporte)
        {
            //Facultad 2 es mayor
            cout << " La industria con el mejor promedio es : " << "Camara de la construccion" << " Promedio: " << promedioConstruccion << endl;
        } else
        if (promedioTransporte > promedioConstruccion && promedioTransporte > promedioIndustria)
        {
            //Facultad 3 es mayor
            cout << " La industria con el mejor promedio es : " << "Camara de transporte" << " Promedio: " << promedioTransporte << endl;
        } else
        {
            //Varias facultades son iguales en promedio
            cout << " Algunas industrias tienen el mismo promedio " << endl << endl;
        }
        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n')
        {
            repetir=false;
        }
    } while (repetir);
}
int Industrias::busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
void Industrias::llenarMatriz(float matriz[numeroEmpresas][aniosDeVentas + 1])
{
    int y, x;
    for (y = 0; y < numeroEmpresas; y++)
    {
        float suma = 0;
        int calificacion = 0;
        for (x = 0; x < aniosDeVentas; x++)
        {
            if (x == 0 || x == 3)  //Calculo del primer parcial o actividades
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 1000);
            } else if (x == 1)  //Calculo del segundo parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 1000);
            } else if (x == 2)  //Calculo del examen final
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 1000);
            }
            suma += (float)calificacion;
            matriz[y][x] = calificacion;
            calificacion=0;
        }
        // Agregar promedio al final de la matriz

        matriz[y][aniosDeVentas] = suma;
    }
}
void Industrias::imprimirMatrizLinea()
{
    int x;

    cout << "+--------";
    for (x = 0; x < aniosDeVentas + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}
float Industrias::imprimirMatriz(float matriz[numeroEmpresas][aniosDeVentas + 1], char empresas[numeroEmpresas][MAXIMA_LONGITUD_CADENA], string nombreIndustria)
{
    int y, x;

    float promedioMayor = matriz[0][aniosDeVentas];
    float promedioMenor = matriz[0][aniosDeVentas];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char empresaPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char empresaPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(empresaPromedioMayor, empresas[0], MAXIMA_LONGITUD_CADENA);
    memcpy(empresaPromedioMenor, empresas[0], MAXIMA_LONGITUD_CADENA);
    cout << nombreIndustria << endl;
    cout << "         Venta año 2015           Venta año 2016         Venta año 2017          Venta año 2018" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Empresa";
    for (x = 0; x < aniosDeVentas; x++)
    {
        cout << setw(9) << "VENTA" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < numeroEmpresas; y++)
    {
        cout << "!" << setw(8) << empresas[y] << "!";
        float suma = 0;
        for (x = 0; x < numeroEmpresas; x++)
        {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz[y][numeroEmpresas];
        totalGeneral += matriz[y][numeroEmpresas];
        if (promedio > promedioMayor) //Se va guardando la nota mayor y el nombre del alumno
        {
            promedioMayor = promedio;
            memcpy(empresaPromedioMayor, empresas[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor) //Se va guardando la nota menor y el nombre del alumno
        {
            promedioMenor = promedio;
            memcpy(empresaPromedioMenor, empresas[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    //Calculo del promedio general de cada facultad
    promedioGeneral = totalGeneral / numeroEmpresas;
    cout << "Venta mayor " << setw(10) << empresaPromedioMayor <<  setw(10) << promedioMayor << endl;
    cout << "venta menor " << setw(10) << empresaPromedioMenor <<  setw(10) << promedioMenor << endl;
    cout << "Venta prom : " << setw(10) <<  promedioGeneral << endl << endl;
    return promedioGeneral; //Retorno del promedio general por facultad
}
Industrias::Industrias()
{
    //ctor
}

Industrias::~Industrias()
{
    //dtor
}
