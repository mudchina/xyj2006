inherit F_CLEAN_UP;
int main(object me) {
        mapping info;
        float x, fraction;
        string str;

        info = rusage();
        x = info["utime"] + info["stime"];
        // time is in msec, convert to sec
        x = (info["utime"] + info["stime"])/1000;
        fraction = x / uptime();    
        str = sprintf("CPU usage: %2.2f%%\n", fraction * 100);
        write( str );
        return 1;
}
