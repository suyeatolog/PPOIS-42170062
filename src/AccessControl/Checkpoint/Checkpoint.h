//
// Created by user on 25.10.2025.
//

#ifndef LABWORK2_CHECKPOINT_H
#define LABWORK2_CHECKPOINT_H
#include "../../Visitor/Visitor.h"

class Checkpoint {
public:
    Checkpoint() = default;
    ~Checkpoint() = default;

    void CheckAccess(Visitor& visitor);
};

#endif //LABWORK2_CHECKPOINT_H