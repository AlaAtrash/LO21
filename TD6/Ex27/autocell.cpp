#include "autocell.h"
#include "automate.h"

AutoCell::AutoCell(QWidget* parent):QWidget(parent) {
    num = new QSpinBox;
    num->setRange(0, 255);
    num->setValue(0);

    numl = new QLabel("Numéro");
    numc = new QVBoxLayout;
    numc->addWidget(numl);
    numc->addWidget(num);

    numeroc = new QHBoxLayout;
    numeroc->addLayout(numc);

    zeroOneValidator = new QIntValidator;
    zeroOneValidator->setRange(0, 1);


    for (int i = 0; i < 8; i++) {
        numeroBit[i] = new QLineEdit;
        numeroBit[i]->setFixedWidth(20);
        numeroBit[i]->setMaxLength(1);
        numeroBit[i]->setText("0");
        numeroBit[i]->setValidator(zeroOneValidator);

        numeroBitl[i] = new QLabel;
        bitc[i] = new QVBoxLayout;
        bitc[i]->addWidget(numeroBitl[i]);
        bitc[i]->addWidget(numeroBit[i]);
        numeroc->addLayout(bitc[i]);
    }
    numeroBitl[0]->setText("000");
    numeroBitl[1]->setText("001");
    numeroBitl[2]->setText("010");
    numeroBitl[3]->setText("011");
    numeroBitl[4]->setText("100");
    numeroBitl[5]->setText("101");
    numeroBitl[6]->setText("110");
    numeroBitl[7]->setText("111");
    setLayout(numeroc);

    connect(num, SIGNAL(valueChanged(int)), this, SLOT(synchronizeNumToNumBit(int)));
    for (int i = 0; i < 8; i++) {
        connect(numeroBitl[i], SIGNAL(textChanged(QString&)), this, SLOT(synchronizeNumBitToNum(const QString)));
    }
}

void AutoCell::synchronizeNumToNumBit(int i) {
    std::string numbit = NumToNumBit(i);
    for (int i = 0; i < 8; i++) {
        numeroBit[i]->setText(QString(numbit[i]));
    }
}

void AutoCell::synchronizeNumBitToNum(const QString& s) {
    std::string str;
    for (int i = 0; i < 8; i++) {
        str += numeroBit[i]->text().toLatin1();
    }
    int i = NumBitToNum(str);
    num->setValue(i);
}


