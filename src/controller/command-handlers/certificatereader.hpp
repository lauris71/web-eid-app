/*
 * Copyright (c) 2020 The Web eID Project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "commandhandler.hpp"

#include <QSslCertificate>
#include <QUrl>

class CertificateReader : public CommandHandler
{
    Q_OBJECT

public:
    explicit CertificateReader(const CommandWithArguments& cmd);

    void run(electronic_id::CardInfo::ptr cardInfo) override;
    void connectSignals(const WebEidUI* window) override;

signals:
    void certificateReady(const QUrl& origin, const CertificateStatus certStatus,
                          const CertificateInfo& certInfo, const PinInfo& pinInfo);

protected:
    void validateAndStoreOrigin(const QVariantMap& arguments);

    QByteArray certificateDer;
    QSslCertificate certificate;
    electronic_id::CertificateType certificateType = electronic_id::CertificateType::NONE;
    QUrl origin;
};
