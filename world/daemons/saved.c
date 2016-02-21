// saved.c
// 自动存盘系统

#include <ansi.h>

inherit F_DBASE;

private void auto_save();
private void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "存盘精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "自动存盘系统已经启动。");
        auto_save();
}
private void auto_save()
{
        int i,player;
        object *ob,link_ob;

        seteuid(getuid());

        ob = filter_array(children(USER_OB),(: userp :));
        i=sizeof(ob);

        for( i=0;i<sizeof(ob);i++) {
                if(!environment(ob[i]) )continue;
                if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
                ob[i]->save();
                link_ob->save();
                player++;
                if( (int)link_ob->save() && (int)ob[i]->save())
                        message("system",HIG"你的资料已经被存储。\n"NOR,ob[i]);
                else
                        message("system", HIG"你的资料存储失败，请尽快联系巫师。\n"NOR,ob[i]);
        }
        CHANNEL_D->do_channel(this_object(),"sys",sprintf("共有%d位使用者资料被保存！系统清除了"+ reclaim_objects() +"个变数。",player));
        remove_call_out("auto_save");
        call_out("auto_save",300);
        return;
}
