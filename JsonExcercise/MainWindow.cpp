#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QJsonValue>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /*
    QFile f("E:/data2.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);

    QJsonObject o = d.object();
    foreach(QJsonValue x,o["users"].toArray())
    {
        qDebug() << (x.toObject())["name"].toString();
    }

    ui->setupUi(this);
    */

    QJsonObject jo;
    QJsonArray users;
    QJsonArray grades;
    grades.append(QJsonValue((double)15));
    grades.append(QJsonValue((double)18));
    QJsonObject b;
    QJsonObject address;
    b["Name"] = "Ali";
    b["Age"] = 23;
    b["Grades"] = grades;
    address["State"] = "Mazandaran";
    address["City"] = "Tonekabon";
    b["Address"] = address;
    users.append(b);
    jo["Users"] = users;
    QJsonDocument Jdoc(jo);
    QFile Jfile("E:/data.json");
    Jfile.open(QIODevice::WriteOnly);
    Jfile.write(Jdoc.toJson());
    Jfile.flush();
    Jfile.close();





}

MainWindow::~MainWindow()
{
    delete ui;
}

