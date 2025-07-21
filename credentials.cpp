#include "credentials.h"

Credentials::Credentials(int id, string name, string user, string password, string email, int phone) {
    this->id = id;
    this->name = name;
    this->user = user;
    this->password = password;
    this->email = email;
    this->phone = phone;
}

int Credentials::GetId() const { return id; }
string Credentials::GetName() const { return name; }
string Credentials::GetPassword() const { return password; }
string Credentials::GetUser() const { return user; }
string Credentials::GetEmail() const { return email; }
int Credentials::GetPhone() const { return phone; }
