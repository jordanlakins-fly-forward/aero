#include "ins.h"

#include <math.h>
#include <string.h>


static ins_state_t state;


int ins_init(void) {
    memset(&state, 0, sizeof(state));
    return 0;
}


int ins_align(double lat, double lon) {
    state.lat = lat;
    state.lon = lon;
    state.aligned = 1;
    return 0;
}


int ins_step(const imu_sample_t *s, double dt) {
    if (!state.aligned) return -1;

    state.vx += s->ax * dt;
    state.vy += s->ay * dt;
    state.vz += s->az * dt;

    state.lat += state.vy * dt / 60.0;
    state.lon += state.vx * dt / 60.0;
    state.alt += state.vz * dt;

    state.roll  += s->p * dt;
    state.pitch += s->q * dt;
    state.yaw   += s->r * dt;

    return 0;
}


ins_state_t ins_get(void) {
    return state;
}
