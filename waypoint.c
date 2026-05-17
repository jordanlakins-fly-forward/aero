#include "waypoint.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>


#define EARTH_R_NM  3440.065


static waypoint_t route[MAX_WAYPOINTS];
static int route_len = 0;
static int active_idx = 0;


int wp_clear(void) {
    route_len = 0;
    active_idx = 0;
    return 0;
}


int wp_add(const waypoint_t *w) {
    if (route_len >= MAX_WAYPOINTS) return -1;
    route[route_len++] = *w;
    return route_len - 1;
}


int wp_count(void) {
    return route_len;
}


const waypoint_t *wp_active(void) {
    if (active_idx >= route_len) return NULL;
    return &route[active_idx];
}


int wp_advance(void) {
    if (active_idx + 1 >= route_len) return -1;
    active_idx++;
    return active_idx;
}


double wp_distance(const waypoint_t *a, const waypoint_t *b) {
    double dlat = (b->lat - a->lat) * M_PI / 180.0;
    double dlon = (b->lon - a->lon) * M_PI / 180.0;

    double s = sin(dlat / 2);
    double c = sin(dlon / 2);

    double h = s * s + cos(a->lat * M_PI / 180.0)
                     * cos(b->lat * M_PI / 180.0)
                     * c * c;

    return 2 * EARTH_R_NM * asin(sqrt(h));
}
