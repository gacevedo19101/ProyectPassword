#ifndef LISTPASSWORD_H
#define LISTPASSWORD_H
#include "credentials.h"
#include <vector>
class ListPassword
{
public:
    ListPassword();
    void addAccount(Credentials credentials);
    void removeAccount(Credentials credentials);
    void editAccount(Credentials credentials);
    std::vector<Credentials> getList();
    void removeAccount(int id);
    int generateNewId() const;
private:
    std::vector<Credentials> list;
};

#endif // LISTPASSWORD_H
