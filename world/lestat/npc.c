#include <ansi.h>

inherit NPC;

int random_place(object me, string dirs);
void _leave();
void leave();
int announced=0;

string *dirs = ({
"/d/xueshan",
"/d/lingtai",
"/d/kunlun",
"/d/nanhai",
"/d/death",
"/d/pansi",
"/d/jjf",
"/d/sea",
"/d/qujing/wudidong",
"/d/qujing/kusong",
"/d/sanxian",
"/d/shushan",
});

void create()
{
        seteuid(getuid());
        set_name("TEST",({"test"}));
        set("age",30);
 
        set("str",30);
        set("per",20);
        set("combat_exp",5000);
        set("attitude", "heroism");
        set_skill("dodge",50);
        set_skill("moshenbu",50);
        set_skill("unarmed",50);
        set_skill("force",50);
        set_skill("dao",50);
        map_skill("dodge","moshenbu");
        map_skill("force","dao");
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }));
        setup();
//      for (int i=0;i<10;i++) carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
}

void init()
{
    object me=this_object();
    object who=this_player();
    int type;
    int t=query("stay_time");

    ::init();
    
    if(t && time()>(t+300)) {
        remove_call_out("leave");
        call_out("leave",1);
        return;
    }

    if(t && time()>t) {
        remove_call_out("_leave");
        call_out("_leave",300);
    }
    if(!living(this_object())) return;
    if(!living(who)) return;
    if( who->query("family/family_name") != query("target"))
    return;
    type=query("type");
    switch (type) {
        case 0:{
            object leader=query_leader();
            if(leader && present(leader, environment(me))) {
                break;
            }
            set_leader(who);
            message_vision("$N盯着$n，馋得直流口水：嘿嘿．．．\n",
                    this_object(), who);
            break;
            }
        case 1:
                if(!announced) {
                  message_vision("$N看见$n，大叫一声：哈哈，送上门来的肉！\n",
                        this_object(), who);
                  announced=1;
                }
                if(random(4)>0)
               {
                    set_leader(who);
                }
                else
                {
                    set_leader(0);
                }
            break;
        case 2:
        {
            add_action("do_block","",1);
            break;
            }
    }
    remove_call_out("check_room");
    call_out("check_room",2);
}

void check_room()
{
    object me=this_object();
    object env=environment(me);
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
                env->query("no_magic"))) {
        random_move();
    }
}

void copy_status(object me,object ob)
{
        object *inv;
        mapping skill_status,map_status;
        string *sname,*mname;
        int i, eff_dx, nk_factor;
        me->set_name(ob->query("name")+"的"RED"心魔"NOR,({ob->query("id")+"_npc"}));
        me->set("gender",ob->query("gender"));
        me->set("title",ob->query("title"));
//       me->set("nickname","非"+ob->query("nickname"));
        me->set("enable_type","刺客");
        me->set("str",ob->query("str"));
        me->set("int",ob->query("int"));
        me->set("con",ob->query("con"));
        me->set("per",ob->query("per"));
        me->set("cor",ob->query("cor"));
        me->set("spi",ob->query("spi"));
        me->set("cps",ob->query("cps"));
        me->set("kar",ob->query("kar"));

        me->set("max_kee",ob->query("max_kee"));
        me->set("eff_kee",ob->query("eff_kee"));
        me->set("kee",ob->query("kee"));

        me->set("max_gin",ob->query("max_gin"));
        me->set("eff_gin",ob->query("eff_gin"));
        me->set("gin",ob->query("gin"));

        me->set("max_sen",ob->query("max_sen"));
        me->set("eff_sen",ob->query("eff_sen"));
        me->set("sen",ob->query("sen"));

        me->set("max_force",ob->query("max_force"));
        me->set("force",ob->query("force")*2);
        me->set("force_factor",ob->query("force_factor"));

        me->set("max_mana",ob->query("max_mana"));
        me->set("mana",ob->query("mana") * 2);
        me->set("mana_factor",ob->query("mana_factor"));

        me->set("combat_exp",ob->query("combat_exp") * 6/5);
/*
        skill_status=me->query_skills();
        sname=keys(skill_status);
        for(i=0;i<sizeof(skill_status);i++) {
                me->delete_skill(sname[i]);
        }
*/
        if (skill_status=ob->query_skills())
        {
        sname=keys(skill_status);
        for(i=0;i<sizeof(skill_status);i++) {
                me->set_skill(sname[i],skill_status[sname[i]]+random(10));
        }
        }
/*      
        if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        me->map_skill(mname[i]);

                }
        }
*/
        if (map_status = ob->query_skill_map())
        {
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
                me->map_skill(mname[i], map_status[mname[i]]);
        }
        }
        inv = all_inventory(ob);
        for(i=0; i<sizeof(inv); i++)
        {
                if( inv[i]->query("weapon_prop") 
                &&  inv[i]->query("equipped")
                &&  !inv[i]->query_unique() ) {
                        carry_object(base_name(inv[i]))->wield();
                }
                else if( inv[i]->query("armor_prop") 
                &&  inv[i]->query("equipped") 
                &&  !inv[i]->query_unique() ) {
                        carry_object(base_name(inv[i]))->wear();
                }

        }

        me->set("stay_time",time()+600+random(60));
        me->set("nk_gain", 100+random(50));
        eff_dx = ob->query("combat_exp");
        if(eff_dx>1500000) 
        nk_factor = 9;
        else if(eff_dx>1000000)
        nk_factor = 8;
        else if(eff_dx>600000)
        nk_factor = 7;
        else if(eff_dx>300000)
        nk_factor = 6;
        else if(eff_dx>100000)
        nk_factor = 5;
        else if(eff_dx>50000)
        nk_factor = 4;
        else if(eff_dx>20000)
        nk_factor = 3;
        else if(eff_dx>10000)
        nk_factor = 2;
        else nk_factor = 1;
        me->set("nk_factor", nk_factor);

        me->set("type", random(3));
        reset_eval_cost();
}

int invocation(object who,int i)
{
        object me=this_object();
        copy_status(me,who);
        if(!random_place(me, dirs[i]))
        return 0;
        return 1;
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                if( random(10)<5 ) {
                        command("say 为什么踢我？会痛耶！");
                        break;
                }
        case "slap":

                if( random(10)<5 ) {
                        command("say 为什么打我？会痛耶！");
                        break;
                }
        case "kiss":
                if( random(10)<5 ) {
                        command("blush");
                        break;
                }
        default:
                if( random(10)<5 )
                        command(verb + " " + ob->query("id"));
                else
                        command("? "+ ob->query("id"));
        }
}

int random_place(object me, string dirs)
{
        int  j, k;
        object  newob;
        mixed*  file, exit;
        file = get_dir( dirs+"/*.c", -1 );

        if( !sizeof(file) )             return 1;

        for(k=0;k<30;k++) { // try 30 times
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
                       newob->query("no_magic") ||
                       !(exit=newob->query("exits")) ||
                       sizeof(exit)<1)
                   continue;

               if(me->move(newob)) {
                   message_vision("$N走了过来。\n",me);
                   return 1;
               }
             }
           }
        }

        return 0;
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

    if(who->query_temp("do_quest/allow_to_go")) {
        who->delete_temp("do_quest/allow_to_go");
        who->delete_temp("do_quest/leave_time");
        return 0;
    }
    t=who->query_temp("do_quest/leave_time");
    if(t>0 && time()>t) {

        who->delete_temp("do_quest/leave_time");
        message_vision("$n乘$N一个不注意，急忙溜了过去。\n",me,who);
        return 0;
    }
    if(t==0) {
        t=time()+30+random(90);
        who->set_temp("do_quest/leave_time",t);
        message_vision("$N猛地跳过来拦在$n面前，高声叫道：\n"+
                "          此山是我开，此树是我栽！\n"+
                "          要打此路过，留下买路财！\n\n",me,who);
    } 
    
    tell_object(who,me->name()+"一把抓住了你！\n");
    return 1;
}

int accept_object (object who, object ob)
{
  object me;
  me = this_object();

  if ((! ob) ||
       ob->value() < 100000)

  {
    message_vision ("$N一瞪眼：就这点东西？不想活了？？？\n", me);
    return 1;
  }
  who->set_temp("do_quest/allow_to_go", 1);
  message_vision ("$N嘿嘿嘿几声怪笑：算你走运，快滚！"
          +"可别让我再看见你！\n",me);
  return 1;
}

varargs int receive_damage(string type, int damage, object who)
{
  object me=this_object();
  call_out("exertheal",1,me);
  return ::receive_damage(type,damage,who);
}

void exertheal(object me) {
  me->command("exert recover");
}

void die()
{

        int reward;
        object ob,me;
        ob = query_temp("last_damage_from");
   me=this_object();
        if (!ob)
        {
                leave();
                return; 
        }
        CHANNEL_D->do_channel( this_object(), "rumor",
        sprintf("挑衅%s的"NOR+YEL"%s"HIM"被%s杀死了。"NOR,query("target"),query("name"), ob->name() ));
        if ( userp(ob) &&
        ob->query("family/family_name") == query("target") )
        {
        reward = query("nk_gain") * query("nk_factor");
        ob->add("kill/nkgain",reward);
        ob->add("daoxing",reward);
        ob->add("potential", reward*2/3);
     ob->add("faith", 1);
     ob->add("score", 10);
//tell_object(users(),HIW"【奖励】:"HIY+ob->name()+"成功保护了门派安全，受到了门派奖励\n"NOR);
        tell_object(ob,"\n你得到了"+COMBAT_D->chinese_daoxing(reward)+"道行和"
                + reward/2 + "点潜能！\n" );
//        tell_object(ob,"你的官值增加了。\n");
        MONITOR_D->report_system_object_msg(ob,"得到了"+COMBAT_D->chinese_daoxing(reward)+"道行和"

                + reward/2 + "点潜能！");
		destruct(this_object());
        }
//  me->move("/d/city/center");
  destruct(this_object());
 //       ::die();
}

void unconcious()
{
  if (query("kee")<0 || query("sen")<0) die();
   else ::unconcious();
}

void heart_beat()
{
        if (!query_temp("weapon") && !query_temp("added"))
        {
        set_temp("added", 1);
        set("force_factor",100);
        set("force",2000);
        }
        if (query("eff_kee")<query("max_kee"))
        {
        if (random(10))
        command("eat yao");

        else
        {
                command("surrender");
                call_out("exertheal",1,this_object());
        }
        }


        ::heart_beat();
}

void _leave()
{
        object me=this_object();
        if(me->is_fighting() || me->is_busy())
        return;
        leave();
}

void leave()
{
      if(this_object()) {
        if(environment())
{
command("say 嘿嘿，这么久没人敢来，看来是怕了我了。。。");
          message("vision",HIB + name() + 
                  HIB"身子一晃，变成一股青烟散去了。\n" NOR,environment());
}
        destruct(this_object());
      }
      return;
}

int attack()
{
        object opponent;
        clean_up_enemy();
        opponent = select_opponent();
        if( objectp(opponent) ) {
        if(opponent->query("family/family_name")==this_object()->query("target")
                        && userp(opponent)
                        && !living(opponent)
                        && environment()==environment(opponent)) {
                    call_out("leave",1);
                    return 0;
                }

                set_temp("last_opponent", opponent);
                COMBAT_D->fight(this_object(), opponent);
                return 1;
        } else
                return 0;
}


