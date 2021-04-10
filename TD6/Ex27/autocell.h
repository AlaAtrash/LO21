#ifndef AUTOCELL_H
#define AUTOCELL_H
#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include <QString>
#include <QVBoxLayout>


class AutoCell : public QWidget {
    Q_OBJECT
    QSpinBox* num; // numéro
    QLineEdit* numeroBit[8]; // un QLineEdit par bit
    QLabel* numl;
    QLabel* numeroBitl[8];
    QVBoxLayout* numc;
    QVBoxLayout* bitc[8];
    QHBoxLayout* numeroc;
    QIntValidator* zeroOneValidator;
    unsigned int dimension = 25;


    public:
        explicit AutoCell(QWidget* parent = nullptr);
    private slots:
        void synchronizeNumToNumBit(int i);
        void synchronizeNumBitToNum(const QString& s);
        void cellActivation (const QModelIndex& index);
};
#endif // AUTOCELL_H
