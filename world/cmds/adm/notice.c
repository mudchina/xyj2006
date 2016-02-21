//Cracked by Roath
// log.c
// by snow@jhfy 
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);

int main(object me, string msg)
{
        string *lines;
        string arg,file="/log/notice";
        if( !msg || msg=="" ){
        if (file_size(file)<0) {
        	write("现在没有设定任何连线通知\n");
        	write("--------------------------------------------\n\n");
        	return help(me);}
        arg=read_file(file);
        write("你现在所设定的连线通知是：\n");
        write("--------------------------------------------\n\n");
        if (strlen(arg)>8190)
           me->start_more(arg);
        else
           write(arg);
        return 1;
        }
      if(msg=="-rm")
      {
          rm("/log/login/notice");
          write("通知已被清除!\n");
          return 1;
       }
        lines = explode(msg, "\n");
        for(int i=0; i<sizeof(lines); i++)
                lines[i] = "    " + lines[i];
        msg = implode(lines, "\n") + "\n";
        arg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$BLINK$", BLINK);
        msg = replace_string(msg, "$BGRN$", BGRN);
        msg = replace_string(msg, "$BCYN$", BCYN);
        msg = replace_string(msg, "$BYEL$", BYEL);
        msg = replace_string(msg, "$BBLU$", BBLU);
        msg = replace_string(msg, "$BMAG$", BMAG);
        msg = replace_string(msg, "$BGRN$", BRED);
        msg = replace_string(msg, "$HBGRN$", HBGRN);
        msg = replace_string(msg, "$HBRED$", HBRED);
        msg = replace_string(msg, "$HBYEL$", HBYEL);
        msg = replace_string(msg, "$HBBLU$", HBBLU);
        msg = replace_string(msg, "$HBMAG$", HBMAG);
        msg = replace_string(msg, "$HBCYN$", HBCYN);
        msg = replace_string(msg, "$HBWHT$", HBWHT);
        write_file(file, msg,1);
        write("连线通知加入完毕。\n");
        return 1;
}

int help(object me)
{
        write(@Help
指令格式: notice <通知内容>

改指令用来添加玩家连线后的通知信息，如无必要尽量少用
notice -rm 用来清除信息,颜色控制符$HIR$ $HIC$...可以
用来修改颜色。
Help
        );
        return 1;
}

