#include <assert.h>

//通过域名获得IP地址，支持IPv6
int url_to_ip(const char *url, char *ip, int ip_len)
{
    //参数检查
    assert(url && ip && ip_len >= 16);
    if (!url || !ip || ip_len < 16) return -1;

    struct sockaddr_in *addr;
    struct addrinfo hint, *ai;
    //输入参数
    memset(&hint, 0, sizeof(hint));
    hint.ai_flags = AI_PASSIVE;
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;

    //根据url取得ip地址
    int error = getaddrinfo(url, "http", &hint, &ai);
    if (error != 0) return -1;

    //将IP地址拷贝出来
    addr = (struct sockaddr_in *)ai->ai_addr;
    inet_ntop(AF_INET, &addr->sin_addr, ip, ip_len);

    freeaddrinfo(ai);

    return 0;
}

//连接TCP服务器
SOCKET tcp_connect(const char *ip, short port)
{
    //参数检查
    assert(ip);
    if (!ip) return -1;

    //请求1.1版本的winsock库
    WORD version = MAKEWORD(1, 1);
    WSADATA wsa_data;

    //初始化WSA库
    int res = WSAStartup(version, &wsa_data);
    if (res != 0) return -1;

    //检查版本是否正确
    if (LOBYTE(wsa_data.wVersion) != 1 || HIBYTE(wsa_data.wVersion) != 1)
    {
        WSACleanup();
        return -1;
    }

    //创建连接套接字
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) return -1;

    //设置服务器地址
    SOCKADDR_IN addr;
    inet_pton(AF_INET, ip, (void *)&addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    //连接服务器
    res = connect(sock, (SOCKADDR *)&addr, sizeof(SOCKADDR));
    if (res == -1)
    {
        closesocket(sock);
        return -1;
    }

    return sock;
}
