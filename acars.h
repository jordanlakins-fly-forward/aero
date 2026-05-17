#ifndef SKYWARD_COMMS_ACARS_H
#define SKYWARD_COMMS_ACARS_H


#define ACARS_INBOX_SIZE  32
#define ACARS_MSG_LEN     220


typedef struct {
    char label[8];
    char body[ACARS_MSG_LEN];
    long ts;
} acars_msg_t;


int                acars_init(void);
int                acars_send(const char *label, const char *body);
int                acars_recv(const acars_msg_t *m);
int                acars_inbox_count(void);
const acars_msg_t *acars_inbox_get(int i);
int                acars_inbox_clear(void);


#endif
