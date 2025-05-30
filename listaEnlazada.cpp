#include <iostream>
using namespace std;

struct Proceso
{
    int id;
    string nombre;
    int prioridad;
    Proceso *siguiente;
};

class ListaProcesos
{
private:
    Proceso *cabeza;

public:
    ListaProcesos() : cabeza(nullptr) {}

    void insertar(int id, string nombre, int prioridad)
    {
        Proceso *nuevo = new Proceso{id, nombre, prioridad, cabeza};
        cabeza = nuevo;
    }

    void mostrar()
    {
        Proceso *temp = cabeza;
        while (temp)
        {
            cout << "ID: " << temp->id << ", Nombre: " << temp->nombre << ", Prioridad: " << temp->prioridad << endl;
            temp = temp->siguiente;
        }
    }

    Proceso *buscar(int id)
    {
        Proceso *temp = cabeza;
        while (temp)
        {
            if (temp->id == id)
                return temp;
            temp = temp->siguiente;
        }
        return nullptr;
    }

    void eliminar(int id)
    {
        Proceso *temp = cabeza;
        Proceso *anterior = nullptr;

        while (temp && temp->id != id)
        {
            anterior = temp;
            temp = temp->siguiente;
        }

        if (!temp)
        {
            cout << "Proceso no encontrado.\n";
            return;
        }

        if (!anterior)
            cabeza = temp->siguiente;
        else
            anterior->siguiente = temp->siguiente;

        delete temp;
        cout << "Proceso eliminado.\n";
    }

    void modificarPrioridad(int id, int nuevaPrioridad)
    {
        Proceso *temp = buscar(id);
        if (temp)
        {
            temp->prioridad = nuevaPrioridad;
            cout << "Prioridad modificada.\n";
        }
        else
        {
            cout << "Proceso no encontrado.\n";
        }
    }
};