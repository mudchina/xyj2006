// by gslxz@mhsj 1/7/2001
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        string banghui;
        object lingpai;
        mapping player;
        if( (banghui=me->query("banghui")))
                return notify_fail("抱歉，你已经是帮会「"+me->query("banghui")+"」的人了，无法加入其他帮会。\n");
        if(me->is_fighting()||me->is_busy())
                return notify_fail("你正忙着呢。\n");
        if(! arg)
                return notify_fail("你要加入谁的帮会？\n");
        if( me->query("id")==arg)
                return notify_fail("你没法这么做！\n");
        if(! objectp(ob=present(arg,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        if((object)me->query_temp("oldsix/target")!=ob)
                return notify_fail("抱歉，"+ob->query("name")+"并没有邀请你参加他的帮会。\n");
        if(! (banghui=ob->query("banghui")))
                return notify_fail("抱歉，"+ob->query("name")+"现在不属于任何帮会！\n");
      if (this_player()->query("combat_exp") < 1000 )
                return notify_fail("你才初入江湖，在磨练磨练吧.\n");
        lingpai=new("/obj/lingpai");
        lingpai->create(banghui);
        if( ! lingpai->query("no_use")) {
        player=lingpai->query("player");
        if(! mapp(player))      player=([]);
        player[me->query("id")]=me->query("id");
        lingpai->set("player",player);
        lingpai->save();
        me->set("banghui",ob->query("banghui"));
        me->set("have_banghui",(int)me->query("have_banghui")+1);
        me->delete_temp("oldsix/target");
        me->save();
        me->set("title",HIG+ob->query("banghui")+"帮众"NOR);
// by gslxz@mhsj 1/7/2001
          destruct(lingpai);
                message("channel:rumor", 
   YEL"【帮会势力】"+me->query("name")+"加入帮会「"HIW+ob->query("banghui")+NOR+YEL"」！\n"NOR,users());
        return 1;
        }
        else    {
        destruct(lingpai);
        return notify_fail("对方帮会文件有问题，请与巫师联系。\n");
        }
}
int help(object me)
{
        write(@HELP
指令格式：jiaru <某人>
这个指令用来加入某人的帮会。
前提是某人必须邀请你。
HELP
        );
        return 1;
}

