#ifndef CLASSFILE_H
#define CLASSFILE_H
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <headers/classfile.h>


class ClassFile: public QFile
{
public:
    void addFile(QString x);
    void addTOFile(QString x);
    void deleteFromFile();
    QStringList readFile();
private:
    QFile file;

};

#endif // CLASSFILE_H
