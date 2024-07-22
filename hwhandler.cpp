#include "hwhandler.h"
#include <QDebug>

void *mapped_base, *mapped_dev_base;
off_t dev_base = XPAR_AXI_COMBINED_BASEADDR;



hwHandler::hwHandler(QObject *parent):
    QThread(parent)
{

    memfd = open("/dev/mem", O_RDWR | O_SYNC);
    if (memfd == -1) {
        //        printf("Can't open /dev/mem.\n");
        exit(0);
    }
    mapped_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, memfd, dev_base & ~MAP_MASK);
    if (mapped_base == (void *) -1) {
        //        printf("Can't map the memory to user space.\n");
        exit(0);
    }

        mapped_dev_base = mapped_base + (dev_base & MAP_MASK);
}

void hwHandler::ai_on()
{
    *((uint8_t *) (mapped_dev_base  + AI_ONOFF_REG ))   = ON_MASK;
    //ai_preset_count(100);
    //qDebug()<<"ai on";
}

void hwHandler::ai_off()
{
    *((uint8_t *) (mapped_dev_base  + AI_ONOFF_REG ))   = OFF_MASK;
    ai_preset_count(0);
    ai_actual_count(0);
   // qDebug()<<"ai off";
}

void hwHandler::ai_preset_count(int count)
{
    *((uint16_t *) (mapped_dev_base  + AI_PRESET_REG ))    = (uint16_t)(count);
    //qDebug()<<"ai preset"<<count;
}

void hwHandler::ai_actual_count(int count)
{
    *((uint16_t *) (mapped_dev_base  + AI_COUNT_REG ))    = (uint16_t)(count);
   // qDebug()<<"ai actual"<<count;
}
