#include <QApplication>
#include <QPushButton>
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);


    QPushButton bouton("Quitter");
    bouton.show();

    QPushButton b2 ("coucou, ceci est un nouveau bouton à déplacer");
    b2.show();

    QObject::connect(&bouton, SIGNAL(clicked()), qApp, SLOT(quit()));
    return app.exec();
}
