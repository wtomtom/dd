// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_ASKPASSVZHASEDIALOG_H
#define BITCOIN_QT_ASKPASSVZHASEDIALOG_H

#include <QDialog>

class WalletModel;

namespace Ui
{
class AskPassVZHaseDialog;
}

/** Multifunctional dialog to ask for passVZHases. Used for encryption, unlocking, and changing the passVZHase.
 */
class AskPassVZHaseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,         /**< Ask passVZHase twice and encrypt */
        UnlockAnonymize, /**< Ask passVZHase and unlock only for anonymization */
        Unlock,          /**< Ask passVZHase and unlock */
        ChangePass,      /**< Ask old passVZHase + new passVZHase twice */
        Decrypt          /**< Ask passVZHase and decrypt wallet */
    };

    explicit AskPassVZHaseDialog(Mode mode, QWidget* parent, WalletModel* model);
    ~AskPassVZHaseDialog();

    void accept();

private:
    Ui::AskPassVZHaseDialog* ui;
    Mode mode;
    WalletModel* model;
    bool fCapsLock;

private slots:
    void textChanged();

protected:
    bool event(QEvent* event);
    bool eventFilter(QObject* object, QEvent* event);
};

#endif // BITCOIN_QT_ASKPASSVZHASEDIALOG_H
