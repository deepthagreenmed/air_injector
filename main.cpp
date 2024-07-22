#include "hwhandler.h"
#include "ads7841.h"

#include <QCoreApplication>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    hwHandler *h = new hwHandler;
    ads7841 *ad = new ads7841;

    int preset;
    int actual;

 //   int input=0;
    preset = std::atoi(argv[1]);

    while(1)
    {
        //std::cout << "enter preset value" << std::endl;

        actual = ad->convert(0xD7);
        //actual = 100;
        actual = actual * 0.34;

        //std::cout << "preset " << preset << std::endl;
        std::cout << "actual " << actual << ", preset "<< preset << std::endl;

        h->ai_on();

//        if(actual == 0)
//        {
//            h->ai_off();
//        }
//        else
//        {
//            h->ai_on();
//        }

        h->ai_preset_count(preset);
        h->ai_actual_count(actual);

//        if(preset == 0 && actual == 0)
//        {
//            h->ai_off();
//            h->ai_preset_count(preset);
//            h->ai_actual_count(actual);
//            std::cout << "Condition 0 (OFF)" << std::endl;
//        }
//        else if(actual > preset)
//        {
//            h->ai_on();
//            h->ai_preset_count(preset);
//            h->ai_actual_count(actual);
//            std::cout << "Condition 1 (actual>preset)" << std::endl;
//        }
//        else if(actual == preset)
//        {
//            h->ai_on();
//            h->ai_preset_count(preset);
//            h->ai_actual_count(actual);
//            std::cout << "Condition 2 (actual=preset)" << std::endl;
//        }
//        else if(actual < preset)
//        {
//            h->ai_on();
//            h->ai_preset_count(preset);
//            h->ai_actual_count(actual);
//            std::cout << "Condition 3 (actual<preset)" << std::endl;
//        }

//        std::cin >> input;

    }

     std::cout << "exiting the program" << std::endl;

    return a.exec();
}
