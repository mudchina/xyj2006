// kantou.c
// modify by happ@YSZZ

inherit F_CLEAN_UP;

//#include <new_ride.h>
#include <ansi.h>
#include <dbase.h>

int main(object me, string arg)
{
        object obj,*ob,toulu,corpse;
        object wield1,wield2;
        object *inv;
        mapping weapon_prop;

        string *killer, callname;
        int i,count;
        int value2;
        if( environment(me)->query("no_fight") )
                return notify_fail("这里不准露出兵器。\n");

        if( !arg )
                return notify_fail("你想要谁的头颅？\n");

        if(!obj)
                obj = present(arg, environment(me));

        if(!obj )
                return notify_fail("这里没有这个死人。\n");

        if(!obj->is_corpse() )
                return notify_fail("你必须先杀了这个人。\n");

        if(obj->query("name")=="腐烂的尸体"
                 || obj->query("name")=="腐烂的无头尸体"
                 || obj->query("name")=="腐烂的无头女尸"
                 || obj->query("name")=="腐烂的无头男尸"
                 )
                return notify_fail("那已是腐烂的尸体了。\n");

        if(obj->query("name")=="无头的尸体"
                 || obj->query("name")=="无头的男尸"
                 || obj->query("name")=="无头的女尸"
                 )
                return notify_fail("那是不是完整的尸体。\n");

        if(arg!="corpse" )
                return notify_fail("那是不是完整的尸体。\n");

        if(obj==me)
                return notify_fail("你想自刎？\n");

        if(!wield1=me->query_temp("weapon"))
                return notify_fail("你应该先有武器。\n");

        if(((string)wield1->query("skill_type")!="sword"
             && ((string)wield1->query("skill_type")!="blade")))
                return notify_fail("你应该找把剑，或是刀什么的。\n");

        message_vision("\n$N嚓地一下，把$n的头砍了下来。\n"

                        +HIR+"鲜血溅了$P一身。\n"+NOR, me, obj);
                me->add("bellicosity", 5);
//add by yudian
                 obj->set("killer", me->query("id"));
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->query("equipped")
                        && inv[i]->query("armor_type")=="cloth"
                          && !(int)inv[i]->query("blood_onit")) {
                                inv[i]->set("blood_onit",1);
                                inv[i]->set("name",HIR"粘满鲜血的"NOR+inv[i]->query("name"));
                                continue;
                        }
        }

        if( objectp(corpse = CHAR_D->make_wutoucorpse(obj)) )
        {
                message_vision("只看见鲜血还在不断地从"+corpse->query("name")+
                        "的断脖流了出来。\n",me);
                corpse->move(environment(me));
        
        }
        else
                write("不能创建无头尸体，请告诉巫师。\n");
        if( objectp(toulu = CHAR_D->make_toulu(obj) ))
{ if (obj->query("killer")) 
   toulu->set("killer",obj->query("killer"));
                toulu->move(me);
}
        else
                write("不能创建头颅，请告诉巫师。\n");
                destruct(obj);
                return 1;

}

int help(object me)
{
  write(@HELP
指令格式 : cut corpse

砍下某个死人的头颅。
HELP
    );
    return 1;
}
