// used for only by admin
// by canoe
#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;
        string id,password;
        if(!arg||sscanf(arg,"%s %s",id,password)!=2)
                return notify_fail("用法:xsuppwd ID 新身份鉴别码\n此操作容易损害玩家利益，你必须先调查清楚！\n");
        ob=find_player(id);
        if(!ob)
        {
        ob = new(LOGIN_OB);
        ob->set("id",id);
        if( !ob->restore() )
                return notify_fail("没有这个玩家。\n");
        else
                {                                    
           ob->set("super_password",crypt(password,0));
           tell_object(me, "玩家" + ob->query("id") + "("+ob->query("name")
                + ")的身份鉴别码已经更改为："+password+"。\n");
           log_file( "changesuper_password.log", sprintf("%s %s(%s)修改了%s(%s)的身份鉴别码",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
           ob->save();
           destruct(ob);
           return 1;
                }
        }
        link_ob=ob->query_temp("link_ob");
        if(link_ob)
        {
                link_ob->set("super_password",crypt(password,0));
 log_file( "changesuper_password.log", sprintf("%s %s(%s)修改了%s(%s)的身份鉴别码。",
               ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));

                link_ob->save();
                tell_object(me, "玩家" + ob->query("id") + "("+ob->query("name")
                        + ")的身份鉴别码已经更改为："+password+"。\n");
                tell_object(ob,"你的身份鉴别码被天神修改了，请去跟 "+me->query("id")+" 交涉。\n");
                return 1;
        }
        else
                return notify_fail("错误。无法进行修改。\n");
        return 1;
}


int help(object me)
{
        write(@HELP
指令格式 : xsuppwd ID 新的身份鉴别码

这个指令可以修改玩家的身份鉴别码，请谨慎使用。

HELP
    );
    return 1;
}

