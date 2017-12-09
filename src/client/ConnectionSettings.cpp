#include "ConnectionSettings.h"
#include<fstream>
#include <string>
#include <cstring>
#define MAX_LEN 20
using namespace std;

ConnectionSettings::ConnectionSettings() {
    fileAddress = "connection_settings.txt";
}

ConnectionSettings::ConnectionSettings(char* file) : fileAddress(file) {}

int ConnectionSettings::GetPort() const {
    return port;
}

const std::string &ConnectionSettings::GetIPaddress() const {
    return IPAddress;
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
    char ip[MAX_LEN];
    char address[MAX_LEN];
    char portField[MAX_LEN];
    int portNumber;
    if (file.is_open()) {
        getline(file,line);
        sscanf(line.c_str(), "%s : %d", portField , &portNumber);
        if (!strcmp(portField, "Port")) {
            port = portNumber;
        } else {
            file.close();
            throw "cannot parse Port";
        }
        getline(file,line);
        sscanf(line.c_str(), "%s : %s", ip , address);
        if (!strcmp(ip, "IP")) {
            IPAddress = address;
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