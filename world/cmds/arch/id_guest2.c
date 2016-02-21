// boy redrose 2000/05  
// id_guest2.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;

        if( !arg ){
                    write("指令格式：id_guest2 <某人>\n将违反规则的使用者打入迎客厅。\n");
                            return 1;
                }

         if( sscanf(arg, "-d %s", arg) ) 
           {
                        ob = find_player(arg);
                        if(!ob) ob = find_living(arg);
                        if(!ob) ob = LOGIN_D->find_body(arg);
                        if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");
                        if(ob->query("punished")!=0) {
              log_file("PUNISH_PLAYER", sprintf("%s(%s) free %s from punish on %s.\n", 
                me->name(1), geteuid(me), arg, ctime(time()) ) );
                tell_object(me,HIW+ob->name()+""HIR"被你释放了"NOR"\n");
              ob->delete("punished");
              ob->move("/d/city/kezhan");
                     return 1;
                   ob->set("startroom","/d/city/kezhan");
                                ob->save();
                               }
                write("这个使用者没有被打入迎客厅！\n");
                return 1;
            }

        ob = find_player(arg);

        if(!ob) ob = find_living(arg);
        
        if(!ob) ob = LOGIN_D->find_body(arg);

        if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");

        if( wizhood(me) != "(wizard)"
        &&      wiz_level(me) <= wiz_level(ob) )
                return notify_fail("你没有惩罚" + ob->name() + "的权利。\n");

        if( me==ob ) return notify_fail("惩罚期满请用id_guest2 -d <ID> 解除惩罚。\n");
                     
                tell_object(me,HIW+ob->name()+""HIR"被你打入了迎客厅！"NOR"\n");
                ob->set("punished",1);
                 ob->move("/d/wiz/guest");
                if( userp(ob) ) log_file("PUNISH_PLAYER",
                              sprintf("%s(%s) punish %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
                                           ctime(time()) ) );
        return 1;
}
int help()
{
        write(@TEXT
指令格式：id_guest2 <某人>

将违反规则的使用者打入迎客厅，id_guest2 -d <某人>则取消惩罚。
TEXT
        );
        return 1;
}

//本文件id_guest1 的续集 本文件id_guest2 hoho
