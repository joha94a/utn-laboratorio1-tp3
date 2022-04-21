//Nombre: Johana Araya
//TP N�:
//Ejercicio N�: 17
/*Una estaci�n meteorol�gica registr� una muestra clim�tica de los �ltimos 15 d�as. Por cada d�a registr�:
N�mero de d�a (entero)
Temperatura (float)
Mil�metros de lluvia (float)
Visibilidad en km (float)

Hay un registro por cada d�a. La informaci�n se encuentra ordenada por d�a. Se pide calcular e informar:
El n�mero de d�a que se haya registrado la temperatura m�xima.
La amplitud t�rmica de todo el per�odo.
La cantidad de d�as con neblina.
Mostrar "Quincena lluviosa" si hubo m�s d�as de lluvia que d�as sin lluvia. Mostrar "Quincena h�meda"
 si llovi� al menos un tercio de los d�as. De lo contrario mostrar "Quincena seca".

NOTA: La amplitud t�rmica es la diferencia entre la temperatura m�xima y la temperatura m�nima.
NOTA: Se considera neblina a una visibilidad menor a 2 km.

*/

#include <iostream>
using namespace std;

int main()
{

    int i, dia, dia_n_ll=0, dia_ll=0;
    float temp, mm_ll, v_km, temp_max, temp_min, dia_t_max, ban_temp_min=1,nebl=0, amplitud_term ;
    string est_ll;

    for(i=0; i < 15; i++)
    {
        cout << "Ingrese el dia: ";
        cin >> dia;

        cout << "Ingrese la temperatura: ";
        cin >> temp;

        cout << "Ingrese los milimetros de lluvia: ";
        cin >> mm_ll;

        cout << "Ingrese la visibilidad en km: ";
        cin >> v_km;
        cout << endl;

        //averigua temperatura m�xima, su d�a y la temperatura m�nima

        if(i == 0)
        {
            temp_max = temp;
            dia_t_max= dia;
        }
        else
        {
            if(temp > temp_max)
            {
                temp_max= temp;
                dia_t_max=dia;
            }
            else
            {
                if(ban_temp_min==1)
                {
                    temp_min=temp;
                    ban_temp_min=0;
                }
                else
                {
                    if(temp < temp_min)
                    {
                        temp_min=temp;
                    }
                }
            }
        }

        //averigua los dias de neblina y lluvia

        if(v_km < 2)
        {
            nebl++;
        }

        if(mm_ll > 0)
        {
            dia_ll++;
        }
        else
        {
            dia_n_ll++;
        }

    }

    //
    amplitud_term = temp_max - temp_min;

    //

    if(dia_ll > dia_n_ll)
    {
        est_ll = "Quincena lluviosa";
    }
    else
    {
        if(dia_ll == 5)
        {
            est_ll = "Quincena humeda";
        }
        else
        {
            est_ll = "Quincena seca";
        }
    }

    cout << "El d�a que se registro la temperatura maxima fue el: " << dia_t_max << endl;
    cout << "La amplitud termica de la quincena fue: " << amplitud_term << " grados" << endl;
    cout << "La cantidad de dias con neblina fue: " << nebl << endl;
    cout << "Por la cantidad de lluvias registradas fue una: " << est_ll << endl;


    return 0;
}
