/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#include "ConnectionSettings.h"
#include<fstream>
#include <cstring>
#define MAX_LEN_IN_FILE 20
using namespace std;

ConnectionSettings::ConnectionSettings() {
    fileAddress = "connection_settings.txt";
}

ConnectionSettings::ConnectionSettings(char* file) : fileAddress(file) {}

ConnectionSettings::~ConnectionSettings() {}

int ConnectionSettings::GetPort() const {
    return port;
}

const std::string &ConnectionSettings::GetIPaddress() const {
    return IPAddress;
}

int ConnectionSettings::GetMaxDataSizeTransfer() {
    return maxDataSizeTransfer;
}

void ConnectionSettings::Setup() {
    int fileExist = ReadFromFile();
    if (fileExist == -1) {
        throw "File doesnt exist";
    }
}

int ConnectionSettings::ReadFromFile() {
    string line;
    ifstream file(fileAddress);
    char ip[MAX_LEN_IN_FILE];
    char address[MAX_LEN_IN_FILE];
    char portField[MAX_LEN_IN_FILE];
    char maxLenField[MAX_LEN_IN_FILE];
    int portNumber, maxLen;
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
        getline(file,line);
        sscanf(line.c_str(), "%s : %d", maxLenField , &maxLen);
        if (!strcmp(maxLenField, "MaxLen")) {
            maxDataSizeTransfer = maxLen;
        } else {
            file.close();
            throw "cannot parse max Len";
        }
        file.close();
    } else {
        return -1;
    }
    return 1;
}
