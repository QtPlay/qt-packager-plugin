#include "packagerplugin.h"

#include <QFileInfo>

PackagerPlugin::PackagerPlugin(QObject *parent) :
    PackagerInterface(parent)
{
}

Q_EXPORT_PLUGIN2(PackagerPlugin, PackagerPlugin)

PackagerPlugin::~PackagerPlugin()
{
}

QString PackagerPlugin::name() const
{
    return "PackagerPlugin";
}

QString PackagerPlugin::version() const
{
    return "1.0";
}

void PackagerPlugin::setDefaultParameters()
{

}

bool PackagerPlugin::pack(const QString &path, const QString &name)
{
    QFile *file = new QFile(name);
    if (!file->open(QIODevice::WriteOnly)) {
        return false;
    }

    int size = 1048576;
    for (int i = 0; i < 20; i++) {
        char *data = new char[size];
        memset(data,'-',size);
        file->seek(i*size);
        file->write(reinterpret_cast<const char*>(data), size);
        delete[] data;
    }

    file->close();

    return true;
}

bool PackagerPlugin::unpack(const QString &name, const QString &path)
{
    int size = 1048576;
    for (int i = 0; i < 5; i++) {
        QString filename = path + "/" + "output_" + QString::number(i);
        QFile *file = new QFile(filename);
        if (file->open(QIODevice::WriteOnly)) {
            char *data = new char[size];
            memset(data,'-',size);
            file->write(reinterpret_cast<const char*>(data), size);
            delete[] data;
        }
        file->close();
    }

    return true;
}
