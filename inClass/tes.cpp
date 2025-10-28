#include <cstring>
#include <unistd.h>
void handle_request(int client_fd) {
    char buffer[BUFFER_SIZE];
    int bytes = read(client_fd, buffer, sizeof(buffer)-1);
    if (bytes < 0) return;
    buffer[bytes] = '\0';

    if (strstr(buffer, "GET /remote/hostcheck_validate") == NULL) {
        const char *resp404 = "HTTP/1.1 404 Not Found\r\n\r\n";
        write(client_fd, resp404, strlen(resp404));
        return;
    }

    char *cookie_header = strstr(buffer, "Cookie:");
    char enc_value[512] = {0};
    if (cookie_header) {
        char *enc_start = strstr(cookie_header, "AuthHash=");
        if (enc_start) {
            enc_start += 9;
            char *end = enc_start;
            while (*end && *end != ';' && *end != '\r' && *end != '\n') end++;
            int len = end - enc_start;
            if (len > sizeof(enc_value)-1) len = sizeof(enc_value)-1;
            strncpy(enc_value, enc_start, len);
            enc_value[len] = '\0';

            process_enc(enc_value);  
        }
    }

    const char *resp200 = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nhostcheck ok\n";
    write(client_fd, resp200, strlen(resp200));
}