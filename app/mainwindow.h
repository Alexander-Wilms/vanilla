#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QProcess>
#include <QPushButton>
#include <QSplitter>
#include <QWidget>
#include <SDL2/SDL_gamecontroller.h>

#include "audiohandler.h"
#include "backend.h"
#include "gamepadhandler.h"
#include "videodecoder.h"
#include "viewer.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() override;

private:
    void populateWirelessInterfaces();
    void populateMicrophones();
    void populateControllers();

    void startObjectOnThread(QObject *object);

    Viewer *m_viewer;

    QComboBox *m_wirelessInterfaceComboBox;
    QComboBox *m_microphoneComboBox;
    QComboBox *m_controllerComboBox;
    QProcess *m_process;

    QPushButton *m_syncBtn;
    QPushButton *m_connectBtn;

    QSplitter *m_splitter;

    Backend *m_backend;
    VideoDecoder *m_videoDecoder;
    GamepadHandler *m_gamepadHandler;
    AudioHandler *m_audioHandler;

    QMap<QObject *, QThread *> m_threadMap;

    QPushButton *m_controllerMappingButton;

private slots:
    void showSyncDialog();

    void setConnectedState(bool on);

    void setJoystick(int index);

    void setFullScreen();
    void exitFullScreen();

    void volumeChanged(int val);

    void showInputConfigDialog();

};

#endif // MAINWINDOW_H
