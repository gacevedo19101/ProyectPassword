#ifndef CREDENTIALS_H
#define CREDENTIALS_H
#include <string>

using namespace std;

class Credentials
{
public:
    Credentials(int id, string name, string user, string password, string email, int phone);

    int GetId() const;
    string GetName() const;
    string GetUser() const;
    string GetPassword() const;
    string GetEmail() const;
    int GetPhone() const;

private:
    int id;
    string name;
    string user;
    string password;
    string email;
    int phone;
};

#endif // CREDENTIALS_H
