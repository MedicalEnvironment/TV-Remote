#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include <QObject>

class RemoteControl : public QObject
{
Q_OBJECT

public:
    explicit RemoteControl(QObject *parent = nullptr);

public slots:
    void onChannelButtonClicked(int channel);
    void onNextChannelButtonClicked();
    void onPrevChannelButtonClicked();
    void onVolumeUpButtonClicked();
    void onVolumeDownButtonClicked();

signals:
    void updateDisplay(int channel, int volumePercent);

private:
    int currentChannel;
    int volumePercent;
};

#endif // REMOTECONTROL_H
