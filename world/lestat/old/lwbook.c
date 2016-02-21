#include <ansi.h>

inherit ITEM;


void init()
{
      if(this_player()==environment())
        add_action("do_read", "read");
      call_out("announce",random(10),this_player());
}

void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
            who->query("name")+"得到了"+name()+"！\n");
}

void create()
{
        set_name(HIW "《九转真经》" NOR, ({"jiuzhuan zhenjing", "zhenjing"}));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "本");
set("no_give",1);
set("no_drop",1);
set("no_get",1);
                set("long", "一本点解玄玄神机的九转真经，上面氤氲袅绕。。。\n");
                set("value", 10000);

        }
  
        set("is_monitored",1);
        setup();
}

int do_read(string arg)
{
        int i,j;

        object me = this_player();
  
        if (!id(arg)) return notify_fail("你要读什么？\n");
        

  

        

        i = random(900);
        j = random(1000);


        message_vision(HIB "$N迫不及待地翻阅着《九转真经》！ \n哼哼叽叽地读了起来，口水直流。\n" NOR, me);  
//	if (!me->query("wizgift/jinchai")) 
//	{
	me->add("wizgift/jinchai",1);
        me->add("daoxing",i+3000);
        me->add("potential",j+800);
        me->add("combat_exp",j+3000);
	log_file("static/jinchai","["+ctime(time())+"] "+
        sprintf("%s(%s)读了%O\n",
         this_player()->query("name"),this_player()->query("id"),
 this_object()));
        
        tell_object (me,"你仿佛领悟了些天机地理，得到了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行
和"+chinese_number(j+3000)+"点武学，以及"+chinese_number(j+800)+"点潜能！
须臾。。。。。
《九转真经》化作一只白鹤冲天而去，你不禁唏嘘不已。\n");
//	}
        destruct(this_object());

        return 1;
        
}
