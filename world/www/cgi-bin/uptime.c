
/* 
   www/cgi-bin/uptime.c  
   By Ammy@YSZZ 
   /2001/04/12/
   is called at board_list.c
*/ 

inherit F_CLEAN_UP;

string report()
{
        int t, d, h, m, s;
        string time;

        t = uptime();
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒。\n";
	return time;
}


