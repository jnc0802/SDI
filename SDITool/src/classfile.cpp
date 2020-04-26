#include "headers/classfile.h"




void ClassFile::addFile(QString x)
{
    file.setFileName(x);
    qDebug()<<"File added!";
}

void ClassFile::addTOFile(QString x)
{

    if(!file.exists()){
        qDebug()<<"No File Detected";
    }
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream fileOut(&file);
    fileOut << x << endl;
    file.close();

}

QStringList ClassFile::readFile()
{
    //returns the current state of the text file
    QStringList classes;
    QString line;
    if(!file.exists()){
        qDebug()<<"No File Detected";
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    while(!file.atEnd()){
        line = file.readLine();
        classes << line;
    }
    file.close();
    return classes;
}
