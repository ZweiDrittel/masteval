#include "datainput.h"
#include "ui_datainput.h"

DataInput::DataInput(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataInput)
{
    ui->setupUi(this);

    test *kleinerTest = new test(this);

    connect(ui->FileIn, SIGNAL(clicked()), this, SLOT(dasnTest()));
}

void DataInput::dasnTest()
{
    ui->setupUi(this);

    ui->TimeIn->setText("jups.");
}

DataInput::~DataInput()
{
    delete ui;
}


