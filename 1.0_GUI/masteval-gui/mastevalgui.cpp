#include "mastevalgui.h"
#include "ui_mastevalgui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int __PI = 3.14159265358979323846;

typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
}point_in_time;

//Funktion, um Kopie von time zurückzugeben
point_in_time* mastevalGUI::setTo(point_in_time *time)
{
    point_in_time *another_time = NULL;
    another_time = (point_in_time*)malloc(sizeof(point_in_time));
    another_time->year = time->year;
    another_time->month = time->month;
    another_time->day = time->day;
    another_time->hour = time->hour;
    another_time->minute = time->minute;
    another_time->second = time->second;
    return another_time;
}

//Funktion, um nächste Minute nach time zurückzugeben
point_in_time *mastevalGUI::nextMinute(point_in_time *time)
{
    point_in_time *another_time = NULL;
    another_time = (point_in_time*)malloc(sizeof(point_in_time));
    another_time = setTo(time);
    //Check, ob Stundenende
    if(another_time->minute < 59)
    {
        another_time->minute = another_time->minute + 1;
    }
    else
    {
        //Stundenende erreicht
        another_time->minute = 0;
        //Check, ob Tagesende
        if(another_time->hour < 23)
        {
            another_time->hour = another_time->hour + 1;
        }
        else
        {
            //Tagesende erreicht
            another_time->hour = 0;
            //Check, ob Monatsende
            if((another_time->month == 1 && another_time->day < 31) ||
               (another_time->month == 2 && another_time->day < 28) ||
               (another_time->month == 3 && another_time->day < 31) ||
               (another_time->month == 4 && another_time->day < 30) ||
               (another_time->month == 5 && another_time->day < 31) ||
               (another_time->month == 6 && another_time->day < 30) ||
               (another_time->month == 7 && another_time->day < 31) ||
               (another_time->month == 8 && another_time->day < 31) ||
               (another_time->month == 9 && another_time->day < 30) ||
               (another_time->month == 10 && another_time->day < 31)||
               (another_time->month == 11 && another_time->day < 30)||
               (another_time->month == 12 && another_time->day < 31))
            {
                another_time->day = another_time->day + 1;
            }
            else
            {
                //Monatsende erreicht
                another_time->day = 1;
                //Check, on Jahresende
                if(another_time->month < 12)
                {
                    another_time->month = another_time->month + 1;
                }
                else
                {
                    //Jahresende erreicht
                    another_time->month = 1;
                    another_time->year = another_time->year + 1;
                }
            }
        }
    }
    return another_time;
}

//Funktion, die zwei Zeitpunkte vergleicht
//gibt 0 zurück, wenn nicht gleich
//gibt 1 zurück, wenn gleich
int mastevalGUI::sameTime(point_in_time time1, point_in_time time2)
{
    if(time1.year == time2.year &&
       time1.month == time2.month &&
       time1.day == time2.day &&
       time1.hour == time2.hour &&
       time1.minute == time2.minute &&
       time1.second == time2.second)
       return 1;
   else
       return 0;
}

//Header erstellen, um Übersichtlichkeit zu gewährleisten
void mastevalGUI::printHeader()
{
    printf("\n################################################################\n"
           "# Programm zur Auswertung von Messmastdaten bei Rasterbegehung #\n"
           "#      Version 1.0 - Barth & Bitter GmbH, den 08.09.2016       #\n"
           "################################################################\n\n");
}

//Funktion, um Inputdatei zu finden und zu öffnen
//Funktion wird nicht verwendet, da ohne Inputdatei gearbeitet wird
int mastevalGUI::openInputFile(FILE *input_file)
{
    printf("Liegt die zu verwendende Konfigurations-Datei "
           "\"masteval_input.txt\"\nim Ordner S:\\User\\Ra"
           "\\Programme\\C\\masteval\\ ?\n(J/n): ");
    char *file_exist = NULL;
    file_exist = (char*)malloc(sizeof(char));
    scanf("%s", file_exist);
    if(*file_exist == 'J' || *file_exist == 'j')
    {
        input_file = fopen("S:\\User\\Ra\\Programme\\C\\masteval\\masteval_input.txt", "r");
        while(input_file == NULL)
        {
        //Fehler beim Öffnen der Datei
            printf("Datei konnte nicht geöffnet werden...\n"
                   "Mit anderem Dateipfad erneut versuchen? (J/n): ");
            free(file_exist);
            file_exist = (char*)malloc(sizeof(char));
            scanf("%s", file_exist);
            if(*file_exist == 'J' || *file_exist == 'j')
            {
                char input_path[100];
                printf("\nPfad der Datei \"masteval_input.txt\" angeben: ");
                scanf("%s", input_path);
                strcat(input_path, "\\masteval_input.txt");
                input_file = fopen(input_path, "r");
            }
            else
            {
                printf("Programm wird beendet...");
                return 1;
            }
        }
        printf("Konfigurationsdatei erfolgreich geöffnet!\n");
    }
    else
    {
        char input_path[100];
        printf("\nPfad der Datei \"masteval_input.txt\" angeben: ");
        scanf("%s", input_path);
        strcat(input_path, "\\masteval_input.txt");
        input_file = fopen(input_path, "r");
        while(input_file == NULL)
        {
        //Fehler beim Öffnen der Datei
            printf("Datei konnte nicht geöffnet werden...\n"
                   "Mit anderem Dateipfad erneut versuchen? (J/n): ");
            free(file_exist);
            file_exist = (char*)malloc(sizeof(char));
            scanf("%s", file_exist);
            if(*file_exist == 'J' || *file_exist == 'j')
            {
                char input_path[100];
                printf("\nPfad der Datei \"masteval_input.txt\" angeben: ");
                scanf("%s", input_path);
                strcat(input_path, "\\masteval_input.txt");
                input_file = fopen(input_path, "r");
            }
            else
            {
                printf("Programm wird beendet...");
                return 1;
            }
        }
        printf("Konfigurationsdatei erfolgreich geöffnet!\n");
    }
    return 0;
}

//Funktion, um aus Inputdatei zu lesen
//nicht implementiert, da nicht benötigt
void mastevalGUI::readInputFile()
{

}

//Funktion, um Eingabe zu cutten
void mastevalGUI::cutString(char *input)
{
    if ((strlen(input)>0) && (input[strlen (input) - 1] == '\n'))
        input[strlen (input) - 1] = '\0';
}

//Funktion, um Rohdatendatei zu finden und zu öffnen
int mastevalGUI::openDataFile(FILE *data_file)
{
    printf("Bitte den Dateipfad (incl. Datei und Dateiendung) der Rohdaten angeben!\n\n"
           "Wichtig: Eingabe in \"\" setzen, wenn Pfad Leerzeichen enthaelt!\n\n"
           "(Beispiel: \"S:\\Aktuell\\Proj16\\16037_AWG_Bassum.GB\\Meteorologie\\Daten der Station\\Bassum_160906.dat\"):\n");
    int const max_length = 256;
    char data_path[max_length];
    fgets(data_path, max_length, stdin);
    cutString(data_path);
    printf("%s", data_path);
    data_file = fopen(data_path, "r");
    while(data_file == NULL)
    {
        printf("\nDatei konnte nicht geoeffnet werden... Erneut versuchen? (J/n): ");
        char try_again;
        scanf("%s", &try_again);
        if(try_again == 'J' || try_again == 'j')
        {
            printf("\n\nBitte den Dateipfad (incl. Datei und Dateiendung) der Rohdaten"
                   " angeben!:\n");
            scanf("%s", data_path);
            data_file = fopen(data_path, "r");
        }
        else
        {
            printf("\nProgramm wird beendet...\n");
            return 1;
        }
    }
    printf("\nDatei erfolgreich geoeffnet!\n");
    return 0;
}

//Funktion, um Beginn des 10-minütigen Messzeitraums zu bestimmen
void mastevalGUI::getInspectionTime(point_in_time *date)
{
    printf("\n\nBitte Zeitpunkt des Beginns der 10-minuetigen Messung eingeben.\n"
           "Format dd.mm.yyyy hh:mm einhalten: ");
    scanf("%2d.%2d.%4d %2d:%2d", &(date->day), &(date->month), &(date->year),
                                 &(date->hour), &(date->minute));
    date->second = 0;
}

//Funktion, um Zeitpunkt auf Konsole auszugeben
void mastevalGUI::printTime(point_in_time *time)
{
    printf("%02d.%02d.%04d %02d:%02d:%02d\n", time->day, time->month, time->year,
                                      time->hour, time->minute, time->second);
}

//Funktion, die Zeile aus Rohdaten-Datei liest
void mastevalGUI::readLine(FILE *data_file, point_in_time *t, float *v, float *dd, float *T)
{
    fscanf(data_file, "%2d.%2d.%4d %2d:%2d:%2d %f %*f %*f %*f %f %*f %*f %*f %f %*f %*f",
                 &(t->day), &(t->month), &(t->year),
                 &(t->hour), &(t->minute), &(t->second),
                 v, dd, T);
}

mastevalGUI::mastevalGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mastevalGUI)
{
    ui->setupUi(this);

    connect(ui->FileIn, SIGNAL(clicked()), this, SLOT(test()));

    printHeader();

    FILE *data_file = NULL;
    //Öffnet die gewollte Datei!
    //Funktioniert nicht, wenn in Funktion ausgelagert....WIESO!?
    printf("Bitte den Dateipfad (incl. Datei und Dateiendung) der Rohdaten angeben!\n\n"
           "(Beispiel: S:\\Aktuell\\Proj16\\16037_AWG_Bassum.GB\\Meteorologie\\Daten der Station\\Bassum_160906.dat):\n");
    int const max_length = 256;
    char data_path[max_length];
    fgets(data_path, max_length, stdin);
    cutString(data_path);
    data_file = fopen(data_path, "r");
    while(data_file == NULL)
    {
        printf("\nDatei konnte nicht geoeffnet werden... Erneut versuchen? (J/n): ");
        char try_again;
        scanf("%s", &try_again);
        if(try_again == 'J' || try_again == 'j')
        {
            printf("\n\nBitte den Dateipfad (incl. Datei und Dateiendung) der Rohdaten"
                   " angeben!:\n");
            fgets(data_path, max_length, stdin);
            cutString(data_path);
            data_file = fopen(data_path, "r");
        }
        else
        {
            printf("\nProgramm wird beendet...\n");
            return;
        }
    }
    printf("\n###########################################################\n"
           "#############  Datei erfolgreich geoeffnet!  ##############\n"
           "###########################################################\n");
////////////////////////////////////////////////////////////////////////
//////Data-Datei erfolgreich geöffnet - check
////////////////////////////////////////////////////////////////////////

    //Pfad für Output-Dateien abfragen
    FILE *output_file1 = NULL;
    FILE *output_file10 = NULL;
    //Öffnet die gewollte Datei!
    //Funktioniert nicht, wenn in Funktion ausgelagert....WIESO!?
    printf("\nBitte den Ordner angeben, in welchem die Ergebnisse abgelegt werden sollen!\n\n"
           "(Beispiel: S:\\Aktuell\\Proj16\\16037_AWG_Bassum.GB\\Meteorologie):\n");
    fgets(data_path, max_length, stdin);
    cutString(data_path);
    char output_path1[max_length];
    char output_path10[max_length];
    strcpy(output_path1, data_path);
    strcpy(output_path10, data_path);
    strcat(output_path1, "\\1-Minutenwerte_Begehung.txt");
    strcat(output_path10, "\\10-Minutenwerte_Begehung.txt");
    output_file1 = fopen(output_path1, "a+");
    output_file10 = fopen(output_path10, "a+");
    while(output_file1 == NULL || output_file10 == NULL)
    {
        printf("Datei konnte nicht geoeffnet werden. Erneut Pfad eingeben? (J/n): ");
        char try_again;
        scanf("%s", &try_again);
        if(try_again == 'J' || try_again == 'j')
        {
            printf("Bitte den Ordner angeben, in welchem die Ergebnisse abgelegt werden sollen: ");
            fgets(data_path, max_length, stdin);
            cutString(data_path);
            strcpy(output_path1, data_path);
            strcpy(output_path10, data_path);
            strcat(output_path1, "\\1-Minutenwerte_Begehung.txt");
            strcat(output_path10, "\\10-Minutenwerte_Begehung.txt");
            output_file1 = fopen(output_path1, "a+");
            output_file10 = fopen(output_path10, "a+");
        }
        else
        {
            printf("\nProgramm wird beendet...\n");
            return;
        }
    }

////////////////////////////////////////////////////////////////////////
//////Output-Dateien erfolgreich geöffnet - check
////////////////////////////////////////////////////////////////////////

    //Daten für bestimmte Zeiten auslesen, bis der Nutzer nicht mehr möchte
    int go_on = 1;

    while(go_on)
    {
        //Abfragen, welche Daten ausgewertet werden sollen
        point_in_time *start_of_inspection = (point_in_time*)malloc(sizeof(point_in_time));
        getInspectionTime(start_of_inspection);
        point_in_time *navigation_time;
        navigation_time = setTo(start_of_inspection);

        point_in_time time[10];
        float v[10];
        float dd[10];
        float T[10];

        //Schleife über 10 Minuten, die eingelesen werden sollen
        for(int i=0; i<10; i++)
        {
            readLine(data_file, &(time[i]), &(v[i]), &(dd[i]), &(T[i]));
            if(sameTime(*navigation_time, time[i]))
                //Zeitpunkt stimmt überein! Gesuchte Daten gefunden
                navigation_time = nextMinute(navigation_time);
            else
                //Zeitpunkt nicht gefunden, nächste Zeile einlesen
                i--;
        }

        //Die 10 gesuchten Minuten wurden gefunden.
        //Mittel bilden und in Datei schreiben.
        float v_mit = 0.0;
        float v_min = v[0];
        float v_max = v[0];
        float dd_mit = 0.0;
        float dd_min = 0.0;
        float dd_max = 0.0;
        float T_mit = 0.0;
        float T_min = T[0];
        float T_max = T[0];

        //Mittel bilden und min/max finden für v und T
        for(int i=0; i<10; i++)
        {
            v_mit += v[i];
            T_mit += T[i];
            if(v[i] < v_min)
                v_min = v[i];

            if(v[i] > v_max)
                v_max = v[i];

            if(T[i] < T_min)
                T_min = T[i];

            if(T[i] > T_max)
                T_max = T[i];
        }
        v_mit /= 10.0;
        T_mit /= 10.0;


        //Mittel und min/max von dd bilden
        double u_comp = 0.0;
        double v_comp = 0.0;
        double angle = 0.0;

        for(int i=0; i<10; i++)
        {
            u_comp += sin(dd[i] * __PI / 180.0);
            v_comp += cos(dd[i] * __PI / 180.0);
        }
        u_comp /= 10.0;
        v_comp /= 10.0;

        angle = atan(fabs(u_comp) / fabs(v_comp)) * 180.0 / __PI;
        if(u_comp >= 0.0 && v_comp >= 0.0)
            dd_mit = angle;
        else if(u_comp >= 0.0 && v_comp < 0.0)
            dd_mit = 180.0 - angle;
        else if(u_comp < 0.0 && v_comp >= 0.0)
            dd_mit = 360 - angle;
        else if(u_comp < 0.0 && v_comp < 0.0)
            dd_mit = 180 + angle;



////////////Alle Daten da, jetzt schreiben////////////////
        //Daten in Dateien schreiben
        for(int i=0; i<10; i++)
        {
            fprintf(output_file1, "%02d.%02d.%04d %02d:%02d:%02d    %.3f    %.3f    %.3f\n",
                    time[i].day, time[i].month, time[i].year, time[i].hour,
                    time[i].minute, time[i].second, v[i], dd[i], T[i]);
        }
        fprintf(output_file10, "%02d.%02d.%04d %02d:%02d:%02d    %.3f    %.3f    %.3f"
                            "    %.3f    %.3f    %.3f    %.3f    %.3f    %.3f\n",
                    start_of_inspection->day, start_of_inspection->month,
                    start_of_inspection->year, start_of_inspection->hour,
                    start_of_inspection->minute, start_of_inspection->second,
                    v_mit, v_min, v_max, dd_mit, dd_min, dd_max, T_mit, T_min, T_max);

        printf("\n######################################################\n"
               "########  Daten gemittelt und abgespeichert.  ########\n"
               "######################################################\n");

        //Abfragen, ob noch ein Zeitpunkt eingegeben werden soll
        printf("\nSoll ein weiterer Zeitpunkt ausgewertet werden? (J/n): ");
        char read_again;
        scanf("%s", &read_again);
        if(read_again == 'J' || read_again == 'j')
        {
            //weiterer Zeitpunkt soll eingelesen werden
            //Datei muss auf Anfang zurückgespult werden
            go_on = 1;
            rewind(data_file);
        }
        else
        {
            go_on = 0;
            printf("\nEinlesen beendet, Programm wird geschlossen!\n");
        }
    }

    fclose(output_file1);
    fclose(output_file10);
    fclose(data_file);

}

void mastevalGUI::test()
{
    ui->TimeIn->setText("jups.");
}

mastevalGUI::~mastevalGUI()
{
    delete ui;
}
