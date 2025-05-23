#include "QuadTree.h"

QuadTree::QuadTree() : root(nullptr), nodeCount(0) {}

bool QuadTree::insert(const Ticket& ticket) {
    return insert(root, ticket);
}

bool QuadTree::insert(std::unique_ptr<Node>& node, const Ticket& ticket) {
    if (!node) {
        node = std::make_unique<Node>(ticket);
        ++nodeCount;
        return true;
    }

    // Simplified placement logic (e.g., by ID or other criteria)
    if (ticket.id < node->data.id) {
        return insert(node->nw, ticket);
    } else if (ticket.id > node->data.id) {
        return insert(node->ne, ticket);
    }
    return false; // Duplicate ticket
}

bool QuadTree::search(int ticketId) const {
    return search(root.get(), ticketId);
}

bool QuadTree::search(const Node* node, int ticketId) const {
    if (!node) return false;

    if (node->data.id == ticketId) {
        return true;
    } else if (ticketId < node->data.id) {
        return search(node->nw.get(), ticketId);
    } else {
        return search(node->ne.get(), ticketId);
    }
}

size_t QuadTree::size() const {
    return nodeCount;
}