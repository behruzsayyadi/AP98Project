#include <QDateTime>
#include <QString>

static QString getLocaleCurrentDate() {
    return QDateTime::currentDateTime().toString(Qt::SystemLocaleLongDate);
}
