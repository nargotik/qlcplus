/*
  Q Light Controller Plus
  dmx4all.h

  Copyright (C) Massimo Callegari

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef STAGEPROFI_H
#define STAGEPROFI_H

#include "dmxusbwidget.h"

class QLCFTDI;

class DMX4ALL : public DMXUSBWidget
{
    /************************************************************************
     * Initialization
     ************************************************************************/
public:
    DMX4ALL(const QString& serial, const QString& name, const QString& vendor,
                    QLCFTDI *ftdi = NULL, quint32 id = 0);
    virtual ~DMX4ALL();

    /** @reimp */
    DMXUSBWidget::Type type() const;

    /************************************************************************
     * Widget functions
     ************************************************************************/
public:
    /** @reimp */
    bool open();

    /** @reimp */
    QString uniqueName() const;

    /** @reimp */
    QString additionalInfo() const;

    /** @reimp */
    bool writeUniverse(const QByteArray& universe);

private:
    bool checkReply();
    bool sendChannelValue(int channel, uchar value);

private:
    QByteArray m_universe;
};

#endif
