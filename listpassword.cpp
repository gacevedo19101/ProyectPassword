#include "listpassword.h"
#include <vector>
#include "credentials.h"
#include <algorithm> // Necesario para std::find_if

ListPassword::ListPassword() {}

void ListPassword::addAccount(Credentials credentials){
    list.push_back(credentials);
}

void ListPassword::editAccount(Credentials credentials){
    for (auto &item : list) { // Usamos & para poder modificar el item
        if (item.GetId() == credentials.GetId()) {
            item = credentials; // Reemplazamos el item viejo con el nuevo
            return;
        }
    }
}

void ListPassword::removeAccount(int id) {
    auto it = std::remove_if(list.begin(), list.end(), [id](const Credentials& c) {
        return c.GetId() == id;
    });
    if (it != list.end()) {
        list.erase(it, list.end());
    }
}

std::vector<Credentials> ListPassword::getList(){
    return list;
}
int ListPassword::generateNewId() const
{
    if (list.empty()) {
        return 1; // Si la lista está vacía, empezamos con el ID 1.
    }

    // Buscamos el ID más alto en la lista actual.
    int maxId = 0;
    for (const auto& c : list) {
        if (c.GetId() > maxId) {
            maxId = c.GetId();
        }
    }
    // El nuevo ID será el máximo encontrado + 1.
    return maxId + 1;
}
