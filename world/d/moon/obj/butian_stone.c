# include <skill.h>
#include <ansi.h>

inherit ITEM;

void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
            who->query("name")+"得到了"+name()+"！\n");
}

void create()
{
        set_name(HIY "五"+ HIR "彩" + HIM "补" + HIC"天"+ HIW"石" NOR, ({"butian stone", "stone", "shi"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_sell",1);
                set("no_put",1);
                set("value",0);
                set("unit","颗");
                set("long",
"一颗五彩缤纷的小石子，似乎仔细端详(duanxiang)之下会发出异彩。\n");
        }
        set("is_monitored",1);
        setup();

}
void init()
{
        call_out("announce",random(10),this_player());
        add_action("do_study","duanxiang");
}

int do_study(string arg)
{
        object me,pearl;
        int i,j;
        me=this_player();
        j=10+random(10);
        if( !arg || (arg!="butian stone"
                        && arg!="stone"
                        && arg!="shi") )
                return notify_fail("你要摸什么？\n");
 if( (int)me->query_skill("butian-force",1) >= 50)
 return notify_fail("你的补天心法过高，五彩补天石内的灵气以对你豪无作用了。\n");
        if(!me->query("m_success/补天石"))
                return notify_fail("五彩补天石的灵气显示你没有福缘吸取天地日月精华。\n");
        if(!me->query("m_success/得到补天心法")){
                message_vision("$N细细端详$n，只见$n里面越来越深邃，好象藏了个大千世界。
$N感觉整个身体要化入其中，丹田一热，一股暖暖的热流流转四肢百骸。\n",me,this_object());
//   me->set_skill("butian-force",j);
   me->add_skill("butian-force",j);
                tell_object(me,"你得到了"+chinese_number(j)+"段补天心法。\n");
                me->set("m_success/得到补天心法",1);
                return 1;
                }
                
        if( (int)me->query_skill("force",1) < 20)
                return notify_fail("你的内功心法不够，还感受不到五彩补天石的灵气。\n");
        if( (int)me->query_skill("butian-force",1) >= 50)
                return notify_fail("你的补天心法过高，五彩补天石内的灵气以对你豪无作用了。\n");
        if( (int)me->query_skill("spells",1) < 20)
                return notify_fail("你的法术修养不够，还领悟不到五彩补天石内的灵气。\n");
        if( (int)me->query("kee") < 30)
                return notify_fail("你的气血不足，再练会晕倒过去。\n");
        if( (int)me->query("sen") < 30)
                return notify_fail("你的精神不济，再练会昏迷过去。\n");
        if( (int)me->query("force") <30)
                return notify_fail("你的内力不足，再练有害无益。\n");
        i=(int)me->query_kar()*(int)me->query("spi")*4;
        if( i>3000 ){
                i=3000;
        }

        if( (int)this_object()->query("learned") >= i) {
                message_vision("$N手中的$n突发七彩之光，一道霞光过后便失去了颜色。\n",me,this_object());
                if( pearl=new("/d/sea/obj/pearl")){
                        pearl->move(me);
                }
                destruct(this_object());
                return 1;
        }
        message_vision("$N细细端详$n，只见几缕淡淡霞光流入掌中。\n",me,this_object());
        me->improve_skill("butian-force", random((int)me->query_int()/3 + (int)me->query_spi()/3)+1+random(8));
        me->receive_damage("kee",5);
        me->receive_damage("sen",30);
        me->add("force",-10);
        this_object()->add("learned",1);

        write("你对补天心法的领悟似乎又深了一层。\n");
        return 1;
}

