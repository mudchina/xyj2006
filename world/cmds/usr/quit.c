
// quit.c

#include <command.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int do_drop(object me, object obj);
void do_yorn(string yn, object me, string arg);
void create() 
{
        seteuid(getuid());
        set("name", "离线指令");
        set("id", "quit");
}

// if force_quit==1, then don't check whether allow quit.
// used by quit after disconnected or idled too long.
// mon 7/5/98
int main(object me, string arg, int force_quit)
{
        int i;
        object *inv, link_ob;
object ob;

        link_ob = me->query_temp("link_ob");

        if(!force_quit) {
        if ( me->query_temp("no_move") )
                return notify_fail("你被定住了，哪里退得出游戏！\n");
        if ( me->query_condition("no_pk_time") > 120 )
                return notify_fail("你刚杀了人，不能退出游戏！\n");
        if ( me->query_temp("pkgame") )
                return notify_fail("你比完了赛再走也不迟呀！\n");
        if(!me->query_temp("suicide_countdown")) {
          if( me->is_busy() )
                return notify_fail("( 你上一个动作还没有完成，不能退出。)\n");
        } //to allow halt suicide :D by mon 9/9/97

        if( !wizardp(me) && environment(me) && 
          environment(me)->query("no_quit") && link_ob )
                        return notify_fail("这里不准退出游戏。\n");
        }
        if (!wizardp(me) && time()-(int)me->query("birthday") < 3600 )
         {
          write("\n由于您的账号是新建的，为了减少系统开销．．．\n");
          write("游戏规定必需连线一小时以上才可存档！\n\n");
          write("您决定想要保留这个账号吗？"HIY"[Y/N]"NOR);
          input_to("do_yorn",me,arg);
         }
       else
        {
        if( !wizardp(me) && (!link_ob || (
            link_ob && !link_ob->is_character()) ) ) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( !inv[i]->query_autoload() )
                                do_drop(me, inv[i]);
        }

        // We might be called on a link_dead player, so check this.
        if( link_ob ) {

                // Are we possessing in others body ?
                if( link_ob->is_character() ) {
                        write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
                        exec(link_ob, me);
                        link_ob->setup();
                        return 1;
                }

                link_ob->set("last_off", time());
                link_ob->set("last_leave", query_ip_name(me));
                link_ob->save();
                destruct(link_ob);
        }
         write("\n欢迎下次再来！\n");
         if(!wizardp(me) || !me->query("env/invisibility"))
         message("system", me->name() + "离开游戏。\n", environment(me), me);
         if (!wizardp(me))
         CHANNEL_D->do_channel(this_object(), "sys",
                me->name() + "(" + capitalize(me->query("id")) + ")" + "离开游戏了。");
         else
         CHANNEL_D->do_channel(this_object(), "wiz",
                me->name() + "(" + capitalize(me->query("id")) + ")" + "离开游戏了。");
         me->save();
     if (!wizardp(me))
{
      ob = find_object("/d/topten/topten");
//     ob->sort_board(me);

  }
         destruct(me);
        }
        return 1;
}
void do_yorn(string yn, object me, string arg)
{
     int i;
     string myid, couple;
     object *inv;
     if(!me) return;
     if(!yn) {
         write("什么？\n");
         return;
     }
     if(yn[0]=='y' || yn[0]=='Y' )
     {
        write("\n\n您决定保留账号，并返回继续游戏！\n");
        return;
     }
                write("\n");
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( !inv[i]->query_autoload() )
                                do_drop(me, inv[i]);
        seteuid(getuid());
        rm( me->query_save_file() + __SAVE_EXTENSION__ );
        myid=me->query("id");
        rm( "/data/login/"+myid[0..0]+"/"+myid+ __SAVE_EXTENSION__ );
        rm( "/data/playerhomes/h_"+myid+ __SAVE_EXTENSION__ );
        rm( "/data/mail/"+myid[0..0]+"/"+myid+ __SAVE_EXTENSION__ );
        couple=me->query("coupld/id");
        if(couple)
          rm("/data/mail/"+couple[0..0]+"/"+couple+__SAVE_EXTENSION__);
      LOGIN_D->set_banned_name(me->name(1),0);
      write("\n"+me->name()+"，欢迎您下次再来！\n");
      message("system", me->name() + "("+me->query("id")+")永远地离开了我们！\n", environment(me), me);
      CHANNEL_D->do_channel(this_object(), "sys",
       me->name() + "(" + capitalize(me->query("id")) + ")" + "决定放弃该账号。");
      log_file("no_reg",
      sprintf("%s(%s) abandoned on %s from %s\n", geteuid(me), me->name(), ctime(time()), (string)query_ip_name(me) ) );
      destruct(me);
      return;
}

int do_drop(object me, object obj)
{
        //if obj is a self-made fabao, save first...
        //if( obj->query("series_no") && obj->query("fabao") ) obj->save();
           
        if( obj->query("no_drop") ){
                destruct(obj);
                return 0;
        }
        if (obj->move(environment(me))) {
                if( obj->is_character() )
                        message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
                else {
                        message_vision( sprintf("$N丢下一%s$n。\n",     obj->query("unit")), me, obj );
                        if( !obj->query("value") && !obj->value() ) {
                                tell_object(me,"因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
                                destruct(obj);
                        }
                }
                return 1;
        }
        return 0;
}

int help(object me)
{
        write(@HELP
指令格式 : quit

当你想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}
