/*
   cmds/usr/plan.c
   Created by Ammy@YSZZ
   /2001/04/13
   用来修改个人说明档(plan)
   plan限一行，80个字母以内
 */ 

#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
    	object ob,link_ob;
        string *txt;

        if( me != this_player(1) ) return 0;

        ob = me->query_temp("link_ob");
        if( !ob ) return 0;

        while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

        if( !arg ) return notify_fail("指令格式：plan <描述>\n");

        txt = explode(arg, "\n");
        if( (wizardp(me) && sizeof(txt) > 20) || sizeof(txt) > 10  )
                return notify_fail("请将您对自己的描述控制在八行以内。\n");

        arg = implode(txt, "\n") + "\n";

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        arg = replace_string(arg, "$BLINK$", BLINK);
        arg = replace_string(arg, "$HBBLU$", HBBLU);
        arg = replace_string(arg, "$HBRED$", HBRED);
        arg = replace_string(arg, "$HBMAG$", HBMAG);
        arg = replace_string(arg, "$HBYEL$", HBYEL);
        arg = replace_string(arg, "$HBWHT$", HBWHT);
        arg = replace_string(arg, "$HBGRN$", HBGRN);
        arg = replace_string(arg, "$HBCYN$", HBCYN);


        if( !ob->set("plan", arg) ) {
                write("说明档设定失败！\n");
                return 0;
        }

        ob->save();
        write("说明档设定成功!\n");
        return 1;
        
}

int help()
{
        write(@TEXT
指令格式：plan <描述>

这个指令让你使用西游记2006在线查询时，描述将显示在个人说明档里面
通常当你的说明档超过一行时可以用 to plan 的方式来输入。在plan
里面支持ANSI颜色，至于怎么输入，自已看吧!
TEXT
        );
        return 1;
}



