#ifndef QCALCULATORMODEL_H
#define QCALCULATORMODEL_H

#include <QObject>

class QCalculatorModel : public QObject
{
    Q_OBJECT
public:
    explicit QCalculatorModel(QObject *parent = nullptr);

signals:

};

#endif // QCALCULATORMODEL_H
