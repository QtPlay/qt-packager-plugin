#ifndef PACKAGERPLUGIN_H
#define PACKAGERPLUGIN_H

#include <QObject>
#include "packager.h"

class PackagerPlugin : public PackagerInterface
{
    Q_OBJECT
    Q_INTERFACES(PackagerInterface)

public:
    PackagerPlugin(QObject * parent = 0);
    ~PackagerPlugin();

    QString name() const;
    QString version() const;
    void setDefaultParameters();

    bool pack(const QString &path, const QString &name);
    bool unpack(const QString &name, const QString &path);
};

#endif // PACKAGERPLUGIN_H
