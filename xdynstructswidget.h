// copyright (c) 2021 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef XDYNSTRUCTSWIDGET_H
#define XDYNSTRUCTSWIDGET_H

#include <QWidget>
#include "xdynstructsengine.h"
#include "xhtml.h"
#include "dialoghexview.h"
#include "xshortcutswidget.h"

namespace Ui {
class XDynStructsWidget;
}

class XDynStructsWidget : public XShortcutsWidget
{
    Q_OBJECT

    struct PAGE
    {
        qint64 nAddress;
        QString sStructName;
        QString sText;
    };

    enum VT
    {
        VT_HEX=0,
        VT_DISASM
    };

public:
    explicit XDynStructsWidget(QWidget *pParent=nullptr);
    void setData(XDynStructsEngine *pStructsEngine, qint64 nAddress);
    ~XDynStructsWidget();

private slots:
    bool reload(QString sStruct);
    void onAnchorClicked(const QUrl &sLink);
    void on_pushButtonStructsReload_clicked();
    void addPage(XDynStructsWidget::PAGE page);
    XDynStructsWidget::PAGE getCurrentPage();
    void on_pushButtonStructsBack_clicked();
    void on_pushButtonStructsForward_clicked();
    void adjustPagesStatus();
    bool adjustComboBox(QString sStructName);
    void restorePage();
    void showViewer(qint64 nAddress,VT vt);

protected:
    virtual void registerShortcuts(bool bState);

signals:
    void showHex(qint64 nAddress);

private:
    Ui::XDynStructsWidget *ui;
    bool g_bAddPageEnable;
    QList<PAGE> g_listPages;
    qint32 g_nPageIndex;
    XDynStructsEngine *g_pStructsEngine;
};

#endif // XDYNSTRUCTSWIDGET_H
