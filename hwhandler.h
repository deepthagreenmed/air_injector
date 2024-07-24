#ifndef HWHANDLER_H
#define HWHANDLER_H

#include <QThread>
#include <stdint.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <fstream>
#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>
#include <QDebug>
#include <QFile>
#include <QCoreApplication>
#include <QEventLoop>
#include <QTime>

#define XPAR_AXI_COMBINED_BASEADDR 0x43C40000;
#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE - 1)

#define ON_MASK                     0x01
#define OFF_MASK                    0x00

#define AI_ONOFF_REG                44
#define AI_PRESET_REG               48
#define AI_COUNT_REG                50


#define MOT_CTRL_REG              32
#define MOT_COUNT_REG             36


#define MOT_ONOFF_MASK  0x01
#define MOT_CCW_MASK   0x02
#define MOT_RST_MASK   0x04
#define MOT_ON_CLK_MASK     0x07
#define MOT_ON_ACLK_MASK    0x05
#define MOT_OFF_MASK        0x00



#define CHANNEL_0                   0x97
#define CHANNEL_1                   0xD7
#define CHANNEL_2                   0xA7
#define CHANNEL_3                   0xE7





class hwHandler: public QThread
{
    Q_OBJECT
public:
    explicit hwHandler(QObject *parent = 0);
    int memfd;

    static void ai_on();
    static void ai_off();
    static void ai_preset_count(int count);
    static void ai_actual_count(int count);
    static void write_motor(int status,int dir,int value);





signals:

};
#endif // HWHANDLER_H



