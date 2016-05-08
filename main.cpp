#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "util.h"

double sumFun(double *in,double *mask,double state){
    state = 0;
    return (state += (*in)*(*mask));
}

int main(int argc, char *argv[])
{
    double *source = new double[10000];
    double *mask = new double[27*3];
    int pos = 0;
    for(int i = 0;i<10;i++)
        for(int z = 0;z<10;z++)
            for(int y = 0;y<10;y++)
                for(int x = 0;x<10;x++){
                    source[pos]=x+y*10+z*100+i*1000;
                    pos++;
                }
    pos =0;
    for(int i = 0;i<3;i++)
        for(int z = 0;z<3;z++)
            for(int y = 0;y<3;y++)
                for(int x = 0;x<3;x++){
                    mask[pos]=1;
                    pos++;
                }
    MyltidimensionOperation d(4,new int[4]{3,3,3,3},new int[4]{10,10,10,10});
    d.calc(source,mask,new int[4]{2,3,1,1},sumFun);

    if(true) return 0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
