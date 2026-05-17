#ifndef SKYWARD_NAV_GPS_H
#define SKYWARD_NAV_GPS_H


typedef struct {
    double lat;
    double lon;
    double alt;
    double hdop;
} gps_fix_t;


typedef struct {
    double latitude;
    double longitude;
    double altitude;
    int    sats;
} nmea_sentence_t;


int        gps_init(void);
int        gps_update(const nmea_sentence_t *s);
gps_fix_t  gps_current(void);
int        gps_sats(void);
double     gps_hdop(void);
int        gps_lock(void);


#endif
