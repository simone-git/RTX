#pragma once

#include <vector>
#include <memory>
#include "objects/Object.h"

struct World {
    std::vector<std::shared_ptr<Object>> objs;
};