#include <QGuiApplication>
#include <mymodel.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MyModel myModel;

    if(!myModel.initialize()){
        return -1;
    }

    QObject::connect(&myModel,&MyModel::editList,&myModel,
                     &MyModel::onEditList);

    return app.exec();
}
