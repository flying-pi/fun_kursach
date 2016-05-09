#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTime>
#include "util.h"

#include "neuralCore/layer.h"
#include "neuralCore/sigmodneuron.h"

double sumFun(double *in,double *mask,double state){
    return (state += (*in)*(*mask));
}

int tort1(){
    double *source = new double[10000];
    double *mask = new double[2*3*4*5];
    int pos = 0;
    for(int i = 0;i<10;i++)
        for(int z = 0;z<10;z++)
            for(int y = 0;y<10;y++)
                for(int x = 0;x<10;x++){
                    source[pos]=x+y*10+z*100+i*1000;
                    pos++;
                }
    pos =0;
    for(int i = 0;i<2;i++)
        for(int z = 0;z<3;z++)
            for(int y = 0;y<4;y++)
                for(int x = 0;x<5;x++){
                    mask[pos]=1;
                    pos++;
                }
    MyltidimensionOperation d(new Vector(4,new int[4]{2,3,4,5}),new Vector(4,new int[4]{10,10,10,10}));
    d.setOffsetPoint(new int[4]{1,1,1,1});
    d.calc(source,mask,sumFun);
    return 1;
}

void tort2(){
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    double *in = new double[2];
    Layer * inLayout = new Layer(1,new int[1]{2},1,new int[1]{2});
    inLayout->addFullConnectedNeuron(SigmodNeuron::createItem);
    for(int i=0;i<1000;i++){
        in[0] =qrand()%2==0;
        in[1] =qrand()%2==1;
        inLayout->nextStep(in);
        inLayout->getOut();
    }

}

int main(int argc, char *argv[])
{
//    tort1();
    tort2();
    if(true) return 0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
