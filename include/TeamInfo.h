#ifndef TEAMINFO_H
#define TEAMINFO_H

#include <QWidget>
#include <QRadioButton>

#include "MatchData.h"

#include "qlabel.h"
#include "qlineedit.h"
#include "qpushbutton.h"

namespace Ui {
class TeamInfo;
}

class TeamInfo : public QWidget
{
    Q_OBJECT

private:
    MatchData m_matchData{};

    void keyPressEvent(QKeyEvent *event);

public:
    explicit TeamInfo(QWidget *parent = nullptr);
    ~TeamInfo();

    int teamNumber();
    int matchNumber();

    QString initials();

public slots:
    void setTeam();
    void setStation();

#ifndef Q_OS_WASM
    void downloadSchedule();

signals:
    void reloadSchedule();
#endif


private:
    Ui::TeamInfo *ui;

    QMap<AllianceStation, QRadioButton *> m_buttonMap;
};

#endif // TEAMINFO_H
