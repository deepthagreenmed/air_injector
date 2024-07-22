#ifndef ADS7841_H
#define ADS7841_H

#include <QObject>
#include <QVector>
#include <QTimer>

class ads7841 : public QObject
{
    Q_OBJECT
public:
    ads7841();
    ~ads7841();
    int convert(uint8_t channel);
    void initSPI();

private:
    QTimer *timer;
    int spi_fd;

};


#endif // ADS7841_H
