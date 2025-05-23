#pragma once

#include "Ticket.h"
#include <vector>
#include <memory>

class QuadTree {
public:
    struct Node {
        Ticket data;
        std::unique_ptr<Node> nw, ne, sw, se;

        Node(const Ticket& ticket) : data(ticket), nw(nullptr), ne(nullptr), sw(nullptr), se(nullptr) {}
    };

    QuadTree();
    bool insert(const Ticket& ticket);
    bool search(int ticketId) const;
    size_t size() const;

private:
    std::unique_ptr<Node> root;
    size_t nodeCount;

    bool insert(std::unique_ptr<Node>& node, const Ticket& ticket);
    bool search(const Node* node, int ticketId) const;
};