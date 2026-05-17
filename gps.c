#include "gps.h"

#include <math.h>
#include <stdio.h>
#include <string.h>


static gps_fix_t current_fix;

static int sat_count = 0;


int gps_init(void) {
    memset(&current_fix, 0, sizeof(current_fix));
    sat_count = 0;
    return 0;
}


int gps_update(const nmea_sentence_t *s) {
    if (!s) return -1;

    current_fix.lat = s->latitude;
    current_fix.lon = s->longitude;
    current_fix.alt = s->altitude;

    sat_count = s->sats;

    return 0;
}


gps_fix_t gps_current(void) {
    return current_fix;
}


int gps_sats(void) {
    return sat_count;
}


double gps_hdop(void) {
    return current_fix.hdop;
}


int gps_lock(void) {
    return sat_count >= 4 ? 1 : 0;
}
