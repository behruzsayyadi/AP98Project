QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Classes/Car.cpp \
    Classes/Cheque.cpp \
    Classes/CityCar.cpp \
    Classes/Customer.cpp \
    Classes/Document.cpp \
    Classes/Exhibition.cpp \
    Classes/Human.cpp \
    Classes/Manager.cpp \
    Classes/Memorandum.cpp \
    Classes/SUV.cpp \
    Classes/Seller.cpp \
    Classes/SportCar.cpp \
    UI/MainWindow.cpp \
    UI/Page_Cars.cpp \
    UI/Page_Finance.cpp \
    UI/Widget_signin.cpp \
    UI/Widget_signup.cpp \
    main.cpp

HEADERS += \
    Classes/Car.h \
    Classes/Cheque.h \
    Classes/CityCar.h \
    Classes/Customer.h \
    Classes/Document.h \
    Classes/Exhibition.h \
    Classes/Human.h \
    Classes/Manager.h \
    Classes/Memorandum.h \
    Classes/SUV.h \
    Classes/Seller.h \
    Classes/SportCar.h \
    UI/MainWindow.h \
    UI/Page_Cars.h \
    UI/Page_Finance.h \
    UI/Widget_signin.h \
    UI/Widget_signup.h

FORMS += \
    UI/MainWindow.ui \
    UI/Page_Cars.ui \
    UI/Page_Finance.ui \
    UI/Widget_signin.ui \
    UI/Widget_signup.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
