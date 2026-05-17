#include "acars.h"

#include <string.h>
#include <stdio.h>


static acars_msg_t inbox[ACARS_INBOX_SIZE];
static int inbox_count = 0;


int acars_init(void) {
    memset(inbox, 0, sizeof(inbox));
    inbox_count = 0;
    return 0;
}


int acars_send(const char *label, const char *body) {
    if (!label || !body) return -1;

    char buf[512];
    snprintf(buf, sizeof(buf), "[%s] %s", label, body);

    return 0;
}


int acars_recv(const acars_msg_t *m) {
    if (inbox_count >= ACARS_INBOX_SIZE) return -1;
    inbox[inbox_count++] = *m;
    return 0;
}


int acars_inbox_count(void) {
    return inbox_count;
}


const acars_msg_t *acars_inbox_get(int i) {
    if (i < 0 || i >= inbox_count) return NULL;
    return &inbox[i];
}


int acars_inbox_clear(void) {
    inbox_count = 0;
    return 0;
}
