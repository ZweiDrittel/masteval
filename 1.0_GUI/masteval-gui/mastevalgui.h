#ifndef MASTEVALGUI_H
#define MASTEVALGUI_H

#include <QMainWindow>



namespace Ui {
class mastevalGUI;
}

class mastevalGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit mastevalGUI(QWidget *parent = 0);
    ~mastevalGUI();

private slots:
    point_in_time *setTo(point_in_time *time);

    point_in_time *nextMinute(point_in_time *time);

    int sameTime(point_in_time time1, point_in_time time2);

    void printHeader();

    int openInputFile(FILE *input_file);

    void readInputFile();

    void cutString(char *input);

    int openDataFile(FILE *data_file);

    void getInspectionTime(point_in_time *date);

    void printTime(point_in_time *time);

    void readLine(FILE *data_file, point_in_time *t, float *v, float *dd, float *T);

    void test();

private:
    Ui::mastevalGUI *ui;
};

#endif // MASTEVALGUI_H
