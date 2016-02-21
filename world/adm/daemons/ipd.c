// ADM SYS ipd.c
// By lxfeng@KYJH 08.10.2000

string seek_ip_address(string ip)
{
        string *ip_address;
        string str;
        string *ip_list_start, *ip_list_end;
        string *user_ip;
        string ip_config="/adm/etc/169ip";
        int i, j, k=0;
        int ip_start, ip_end, now_ip;

        user_ip = explode(ip, ".");
        if ( atoi(user_ip[0])==10 )
                ip_config="/adm/etc/169ip";

        else if ( atoi(user_ip[0])<=201 )
                ip_config="/adm/etc/163ip1";

        else if ( atoi(user_ip[0])==202 && atoi(user_ip[1])<=60 && atoi(user_ip[1])>=0 )        //202.0 -- 202.60
                ip_config="/adm/etc/163ip2";

        else if ( atoi(user_ip[0])==202 && atoi(user_ip[1])<=103 && atoi(user_ip[1])>60 )       //202.61 -- 202.103
                ip_config="/adm/etc/163ip3";

        else if ( atoi(user_ip[0])==202 && atoi(user_ip[1])<=255 && atoi(user_ip[1])>103 )      //202.104 -- 202.255
                ip_config="/adm/etc/163ip4";

        else ip_config="/adm/etc/163ip5";

        str = read_file(ip_config);
        if (!str) return "文件为空。";
        ip_address = explode(str, "\n");
        for (i = 0; i < sizeof(ip_address); i++) {
                if (atoi(ip_address[i][0..2])==atoi(user_ip[0])) {
                        ip_list_start = explode(ip_address[i][0..14], ".");
                        ip_list_end = explode(ip_address[i][16..30], ".");

                        for ( j = 1;j< 4 ;j++ ) {
                                ip_start=atoi(ip_list_start[j]);
                                ip_end=atoi(ip_list_end[j]);
                                now_ip=atoi(user_ip[j]);
                                if ( now_ip <= ip_end && now_ip >= ip_start )
                                        k++;
                        }
                        if ( k == 3 ) {
                                return ip_address[i][32..]+"。";
                        }
                        k=0;
                }
        }
        return "是个未知的IP所属地址。";

}
