#ifndef SKYWARD_NAV_WAYPOINT_H
#define SKYWARD_NAV_WAYPOINT_H


#define MAX_WAYPOINTS  128


typedef struct {
    char   id[8];
    double lat;
    double lon;
    double alt;
} waypoint_t;


int                 wp_clear(void);
int                 wp_add(const waypoint_t *w);
int                 wp_count(void);
const waypoint_t   *wp_active(void);
int                 wp_advance(void);
double              wp_distance(const waypoint_t *a, const waypoint_t *b);


#endif
