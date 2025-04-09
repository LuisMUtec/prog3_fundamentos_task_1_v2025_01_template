//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_BAG_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_BAG_H

#include <cstddef>

#ifndef BAG_H
#define BAG_H

#include <cstddef>

namespace structures {

    // Se asigna un parámetro de plantilla por defecto para poder omitirlo al instanciar.
    template<typename T = int>
    class bag {
    public:
        // Estructura pública del nodo, accesible para los tests.
        struct Node {
            T data;      // Dato almacenado.
            Node* next;  // Puntero al siguiente nodo.
            Node(const T& d) : data(d), next(nullptr) {}
        };

        // Constructor por defecto.
        bag();

        // Destructor.
        ~bag();

        // Inserta un elemento en el bag.
        bool add(const T& data);

        // Retorna el número de elementos en el bag.
        std::size_t size() const;

        // Iteración: begin() retorna el primer nodo y end() retorna nullptr.
        Node* begin() const;
        Node* end() const;

    private:
        Node* head_;         // Puntero al primer nodo de la lista enlazada.
        std::size_t size_;   // Número de elementos almacenados.
    };

    template<typename T>
    bag<T>::bag() : head_{nullptr}, size_{0} {}

    template<typename T>
    bag<T>::~bag() {
        Node* current = head_;
        while (current != nullptr) {
            Node* tmp = current;
            current = current->next;
            delete tmp;
        }
    }

    template<typename T>
    bool bag<T>::add(const T& data) {
        // Inserción al inicio de la lista enlazada.
        Node* new_node = new Node(data);
        new_node->next = head_;
        head_ = new_node;
        ++size_;
        return true;
    }

    template<typename T>
    std::size_t bag<T>::size() const {
        return size_;
    }

    template<typename T>
    typename bag<T>::Node* bag<T>::begin() const {
        return head_;
    }

    template<typename T>
    typename bag<T>::Node* bag<T>::end() const {
        return nullptr;
    }

} // namespace structures

#endif // BAG_H


#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_BAG_H
