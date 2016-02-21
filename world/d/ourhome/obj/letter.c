//Cracked by Roath
#include <ansi.h>
inherit ITEM;
string daoxing(int dx);
void create()
{
        set_name(HIR+"信件"+NOR, ({"xin letter", "letter"}));
        set("weight", 5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是千里眼托付你的信件。\n");
                set("unit", "个");
                set("no_get", 1);
        }
        set("channel_id", "送宝精灵");
        setup();
}



void init()
{
        add_action("do_give", "give");

        if(query("target") ) {
                remove_call_out("set_target");
                call_out("set_target", 6, query("target"));
                delete("target");               // add 4 seconds' delay, can't be so fast
        }
}

void set_target(string target)
{
        set("target", target);
}
void set_owner(string owner)
{
        set("owner", owner);
}
int do_give(string arg)
{
        object me,ob;
        string obj,target;
        int i,qn;
       if(!arg || arg==" ")
            return 0;
        if (sscanf(arg,"%s to %s", obj, target)!=2 )
                if(sscanf(arg,"%s %s", target, obj) !=2 )       
                        return 0;

        if(!id(obj) )   return 0;

        me = this_player();
       
        if(!ob = present(target,environment(me)) ) {
                tell_object(me,"你想要把信件交给谁？\n");
                return 1;
        }
        if( ob->short(1) != query("target")) {
                tell_object(me, "你不能把宝盒交给这个人。\n");
                return 1;
        }
        if(!living(ob) ) {
                tell_object(me,ob->query("name")+"已经无法收下这样东西了。\n");
                return 1;
        }
// 解决找人帮忙送物，或者送别人的信件的bug
        if(!me->query("letter")||query("owner")!=me->query("id"))  {
        	write("义务劳动，值得鼓励，可惜没有报酬，哈哈！\n");
        	 me->receive_damage("kee", 20);
                 me->receive_damage("sen", 20);
                 destruct(this_object());
                 return 1;
                 }
        message("vision",me->name()+"拿出一个宝盒交给了" + ob->name() + "。\n", environment(me),({ me, ob }));
        if((time() > me->query( "letter/task_time" )) ) {
                tell_object(me,ob->name()+"打开宝合看了看，生气地瞪了你一眼。\n");
                tell_object(me, "你没有及时把信件送到" + ob->query("name") + "的手中，你的任务失败了！\n");
        } else {
                tell_object(me,ob->name()+"说道：多谢，多谢！\n");
                tell_object(me, "你成功地把信件送到了" + ob->name() + "的手中。\n");
                if(me->query("letter/basic")||me->query("combat_exp")<5000)
                i = 40+(int)( me->query("letter/task_time")-time())/10;
                else i = 50 + (int)(me->query("letter/task_time")-time())/7;
                i=i+random(40);
                me->add("daoxing",i);
                qn = 1+i/10;                
                me->add("potential",qn);
                tell_object(me, sprintf("你获得了"HIR"%s"NOR"的道行 ,"HIY"%s"NOR"点潜能！\n"NOR, daoxing(i),chinese_number(qn)) );
                CHANNEL_D->do_channel(this_object(),"sys",NOR+me->name()+"将信件送给"+ob->name()+"获得"HIR+daoxing(i)+NOR"的道行，"HIY+chinese_number(qn)+NOR"点潜能\n");
                me->set("letter_over",time()+240+random(120));
                me->delete("letter");
        }
        if(me->query("kee")<=20||me->query("sen")<=20)
        { message_vision("$N突然觉得头晕眼花，看样子是累坏了！\n",me);
          me->unconcious();
         }
         else {
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        }
        destruct(this_object());
        return 1;
}
string daoxing(int dx)
{
	
	int day,hour;
	day = (dx) / 4;
	hour = (dx  - day * 4) * 3; 
	return day?(chinese_number(day)+"天"):""+hour?(chinese_number(hour)+"时辰"):"";
}
void owner_is_killed() { destruct(this_object()); }

