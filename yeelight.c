#include "yeelight.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int command(const char *ip, const char *command, size_t commandLen) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        return -1;
    }

    struct sockaddr_in info;
    bzero(&info, sizeof(info));
    info.sin_family = PF_INET;
    info.sin_addr.s_addr = inet_addr(ip);
    info.sin_port = htons(55443);

    int rc = connect(sock, (struct sockaddr *) &info, sizeof(info));
    if (rc == -1) {
        return -2;
    }

    rc = send(sock, command, commandLen, 0);
    if (rc == -1) {
        return -3;
    }

    char rBuf[256] = {0};
    rc = recv(sock, rBuf, 256, 0);

    if (rc == -1) {
        return -4;
    }

    close(sock);

    return 0;
}

int toggle(const char *ip) {
    char cmd[] = "{\"params\":[\"smooth\",300],\"method\":\"toggle\",\"id\":0}\r\n";
    return command(ip, cmd, sizeof(cmd));
}

int on(const char *ip) {
    char cmd[] = "{\"params\":[\"on\",\"smooth\",300],\"method\":\"set_power\",\"id\":0}\r\n";
    return command(ip, cmd, sizeof(cmd));
}

int off(const char *ip) {
    char cmd[] = "{\"params\":[\"off\",\"smooth\",300],\"method\":\"set_power\",\"id\":0}\r\n";
    return command(ip, cmd, sizeof(cmd));
}

int brightness(const char *ip, uint8_t level) {
    char fmt[] = "{\"params\":[%u,\"smooth\",300],\"method\":\"set_bright\",\"id\":0}\r\n";
    char cmd[256] = {0};

    sprintf(cmd, fmt, level);

    return command(ip, cmd, strlen(cmd));
}

int color(const char *ip, uint8_t r, uint8_t g, uint8_t b) {
    char fmt[] = "{\"params\":[%u,\"smooth\",300],\"method\":\"set_rgb\",\"id\":0}\r\n";
    char cmd[256] = {0};

    uint32_t color = r * 65536 + g * 256 + b;

    sprintf(cmd, fmt, color);

    return command(ip, cmd, strlen(cmd));
}

int main() {
    toggle("192.168.1.157");
    on("192.168.1.157");
    off("192.168.1.157");
    brightness("192.168.1.157", 100);
    color("192.168.1.157", 255, 255, 255);
    return 0;
}
