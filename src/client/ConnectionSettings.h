/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef CONNECTION_SETTINGS_
#define CONNECTION_SETTINGS_

#include <string>

class ConnectionSettings {
public:
    ConnectionSettings();
    ConnectionSettings(char *file);
    ~ConnectionSettings();
    void Setup();
    const std::string& GetIPaddress() const;
    int GetPort() const;

private:
    int ReadFromFile();

private:
    char* fileAddress;
    std::string IPaddress;
    int port;
};

#endif //REVERSI_CONNECTIONSETTINGS_H
