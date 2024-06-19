#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define IVA 0.21

void limpiarPantalla();
float obtenerPrecioPorClase(char claseVuelo);
float calcularPrecioSinIVA(float precio, int numPasajes);
float calcularIVA(float precioSinIVA);
float calcularPrecioConIVA(float precioSinIVA);
const char* obtenerNombreDestino(char destino);
const char* obtenerNombreClaseVuelo(char claseVuelo);

int main() {
    char band = 's', fechaString[11], destino, claseVuelo;
    int numPasajes, totalPasajes = 0;
    float precioPorPasaje, precioSinIVA, ivaAplicado, precioConIVA;
    int countE = 0, countC = 0, countP = 0;

    while (band == 's') {
        printf("Ingrese la fecha en formato yyyy-mm-dd: ");
        scanf("%10s", fechaString);

        printf("Ingrese el destino que desea 'A'->Nueva York, 'B'->Londres, 'C'->Paris, 'D'->Tokio, 'E'->Sidney: ");
        scanf(" %c", &destino);
        destino = toupper(destino);

        do {
            printf("Ingrese el numero de pasajes: ");
            scanf("%d", &numPasajes);

            printf("Ingrese la clase del vuelo Económica ('E'), Ejecutiva ('C') y Primera Clase ('P'): ");
            scanf(" %c", &claseVuelo);
            claseVuelo = toupper(claseVuelo);

            if (claseVuelo == 'E') {
                countE += numPasajes;
            } else if (claseVuelo == 'C') {
                countC += numPasajes;
            } else if (claseVuelo == 'P') {
                countP += numPasajes;
            } else {
                printf("Clase de vuelo inválida.\n");
                continue;
            }

            precioPorPasaje = obtenerPrecioPorClase(claseVuelo);
            precioSinIVA = calcularPrecioSinIVA(precioPorPasaje, numPasajes);
            ivaAplicado = calcularIVA(precioSinIVA);
            precioConIVA = calcularPrecioConIVA(precioSinIVA);

            printf("\nResumen de la reserva parcial:\n");
            printf("Destino elegido: %s\n", obtenerNombreDestino(destino));
            printf("Fecha de viaje: %s\n", fechaString);
            printf("Clase de vuelo: %s\n", obtenerNombreClaseVuelo(claseVuelo));
            printf("Cantidad de pasajes: %d\n", numPasajes);
            printf("Precio por pasaje: $%.2f\n", precioPorPasaje);
            printf("Total sin IVA: $%.2f\n", precioSinIVA);
            printf("IVA aplicado: $%.2f\n", ivaAplicado);
            printf("Total con IVA: $%.2f\n", precioConIVA);

            totalPasajes += numPasajes;

            printf("¿Desea agregar otro pasaje? (s/n): ");
            scanf(" %c", &band);
            band = tolower(band);
        } while (band == 's');

        printf("¿Desea ingresar más reservas? (s/n): ");
        scanf(" %c", &band);
        band = tolower(band);

        limpiarPantalla();
    }

    printf("Resumen final de la reserva:\n");
    printf("Destino elegido: %s\n", obtenerNombreDestino(destino));
    printf("Fecha de viaje: %s\n", fechaString);
    printf("Cantidad total de pasajes: %d\n", totalPasajes);

    if (countE <= countC && countE <= countP) {
        printf("La clase de vuelo menos elegida es: Económica (E)\n");
    } else if (countC <= countE && countC <= countP) {
        printf("La clase de vuelo menos elegida es: Ejecutiva (C)\n");
    } else {
        printf("La clase de vuelo menos elegida es: Primera Clase (P)\n");
    }

    return 0;
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}

float obtenerPrecioPorClase(char claseVuelo) {
    switch (claseVuelo) {
        case 'E':
            return 100.0;
        case 'C':
            return 200.0;
        case 'P':
            return 300.0;
        default:
            return 0.0;
    }
}

float calcularPrecioSinIVA(float precio, int numPasajes) {
    return precio * numPasajes;
}

float calcularIVA(float precioSinIVA) {
    return precioSinIVA * IVA;
}

float calcularPrecioConIVA(float precioSinIVA) {
    return precioSinIVA * (1 + IVA);
}

const char* obtenerNombreDestino(char destino) {
    switch (destino) {
        case 'A':
            return "Nueva York";
        case 'B':
            return "Londres";
        case 'C':
            return "Paris";
        case 'D':
            return "Tokio";
        case 'E':
            return "Sidney";
        default:
            return "Destino inválido";
    }
}

const char* obtenerNombreClaseVuelo(char claseVuelo) {
    switch (claseVuelo) {
        case 'E':
            return "Económica";
        case 'C':
            return "Ejecutiva";
        case 'P':
            return "Primera Clase";
        default:
            return "Clase inválida";
    }
}
