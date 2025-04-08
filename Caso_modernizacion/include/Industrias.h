#ifndef INDUSTRIAS_H
#define INDUSTRIAS_H

#define numeroEmpresas 5
#define aniosDeVentas 4
#define MAX_CALIFICACION 1000
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 1000
class Industrias
{
    public:
        void llamaciclo();
        int busquedaAleatorios(int minimo, int maximo); //Funciòn que permite obtener valores aleatorios en las notas de cada alumno
        void llenarMatriz(float matriz[numeroEmpresas][aniosDeVentas + 1]); //Funciòn que permite asignar a cada alumno las notas aleatorios
        void imprimirMatrizLinea(); //Funciòn que apoya el despliegue de titulos en el comparativo de facultades
            float imprimirMatriz(float matriz[numeroEmpresas][aniosDeVentas + 1], char empresas[numeroEmpresas][MAXIMA_LONGITUD_CADENA]);
        Industrias();
        virtual ~Industrias();

    protected:

    private:
;
};

#endif // INDUSTRIAS_H
