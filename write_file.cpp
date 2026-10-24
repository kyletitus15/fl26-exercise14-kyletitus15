// write_file.cpp
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QString>
#include <QList>

#include "file_header.h"
  
int main(int argc, char *argv[])
{
  QFile file("temp.dat");
  if (!file.open(QIODevice::WriteOnly)) {
    qDebug() << "Error";
    return EXIT_FAILURE;
  }

  // treat the file as consuming a data stream
  QDataStream out(&file);

  // Write a header with a magic number and a version
  out << MAGIC;
  out << VERSION;

  // use a specific streaming format
  out.setVersion(QDataStream::Qt_5_0);
  
  // write some data
  QList<QString> list;
  list << "Test" << "Test" << "Testttt.";
  out << list;
  
  // notify the user that we're finished
  qDebug() << "A data stream has been written to a file.";  
  
  return EXIT_SUCCESS;
}
