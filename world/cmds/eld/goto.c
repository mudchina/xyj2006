// goto.c
// modified by tool on 96/10/05

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int goto_inventory = 0;
        object obj, ridee;
        string msg, ridemsg;

        if( !arg ) return notify_fail("你要去哪里？\n");

        if( me->over_encumbranced() )
                   return notify_fail("你负载太重了！\n");

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail("你要去哪里？\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
       
	if(!obj) obj = LOGIN_D->find_body(arg);
	/* added by mon. 2/23/97 */
	if(!obj) obj = find_object(arg);

	if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return me->move(arg);
                        return notify_fail("没有这个玩家、生物、或地方。\n");
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");

      if(!me->query("env/invisibility")) {
        if( stringp(msg = me->query("env/msg_mout")) ) {
           msg = replace_string(msg, "$BLK$", BLK);
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
           if (msg != "") message_vision(msg+NOR+"\n", me);
        }
        else
                message_vision("只见一阵烟雾过后，$N的身影已经不见了。\n", me);
      }

	if (ridee = me->ride())
        {
          ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
	  ridee->move(obj);
	}  
	else
	  ridemsg = "";
        me->move(obj);

      if(!me->query("env/invisibility")) {
        if( stringp(msg = me->query("env/msg_min")) )
        {
           msg = replace_string(msg, "$BLK$", BLK);
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
           if (msg != "") message_vision(msg+NOR+"\n", me);
        }
        else
                message_vision("$N"+ridemsg+"突然出现在一阵烟雾之中。\n", me);
      }

        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : goto [-i] <目标>

这个指令会将你传送到指定的目标. 目标可以是一个living 或房间
的档名. 如果目标是living , 你会被移到跟那个人同样的环境.
如果有加上 -i 参数且目标是 living, 则你会被移到该 living 的
的 inventory 中.

HELP
    );
    return 1;
}

