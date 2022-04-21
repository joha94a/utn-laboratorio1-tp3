//Nombre: Johana Araya
//TP N°:
//Ejercicio N°: 17
/*Una estación meteorológica registró una muestra climática de los últimos 15 días. Por cada día registró:
Número de día (entero)
Temperatura (float)
Milímetros de lluvia (float)
Visibilidad en km (float)

Hay un registro por cada día. La información se encuentra ordenada por día. Se pide calcular e informar:
El número de día que se haya registrado la temperatura máxima.
La amplitud térmica de todo el período.
La cantidad de días con neblina.
Mostrar "Quincena lluviosa" si hubo más días de lluvia que días sin lluvia. Mostrar "Quincena húmeda"
 si llovió al menos un tercio de los días. De lo contrario mostrar "Quincena seca".

NOTA: La amplitud térmica es la diferencia entre la temperatura máxima y la temperatura mínima.
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

        //averigua temperatura máxima, su día y la temperatura mínima

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

    cout << "El día que se registro la temperatura maxima fue el: " << dia_t_max << endl;
    cout << "La amplitud termica de la quincena fue: " << amplitud_term << " grados" << endl;
    cout << "La cantidad de dias con neblina fue: " << nebl << endl;
    cout << "Por la cantidad de lluvias registradas fue una: " << est_ll << endl;


    return 0;
}
