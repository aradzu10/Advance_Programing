/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef CONNECTION_SETTINGS_
#define CONNECTION_SETTINGS_

#include <string>

//analise ip and port
class ConnectionSettings {
public:
    //constructor for default file
    ConnectionSettings();
    //constructor change file name settings
    ConnectionSettings(char *file);
    ~ConnectionSettings();
    //analise ip and port from file
    void Setup();
    //return IP address
    const std::string& GetIPaddress() const;
    //return port number
    int GetPort() const;
    //get max data size transfer
    int GetMaxDataSizeTransfer();

private:
    //return 1 if successes otherwise 0
    int ReadFromFile();

private:
    //members
    char* fileAddress;
    std::string IPAddress;
    int port;
    int maxDataSizeTransfer;
};

#endif //REVERSI_CONNECTIONSETTINGS_H
