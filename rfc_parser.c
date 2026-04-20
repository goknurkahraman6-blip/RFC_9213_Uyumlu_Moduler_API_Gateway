#include <string.h>
#include <stdlib.h>

int parseUrgency(const char *header) {
    const char *pos = strstr(header, "u=");
    if (pos != NULL) {
        return atoi(pos + 2); // "u=" karakterlerinden sonrasýný sayýya çevir
    }
    return 3; // Bulamazsa varsayýlan öncelik
}
