#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#define SIZE 128
typedef struct msgbuf {
    long mtype;
    char mtext[SIZE];
} message_buf;

int main() {
    int msqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    message_buf sbuf;
    size_t buf_length;
    char msg[100];
    key = 1234;

    if ((msqid = msgget(key, msgflg)) < 0) {
        printf("msgget-msg queue can not be created \n");
        return 1;
    }
    printf("\n Message Queue created with ID = %d\n", msqid);
    sbuf.mtype = 1;
    printf("\n  Enter the message to send \n");
    scanf("%s", msg);
    strcpy(sbuf.mtext, msg);
    buf_length = strlen(sbuf.mtext) + 1;
    if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
        return 1;
    } else {
        printf("\n Message Sent to Message Queue is %s \n", sbuf.mtext);
    }
    return 1;
}