/*
ID: 318439981
Name: Matan Dombelski
ID: 315240564
Name: Arad Zulti
*/

#ifndef CONNECTION_SETTINGS_
#define CONNECTION_SETTINGS_

class ConnectionSettings {
public:
    

private:
    void ReadFromFile();
    void WriteToFile();

private:
    const char* IPaddress;
    int port;
};

#endif //REVERSI_CONNECTIONSETTINGS_H
