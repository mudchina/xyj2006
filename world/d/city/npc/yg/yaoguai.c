#include <ansi.h>;

inherit "/d/dntg/yunlou/npc/yaoguai.c";


int yaoguai_type=0;

void create()
{
        ::create();

        setname2();

        set("chat_chance", 3);
        set("chat_msg", ({
             (: random_move :)
        }) );

        setup();
}

void leave()
{
      if(this_object()) { 
        if(environment())
          message("vision",HIB + name() + 
                  "窜了几窜就不见了。\n" NOR,environment());
        destruct(this_object());
      }
      return;
}

string invocation(object who, int level)
{       object me=this_object(), env;
        string *dirs; 
        int exp, i, lvl;
        string where, long, guainame;
        
        // make skills less.
        copy_status(me, who, level-2);

        ::_invocation(who ,level);

        dirs=dirs1;

        // choose npc type.
        i=random(1000);
        if(i<30) {
            set("type","aggressive");
        } else if(i<100) {
            set("type","blocker");
        } else if(i<300) {
            set("type","aggressive_on_owner");
        } else 
            set("type","normal");
        
        if(!random_place(me, dirs)) {
            leave();
            return 0;
        }
        
        env=environment(me);
        guainame=me->query("name")+"("+me->query("id")+")";
        where=guainame;
        if(env)
          where+="在"+MISC_D->find_place(env);

        if(query("daoxing")>10000 ||
                query("combat_exp")>10000)
            command("wield all");

        return where;
}

int accept_object (object who, object ob)
{
    return 1;
}

int do_block(string arg)
{
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    if(wizardp(who) && !visible(who)) return 0;
    
    if(me->is_fighting()) return 0;

    if(verb!="go" &&
            verb!="fly" &&
            !(environment() && environment()->query("exits/" + verb)))
        return 0;

    t=who->query_temp("mieyao/allow_to_leave");
    if(t==0 || random(3)>0) {
        tell_object(who,"你正要离开，忽然看见什么东西在眼前一晃，"+
                "不由得停了下来。\n");
        who->set_temp("mieyao/allow_to_leave",1);
        return 1;
    } 
    
    who->set_temp("mieyao/allow_to_leave",0);
    return 0;
}

void die()
{
        string owner;
        object owner_ob;
        object me=this_object();
        string str;
object silver;
        int max_kee, max_sen, ratio, exp_r, pot_r;

        owner = query("owner");

        if( stringp(owner) && objectp(owner_ob = find_player(owner)) ) {
                    message_vision("$N惨叫一声，死了。\n",this_object());
                    owner_ob->set("mieyao/done1",1);
                    
                    max_kee=query("max_kee");
                    max_sen=query("max_sen");
                    ratio=100*(max_kee-other_kee)/max_kee;
                    if(ratio<0) ratio=0;
                    ratio=ratio*(max_sen-other_sen)/max_sen;
                    if(ratio<0) ratio=0;

                    exp_r=exp_reward*ratio/100;
                    pot_r=pot_reward*ratio/100;
                    owner_ob->add("combat_exp",exp_r);
                    owner_ob->add("potential",pot_r);
                    
                    str=" got "+exp_r+"/"+exp_reward+" exp "+
                        pot_r+"/"+pot_reward+" pot in level "+
                        owner_ob->query_temp("mieyao/level1")+
                        ".\n";

                    MONITOR_D->report_system_object_msg(owner_ob, str);

 silver=new("/obj/money/silver");
       silver->set_amount(random(15)+1);
if (silver->move(environment(owner_ob)))
tell_object(owner_ob,"你看见地上好象有几两银子闪闪发光，快捡吧。\n");
                    tell_object(owner_ob, "你得到了"+chinese_number(exp_r)
                            +"点武学经验和"+chinese_number(pot_r)+
                            "点潜能！\n");
/*
      tell_object(owner_ob, "你得到了"+COMBAT_D->chinese_daoxing(exp_r)
        +"道行和"+chinese_number(pot_r)+ "点潜能！\n");
*/

        } else {
            message_vision("$N死了。\n",this_object());
        }

        destruct(this_object());

}
