#include "remotecontrol.h"

RemoteControl::RemoteControl(QObject *parent) : QObject(parent)
{
    currentChannel = 1; // Start with channel 1
    volumePercent = 50; // Start with 50% volume
}

void RemoteControl::onChannelButtonClicked(int channel)
{
    currentChannel = channel;
    emit updateDisplay(currentChannel, volumePercent);
}

void RemoteControl::onNextChannelButtonClicked()
{
    currentChannel++;
    emit updateDisplay(currentChannel, volumePercent);
}

void RemoteControl::onPrevChannelButtonClicked()
{
    currentChannel--;
    emit updateDisplay(currentChannel, volumePercent);
}

void RemoteControl::onVolumeUpButtonClicked()
{
    volumePercent += 10;
    if (volumePercent > 100)
        volumePercent = 100;
    emit updateDisplay(currentChannel, volumePercent);
}

void RemoteControl::onVolumeDownButtonClicked()
{
    volumePercent -= 10;
    if (volumePercent < 0)
        volumePercent = 0;
    emit updateDisplay(currentChannel, volumePercent);
}
