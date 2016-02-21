// file:            Autosave daemon
// for autosave players data file.
#include <ansi.h>
#pragma save_binary
void autosave(int i)
{

    int  j;
    object *user=children(USER_OB);
    j=i+5;
    for (j=i;j<i+5;j++){
        if(j>=sizeof(user)) return;
        if (!user[j] || !environment(user[j])) continue;
    user[j]->save();

  tell_object(user[j], ""+WHT+"【档案储存完毕】\n"NOR);



    }
    call_out("autosave",1,i+5);
}
void auto_save();
 
void create()
{
        seteuid(ROOT_UID);
        CHANNEL_D->do_channel( this_object(), "sys", "自动存盘系统已经启动。\n\n");
        remove_call_out("auto_save");
        call_out("auto_save", 40);
}

mixed query(string arg)
{
    if (arg=="channel_id") return "存盘精灵(AutoSave)";
    return 0;
}

void auto_save()
{
        remove_call_out("autosave");
        call_out("autosave",1,0);
        remove_call_out("auto_save");
        call_out("auto_save", 300);
}




