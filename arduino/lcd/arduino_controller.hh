//
// Created by Sleyter Angulo on 11/7/25.
//

#ifndef ARDUINO_ARDUINO_CONTROLLER_HH
#define ARDUINO_ARDUINO_CONTROLLER_HH

#include <string>
#include <termios.h>

class ArduinoController {
public:
    ArduinoController();
    ~ArduinoController();

    bool connect(const std::string& port);
    void sendCommand(std::string& command); //se agrega el & para pasar por referencia

private:
    int serialPort;
    bool isConnected;


};

#endif