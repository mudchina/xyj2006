// by canoe

#include <ansi.h>

void morefile(string cmd, string *text, int line)
{
        int i;
        
        switch(cmd) {
                case "b":
                        if(line<24) {
                                write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
                                break;
                        }
                        if(line>23 && line<47) line = 0;
                        if(line>46) line -= 46;
                        write(ESC+"[1A"+ESC+"[200D"+ESC+"[K\n\n");
                        for(i=line + 23; line < i;line++)
                        { 
//                      if ( this_player()->query("env/more") && wizardp(this_player()) ) 
                                if ( line <= 8 )
                                    write(HIR + "[000" + (line+1) + "]"+ NOR);
                                else
                                {
                                        if ( line <= 98 )
                                                write(HIR + "[00" + (line+1) + "]"+ NOR);
                                        else
                                        {
                                                if ( line <= 998 )
                                                        write(HIR + "[0" + (line+1) + "]"+ NOR);
                                                else
                                                        write(HIR + "[" + (line+1) + "]"+ NOR);
                                        }
                                }
                        write(text[line]+"\n");
                        }
                        break;
                case "q":
                        write(ESC+"[1A"+ESC+"[200D"+ESC+"[K\n\n");
                        return;
                default :
                        write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
                        for(i=line + 23; line<sizeof(text) && line<i; line++) 
                        {
//                              if ( this_player()->query("env/more") && wizardp(this_player()) ) 
                                if ( line <= 8 )
                                    write(HIR + "[000" + (line+1) + "]"+ NOR);
                                else
                                {
                                        if ( line <= 98 )
                                                write(HIR + "[00" + (line+1) + "]"+ NOR);
                                        else
                                        {
                                                if ( line <= 998 )
                                                        write(HIR + "[0" + (line+1) + "]"+ NOR);
                                                else
                                                        write(HIR + "[" + (line+1) + "]"+ NOR);
                                        }
                                }
                        write(text[line]+"\n");
                        }
                        if( line>=sizeof(text) ) return printf(HIW"-----------------------   [    文   件   结   束    ]   -----------------------\n"NOR);
;
                        break;
        }
        printf(HIM MUD_NAME + HIW + " >> 未完继续 " HIY "%d%%" HIW " << " NOR "(" HIC "ENTER" NOR " 继续下一页，" HIC 
                "q" NOR " 离开，" HIC "b" NOR " 前一页)", (line*100/sizeof(text)));
        input_to("morefile", text, line);
}

void more(string cmd, string *text, int line)
{
    int i;
    switch(cmd) {
    case "b":
        line = line - 46;
        if(line<-22) line=-23;
                write(ESC+"[1A"+ESC+"[200D"+ESC+"[K\n\n");
        for(i=line + 23; line < i;line++)
        write(text[line]+"\n");
        break;
    case "q":
            write(ESC+"[1A"+ESC+"[200D"+ESC+"[K\n\n");
        return;
    default:
                write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
        for(i=line + 23; line<sizeof(text) && line<i; line++)
            write(text[line] + "\n");
        if( line>=sizeof(text) ) return;
        break;
    }
    printf("== 未完继续 " HIY "%d%%" NOR " == ("+HIC+"q"+NOR+" 离开，"+HIC+"b"+NOR+" 前一页，其他继续下一页)",
        (line*100/sizeof(text)) );
    input_to("more", text, line);
}
void start_more(string msg)
{
     write("\n");
     more("", explode(msg, "\n"), 0);
}

void start_more_file(string msg,string file)
{
        if (!stringp(msg)) return;
        write(HIW"-----------------------   [    文   件   开   始    ]   -----------------------\n"+
                  "文件名： "+file+HIW" 。\n-------------------------------------------------------------------------------\n"NOR);
        write("\n");
        morefile("", explode(msg, "\n"), 0);
}
