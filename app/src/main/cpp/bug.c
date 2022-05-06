#include "bug.h"

bool hello(UINT16 argument) {
    switch (argument) { // NOLINT(hicpp-multiway-paths-covered)
        case CONSTANT:
            return true;
        default:
            return false;
    }
}

bool hello_optimizations_disabled(UINT16 argument) __attribute__ ((optnone)) {
    switch (argument) { // NOLINT(hicpp-multiway-paths-covered)
        case CONSTANT:
            return true;
        default:
            return false;
    }
}
