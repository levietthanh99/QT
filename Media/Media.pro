QT += quick dbus multimedia
CONFIG += c++17

# The following define makes your compiler emit warning if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += PROJECT_PATH=\"\\\"$${_PRO_FILE_PWD_}/\\\"\"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    ./src \
    ./src/common \
    ./src/controller \
    ./src/model \
    ./src/model/playback \
    ./src/service


RESOURCES += qml.qrc \
    images.qrc \
    localization.qrc

TRANSLATIONS += \
    localization/AppLanguage_en.ts \
    localization/AppLanguage_vi.ts


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DISTFILES +=

SOURCES += \
    src/appengine.cpp \
    src/controller/baseplayercontroller.cpp \
    src/controller/musiclistcontroller.cpp \
    src/controller/musicplayercontroller.cpp \
    src/controller/screencontroller.cpp \
    src/controller/translatorcontroller.cpp \
    src/main.cpp \
    src/model/musiclistmodel.cpp \
    src/model/playback/baseplaybackmodel.cpp \
    src/model/playback/musicplaybackmodel.cpp \
    src/model/playback/videoplaybackmodel.cpp \
    src/model/screenmodel.cpp \
    src/model/translatormodel.cpp

HEADERS += \
    src/appengine.h \
    src/common/appdefines.h \
    src/common/loghelper.h \
    src/controller/baseplayercontroller.h \
    src/controller/musiclistcontroller.h \
    src/controller/musicplayercontroller.h \
    src/controller/screencontroller.h \
    src/controller/translatorcontroller.h \
    src/model/musiclistmodel.h \
    src/model/playback/baseplaybackmodel.h \
    src/model/playback/musicplaybackmodel.h \
    src/model/playback/videoplaybackmodel.h \
    src/model/screenmodel.h \
    src/model/translatormodel.h
