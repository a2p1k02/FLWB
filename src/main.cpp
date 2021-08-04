#include "FLWB/mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#ifdef _WIN32
    #define <Windows.h>
#endif

int main(int argc, char* argv[])
{
    QApplication FLWB(argc, argv);

    QApplication::setApplicationName(QString("FLWB"));
    QApplication::setApplicationDisplayName(QString("Fast Web Browser"));
    QApplication::setApplicationVersion(QString("0.5"));

    QIcon icon;
    icon.addFile(QString(":/app/icon/src/FLWB/icon/FLWB.svg"), QSize(16, 16));
    icon.addFile(QString(":/app/icon/src/FLWB/icon/FLWB.svg"), QSize(24, 24));
    icon.addFile(QString(":/app/icon/src/FLWB/icon/FLWB.svg"), QSize(32, 32));
    icon.addFile(QString(":/app/icon/src/FLWB/icon/FLWB.svg"), QSize(48, 48));
    icon.addFile(QString(":/app/icon/src/FLWB/icon/FLWB.svg"), QSize(64, 64));
    icon.addFile(QString(":/app/icon/src/FLWB/icon/FLWB.svg"), QSize(96, 96));
    icon.addFile(QString(":/app/icon/src/FLWB/icon/FLWB.svg"), QSize(128, 128));
    icon.addFile(QString(":/app/icon/src/FLWB/icon/FLWB.svg"), QSize(256, 256));
    icon.addFile(QString(":/app/icon/src/FLWB/icon/FLWB.svg"), QSize(512, 512));
    FLWB.setWindowIcon(icon);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString& locale : uiLanguages) {
        const QString baseName = "FLWB_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            FLWB.installTranslator(&translator);
            break;
        }
    }

#ifdef _WIN32
    FreeConsole();
#endif

    MainWindow FLWB_Win;

    FLWB_Win.show();
    return FLWB.exec();
}
