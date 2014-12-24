/**
* @file main.cpp
* @brief Main function.
*/

#include <core/capplication.h>

int main(int argc, char *argv[])
{
    core::CApplication a(argc, argv);
    // Waiting for MainWindow
    return a.exec();
}
