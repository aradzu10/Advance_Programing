#include "ConnectionSettings.h"
#include<fstream>
#include <string>
#include <cstring>

using namespace std;

ConnectionSettings::ConnectionSettings() {
    fileAddress = "connection_settings.txt";
}

ConnectionSettings::ConnectionSettings(char* file) : fileAddress(file) {}

int ConnectionSettings::GetPort() const {
    return port;
}

const std::string &ConnectionSettings::GetIPaddress() const {
    return IPaddress;
}

ConnectionSettings::~ConnectionSettings() {}

void ConnectionSettings::Setup() {
    int fileExist = ReadFromFile();
    if (fileExist == -1) {
        throw "File doesnt exist";
    }
}

int ConnectionSettings::ReadFromFile() {
    string line;
    ifstream file(fileAddress);
    string ip , adress;
    string portField;
    int portNumber;
    if (file.is_open()) {
        getline(file,line);
        sscanf(line, "%s: %d", portField , portNumber);
        if (strcmp(portField, "Port")) {
            port = portNumber;
        } else {
            file.close();
            throw "cannot parse Port";
        }
        getline(file,line);
        sscanf(line, "%s: %s", ip , adress);
        if (strcmp(ip, "IP")) {
            IPaddress = adress;
        } else {
            file.close();
            throw "cannot parse IP";
        }
        file.close();
    } else {
        return -1;
    }
    return 1;
}