#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget fenetre;
    fenetre.setFixedSize(150, 110);

    /*
    QLabel numl("Numéro", &fenetre);
    QLabel numeroBitl("NuméroBit", &fenetre);


    QLineEdit num(&fenetre);

    QLineEdit numeroBit(&fenetre);

    QPushButton ok ("ok", &fenetre);

    QHBoxLayout h1(&fenetre);
    h1.addWidget(&numl);
    h1.addWidget(&num);

    QHBoxLayout h2 (&fenetre);
    h2.addWidget(&numeroBitl);
    h2.addWidget(&numeroBit);

    QHBoxLayout h3 (&fenetre);
    h3.addWidget(&ok);

    QVBoxLayout v (&fenetre);
    v.addLayout(&h1);
    v.addLayout(&h2);
    v.addLayout(&h3);

    fenetre.setLayout(&v);


    */

    QLabel* num1 = new QLabel("numéro");
    QLabel* numbit1 = new QLabel("numérobit");
    QLineEdit* num = new QLineEdit();
    QLineEdit* numbit = new QLineEdit();
    QPushButton* ok = new QPushButton("ok");


    QHBoxLayout *layout1 = new QHBoxLayout;
   layout1->addWidget(num1);
   layout1->addWidget(num);

   QHBoxLayout *layout2 = new QHBoxLayout;
   layout2->addWidget(numbit1);
   layout2->addWidget(numbit);

   QVBoxLayout* layoutv = new QVBoxLayout;
   layoutv->addLayout(layout1);
   layoutv->addLayout(layout2);
   layoutv->addWidget(ok);

   fenetre.setLayout(layoutv);

    fenetre.show();
    return app.exec();
}
