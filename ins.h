#ifndef SKYWARD_NAV_INS_H
#define SKYWARD_NAV_INS_H


typedef struct {
    double ax, ay, az;
    double p, q, r;
} imu_sample_t;


typedef struct {
    double lat, lon, alt;
    double vx, vy, vz;
    double roll, pitch, yaw;
    int    aligned;
} ins_state_t;


int          ins_init(void);
int          ins_align(double lat, double lon);
int          ins_step(const imu_sample_t *s, double dt);
ins_state_t  ins_get(void);


#endif
