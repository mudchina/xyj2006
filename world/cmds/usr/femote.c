//Cracked by Roath
/* grep.c
 * 98-10-26
 * modify name to femote.c
 * make code less
 * by ken@XAJH
 */

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
        mapping emote;
        string *e, *loop;
        string result="", msg;
        int count=0;

        loop = ({ "others_target", "others_self", "others" });
        if( !arg )
                return help(me);
      if (time()-me->query_temp("scan_time") < 20 )
          return notify_fail("等等，系统喘气中......\n");

        foreach( e in sort_array(EMOTE_D->query_all_emote(),1) ) {
                emote = EMOTE_D->query_emote(e);
                for ( int j=0; j<sizeof(loop); j++ ) {
                        msg = emote[ loop[j] ];
                        if( msg && strsrch(msg, arg) >=0 ) {
                                result += sprintf(HIR "%s\n"+NOR+"动作: %s\n", e, msg);
                                count ++;
                        }
                }
        }

        if(  result == "" )
                return notify_fail(MUD_NAME" 中无符合查询条件的 emote.\n");
        else
                result = "\n查询结果"
                                "\n------------------------------------------------------------\n"
                                + result;
        result = replace_string(result, "$n", "某人");
        result = replace_string(result, "$N", me->name(1));
        result = replace_string(result, "$P", "你");
        result = replace_string(result, "$p", "(他/她)");
        result = replace_string(result, "$S", RANK_D->query_self(me));
        result = replace_string(result, "$s", RANK_D->query_self_rude(me));
        result = replace_string(result, "$R", "壮士");
        result = replace_string(result, "$r", "臭贼");
        result = replace_string(result, "$C", "愚兄我");
        result = replace_string(result, "$c", "哥哥");

        result += "------------------------------------------------------------\n";
        result += sprintf("在%s中，包含“%s”的 emote 共有 %d 个。\n",
                                        MUD_NAME, arg, count );
      me->set_temp("scan_time",time());
        me->start_more(result);
        return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : femote 关键字
功能：列出目前所有含指定关键字的 emote.

HELP
    );
    return 1;
}
